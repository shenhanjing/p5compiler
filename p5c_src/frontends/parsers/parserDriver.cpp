#include "parserDriver.h"

#include <cerrno>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string_view>

#include <boost/format.hpp>

#include "frontends/common/constantFolding.h"
#include "lib/error.h"

#include "frontends/parsers/p5/p5lexer.hpp"
#include "frontends/parsers/p5/p5parser.hpp"

namespace {

/// A RAII helper class that provides an istream wrapper for a stdio FILE*.
/// Standalone p5compiler uses a simple, portable implementation (no boost::iostreams).
struct AutoStdioInputStream {
    explicit AutoStdioInputStream(FILE *in) {
        char buffer[512];
        while (fgets(buffer, sizeof(buffer), in)) stream << buffer;
    }
    std::istream &get() { return stream; }

 private:
    std::stringstream stream;
};

}  // namespace

namespace P4 {

AbstractParserDriver::AbstractParserDriver() : sources(new Util::InputSources) {}

AbstractParserDriver::~AbstractParserDriver() {}

void AbstractParserDriver::onReadToken(const char *text) {
    auto posBeforeToken = sources->getCurrentPosition();
    sources->appendText(text);
    auto posAfterToken = sources->getCurrentPosition();
    yylloc = Util::SourceInfo(sources, posBeforeToken, posAfterToken);
}

void AbstractParserDriver::onReadLineNumber(const char *text) {
    char *last;
    errno = 0;
    lineDirectiveLine = strtol(text, &last, 10);
    const bool consumedEntireToken = strlen(last) == 0;
    if (errno != 0 || !consumedEntireToken) {
        auto &context = BaseCompileContext::get();
        context.errorReporter().parser_error(sources, "Error parsing line number %s", text);
    }
}

void AbstractParserDriver::onReadComment(const char *text, bool lineComment) {
    sources->addComment(yylloc, lineComment, cstring(text));
}

void AbstractParserDriver::onReadFileName(const char *text) {
    lineDirectiveFile = cstring(text);
    sources->mapLine(text, lineDirectiveLine);
}

void AbstractParserDriver::onReadIdentifier(cstring id) { lastIdentifier = id; }

void AbstractParserDriver::onParseError(const Util::SourceInfo &location,
                                        const std::string &message) {
    static const std::string_view unexpectedIdentifierError = "syntax error, unexpected IDENTIFIER";
    auto &context = BaseCompileContext::get();
    if (message == unexpectedIdentifierError) {
        context.errorReporter().parser_error(
            location, boost::format("%s \"%s\"") % unexpectedIdentifierError % lastIdentifier);
    } else {
        context.errorReporter().parser_error(location, message);
    }
}

}  // namespace P4

namespace P4::P5 {

P5ParserDriver::P5ParserDriver()
    : structure(new Util::ProgramStructure), nodes(new IR::Vector<IR::Node>) {}

/* static */ const IR::P4Program *P5ParserDriver::parse(std::istream &in,
                                                        std::string_view sourceFile,
                                                        unsigned sourceLine /* = 1 */) {
    LOG1("Parsing P5 program " << sourceFile);

    P5ParserDriver driver;
    P5Lexer lexer(in);
    P5Parser parser(driver, lexer);

#ifdef YYDEBUG
    if (const char *p = getenv("YYDEBUG")) parser.set_debug_level(atoi(p));
    driver.structure->setDebug(parser.debug_level() != 0);
#endif

    // Provide an initial source location.
    driver.sources->mapLine(sourceFile, sourceLine);

    // Parse.
    if (parser.parse() != 0) return nullptr;
    return new IR::P4Program(driver.nodes->srcInfo, *driver.nodes);
}

/* static */ const IR::P4Program *P5ParserDriver::parse(FILE *in, std::string_view sourceFile,
                                                        unsigned sourceLine /* = 1 */) {
    AutoStdioInputStream inputStream(in);
    return parse(inputStream.get(), sourceFile, sourceLine);
}

IR::Constant *P5ParserDriver::constantFold(IR::Expression *expr) {
    IR::Node *node(expr);
    auto rv = node->apply(P4::DoConstantFolding())->to<IR::Constant>();
    return rv ? new IR::Constant(rv->srcInfo, rv->type, rv->value, rv->base) : nullptr;
}

IR::Vector<IR::Expression> P5ParserDriver::makeExpressionList(const IR::NameList *list) {
    IR::Vector<IR::Expression> rv;
    for (auto &name : list->names) rv.push_back(new IR::StringLiteral(name));
    return rv;
}

void P5ParserDriver::clearPragmas() { currentPragmas.clear(); }

void P5ParserDriver::addPragma(IR::Annotation *pragma) {
    // Standalone p5compiler does not expose annotation-disable options.
    currentPragmas.push_back(pragma);
}

IR::Vector<IR::Annotation> P5ParserDriver::takePragmasAsVector() {
    IR::Vector<IR::Annotation> pragmas;
    std::swap(pragmas, currentPragmas);
    return pragmas;
}

}  // namespace P4::P5
