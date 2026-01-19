// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 139 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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

static int globalAnonCount = 0;


#line 62 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"


#include "p5parser.hpp"




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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 7 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
namespace P4 { namespace P5 {
#line 160 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"

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

  /*---------.
  | symbol.  |
  `---------*/



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

  P5Parser::symbol_kind_type
  P5Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  P5Parser::stack_symbol_type::stack_symbol_type ()
  {}

  P5Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_annotation: // annotation
        value.YY_MOVE_OR_COPY< IR::Annotation* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arg: // arg
        value.YY_MOVE_OR_COPY< IR::Argument* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_return_value_type_list: // return_value_type_list
      case symbol_kind::S_action_statement_list: // action_statement_list
      case symbol_kind::S_action_compound_statement: // action_compound_statement
      case symbol_kind::S_program_selection_statement_list: // program_selection_statement_list
      case symbol_kind::S_table_property_list: // table_property_list
        value.YY_MOVE_OR_COPY< IR::BlockStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_value: // const_value
        value.YY_MOVE_OR_COPY< IR::Constant* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_header_declaration: // header_declaration
        value.YY_MOVE_OR_COPY< IR::Declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant_declaration: // constant_declaration
        value.YY_MOVE_OR_COPY< IR::Declaration_Constant* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.YY_MOVE_OR_COPY< IR::Declaration_Variable* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_field_ref_no_slice: // field_ref_no_slice
      case symbol_kind::S_field_ref: // field_ref
      case symbol_kind::S_value_masked_or_set: // value_masked_or_set
      case symbol_kind::S_field_ref_or_func: // field_ref_or_func
        value.YY_MOVE_OR_COPY< IR::Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.YY_MOVE_OR_COPY< IR::Function* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
        value.YY_MOVE_OR_COPY< IR::ID* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.YY_MOVE_OR_COPY< IR::IndexedVector<IR::SerEnumMember>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_field_list: // struct_field_list
        value.YY_MOVE_OR_COPY< IR::IndexedVector<IR::StructField>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_select_exp: // select_exp
        value.YY_MOVE_OR_COPY< IR::ListExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.YY_MOVE_OR_COPY< IR::Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_case_entry: // key_case_entry
        value.YY_MOVE_OR_COPY< IR::P5KeyCase* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_element: // key_element
        value.YY_MOVE_OR_COPY< IR::P5KeyElement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_switch_entry: // key_switch_entry
        value.YY_MOVE_OR_COPY< IR::P5KeySwitch* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_table_declaration: // table_declaration
        value.YY_MOVE_OR_COPY< IR::P5Table* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter: // parameter
        value.YY_MOVE_OR_COPY< IR::Parameter* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_param_list: // param_list
        value.YY_MOVE_OR_COPY< IR::ParameterList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_action_statement: // action_statement
      case symbol_kind::S_program_selection_statement: // program_selection_statement
      case symbol_kind::S_table_property: // table_property
        value.YY_MOVE_OR_COPY< IR::StatOrDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_return_value_type: // return_value_type
      case symbol_kind::S_return_select_statement: // return_select_statement
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_do_while_statement: // do_while_statement
      case symbol_kind::S_conditional_statement: // conditional_statement
      case symbol_kind::S_for_loop_statement: // for_loop_statement
      case symbol_kind::S_switch_statement: // switch_statement
      case symbol_kind::S_assignment_or_call_statement: // assignment_or_call_statement
        value.YY_MOVE_OR_COPY< IR::Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string_lit: // string_lit
        value.YY_MOVE_OR_COPY< IR::StringLiteral* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field_dec: // field_dec
      case symbol_kind::S_anonymous_struct_union_dec: // anonymous_struct_union_dec
      case symbol_kind::S_struct_field_dec: // struct_field_dec
        value.YY_MOVE_OR_COPY< IR::StructField* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_case_entry: // case_entry
      case symbol_kind::S_case: // case
      case symbol_kind::S_table_case_entry: // table_case_entry
        value.YY_MOVE_OR_COPY< IR::SwitchCase* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enum_declaration: // enum_declaration
      case symbol_kind::S_type_declaration: // type_declaration
        value.YY_MOVE_OR_COPY< IR::Type_Declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_union_type_declaration: // struct_union_type_declaration
        value.YY_MOVE_OR_COPY< IR::Type_Struct* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_typedef_declaration: // typedef_declaration
        value.YY_MOVE_OR_COPY< IR::Type_Typedef* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_annotations: // annotations
        value.YY_MOVE_OR_COPY< IR::Vector<IR::Annotation>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.YY_MOVE_OR_COPY< IR::Vector<IR::Argument>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_value_list: // value_list
        value.YY_MOVE_OR_COPY< IR::Vector<IR::Expression>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.YY_MOVE_OR_COPY< IR::Vector<IR::Node>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_case_list: // key_case_list
        value.YY_MOVE_OR_COPY< IR::Vector<IR::P5KeyCase>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_element_list: // key_element_list
        value.YY_MOVE_OR_COPY< IR::Vector<IR::P5KeyElement>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_switch_list: // key_switch_list
        value.YY_MOVE_OR_COPY< IR::Vector<IR::P5KeySwitch>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_switch_cases: // switch_cases
      case symbol_kind::S_table_case_list: // table_case_list
        value.YY_MOVE_OR_COPY< IR::Vector<IR::SwitchCase>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.YY_MOVE_OR_COPY< P4::P5::EnumItem* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< UnparsedConstant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_ref: // type_ref
        value.YY_MOVE_OR_COPY< const IR::Type* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CASE: // CASE
      case symbol_kind::S_CONST: // CONST
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_DEFAULT: // DEFAULT
      case symbol_kind::S_DO: // DO
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_ENUM: // ENUM
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_NAMESPACE: // NAMESPACE
      case symbol_kind::S_PRIVATE: // PRIVATE
      case symbol_kind::S_PROTECTED: // PROTECTED
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_SWITCH: // SWITCH
      case symbol_kind::S_TYPEDEF: // TYPEDEF
      case symbol_kind::S_UNION: // UNION
      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_USING: // USING
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_KEY: // KEY
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_CONTROL_PARAMETERS: // CONTROL_PARAMETERS
      case symbol_kind::S_HEADER: // HEADER
      case symbol_kind::S_TABLE: // TABLE
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
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
    switch (that.kind ())
    {
      case symbol_kind::S_annotation: // annotation
        value.move< IR::Annotation* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arg: // arg
        value.move< IR::Argument* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_return_value_type_list: // return_value_type_list
      case symbol_kind::S_action_statement_list: // action_statement_list
      case symbol_kind::S_action_compound_statement: // action_compound_statement
      case symbol_kind::S_program_selection_statement_list: // program_selection_statement_list
      case symbol_kind::S_table_property_list: // table_property_list
        value.move< IR::BlockStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_value: // const_value
        value.move< IR::Constant* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_header_declaration: // header_declaration
        value.move< IR::Declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant_declaration: // constant_declaration
        value.move< IR::Declaration_Constant* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.move< IR::Declaration_Variable* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_field_ref_no_slice: // field_ref_no_slice
      case symbol_kind::S_field_ref: // field_ref
      case symbol_kind::S_value_masked_or_set: // value_masked_or_set
      case symbol_kind::S_field_ref_or_func: // field_ref_or_func
        value.move< IR::Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.move< IR::Function* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
        value.move< IR::ID* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< IR::IndexedVector<IR::SerEnumMember>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_field_list: // struct_field_list
        value.move< IR::IndexedVector<IR::StructField>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_select_exp: // select_exp
        value.move< IR::ListExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< IR::Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_case_entry: // key_case_entry
        value.move< IR::P5KeyCase* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_element: // key_element
        value.move< IR::P5KeyElement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_switch_entry: // key_switch_entry
        value.move< IR::P5KeySwitch* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_table_declaration: // table_declaration
        value.move< IR::P5Table* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter: // parameter
        value.move< IR::Parameter* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_param_list: // param_list
        value.move< IR::ParameterList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_action_statement: // action_statement
      case symbol_kind::S_program_selection_statement: // program_selection_statement
      case symbol_kind::S_table_property: // table_property
        value.move< IR::StatOrDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_return_value_type: // return_value_type
      case symbol_kind::S_return_select_statement: // return_select_statement
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_do_while_statement: // do_while_statement
      case symbol_kind::S_conditional_statement: // conditional_statement
      case symbol_kind::S_for_loop_statement: // for_loop_statement
      case symbol_kind::S_switch_statement: // switch_statement
      case symbol_kind::S_assignment_or_call_statement: // assignment_or_call_statement
        value.move< IR::Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string_lit: // string_lit
        value.move< IR::StringLiteral* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field_dec: // field_dec
      case symbol_kind::S_anonymous_struct_union_dec: // anonymous_struct_union_dec
      case symbol_kind::S_struct_field_dec: // struct_field_dec
        value.move< IR::StructField* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_case_entry: // case_entry
      case symbol_kind::S_case: // case
      case symbol_kind::S_table_case_entry: // table_case_entry
        value.move< IR::SwitchCase* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enum_declaration: // enum_declaration
      case symbol_kind::S_type_declaration: // type_declaration
        value.move< IR::Type_Declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_union_type_declaration: // struct_union_type_declaration
        value.move< IR::Type_Struct* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_typedef_declaration: // typedef_declaration
        value.move< IR::Type_Typedef* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_annotations: // annotations
        value.move< IR::Vector<IR::Annotation>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.move< IR::Vector<IR::Argument>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_value_list: // value_list
        value.move< IR::Vector<IR::Expression>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.move< IR::Vector<IR::Node>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_case_list: // key_case_list
        value.move< IR::Vector<IR::P5KeyCase>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_element_list: // key_element_list
        value.move< IR::Vector<IR::P5KeyElement>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_switch_list: // key_switch_list
        value.move< IR::Vector<IR::P5KeySwitch>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_switch_cases: // switch_cases
      case symbol_kind::S_table_case_list: // table_case_list
        value.move< IR::Vector<IR::SwitchCase>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< P4::P5::EnumItem* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< UnparsedConstant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_ref: // type_ref
        value.move< const IR::Type* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CASE: // CASE
      case symbol_kind::S_CONST: // CONST
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_DEFAULT: // DEFAULT
      case symbol_kind::S_DO: // DO
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_ENUM: // ENUM
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_NAMESPACE: // NAMESPACE
      case symbol_kind::S_PRIVATE: // PRIVATE
      case symbol_kind::S_PROTECTED: // PROTECTED
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_SWITCH: // SWITCH
      case symbol_kind::S_TYPEDEF: // TYPEDEF
      case symbol_kind::S_UNION: // UNION
      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_USING: // USING
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_KEY: // KEY
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_CONTROL_PARAMETERS: // CONTROL_PARAMETERS
      case symbol_kind::S_HEADER: // HEADER
      case symbol_kind::S_TABLE: // TABLE
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.move< cstring > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  P5Parser::stack_symbol_type&
  P5Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_annotation: // annotation
        value.copy< IR::Annotation* > (that.value);
        break;

      case symbol_kind::S_arg: // arg
        value.copy< IR::Argument* > (that.value);
        break;

      case symbol_kind::S_return_value_type_list: // return_value_type_list
      case symbol_kind::S_action_statement_list: // action_statement_list
      case symbol_kind::S_action_compound_statement: // action_compound_statement
      case symbol_kind::S_program_selection_statement_list: // program_selection_statement_list
      case symbol_kind::S_table_property_list: // table_property_list
        value.copy< IR::BlockStatement* > (that.value);
        break;

      case symbol_kind::S_const_value: // const_value
        value.copy< IR::Constant* > (that.value);
        break;

      case symbol_kind::S_header_declaration: // header_declaration
        value.copy< IR::Declaration* > (that.value);
        break;

      case symbol_kind::S_constant_declaration: // constant_declaration
        value.copy< IR::Declaration_Constant* > (that.value);
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.copy< IR::Declaration_Variable* > (that.value);
        break;

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_field_ref_no_slice: // field_ref_no_slice
      case symbol_kind::S_field_ref: // field_ref
      case symbol_kind::S_value_masked_or_set: // value_masked_or_set
      case symbol_kind::S_field_ref_or_func: // field_ref_or_func
        value.copy< IR::Expression* > (that.value);
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.copy< IR::Function* > (that.value);
        break;

      case symbol_kind::S_ID: // ID
        value.copy< IR::ID* > (that.value);
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.copy< IR::IndexedVector<IR::SerEnumMember>* > (that.value);
        break;

      case symbol_kind::S_struct_field_list: // struct_field_list
        value.copy< IR::IndexedVector<IR::StructField>* > (that.value);
        break;

      case symbol_kind::S_select_exp: // select_exp
        value.copy< IR::ListExpression* > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.copy< IR::Node* > (that.value);
        break;

      case symbol_kind::S_key_case_entry: // key_case_entry
        value.copy< IR::P5KeyCase* > (that.value);
        break;

      case symbol_kind::S_key_element: // key_element
        value.copy< IR::P5KeyElement* > (that.value);
        break;

      case symbol_kind::S_key_switch_entry: // key_switch_entry
        value.copy< IR::P5KeySwitch* > (that.value);
        break;

      case symbol_kind::S_table_declaration: // table_declaration
        value.copy< IR::P5Table* > (that.value);
        break;

      case symbol_kind::S_parameter: // parameter
        value.copy< IR::Parameter* > (that.value);
        break;

      case symbol_kind::S_param_list: // param_list
        value.copy< IR::ParameterList* > (that.value);
        break;

      case symbol_kind::S_action_statement: // action_statement
      case symbol_kind::S_program_selection_statement: // program_selection_statement
      case symbol_kind::S_table_property: // table_property
        value.copy< IR::StatOrDecl* > (that.value);
        break;

      case symbol_kind::S_return_value_type: // return_value_type
      case symbol_kind::S_return_select_statement: // return_select_statement
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_do_while_statement: // do_while_statement
      case symbol_kind::S_conditional_statement: // conditional_statement
      case symbol_kind::S_for_loop_statement: // for_loop_statement
      case symbol_kind::S_switch_statement: // switch_statement
      case symbol_kind::S_assignment_or_call_statement: // assignment_or_call_statement
        value.copy< IR::Statement* > (that.value);
        break;

      case symbol_kind::S_string_lit: // string_lit
        value.copy< IR::StringLiteral* > (that.value);
        break;

      case symbol_kind::S_field_dec: // field_dec
      case symbol_kind::S_anonymous_struct_union_dec: // anonymous_struct_union_dec
      case symbol_kind::S_struct_field_dec: // struct_field_dec
        value.copy< IR::StructField* > (that.value);
        break;

      case symbol_kind::S_case_entry: // case_entry
      case symbol_kind::S_case: // case
      case symbol_kind::S_table_case_entry: // table_case_entry
        value.copy< IR::SwitchCase* > (that.value);
        break;

      case symbol_kind::S_enum_declaration: // enum_declaration
      case symbol_kind::S_type_declaration: // type_declaration
        value.copy< IR::Type_Declaration* > (that.value);
        break;

      case symbol_kind::S_struct_union_type_declaration: // struct_union_type_declaration
        value.copy< IR::Type_Struct* > (that.value);
        break;

      case symbol_kind::S_typedef_declaration: // typedef_declaration
        value.copy< IR::Type_Typedef* > (that.value);
        break;

      case symbol_kind::S_annotations: // annotations
        value.copy< IR::Vector<IR::Annotation>* > (that.value);
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.copy< IR::Vector<IR::Argument>* > (that.value);
        break;

      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_value_list: // value_list
        value.copy< IR::Vector<IR::Expression>* > (that.value);
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.copy< IR::Vector<IR::Node>* > (that.value);
        break;

      case symbol_kind::S_key_case_list: // key_case_list
        value.copy< IR::Vector<IR::P5KeyCase>* > (that.value);
        break;

      case symbol_kind::S_key_element_list: // key_element_list
        value.copy< IR::Vector<IR::P5KeyElement>* > (that.value);
        break;

      case symbol_kind::S_key_switch_list: // key_switch_list
        value.copy< IR::Vector<IR::P5KeySwitch>* > (that.value);
        break;

      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_switch_cases: // switch_cases
      case symbol_kind::S_table_case_list: // table_case_list
        value.copy< IR::Vector<IR::SwitchCase>* > (that.value);
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.copy< P4::P5::EnumItem* > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< UnparsedConstant > (that.value);
        break;

      case symbol_kind::S_type_ref: // type_ref
        value.copy< const IR::Type* > (that.value);
        break;

      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CASE: // CASE
      case symbol_kind::S_CONST: // CONST
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_DEFAULT: // DEFAULT
      case symbol_kind::S_DO: // DO
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_ENUM: // ENUM
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_NAMESPACE: // NAMESPACE
      case symbol_kind::S_PRIVATE: // PRIVATE
      case symbol_kind::S_PROTECTED: // PROTECTED
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_SWITCH: // SWITCH
      case symbol_kind::S_TYPEDEF: // TYPEDEF
      case symbol_kind::S_UNION: // UNION
      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_USING: // USING
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_KEY: // KEY
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_CONTROL_PARAMETERS: // CONTROL_PARAMETERS
      case symbol_kind::S_HEADER: // HEADER
      case symbol_kind::S_TABLE: // TABLE
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
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
    switch (that.kind ())
    {
      case symbol_kind::S_annotation: // annotation
        value.move< IR::Annotation* > (that.value);
        break;

      case symbol_kind::S_arg: // arg
        value.move< IR::Argument* > (that.value);
        break;

      case symbol_kind::S_return_value_type_list: // return_value_type_list
      case symbol_kind::S_action_statement_list: // action_statement_list
      case symbol_kind::S_action_compound_statement: // action_compound_statement
      case symbol_kind::S_program_selection_statement_list: // program_selection_statement_list
      case symbol_kind::S_table_property_list: // table_property_list
        value.move< IR::BlockStatement* > (that.value);
        break;

      case symbol_kind::S_const_value: // const_value
        value.move< IR::Constant* > (that.value);
        break;

      case symbol_kind::S_header_declaration: // header_declaration
        value.move< IR::Declaration* > (that.value);
        break;

      case symbol_kind::S_constant_declaration: // constant_declaration
        value.move< IR::Declaration_Constant* > (that.value);
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.move< IR::Declaration_Variable* > (that.value);
        break;

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_field_ref_no_slice: // field_ref_no_slice
      case symbol_kind::S_field_ref: // field_ref
      case symbol_kind::S_value_masked_or_set: // value_masked_or_set
      case symbol_kind::S_field_ref_or_func: // field_ref_or_func
        value.move< IR::Expression* > (that.value);
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.move< IR::Function* > (that.value);
        break;

      case symbol_kind::S_ID: // ID
        value.move< IR::ID* > (that.value);
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< IR::IndexedVector<IR::SerEnumMember>* > (that.value);
        break;

      case symbol_kind::S_struct_field_list: // struct_field_list
        value.move< IR::IndexedVector<IR::StructField>* > (that.value);
        break;

      case symbol_kind::S_select_exp: // select_exp
        value.move< IR::ListExpression* > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< IR::Node* > (that.value);
        break;

      case symbol_kind::S_key_case_entry: // key_case_entry
        value.move< IR::P5KeyCase* > (that.value);
        break;

      case symbol_kind::S_key_element: // key_element
        value.move< IR::P5KeyElement* > (that.value);
        break;

      case symbol_kind::S_key_switch_entry: // key_switch_entry
        value.move< IR::P5KeySwitch* > (that.value);
        break;

      case symbol_kind::S_table_declaration: // table_declaration
        value.move< IR::P5Table* > (that.value);
        break;

      case symbol_kind::S_parameter: // parameter
        value.move< IR::Parameter* > (that.value);
        break;

      case symbol_kind::S_param_list: // param_list
        value.move< IR::ParameterList* > (that.value);
        break;

      case symbol_kind::S_action_statement: // action_statement
      case symbol_kind::S_program_selection_statement: // program_selection_statement
      case symbol_kind::S_table_property: // table_property
        value.move< IR::StatOrDecl* > (that.value);
        break;

      case symbol_kind::S_return_value_type: // return_value_type
      case symbol_kind::S_return_select_statement: // return_select_statement
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_do_while_statement: // do_while_statement
      case symbol_kind::S_conditional_statement: // conditional_statement
      case symbol_kind::S_for_loop_statement: // for_loop_statement
      case symbol_kind::S_switch_statement: // switch_statement
      case symbol_kind::S_assignment_or_call_statement: // assignment_or_call_statement
        value.move< IR::Statement* > (that.value);
        break;

      case symbol_kind::S_string_lit: // string_lit
        value.move< IR::StringLiteral* > (that.value);
        break;

      case symbol_kind::S_field_dec: // field_dec
      case symbol_kind::S_anonymous_struct_union_dec: // anonymous_struct_union_dec
      case symbol_kind::S_struct_field_dec: // struct_field_dec
        value.move< IR::StructField* > (that.value);
        break;

      case symbol_kind::S_case_entry: // case_entry
      case symbol_kind::S_case: // case
      case symbol_kind::S_table_case_entry: // table_case_entry
        value.move< IR::SwitchCase* > (that.value);
        break;

      case symbol_kind::S_enum_declaration: // enum_declaration
      case symbol_kind::S_type_declaration: // type_declaration
        value.move< IR::Type_Declaration* > (that.value);
        break;

      case symbol_kind::S_struct_union_type_declaration: // struct_union_type_declaration
        value.move< IR::Type_Struct* > (that.value);
        break;

      case symbol_kind::S_typedef_declaration: // typedef_declaration
        value.move< IR::Type_Typedef* > (that.value);
        break;

      case symbol_kind::S_annotations: // annotations
        value.move< IR::Vector<IR::Annotation>* > (that.value);
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.move< IR::Vector<IR::Argument>* > (that.value);
        break;

      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_value_list: // value_list
        value.move< IR::Vector<IR::Expression>* > (that.value);
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.move< IR::Vector<IR::Node>* > (that.value);
        break;

      case symbol_kind::S_key_case_list: // key_case_list
        value.move< IR::Vector<IR::P5KeyCase>* > (that.value);
        break;

      case symbol_kind::S_key_element_list: // key_element_list
        value.move< IR::Vector<IR::P5KeyElement>* > (that.value);
        break;

      case symbol_kind::S_key_switch_list: // key_switch_list
        value.move< IR::Vector<IR::P5KeySwitch>* > (that.value);
        break;

      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_switch_cases: // switch_cases
      case symbol_kind::S_table_case_list: // table_case_list
        value.move< IR::Vector<IR::SwitchCase>* > (that.value);
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< P4::P5::EnumItem* > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< UnparsedConstant > (that.value);
        break;

      case symbol_kind::S_type_ref: // type_ref
        value.move< const IR::Type* > (that.value);
        break;

      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CASE: // CASE
      case symbol_kind::S_CONST: // CONST
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_DEFAULT: // DEFAULT
      case symbol_kind::S_DO: // DO
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_ENUM: // ENUM
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_NAMESPACE: // NAMESPACE
      case symbol_kind::S_PRIVATE: // PRIVATE
      case symbol_kind::S_PROTECTED: // PROTECTED
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_SWITCH: // SWITCH
      case symbol_kind::S_TYPEDEF: // TYPEDEF
      case symbol_kind::S_UNION: // UNION
      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_USING: // USING
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_KEY: // KEY
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_CONTROL_PARAMETERS: // CONTROL_PARAMETERS
      case symbol_kind::S_HEADER: // HEADER
      case symbol_kind::S_TABLE: // TABLE
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
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
  P5Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_BREAK: // BREAK
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1236 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_CASE: // CASE
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1242 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_CONST: // CONST
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1248 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_CLASS: // CLASS
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1254 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_DEFAULT: // DEFAULT
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1260 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_DO: // DO
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1266 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1272 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_ENUM: // ENUM
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1278 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1284 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1290 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_INT: // INT
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1296 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_NAMESPACE: // NAMESPACE
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1302 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_PRIVATE: // PRIVATE
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1308 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_PROTECTED: // PROTECTED
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1314 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_PUBLIC: // PUBLIC
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1320 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1326 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_STRUCT: // STRUCT
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1332 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_SWITCH: // SWITCH
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1338 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_TYPEDEF: // TYPEDEF
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1344 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_UNION: // UNION
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1350 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_UINT: // UINT
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1356 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_USING: // USING
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1362 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1368 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_VOID: // VOID
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1374 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_KEY: // KEY
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1380 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_SIZE: // SIZE
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1386 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_CONTROL_PARAMETERS: // CONTROL_PARAMETERS
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1392 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_HEADER: // HEADER
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1398 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_TABLE: // TABLE
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1404 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1410 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1416 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < UnparsedConstant > (); }
#line 1422 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_string_lit: // string_lit
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::StringLiteral* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1435 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::ID* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1448 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_const_value: // const_value
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Constant* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1461 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_primary_expression: // primary_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1474 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1487 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_unary_expression: // unary_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1500 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_cast_expression: // cast_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1513 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1526 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_additive_expression: // additive_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1539 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_shift_expression: // shift_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1552 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_relational_expression: // relational_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1565 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_equality_expression: // equality_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1578 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_and_expression: // and_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1591 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1604 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1617 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1630 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_logical_or_expression: // logical_or_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1643 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_conditional_expression: // conditional_expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1656 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_expression: // expression
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1669 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_expression_list: // expression_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::Expression>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1682 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_annotation: // annotation
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Annotation* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1695 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_annotations: // annotations
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::Annotation>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1708 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_type_ref: // type_ref
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < const IR::Type* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1721 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_field_ref_no_slice: // field_ref_no_slice
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1734 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_field_ref: // field_ref
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1747 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_field_dec: // field_dec
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::StructField* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1760 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_anonymous_struct_union_dec: // anonymous_struct_union_dec
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::StructField* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1773 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_struct_field_dec: // struct_field_dec
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::StructField* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1786 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_struct_field_list: // struct_field_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::IndexedVector<IR::StructField>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1799 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_constant_declaration: // constant_declaration
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Declaration_Constant* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1812 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_header_declaration: // header_declaration
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Declaration* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1825 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Declaration_Variable* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1838 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_return_value_type: // return_value_type
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1851 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_return_value_type_list: // return_value_type_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::BlockStatement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1864 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_value_masked_or_set: // value_masked_or_set
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1877 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_value_list: // value_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::Expression>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1890 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_case_entry: // case_entry
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::SwitchCase* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1903 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_case_list: // case_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::SwitchCase>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1916 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_field_ref_or_func: // field_ref_or_func
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1929 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_select_exp: // select_exp
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::ListExpression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1942 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_return_select_statement: // return_select_statement
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1955 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_return_statement: // return_statement
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1968 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_break_statement: // break_statement
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1981 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_parameter: // parameter
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Parameter* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1994 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_param_list: // param_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::ParameterList* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2007 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_arg: // arg
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Argument* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2020 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_arg_list: // arg_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::Argument>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2033 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_do_while_statement: // do_while_statement
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2046 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_conditional_statement: // conditional_statement
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2059 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_for_loop_statement: // for_loop_statement
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2072 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_case: // case
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::SwitchCase* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2085 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_switch_cases: // switch_cases
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::SwitchCase>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2098 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_switch_statement: // switch_statement
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2111 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_assignment_or_call_statement: // assignment_or_call_statement
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2124 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_action_statement: // action_statement
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::StatOrDecl* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2137 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_action_statement_list: // action_statement_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::BlockStatement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2150 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_action_compound_statement: // action_compound_statement
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::BlockStatement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2163 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_key_element: // key_element
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::P5KeyElement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2176 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_key_element_list: // key_element_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::P5KeyElement>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2189 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_key_case_entry: // key_case_entry
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::P5KeyCase* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2202 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_key_case_list: // key_case_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::P5KeyCase>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2215 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_key_switch_entry: // key_switch_entry
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::P5KeySwitch* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2228 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_key_switch_list: // key_switch_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::P5KeySwitch>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2241 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_program_selection_statement: // program_selection_statement
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::StatOrDecl* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2254 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_program_selection_statement_list: // program_selection_statement_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::BlockStatement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2267 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_table_case_entry: // table_case_entry
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::SwitchCase* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2280 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_table_case_list: // table_case_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::SwitchCase>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2293 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_table_property: // table_property
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::StatOrDecl* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2306 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_table_property_list: // table_property_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::BlockStatement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2319 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_table_declaration: // table_declaration
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::P5Table* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2332 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_typedef_declaration: // typedef_declaration
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Type_Typedef* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2345 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_enumerator: // enumerator
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < P4::P5::EnumItem* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2358 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::IndexedVector<IR::SerEnumMember>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2371 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_enum_declaration: // enum_declaration
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Type_Declaration* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2384 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_struct_union_type_declaration: // struct_union_type_declaration
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Type_Struct* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2397 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_type_declaration: // type_declaration
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Type_Declaration* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2410 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_function_declaration: // function_declaration
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Function* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2423 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_declaration: // declaration
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Node* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2436 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_declaration_list: // declaration_list
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::Node>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2449 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      default:
        break;
    }
        yyo << ')';
      }
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
  P5Parser::yypop_ (int n) YY_NOEXCEPT
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
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  P5Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  P5Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
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
    YY_STACK_PRINT ();

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
        YYCDEBUG << "Reading a token\n";
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
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
      case symbol_kind::S_annotation: // annotation
        yylhs.value.emplace< IR::Annotation* > ();
        break;

