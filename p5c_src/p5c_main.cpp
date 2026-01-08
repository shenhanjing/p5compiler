#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <memory>
#include <optional>
#include <string>

#include "frontends/parsers/parserDriver.h"
#include "frontends/p5/passes/p5_to_c.h"
#include "lib/compile_context.h"
#include "lib/error.h"

namespace {

struct StandaloneContext : P4::BaseCompileContext {
    StandaloneContext() = default;
};

struct PopenFile {
    void operator()(FILE *f) const {
        if (f) pclose(f);
    }
};

using PopenFilePtr = std::unique_ptr<FILE, PopenFile>;

std::optional<PopenFilePtr> preprocessToPipe(const std::filesystem::path &inputFile) {
    // We need macro expansion / conditional compilation (#define/#if/#ifdef),
    // but no #include, so we use a minimal cpp invocation.
    //
    // -C: keep comments (harmless)
    // -undef -nostdinc: reduce host-dependent macros/includes
    // -x assembler-with-cpp: allow preprocessing directives on arbitrary text
    std::string cmd = "cpp -C -undef -nostdinc -x assembler-with-cpp ";
    cmd += "\"";
    cmd += inputFile.string();
    cmd += "\"";

    FILE *in = popen(cmd.c_str(), "r");
    if (!in) {
        ::P4::error(P4::ErrorType::ERR_IO, "Error invoking preprocessor");
        return std::nullopt;
    }
    return std::optional<PopenFilePtr>(PopenFilePtr(in));
}

void usage(const char *argv0) {
    std::cerr << "Usage: " << argv0 << " <input.p5> [-o <out_dir>]\n";
}

}  // namespace

int main(int argc, char **argv) {
    StandaloneContext ctx;
    P4::AutoCompileContext autoCtx(&ctx);

    if (argc < 2) {
        usage(argv[0]);
        return 2;
    }

    std::filesystem::path input;
    std::filesystem::path outDir = ".";

    // Minimal args: first non-flag is input; support "-o <dir>".
    for (int i = 1; i < argc; i++) {
        std::string a = argv[i];
        if (a == "-o") {
            if (i + 1 >= argc) {
                usage(argv[0]);
                return 2;
            }
            outDir = argv[++i];
            continue;
        }
        if (!a.empty() && a[0] == '-') {
            std::cerr << "Unknown option: " << a << "\n";
            usage(argv[0]);
            return 2;
        }
        if (!input.empty()) {
            std::cerr << "Only one input file is supported.\n";
            usage(argv[0]);
            return 2;
        }
        input = a;
    }

    if (input.empty()) {
        usage(argv[0]);
        return 2;
    }

    auto pre = preprocessToPipe(input);
    if (!pre.has_value() || ::P4::errorCount() > 0) {
        return 1;
    }

    const P4::IR::P4Program *program =
        P4::P5::P5ParserDriver::parse(pre->get(), input.string(), 1);
    if (::P4::errorCount() > 0 || program == nullptr) {
        return 1;
    }

    // Emit generated C++ files under outDir/{include,src}.
    P4::P5::runP5ToC(program, outDir.string());

    if (::P4::errorCount() > 0) {
        return 1;
    }

    return 0;
}


