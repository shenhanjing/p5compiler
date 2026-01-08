%{
#include "frontends/common/constantParsing.h"
#include "frontends/parsers/parserDriver.h"
#include "frontends/parsers/p5/p5lexer_internal.hpp"
#include "frontends/parsers/p5/p5parser.hpp"

using namespace P4;

using Parser = P5::P5Parser;

#undef  YY_DECL
#define YY_DECL Parser::symbol_type P5::P5Lexer::yylex(P5::P5ParserDriver& driver)

#define YY_USER_ACTION driver.onReadToken(yytext);
#define YY_USER_INIT driver.saveState = NORMAL
#define yyterminate() return Parser::make_END(driver.yylloc);

// Silence the warnings triggered by the code flex generates.
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wtautological-undefined-compare"
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#ifdef __clang__
#pragma clang diagnostic ignored "-Wnull-conversion"
#pragma clang diagnostic ignored "-Wregister"
#endif

%}

%option c++
%option outfile="lex.yy.c"
%option yyclass="P5::P5Lexer"
%option prefix="p5"
%option nodefault noyywrap nounput noinput noyyget_leng
%option noyyget_debug noyyset_debug noyyget_extra noyyset_extra noyyget_in noyyset_in
%option noyyget_out noyyset_out noyyget_text noyyget_lineno noyyset_lineno

%x COMMENT
%x LINE1 LINE2 LINE3
%s NORMAL

%%

[ \t\r\n]+              ;
"//".*                  ;
"/*"                  { BEGIN COMMENT; }
<COMMENT>"*/"         { BEGIN driver.saveState; }
<COMMENT>.              ;
<COMMENT>[\n]           ;

<INITIAL>"#line"      { BEGIN(LINE1); }
<INITIAL>"# "         { BEGIN(LINE1); }
<INITIAL>[ \t]*"#"    { BEGIN(LINE3); }
<LINE1>[0-9]+         { BEGIN(LINE2); driver.onReadLineNumber(yytext); }
<LINE2>\"[^"]*        { BEGIN(LINE3); driver.onReadFileName(yytext+1); }
<LINE1,LINE2>[ \t]      ;
<LINE1,LINE2>.        { BEGIN(LINE3); }
<LINE3>.                ;
<LINE1,LINE2,LINE3>\n { BEGIN(INITIAL); }
<LINE1,LINE2,LINE3,COMMENT,NORMAL><<EOF>> { BEGIN(INITIAL); }

\"[^"]*\"             { BEGIN(driver.saveState);
                        auto string = cstring(driver.stringLiteral);
                        return Parser::make_STRING_LITERAL(string, driver.yylloc);
                      }

"break"         { BEGIN(driver.saveState);
                  return Parser::make_BREAK(cstring(yytext), driver.yylloc); }
"case"          { BEGIN(driver.saveState);
                  return Parser::make_CASE(cstring(yytext), driver.yylloc); }
"class"         { BEGIN(driver.saveState);
                  return Parser::make_CLASS(cstring(yytext), driver.yylloc); }
"const"         { BEGIN(driver.saveState);
                  return Parser::make_CONST(cstring(yytext), driver.yylloc); }
"default"       { BEGIN(driver.saveState);
                  return Parser::make_DEFAULT(cstring(yytext), driver.yylloc); }
"do"            { BEGIN(driver.saveState);
                  return Parser::make_DO(cstring(yytext), driver.yylloc); }
"else"          { BEGIN(driver.saveState);
                  return Parser::make_ELSE(cstring(yytext), driver.yylloc); }
"enum"          { BEGIN(driver.saveState);
                  return Parser::make_ENUM(cstring(yytext), driver.yylloc); }
"for"           { BEGIN(driver.saveState);
                  return Parser::make_FOR(cstring(yytext), driver.yylloc); }
"if"            { BEGIN(driver.saveState);
                  return Parser::make_IF(cstring(yytext), driver.yylloc); }
"int"           { BEGIN(driver.saveState);
                  return Parser::make_INT(cstring(yytext), driver.yylloc); }
"namespace"     { BEGIN(driver.saveState);
                  return Parser::make_NAMESPACE(cstring(yytext), driver.yylloc); }
"private"       { BEGIN(driver.saveState);
                  return Parser::make_PRIVATE(cstring(yytext), driver.yylloc); }
"protected"     { BEGIN(driver.saveState);
                  return Parser::make_PROTECTED(cstring(yytext), driver.yylloc); }