      case symbol_kind::S_arg: // arg
        yylhs.value.emplace< IR::Argument* > ();
        break;

      case symbol_kind::S_return_value_type_list: // return_value_type_list
      case symbol_kind::S_action_statement_list: // action_statement_list
      case symbol_kind::S_action_compound_statement: // action_compound_statement
      case symbol_kind::S_program_selection_statement_list: // program_selection_statement_list
      case symbol_kind::S_table_property_list: // table_property_list
        yylhs.value.emplace< IR::BlockStatement* > ();
        break;

      case symbol_kind::S_const_value: // const_value
        yylhs.value.emplace< IR::Constant* > ();
        break;

      case symbol_kind::S_header_declaration: // header_declaration
        yylhs.value.emplace< IR::Declaration* > ();
        break;

      case symbol_kind::S_constant_declaration: // constant_declaration
        yylhs.value.emplace< IR::Declaration_Constant* > ();
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        yylhs.value.emplace< IR::Declaration_Variable* > ();
        break;

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_conditional_expression: // conditional_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_field_ref_no_slice: // field_ref_no_slice
      case symbol_kind::S_field_ref: // field_ref
      case symbol_kind::S_value_masked_or_set: // value_masked_or_set
      case symbol_kind::S_field_ref_or_func: // field_ref_or_func
        yylhs.value.emplace< IR::Expression* > ();
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        yylhs.value.emplace< IR::Function* > ();
        break;

      case symbol_kind::S_ID: // ID
        yylhs.value.emplace< IR::ID* > ();
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        yylhs.value.emplace< IR::IndexedVector<IR::SerEnumMember>* > ();
        break;

      case symbol_kind::S_struct_field_list: // struct_field_list
        yylhs.value.emplace< IR::IndexedVector<IR::StructField>* > ();
        break;

      case symbol_kind::S_select_exp: // select_exp
        yylhs.value.emplace< IR::ListExpression* > ();
        break;

