// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 100 "p5parser.ypp"
 /* -*-C++-*- */
#include <iostream>  // NOLINT(build/include_order)

#include "frontends/parsers/parserDriver.h"
#include "frontends/parsers/p5/p5lexer.hpp"
#include "frontends/parsers/p5/p5parser.hpp"
#include "ir/ir.h"

using namespace P4;

#define YYLLOC_DEFAULT(Cur, Rhs, N)                                             \
    ((Cur) = (N) ? YYRHSLOC(Rhs, 1) + YYRHSLOC(Rhs, N)                          \
                 : Util::SourceInfo(driver.sources, YYRHSLOC(Rhs, 0).getEnd()))

#undef yylex
#define yylex lexer.yylex

namespace P4 {

static const IR::Expression *removeRedundantValid(const IR::Expression *e);

}  // namespace P4



#line 66 "y.tab.c"


#include "y.tab.h"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 7 "p5parser.ypp"
namespace P4 { namespace P5 {
#line 163 "y.tab.c"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  P5Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  P5Parser::P5Parser (P4::P5::P5ParserDriver& driver_yyarg, P4::P5::P5Lexer& lexer_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg),
      lexer (lexer_yyarg)
  {}

  P5Parser::~P5Parser ()
  {}

  P5Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  P5Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  P5Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  P5Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  P5Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  P5Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  P5Parser::symbol_number_type
  P5Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  P5Parser::stack_symbol_type::stack_symbol_type ()
  {}

  P5Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 85: // INTEGER
        value.YY_MOVE_OR_COPY< UnparsedConstant > (YY_MOVE (that.value));
        break;

      case 54: // BREAK
      case 55: // CASE
      case 56: // CONST
      case 57: // CLASS
      case 58: // DEFAULT
      case 59: // DO
      case 60: // ELSE
      case 61: // ENUM
      case 62: // FOR
      case 63: // IF
      case 64: // INT
      case 65: // NAMESPACE
      case 66: // PRIVATE
      case 67: // PROTECTED
      case 68: // PUBLIC
      case 69: // RETURN
      case 70: // STRUCT
      case 71: // SWITCH
      case 72: // TYPEDEF
      case 73: // UNION
      case 74: // UINT
      case 75: // USING
      case 76: // WHILE
      case 77: // VOID
      case 78: // KEY
      case 79: // CONTROL_PARAMETERS
      case 80: // MA_ID
      case 81: // SIZE
      case 82: // HEADER
      case 83: // TABLE
      case 84: // IDENTIFIER
      case 98: // string_lit
      case 99: // ID
        value.YY_MOVE_OR_COPY< cstring > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  P5Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 85: // INTEGER
        value.move< UnparsedConstant > (YY_MOVE (that.value));
        break;

      case 54: // BREAK
      case 55: // CASE
      case 56: // CONST
      case 57: // CLASS
      case 58: // DEFAULT
      case 59: // DO
      case 60: // ELSE
      case 61: // ENUM
      case 62: // FOR
      case 63: // IF
      case 64: // INT
      case 65: // NAMESPACE
      case 66: // PRIVATE
      case 67: // PROTECTED
      case 68: // PUBLIC
      case 69: // RETURN
      case 70: // STRUCT
      case 71: // SWITCH
      case 72: // TYPEDEF
      case 73: // UNION
      case 74: // UINT
      case 75: // USING
      case 76: // WHILE
      case 77: // VOID
      case 78: // KEY
      case 79: // CONTROL_PARAMETERS
      case 80: // MA_ID
      case 81: // SIZE
      case 82: // HEADER
      case 83: // TABLE
      case 84: // IDENTIFIER
      case 98: // string_lit
      case 99: // ID
        value.move< cstring > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  P5Parser::stack_symbol_type&
  P5Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 85: // INTEGER
        value.copy< UnparsedConstant > (that.value);
        break;

      case 54: // BREAK
      case 55: // CASE
      case 56: // CONST
      case 57: // CLASS
      case 58: // DEFAULT
      case 59: // DO
      case 60: // ELSE
      case 61: // ENUM
      case 62: // FOR
      case 63: // IF
      case 64: // INT
      case 65: // NAMESPACE
      case 66: // PRIVATE
      case 67: // PROTECTED
      case 68: // PUBLIC
      case 69: // RETURN
      case 70: // STRUCT
      case 71: // SWITCH
      case 72: // TYPEDEF
      case 73: // UNION
      case 74: // UINT
      case 75: // USING
      case 76: // WHILE
      case 77: // VOID
      case 78: // KEY
      case 79: // CONTROL_PARAMETERS
      case 80: // MA_ID
      case 81: // SIZE
      case 82: // HEADER
      case 83: // TABLE
      case 84: // IDENTIFIER
      case 98: // string_lit
      case 99: // ID
        value.copy< cstring > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  P5Parser::stack_symbol_type&
  P5Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 85: // INTEGER
        value.move< UnparsedConstant > (that.value);
        break;

      case 54: // BREAK
      case 55: // CASE
      case 56: // CONST
      case 57: // CLASS
      case 58: // DEFAULT
      case 59: // DO
      case 60: // ELSE
      case 61: // ENUM
      case 62: // FOR
      case 63: // IF
      case 64: // INT
      case 65: // NAMESPACE
      case 66: // PRIVATE
      case 67: // PROTECTED
      case 68: // PUBLIC
      case 69: // RETURN
      case 70: // STRUCT
      case 71: // SWITCH
      case 72: // TYPEDEF
      case 73: // UNION
      case 74: // UINT
      case 75: // USING
      case 76: // WHILE
      case 77: // VOID
      case 78: // KEY
      case 79: // CONTROL_PARAMETERS
      case 80: // MA_ID
      case 81: // SIZE
      case 82: // HEADER
      case 83: // TABLE
      case 84: // IDENTIFIER
      case 98: // string_lit
      case 99: // ID
        value.move< cstring > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  P5Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  P5Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
      case 54: // BREAK
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 520 "y.tab.c"
        break;

