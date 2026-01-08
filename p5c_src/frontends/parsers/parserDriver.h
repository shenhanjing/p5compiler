/*
Copyright 2013-present Barefoot Networks, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef FRONTENDS_PARSERS_PARSERDRIVER_H_
#define FRONTENDS_PARSERS_PARSERDRIVER_H_

#include <cstdio>
#include <string>
#include <string_view>

#include "frontends/p4/symbol_table.h"
#include "ir/ir.h"
#include "lib/cstring.h"
#include "lib/source_file.h"

namespace P4 {

/// Minimal base class of ParserDrivers, providing shared lexer/parser state.
class AbstractParserDriver {
 public:
    virtual ~AbstractParserDriver() = 0;

 protected:
    AbstractParserDriver();

    // Callbacks used by lexer/parser actions.
    void onReadComment(const char *text, bool lineComment);
    void onReadToken(const char *text);
    void onReadLineNumber(const char *text);
    void onReadFileName(const char *text);
    void onReadIdentifier(cstring id);
    void onParseError(const Util::SourceInfo &location, const std::string &message);

    // Shared state manipulated directly by the lexer and parser.
    Util::InputSources *sources;
    Util::SourceInfo yylloc;
    int saveState = -1;

 private:
    int lineDirectiveLine = 0;
    cstring lineDirectiveFile;
    cstring lastIdentifier;
};

}  // namespace P4

namespace P4::P5 {

class P5Lexer;
class P5Parser;

/// ParserDriver for Huawei P5 programs (standalone build only supports P5).
class P5ParserDriver final : public P4::AbstractParserDriver {
 public:
    static const IR::P4Program *parse(std::istream &in, std::string_view sourceFile,
                                      unsigned sourceLine = 1);
    static const IR::P4Program *parse(FILE *in, std::string_view sourceFile,
                                      unsigned sourceLine = 1);

 protected:
    friend class P5::P5Lexer;
    friend class P5::P5Parser;

    Util::ProgramStructure *structure = nullptr;
    IR::Vector<IR::Node> *nodes = nullptr;

    IR::Constant *constantFold(IR::Expression *expr);
    IR::Vector<IR::Expression> makeExpressionList(const IR::NameList *list);

    void clearPragmas();
    void addPragma(IR::Annotation *pragma);
    IR::Vector<IR::Annotation> takePragmasAsVector();

    std::string stringLiteral;

 private:
    IR::Vector<IR::Annotation> currentPragmas;
    P5ParserDriver();
};

}  // namespace P4::P5

#endif /* FRONTENDS_PARSERS_PARSERDRIVER_H_ */
