#ifndef FRONTENDS_P5LEXER_H_
#define FRONTENDS_P5LEXER_H_

// FlexLexer.h requires you to provide an external #include guard so that it can
// be included multiple times, each time providing a different definition for
// yyFlexLexer, to define multiple lexer base classes.

#define yyFlexLexer p5FlexLexer
#include <FlexLexer.h>
#undef yyFlexLexer

#include "frontends/parsers/p5/p5lexer_internal.hpp"

#endif  /* FRONTENDS_P5LEXER_H_ */