"public"        { BEGIN(driver.saveState);
                  return Parser::make_PUBLIC(cstring(yytext), driver.yylloc); }
"return"        { BEGIN(driver.saveState);
                  return Parser::make_RETURN(cstring(yytext), driver.yylloc); }
"struct"        { BEGIN(driver.saveState);
                  return Parser::make_STRUCT(cstring(yytext), driver.yylloc); }
"switch"        { BEGIN(driver.saveState);
                  return Parser::make_SWITCH(cstring(yytext), driver.yylloc); }
"typedef"       { BEGIN(driver.saveState);
                  return Parser::make_TYPEDEF(cstring(yytext), driver.yylloc); }
"union"         { BEGIN(driver.saveState);
                  return Parser::make_UNION(cstring(yytext), driver.yylloc); }
"uint"          { BEGIN(driver.saveState);
                  return Parser::make_UINT(cstring(yytext), driver.yylloc); }
"using"         { BEGIN(driver.saveState);
                  return Parser::make_USING(cstring(yytext), driver.yylloc); }
"while"         { BEGIN(driver.saveState);
                  return Parser::make_WHILE(cstring(yytext), driver.yylloc); }
"void"          { BEGIN(driver.saveState);
                  return Parser::make_VOID(cstring(yytext), driver.yylloc); }

"key"          { BEGIN(driver.saveState);
                  return Parser::make_KEY(cstring(yytext), driver.yylloc); }
"control_parameters"   { BEGIN(driver.saveState);
                        return Parser::make_CONTROL_PARAMETERS(cstring(yytext), driver.yylloc); }
"size"        { BEGIN(driver.saveState);
                  return Parser::make_SIZE(cstring(yytext), driver.yylloc); }

"header"        { BEGIN(driver.saveState);
                  return Parser::make_HEADER(cstring(yytext), driver.yylloc); }
"table"        { BEGIN(driver.saveState);
                  return Parser::make_TABLE(cstring(yytext), driver.yylloc); }

[A-Za-z_][A-Za-z0-9_]* {
                  BEGIN(driver.saveState);
                  cstring name = cstring(yytext);
                  driver.onReadIdentifier(name);
                  return Parser::make_IDENTIFIER(name, driver.yylloc);
}


0[xX][0-9a-fA-F_]+ { BEGIN(driver.saveState);
                     UnparsedConstant constant{cstring(yytext), 2, 16, false};
                     return Parser::make_INTEGER(constant, driver.yylloc); }
0[dD][0-9_]+    { BEGIN(driver.saveState);
                  UnparsedConstant constant{cstring(yytext), 2, 10, false};
                  return Parser::make_INTEGER(constant, driver.yylloc); }
0[oO][0-7_]+    { BEGIN(driver.saveState);
                  UnparsedConstant constant{cstring(yytext), 2, 8, false};
                  return Parser::make_INTEGER(constant, driver.yylloc); }
0[bB][01_]+     { BEGIN(driver.saveState);
                  UnparsedConstant constant{cstring(yytext), 2, 2, false};
                  return Parser::make_INTEGER(constant, driver.yylloc); }
[0-9]+          { BEGIN(driver.saveState);
                  UnparsedConstant constant{cstring(yytext), 0, 10, false};
                  return Parser::make_INTEGER(constant, driver.yylloc); }