      case 55: // CASE
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 526 "y.tab.c"
        break;

      case 56: // CONST
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 532 "y.tab.c"
        break;

      case 57: // CLASS
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 538 "y.tab.c"
        break;

      case 58: // DEFAULT
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 544 "y.tab.c"
        break;

      case 59: // DO
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 550 "y.tab.c"
        break;

      case 60: // ELSE
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 556 "y.tab.c"
        break;

      case 61: // ENUM
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 562 "y.tab.c"
        break;

      case 62: // FOR
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 568 "y.tab.c"
        break;

      case 63: // IF
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 574 "y.tab.c"
        break;

      case 64: // INT
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 580 "y.tab.c"
        break;

      case 65: // NAMESPACE
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 586 "y.tab.c"
        break;

      case 66: // PRIVATE
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 592 "y.tab.c"
        break;

      case 67: // PROTECTED
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 598 "y.tab.c"
        break;

      case 68: // PUBLIC
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 604 "y.tab.c"
        break;

      case 69: // RETURN
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 610 "y.tab.c"
        break;

      case 70: // STRUCT
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 616 "y.tab.c"
        break;

      case 71: // SWITCH
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 622 "y.tab.c"
        break;

      case 72: // TYPEDEF
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 628 "y.tab.c"
        break;

      case 73: // UNION
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 634 "y.tab.c"
        break;

      case 74: // UINT
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 640 "y.tab.c"
        break;

      case 75: // USING
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 646 "y.tab.c"
        break;

      case 76: // WHILE
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 652 "y.tab.c"
        break;

      case 77: // VOID
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 658 "y.tab.c"
        break;

      case 78: // KEY
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 664 "y.tab.c"
        break;

      case 79: // CONTROL_PARAMETERS
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 670 "y.tab.c"
        break;

      case 80: // MA_ID
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 676 "y.tab.c"
        break;

      case 81: // SIZE
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 682 "y.tab.c"
        break;

      case 82: // HEADER
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 688 "y.tab.c"
        break;

      case 83: // TABLE
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 694 "y.tab.c"
        break;

      case 84: // IDENTIFIER
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 700 "y.tab.c"
        break;

      case 85: // INTEGER
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < UnparsedConstant > (); }
#line 706 "y.tab.c"
        break;

      case 98: // string_lit
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 712 "y.tab.c"
        break;

      case 99: // ID
#line 129 "p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 718 "y.tab.c"
        break;

      default:
        break;
    }
    yyo << ')';
  }
#endif

  void
  P5Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  P5Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  P5Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  P5Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  P5Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  P5Parser::debug_level_type
  P5Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  P5Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  P5Parser::state_type
  P5Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  P5Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  P5Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  P5Parser::operator() ()
  {
    return parse ();
  }

  int
  P5Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 85: // INTEGER
        yylhs.value.emplace< UnparsedConstant > ();
        break;

      case 54: // BREAK
      case 55: // CASE
      case 56: // CONST
      case 57: // CLASS
      case 58: // DEFAULT
      case 59: // DO
      case 60: // ELSE
      case 61: // ENUM
      case 62: // FOR
      case 63: // IF
      case 64: // INT
      case 65: // NAMESPACE
      case 66: // PRIVATE
      case 67: // PROTECTED
      case 68: // PUBLIC
      case 69: // RETURN
      case 70: // STRUCT
      case 71: // SWITCH
      case 72: // TYPEDEF
      case 73: // UNION
      case 74: // UINT
      case 75: // USING
      case 76: // WHILE
      case 77: // VOID
      case 78: // KEY
      case 79: // CONTROL_PARAMETERS
      case 80: // MA_ID
      case 81: // SIZE
      case 82: // HEADER
      case 83: // TABLE
      case 84: // IDENTIFIER
      case 98: // string_lit
      case 99: // ID
        yylhs.value.emplace< cstring > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 226 "p5parser.ypp"
                    { YYACCEPT; }
#line 999 "y.tab.c"
    break;

  case 3:
#line 235 "p5parser.ypp"
          { yylhs.value.as < cstring > () = yystack_[0].value.as < cstring > (); }
#line 1005 "y.tab.c"
    break;

  case 4:
#line 239 "p5parser.ypp"
          { yylhs.value.as < cstring > () = yystack_[0].value.as < cstring > (); }
#line 1011 "y.tab.c"
    break;


