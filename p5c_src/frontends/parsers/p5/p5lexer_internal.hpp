#ifndef FRONTENDS_PARSERS_P5_P5LEXER_INTERNAL_HPP_
#define FRONTENDS_PARSERS_P5_P5LEXER_INTERNAL_HPP_

#include <string_view>

#include "frontends/common/constantParsing.h"
#include "frontends/parsers/p5/p5parser.hpp"
#include "lib/source_file.h"

namespace P4::P5 {

class P5ParserDriver;

class P5Lexer : public p5FlexLexer {
    typedef P5::P5Parser::symbol_type Token;

 public:
    explicit P5Lexer(std::istream &input) : p5FlexLexer(&input) {}

    /**
     * Invoked by the parser to advance to the next token in the input stream.
     *
     * Note that we could store @driver as a member on the class, but it's
     * actually useful to explicitly pass it in. In C++, you cannot overload a
     * method on return type only. Since yyFlexLexer already declares a version
     * of yylex() that takes no arguments and returns an int, and we need to
     * return a Token, we need to add an additional argument to permit the
     * overload.
     *
     * @return the token that was just read.
     */
    virtual Token yylex(P5::P5ParserDriver &driver);

    // Clear the whitespace characters before and after the string to avoid reserving extra spaces
    // in lexical analysis.
    static constexpr std::string_view trim(std::string_view in,
                                           std::string_view white = " \n\r\t\v") {
        auto left = in.find_first_not_of(white);
        if (left == std::string_view::npos) return {};

        in.remove_prefix(left);

        auto right = in.find_last_not_of(white);
        if (right == std::string_view::npos) return {};

        in.remove_suffix(in.size() - right - 1);
        return in;
    }

 private:
    int yylex() override { return p5FlexLexer::yylex(); }
};

}  // namespace P4::P5

#endif /* FRONTENDS_PARSERS_P5_P5LEXER_INTERNAL_HPP_ */