      case symbol_kind::S_declaration: // declaration
        yylhs.value.emplace< IR::Node* > ();
        break;

      case symbol_kind::S_key_case_entry: // key_case_entry
        yylhs.value.emplace< IR::P5KeyCase* > ();
        break;

      case symbol_kind::S_key_element: // key_element
        yylhs.value.emplace< IR::P5KeyElement* > ();
        break;

      case symbol_kind::S_key_switch_entry: // key_switch_entry
        yylhs.value.emplace< IR::P5KeySwitch* > ();
        break;

      case symbol_kind::S_table_declaration: // table_declaration
        yylhs.value.emplace< IR::P5Table* > ();
        break;

      case symbol_kind::S_parameter: // parameter
        yylhs.value.emplace< IR::Parameter* > ();
        break;

      case symbol_kind::S_param_list: // param_list
        yylhs.value.emplace< IR::ParameterList* > ();
        break;

      case symbol_kind::S_action_statement: // action_statement
      case symbol_kind::S_program_selection_statement: // program_selection_statement
      case symbol_kind::S_table_property: // table_property
        yylhs.value.emplace< IR::StatOrDecl* > ();
        break;

      case symbol_kind::S_return_value_type: // return_value_type
      case symbol_kind::S_return_select_statement: // return_select_statement
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_do_while_statement: // do_while_statement
      case symbol_kind::S_conditional_statement: // conditional_statement
      case symbol_kind::S_for_loop_statement: // for_loop_statement
      case symbol_kind::S_switch_statement: // switch_statement
      case symbol_kind::S_assignment_or_call_statement: // assignment_or_call_statement
        yylhs.value.emplace< IR::Statement* > ();
        break;

      case symbol_kind::S_string_lit: // string_lit
        yylhs.value.emplace< IR::StringLiteral* > ();
        break;

      case symbol_kind::S_field_dec: // field_dec
      case symbol_kind::S_anonymous_struct_union_dec: // anonymous_struct_union_dec
      case symbol_kind::S_struct_field_dec: // struct_field_dec
        yylhs.value.emplace< IR::StructField* > ();
        break;

      case symbol_kind::S_case_entry: // case_entry
      case symbol_kind::S_case: // case
      case symbol_kind::S_table_case_entry: // table_case_entry
        yylhs.value.emplace< IR::SwitchCase* > ();
        break;

      case symbol_kind::S_enum_declaration: // enum_declaration
      case symbol_kind::S_type_declaration: // type_declaration
        yylhs.value.emplace< IR::Type_Declaration* > ();
        break;

      case symbol_kind::S_struct_union_type_declaration: // struct_union_type_declaration
        yylhs.value.emplace< IR::Type_Struct* > ();
        break;

      case symbol_kind::S_typedef_declaration: // typedef_declaration
        yylhs.value.emplace< IR::Type_Typedef* > ();
        break;

      case symbol_kind::S_annotations: // annotations
        yylhs.value.emplace< IR::Vector<IR::Annotation>* > ();
        break;

      case symbol_kind::S_arg_list: // arg_list
        yylhs.value.emplace< IR::Vector<IR::Argument>* > ();
        break;

      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_value_list: // value_list
        yylhs.value.emplace< IR::Vector<IR::Expression>* > ();
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        yylhs.value.emplace< IR::Vector<IR::Node>* > ();
        break;

      case symbol_kind::S_key_case_list: // key_case_list
        yylhs.value.emplace< IR::Vector<IR::P5KeyCase>* > ();
        break;

      case symbol_kind::S_key_element_list: // key_element_list
        yylhs.value.emplace< IR::Vector<IR::P5KeyElement>* > ();
        break;

      case symbol_kind::S_key_switch_list: // key_switch_list
        yylhs.value.emplace< IR::Vector<IR::P5KeySwitch>* > ();
        break;

      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_switch_cases: // switch_cases
      case symbol_kind::S_table_case_list: // table_case_list
        yylhs.value.emplace< IR::Vector<IR::SwitchCase>* > ();
        break;

      case symbol_kind::S_enumerator: // enumerator
        yylhs.value.emplace< P4::P5::EnumItem* > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        yylhs.value.emplace< UnparsedConstant > ();
        break;

      case symbol_kind::S_type_ref: // type_ref
        yylhs.value.emplace< const IR::Type* > ();
        break;

      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CASE: // CASE
      case symbol_kind::S_CONST: // CONST
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_DEFAULT: // DEFAULT
      case symbol_kind::S_DO: // DO
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_ENUM: // ENUM
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_NAMESPACE: // NAMESPACE
      case symbol_kind::S_PRIVATE: // PRIVATE
      case symbol_kind::S_PROTECTED: // PROTECTED
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_SWITCH: // SWITCH
      case symbol_kind::S_TYPEDEF: // TYPEDEF
      case symbol_kind::S_UNION: // UNION
      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_USING: // USING
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_KEY: // KEY
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_CONTROL_PARAMETERS: // CONTROL_PARAMETERS
      case symbol_kind::S_HEADER: // HEADER
      case symbol_kind::S_TABLE: // TABLE
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
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
  case 2: // program: input END
#line 328 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                    { YYACCEPT; }
#line 2933 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 3: // string_lit: STRING_LITERAL
#line 337 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         { yylhs.value.as < IR::StringLiteral* > () = new IR::StringLiteral(yystack_[0].location, yystack_[0].value.as < cstring > ()); }
#line 2939 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 4: // ID: IDENTIFIER
#line 341 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     { yylhs.value.as < IR::ID* > () = new IR::ID(yystack_[0].location, yystack_[0].value.as < cstring > ()); }
#line 2945 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 5: // const_value: INTEGER
#line 351 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                  { yylhs.value.as < IR::Constant* > () = parseConstant(yystack_[0].location, yystack_[0].value.as < UnparsedConstant > (), 0); }
#line 2951 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 6: // primary_expression: field_ref
#line 354 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 2957 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 7: // primary_expression: const_value
#line 355 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Constant* > (); }
#line 2963 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 8: // primary_expression: string_lit
#line 356 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::StringLiteral* > (); }
#line 2969 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 9: // primary_expression: "(" expression ")"
#line 357 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[1].value.as < IR::Expression* > (); }
#line 2975 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 10: // primary_expression: "{" expression_list "}"
#line 358 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = new IR::ListExpression(yystack_[2].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ()); }
#line 2981 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 11: // postfix_expression: primary_expression
#line 362 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 2987 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 12: // postfix_expression: postfix_expression "(" arg_list ")"
#line 363 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                              { yylhs.value.as < IR::Expression* > () = new IR::MethodCallExpression(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Vector<IR::Argument>* > ()); }
#line 2993 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 13: // unary_expression: postfix_expression
#line 367 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 2999 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 14: // unary_expression: "+" cast_expression
#line 368 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3005 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 15: // unary_expression: "-" cast_expression
#line 369 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = new IR::Neg(yystack_[1].location, yystack_[0].value.as < IR::Expression* > ()); }
#line 3011 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 16: // unary_expression: "!" cast_expression
#line 370 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = new IR::LNot(yystack_[1].location, yystack_[0].value.as < IR::Expression* > ()); }
#line 3017 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 17: // unary_expression: "~" cast_expression
#line 371 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = new IR::Cmpl(yystack_[1].location, yystack_[0].value.as < IR::Expression* > ()); }
#line 3023 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 18: // cast_expression: unary_expression
#line 375 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3029 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 19: // cast_expression: "(" type_ref ")" cast_expression
#line 376 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           { yylhs.value.as < IR::Expression* > () = new IR::Cast(yystack_[3].location, yystack_[2].value.as < const IR::Type* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3035 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 20: // multiplicative_expression: cast_expression
#line 380 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3041 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 21: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 381 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                        { yylhs.value.as < IR::Expression* > () = new IR::Mul(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3047 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 22: // multiplicative_expression: multiplicative_expression "/" cast_expression
#line 382 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                        { yylhs.value.as < IR::Expression* > () = new IR::Div(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3053 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 23: // multiplicative_expression: multiplicative_expression "%" cast_expression
#line 383 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                        { yylhs.value.as < IR::Expression* > () = new IR::Mod(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3059 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 24: // additive_expression: multiplicative_expression
#line 387 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3065 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 25: // additive_expression: multiplicative_expression "+" multiplicative_expression
#line 388 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                  { yylhs.value.as < IR::Expression* > () = new IR::Add(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3071 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 26: // additive_expression: multiplicative_expression "-" multiplicative_expression
#line 389 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                  { yylhs.value.as < IR::Expression* > () = new IR::Sub(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3077 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 27: // shift_expression: additive_expression
#line 393 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3083 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 28: // shift_expression: shift_expression "<<" additive_expression
#line 394 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                       { yylhs.value.as < IR::Expression* > () = new IR::Shl(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3089 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 29: // shift_expression: shift_expression ">>" additive_expression
#line 395 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                        { yylhs.value.as < IR::Expression* > () = new IR::Shr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3095 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 30: // relational_expression: shift_expression
#line 399 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                           { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3101 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 31: // relational_expression: relational_expression "<" shift_expression
#line 400 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                     { yylhs.value.as < IR::Expression* > () = new IR::Lss(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3107 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 32: // relational_expression: relational_expression ">" shift_expression
#line 401 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      { yylhs.value.as < IR::Expression* > () = new IR::Grt(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3113 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 33: // relational_expression: relational_expression "<=" shift_expression
#line 402 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      { yylhs.value.as < IR::Expression* > () = new IR::Leq(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3119 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 34: // relational_expression: relational_expression ">=" shift_expression
#line 403 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      { yylhs.value.as < IR::Expression* > () = new IR::Geq(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3125 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 35: // equality_expression: relational_expression
#line 407 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3131 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 36: // equality_expression: equality_expression "==" relational_expression
#line 408 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                           { yylhs.value.as < IR::Expression* > () = new IR::Equ(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3137 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 37: // equality_expression: equality_expression "!=" relational_expression
#line 409 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                           { yylhs.value.as < IR::Expression* > () = new IR::Neq(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3143 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 38: // and_expression: equality_expression
#line 413 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                              { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3149 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 39: // and_expression: and_expression "&" equality_expression
#line 414 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                 { yylhs.value.as < IR::Expression* > () = new IR::BAnd(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3155 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 40: // exclusive_or_expression: and_expression
#line 418 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3161 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 41: // exclusive_or_expression: exclusive_or_expression "^" and_expression
#line 419 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                     { yylhs.value.as < IR::Expression* > () = new IR::BXor(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3167 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 42: // inclusive_or_expression: exclusive_or_expression
#line 423 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3173 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 43: // inclusive_or_expression: inclusive_or_expression "|" exclusive_or_expression
#line 424 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                              { yylhs.value.as < IR::Expression* > () = new IR::BOr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3179 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 44: // logical_and_expression: inclusive_or_expression
#line 428 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3185 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 45: // logical_and_expression: logical_and_expression "&&" inclusive_or_expression
#line 429 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                { yylhs.value.as < IR::Expression* > () = new IR::LAnd(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3191 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 46: // logical_or_expression: logical_and_expression
#line 433 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3197 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 47: // logical_or_expression: logical_or_expression "||" logical_and_expression
#line 434 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                             { yylhs.value.as < IR::Expression* > () = new IR::LOr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3203 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 48: // conditional_expression: logical_or_expression
#line 438 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3209 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 49: // conditional_expression: logical_or_expression "?" expression ":" conditional_expression
#line 439 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                          { yylhs.value.as < IR::Expression* > () = new IR::Mux(yystack_[3].location, yystack_[4].value.as < IR::Expression* > (), yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3215 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 50: // expression: conditional_expression
#line 443 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3221 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 51: // expression: expression "++"
#line 445 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          {
                yylhs.value.as < IR::Expression* > () = new IR::P5PostIncrement(yystack_[1].location + yystack_[0].location, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3229 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 52: // expression: "." field_ref "=" expression
#line 450 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                yylhs.value.as < IR::Expression* > () = new IR::P5DesignatedInitializer(yystack_[3].location + yystack_[0].location, /*isMember=*/true, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
        }
#line 3237 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 53: // expression: "[" field_ref "]" "=" expression
#line 454 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                yylhs.value.as < IR::Expression* > () = new IR::P5DesignatedInitializer(yystack_[4].location + yystack_[0].location, /*isMember=*/false, yystack_[3].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
        }
#line 3245 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 54: // expression_list: expression
#line 460 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     { auto v = new IR::Vector<IR::Expression>();
                       v->push_back(yystack_[0].value.as < IR::Expression* > ());
                       yylhs.value.as < IR::Vector<IR::Expression>* > () = v; }
#line 3253 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 55: // expression_list: expression_list "," expression
#line 463 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yystack_[2].value.as < IR::Vector<IR::Expression>* > ()->push_back(yystack_[0].value.as < IR::Expression* > ());
                                           yylhs.value.as < IR::Vector<IR::Expression>* > () = yystack_[2].value.as < IR::Vector<IR::Expression>* > (); }
#line 3260 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 56: // annotation: "@" ID
#line 474 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   {
                // 无参数：生成一个空的、已结构化的表达式列表
                IR::Vector<IR::Expression> args;
                yylhs.value.as < IR::Annotation* > () = new IR::Annotation(yystack_[1].location + yystack_[0].location, *yystack_[0].value.as < IR::ID* > (), args, /*structured=*/true);
        }
#line 3270 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 57: // annotation: "@" ID "(" expression_list ")"
#line 480 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         {
                // expression_list: IR::Vector<IR::Expression>*
                yylhs.value.as < IR::Annotation* > () = new IR::Annotation(yystack_[4].location + yystack_[0].location, *yystack_[3].value.as < IR::ID* > (), *yystack_[1].value.as < IR::Vector<IR::Expression>* > (), /*structured=*/true);
        }
#line 3279 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 58: // annotations: %empty
#line 487 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::Vector<IR::Annotation>* > () = new IR::Vector<IR::Annotation>();
        }
#line 3287 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 59: // annotations: annotations annotation
#line 490 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 {
                yylhs.value.as < IR::Vector<IR::Annotation>* > () = yystack_[1].value.as < IR::Vector<IR::Annotation>* > ();
                if (yystack_[0].value.as < IR::Annotation* > () != nullptr) {
                        yylhs.value.as < IR::Vector<IR::Annotation>* > ()->push_back(yystack_[0].value.as < IR::Annotation* > ());
                        yylhs.value.as < IR::Vector<IR::Annotation>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
                }
        }
#line 3299 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 60: // type_ref: UINT "<" const_value ">"
#line 504 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   {
                auto width = yystack_[1].value.as < IR::Constant* > ()->asInt();
                yylhs.value.as < const IR::Type* > () = IR::Type_Bits::get(width, false); // false 表示无符号
        }
#line 3308 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 61: // type_ref: INT "<" const_value ">"
#line 508 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   {
                auto width = yystack_[1].value.as < IR::Constant* > ()->asInt();
                yylhs.value.as < const IR::Type* > () = IR::Type_Bits::get(width, true);  // true 表示有符号
        }
#line 3317 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 62: // type_ref: struct_union_type_declaration
#line 512 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                yylhs.value.as < const IR::Type* > () = yystack_[0].value.as < IR::Type_Struct* > ();
        }
#line 3325 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 63: // type_ref: ID
#line 515 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
             {
                auto path = new IR::Path(yystack_[0].location, *yystack_[0].value.as < IR::ID* > ());
                yylhs.value.as < const IR::Type* > () = new IR::Type_Name(yystack_[0].location, path);
        }
#line 3334 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 64: // type_ref: ID "::" ID
#line 519 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     {
                auto p = new IR::Path(yystack_[2].location, *yystack_[2].value.as < IR::ID* > () + "::" + *yystack_[0].value.as < IR::ID* > ());
                yylhs.value.as < const IR::Type* > () = new IR::Type_Name(yystack_[2].location, p);
        }