#line 1015 "y.tab.c"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  P5Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  P5Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short P5Parser::yypact_ninf_ = -393;

  const short P5Parser::yytable_ninf_ = -223;

  const short
  P5Parser::yypact_[] =
  {
      39,    63,   255,  -393,   166,   190,  -393,   123,   123,   123,
     193,   123,   123,   353,   123,   210,   353,   123,  -393,   136,
    -393,   335,   123,  -393,  -393,  -393,  -393,   298,   389,   397,
     422,  -393,  -393,  -393,  -393,  -393,   251,   306,   482,    94,
     490,   532,   123,  -393,   556,    94,   123,   504,   123,   123,
     353,   216,   123,   428,  -393,  -393,  -393,  -393,  -393,   299,
    -393,   123,   299,   299,   299,   473,  -393,  -393,   496,  -393,
    -393,    51,  -393,   531,  -393,  -393,  -393,  -393,   168,    93,
    -393,   137,  -393,   217,   123,   123,   236,  -393,   187,   299,
     299,    23,    57,    57,    57,    57,   575,  -393,  -393,   516,
    -393,   520,   512,   487,   537,   543,   536,   550,   133,  -393,
     222,   441,   140,  -393,    14,   576,  -393,   294,   279,   585,
     380,   409,    23,   299,  -393,   299,   123,   588,   140,  -393,
     604,   607,  -393,   299,  -393,   480,   528,   600,    35,   533,
    -393,  -393,   569,  -393,  -393,   104,   123,  -393,    64,   570,
     299,   299,  -393,   485,   359,   617,   514,   524,   469,  -393,
    -393,  -393,  -393,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
     299,    57,  -393,  -393,  -393,   299,    79,  -393,   321,   299,
    -393,   123,  -393,  -393,   299,   531,   585,  -393,   488,   426,
    -393,  -393,   123,  -393,  -393,  -393,   410,   618,    23,   619,
     299,   299,   299,   572,   299,   577,   299,   299,   299,   299,
     299,   299,   299,   299,  -393,  -393,  -393,   592,   299,   299,
     299,  -393,   411,   150,   621,    23,    57,  -393,   612,   299,
     498,   498,  -393,  -393,  -393,  -393,  -393,   520,   520,   520,
     520,   512,   512,   487,   537,   543,   536,   452,   550,   585,
     123,   296,  -393,   540,   123,   585,  -393,   438,  -393,   299,
    -393,   299,   246,   579,   137,   169,   531,  -393,    16,   561,
     489,    45,   218,  -393,   238,  -393,   248,   274,   283,   302,
     303,   304,   312,   320,  -393,   440,   322,    33,   258,  -393,
    -393,  -393,   346,  -393,   299,   585,    57,   615,   624,   299,
     620,   622,   623,  -393,  -393,   334,   544,  -393,  -393,   442,
     299,   299,  -393,  -393,   106,    23,   547,   632,   211,  -393,
     633,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,   625,  -393,   558,   299,   299,  -393,   634,
     585,  -393,   299,  -393,   585,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,   453,   323,  -393,  -393,  -393,    23,    65,
    -393,  -393,   299,   299,   456,   327,  -393,   282,  -393,   585,
      30,   174,  -393,   220,  -393,   551,   497,   123,  -393,   337,
      52,    32,  -393,   594,   578,   642,   643,    12,   644,  -393,
    -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,   560,
     299,  -393,   299,   635,  -393,  -393,   648,   605,  -393,   568,
     299,  -393,  -393,   582,  -393,   299,    41,   654,    95,  -393,
    -393,   299,   540,   457,    75,  -393,   539,   653,  -393,  -393,
     299,   338,   656,   610,   342,  -393,    97,    23,   299,  -393,
     367,   345,   611,   299,   299,   657,    23,   229,  -393,   658,
      68,  -393,   299,   299,   177,  -393,  -393,   502,   506,   660,
    -393,  -393,   585,  -393,    23,  -393,  -393,  -393,  -393,    59,
     299,   649,   661,  -393,  -393,   398,   340,   608,   663,   626,
    -393,    83,  -393,  -393,   552,   664,  -393,  -393,    23,   177,
     527,  -393,   181,  -393,   665,  -393,   667,  -393,   299,   659,
    -393,   204,  -393,   299,   666,  -393,  -393,   668,   177,   571,
      41,  -393,  -393,   573,   219,   669,  -393,  -393,    41,   627,
     219,  -393,  -393,   628,  -393,  -393,  -393
  };

  const unsigned char
  P5Parser::yydefact_[] =
  {
      60,     0,    60,   212,    60,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,    65,
      61,     0,     0,   205,   207,   210,   208,     0,     0,    64,
       0,   206,   211,    60,   213,     2,    57,     0,     0,     0,
       0,     0,     0,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   201,   199,   200,   209,     0,
      60,     0,     0,     0,     0,     3,     5,     8,    69,     7,
      11,     0,    73,     6,    60,    60,   189,    60,     0,     0,
      60,    60,    66,     0,     0,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    18,    20,    24,
      27,    30,    35,    38,    40,    42,    44,    46,    48,    50,
      55,     0,     0,   120,     0,   190,   192,     0,     0,    55,
       0,     0,     0,     0,    63,     0,     0,    60,     0,    80,
      60,    60,    62,     0,    85,     0,     0,     0,    69,   107,
     183,   184,     0,   182,   185,    60,     0,    67,     0,     0,
       0,     0,    87,     0,    69,     0,     0,     6,     0,    17,
      14,    15,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    52,    59,     0,     0,    60,     0,     0,
     194,     0,     9,    10,     0,    72,   122,   123,     0,     0,
      70,   204,     0,   195,    81,   196,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   188,   186,     0,     0,     0,
       0,    93,     0,     0,     0,     0,     0,    10,     0,     0,
      25,    26,    21,    22,    23,    29,    28,    32,    31,    34,
      33,    36,    37,    39,    41,    43,    45,     0,    47,    56,
       0,   115,   121,    60,     0,   191,   193,     0,    12,     0,
      71,     0,     0,     0,    60,    69,   107,   109,     0,    60,
       0,     0,     0,   145,     0,   146,     0,     0,     0,     0,
       0,     0,     0,     0,    68,     0,     0,     0,     0,    88,
     158,   203,    69,    19,     0,    53,     0,   117,     0,     0,
       0,     0,     0,   217,   218,    60,     0,    75,   124,     0,
       0,     0,    76,    86,    60,     0,     0,     0,     0,   163,
      60,   108,   181,   135,   137,   136,   138,   139,   140,   141,
     142,   144,   143,     0,    82,     0,     0,     0,    89,    60,
      54,    49,     0,   119,   116,   215,   216,   214,   197,   219,
     220,    60,    74,     0,     0,   187,   110,    60,     0,     0,
     178,   164,     0,     0,     0,     0,   160,    60,   159,   118,
       0,     0,    77,     0,   176,    60,     0,     0,   162,     0,
       0,     0,    90,     0,    60,     0,     0,     0,     0,   149,
     148,   155,   156,   153,   151,   154,   152,   157,   150,     0,
       0,    78,     0,     0,   180,   177,     0,     0,    83,     0,
       0,    91,   114,     0,    60,     0,     0,     0,     0,   113,
     112,     0,    60,     0,    99,   101,     0,     0,    60,   161,
       0,     0,     0,     0,     0,    97,     0,     0,     0,    94,
       0,    60,     0,     0,     0,     0,    60,     0,   167,    60,
       0,    92,     0,     0,    60,    96,    98,     0,     0,     0,
     198,    79,   100,   102,    60,   169,   170,   171,   172,    60,
       0,     0,     0,   168,    84,     0,     0,   126,     0,     0,
     131,    60,   175,   173,     0,     0,   179,   125,     0,    60,
       0,    95,     0,   174,     0,    60,     0,   127,     0,     0,
     105,     0,   133,     0,     0,   132,    60,    60,    60,     0,
       0,   111,   106,     0,    60,    60,   166,   128,     0,     0,
      60,   130,   165,     0,   104,   129,   103
  };

  const short
  P5Parser::yypgoto_[] =
  {
    -393,  -393,  -393,     9,  -393,  -393,   241,  -393,   -56,   205,
     390,   401,   439,   505,   507,   508,   495,   510,  -393,   377,
     381,   318,  -393,     0,    28,  -393,   -76,   486,   616,     1,
    -393,     5,  -392,  -393,   233,  -342,   178,  -393,  -206,  -323,
    -393,  -393,  -393,  -174,   -79,   419,  -201,  -393,  -393,  -393,
    -393,  -393,  -393,  -330,  -366,  -393,   315,  -320,  -146,   235,
    -393,  -182,   221,   311,  -393,  -133,   423,  -393,  -393,   509,
    -393,  -393,   696,  -393,  -393,  -393,  -393,     2,   629,  -291,
     267,  -393
  };

  const short
  P5Parser::yydefgoto_[] =
  {
      -1,     1,    67,    68,    69,    70,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     434,   111,    20,    21,    22,    72,    73,   129,   130,   140,
      24,   141,   429,   446,   435,   436,   510,   511,   142,   278,
     430,   401,   402,   113,   114,   197,   198,   403,   404,   405,
     515,   502,   406,   143,   378,   349,   301,   329,   330,   458,
     459,   478,   479,   384,   385,   144,   145,    26,    27,   116,
     117,    28,    43,    30,    31,    32,    33,     3,     4,   314,
     315,     5
  };

  const short
  P5Parser::yytable_[] =
  {
       2,   135,   277,    23,     2,   139,    34,    25,   153,   280,
     371,    19,   226,   262,   157,   158,    36,    37,    38,   426,
      40,    41,    19,    44,   360,    19,    47,   187,   423,   325,
      19,    53,    64,     2,   445,    58,   159,   160,   161,   162,
     210,    42,  -222,   187,    46,   386,   195,   407,   426,    52,
     420,    76,   122,   183,   466,    79,   123,    82,    83,    19,
     112,    86,    88,     6,    63,   183,    64,   492,    64,   139,
     115,    92,   183,   228,     2,   128,    93,   128,    84,    94,
     112,   387,   229,   427,   421,   183,   124,   112,   183,    95,
     138,   503,    64,   148,   149,   183,    18,   154,   487,    62,
     448,    63,   133,    64,   426,   465,   188,    18,   326,   242,
     243,   244,   225,    64,   365,    64,   155,   388,   260,   366,
     345,    19,   409,   211,   467,    18,   477,     2,   529,    34,
     128,   128,   276,   507,   332,   200,   533,    19,   494,   419,
     186,    65,    66,    18,   477,   134,    64,   449,   180,   477,
     230,     7,   527,    48,   138,   227,   202,   484,   531,   195,
     360,   477,   277,    18,   535,   453,   519,    18,   506,  -221,
     183,   523,    49,   123,   210,   136,   181,   136,    65,    66,
     303,    18,   137,   410,   137,  -147,   122,   112,    18,   512,
      18,   226,    88,    35,    89,   261,    90,   371,   139,    91,
     115,    92,   299,   132,    10,   371,    93,    18,   136,    94,
      12,   272,   521,    14,    15,   137,    88,   275,    89,    95,
      90,    18,     7,    91,    18,    92,   411,  -147,   182,    39,
      93,     7,  -147,    94,   146,  -147,   513,  -147,   183,   514,
       7,   277,   183,    95,   302,   150,    45,   468,   139,   276,
     443,    10,   147,  -147,   151,   320,    59,    12,   183,   508,
      14,    15,   509,     2,   321,   313,     7,   346,   183,   307,
     333,    65,    66,   316,  -147,   412,   347,  -147,   413,   328,
      71,    85,   380,   138,   480,   192,    78,   481,   152,   300,
     334,    64,   276,     7,   183,    65,    66,   493,   322,   183,
     335,   139,   190,   183,    88,   308,    89,   191,    90,   493,
     348,    91,     8,    92,   309,     2,     9,   359,    93,    10,
      11,    94,   183,   183,   183,    12,   336,    13,    14,    15,
     328,    95,   183,   138,   275,   337,   393,    16,    17,    18,
     183,   394,   183,   183,   395,   396,     7,   183,   464,   377,
      54,   397,   -66,   398,   338,   339,   340,   183,   183,   517,
     183,   112,   183,   122,   341,   -65,    18,   383,   240,   241,
     525,   276,   342,   469,   344,   382,   235,   275,   399,   392,
     139,   120,   400,    65,    66,   383,   275,   183,   193,   418,
     461,    50,   498,   185,   377,    49,   417,    60,   139,    10,
     310,   311,   312,   139,   497,    12,   428,   156,    14,    15,
      51,   310,   311,   312,   263,   139,   264,    10,   183,    18,
     273,   298,   139,    12,   112,   194,    14,    15,   358,   183,
     183,   183,     2,    87,   313,   428,   270,    18,   457,   470,
     110,    55,   271,   118,   119,   121,   183,   184,   317,    56,
     343,     2,   362,   359,   185,   428,   275,   475,   183,   457,
     183,   476,   183,   381,   377,   275,   391,   452,   306,   118,
     119,   121,   183,   183,    57,   475,   183,   183,   125,   476,
     475,   126,    -4,   275,   476,    -4,   207,   239,   275,    61,
      -4,   234,   475,   187,   268,   331,   476,    74,   187,   377,
     275,   269,   269,   416,   196,   328,   199,   275,   488,    80,
     325,    81,   489,   122,   206,   325,   328,   328,   377,   269,
     174,   175,   237,   165,   377,   328,   166,   185,   167,   428,
     377,   232,   233,   125,   238,   163,   126,   428,   164,    75,
     125,   165,   125,   126,   166,   126,   167,   170,   171,   172,
     173,   212,   454,   213,   214,   455,   215,   216,   245,   246,
     217,   257,   218,    77,   219,   454,   259,   168,   504,   169,
     265,   247,   248,   249,   250,   267,   176,   220,   178,   221,
     123,   222,   508,   223,   454,   509,   454,   528,   177,   530,
     179,   196,   281,   282,   189,   284,   201,   286,   287,   288,
     289,   290,   291,   292,   293,   183,   310,   311,   312,   295,
     296,   297,   203,   251,   252,   205,   204,   204,   209,   208,
     305,   224,   231,   236,   283,   274,   279,   294,   300,   285,
     304,   323,   327,   352,   353,   361,   355,   368,   356,   357,
     367,   370,   376,   372,   373,   414,   422,   424,   425,   431,
     196,   437,   319,   432,  -147,   438,   440,   439,   442,   447,
     456,   462,   463,   471,   474,   495,   482,   490,   499,   496,
     500,   505,   516,   518,   256,   520,   526,   532,   501,   534,
     536,   253,   524,   351,   254,   350,   255,   473,   318,   522,
     354,   258,   408,   131,   483,   491,   415,   324,    29,   451,
     266,   363,   364,   127,     0,     0,     0,     0,     0,   369,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   374,   375,     0,
       0,     0,     0,   379,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   389,   390,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   433,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   441,     0,     0,     0,     0,   444,     0,     0,     0,
       0,     0,   450,     0,     0,     0,     0,     0,     0,     0,
       0,   460,     0,     0,     0,     0,     0,     0,     0,   196,
       0,     0,     0,     0,   472,     0,     0,     0,     0,     0,
       0,     0,     0,   485,   486
  };

  const short
  P5Parser::yycheck_[] =
  {
       0,    80,   208,     2,     4,    81,     4,     2,    87,   210,
     330,     2,   145,   187,    90,    91,     7,     8,     9,     7,
      11,    12,    13,    14,   315,    16,    17,    13,   394,    13,
      21,    22,     9,    33,   426,    33,    92,    93,    94,    95,
       5,    13,     3,    13,    16,   368,   122,   377,     7,    21,
      18,    42,    17,    20,   446,    46,     5,    48,    49,    50,
      60,    52,     5,     0,     7,    20,     9,     8,     9,   145,
      61,    14,    20,     9,    74,    75,    19,    77,    50,    22,
      80,    16,    18,    71,    52,    20,    35,    87,    20,    32,
      81,     8,     9,    84,    85,    20,    84,    88,   464,     5,
       5,     7,     9,     9,     7,     8,    92,    84,    92,   165,
     166,   167,     8,     9,     8,     9,    88,    52,    39,   325,
      87,   112,    92,    88,   447,    84,   456,   127,   520,   127,
     130,   131,   208,   499,    89,   126,   528,   128,   480,    87,
     112,    84,    85,    84,   474,    52,     9,    52,    15,   479,
      86,    11,   518,    17,   145,   146,   128,    89,   524,   235,
     451,   491,   368,    84,   530,    90,   508,    84,   498,     3,
      20,   513,    36,     5,     5,    71,    43,    71,    84,    85,
     236,    84,    78,     9,    78,     8,    17,   187,    84,     8,
      84,   324,     5,     3,     7,   186,     9,   517,   274,    12,
     191,    14,    52,    35,    64,   525,    19,    84,    71,    22,
      70,   202,     8,    73,    74,    78,     5,   208,     7,    32,
       9,    84,    11,    12,    84,    14,    52,     8,     6,    36,
      19,    11,    55,    22,    17,    58,    55,    60,    20,    58,
      11,   447,    20,    32,   235,     9,    36,   448,   324,   325,
     424,    64,    35,    76,    18,     9,     5,    70,    20,    55,
      73,    74,    58,   263,    18,   263,    11,     9,    20,   260,
      52,    84,    85,   264,    55,    55,    18,    58,    58,   279,
      39,    65,   361,   274,    55,     6,    45,    58,    52,     7,
      52,     9,   368,    11,    20,    84,    85,   479,    52,    20,
      52,   377,     8,    20,     5,     9,     7,    13,     9,   491,
      52,    12,    57,    14,    18,   315,    61,   315,    19,    64,
      65,    22,    20,    20,    20,    70,    52,    72,    73,    74,
     330,    32,    20,   324,   325,    52,    54,    82,    83,    84,
      20,    59,    20,    20,    62,    63,    11,    20,     6,   349,
      52,    69,     6,    71,    52,    52,    52,    20,    20,   505,
      20,   361,    20,    17,    52,     6,    84,   367,   163,   164,
     516,   447,    52,     6,    52,    52,    17,   368,   377,    52,
     456,    63,   377,    84,    85,   385,   377,    20,     8,    52,
      52,    56,    52,    13,   394,    36,   387,    91,   474,    64,
      66,    67,    68,   479,     6,    70,   397,    89,    73,    74,
      75,    66,    67,    68,    93,   491,    95,    64,    20,    84,
      10,    10,   498,    70,   424,    16,    73,    74,    94,    20,
      20,    20,   432,     5,   432,   426,    10,    84,   438,    94,
      59,    52,    16,    62,    63,    64,    20,     6,    10,    52,
      10,   451,    10,   451,    13,   446,   447,   456,    20,   459,
      20,   456,    20,    10,   464,   456,    10,    10,    16,    88,
      89,    90,    20,    20,    52,   474,    20,    20,     9,   474,
     479,    12,     9,   474,   479,    12,     6,    18,   479,     7,
      17,     6,   491,    13,     6,     6,   491,     7,    13,   499,
     491,    13,    13,     6,   123,   505,   125,   498,     6,     5,
      13,     7,     6,    17,   133,    13,   516,   517,   518,    13,
      33,    34,     8,    25,   524,   525,    28,    13,    30,   520,
     530,   150,   151,     9,    10,    19,    12,   528,    22,     7,
       9,    25,     9,    12,    28,    12,    30,    35,    36,    37,
      38,    18,    13,    20,    21,    16,    23,    24,   168,   169,
      27,   180,    29,     7,    31,    13,   185,    47,    16,    49,
     189,   170,   171,   172,   173,   194,    39,    44,    42,    46,
       5,    48,    55,    50,    13,    58,    13,    16,    45,    16,
      40,   210,   211,   212,    18,   214,     8,   216,   217,   218,
     219,   220,   221,   222,   223,    20,    66,    67,    68,   228,
     229,   230,     8,   174,   175,     8,   130,   131,    18,    91,
     239,    52,    52,     6,    52,     7,     7,    35,     7,    52,
      18,    52,    71,    18,    10,    91,    16,     5,    16,    16,
      93,     8,     8,    18,    86,    94,    52,     5,     5,     5,
     269,    16,   271,    93,    76,     7,    88,    52,    76,     5,
       7,     5,    52,    52,     7,    16,     8,     7,    60,     8,
       7,     7,     7,     6,   179,    16,     8,     8,    52,    52,
      52,   176,    16,   306,   177,   304,   178,   454,   269,   511,
     309,   181,   377,    77,   459,   474,   385,   274,     2,   432,
     191,   320,   321,    74,    -1,    -1,    -1,    -1,    -1,   328,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,   347,    -1,
      -1,    -1,    -1,   352,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   372,   373,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   420,    -1,    -1,    -1,    -1,   425,    -1,    -1,    -1,
      -1,    -1,   431,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   440,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,
      -1,    -1,    -1,    -1,   453,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   462,   463
  };

  const unsigned char
  P5Parser::yystos_[] =
  {
       0,    97,   119,   173,   174,   177,     0,    11,    57,    61,
      64,    65,    70,    72,    73,    74,    82,    83,    84,    99,
     118,   119,   120,   125,   126,   127,   163,   164,   167,   168,
     169,   170,   171,   172,   173,     3,    99,    99,    99,    36,
      99,    99,   120,   168,    99,    36,   120,    99,    17,    36,
      56,    75,   120,    99,    52,    52,    52,    52,   173,     5,
      91,     7,     5,     7,     9,    84,    85,    98,    99,   100,
     101,   102,   121,   122,     7,     7,    99,     7,   102,    99,
       5,     7,    99,    99,   120,    65,    99,     5,     5,     7,
       9,    12,    14,    19,    22,    32,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   119,   139,   140,    99,   165,   166,   116,   116,
     117,   116,    17,     5,    35,     9,    12,   174,   119,   123,
     124,   124,    35,     9,    52,   140,    71,    78,    99,   122,
     125,   127,   134,   149,   161,   162,    17,    35,    99,    99,
       9,    18,    52,   140,    99,   120,   117,   122,   122,   104,
     104,   104,   104,    19,    22,    25,    28,    30,    47,    49,
      35,    36,    37,    38,    33,    34,    39,    45,    42,    40,
      15,    43,     6,    20,     6,    13,   120,    13,    92,    18,
       8,    13,     6,     8,    16,   122,   116,   141,   142,   116,
      99,     8,   120,     8,   123,     8,   116,     6,    91,    18,
       5,    88,    18,    20,    21,    23,    24,    27,    29,    31,
      44,    46,    48,    50,    52,     8,   161,    99,     9,    18,
      86,    52,   116,   116,     6,    17,     6,     8,    10,    18,
     105,   105,   104,   104,   104,   106,   106,   107,   107,   107,
     107,   108,   108,   109,   110,   111,   112,   116,   113,   116,
      39,    99,   139,    93,    95,   116,   165,   116,     6,    13,
      10,    16,    99,    10,     7,    99,   122,   134,   135,     7,
     142,   116,   116,    52,   116,    52,   116,   116,   116,   116,
     116,   116,   116,   116,    35,   116,   116,   116,    10,    52,
       7,   152,    99,   104,    18,   116,    16,    99,     9,    18,
      66,    67,    68,   173,   175,   176,    99,    10,   141,   116,
       9,    18,    52,    52,   162,    13,    92,    71,   119,   153,
     154,     6,    89,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    10,    52,    87,     9,    18,    52,   151,
     116,   115,    18,    10,   116,    16,    16,    16,    94,   173,
     175,    91,    10,   116,   116,     8,   134,    93,     5,   116,
       8,   153,    18,    86,   116,   116,     8,   119,   150,   116,
     140,    10,    52,   119,   159,   160,   135,    16,    52,   116,
     116,    10,    52,    54,    59,    62,    63,    69,    71,   125,
     127,   137,   138,   143,   144,   145,   148,   149,   152,    92,
       9,    52,    55,    58,    94,   159,     6,    99,    52,    87,
      18,    52,    52,   150,     5,     5,     7,    71,    99,   128,
     136,     5,    93,   116,   116,   130,   131,    16,     7,    52,
      88,   116,    76,   139,   116,   128,   129,     5,     5,    52,
     116,   176,    10,    90,    13,    16,     7,   119,   155,   156,
     116,    52,     5,    52,     6,     8,   128,   135,   142,     6,
      94,    52,   116,   130,     7,   125,   127,   149,   157,   158,
      55,    58,     8,   155,    89,   116,   116,   150,     6,     6,
       7,   158,     8,   157,   131,    16,     8,     6,    52,    60,
       7,    52,   147,     8,    16,     7,   149,   150,    55,    58,
     132,   133,     8,    55,    58,   146,     7,   154,     6,   131,
      16,     8,   132,   131,    16,   154,     8,   150,    16,   128,
      16,   150,     8,   128,    52,   150,    52
  };

  const unsigned char
  P5Parser::yyr1_[] =
  {
       0,    96,    97,    98,    99,   100,   101,   101,   101,   101,
     101,   102,   102,   103,   103,   103,   103,   103,   104,   104,
     105,   105,   105,   105,   106,   106,   106,   107,   107,   107,
     108,   108,   108,   108,   108,   109,   109,   109,   110,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   116,   116,   116,   117,   117,   118,   118,   118,
     119,   119,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   121,   121,   122,   122,   122,   123,   123,   123,   123,
     124,   124,   125,   125,   125,   126,   126,   127,   127,   127,
     127,   127,   127,   127,   128,   128,   128,   129,   129,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   137,   137,   138,   139,   139,   139,   139,   139,
     140,   140,   141,   142,   142,   143,   144,   144,   145,   146,
     146,   147,   147,   148,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   151,   151,
     152,   153,   153,   154,   154,   155,   155,   156,   156,   157,
     157,   157,   158,   158,   159,   159,   160,   160,   161,   161,
     161,   161,   161,   161,   161,   162,   162,   163,   163,   164,
     165,   165,   166,   166,   167,   168,   168,   169,   169,   170,
     170,   170,   170,   171,   172,   173,   173,   173,   173,   173,
     173,   173,   174,   174,   175,   175,   175,   176,   176,   176,
     176,   177,   177
  };

  const signed char
  P5Parser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     4,     1,     2,     2,     2,     2,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     2,     4,     5,     1,     3,     2,     5,     5,
       0,     2,     4,     4,     1,     1,     3,     4,     6,     1,
       3,     4,     3,     1,     6,     5,     4,     6,     7,    10,
       1,     2,     7,    10,    13,     4,     7,     4,     6,     7,
       9,    10,    12,     5,     2,     5,     3,     1,     2,     1,
       3,     1,     3,     5,     4,     1,     2,     1,     4,     1,
       3,     7,     2,     2,     2,     3,     5,     4,     6,     5,
       1,     3,     1,     1,     3,     6,     5,     7,     9,     4,
       3,     0,     2,     7,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     3,     3,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     2,
       3,     5,     3,     1,     2,     7,     6,     1,     2,     1,
       1,     1,     1,     2,     7,     6,     1,     2,     5,    11,
       7,     4,     1,     1,     1,     1,     2,     8,     5,     3,
       1,     3,     1,     3,     5,     5,     5,     8,    13,     2,
       2,     2,     2,     6,     5,     2,     2,     2,     2,     3,
       2,     2,     1,     2,     2,     2,     2,     1,     1,     2,
       2,     1,     0
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const P5Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "END", "UNEXPECTED_TOKEN", "\"(\"",
  "\")\"", "\"{\"", "\"}\"", "\"[\"", "\"]\"", "\"@\"", "\".\"", "\",\"",
  "\"~\"", "\"?\"", "\":\"", "\"::\"", "\"=\"", "\"+\"", "\"++\"",
  "\"+=\"", "\"-\"", "\"--\"", "\"-=\"", "\"*\"", "\"**\"", "\"*=\"",
  "\"/\"", "\"/=\"", "\"%\"", "\"%=\"", "\"!\"", "\"==\"", "\"!=\"",
  "\">\"", "\"<\"", "\">=\"", "\"<=\"", "\"&\"", "\"&&\"", "\"&=\"",
  "\"|\"", "\"||\"", "\"|=\"", "\"^\"", "\"^=\"", "\">>\"", "\">>=\"",
  "\"<<\"", "\"<<=\"", "\"#\"", "\";\"", "NEWLINE", "BREAK", "CASE",
  "CONST", "CLASS", "DEFAULT", "DO", "ELSE", "ENUM", "FOR", "IF", "INT",
  "NAMESPACE", "PRIVATE", "PROTECTED", "PUBLIC", "RETURN", "STRUCT",
  "SWITCH", "TYPEDEF", "UNION", "UINT", "USING", "WHILE", "VOID", "KEY",
  "CONTROL_PARAMETERS", "MA_ID", "SIZE", "HEADER", "TABLE", "IDENTIFIER",
  "INTEGER", "'['", "']'", "'='", "';'", "\"&&&\"", "'('", "')'", "'{'",
  "'}'", "':'", "$accept", "program", "string_lit", "ID", "const_value",
  "primary_expression", "postfix_expression", "unary_expression",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "expression", "expression_list", "annotation",
  "annotations", "type_ref", "field_ref_no_slice", "field_ref",
  "field_dec", "struct_field_list", "constant_declaration",
  "header_declaration", "variable_declaration", "return_value_type",
  "return_value_type_list", "value_masked_or_set", "value_list",
  "case_entry", "case_list", "field_ref_or_func", "select_exp",
  "return_select_statement", "return_statement", "break_statement",
  "parameter", "param_list", "arg", "arg_list", "do_while_statement",
  "conditional_statement", "for_loop_statement", "case", "switch_cases",
  "switch_statement", "assignment_or_call_statement", "action_statement",
  "action_statement_list", "action_compound_statement", "key_element",
  "key_element_list", "key_case_entry", "key_case_list",
  "program_selection_statement", "program_selection_statement_list",
  "table_case_entry", "table_case_list", "table_property",
  "table_property_list", "table_declaration", "typedef_declaration",
  "enumerator", "enumerator_list", "enum_declaration",
  "struct_union_type_declaration", "class_declaration", "type_declaration",
  "function_declaration", "namespace", "declaration", "declaration_list",
  "specifier", "declaration_list_with_specifier", "input", YY_NULLPTR
  };

