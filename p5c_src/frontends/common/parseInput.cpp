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

#include "parseInput.h"

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "frontends/common/options.h"
#include "frontends/p4-14/fromv1.0/converters.h"
#include "frontends/p4/frontend.h"
#include "frontends/p4/removeReturns.h"
#include "frontends/p4/sideEffects.h"
#include "frontends/p4/switchAddDefault.h"
#include "frontends/p4/typeChecking/typeChecker.h"
#include "frontends/p4/typeMap.h"
#include "frontends/p4/uniqueNames.h"
#include "frontends/p5/passes/add_main_annotation.h"
#include "frontends/p5/passes/functionsInlining.h"
#include "frontends/p5/passes/remove_unused.h"
#include "frontends/p5/passes/typeChecking/typeChecker.h"
#include "frontends/parsers/parserDriver.h"
#include "ir/dump.h"
#include "ir/pass_manager.h"
#include "lib/error.h"

namespace P4 {

void logP5Ast(std::string_view sourceFile, const IR::P4Program *program) {
    if (program == nullptr) return;

    std::string logPath(sourceFile);
    if (logPath.empty()) {
        logPath = "p5_ast.log";
    } else {
        logPath += ".p5.ast.log";
    }

    std::ofstream logFile(logPath, std::ios::out | std::ios::trunc);
    if (!logFile.good()) {
        std::cerr << "Failed to open P5 AST log file " << logPath << std::endl;
        return;
    }

    logFile << dumpToString(program) << std::endl;
    std::cout << "P5 AST written to " << logPath << std::endl;
}

namespace {

class SetStrictStruct : public Inspector {
    TypeMap *typeMap;
    bool strictStruct;

 public:
    SetStrictStruct(TypeMap *typeMap, bool strict) : typeMap(typeMap), strictStruct(strict) {
        CHECK_NULL(typeMap);
        setName("SetStrictStruct");
    }
    profile_t init_apply(const IR::Node *node) override {
        typeMap->setStrictStruct(strictStruct);
        return Inspector::init_apply(node);
    }
};

}  // namespace
const IR::P4Program *runInlinePreparationPasses(const CompilerOptions &options,
                                                const IR::P4Program *program,
                                                std::ostream *dumpStream) {
    if (program == nullptr) return nullptr;

    TypeMap typeMap;
    FrontEndPolicy inlinePolicy;

    std::unique_ptr<std::ofstream> fileStream;
    std::ostream *logStream = dumpStream;
    if (logStream == nullptr && !options.file.empty()) {
        auto logPath = options.file;
        logPath += ".inline.log";
        fileStream = std::make_unique<std::ofstream>(logPath.string(), std::ios::out | std::ios::trunc);
        if (fileStream->good()) {
            logStream = fileStream.get();
            std::cout << "Writing P5 inline log to " << logPath << std::endl;
        } else {
            std::cerr << "Failed to open P5 inline log file " << logPath << std::endl;
            fileStream.reset();
        }
    }

    PassManager passes({
        new P5::AddMainAnnotation("ingress"_cs, "main"_cs),
        new SetStrictStruct(&typeMap, true),
        new P5::TypeInference(&typeMap, false, false),
        new SetStrictStruct(&typeMap, false),
        new SwitchAddDefault,
        new UniqueParameters(&typeMap),
        new SideEffectOrdering(&typeMap, inlinePolicy.skipSideEffectOrdering()),
        new RemoveReturns(),
        new UniqueNames(),
        new UniqueParameters(&typeMap),
        new P5::InlineFunctions(&typeMap, inlinePolicy, std::vector<cstring>{"parser"_cs, "main"_cs}),
        new P5::RemoveAllUnusedDeclarationsFromAnnotations(inlinePolicy, std::vector<cstring>{"main"_cs}),
    });
    passes.setName("P5InlineOnly");
    passes.setStopOnError(true);

    if (logStream != nullptr || dumpStream != nullptr) {
        auto logHook = [logStream](const char *manager, unsigned seq, const char *pass,
                                   const IR::Node *node) {
            if (node == nullptr) return;
            std::ostream *out = logStream;
            if (out == nullptr) return;
            (*out) << "[P5InlineOnly] after pass #" << seq;
            if (manager != nullptr) (*out) << " (" << manager << ")";
            if (pass != nullptr) (*out) << ": " << pass;
            (*out) << '\n';
            (*out) << dumpToString(node) << "\n";
        };
        passes.addDebugHook(logHook, false);
    }
    passes.addDebugHook(options.getDebugHook(), true);

    return program->apply(passes);
}

const IR::P4Program *parseP4String(const char *sourceFile, unsigned sourceLine,
                                   const std::string &input,
                                   CompilerOptions::FrontendVersion version) {
    std::istringstream stream(input);
    const auto *result =
        version == CompilerOptions::FrontendVersion::P4_14
            ? parseV1Program<std::istringstream &, P4V1::Converter>(stream, sourceFile, sourceLine)
            : P4ParserDriver::parse(stream, sourceFile, sourceLine);

    if (::P4::errorCount() > 0) {
        ::P4::error(ErrorType::ERR_OVERLIMIT, "%1% errors encountered, aborting compilation",
                    ::P4::errorCount());
        return nullptr;
    }
    BUG_CHECK(result != nullptr, "Parsing failed, but we didn't report an error");
    return result;
}

const IR::P4Program *parseP4String(const std::string &input,
                                   CompilerOptions::FrontendVersion version) {
    return parseP4String("(string)", 1, input, version);
}

}  // namespace P4