#line 3343 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 65: // type_ref: ID "<" ID ">"
#line 523 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                        {
                auto p = new IR::Path(yystack_[3].location, *yystack_[3].value.as < IR::ID* > () + "<" + *yystack_[1].value.as < IR::ID* > () + ">");
                yylhs.value.as < const IR::Type* > () = new IR::Type_Name(yystack_[3].location, p);
        }
#line 3352 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 66: // type_ref: ID "<" ID "::" ID ">"
#line 527 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                {
                auto p = new IR::Path(yystack_[5].location, *yystack_[5].value.as < IR::ID* > () + "<" + *yystack_[3].value.as < IR::ID* > () + "::" + *yystack_[1].value.as < IR::ID* > () + ">");
                yylhs.value.as < const IR::Type* > () = new IR::Type_Name(yystack_[5].location, p);
        }
#line 3361 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 67: // type_ref: VOID
#line 531 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
               {
                yylhs.value.as < const IR::Type* > () = IR::Type_Void::get();
        }
#line 3369 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 68: // field_ref_no_slice: ID
#line 536 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
             { auto path = new IR::Path(yystack_[0].location, *yystack_[0].value.as < IR::ID* > ());
               yylhs.value.as < IR::Expression* > () = new IR::PathExpression(yystack_[0].location, path); }
#line 3376 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 69: // field_ref_no_slice: field_ref "." ID
#line 538 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                           { yylhs.value.as < IR::Expression* > () = new IR::Member(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), *yystack_[0].value.as < IR::ID* > ()); }
#line 3382 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 70: // field_ref_no_slice: field_ref "[" expression "]"
#line 539 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       { yylhs.value.as < IR::Expression* > () = new IR::ArrayIndex(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3388 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 71: // field_ref_no_slice: ID "::" field_ref
#line 540 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            { auto path = new IR::Path(yystack_[2].location, *yystack_[2].value.as < IR::ID* > ());
                              auto base = new IR::PathExpression(yystack_[2].location, path);
                              yylhs.value.as < IR::Expression* > () = new IR::Member(yystack_[1].location, base, yystack_[0].value.as < IR::Expression* > ()->toString()); }
#line 3396 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 72: // field_ref: field_ref_no_slice
#line 545 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                             { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3402 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 73: // field_ref: field_ref "[" expression ":" expression "]"
#line 546 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      { yylhs.value.as < IR::Expression* > () = new IR::Slice(yystack_[4].location, yystack_[5].value.as < IR::Expression* > (), yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3408 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 74: // field_ref: "[" expression ":" expression "]"
#line 547 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            { yylhs.value.as < IR::Expression* > () = new IR::Slice(yystack_[4].location, nullptr, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3414 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 75: // field_dec: annotations type_ref ID ";"
#line 550 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                auto field = new IR::StructField(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), yystack_[2].value.as < const IR::Type* > ());
                if (yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3426 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 76: // field_dec: annotations type_ref ID "=" expression ";"
#line 557 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      {
                // 只能忽略初始化值，或者记录表达式用于后续处理
                auto field = new IR::StructField(yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), yystack_[4].value.as < const IR::Type* > ());
                if (yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3439 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 77: // field_dec: annotations type_ref ID "[" expression "]" ";"
#line 565 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                         {
                auto arrayType = new IR::Type_Stack(yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::Expression* > ());
                auto field = new IR::StructField(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), arrayType);
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3452 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 78: // field_dec: annotations type_ref ID "[" expression "]" "[" expression "]" ";"
#line 573 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                            {
                auto innerArray = new IR::Type_Stack(yystack_[8].value.as < const IR::Type* > (), yystack_[5].value.as < IR::Expression* > ());
                auto outerArray = new IR::Type_Stack(innerArray, yystack_[2].value.as < IR::Expression* > ());
                auto field = new IR::StructField(yystack_[7].location, *yystack_[7].value.as < IR::ID* > (), outerArray);
                if (yystack_[9].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[9].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3466 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 79: // anonymous_struct_union_dec: annotations STRUCT "{" struct_field_list "}" ";"
#line 585 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[4].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[2].value.as < IR::IndexedVector<IR::StructField>* > ());
                if (yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[4].location, anonName, type);
        }
#line 3479 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 80: // anonymous_struct_union_dec: annotations STRUCT "{" struct_field_list "}" ID ";"
#line 594 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[5].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[3].value.as < IR::IndexedVector<IR::StructField>* > ());
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), type);
        }
#line 3492 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 81: // anonymous_struct_union_dec: annotations UNION "{" struct_field_list "}" ";"
#line 603 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[4].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[2].value.as < IR::IndexedVector<IR::StructField>* > ());
                // 给它加个 @union 标记，保留语法信息
                type->annotations.push_back(new IR::Annotation("union", {}));
                if (yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[4].location, anonName, type);
        }
#line 3507 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 82: // anonymous_struct_union_dec: annotations UNION "{" struct_field_list "}" ID ";"
#line 614 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[5].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[3].value.as < IR::IndexedVector<IR::StructField>* > ());
                type->annotations.push_back(new IR::Annotation("union", {}));
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), type);
        }
#line 3521 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 83: // struct_field_dec: field_dec
#line 625 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                    { yylhs.value.as < IR::StructField* > () = yystack_[0].value.as < IR::StructField* > (); }
#line 3527 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 84: // struct_field_dec: anonymous_struct_union_dec
#line 626 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                     { yylhs.value.as < IR::StructField* > () = yystack_[0].value.as < IR::StructField* > (); }
#line 3533 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 85: // struct_field_list: struct_field_dec
#line 631 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto vec = new IR::IndexedVector<IR::StructField>();
                vec->push_back(yystack_[0].value.as < IR::StructField* > ());
                yylhs.value.as < IR::IndexedVector<IR::StructField>* > () = vec;
        }
#line 3543 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 86: // struct_field_list: struct_field_list struct_field_dec
#line 637 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ()->push_back(yystack_[0].value.as < IR::StructField* > ());
                yylhs.value.as < IR::IndexedVector<IR::StructField>* > () = yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ();
        }
#line 3552 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 87: // constant_declaration: CONST type_ref ID "=" expression ";"
#line 651 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Declaration_Constant* > () = new IR::Declaration_Constant(yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), yystack_[4].value.as < const IR::Type* > (), yystack_[1].value.as < IR::Expression* > ());
        }
#line 3560 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 88: // constant_declaration: CONST type_ref ID "[" expression "]" "=" expression ";"
#line 655 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto type = new IR::Type_Stack(yystack_[7].location, yystack_[7].value.as < const IR::Type* > (), yystack_[4].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Declaration_Constant* > () = new IR::Declaration_Constant(yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3569 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 89: // constant_declaration: CONST type_ref ID '[' expression ']' '[' expression ']' '=' expression ';'
#line 660 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto innerType = new IR::Type_Stack(yystack_[10].location, yystack_[10].value.as < const IR::Type* > (), yystack_[7].value.as < IR::Expression* > ());
                auto type = new IR::Type_Stack(yystack_[10].location, innerType, yystack_[4].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Declaration_Constant* > () = new IR::Declaration_Constant(yystack_[9].location, *yystack_[9].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3579 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 90: // header_declaration: HEADER type_ref ID ";"
#line 667 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 {
                auto args = new IR::Vector<IR::Argument>();
                yylhs.value.as < IR::Declaration* > () = new IR::Declaration_Instance(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), yystack_[2].value.as < const IR::Type* > (), args);
        }
#line 3588 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 91: // header_declaration: HEADER type_ref ID "[" expression "]" ";"
#line 671 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   {
                auto type = new IR::Type_Stack(yystack_[5].location, yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Declaration* > () = new IR::Declaration_Instance(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), type, {});
        }
#line 3597 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 92: // variable_declaration: type_ref ID ";"
#line 677 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          { yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), yystack_[2].value.as < const IR::Type* > (), nullptr); }
#line 3603 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 93: // variable_declaration: type_ref ID "=" expression ";"
#line 678 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), yystack_[4].value.as < const IR::Type* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3609 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 94: // variable_declaration: type_ref ID "[" expression "]" ";"
#line 679 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                             {
            auto type = new IR::Type_Stack(yystack_[5].location, yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), type, nullptr);
        }
#line 3618 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 95: // variable_declaration: type_ref ID "[" expression "]" "=" expression ";"
#line 683 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                            {
            auto type = new IR::Type_Stack(yystack_[7].location, yystack_[7].value.as < const IR::Type* > (), yystack_[4].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3627 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 96: // variable_declaration: type_ref ID "[" expression "]" "[" expression "]" ";"
#line 687 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                {
            auto innerType = new IR::Type_Stack(yystack_[8].location, yystack_[8].value.as < const IR::Type* > (), yystack_[5].value.as < IR::Expression* > ());
            auto type = new IR::Type_Stack(yystack_[8].location, innerType, yystack_[2].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[7].location, *yystack_[7].value.as < IR::ID* > (), type, nullptr);
        }
#line 3637 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 97: // variable_declaration: type_ref ID "[" expression "]" "[" expression "]" "=" expression ";"
#line 692 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                               {
            auto innerType = new IR::Type_Stack(yystack_[10].location, yystack_[10].value.as < const IR::Type* > (), yystack_[7].value.as < IR::Expression* > ());
            auto type = new IR::Type_Stack(yystack_[10].location, innerType, yystack_[4].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[9].location, *yystack_[9].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3647 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 98: // variable_declaration: USING NAMESPACE ID ";"
#line 697 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::Declaration_Variable* > () = nullptr; /* TODO: maybe handle 'using namespace' */ }
#line 3653 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 99: // return_value_type: ID "(" arg_list ")" ";"
#line 706 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  {
                auto pe = new IR::PathExpression(*yystack_[4].value.as < IR::ID* > ());
                auto mc = new IR::MethodCallExpression(yystack_[4].location, pe,
                                                 new IR::Vector<IR::Type>(), yystack_[2].value.as < IR::Vector<IR::Argument>* > ());
                yylhs.value.as < IR::Statement* > () = new IR::ReturnStatement(yystack_[4].location + yystack_[1].location, mc);
        }
#line 3664 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 100: // return_value_type: "{" return_value_type_list "}"
#line 712 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Statement* > () = yystack_[1].value.as < IR::BlockStatement* > (); }
#line 3670 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 101: // return_value_type: ID ";"
#line 713 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                auto pe = new IR::PathExpression(*yystack_[1].value.as < IR::ID* > ());
                yylhs.value.as < IR::Statement* > () = new IR::ReturnStatement(yystack_[1].location + yystack_[0].location, pe);
        }
#line 3679 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 102: // return_value_type_list: %empty
#line 719 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yylhs.location);
        }
#line 3687 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 103: // return_value_type_list: return_value_type_list return_value_type
#line 722 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   {
                yystack_[1].value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::Statement* > ());
                yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 3696 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 104: // value_masked_or_set: expression
#line 728 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3702 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 105: // value_masked_or_set: expression "&&&" expression
#line 729 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      { yylhs.value.as < IR::Expression* > () = new IR::Mask(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3708 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 106: // value_list: value_masked_or_set
#line 733 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto vec = new IR::Vector<IR::Expression>();
                vec->push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Vector<IR::Expression>* > () = vec;
        }
#line 3718 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 107: // value_list: value_list "," value_masked_or_set
#line 739 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[2].value.as < IR::Vector<IR::Expression>* > ()->push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Vector<IR::Expression>* > () = yystack_[2].value.as < IR::Vector<IR::Expression>* > ();
        }
#line 3727 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 108: // case_entry: CASE value_list ":" return_value_type
#line 746 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                IR::Expression* le =  new IR::ListExpression(yystack_[3].location, *yystack_[2].value.as < IR::Vector<IR::Expression>* > ());
                const IR::Statement* stmt = yystack_[0].value.as < IR::Statement* > ();
                if (stmt && !stmt->is<IR::BlockStatement>()) {
                        auto block = new IR::BlockStatement(yystack_[0].location);
                        block->components.push_back(stmt);
                        stmt = block;
                }
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[3].location, le, stmt);
        }
#line 3742 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 109: // case_entry: CASE value_list ":"
#line 757 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                // Empty case body (fallthrough): "case ...:" with nothing after ':'
                IR::Expression* le =  new IR::ListExpression(yystack_[2].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ());
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, le, nullptr);
        }
#line 3752 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 110: // case_entry: DEFAULT ":" return_value_type
#line 763 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto label = new IR::DefaultExpression(yystack_[2].location);
                const IR::Statement* stmt = yystack_[0].value.as < IR::Statement* > ();
                if (stmt && !stmt->is<IR::BlockStatement>()) {
                        auto block = new IR::BlockStatement(yystack_[0].location);
                        block->components.push_back(stmt);
                        stmt = block;
                }
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, label, stmt);
        }
#line 3767 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 111: // case_entry: DEFAULT ":"
#line 774 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                // Empty default body (fallthrough).
                auto label = new IR::DefaultExpression(yystack_[1].location);
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[1].location, label, nullptr);
        }
#line 3777 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 112: // case_list: case_entry
#line 781 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = new IR::Vector<IR::SwitchCase>();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[0].location;
        }
#line 3787 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 113: // case_list: case_list case_entry
#line 786 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                               {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
        }
#line 3797 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 114: // field_ref_or_func: field_ref
#line 793 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                    {
                yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > ();
        }
#line 3805 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 115: // field_ref_or_func: ID "(" arg_list ")"
#line 796 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                              {
                auto path   = new IR::Path(yystack_[3].location, *yystack_[3].value.as < IR::ID* > ());
                auto callee = new IR::PathExpression(yystack_[3].location, path);
                yylhs.value.as < IR::Expression* > () = new IR::MethodCallExpression(yystack_[2].location, callee, yystack_[1].value.as < IR::Vector<IR::Argument>* > ());
        }
#line 3815 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 116: // select_exp: field_ref_or_func
#line 803 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            {
                auto vec = new IR::Vector<IR::Expression>();
                vec->push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::ListExpression* > () = new IR::ListExpression(yystack_[0].location, *vec);
        }
#line 3825 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 117: // select_exp: select_exp "," field_ref_or_func
#line 808 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            {
                yystack_[2].value.as < IR::ListExpression* > ()->components.push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::ListExpression* > () = yystack_[2].value.as < IR::ListExpression* > ();
        }