#if YYDEBUG
  const short
  P5Parser::yyrline_[] =
  {
       0,   226,   226,   235,   239,   249,   252,   253,   254,   255,
     256,   260,   261,   265,   266,   267,   268,   269,   273,   274,
     278,   279,   280,   281,   285,   286,   287,   291,   292,   293,
     297,   298,   299,   300,   301,   305,   306,   307,   311,   312,
     316,   317,   321,   322,   326,   327,   331,   332,   336,   337,
     341,   342,   343,   344,   345,   349,   350,   359,   360,   361,
     364,   365,   373,   374,   375,   376,   377,   378,   379,   382,
     383,   384,   385,   388,   389,   390,   393,   394,   395,   396,
     399,   400,   410,   411,   412,   415,   416,   419,   420,   421,
     422,   423,   424,   425,   434,   435,   436,   439,   440,   443,
     444,   447,   448,   451,   452,   455,   456,   459,   460,   463,
     464,   467,   470,   471,   474,   482,   483,   484,   485,   486,
     489,   490,   493,   495,   496,   499,   502,   503,   506,   508,
     509,   512,   513,   516,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   547,   548,
     551,   560,   561,   564,   565,   568,   569,   572,   573,   576,
     577,   578,   581,   582,   585,   586,   589,   590,   593,   594,
     595,   596,   597,   598,   599,   603,   604,   607,   608,   617,
     620,   621,   624,   625,   628,   631,   632,   635,   636,   640,
     641,   642,   643,   646,   649,   659,   660,   661,   662,   663,
     664,   665,   668,   669,   672,   673,   674,   677,   678,   679,
     680,   682,   683
  };

  // Print the state stack on the debug stream.
  void
  P5Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  P5Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 7 "p5parser.ypp"
} } // P4::P5
#line 1839 "y.tab.c"

#line 687 "p5parser.ypp"


namespace P4 {

void P5::P5Parser::error(const Util::SourceInfo& location,
                         const std::string& message) {
    driver.onParseError(location, message);
}

static const IR::Expression *removeRedundantValid(const IR::Expression *e) {
    if (auto *prim = e->to<IR::Primitive>()) {
        if (prim->name == "valid")
            return prim->operands.at(0); }
    return e;
}

}  // namespace P4