"("             { BEGIN(driver.saveState); return Parser::make_L_PAREN(driver.yylloc); }
")"             { BEGIN(driver.saveState); return Parser::make_R_PAREN(driver.yylloc); }
"{"             { BEGIN(driver.saveState); return Parser::make_L_BRACE(driver.yylloc); }
"}"             { BEGIN(driver.saveState); return Parser::make_R_BRACE(driver.yylloc); }
"["             { BEGIN(driver.saveState); return Parser::make_L_BRACKET(driver.yylloc); }
"]"             { BEGIN(driver.saveState); return Parser::make_R_BRACKET(driver.yylloc); }
"@"             { BEGIN(driver.saveState); return Parser::make_AT(driver.yylloc); }
"."             { BEGIN(driver.saveState); return Parser::make_DOT(driver.yylloc); }
","             { BEGIN(driver.saveState); return Parser::make_COMMA(driver.yylloc); }
"~"             { BEGIN(driver.saveState); return Parser::make_COMPLEMENT(driver.yylloc); }
"?"             { BEGIN(driver.saveState); return Parser::make_QUESTION(driver.yylloc); }
":"             { BEGIN(driver.saveState); return Parser::make_COLON(driver.yylloc); }
"::"            { BEGIN(driver.saveState); return Parser::make_SCOPE(driver.yylloc); }
"="             { BEGIN(driver.saveState); return Parser::make_ASSIGN(driver.yylloc); }
"+"             { BEGIN(driver.saveState); return Parser::make_PLUS(driver.yylloc); }
"++"            { BEGIN(driver.saveState); return Parser::make_PP(driver.yylloc); }
"+="            { BEGIN(driver.saveState); return Parser::make_ASSIGN_PLUS(driver.yylloc); }
"-"             { BEGIN(driver.saveState); return Parser::make_MINUS(driver.yylloc); }
"--"            { BEGIN(driver.saveState); return Parser::make_MM(driver.yylloc); }
"-="            { BEGIN(driver.saveState); return Parser::make_ASSIGN_MINUS(driver.yylloc); }
"*"             { BEGIN(driver.saveState); return Parser::make_MUL(driver.yylloc); }
"**"            { BEGIN(driver.saveState); return Parser::make_POW(driver.yylloc); }
"*="            { BEGIN(driver.saveState); return Parser::make_ASSIGN_MUL(driver.yylloc); }
"/"             { BEGIN(driver.saveState); return Parser::make_DIV(driver.yylloc); }
"/="            { BEGIN(driver.saveState); return Parser::make_ASSIGN_DIV(driver.yylloc); }
"%"             { BEGIN(driver.saveState); return Parser::make_MOD(driver.yylloc); }
"%="            { BEGIN(driver.saveState); return Parser::make_ASSIGN_MOD(driver.yylloc); }
"!"             { BEGIN(driver.saveState); return Parser::make_NOT(driver.yylloc); }
"=="            { BEGIN(driver.saveState); return Parser::make_EQ_OP(driver.yylloc); }
"!="            { BEGIN(driver.saveState); return Parser::make_NE_OP(driver.yylloc); }
">"             { BEGIN(driver.saveState); return Parser::make_R_ANGLE(driver.yylloc); }
"<"             { BEGIN(driver.saveState); return Parser::make_L_ANGLE(driver.yylloc); }
">="            { BEGIN(driver.saveState); return Parser::make_GE(driver.yylloc); }
"<="            { BEGIN(driver.saveState); return Parser::make_LE(driver.yylloc); }
"&"             { BEGIN(driver.saveState); return Parser::make_BIT_AND(driver.yylloc); }
"&&"            { BEGIN(driver.saveState); return Parser::make_AND_OP(driver.yylloc); }
"&="            { BEGIN(driver.saveState); return Parser::make_ASSIGN_BIT_AND(driver.yylloc); }
"|"             { BEGIN(driver.saveState); return Parser::make_BIT_OR(driver.yylloc); }
"||"            { BEGIN(driver.saveState); return Parser::make_OR_OP(driver.yylloc); }
"|="            { BEGIN(driver.saveState); return Parser::make_ASSIGN_BIT_OR(driver.yylloc); }
"^"             { BEGIN(driver.saveState); return Parser::make_BIT_XOR(driver.yylloc); }
"^="            { BEGIN(driver.saveState); return Parser::make_ASSIGN_BIT_XOR(driver.yylloc); }
">>"            { BEGIN(driver.saveState); return Parser::make_RIGHT_OP(driver.yylloc); }
">>="           { BEGIN(driver.saveState); return Parser::make_ASSIGN_SHR(driver.yylloc); }
"<<"            { BEGIN(driver.saveState); return Parser::make_LEFT_OP(driver.yylloc); }
"<<="           { BEGIN(driver.saveState); return Parser::make_ASSIGN_SHL(driver.yylloc); }
"#"             { BEGIN(driver.saveState); return Parser::make_SHARP(driver.yylloc); }
";"             { BEGIN(driver.saveState); return Parser::make_SEMICOLON(driver.yylloc); }

"”"             { BEGIN(driver.saveState); return Parser::make_UNEXPECTED_TOKEN(driver.yylloc); }
"’"             { BEGIN(driver.saveState); return Parser::make_UNEXPECTED_TOKEN(driver.yylloc); }


.               { return Parser::make_UNEXPECTED_TOKEN(driver.yylloc); }


%%