#line 3834 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 118: // return_select_statement: SWITCH "(" select_exp ")" "{" case_list "}"
#line 814 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      {
                yylhs.value.as < IR::Statement* > () = new IR::SwitchStatement(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 3842 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 119: // return_statement: RETURN return_select_statement
#line 819 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Statement* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 3848 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 120: // return_statement: RETURN return_value_type
#line 820 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   { yylhs.value.as < IR::Statement* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 3854 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 121: // break_statement: BREAK ";"
#line 823 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                    { yylhs.value.as < IR::Statement* > () = new IR::BreakStatement(yystack_[1].location); }
#line 3860 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 122: // parameter: annotations type_ref ID
#line 831 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  {
                auto param = new IR::Parameter(yystack_[0].location, *yystack_[0].value.as < IR::ID* > (), IR::Direction::In, yystack_[1].value.as < const IR::Type* > ());
                if (yystack_[2].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[2].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 3872 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 123: // parameter: annotations type_ref ID "=" expression
#line 838 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                 {
                auto param = new IR::Parameter(yystack_[2].location, *yystack_[2].value.as < IR::ID* > (), IR::Direction::In, yystack_[3].value.as < const IR::Type* > (), yystack_[0].value.as < IR::Expression* > ());
                if (yystack_[4].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[4].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 3884 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 124: // parameter: annotations type_ref "&" ID
#line 845 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      {
                auto param = new IR::Parameter(yystack_[0].location, *yystack_[0].value.as < IR::ID* > (), IR::Direction::InOut, yystack_[2].value.as < const IR::Type* > ());
                if (yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 3896 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 125: // parameter: annotations type_ref "&" ID "=" expression
#line 852 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                     {
                auto param = new IR::Parameter(yystack_[2].location, *yystack_[2].value.as < IR::ID* > (), IR::Direction::InOut, yystack_[4].value.as < const IR::Type* > (), yystack_[0].value.as < IR::Expression* > ());
                if (yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 3908 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 126: // parameter: annotations type_ref "&" ID "[" "]"
#line 859 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                              {
                // Unsized array parameter passed by reference (inout).
                // IR::Type_Stack does not accept a nullptr size, so we preserve "[]" using an annotation.
                auto param = new IR::Parameter(yystack_[2].location, *yystack_[2].value.as < IR::ID* > (), IR::Direction::InOut, yystack_[4].value.as < const IR::Type* > ());
                param->addAnnotation(new IR::Annotation("p5_unsized_array", {}));
                if (yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 3923 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 127: // parameter: annotations type_ref ID "[" "]"
#line 869 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                          {
                // Unsized array parameter.
                // IR::Type_Stack does not accept a nullptr size, so we preserve "[]" using an annotation.
                auto param = new IR::Parameter(yystack_[2].location, *yystack_[2].value.as < IR::ID* > (), IR::Direction::In, yystack_[3].value.as < const IR::Type* > ());
                param->addAnnotation(new IR::Annotation("p5_unsized_array", {}));
                if (yystack_[4].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[4].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 3938 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 128: // param_list: %empty
#line 881 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::ParameterList* > () = new IR::ParameterList(); }
#line 3944 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 129: // param_list: parameter
#line 883 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto pl = new IR::ParameterList(); pl->push_back(yystack_[0].value.as < IR::Parameter* > ());
                yylhs.value.as < IR::ParameterList* > () = pl;
        }
#line 3953 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 130: // param_list: param_list "," parameter
#line 888 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[2].value.as < IR::ParameterList* > ()->push_back(yystack_[0].value.as < IR::Parameter* > ());
                yylhs.value.as < IR::ParameterList* > () = yystack_[2].value.as < IR::ParameterList* > ();
        }
#line 3962 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 131: // arg: expression
#line 895 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     { yylhs.value.as < IR::Argument* > () = new IR::Argument(yystack_[0].location, yystack_[0].value.as < IR::Expression* > ()); }
#line 3968 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 132: // arg_list: %empty
#line 898 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::Vector<IR::Argument>* > () = new IR::Vector<IR::Argument>(); }
#line 3974 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 133: // arg_list: arg
#line 900 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto v = new IR::Vector<IR::Argument>();
                v->push_back(yystack_[0].value.as < IR::Argument* > ());
                yylhs.value.as < IR::Vector<IR::Argument>* > () = v;
        }
#line 3984 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 134: // arg_list: arg_list "," arg
#line 906 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[2].value.as < IR::Vector<IR::Argument>* > ()->push_back(yystack_[0].value.as < IR::Argument* > ());
                yylhs.value.as < IR::Vector<IR::Argument>* > () = yystack_[2].value.as < IR::Vector<IR::Argument>* > ();
        }
#line 3993 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 135: // do_while_statement: DO action_statement WHILE "(" expression ")"
#line 914 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                IR::IndexedVector<IR::StatOrDecl> as;
                as.push_back(yystack_[4].value.as < IR::StatOrDecl* > ());
                auto bs = new IR::BlockStatement(yystack_[4].location, as);
                yylhs.value.as < IR::Statement* > () = new IR::ForStatement(
                        yystack_[5].location,
                        IR::IndexedVector<IR::StatOrDecl>(),
                        yystack_[1].value.as < IR::Expression* > (),
                        IR::IndexedVector<IR::StatOrDecl>(),
                        bs
                );
        }
#line 4010 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 136: // conditional_statement: IF "(" expression ")" action_statement
#line 929 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                   {
                IR::IndexedVector<IR::StatOrDecl> as;
                as.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto bs = new IR::BlockStatement(yystack_[0].location, as);
                yylhs.value.as < IR::Statement* > () = new IR::IfStatement(yystack_[4].location, yystack_[2].value.as < IR::Expression* > (), bs, nullptr);
        }
#line 4021 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 137: // conditional_statement: IF "(" expression ")" action_statement ELSE action_statement
#line 935 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                                   {
                IR::IndexedVector<IR::StatOrDecl> as0;
                as0.push_back(yystack_[2].value.as < IR::StatOrDecl* > ());
                auto bs0 = new IR::BlockStatement(yystack_[2].location, as0);
                IR::IndexedVector<IR::StatOrDecl> as1;
                as1.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto bs1 = new IR::BlockStatement(yystack_[0].location, as1);
                yylhs.value.as < IR::Statement* > () = new IR::IfStatement(yystack_[6].location, yystack_[4].value.as < IR::Expression* > (), bs0, bs1);
        }
#line 4035 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 138: // for_loop_statement: FOR "(" parameter ";" expression ";" assignment_or_call_statement ")" action_statement
#line 947 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                IR::IndexedVector<IR::StatOrDecl> init;
                init.push_back(yystack_[6].value.as < IR::Parameter* > ());   // parameter 本身就是 IR::Parameter/Declaration

                IR::IndexedVector<IR::StatOrDecl> iter;
                iter.push_back(yystack_[2].value.as < IR::Statement* > ());   // assignment_or_call_statement -> IR::Statement

                IR::IndexedVector<IR::StatOrDecl> as_vec;
                as_vec.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto as = new IR::BlockStatement(yystack_[0].location, as_vec);

                yylhs.value.as < IR::Statement* > () = new IR::ForStatement(
                        yystack_[8].location,
                        init,
                        yystack_[4].value.as < IR::Expression* > (),
                        iter,
                        as
                );
        }
#line 4059 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 139: // case: CASE value_list ":" action_statement
#line 968 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                IR::Expression* vl = new IR::ListExpression(yystack_[3].location, *yystack_[2].value.as < IR::Vector<IR::Expression>* > ());

                IR::IndexedVector<IR::StatOrDecl> as_vec;
                as_vec.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto as = new IR::BlockStatement(yystack_[0].location, as_vec);

                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[3].location, vl, as);
        }
#line 4073 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 140: // case: CASE value_list ":"
#line 978 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                // Empty case body (fallthrough).
                IR::Expression* vl = new IR::ListExpression(yystack_[2].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ());
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, vl, nullptr);
        }
#line 4083 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 141: // case: DEFAULT ":" action_statement
#line 983 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                IR::IndexedVector<IR::StatOrDecl> as_vec;
                as_vec.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto as = new IR::BlockStatement(yystack_[0].location, as_vec);

                auto label = new IR::DefaultExpression(yystack_[2].location);

                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, label, as);
        }
#line 4097 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 142: // case: DEFAULT ":"
#line 992 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                      {
                // Empty default body (fallthrough).
                auto label = new IR::DefaultExpression(yystack_[1].location);
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[1].location, label, nullptr);
        }
#line 4107 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 143: // switch_cases: %empty
#line 999 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = new IR::Vector<IR::SwitchCase>; }
#line 4113 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 144: // switch_cases: switch_cases case
#line 1000 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            {
                yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ();
        }
#line 4122 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 145: // switch_statement: SWITCH "(" select_exp ")" "{" switch_cases "}"
#line 1006 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                         {
                yylhs.value.as < IR::Statement* > () = new IR::SwitchStatement(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 4130 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 146: // assignment_or_call_statement: field_ref_or_func ";"
#line 1011 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                {
                if (auto mc = yystack_[1].value.as < IR::Expression* > ()->to<IR::MethodCallExpression>()) {
                        yylhs.value.as < IR::Statement* > () = new IR::MethodCallStatement(yystack_[1].location, mc);
                } else {
                        yylhs.value.as < IR::Statement* > () = new IR::EmptyStatement(yystack_[1].location);
                }
        }
#line 4142 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 147: // assignment_or_call_statement: field_ref "=" expression ";"
#line 1018 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ());
        }
#line 4150 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 148: // assignment_or_call_statement: field_ref "-=" expression ";"
#line 1021 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                auto sub = new IR::Sub(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), sub);
        }
#line 4159 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 149: // assignment_or_call_statement: field_ref "+=" expression ";"
#line 1025 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                auto sub = new IR::Sub(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), sub);
        }
#line 4168 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 150: // assignment_or_call_statement: field_ref "*=" expression ";"
#line 1029 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                auto mul = new IR::Mul(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), mul);
        }
#line 4177 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 151: // assignment_or_call_statement: field_ref "/=" expression ";"
#line 1033 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                auto div = new IR::Div(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), div);
        }
#line 4186 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 152: // assignment_or_call_statement: field_ref "%=" expression ";"
#line 1037 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                auto mod = new IR::Mod(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), mod);
        }
#line 4195 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 153: // assignment_or_call_statement: field_ref "|=" expression ";"
#line 1041 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                auto bor = new IR::BOr(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), bor);
        }
#line 4204 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 154: // assignment_or_call_statement: field_ref "^=" expression ";"
#line 1045 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                auto bxor = new IR::BXor(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), bxor);
        }
#line 4213 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 155: // assignment_or_call_statement: field_ref "<<=" expression ";"
#line 1049 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         {
                auto shl = new IR::Shl(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), shl);
        }
#line 4222 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 156: // assignment_or_call_statement: field_ref ">>=" expression ";"
#line 1053 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         {
                auto shr = new IR::Shr(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), shr);
        }
#line 4231 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 157: // assignment_or_call_statement: field_ref "++" ";"
#line 1057 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                             {
                auto one = new IR::Constant(IR::Type_Bits::get(32), 1);
                auto add = new IR::Add(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), one);
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), add);
        }
#line 4241 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 158: // assignment_or_call_statement: field_ref "--" ";"
#line 1062 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                             {
                auto one = new IR::Constant(IR::Type_Bits::get(32), 1);
                auto sub = new IR::Sub(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), one);
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), sub);
        }
#line 4251 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 159: // action_statement: annotations variable_declaration
#line 1069 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Variable* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Variable* > ();
        }
#line 4260 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 160: // action_statement: annotations constant_declaration
#line 1073 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Constant* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Constant* > ();
        }
#line 4269 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 161: // action_statement: annotations action_compound_statement
#line 1077 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                {
                attachAnnotations(yystack_[0].value.as < IR::BlockStatement* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::BlockStatement* > ();
        }
#line 4278 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 162: // action_statement: annotations conditional_statement
#line 1081 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4284 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 163: // action_statement: annotations switch_statement
#line 1082 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4290 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 164: // action_statement: annotations do_while_statement
#line 1083 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4296 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 165: // action_statement: annotations for_loop_statement
#line 1084 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4302 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 166: // action_statement: annotations return_statement
#line 1085 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4308 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 167: // action_statement: annotations break_statement
#line 1086 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4314 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 168: // action_statement: annotations assignment_or_call_statement
#line 1087 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4320 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 169: // action_statement_list: %empty
#line 1091 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yylhs.location); }
#line 4326 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 170: // action_statement_list: action_statement_list action_statement
#line 1092 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                 {
              yystack_[1].value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
              yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 4335 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 171: // action_compound_statement: "{" action_statement_list "}"
#line 1098 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > (); }
#line 4341 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 172: // key_element: CONTROL_PARAMETERS "=" "{" action_statement_list "}"
#line 1107 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                               {
                auto ke = new IR::P5KeyElement(yystack_[4].location);
                ke->control = *yystack_[1].value.as < IR::BlockStatement* > ();
                yylhs.value.as < IR::P5KeyElement* > () = ke;
        }
#line 4351 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 173: // key_element: annotations expression ":" ID ";"
#line 1112 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            {
                auto ke = new IR::P5KeyElement(yystack_[4].location);
                ke->annotations = *yystack_[4].value.as < IR::Vector<IR::Annotation>* > ();
                ke->expr = yystack_[3].value.as < IR::Expression* > ();
                ke->matchType = *yystack_[1].value.as < IR::ID* > ();
                yylhs.value.as < IR::P5KeyElement* > () = ke;
        }
#line 4363 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 174: // key_element: annotations expression ";"
#line 1119 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                     {
                auto ke = new IR::P5KeyElement(yystack_[2].location);
                ke->annotations = *yystack_[2].value.as < IR::Vector<IR::Annotation>* > ();
                ke->expr = yystack_[1].value.as < IR::Expression* > ();
                yylhs.value.as < IR::P5KeyElement* > () = ke;
        }
#line 4374 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 175: // key_element_list: %empty
#line 1127 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::Vector<IR::P5KeyElement>* > () = new IR::Vector<IR::P5KeyElement>();
        }
#line 4382 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 176: // key_element_list: key_element_list key_element
#line 1130 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ()->push_back(yystack_[0].value.as < IR::P5KeyElement* > ());
                yylhs.value.as < IR::Vector<IR::P5KeyElement>* > () = yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
        }
#line 4391 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 177: // key_case_entry: annotations CASE value_list ":" "{" key_element_list "}"
#line 1136 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                   {
                auto label = new IR::ListExpression(yystack_[4].location, *yystack_[4].value.as < IR::Vector<IR::Expression>* > ());
                auto kce = new IR::P5KeyCase(yystack_[6].location, false);
                kce->annotations = *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ();
                kce->label = label;
                kce->elements = *yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
                kce->fallthrough = false;
                yylhs.value.as < IR::P5KeyCase* > () = kce;
        }
#line 4405 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 178: // key_case_entry: annotations CASE value_list ":"
#line 1145 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                          {
                // Empty case body (fallthrough): "case ...:" with nothing after ':'
                auto label = new IR::ListExpression(yystack_[1].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ());
                auto kce = new IR::P5KeyCase(yystack_[3].location, true);
                kce->annotations = *yystack_[3].value.as < IR::Vector<IR::Annotation>* > ();
                kce->label = label;
                // Keep elements as an empty vector to avoid relying on nullptr checks.
                kce->elements = IR::Vector<IR::P5KeyElement>();
                kce->fallthrough = true;
                yylhs.value.as < IR::P5KeyCase* > () = kce;
        }
#line 4421 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 179: // key_case_entry: annotations DEFAULT ":" "{" key_element_list "}"
#line 1156 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                           {
                auto label = new IR::DefaultExpression(yystack_[4].location);
                auto kce = new IR::P5KeyCase(yystack_[5].location, false);
                kce->annotations = *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ();
                kce->label = label;
                kce->elements = *yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
                kce->fallthrough = false;
                yylhs.value.as < IR::P5KeyCase* > () = kce;
        }
#line 4435 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 180: // key_case_entry: annotations DEFAULT ":"
#line 1165 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  {
                // Empty default body (fallthrough).
                auto label = new IR::DefaultExpression(yystack_[1].location);
                auto kce = new IR::P5KeyCase(yystack_[2].location, true);
                kce->annotations = *yystack_[2].value.as < IR::Vector<IR::Annotation>* > ();
                kce->label = label;
                kce->elements = IR::Vector<IR::P5KeyElement>();
                kce->fallthrough = true;
                yylhs.value.as < IR::P5KeyCase* > () = kce;
        }
#line 4450 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 181: // key_case_list: key_case_entry
#line 1177 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         {
                auto v = new IR::Vector<IR::P5KeyCase>();
                v->push_back(yystack_[0].value.as < IR::P5KeyCase* > ());
                yylhs.value.as < IR::Vector<IR::P5KeyCase>* > () = v;
        }
#line 4460 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 182: // key_case_list: key_case_list key_case_entry
#line 1182 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                yystack_[1].value.as < IR::Vector<IR::P5KeyCase>* > ()->push_back(yystack_[0].value.as < IR::P5KeyCase* > ());
                yylhs.value.as < IR::Vector<IR::P5KeyCase>* > () = yystack_[1].value.as < IR::Vector<IR::P5KeyCase>* > ();
        }
#line 4469 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 183: // key_switch_entry: SWITCH "(" select_exp ")" "{" key_case_list "}"
#line 1188 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                          {
                // P5KeySwitch is a dedicated IR node so a single key={...} can contain
                // multiple switch blocks in source order.
                yylhs.value.as < IR::P5KeySwitch* > () = new IR::P5KeySwitch(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::P5KeyCase>* > ());
        }
#line 4479 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 184: // key_switch_list: key_switch_entry
#line 1195 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                           {
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > () = new IR::Vector<IR::P5KeySwitch>();
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->push_back(yystack_[0].value.as < IR::P5KeySwitch* > ());
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->srcInfo = yystack_[0].location;
        }
#line 4489 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 185: // key_switch_list: key_switch_entry key_switch_list
#line 1200 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > () = yystack_[0].value.as < IR::Vector<IR::P5KeySwitch>* > ();
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->insert(yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->begin(), yystack_[1].value.as < IR::P5KeySwitch* > ());
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
        }
#line 4499 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 186: // program_selection_statement: constant_declaration
#line 1207 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Constant* > (); }
#line 4505 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 187: // program_selection_statement: variable_declaration
#line 1208 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Variable* > (); }
#line 4511 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 188: // program_selection_statement: assignment_or_call_statement
#line 1209 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4517 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 189: // program_selection_statement_list: %empty
#line 1212 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yylhs.location);
        }
#line 4525 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 190: // program_selection_statement_list: program_selection_statement
#line 1215 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      {
                auto blk = new IR::BlockStatement(yystack_[0].location);
                blk->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                yylhs.value.as < IR::BlockStatement* > () = blk;
        }
#line 4535 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 191: // program_selection_statement_list: program_selection_statement_list program_selection_statement
#line 1220 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                       {
                yystack_[1].value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 4544 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 192: // table_case_entry: annotations CASE value_list ":" "{" program_selection_statement_list "}"
#line 1226 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                                   {
                IR::Expression* label = new IR::ListExpression(yystack_[4].location, *yystack_[4].value.as < IR::Vector<IR::Expression>* > ());
                const IR::Statement* stmt = yystack_[1].value.as < IR::BlockStatement* > ();
                if (stmt && !stmt->is<IR::BlockStatement>()) {
                        auto blk = new IR::BlockStatement(yystack_[1].location);
                        blk->components.push_back(stmt);
                        stmt = blk;
                }
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[5].location, label, stmt);
        }
#line 4559 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 193: // table_case_entry: annotations CASE value_list ":"
#line 1236 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                          {
                // Empty case body (fallthrough).
                IR::Expression* label = new IR::ListExpression(yystack_[1].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ());
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, label, nullptr);
        }
#line 4569 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 194: // table_case_entry: annotations DEFAULT ":" "{" program_selection_statement_list "}"
#line 1241 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                           {
                IR::Expression* label = new IR::DefaultExpression(yystack_[4].location);
                const IR::Statement* stmt = yystack_[1].value.as < IR::BlockStatement* > ();
                if (stmt && !stmt->is<IR::BlockStatement>()) {
                        auto blk = new IR::BlockStatement(yystack_[1].location);
                        blk->components.push_back(stmt);
                        stmt = blk;
                }
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[4].location, label, stmt);
        }
#line 4584 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 195: // table_case_entry: annotations DEFAULT ":"
#line 1251 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  {
                // Empty default body (fallthrough).
                IR::Expression* label = new IR::DefaultExpression(yystack_[1].location);
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[1].location, label, nullptr);
        }
#line 4594 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 196: // table_case_list: table_case_entry
#line 1259 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = new IR::Vector<IR::SwitchCase>();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[0].location;
        }
#line 4604 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 197: // table_case_list: table_case_list table_case_entry
#line 1265 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
        }
#line 4614 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 198: // table_property: KEY "=" "{" key_element_list "}"
#line 1272 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                auto key = new IR::P5Key(yystack_[4].location);
                key->elements = *yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
                yylhs.value.as < IR::StatOrDecl* > () = key;
        }
#line 4624 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 199: // table_property: KEY "=" "{" key_switch_list "}"
#line 1277 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                          {
                auto key = new IR::P5Key(yystack_[4].location);
                key->switches = *yystack_[1].value.as < IR::Vector<IR::P5KeySwitch>* > ();
                yylhs.value.as < IR::StatOrDecl* > () = key;
        }
#line 4634 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 200: // table_property: SWITCH "(" select_exp ")" "{" table_case_list "}"
#line 1282 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                            {
                yylhs.value.as < IR::StatOrDecl* > () = new IR::SwitchStatement(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 4642 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 201: // table_property: assignment_or_call_statement
#line 1285 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > ();
        }
#line 4650 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 202: // table_property: constant_declaration
#line 1288 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                               {
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Constant* > ();
        }
#line 4658 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 203: // table_property: variable_declaration
#line 1291 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                               {
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Variable* > ();
        }
#line 4666 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 204: // table_property_list: table_property
#line 1297 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         {
                yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yystack_[0].location);
                if (yystack_[0].value.as < IR::StatOrDecl* > ()) yylhs.value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
        }
#line 4675 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 205: // table_property_list: table_property_list table_property
#line 1301 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                             {
                yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
                if (yystack_[0].value.as < IR::StatOrDecl* > ()) yylhs.value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
        }
#line 4684 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 206: // table_declaration: TABLE ID "(" param_list ")" "{" table_property_list "}"
#line 1309 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                  {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[7].location+yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), yystack_[4].value.as < IR::ParameterList* > (), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4692 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 207: // table_declaration: TABLE ID "{" table_property_list "}"
#line 1312 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                               {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[4].location+yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), new IR::ParameterList(), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4700 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 208: // table_declaration: CLASS ID "(" param_list ")" "{" table_property_list "}"
#line 1315 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                  {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[7].location+yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), yystack_[4].value.as < IR::ParameterList* > (), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4708 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 209: // table_declaration: CLASS ID "{" table_property_list "}"
#line 1318 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                               {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[4].location+yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), new IR::ParameterList(), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4716 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 210: // typedef_declaration: TYPEDEF type_ref ID
#line 1331 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto id = IR::ID(yystack_[0].location, *yystack_[0].value.as < IR::ID* > ());
                yylhs.value.as < IR::Type_Typedef* > () = new IR::Type_Typedef(yystack_[2].location, id, yystack_[1].value.as < const IR::Type* > ());
        }
#line 4725 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 211: // enumerator: ID
#line 1338 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < P4::P5::EnumItem* > () = new P4::P5::EnumItem(yystack_[0].location, yystack_[0].value.as < IR::ID* > (), nullptr);
        }
#line 4733 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 212: // enumerator: ID "=" expression
#line 1342 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < P4::P5::EnumItem* > () = new P4::P5::EnumItem(yystack_[2].location + yystack_[0].location, yystack_[2].value.as < IR::ID* > (), yystack_[0].value.as < IR::Expression* > ());
        }
#line 4741 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 213: // enumerator_list: enumerator
#line 1347 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     {
                yylhs.value.as < IR::IndexedVector<IR::SerEnumMember>* > () = new IR::IndexedVector<IR::SerEnumMember>();
                IR::Expression* v = nullptr;
                if (yystack_[0].value.as < P4::P5::EnumItem* > ()->value) {
                    v = yystack_[0].value.as < P4::P5::EnumItem* > ()->value;
                } else {
                    v = new IR::Constant(IR::Type_Bits::get(32), 0);
                }
                yylhs.value.as < IR::IndexedVector<IR::SerEnumMember>* > ()->push_back(new IR::SerEnumMember(yystack_[0].location, *yystack_[0].value.as < P4::P5::EnumItem* > ()->name, v));
        }
#line 4756 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 214: // enumerator_list: enumerator_list "," enumerator
#line 1357 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         {
                IR::Expression* v = nullptr;
                if (yystack_[0].value.as < P4::P5::EnumItem* > ()->value) {
                    v = yystack_[0].value.as < P4::P5::EnumItem* > ()->value;
                } else {
                    const IR::SerEnumMember* prev = (*yystack_[2].value.as < IR::IndexedVector<IR::SerEnumMember>* > ())[yystack_[2].value.as < IR::IndexedVector<IR::SerEnumMember>* > ()->size() - 1];
                    auto one = new IR::Constant(IR::Type_Bits::get(32), 1);
                    v = new IR::Add(yystack_[1].location, prev->value, one);
                }
                yystack_[2].value.as < IR::IndexedVector<IR::SerEnumMember>* > ()->push_back(new IR::SerEnumMember(yystack_[0].location, *yystack_[0].value.as < P4::P5::EnumItem* > ()->name, v));
                yylhs.value.as < IR::IndexedVector<IR::SerEnumMember>* > () = yystack_[2].value.as < IR::IndexedVector<IR::SerEnumMember>* > ();
        }
#line 4773 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 215: // enum_declaration: ENUM ID "{" enumerator_list "}"
#line 1372 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                const IR::Type* underlying = IR::Type_Bits::get(32, false);
                yylhs.value.as < IR::Type_Declaration* > () = new IR::Type_SerEnum(*yystack_[3].value.as < IR::ID* > (), underlying, *yystack_[1].value.as < IR::IndexedVector<IR::SerEnumMember>* > ());
        }
#line 4782 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 216: // struct_union_type_declaration: STRUCT ID "{" struct_field_list "}"
#line 1379 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Type_Struct* > () = new IR::Type_Struct(yystack_[3].location + yystack_[0].location, *yystack_[3].value.as < IR::ID* > (), *yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ());
        }
#line 4790 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 217: // struct_union_type_declaration: UNION ID "{" struct_field_list "}"
#line 1383 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto st = new IR::Type_Struct(yystack_[3].location + yystack_[0].location, *yystack_[3].value.as < IR::ID* > (), *yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ());
                st->annotations.push_back(new IR::Annotation("union", {}));
                yylhs.value.as < IR::Type_Struct* > () = st;
        }
#line 4800 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 218: // type_declaration: struct_union_type_declaration ";"
#line 1391 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            { yylhs.value.as < IR::Type_Declaration* > () = yystack_[1].value.as < IR::Type_Struct* > (); }
#line 4806 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 219: // type_declaration: enum_declaration ";"
#line 1392 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                               { yylhs.value.as < IR::Type_Declaration* > () = yystack_[1].value.as < IR::Type_Declaration* > (); }
#line 4812 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 220: // type_declaration: typedef_declaration ";"
#line 1393 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   { yylhs.value.as < IR::Type_Declaration* > () = yystack_[1].value.as < IR::Type_Typedef* > (); }
#line 4818 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 221: // function_declaration: type_ref ID "(" param_list ")" action_compound_statement
#line 1397 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring funcName = yystack_[4].value.as < IR::ID* > ()->name;  // ID* -> cstring
                auto funcType = new IR::Type_Method(yystack_[5].location + yystack_[1].location, yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::ParameterList* > (), funcName);
                yylhs.value.as < IR::Function* > () = new IR::Function(yystack_[4].location + yystack_[0].location, funcName, funcType, yystack_[0].value.as < IR::BlockStatement* > ());
        }
#line 4828 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 223: // declaration: annotations constant_declaration
#line 1415 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Constant* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Declaration_Constant* > ();
        }
#line 4837 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 224: // declaration: annotations type_declaration
#line 1420 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Type_Declaration* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Type_Declaration* > ();
        }
#line 4846 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 225: // declaration: annotations header_declaration
#line 1425 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Declaration* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Declaration* > ();
        }
#line 4855 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 226: // declaration: annotations table_declaration
#line 1430 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::P5Table* > ();
        }
#line 4863 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 228: // declaration: annotations variable_declaration
#line 1435 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Variable* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Declaration_Variable* > ();
        }
#line 4872 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 229: // declaration: annotations function_declaration
#line 1440 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Function* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Function* > ();
        }
#line 4881 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 230: // declaration_list: declaration
#line 1447 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Vector<IR::Node>* > () = new IR::IndexedVector<IR::Node>();
                if (yystack_[0].value.as < IR::Node* > ()) yylhs.value.as < IR::Vector<IR::Node>* > ()->push_back(yystack_[0].value.as < IR::Node* > ());
        }
#line 4890 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 231: // declaration_list: declaration_list declaration
#line 1452 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                if (yystack_[0].value.as < IR::Node* > ()) yystack_[1].value.as < IR::Vector<IR::Node>* > ()->push_back(yystack_[0].value.as < IR::Node* > ());
                yylhs.value.as < IR::Vector<IR::Node>* > () = yystack_[1].value.as < IR::Vector<IR::Node>* > ();
        }
#line 4899 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 233: // input: input declaration
#line 1460 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                             {
                if (yystack_[0].value.as < IR::Node* > ()) driver.nodes->push_back(yystack_[0].value.as < IR::Node* > ()->getNode());
        }
#line 4907 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 234: // input: input ";"
#line 1463 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                           {}
#line 4913 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;


#line 4917 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;

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
    YY_STACK_PRINT ();
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

  std::string
  P5Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // P5Parser::context.
  P5Parser::context::context (const P5Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  P5Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  P5Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
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

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  P5Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

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
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short P5Parser::yypact_ninf_ = -426;

  const short P5Parser::yytable_ninf_ = -143;

  const short
  P5Parser::yypact_[] =
  {
    -426,    66,   108,  -426,  -426,  -426,   676,  -426,   146,   489,
     146,   146,    76,   146,   146,   489,   146,   316,   207,  -426,
     489,   146,  -426,   167,  -426,   146,  -426,  -426,  -426,  -426,
     277,   310,   319,  -426,  -426,  -426,   431,   146,  -426,   147,
     423,   362,   460,   461,   146,   490,   362,   146,   146,   247,
     146,   146,   237,  -426,  -426,  -426,  -426,   272,    10,   340,
     626,   146,  -426,   361,  -426,  -426,  -426,  -426,   458,   459,
      15,   340,   626,  -426,    74,   340,   272,   272,  -426,   231,
     272,   272,    21,   101,   101,   101,   101,  -426,  -426,   509,
    -426,  -426,   519,  -426,  -426,   360,  -426,   468,   576,   385,
     491,   496,   494,   488,   190,  -426,   531,   444,  -426,   280,
     272,   272,   272,   118,  -426,   449,   272,   539,   550,    35,
     146,   758,  -426,  -426,   516,  -426,  -426,   474,   552,  -426,
     162,  -426,  -426,   578,   258,  -426,  -426,  -426,   580,   584,
    -426,  -426,   272,  -426,   457,   500,   146,  -426,   466,   355,
      34,   154,   294,   587,   429,   194,   573,   442,  -426,  -426,
    -426,  -426,    21,   272,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   272,   101,  -426,  -426,   272,   272,   146,   366,   123,
      31,    19,   615,  -426,    21,   619,   272,    21,   186,   272,
     562,   272,   583,   272,   272,   272,   272,   272,   272,   272,
     272,  -426,  -426,  -426,   272,  -426,   146,  -426,  -426,     1,
      48,   146,  -426,  -426,  -426,   373,   630,  -426,   605,   634,
     265,  -426,  -426,   101,  -426,   272,   624,   272,   280,   531,
    -426,   471,   513,   513,  -426,  -426,  -426,  -426,  -426,   468,
     468,   468,   468,   576,   576,   385,   491,   496,   494,   292,
     488,   531,   364,  -426,   625,  -426,   555,   146,   326,   626,
    -426,   343,   280,  -426,   481,   574,   482,    44,   144,  -426,
     148,  -426,   168,   178,   198,   204,   208,   215,   246,   250,
     531,  -426,  -426,  -426,   269,   592,   626,  -426,  -426,  -426,
     272,   272,  -426,  -426,   389,   272,  -426,  -426,   272,   101,
    -426,   272,   272,   272,   352,   638,   272,   524,   642,    21,
     645,    56,   574,   643,  -426,  -426,  -426,  -426,  -426,  -426,
    -426,  -426,  -426,  -426,  -426,   644,   646,   272,   272,  -426,
    -426,   598,   654,   391,   260,  -426,  -426,  -426,  -426,   395,
     268,    36,   655,   272,  -426,   531,  -426,  -426,  -426,    21,
    -426,   649,   253,  -426,  -426,  -426,    96,   223,   403,   273,
    -426,  -426,   357,  -426,     7,  -426,  -426,  -426,   577,  -426,
     531,    18,  -426,   656,   485,   664,   126,  -426,   622,  -426,
     627,   129,  -426,   628,  -426,   673,   674,    63,   679,  -426,
    -426,  -426,  -426,  -426,  -426,  -426,  -426,  -426,  -426,   272,
    -426,   272,   272,   669,  -426,  -426,   681,  -426,   146,  -426,
    -426,  -426,   272,  -426,  -426,   609,  -426,   272,  -426,   684,
      30,  -426,  -426,    21,   278,     3,    43,  -426,   543,   683,
    -426,   685,   639,   439,   689,   650,   305,    38,    21,   272,
    -426,   486,  -426,  -426,   272,   272,   688,   332,   161,  -426,
     691,  -426,  -426,   653,   272,   272,  -426,  -426,  -426,   504,
     507,   700,   531,  -426,   332,  -426,  -426,  -426,  -426,   369,
     272,   680,  -426,  -426,  -426,   314,   290,   647,   702,   658,
    -426,   582,  -426,  -426,   564,   705,  -426,    21,  -426,   538,
    -426,   110,  -426,   706,  -426,   708,  -426,   272,   699,  -426,
     122,  -426,   272,   701,  -426,  -426,    59,  -426,   588,    52,
    -426,  -426,   608,   150,    72,  -426,  -426,    52,  -426,   157,
    -426,  -426,  -426,  -426
  };

  const unsigned char
  P5Parser::yydefact_[] =
  {
     232,     0,    58,     1,     2,   234,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,     0,     4,    63,    59,     0,   223,   225,   228,   226,
       0,     0,    62,   224,   229,    58,    56,     0,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   219,   218,   227,     0,     0,    58,
       0,     0,     5,     0,    58,    58,   210,    58,     0,     0,
       0,    58,     0,    64,     0,    58,     0,     0,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     8,    68,
       7,    11,    13,    18,    20,    24,    27,    30,    35,    38,
      40,    42,    44,    46,    48,    50,    54,     0,    72,     6,
       0,     0,     0,     0,   129,     0,     0,     0,     0,    68,
       0,   114,   202,   203,     0,   201,   204,     0,   211,   213,
       0,    61,   230,    58,     0,    83,    84,    85,    58,    58,
      60,    98,     0,    90,     0,     0,     0,    65,     0,     0,
       0,    68,     0,     0,     0,     0,     6,     0,    17,    14,
      15,    16,     0,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    57,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,   132,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   209,   205,     0,   215,     0,   222,   231,     0,
       0,     0,   216,    86,   217,     0,     0,   207,     0,     0,
       0,    93,     9,     0,    10,     0,     0,     0,    71,   131,
     133,     0,    25,    26,    21,    22,    23,    29,    28,    32,
      31,    34,    33,    36,    37,    39,    41,    43,    45,     0,
      47,    55,     0,    69,     0,    87,     0,     0,   122,     0,
     130,    68,   114,   116,     0,   175,     0,    68,     0,   157,
       0,   158,     0,     0,     0,     0,     0,     0,     0,     0,
     212,   214,    58,    58,     0,     0,     0,    66,   169,   221,
       0,     0,    94,    19,     0,     0,    52,    12,     0,     0,
      70,     0,     0,     0,   124,     0,     0,     0,     0,     0,
       0,    58,   184,     0,   115,   147,   149,   148,   150,   151,
     152,   153,   154,   156,   155,    58,    58,     0,     0,    75,
      91,     0,    58,     0,     0,    74,    53,   134,    49,     0,
       0,     0,     0,     0,   127,   123,   208,    58,   117,     0,
     198,     0,     0,   176,   185,   199,     0,     0,     0,     0,
     206,   171,     0,   170,     0,    95,    73,    88,     0,   126,
     125,     0,   196,    58,     0,     0,     0,    79,     0,    81,
       0,     0,    76,     0,    58,     0,     0,     0,     0,   160,
     159,   166,   167,   164,   162,   165,   163,   168,   161,     0,
      96,     0,     0,     0,   200,   197,     0,   169,     0,   174,
      80,    82,     0,    77,   121,     0,    58,     0,   102,     0,
       0,   120,   119,     0,     0,     0,   104,   106,     0,   195,
      58,    58,     0,     0,     0,     0,     0,     0,     0,   132,
     101,     0,    97,    89,     0,     0,   193,   189,     0,   181,
      58,   172,   173,     0,     0,     0,    58,   100,   103,     0,
       0,     0,   105,   107,   189,   186,   187,   188,   190,     0,
       0,     0,   183,   182,    78,     0,     0,   136,     0,     0,
     143,     0,   194,   191,     0,   180,   135,     0,    58,     0,
      99,     0,   192,   178,   175,     0,   137,     0,     0,   112,
       0,   145,     0,     0,   144,   175,    58,    58,     0,   111,
     118,   113,     0,    58,    58,   179,   138,   109,   110,    58,
     141,   177,   108,   139
  };

  const short
  P5Parser::yypgoto_[] =
  {
    -426,  -426,  -426,    28,   425,  -426,  -426,  -426,   -70,   -83,
      42,   445,   386,   541,   542,   537,   546,   540,  -426,   410,
     424,   641,  -426,    -2,    11,  -426,    32,  -426,  -426,  -128,
     -60,    -5,  -426,    -1,  -425,  -426,   275,  -153,   213,  -426,
    -192,  -347,  -426,  -426,  -426,  -189,   327,   419,  -190,  -426,
    -426,  -426,  -426,  -426,  -426,  -340,  -373,   311,   359,  -426,
    -233,   279,  -426,  -426,   421,  -129,   270,   363,  -426,  -118,
     -69,  -426,  -426,   529,  -426,  -426,   742,  -426,  -426,  -426,
     -17,  -426,  -426
  };

  const short
  P5Parser::yydefgoto_[] =
  {
       0,     1,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     436,   107,    24,   134,   120,   108,   109,   135,   136,   137,
     138,   122,    27,   123,   431,   447,   437,   438,   509,   510,
     124,   274,   432,   401,   402,   114,   115,   240,   241,   403,
     404,   405,   514,   501,   406,   125,   373,   342,   299,   363,
     321,   459,   460,   322,   323,   478,   479,   382,   383,   126,
     127,    29,    30,   129,   130,    31,    38,    33,    34,    35,
       7,   133,     2
  };

  const short
  P5Parser::yytable_[] =
  {
       6,    26,   273,   145,   270,    28,   276,   139,   292,   213,
     223,   223,   384,   158,   159,   160,   161,    25,    56,   110,
      37,   425,   468,   183,   142,   409,    44,   213,   111,     8,
     116,    48,   407,     6,    23,   449,    36,    23,    39,    40,
     196,    42,    43,    23,    45,   428,   467,   132,    23,    49,
     -64,   183,   197,    52,   183,   293,   183,   113,   267,   428,
     410,   162,     6,   183,   360,    58,     3,   525,   143,   113,
     428,    51,    66,   113,   412,    69,    70,   413,    73,    74,
     531,   242,   243,   450,   454,    22,   451,   231,   119,   128,
     153,   146,   121,   487,   528,   453,   244,   245,   246,   112,
     119,   469,   532,    22,   121,    22,    79,   151,    80,   147,
     116,     4,    41,   156,   157,    83,   218,   477,   511,   -63,
      84,   266,    22,    85,   191,   506,   378,   358,   -64,     8,
     520,     6,    22,    86,   477,   429,    22,   361,   422,   477,
     361,    23,   418,   183,   526,   221,   183,    22,   198,   387,
     530,   477,    59,   361,    60,   119,   533,   505,  -142,   121,
     -63,     5,    23,   303,   183,  -140,   512,   273,   183,   513,
     215,   197,     8,   119,   228,   216,   265,   121,   507,   419,
      22,   508,   423,    12,    50,    22,    87,    62,   183,    14,
      51,   113,    16,    17,   238,    76,    19,   325,   183,   213,
     317,   326,    22,    51,    77,   181,  -142,   223,   223,  -142,
     235,   247,   248,  -140,   183,   263,  -140,   480,   183,   268,
     481,   327,   271,   213,   183,   277,   272,   341,   183,   238,
      22,   328,   335,   336,   182,   183,    79,   445,    80,    78,
      81,   273,    75,    82,   128,    83,    76,    43,    45,   294,
      84,   329,    71,    85,    72,    77,   273,   330,    79,   470,
      80,   331,    81,    86,     8,    82,   183,    83,   332,     8,
     183,   516,    84,    47,   300,    85,   389,    79,   337,    80,
     183,    81,   524,   301,    82,    86,    83,   338,   183,   186,
      78,    84,   187,   183,    85,   314,    12,   119,   183,   333,
     232,   121,    14,   334,    86,    16,    17,    22,   309,    19,
     183,   466,   183,   375,   183,    22,    87,    62,   302,   362,
     496,   377,   339,    12,   119,   183,   392,   494,   121,   219,
      53,   452,   220,    17,   183,   315,    19,    22,    87,    62,
     372,   116,    22,   497,   316,   119,  -128,   271,   196,   121,
     493,   272,    46,  -128,   518,   381,    22,    87,    62,   522,
     162,   352,   493,    54,   298,   230,   116,   399,     8,   119,
     353,   400,    55,   121,   310,   183,   264,   492,   116,   164,
     311,   381,   165,   295,   183,   166,   183,   271,   167,     9,
     168,   272,   372,   183,   388,   390,   131,    12,   144,   345,
     119,   374,   148,    14,   121,   376,    16,    17,    18,   183,
      19,   183,   393,   391,     9,   183,    22,   394,   175,   176,
     395,   396,    12,   183,   113,   430,     9,   397,    14,   398,
      61,    16,    17,    18,    12,    19,    57,   234,   458,   372,
      14,    22,   185,    16,    17,    18,   442,    19,    62,   463,
     184,   186,   475,    22,   187,   192,   476,   185,   458,   183,
     237,   271,   193,   226,   372,   272,    63,    64,    65,   475,
     193,    68,   229,   476,   475,   430,   271,   307,   476,   193,
     272,   106,   212,   116,   308,   119,   475,   318,   324,   121,
     476,   416,   471,   140,   319,   308,   372,    67,   319,   319,
     149,   150,   119,   152,   106,   155,   121,   119,   227,   116,
     488,   121,   141,   489,   362,   372,   169,   319,   170,   119,
     308,   372,   362,   121,   163,   271,   162,   372,   180,   121,
     177,     9,   356,   116,   188,   189,   190,   179,   166,    12,
     155,   167,   178,   168,   194,    14,   117,   430,    16,    17,
      18,   183,    19,   118,    12,   430,   455,     9,    22,   456,
      14,   253,   254,    16,    17,    12,   225,    19,   195,   211,
     214,    14,   117,    22,    16,    17,    18,   455,    19,   118,
     503,     9,   186,   236,    22,   187,   217,   239,   222,    12,
     502,   116,   224,   233,   507,    14,   117,   508,    16,    17,
      18,   455,    19,   118,   527,   259,   370,   116,    22,   261,
     262,   171,   172,   173,   174,   279,   249,   250,   251,   252,
     239,   455,   269,   278,   529,   280,   275,   282,   283,   284,
     285,   286,   287,   288,   289,   116,   281,   296,   290,     9,
     297,   298,   305,   312,   313,   340,   320,    12,   354,   357,
     359,   365,   366,    14,   367,     9,    16,    17,    18,   304,
      19,   306,   371,    12,   414,   379,    22,   385,   411,    14,
     117,   417,    16,    17,    18,   420,    19,   118,   426,   427,
     421,   424,    22,     9,   433,   439,   444,     8,   440,   448,
     457,    12,   462,   461,   464,   474,   495,    14,   117,   482,
      16,    17,    18,   465,    19,   118,   484,   490,   498,   499,
      22,   500,   504,   515,   517,   519,   257,   523,   255,   348,
     256,   154,   260,   521,   343,   344,   258,   347,   441,   346,
     473,   408,   239,     9,    10,   349,   350,   351,    11,   483,
     355,    12,    13,   364,   491,   291,   415,    14,    32,    15,
      16,    17,    18,     0,    19,     0,     0,     0,    20,    21,
      22,   368,   369,     0,     0,     0,     0,   186,     0,     0,
     187,     0,     0,     0,     0,     0,   199,   380,   200,   201,
       0,   202,   203,     0,     0,   204,   386,   205,     0,   206,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   207,     0,   208,     0,   209,     0,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   434,     0,   435,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   443,     0,     0,     0,
       0,   446,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,     0,     0,     0,     0,   472,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   485,   486
  };

  const short
  P5Parser::yycheck_[] =
  {
       2,     6,   194,    72,   193,     6,   196,    67,     7,   127,
     138,   139,   359,    83,    84,    85,    86,     6,    35,     9,
       9,   394,   447,    20,     9,    18,    15,   145,    18,    11,
       9,    20,   372,    35,     6,     5,     8,     9,    10,    11,
       5,    13,    14,    15,    16,     7,     8,    64,    20,    21,
       6,    20,    17,    25,    20,     7,    20,    59,    39,     7,
      53,    17,    64,    20,     8,    37,     0,     8,    53,    71,
       7,    36,    44,    75,    56,    47,    48,    59,    50,    51,
       8,   164,   165,    53,    41,    84,   433,    53,    60,    61,
      79,    17,    60,   466,   519,    92,   166,   167,   168,    89,
      72,   448,   527,    84,    72,    84,     5,    79,     7,    35,
       9,     3,    36,    81,    82,    14,   133,   457,     8,    84,
      19,    90,    84,    22,   113,   498,    90,   319,    84,    11,
       8,   133,    84,    32,   474,    72,    84,    81,     9,   479,
      81,   113,    16,    20,   517,   134,    20,    84,   120,    53,
     523,   491,     5,    81,     7,   127,   529,   497,     8,   127,
       6,    53,   134,   233,    20,     8,    56,   359,    20,    59,
       8,    17,    11,   145,   146,    13,    53,   145,    56,    53,
      84,    59,    53,    65,    17,    84,    85,    86,    20,    71,
      36,   193,    74,    75,   162,     9,    78,    53,    20,   317,
     269,    53,    84,    36,    18,    15,    56,   335,   336,    59,
      16,   169,   170,    56,    20,   187,    59,    56,    20,   191,
      59,    53,   194,   341,    20,   197,   194,   296,    20,   197,
      84,    53,   292,   293,    44,    20,     5,   426,     7,    53,
       9,   433,     5,    12,   216,    14,     9,   219,   220,   221,
      19,    53,     5,    22,     7,    18,   448,    53,     5,   449,
       7,    53,     9,    32,    11,    12,    20,    14,    53,    11,
      20,   504,    19,    66,     9,    22,    53,     5,     9,     7,
      20,     9,   515,    18,    12,    32,    14,    18,    20,     9,
      53,    19,    12,    20,    22,   267,    65,   269,    20,    53,
       6,   269,    71,    53,    32,    74,    75,    84,    16,    78,
      20,     6,    20,    53,    20,    84,    85,    86,    53,   321,
       6,    53,    53,    65,   296,    20,    53,   480,   296,    71,
      53,    53,    74,    75,    20,     9,    78,    84,    85,    86,
     342,     9,    84,    53,    18,   317,     6,   319,     5,   317,
     479,   319,    36,    13,   507,   357,    84,    85,    86,   512,
      17,     9,   491,    53,     7,    10,     9,   372,    11,   341,
      18,   372,    53,   341,    10,    20,    10,     8,     9,    19,
      16,   383,    22,    10,    20,    25,    20,   359,    28,    57,
      30,   359,   394,    20,   366,   367,    35,    65,    71,    10,
     372,    10,    75,    71,   372,    10,    74,    75,    76,    20,
      78,    20,    55,    10,    57,    20,    84,    60,    33,    34,
      63,    64,    65,    20,   426,   397,    57,    70,    71,    72,
       7,    74,    75,    76,    65,    78,     5,     8,   440,   441,
      71,    84,    13,    74,    75,    76,   418,    78,    86,    10,
       6,     9,   457,    84,    12,     6,   457,    13,   460,    20,
      18,   433,    13,     6,   466,   433,    41,     7,     7,   474,
      13,    46,     6,   474,   479,   447,   448,     6,   479,    13,
     448,    57,     8,     9,    13,   457,   491,     6,     6,   457,
     491,     6,     6,    35,    13,    13,   498,     7,    13,    13,
      76,    77,   474,    79,    80,    81,   474,   479,     8,     9,
       6,   479,    53,     6,   516,   517,    48,    13,    50,   491,
      13,   523,   524,   491,     5,   497,    17,   529,    40,   497,
      39,    57,     8,     9,   110,   111,   112,    43,    25,    65,
     116,    28,    46,    30,     5,    71,    72,   519,    74,    75,
      76,    20,    78,    79,    65,   527,    13,    57,    84,    16,
      71,   175,   176,    74,    75,    65,   142,    78,    18,    53,
      18,    71,    72,    84,    74,    75,    76,    13,    78,    79,
      16,    57,     9,    10,    84,    12,     8,   163,     8,    65,
       8,     9,     8,     6,    56,    71,    72,    59,    74,    75,
      76,    13,    78,    79,    16,   181,     8,     9,    84,   185,
     186,    35,    36,    37,    38,    53,   171,   172,   173,   174,
     196,    13,     7,   199,    16,   201,     7,   203,   204,   205,
     206,   207,   208,   209,   210,     9,    53,     7,   214,    57,
      35,     7,    18,    18,    89,    53,    72,    65,    10,     7,
       5,     8,     8,    71,     8,    57,    74,    75,    76,   235,
      78,   237,     8,    65,     8,    10,    84,    18,    91,    71,
      72,     7,    74,    75,    76,    53,    78,    79,     5,     5,
      53,    53,    84,    57,     5,    16,    77,    11,     7,     5,
       7,    65,    53,     8,     5,     7,    16,    71,    72,     8,
      74,    75,    76,    53,    78,    79,    53,     7,    61,     7,
      84,    53,     7,     7,     6,    16,   179,    16,   177,   309,
     178,    80,   182,   510,   300,   301,   180,   308,   417,   305,
     455,   372,   308,    57,    58,   311,   312,   313,    62,   460,
     316,    65,    66,   322,   474,   216,   383,    71,     6,    73,
      74,    75,    76,    -1,    78,    -1,    -1,    -1,    82,    83,
      84,   337,   338,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    18,   353,    20,    21,
      -1,    23,    24,    -1,    -1,    27,   362,    29,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    47,    -1,    49,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   409,    -1,   411,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   422,    -1,    -1,    -1,
      -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   449,    -1,    -1,    -1,    -1,   454,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   464,   465
  };

  const unsigned char
  P5Parser::yystos_[] =
  {
       0,    94,   175,     0,     3,    53,   116,   173,    11,    57,
      58,    62,    65,    66,    71,    73,    74,    75,    76,    78,
      82,    83,    84,    96,   115,   117,   124,   125,   126,   164,
     165,   168,   169,   170,   171,   172,    96,   117,   169,    96,
      96,    36,    96,    96,   117,    96,    36,    66,   117,    96,
      17,    36,    96,    53,    53,    53,   173,     5,    96,     5,
       7,     7,    86,    97,     7,     7,    96,     7,    97,    96,
      96,     5,     7,    96,    96,     5,     9,    18,    53,     5,
       7,     9,    12,    14,    19,    22,    32,    85,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   118,   119,
       9,    18,    89,   116,   138,   139,     9,    72,    79,    96,
     117,   119,   124,   126,   133,   148,   162,   163,    96,   166,
     167,    35,   173,   174,   116,   120,   121,   122,   123,   123,
      35,    53,     9,    53,   139,   163,    17,    35,   139,   113,
     113,    96,   113,   117,   114,   113,   119,   119,   101,   101,
     101,   101,    17,     5,    19,    22,    25,    28,    30,    48,
      50,    35,    36,    37,    38,    33,    34,    39,    46,    43,
      40,    15,    44,    20,     6,    13,     9,    12,   113,   113,
     113,   117,     6,    13,     5,    18,     5,    17,    96,    18,
      20,    21,    23,    24,    27,    29,    31,    45,    47,    49,
      51,    53,     8,   162,    18,     8,    13,     8,   173,    71,
      74,   117,     8,   122,     8,   113,     6,     8,    96,     6,
      10,    53,     6,     6,     8,    16,    10,    18,   119,   113,
     140,   141,   102,   102,   101,   101,   101,   103,   103,   104,
     104,   104,   104,   105,   105,   106,   107,   108,   109,   113,
     110,   113,   113,    96,    10,    53,    90,    39,    96,     7,
     138,    96,   119,   133,   134,     7,   141,    96,   113,    53,
     113,    53,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   166,     7,     7,    96,    10,     7,    35,     7,   151,
       9,    18,    53,   101,   113,    18,   113,     6,    13,    16,
      10,    16,    18,    89,    96,     9,    18,   163,     6,    13,
      72,   153,   156,   157,     6,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,   123,   123,     9,    18,    53,
      53,   163,   150,   113,   113,    10,   113,   140,   112,   113,
     113,   113,     9,    18,    10,   113,     8,     7,   133,     5,
       8,    81,   116,   152,   157,     8,     8,     8,   113,   113,
       8,     8,   116,   149,    10,    53,    10,    53,    90,    10,
     113,   116,   160,   161,   134,    18,   113,    53,    96,    53,
      96,    10,    53,    55,    60,    63,    64,    70,    72,   124,
     126,   136,   137,   142,   143,   144,   147,   148,   151,    18,
      53,    91,    56,    59,     8,   160,     6,     7,    16,    53,
      53,    53,     9,    53,    53,   149,     5,     5,     7,    72,
      96,   127,   135,     5,   113,   113,   113,   129,   130,    16,
       7,   150,    96,   113,    77,   138,   113,   128,     5,     5,
      53,   134,    53,    92,    41,    13,    16,     7,   116,   154,
     155,     8,    53,    10,     5,    53,     6,     8,   127,   134,
     141,     6,   113,   129,     7,   124,   126,   148,   158,   159,
      56,    59,     8,   154,    53,   113,   113,   149,     6,     6,
       7,   159,     8,   158,   130,    16,     6,    53,    61,     7,
      53,   146,     8,    16,     7,   148,   149,    56,    59,   131,
     132,     8,    56,    59,   145,     7,   153,     6,   130,    16,
       8,   131,   130,    16,   153,     8,   149,    16,   127,    16,
     149,     8,   127,   149
  };

  const unsigned char
  P5Parser::yyr1_[] =
  {
       0,    93,    94,    95,    96,    97,    98,    98,    98,    98,
      98,    99,    99,   100,   100,   100,   100,   100,   101,   101,
     102,   102,   102,   102,   103,   103,   103,   104,   104,   104,
     105,   105,   105,   105,   105,   106,   106,   106,   107,   107,
     108,   108,   109,   109,   110,   110,   111,   111,   112,   112,
     113,   113,   113,   113,   114,   114,   115,   115,   116,   116,
     117,   117,   117,   117,   117,   117,   117,   117,   118,   118,
     118,   118,   119,   119,   119,   120,   120,   120,   120,   121,
     121,   121,   121,   122,   122,   123,   123,   124,   124,   124,
     125,   125,   126,   126,   126,   126,   126,   126,   126,   127,
     127,   127,   128,   128,   129,   129,   130,   130,   131,   131,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   136,
     136,   137,   138,   138,   138,   138,   138,   138,   139,   139,
     139,   140,   141,   141,   141,   142,   143,   143,   144,   145,
     145,   145,   145,   146,   146,   147,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   150,
     150,   151,   152,   152,   152,   153,   153,   154,   154,   154,
     154,   155,   155,   156,   157,   157,   158,   158,   158,   159,
     159,   159,   160,   160,   160,   160,   161,   161,   162,   162,
     162,   162,   162,   162,   163,   163,   164,   164,   164,   164,
     165,   166,   166,   167,   167,   168,   169,   169,   170,   170,
     170,   171,   172,   173,   173,   173,   173,   173,   173,   173,
     174,   174,   175,   175,   175
  };

  const signed char
  P5Parser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     4,     1,     2,     2,     2,     2,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     2,     4,     5,     1,     3,     2,     5,     0,     2,
       4,     4,     1,     1,     3,     4,     6,     1,     1,     3,
       4,     3,     1,     6,     5,     4,     6,     7,    10,     6,
       7,     6,     7,     1,     1,     1,     2,     6,     9,    12,
       4,     7,     3,     5,     6,     8,     9,    11,     4,     5,
       3,     2,     0,     2,     1,     3,     1,     3,     4,     3,
       3,     2,     1,     2,     1,     4,     1,     3,     7,     2,
       2,     2,     3,     5,     4,     6,     6,     5,     0,     1,
       3,     1,     0,     1,     3,     6,     5,     7,     9,     4,
       3,     3,     2,     0,     2,     7,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     3,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     0,
       2,     3,     5,     5,     3,     0,     2,     7,     4,     6,
       3,     1,     2,     7,     1,     2,     1,     1,     1,     0,
       1,     2,     7,     4,     6,     3,     1,     2,     5,     5,
       7,     1,     1,     1,     1,     2,     8,     5,     8,     5,
       3,     1,     3,     1,     3,     5,     5,     5,     2,     2,
       2,     6,     5,     2,     2,     2,     2,     3,     2,     2,
       1,     2,     0,     2,     2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const P5Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "END",
  "UNEXPECTED_TOKEN", "\"(\"", "\")\"", "\"{\"", "\"}\"", "\"[\"", "\"]\"",
  "\"@\"", "\".\"", "\",\"", "\"~\"", "\"?\"", "\":\"", "\"::\"", "\"=\"",
  "\"+\"", "\"++\"", "\"+=\"", "\"-\"", "\"--\"", "\"-=\"", "\"*\"",
  "\"**\"", "\"*=\"", "\"/\"", "\"/=\"", "\"%\"", "\"%=\"", "\"!\"",
  "\"==\"", "\"!=\"", "\">\"", "\"<\"", "\">=\"", "\"<=\"", "\"&\"",
  "\"&&\"", "\"&&&\"", "\"&=\"", "\"|\"", "\"||\"", "\"|=\"", "\"^\"",
  "\"^=\"", "\">>\"", "\">>=\"", "\"<<\"", "\"<<=\"", "\"#\"", "\";\"",
  "NEWLINE", "BREAK", "CASE", "CONST", "CLASS", "DEFAULT", "DO", "ELSE",
  "ENUM", "FOR", "IF", "INT", "NAMESPACE", "PRIVATE", "PROTECTED",
  "PUBLIC", "RETURN", "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UINT",
  "USING", "WHILE", "VOID", "KEY", "SIZE", "CONTROL_PARAMETERS", "HEADER",
  "TABLE", "IDENTIFIER", "STRING_LITERAL", "INTEGER", "LPAREN_PREC",
  "THEN", "'['", "']'", "'='", "';'", "$accept", "program", "string_lit",
  "ID", "const_value", "primary_expression", "postfix_expression",
  "unary_expression", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression", "expression",
  "expression_list", "annotation", "annotations", "type_ref",
  "field_ref_no_slice", "field_ref", "field_dec",
  "anonymous_struct_union_dec", "struct_field_dec", "struct_field_list",
  "constant_declaration", "header_declaration", "variable_declaration",
  "return_value_type", "return_value_type_list", "value_masked_or_set",
  "value_list", "case_entry", "case_list", "field_ref_or_func",
  "select_exp", "return_select_statement", "return_statement",
  "break_statement", "parameter", "param_list", "arg", "arg_list",
  "do_while_statement", "conditional_statement", "for_loop_statement",
  "case", "switch_cases", "switch_statement",
  "assignment_or_call_statement", "action_statement",
  "action_statement_list", "action_compound_statement", "key_element",
  "key_element_list", "key_case_entry", "key_case_list",
  "key_switch_entry", "key_switch_list", "program_selection_statement",
  "program_selection_statement_list", "table_case_entry",
  "table_case_list", "table_property", "table_property_list",
  "table_declaration", "typedef_declaration", "enumerator",
  "enumerator_list", "enum_declaration", "struct_union_type_declaration",
  "type_declaration", "function_declaration", "namespace", "declaration",
  "declaration_list", "input", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  P5Parser::yyrline_[] =
  {
       0,   328,   328,   337,   341,   351,   354,   355,   356,   357,
     358,   362,   363,   367,   368,   369,   370,   371,   375,   376,
     380,   381,   382,   383,   387,   388,   389,   393,   394,   395,
     399,   400,   401,   402,   403,   407,   408,   409,   413,   414,
     418,   419,   423,   424,   428,   429,   433,   434,   438,   439,
     443,   445,   450,   454,   460,   463,   474,   480,   487,   490,
     504,   508,   512,   515,   519,   523,   527,   531,   536,   538,
     539,   540,   545,   546,   547,   550,   557,   565,   573,   584,
     593,   602,   613,   625,   626,   630,   636,   650,   654,   659,
     667,   671,   677,   678,   679,   683,   687,   692,   697,   706,
     712,   713,   719,   722,   728,   729,   732,   738,   745,   756,
     762,   773,   781,   786,   793,   796,   803,   808,   814,   819,
     820,   823,   831,   838,   845,   852,   859,   869,   881,   882,
     887,   895,   898,   899,   905,   913,   929,   935,   946,   967,
     977,   983,   992,   999,  1000,  1006,  1011,  1018,  1021,  1025,
    1029,  1033,  1037,  1041,  1045,  1049,  1053,  1057,  1062,  1069,
    1073,  1077,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1091,
    1092,  1098,  1107,  1112,  1119,  1127,  1130,  1136,  1145,  1156,
    1165,  1177,  1182,  1188,  1195,  1200,  1207,  1208,  1209,  1212,
    1215,  1220,  1226,  1236,  1241,  1251,  1258,  1264,  1272,  1277,
    1282,  1285,  1288,  1291,  1297,  1301,  1309,  1312,  1315,  1318,
    1330,  1337,  1341,  1347,  1357,  1371,  1378,  1382,  1391,  1392,
    1393,  1396,  1404,  1414,  1419,  1424,  1429,  1433,  1434,  1439,
    1446,  1451,  1459,  1460,  1463
  };

  void
  P5Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  P5Parser::yy_reduce_print_ (int yyrule) const
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


#line 7 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
} } // P4::P5
#line 5835 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"

#line 1466 "/root/p4c/frontends/parsers/p5/p5parser.ypp"


namespace P4 {

void P5::P5Parser::error(const Util::SourceInfo& location,
                         const std::string& message) {
    driver.onParseError(location, message);
}

}  // namespace P4
