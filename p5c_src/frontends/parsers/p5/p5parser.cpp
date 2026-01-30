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
      case symbol_kind::S_assignment_or_call: // assignment_or_call
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
      case symbol_kind::S_assignment_or_call: // assignment_or_call
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
      case symbol_kind::S_assignment_or_call: // assignment_or_call
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
      case symbol_kind::S_assignment_or_call: // assignment_or_call
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
#line 1240 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_CASE: // CASE
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1246 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_CONST: // CONST
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1252 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_CLASS: // CLASS
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1258 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_DEFAULT: // DEFAULT
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1264 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_DO: // DO
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1270 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1276 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_ENUM: // ENUM
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1282 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1288 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1294 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_INT: // INT
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1300 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_NAMESPACE: // NAMESPACE
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1306 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_PRIVATE: // PRIVATE
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1312 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_PROTECTED: // PROTECTED
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1318 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_PUBLIC: // PUBLIC
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1324 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1330 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_STRUCT: // STRUCT
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1336 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_SWITCH: // SWITCH
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1342 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_TYPEDEF: // TYPEDEF
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1348 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_UNION: // UNION
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1354 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_UINT: // UINT
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1360 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_USING: // USING
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1366 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1372 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_VOID: // VOID
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1378 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_KEY: // KEY
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1384 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_SIZE: // SIZE
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1390 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_CONTROL_PARAMETERS: // CONTROL_PARAMETERS
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1396 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_HEADER: // HEADER
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1402 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_TABLE: // TABLE
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1408 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1414 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1420 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < UnparsedConstant > (); }
#line 1426 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1439 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1452 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1465 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1478 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1491 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1504 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1517 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1530 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1543 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1556 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1569 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1582 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1595 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1608 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1621 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1634 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1647 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1660 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1673 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1686 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1699 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1712 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1725 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1738 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1751 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1764 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1777 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1790 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1803 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1816 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1829 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1842 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1855 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1868 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1881 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1894 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1907 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1920 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1933 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1946 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1959 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1972 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1985 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 1998 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2011 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2024 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2037 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2050 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2063 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2076 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2089 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2102 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2115 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_assignment_or_call: // assignment_or_call
#line 164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2128 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2141 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2154 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2167 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2180 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2193 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2206 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2219 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2232 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2245 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2258 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2271 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2284 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2297 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2310 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2323 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2336 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2349 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2362 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2375 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2388 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2401 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2414 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2427 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2440 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2453 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
#line 2466 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
      case symbol_kind::S_assignment_or_call: // assignment_or_call
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
#line 2951 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 3: // string_lit: STRING_LITERAL
#line 337 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         { yylhs.value.as < IR::StringLiteral* > () = new IR::StringLiteral(yystack_[0].location, yystack_[0].value.as < cstring > ()); }
#line 2957 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 4: // ID: IDENTIFIER
#line 341 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     { yylhs.value.as < IR::ID* > () = new IR::ID(yystack_[0].location, yystack_[0].value.as < cstring > ()); }
#line 2963 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 5: // const_value: INTEGER
#line 351 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                  { yylhs.value.as < IR::Constant* > () = parseConstant(yystack_[0].location, yystack_[0].value.as < UnparsedConstant > (), 0); }
#line 2969 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 6: // primary_expression: field_ref
#line 354 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 2975 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 7: // primary_expression: const_value
#line 355 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Constant* > (); }
#line 2981 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 8: // primary_expression: string_lit
#line 356 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::StringLiteral* > (); }
#line 2987 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 9: // primary_expression: "(" expression ")"
#line 357 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[1].value.as < IR::Expression* > (); }
#line 2993 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 10: // primary_expression: "[" expression "]"
#line 358 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[1].value.as < IR::Expression* > (); }
#line 2999 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 11: // primary_expression: "{" expression_list "}"
#line 359 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = new IR::ListExpression(yystack_[2].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ()); }
#line 3005 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 12: // postfix_expression: primary_expression
#line 363 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3011 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 13: // postfix_expression: postfix_expression "(" arg_list ")"
#line 364 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                              { yylhs.value.as < IR::Expression* > () = new IR::MethodCallExpression(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Vector<IR::Argument>* > ()); }
#line 3017 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 14: // unary_expression: postfix_expression
#line 368 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3023 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 15: // unary_expression: "+" cast_expression
#line 369 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3029 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 16: // unary_expression: "-" cast_expression
#line 370 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = new IR::Neg(yystack_[1].location, yystack_[0].value.as < IR::Expression* > ()); }
#line 3035 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 17: // unary_expression: "!" cast_expression
#line 371 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = new IR::LNot(yystack_[1].location, yystack_[0].value.as < IR::Expression* > ()); }
#line 3041 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 18: // unary_expression: "~" cast_expression
#line 372 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = new IR::Cmpl(yystack_[1].location, yystack_[0].value.as < IR::Expression* > ()); }
#line 3047 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 19: // cast_expression: unary_expression
#line 376 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3053 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 20: // cast_expression: "(" type_ref ")" cast_expression
#line 377 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           { yylhs.value.as < IR::Expression* > () = new IR::Cast(yystack_[3].location, yystack_[2].value.as < const IR::Type* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3059 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 21: // multiplicative_expression: cast_expression
#line 381 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3065 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 22: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 382 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                        { yylhs.value.as < IR::Expression* > () = new IR::Mul(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3071 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 23: // multiplicative_expression: multiplicative_expression "/" cast_expression
#line 383 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                        { yylhs.value.as < IR::Expression* > () = new IR::Div(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3077 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 24: // multiplicative_expression: multiplicative_expression "%" cast_expression
#line 384 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                        { yylhs.value.as < IR::Expression* > () = new IR::Mod(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3083 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 25: // additive_expression: multiplicative_expression
#line 388 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3089 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 26: // additive_expression: additive_expression "+" multiplicative_expression
#line 390 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                            { yylhs.value.as < IR::Expression* > () = new IR::Add(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3095 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 27: // additive_expression: additive_expression "-" multiplicative_expression
#line 391 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                            { yylhs.value.as < IR::Expression* > () = new IR::Sub(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3101 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 28: // shift_expression: additive_expression
#line 395 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3107 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 29: // shift_expression: shift_expression "<<" additive_expression
#line 396 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                       { yylhs.value.as < IR::Expression* > () = new IR::Shl(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3113 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 30: // shift_expression: shift_expression ">>" additive_expression
#line 397 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                        { yylhs.value.as < IR::Expression* > () = new IR::Shr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3119 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 31: // relational_expression: shift_expression
#line 401 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                           { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3125 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 32: // relational_expression: relational_expression "<" shift_expression
#line 402 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                     { yylhs.value.as < IR::Expression* > () = new IR::Lss(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3131 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 33: // relational_expression: relational_expression ">" shift_expression
#line 403 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      { yylhs.value.as < IR::Expression* > () = new IR::Grt(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3137 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 34: // relational_expression: relational_expression "<=" shift_expression
#line 404 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      { yylhs.value.as < IR::Expression* > () = new IR::Leq(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3143 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 35: // relational_expression: relational_expression ">=" shift_expression
#line 405 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      { yylhs.value.as < IR::Expression* > () = new IR::Geq(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3149 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 36: // equality_expression: relational_expression
#line 409 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3155 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 37: // equality_expression: equality_expression "==" relational_expression
#line 410 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                           { yylhs.value.as < IR::Expression* > () = new IR::Equ(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3161 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 38: // equality_expression: equality_expression "!=" relational_expression
#line 411 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                           { yylhs.value.as < IR::Expression* > () = new IR::Neq(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3167 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 39: // and_expression: equality_expression
#line 415 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                              { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3173 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 40: // and_expression: and_expression "&" equality_expression
#line 416 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                 { yylhs.value.as < IR::Expression* > () = new IR::BAnd(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3179 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 41: // exclusive_or_expression: and_expression
#line 420 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3185 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 42: // exclusive_or_expression: exclusive_or_expression "^" and_expression
#line 421 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                     { yylhs.value.as < IR::Expression* > () = new IR::BXor(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3191 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 43: // inclusive_or_expression: exclusive_or_expression
#line 425 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3197 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 44: // inclusive_or_expression: inclusive_or_expression "|" exclusive_or_expression
#line 426 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                              { yylhs.value.as < IR::Expression* > () = new IR::BOr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3203 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 45: // logical_and_expression: inclusive_or_expression
#line 430 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3209 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 46: // logical_and_expression: logical_and_expression "&&" inclusive_or_expression
#line 431 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                { yylhs.value.as < IR::Expression* > () = new IR::LAnd(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3215 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 47: // logical_or_expression: logical_and_expression
#line 435 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3221 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 48: // logical_or_expression: logical_or_expression "||" logical_and_expression
#line 436 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                             { yylhs.value.as < IR::Expression* > () = new IR::LOr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3227 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 49: // conditional_expression: logical_or_expression
#line 440 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3233 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 50: // conditional_expression: logical_or_expression "?" expression ":" conditional_expression
#line 441 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                          { yylhs.value.as < IR::Expression* > () = new IR::Mux(yystack_[3].location, yystack_[4].value.as < IR::Expression* > (), yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3239 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 51: // expression: conditional_expression
#line 445 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3245 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 52: // expression: expression "++"
#line 447 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          {
                yylhs.value.as < IR::Expression* > () = new IR::P5PostIncrement(yystack_[1].location + yystack_[0].location, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3253 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 53: // expression: "." field_ref "=" expression
#line 452 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                yylhs.value.as < IR::Expression* > () = new IR::P5DesignatedInitializer(yystack_[3].location + yystack_[0].location, /*isMember=*/true, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
        }
#line 3261 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 54: // expression_list: expression
#line 462 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     { auto v = new IR::Vector<IR::Expression>();
                       v->push_back(yystack_[0].value.as < IR::Expression* > ());
                       yylhs.value.as < IR::Vector<IR::Expression>* > () = v; }
#line 3269 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 55: // expression_list: expression_list "," expression
#line 465 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yystack_[2].value.as < IR::Vector<IR::Expression>* > ()->push_back(yystack_[0].value.as < IR::Expression* > ());
                                           yylhs.value.as < IR::Vector<IR::Expression>* > () = yystack_[2].value.as < IR::Vector<IR::Expression>* > (); }
#line 3276 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 56: // annotation: "@" ID
#line 476 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   {
                // 无参数：生成一个空的、已结构化的表达式列表
                IR::Vector<IR::Expression> args;
                yylhs.value.as < IR::Annotation* > () = new IR::Annotation(yystack_[1].location + yystack_[0].location, *yystack_[0].value.as < IR::ID* > (), args, /*structured=*/true);
        }
#line 3286 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 57: // annotation: "@" ID "(" expression_list ")"
#line 482 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         {
                // expression_list: IR::Vector<IR::Expression>*
                yylhs.value.as < IR::Annotation* > () = new IR::Annotation(yystack_[4].location + yystack_[0].location, *yystack_[3].value.as < IR::ID* > (), *yystack_[1].value.as < IR::Vector<IR::Expression>* > (), /*structured=*/true);
        }
#line 3295 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 58: // annotations: %empty
#line 489 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::Vector<IR::Annotation>* > () = new IR::Vector<IR::Annotation>();
        }
#line 3303 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 59: // annotations: annotations annotation
#line 492 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 {
                yylhs.value.as < IR::Vector<IR::Annotation>* > () = yystack_[1].value.as < IR::Vector<IR::Annotation>* > ();
                if (yystack_[0].value.as < IR::Annotation* > () != nullptr) {
                        yylhs.value.as < IR::Vector<IR::Annotation>* > ()->push_back(yystack_[0].value.as < IR::Annotation* > ());
                        yylhs.value.as < IR::Vector<IR::Annotation>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
                }
        }
#line 3315 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 60: // type_ref: UINT "<" postfix_expression ">"
#line 506 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                          {
                auto expr = yystack_[1].value.as < IR::Expression* > ();
                if (auto c = expr->to<IR::Constant>()) {
                    yylhs.value.as < const IR::Type* > () = IR::Type_Bits::get(c->asInt(), false);
                } else {
                    yylhs.value.as < const IR::Type* > () = IR::Type_Bits::get(yystack_[3].location, expr, false);
                }
        }
#line 3328 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 61: // type_ref: INT "<" postfix_expression ">"
#line 514 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                          {
                auto expr = yystack_[1].value.as < IR::Expression* > ();
                if (auto c = expr->to<IR::Constant>()) {
                    yylhs.value.as < const IR::Type* > () = IR::Type_Bits::get(c->asInt(), true);
                } else {
                    yylhs.value.as < const IR::Type* > () = IR::Type_Bits::get(yystack_[3].location, expr, true);
                }
        }
#line 3341 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 62: // type_ref: struct_union_type_declaration
#line 522 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                yylhs.value.as < const IR::Type* > () = yystack_[0].value.as < IR::Type_Struct* > ();
        }
#line 3349 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 63: // type_ref: ID
#line 525 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
             {
                auto path = new IR::Path(yystack_[0].location, *yystack_[0].value.as < IR::ID* > ());
                yylhs.value.as < const IR::Type* > () = new IR::Type_Name(yystack_[0].location, path);
        }
#line 3358 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 64: // type_ref: ID "::" ID
#line 529 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     {
                auto p = new IR::Path(yystack_[2].location, *yystack_[2].value.as < IR::ID* > () + "::" + *yystack_[0].value.as < IR::ID* > ());
                yylhs.value.as < const IR::Type* > () = new IR::Type_Name(yystack_[2].location, p);
        }
#line 3367 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 65: // type_ref: ID "<" ID ">"
#line 533 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                        {
                auto p = new IR::Path(yystack_[3].location, *yystack_[3].value.as < IR::ID* > () + "<" + *yystack_[1].value.as < IR::ID* > () + ">");
                yylhs.value.as < const IR::Type* > () = new IR::Type_Name(yystack_[3].location, p);
        }
#line 3376 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 66: // type_ref: ID "<" ID "::" ID ">"
#line 537 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                {
                auto p = new IR::Path(yystack_[5].location, *yystack_[5].value.as < IR::ID* > () + "<" + *yystack_[3].value.as < IR::ID* > () + "::" + *yystack_[1].value.as < IR::ID* > () + ">");
                yylhs.value.as < const IR::Type* > () = new IR::Type_Name(yystack_[5].location, p);
        }
#line 3385 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 67: // type_ref: VOID
#line 541 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
               {
                yylhs.value.as < const IR::Type* > () = IR::Type_Void::get();
        }
#line 3393 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 68: // field_ref_no_slice: ID
#line 546 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
             { auto path = new IR::Path(yystack_[0].location, *yystack_[0].value.as < IR::ID* > ());
               yylhs.value.as < IR::Expression* > () = new IR::PathExpression(yystack_[0].location, path); }
#line 3400 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 69: // field_ref_no_slice: field_ref "." ID
#line 548 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                           { yylhs.value.as < IR::Expression* > () = new IR::Member(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), *yystack_[0].value.as < IR::ID* > ()); }
#line 3406 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 70: // field_ref_no_slice: field_ref "[" expression "]"
#line 549 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       { yylhs.value.as < IR::Expression* > () = new IR::ArrayIndex(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3412 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 71: // field_ref_no_slice: field_ref "[" "]"
#line 550 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            { yylhs.value.as < IR::Expression* > () = new IR::ArrayIndex(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), new IR::DefaultExpression(yystack_[1].location)); }
#line 3418 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 72: // field_ref_no_slice: ID "::" field_ref
#line 551 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            { auto path = new IR::Path(yystack_[2].location, *yystack_[2].value.as < IR::ID* > ());
                              auto base = new IR::PathExpression(yystack_[2].location, path);
                              yylhs.value.as < IR::Expression* > () = new IR::Member(yystack_[1].location, base, yystack_[0].value.as < IR::Expression* > ()->toString()); }
#line 3426 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 73: // field_ref: field_ref_no_slice
#line 556 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                             { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3432 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 74: // field_ref: field_ref "[" expression ":" expression "]"
#line 557 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      { yylhs.value.as < IR::Expression* > () = new IR::Slice(yystack_[4].location, yystack_[5].value.as < IR::Expression* > (), yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3438 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 75: // field_ref: "[" expression ":" expression "]"
#line 558 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            { yylhs.value.as < IR::Expression* > () = new IR::Slice(yystack_[4].location, nullptr, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3444 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 76: // field_dec: annotations type_ref ID ";"
#line 561 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                auto field = new IR::StructField(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), yystack_[2].value.as < const IR::Type* > ());
                if (yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3456 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 77: // field_dec: annotations type_ref ID "=" expression ";"
#line 568 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      {
                // 只能忽略初始化值，或者记录表达式用于后续处理
                auto field = new IR::StructField(yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), yystack_[4].value.as < const IR::Type* > ());
                if (yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3469 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 78: // field_dec: annotations type_ref ID "[" expression "]" ";"
#line 576 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                         {
                auto arrayType = new IR::Type_Stack(yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::Expression* > ());
                auto field = new IR::StructField(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), arrayType);
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3482 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 79: // field_dec: annotations type_ref ID "[" expression "]" "[" expression "]" ";"
#line 584 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                            {
                auto innerArray = new IR::Type_Stack(yystack_[8].value.as < const IR::Type* > (), yystack_[5].value.as < IR::Expression* > ());
                auto outerArray = new IR::Type_Stack(innerArray, yystack_[2].value.as < IR::Expression* > ());
                auto field = new IR::StructField(yystack_[7].location, *yystack_[7].value.as < IR::ID* > (), outerArray);
                if (yystack_[9].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[9].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3496 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 80: // anonymous_struct_union_dec: annotations STRUCT "{" struct_field_list "}" ";"
#line 596 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[4].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[2].value.as < IR::IndexedVector<IR::StructField>* > ());
                if (yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[4].location, anonName, type);
        }
#line 3509 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 81: // anonymous_struct_union_dec: annotations STRUCT ID "{" struct_field_list "}" ";"
#line 605 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[5].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[2].value.as < IR::IndexedVector<IR::StructField>* > ());
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), type);
        }
#line 3522 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 82: // anonymous_struct_union_dec: annotations STRUCT "{" struct_field_list "}" ID ";"
#line 614 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[5].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[3].value.as < IR::IndexedVector<IR::StructField>* > ());
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), type);
        }
#line 3535 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 83: // anonymous_struct_union_dec: annotations UNION "{" struct_field_list "}" ";"
#line 623 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 3550 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 84: // anonymous_struct_union_dec: annotations UNION ID "{" struct_field_list "}" ";"
#line 634 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[5].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[2].value.as < IR::IndexedVector<IR::StructField>* > ());
                type->annotations.push_back(new IR::Annotation("union", {}));
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), type);
        }
#line 3564 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 85: // anonymous_struct_union_dec: annotations UNION "{" struct_field_list "}" ID ";"
#line 644 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[5].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[3].value.as < IR::IndexedVector<IR::StructField>* > ());
                type->annotations.push_back(new IR::Annotation("union", {}));
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), type);
        }
#line 3578 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 86: // struct_field_dec: field_dec
#line 655 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                    { yylhs.value.as < IR::StructField* > () = yystack_[0].value.as < IR::StructField* > (); }
#line 3584 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 87: // struct_field_dec: anonymous_struct_union_dec
#line 656 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                     { yylhs.value.as < IR::StructField* > () = yystack_[0].value.as < IR::StructField* > (); }
#line 3590 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 88: // struct_field_list: struct_field_dec
#line 661 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto vec = new IR::IndexedVector<IR::StructField>();
                vec->push_back(yystack_[0].value.as < IR::StructField* > ());
                yylhs.value.as < IR::IndexedVector<IR::StructField>* > () = vec;
        }
#line 3600 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 89: // struct_field_list: struct_field_list struct_field_dec
#line 667 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ()->push_back(yystack_[0].value.as < IR::StructField* > ());
                yylhs.value.as < IR::IndexedVector<IR::StructField>* > () = yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ();
        }
#line 3609 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 90: // constant_declaration: CONST type_ref ID "=" expression ";"
#line 681 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Declaration_Constant* > () = new IR::Declaration_Constant(yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), yystack_[4].value.as < const IR::Type* > (), yystack_[1].value.as < IR::Expression* > ());
        }
#line 3617 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 91: // constant_declaration: CONST type_ref ID "[" expression "]" "=" expression ";"
#line 685 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto type = new IR::Type_Stack(yystack_[7].location, yystack_[7].value.as < const IR::Type* > (), yystack_[4].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Declaration_Constant* > () = new IR::Declaration_Constant(yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3626 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 92: // constant_declaration: CONST type_ref ID '[' expression ']' '[' expression ']' '=' expression ';'
#line 690 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto innerType = new IR::Type_Stack(yystack_[10].location, yystack_[10].value.as < const IR::Type* > (), yystack_[7].value.as < IR::Expression* > ());
                auto type = new IR::Type_Stack(yystack_[10].location, innerType, yystack_[4].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Declaration_Constant* > () = new IR::Declaration_Constant(yystack_[9].location, *yystack_[9].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3636 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 93: // header_declaration: HEADER type_ref ID ";"
#line 697 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 {
                auto args = new IR::Vector<IR::Argument>();
                yylhs.value.as < IR::Declaration* > () = new IR::Declaration_Instance(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), yystack_[2].value.as < const IR::Type* > (), args);
        }
#line 3645 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 94: // header_declaration: HEADER type_ref ID "[" expression "]" ";"
#line 701 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   {
                auto type = new IR::Type_Stack(yystack_[5].location, yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Declaration* > () = new IR::Declaration_Instance(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), type, new IR::Vector<IR::Argument>());
        }
#line 3654 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 95: // variable_declaration: type_ref ID ";"
#line 707 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          { yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), yystack_[2].value.as < const IR::Type* > (), nullptr); }
#line 3660 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 96: // variable_declaration: type_ref ID "=" expression ";"
#line 708 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), yystack_[4].value.as < const IR::Type* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3666 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 97: // variable_declaration: type_ref ID "[" expression "]" ";"
#line 709 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                             {
            auto type = new IR::Type_Stack(yystack_[5].location, yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), type, nullptr);
        }
#line 3675 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 98: // variable_declaration: type_ref ID "[" expression "]" "=" expression ";"
#line 713 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                            {
            auto type = new IR::Type_Stack(yystack_[7].location, yystack_[7].value.as < const IR::Type* > (), yystack_[4].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3684 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 99: // variable_declaration: type_ref ID "[" expression "]" "[" expression "]" ";"
#line 717 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                {
            auto innerType = new IR::Type_Stack(yystack_[8].location, yystack_[8].value.as < const IR::Type* > (), yystack_[5].value.as < IR::Expression* > ());
            auto type = new IR::Type_Stack(yystack_[8].location, innerType, yystack_[2].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[7].location, *yystack_[7].value.as < IR::ID* > (), type, nullptr);
        }
#line 3694 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 100: // variable_declaration: type_ref ID "[" expression "]" "[" expression "]" "=" expression ";"
#line 722 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                               {
            auto innerType = new IR::Type_Stack(yystack_[10].location, yystack_[10].value.as < const IR::Type* > (), yystack_[7].value.as < IR::Expression* > ());
            auto type = new IR::Type_Stack(yystack_[10].location, innerType, yystack_[4].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[9].location, *yystack_[9].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3704 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 101: // variable_declaration: USING NAMESPACE ID ";"
#line 727 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::Declaration_Variable* > () = nullptr; /* TODO: maybe handle 'using namespace' */ }
#line 3710 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 102: // return_value_type: ID "(" arg_list ")" ";"
#line 736 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  {
                auto pe = new IR::PathExpression(*yystack_[4].value.as < IR::ID* > ());
                auto mc = new IR::MethodCallExpression(yystack_[4].location, pe,
                                                 new IR::Vector<IR::Type>(), yystack_[2].value.as < IR::Vector<IR::Argument>* > ());
                yylhs.value.as < IR::Statement* > () = new IR::ReturnStatement(yystack_[4].location + yystack_[1].location, mc);
        }
#line 3721 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 103: // return_value_type: "{" return_value_type_list "}"
#line 742 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Statement* > () = yystack_[1].value.as < IR::BlockStatement* > (); }
#line 3727 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 104: // return_value_type: ID ";"
#line 743 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                auto pe = new IR::PathExpression(*yystack_[1].value.as < IR::ID* > ());
                yylhs.value.as < IR::Statement* > () = new IR::ReturnStatement(yystack_[1].location + yystack_[0].location, pe);
        }
#line 3736 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 105: // return_value_type_list: %empty
#line 749 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yylhs.location);
        }
#line 3744 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 106: // return_value_type_list: return_value_type_list return_value_type
#line 752 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   {
                yystack_[1].value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::Statement* > ());
                yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 3753 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 107: // value_masked_or_set: expression
#line 758 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3759 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 108: // value_masked_or_set: expression "&&&" expression
#line 759 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      { yylhs.value.as < IR::Expression* > () = new IR::Mask(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3765 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 109: // value_list: value_masked_or_set
#line 763 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto vec = new IR::Vector<IR::Expression>();
                vec->push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Vector<IR::Expression>* > () = vec;
        }
#line 3775 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 110: // value_list: value_list "," value_masked_or_set
#line 769 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[2].value.as < IR::Vector<IR::Expression>* > ()->push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Vector<IR::Expression>* > () = yystack_[2].value.as < IR::Vector<IR::Expression>* > ();
        }
#line 3784 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 111: // case_entry: CASE value_list ":" return_value_type
#line 776 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 3799 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 112: // case_entry: CASE value_list ":"
#line 787 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                // Empty case body (fallthrough): "case ...:" with nothing after ':'
                IR::Expression* le =  new IR::ListExpression(yystack_[2].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ());
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, le, nullptr);
        }
#line 3809 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 113: // case_entry: DEFAULT ":" return_value_type
#line 793 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 3824 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 114: // case_entry: DEFAULT ":"
#line 804 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                // Empty default body (fallthrough).
                auto label = new IR::DefaultExpression(yystack_[1].location);
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[1].location, label, nullptr);
        }
#line 3834 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 115: // case_list: case_entry
#line 811 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = new IR::Vector<IR::SwitchCase>();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[0].location;
        }
#line 3844 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 116: // case_list: case_list case_entry
#line 816 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                               {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
        }
#line 3854 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 117: // field_ref_or_func: field_ref
#line 823 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                    {
                yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > ();
        }
#line 3862 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 118: // field_ref_or_func: ID "(" arg_list ")"
#line 826 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                              {
                auto path   = new IR::Path(yystack_[3].location, *yystack_[3].value.as < IR::ID* > ());
                auto callee = new IR::PathExpression(yystack_[3].location, path);
                yylhs.value.as < IR::Expression* > () = new IR::MethodCallExpression(yystack_[2].location, callee, yystack_[1].value.as < IR::Vector<IR::Argument>* > ());
        }
#line 3872 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 119: // select_exp: annotations field_ref_or_func
#line 833 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                auto vec = new IR::Vector<IR::Expression>();
                // Ignore annotations for select list entries.
                vec->push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::ListExpression* > () = new IR::ListExpression(yystack_[1].location, *vec);
        }
#line 3883 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 120: // select_exp: select_exp "," annotations field_ref_or_func
#line 839 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                       {
                // Ignore annotations for select list entries.
                yystack_[3].value.as < IR::ListExpression* > ()->components.push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::ListExpression* > () = yystack_[3].value.as < IR::ListExpression* > ();
        }
#line 3893 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 121: // return_select_statement: SWITCH "(" select_exp ")" "{" case_list "}"
#line 846 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      {
                yylhs.value.as < IR::Statement* > () = new IR::SwitchStatement(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 3901 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 122: // return_select_statement: SWITCH "(" ")" "{" case_list "}"
#line 849 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                yylhs.value.as < IR::Statement* > () = new IR::SwitchStatement(yystack_[5].location, nullptr, *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 3909 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 123: // return_statement: RETURN return_select_statement
#line 854 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Statement* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 3915 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 124: // return_statement: RETURN return_value_type
#line 855 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   { yylhs.value.as < IR::Statement* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 3921 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 125: // break_statement: BREAK ";"
#line 858 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                    { yylhs.value.as < IR::Statement* > () = new IR::BreakStatement(yystack_[1].location); }
#line 3927 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 126: // parameter: annotations type_ref ID
#line 866 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  {
                auto param = new IR::Parameter(yystack_[0].location, *yystack_[0].value.as < IR::ID* > (), IR::Direction::In, yystack_[1].value.as < const IR::Type* > ());
                if (yystack_[2].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[2].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 3939 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 127: // parameter: annotations type_ref ID "=" expression
#line 873 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                 {
                auto param = new IR::Parameter(yystack_[2].location, *yystack_[2].value.as < IR::ID* > (), IR::Direction::In, yystack_[3].value.as < const IR::Type* > (), yystack_[0].value.as < IR::Expression* > ());
                if (yystack_[4].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[4].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 3951 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 128: // parameter: annotations type_ref "&" ID
#line 880 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      {
                auto param = new IR::Parameter(yystack_[0].location, *yystack_[0].value.as < IR::ID* > (), IR::Direction::InOut, yystack_[2].value.as < const IR::Type* > ());
                if (yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 3963 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 129: // parameter: annotations type_ref "&" ID "=" expression
#line 887 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                     {
                auto param = new IR::Parameter(yystack_[2].location, *yystack_[2].value.as < IR::ID* > (), IR::Direction::InOut, yystack_[4].value.as < const IR::Type* > (), yystack_[0].value.as < IR::Expression* > ());
                if (yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 3975 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 130: // parameter: annotations type_ref "&" ID "[" "]"
#line 894 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 3990 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 131: // parameter: annotations type_ref ID "[" "]"
#line 904 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4005 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 132: // param_list: %empty
#line 916 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::ParameterList* > () = new IR::ParameterList(); }
#line 4011 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 133: // param_list: parameter
#line 918 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto pl = new IR::ParameterList(); pl->push_back(yystack_[0].value.as < IR::Parameter* > ());
                yylhs.value.as < IR::ParameterList* > () = pl;
        }
#line 4020 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 134: // param_list: param_list "," parameter
#line 923 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[2].value.as < IR::ParameterList* > ()->push_back(yystack_[0].value.as < IR::Parameter* > ());
                yylhs.value.as < IR::ParameterList* > () = yystack_[2].value.as < IR::ParameterList* > ();
        }
#line 4029 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 135: // arg: expression
#line 930 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     { yylhs.value.as < IR::Argument* > () = new IR::Argument(yystack_[0].location, yystack_[0].value.as < IR::Expression* > ()); }
#line 4035 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 136: // arg_list: %empty
#line 933 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::Vector<IR::Argument>* > () = new IR::Vector<IR::Argument>(); }
#line 4041 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 137: // arg_list: arg
#line 935 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto v = new IR::Vector<IR::Argument>();
                v->push_back(yystack_[0].value.as < IR::Argument* > ());
                yylhs.value.as < IR::Vector<IR::Argument>* > () = v;
        }
#line 4051 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 138: // arg_list: arg_list "," arg
#line 941 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[2].value.as < IR::Vector<IR::Argument>* > ()->push_back(yystack_[0].value.as < IR::Argument* > ());
                yylhs.value.as < IR::Vector<IR::Argument>* > () = yystack_[2].value.as < IR::Vector<IR::Argument>* > ();
        }
#line 4060 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 139: // do_while_statement: DO action_statement WHILE "(" expression ")"
#line 949 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4077 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 140: // conditional_statement: IF "(" expression ")" action_statement
#line 964 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                   {
                IR::IndexedVector<IR::StatOrDecl> as;
                as.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto bs = new IR::BlockStatement(yystack_[0].location, as);
                yylhs.value.as < IR::Statement* > () = new IR::IfStatement(yystack_[4].location, yystack_[2].value.as < IR::Expression* > (), bs, nullptr);
        }
#line 4088 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 141: // conditional_statement: IF "(" expression ")" action_statement ELSE action_statement
#line 970 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                                   {
                IR::IndexedVector<IR::StatOrDecl> as0;
                as0.push_back(yystack_[2].value.as < IR::StatOrDecl* > ());
                auto bs0 = new IR::BlockStatement(yystack_[2].location, as0);
                IR::IndexedVector<IR::StatOrDecl> as1;
                as1.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto bs1 = new IR::BlockStatement(yystack_[0].location, as1);
                yylhs.value.as < IR::Statement* > () = new IR::IfStatement(yystack_[6].location, yystack_[4].value.as < IR::Expression* > (), bs0, bs1);
        }
#line 4102 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 142: // for_loop_statement: FOR "(" parameter ";" expression ";" assignment_or_call ")" action_statement
#line 982 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                IR::IndexedVector<IR::StatOrDecl> init;
                init.push_back(yystack_[6].value.as < IR::Parameter* > ());   // parameter 本身就是 IR::Parameter/Declaration

                IR::IndexedVector<IR::StatOrDecl> iter;
                iter.push_back(yystack_[2].value.as < IR::Statement* > ());   // assignment_or_call -> IR::Statement

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
#line 4126 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 143: // for_loop_statement: FOR "(" parameter ":" expression ")" action_statement
#line 1002 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto param = yystack_[4].value.as < IR::Parameter* > ();
                auto bound = yystack_[2].value.as < IR::Expression* > ();

                // 1. Initialize param to 0 if it doesn't have a default value
                if (param->defaultValue == nullptr) {
                    param->defaultValue = new IR::Constant(param->type, 0);
                }

                IR::IndexedVector<IR::StatOrDecl> init;
                init.push_back(param);

                // 2. Condition: param < bound
                auto param_ref = new IR::PathExpression(param->srcInfo, new IR::Path(param->name));
                auto cond = new IR::Lss(yystack_[3].location, param_ref, bound);

                // 3. Update: param = param + 1
                auto one = new IR::Constant(param->type, 1);
                auto add = new IR::Add(yystack_[3].location, param_ref->clone(), one);
                auto update = new IR::AssignmentStatement(yystack_[3].location, param_ref->clone(), add);
                IR::IndexedVector<IR::StatOrDecl> updates;
                updates.push_back(update);

                // 4. Body
                IR::IndexedVector<IR::StatOrDecl> as_vec;
                as_vec.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto as = new IR::BlockStatement(yystack_[0].location, as_vec);

                yylhs.value.as < IR::Statement* > () = new IR::ForStatement(
                        yystack_[6].location,
                        init,
                        cond,
                        updates,
                        as
                );
        }
#line 4167 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 144: // case: CASE value_list ":" action_statement
#line 1040 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                IR::Expression* vl = new IR::ListExpression(yystack_[3].location, *yystack_[2].value.as < IR::Vector<IR::Expression>* > ());

                IR::IndexedVector<IR::StatOrDecl> as_vec;
                as_vec.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto as = new IR::BlockStatement(yystack_[0].location, as_vec);

                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[3].location, vl, as);
        }
#line 4181 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 145: // case: CASE value_list ":"
#line 1050 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                // Empty case body (fallthrough).
                IR::Expression* vl = new IR::ListExpression(yystack_[2].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ());
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, vl, nullptr);
        }
#line 4191 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 146: // case: DEFAULT ":" action_statement
#line 1055 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                IR::IndexedVector<IR::StatOrDecl> as_vec;
                as_vec.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto as = new IR::BlockStatement(yystack_[0].location, as_vec);

                auto label = new IR::DefaultExpression(yystack_[2].location);

                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, label, as);
        }
#line 4205 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 147: // case: DEFAULT ":"
#line 1064 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                      {
                // Empty default body (fallthrough).
                auto label = new IR::DefaultExpression(yystack_[1].location);
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[1].location, label, nullptr);
        }
#line 4215 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 148: // switch_cases: %empty
#line 1071 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = new IR::Vector<IR::SwitchCase>; }
#line 4221 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 149: // switch_cases: switch_cases case
#line 1072 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            {
                yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ();
        }
#line 4230 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 150: // switch_statement: SWITCH "(" select_exp ")" "{" switch_cases "}"
#line 1078 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                         {
                yylhs.value.as < IR::Statement* > () = new IR::SwitchStatement(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 4238 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 151: // switch_statement: SWITCH "(" ")" "{" switch_cases "}"
#line 1081 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                              {
                yylhs.value.as < IR::Statement* > () = new IR::SwitchStatement(yystack_[5].location, nullptr, *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 4246 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 152: // assignment_or_call: field_ref_or_func
#line 1086 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            {
                if (auto mc = yystack_[0].value.as < IR::Expression* > ()->to<IR::MethodCallExpression>()) {
                        yylhs.value.as < IR::Statement* > () = new IR::MethodCallStatement(yystack_[0].location, mc);
                } else {
                        yylhs.value.as < IR::Statement* > () = new IR::EmptyStatement(yystack_[0].location);
                }
        }
#line 4258 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 153: // assignment_or_call: field_ref "=" expression
#line 1093 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   {
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
        }
#line 4266 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 154: // assignment_or_call: field_ref "-=" expression
#line 1096 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto sub = new IR::Sub(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), sub);
        }
#line 4275 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 155: // assignment_or_call: field_ref "+=" expression
#line 1100 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto sub = new IR::Sub(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), sub);
        }
#line 4284 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 156: // assignment_or_call: field_ref "*=" expression
#line 1104 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto mul = new IR::Mul(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), mul);
        }
#line 4293 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 157: // assignment_or_call: field_ref "/=" expression
#line 1108 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto div = new IR::Div(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), div);
        }
#line 4302 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 158: // assignment_or_call: field_ref "%=" expression
#line 1112 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto mod = new IR::Mod(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), mod);
        }
#line 4311 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 159: // assignment_or_call: field_ref "|=" expression
#line 1116 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto bor = new IR::BOr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), bor);
        }
#line 4320 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 160: // assignment_or_call: field_ref "^=" expression
#line 1120 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto bxor = new IR::BXor(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), bxor);
        }
#line 4329 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 161: // assignment_or_call: field_ref "<<=" expression
#line 1124 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                     {
                auto shl = new IR::Shl(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), shl);
        }
#line 4338 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 162: // assignment_or_call: field_ref ">>=" expression
#line 1128 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                     {
                auto shr = new IR::Shr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), shr);
        }
#line 4347 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 163: // assignment_or_call: field_ref "++"
#line 1132 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         {
                auto one = new IR::Constant(IR::Type_Bits::get(32), 1);
                auto add = new IR::Add(yystack_[0].location, yystack_[1].value.as < IR::Expression* > (), one);
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[0].location, yystack_[1].value.as < IR::Expression* > (), add);
        }
#line 4357 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 164: // assignment_or_call: field_ref "--"
#line 1137 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         {
                auto one = new IR::Constant(IR::Type_Bits::get(32), 1);
                auto sub = new IR::Sub(yystack_[0].location, yystack_[1].value.as < IR::Expression* > (), one);
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[0].location, yystack_[1].value.as < IR::Expression* > (), sub);
        }
#line 4367 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 165: // assignment_or_call_statement: assignment_or_call ";"
#line 1144 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::Statement* > () = yystack_[1].value.as < IR::Statement* > (); }
#line 4373 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 166: // action_statement: annotations variable_declaration
#line 1147 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Variable* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Variable* > ();
        }
#line 4382 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 167: // action_statement: annotations constant_declaration
#line 1151 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Constant* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Constant* > ();
        }
#line 4391 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 168: // action_statement: annotations action_compound_statement
#line 1155 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                {
                attachAnnotations(yystack_[0].value.as < IR::BlockStatement* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::BlockStatement* > ();
        }
#line 4400 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 169: // action_statement: annotations conditional_statement
#line 1159 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4406 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 170: // action_statement: annotations switch_statement
#line 1160 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4412 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 171: // action_statement: annotations do_while_statement
#line 1161 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4418 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 172: // action_statement: annotations for_loop_statement
#line 1162 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4424 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 173: // action_statement: annotations return_statement
#line 1163 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4430 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 174: // action_statement: annotations break_statement
#line 1164 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4436 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 175: // action_statement: annotations assignment_or_call_statement
#line 1165 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4442 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 176: // action_statement: annotations ";"
#line 1166 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          {
            yylhs.value.as < IR::StatOrDecl* > () = new IR::EmptyStatement(yylhs.location);
        }
#line 4450 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 177: // action_statement_list: %empty
#line 1172 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yylhs.location); }
#line 4456 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 178: // action_statement_list: action_statement_list action_statement
#line 1173 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                 {
              yystack_[1].value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
              yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 4465 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 179: // action_compound_statement: "{" action_statement_list "}"
#line 1179 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > (); }
#line 4471 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 180: // key_element: CONTROL_PARAMETERS "=" "{" action_statement_list "}"
#line 1188 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                               {
                auto ke = new IR::P5KeyElement(yystack_[4].location);
                ke->control = *yystack_[1].value.as < IR::BlockStatement* > ();
                yylhs.value.as < IR::P5KeyElement* > () = ke;
        }
#line 4481 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 181: // key_element: annotations expression ":" ID ";"
#line 1193 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            {
                auto ke = new IR::P5KeyElement(yystack_[4].location);
                ke->annotations = *yystack_[4].value.as < IR::Vector<IR::Annotation>* > ();
                ke->expr = yystack_[3].value.as < IR::Expression* > ();
                ke->matchType = *yystack_[1].value.as < IR::ID* > ();
                yylhs.value.as < IR::P5KeyElement* > () = ke;
        }
#line 4493 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 182: // key_element: annotations expression ";"
#line 1200 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                     {
                auto ke = new IR::P5KeyElement(yystack_[2].location);
                ke->annotations = *yystack_[2].value.as < IR::Vector<IR::Annotation>* > ();
                ke->expr = yystack_[1].value.as < IR::Expression* > ();
                yylhs.value.as < IR::P5KeyElement* > () = ke;
        }
#line 4504 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 183: // key_element_list: %empty
#line 1208 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::Vector<IR::P5KeyElement>* > () = new IR::Vector<IR::P5KeyElement>();
        }
#line 4512 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 184: // key_element_list: key_element_list key_element
#line 1211 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ()->push_back(yystack_[0].value.as < IR::P5KeyElement* > ());
                yylhs.value.as < IR::Vector<IR::P5KeyElement>* > () = yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
        }
#line 4521 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 185: // key_case_entry: annotations CASE value_list ":" "{" key_element_list "}"
#line 1217 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                   {
                auto label = new IR::ListExpression(yystack_[4].location, *yystack_[4].value.as < IR::Vector<IR::Expression>* > ());
                auto kce = new IR::P5KeyCase(yystack_[6].location, false);
                kce->annotations = *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ();
                kce->label = label;
                kce->elements = *yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
                kce->fallthrough = false;
                yylhs.value.as < IR::P5KeyCase* > () = kce;
        }
#line 4535 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 186: // key_case_entry: annotations CASE value_list ":"
#line 1226 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4551 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 187: // key_case_entry: annotations DEFAULT ":" "{" key_element_list "}"
#line 1237 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                           {
                auto label = new IR::DefaultExpression(yystack_[4].location);
                auto kce = new IR::P5KeyCase(yystack_[5].location, false);
                kce->annotations = *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ();
                kce->label = label;
                kce->elements = *yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
                kce->fallthrough = false;
                yylhs.value.as < IR::P5KeyCase* > () = kce;
        }
#line 4565 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 188: // key_case_entry: annotations DEFAULT ":"
#line 1246 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4580 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 189: // key_case_list: key_case_entry
#line 1258 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         {
                auto v = new IR::Vector<IR::P5KeyCase>();
                v->push_back(yystack_[0].value.as < IR::P5KeyCase* > ());
                yylhs.value.as < IR::Vector<IR::P5KeyCase>* > () = v;
        }
#line 4590 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 190: // key_case_list: key_case_list key_case_entry
#line 1263 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                yystack_[1].value.as < IR::Vector<IR::P5KeyCase>* > ()->push_back(yystack_[0].value.as < IR::P5KeyCase* > ());
                yylhs.value.as < IR::Vector<IR::P5KeyCase>* > () = yystack_[1].value.as < IR::Vector<IR::P5KeyCase>* > ();
        }
#line 4599 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 191: // key_switch_entry: SWITCH "(" select_exp ")" "{" key_case_list "}"
#line 1269 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                          {
                // P5KeySwitch is a dedicated IR node so a single key={...} can contain
                // multiple switch blocks in source order.
                yylhs.value.as < IR::P5KeySwitch* > () = new IR::P5KeySwitch(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::P5KeyCase>* > ());
        }
#line 4609 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 192: // key_switch_list: key_switch_entry
#line 1276 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                           {
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > () = new IR::Vector<IR::P5KeySwitch>();
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->push_back(yystack_[0].value.as < IR::P5KeySwitch* > ());
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->srcInfo = yystack_[0].location;
        }
#line 4619 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 193: // key_switch_list: key_switch_entry key_switch_list
#line 1281 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > () = yystack_[0].value.as < IR::Vector<IR::P5KeySwitch>* > ();
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->insert(yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->begin(), yystack_[1].value.as < IR::P5KeySwitch* > ());
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
        }
#line 4629 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 194: // program_selection_statement: constant_declaration
#line 1288 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Constant* > (); }
#line 4635 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 195: // program_selection_statement: variable_declaration
#line 1289 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Variable* > (); }
#line 4641 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 196: // program_selection_statement: assignment_or_call_statement
#line 1290 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4647 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 197: // program_selection_statement_list: %empty
#line 1293 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yylhs.location);
        }
#line 4655 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 198: // program_selection_statement_list: program_selection_statement
#line 1296 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      {
                auto blk = new IR::BlockStatement(yystack_[0].location);
                blk->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                yylhs.value.as < IR::BlockStatement* > () = blk;
        }
#line 4665 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 199: // program_selection_statement_list: program_selection_statement_list program_selection_statement
#line 1301 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                       {
                yystack_[1].value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 4674 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 200: // table_case_entry: annotations CASE value_list ":" "{" program_selection_statement_list "}"
#line 1307 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4689 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 201: // table_case_entry: annotations CASE value_list ":"
#line 1317 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                          {
                // Empty case body (fallthrough).
                IR::Expression* label = new IR::ListExpression(yystack_[1].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ());
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, label, nullptr);
        }
#line 4699 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 202: // table_case_entry: annotations DEFAULT ":" "{" program_selection_statement_list "}"
#line 1322 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4714 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 203: // table_case_entry: annotations DEFAULT ":"
#line 1332 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  {
                // Empty default body (fallthrough).
                IR::Expression* label = new IR::DefaultExpression(yystack_[1].location);
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[1].location, label, nullptr);
        }
#line 4724 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 204: // table_case_list: table_case_entry
#line 1340 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = new IR::Vector<IR::SwitchCase>();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[0].location;
        }
#line 4734 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 205: // table_case_list: table_case_list table_case_entry
#line 1346 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
        }
#line 4744 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 206: // table_property: KEY "=" "{" key_element_list "}"
#line 1353 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                auto key = new IR::P5Key(yystack_[4].location);
                key->elements = *yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
                yylhs.value.as < IR::StatOrDecl* > () = key;
        }
#line 4754 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 207: // table_property: KEY "=" "{" key_switch_list "}"
#line 1358 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                          {
                auto key = new IR::P5Key(yystack_[4].location);
                key->switches = *yystack_[1].value.as < IR::Vector<IR::P5KeySwitch>* > ();
                yylhs.value.as < IR::StatOrDecl* > () = key;
        }
#line 4764 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 208: // table_property: CONTROL_PARAMETERS "=" "{" action_statement_list "}"
#line 1363 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                               {
                // Similar to key_element's CONTROL_PARAMETERS form, but table properties
                // don't wrap this in a P5KeyElement: return the action block directly.
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 4774 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 209: // table_property: SWITCH "(" select_exp ")" "{" table_case_list "}"
#line 1368 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                            {
                yylhs.value.as < IR::StatOrDecl* > () = new IR::SwitchStatement(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 4782 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 210: // table_property: SWITCH "(" ")" "{" table_case_list "}"
#line 1371 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                 {
                yylhs.value.as < IR::StatOrDecl* > () = new IR::SwitchStatement(yystack_[5].location, nullptr, *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 4790 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 211: // table_property: annotations assignment_or_call_statement
#line 1374 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   {
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > ();
        }
#line 4798 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 212: // table_property: annotations constant_declaration
#line 1377 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Constant* > ();
        }
#line 4806 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 213: // table_property: annotations variable_declaration
#line 1380 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Variable* > ();
        }
#line 4814 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 214: // table_property_list: table_property
#line 1386 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         {
                yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yystack_[0].location);
                if (yystack_[0].value.as < IR::StatOrDecl* > ()) yylhs.value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
        }
#line 4823 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 215: // table_property_list: table_property_list table_property
#line 1390 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                             {
                yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
                if (yystack_[0].value.as < IR::StatOrDecl* > ()) yylhs.value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
        }
#line 4832 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 216: // table_declaration: TABLE ID "(" param_list ")" "{" table_property_list "}"
#line 1398 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                  {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[7].location+yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), yystack_[4].value.as < IR::ParameterList* > (), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4840 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 217: // table_declaration: TABLE ID "{" table_property_list "}"
#line 1401 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                               {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[4].location+yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), new IR::ParameterList(), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4848 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 218: // table_declaration: CLASS ID "(" param_list ")" "{" table_property_list "}"
#line 1404 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                  {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[7].location+yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), yystack_[4].value.as < IR::ParameterList* > (), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4856 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 219: // table_declaration: CLASS ID "{" table_property_list "}"
#line 1407 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                               {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[4].location+yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), new IR::ParameterList(), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4864 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 220: // typedef_declaration: TYPEDEF type_ref ID
#line 1420 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto id = IR::ID(yystack_[0].location, *yystack_[0].value.as < IR::ID* > ());
                yylhs.value.as < IR::Type_Typedef* > () = new IR::Type_Typedef(yystack_[2].location, id, yystack_[1].value.as < const IR::Type* > ());
        }
#line 4873 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 221: // enumerator: ID
#line 1427 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < P4::P5::EnumItem* > () = new P4::P5::EnumItem(yystack_[0].location, yystack_[0].value.as < IR::ID* > (), nullptr);
        }
#line 4881 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 222: // enumerator: ID "=" expression
#line 1431 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < P4::P5::EnumItem* > () = new P4::P5::EnumItem(yystack_[2].location + yystack_[0].location, yystack_[2].value.as < IR::ID* > (), yystack_[0].value.as < IR::Expression* > ());
        }
#line 4889 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 223: // enumerator_list: enumerator
#line 1436 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4904 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 224: // enumerator_list: enumerator_list "," enumerator
#line 1446 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4921 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 225: // enum_declaration: ENUM ID "{" enumerator_list "}"
#line 1461 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                const IR::Type* underlying = IR::Type_Bits::get(32, false);
                yylhs.value.as < IR::Type_Declaration* > () = new IR::Type_SerEnum(*yystack_[3].value.as < IR::ID* > (), underlying, *yystack_[1].value.as < IR::IndexedVector<IR::SerEnumMember>* > ());
        }
#line 4930 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 226: // struct_union_type_declaration: STRUCT ID "{" struct_field_list "}"
#line 1468 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Type_Struct* > () = new IR::Type_Struct(yystack_[3].location + yystack_[0].location, *yystack_[3].value.as < IR::ID* > (), *yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ());
        }
#line 4938 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 227: // struct_union_type_declaration: UNION ID "{" struct_field_list "}"
#line 1472 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto st = new IR::Type_Struct(yystack_[3].location + yystack_[0].location, *yystack_[3].value.as < IR::ID* > (), *yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ());
                st->annotations.push_back(new IR::Annotation("union", {}));
                yylhs.value.as < IR::Type_Struct* > () = st;
        }
#line 4948 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 228: // type_declaration: struct_union_type_declaration ";"
#line 1480 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            { yylhs.value.as < IR::Type_Declaration* > () = yystack_[1].value.as < IR::Type_Struct* > (); }
#line 4954 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 229: // type_declaration: enum_declaration ";"
#line 1481 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                               { yylhs.value.as < IR::Type_Declaration* > () = yystack_[1].value.as < IR::Type_Declaration* > (); }
#line 4960 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 230: // type_declaration: typedef_declaration ";"
#line 1482 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   { yylhs.value.as < IR::Type_Declaration* > () = yystack_[1].value.as < IR::Type_Typedef* > (); }
#line 4966 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 231: // function_declaration: type_ref ID "(" param_list ")" action_compound_statement
#line 1486 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring funcName = yystack_[4].value.as < IR::ID* > ()->name;  // ID* -> cstring
                auto funcType = new IR::Type_Method(yystack_[5].location + yystack_[1].location, yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::ParameterList* > (), funcName);
                yylhs.value.as < IR::Function* > () = new IR::Function(yystack_[4].location + yystack_[0].location, funcName, funcType, yystack_[0].value.as < IR::BlockStatement* > ());
        }
#line 4976 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 233: // declaration: annotations constant_declaration
#line 1504 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Constant* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Declaration_Constant* > ();
        }
#line 4985 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 234: // declaration: annotations ";"
#line 1508 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          {
                // Standalone annotation statement (e.g. @u_version(...);).
                // Ignore it completely and keep parsing.
                yylhs.value.as < IR::Node* > () = nullptr;
        }
#line 4995 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 235: // declaration: annotations type_declaration
#line 1514 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Type_Declaration* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Type_Declaration* > ();
        }
#line 5004 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 236: // declaration: annotations header_declaration
#line 1519 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Declaration* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Declaration* > ();
        }
#line 5013 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 237: // declaration: annotations table_declaration
#line 1524 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::P5Table* > ();
        }
#line 5021 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 239: // declaration: annotations variable_declaration
#line 1529 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Variable* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Declaration_Variable* > ();
        }
#line 5030 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 240: // declaration: annotations function_declaration
#line 1534 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Function* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Function* > ();
        }
#line 5039 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 241: // declaration_list: declaration
#line 1541 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Vector<IR::Node>* > () = new IR::IndexedVector<IR::Node>();
                if (yystack_[0].value.as < IR::Node* > ()) yylhs.value.as < IR::Vector<IR::Node>* > ()->push_back(yystack_[0].value.as < IR::Node* > ());
        }
#line 5048 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 242: // declaration_list: declaration_list declaration
#line 1546 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                if (yystack_[0].value.as < IR::Node* > ()) yystack_[1].value.as < IR::Vector<IR::Node>* > ()->push_back(yystack_[0].value.as < IR::Node* > ());
                yylhs.value.as < IR::Vector<IR::Node>* > () = yystack_[1].value.as < IR::Vector<IR::Node>* > ();
        }
#line 5057 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 244: // input: input declaration
#line 1554 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                             {
                if (yystack_[0].value.as < IR::Node* > ()) driver.nodes->push_back(yystack_[0].value.as < IR::Node* > ()->getNode());
        }
#line 5065 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 245: // input: input ";"
#line 1557 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                           {}
#line 5071 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;


#line 5075 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"

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


  const short P5Parser::yypact_ninf_ = -437;

  const short P5Parser::yytable_ninf_ = -148;

  const short
  P5Parser::yypact_[] =
  {
    -437,    57,    44,  -437,  -437,  -437,   578,  -437,    27,  -437,
     425,    27,    27,   125,    27,    27,   425,    27,   141,   131,
    -437,   425,    27,  -437,   254,  -437,    27,  -437,  -437,  -437,
    -437,   248,   262,   282,  -437,  -437,  -437,   381,    27,  -437,
     397,   413,    63,   418,   445,    27,   467,    63,    27,    27,
     528,    27,    27,   378,  -437,  -437,  -437,  -437,   315,    26,
     476,   438,    27,   315,   315,   315,  -437,  -437,  -437,   553,
    -437,  -437,   320,  -437,   579,  -437,  -437,  -437,  -437,   347,
     393,   167,   476,   438,  -437,    79,   476,   315,   315,  -437,
     265,    34,   407,   407,   407,   407,   563,  -437,  -437,   440,
     550,   624,   560,   478,   519,   532,   531,   536,   263,  -437,
     573,   500,   315,   315,   315,   115,  -437,   514,   603,   592,
     597,   170,  -437,    56,   609,  -437,   551,   130,   558,   412,
      34,   315,  -437,    81,    27,  -437,   625,   369,  -437,  -437,
    -437,   633,   642,  -437,  -437,   315,  -437,   516,    90,    27,
    -437,   524,   395,   148,   340,   651,   315,   415,  -437,  -437,
    -437,  -437,   407,   407,   407,   407,   407,   407,   407,   407,
     407,   407,   407,   407,   407,   407,   407,   407,   407,   315,
     407,  -437,  -437,   315,   403,   223,    62,   100,   656,  -437,
     670,   671,   672,    43,    27,   646,  -437,  -437,  -437,   627,
    -437,  -437,  -437,   315,  -437,    27,  -437,  -437,  -437,   315,
     579,   573,  -437,   525,  -437,   453,  -437,  -437,  -437,    21,
      70,    27,  -437,  -437,  -437,   431,   674,  -437,   647,   676,
     164,  -437,    34,   407,   429,   315,  -437,  -437,  -437,   440,
     440,   550,   550,   624,   624,   624,   624,   560,   560,   478,
     519,   532,   531,   482,   536,   573,   666,  -437,   596,    27,
     344,   438,  -437,   679,    22,   526,   615,  -437,   315,   185,
     315,  -437,   315,  -437,   315,   315,   315,   315,   315,   315,
     315,   315,  -437,   573,  -437,   444,  -437,   315,  -437,   315,
    -437,   681,  -437,   682,   295,   637,   438,  -437,  -437,  -437,
     315,   315,  -437,    45,  -437,  -437,   407,   315,   315,   439,
     684,   315,   177,  -437,    99,   579,  -437,   685,  -437,   691,
      61,   615,   690,   692,   530,   573,   573,   573,   573,   573,
     573,   573,   573,   573,   573,  -437,  -437,   461,   693,  -437,
     694,  -437,   315,   315,  -437,  -437,   188,   695,   477,   230,
    -437,   266,    69,   689,   315,  -437,   573,  -437,   152,  -437,
     696,  -437,    22,  -437,  -437,   687,   207,  -437,  -437,  -437,
    -437,   554,  -437,  -437,  -437,   121,   698,   212,   699,   484,
     285,  -437,  -437,   204,  -437,  -437,   617,  -437,   573,   315,
     697,  -437,  -437,   701,  -437,   540,   703,    30,  -437,   658,
    -437,   707,   709,    60,   710,  -437,  -437,  -437,  -437,  -437,
    -437,  -437,  -437,  -437,  -437,  -437,   663,   664,  -437,   665,
     667,   198,  -437,   315,  -437,   315,   313,  -437,   574,   712,
    -437,   714,  -437,    27,  -437,  -437,   645,  -437,   315,  -437,
     718,    87,  -437,  -437,   719,  -437,  -437,  -437,  -437,   315,
    -437,   312,    25,   315,   315,   717,   450,  -437,   721,   673,
     722,   194,   358,    67,   725,   315,  -437,   726,   541,   485,
    -437,  -437,   573,  -437,   450,  -437,  -437,  -437,  -437,   224,
     172,  -437,   724,  -437,  -437,   315,   315,   315,  -437,  -437,
    -437,   727,   542,   544,  -437,   728,   683,   401,  -437,  -437,
     315,   723,  -437,  -437,   383,   391,   321,   677,   564,   730,
     688,   229,  -437,  -437,  -437,   621,   733,  -437,  -437,    34,
    -437,   315,   729,  -437,   247,   564,  -437,  -437,   315,   731,
    -437,   253,   735,  -437,  -437,   738,  -437,   626,    71,  -437,
    -437,   258,   652,   267,  -437,  -437,    77,  -437,    71,  -437,
    -437,   272,  -437,    91,  -437,  -437,  -437,  -437,  -437
  };

  const unsigned char
  P5Parser::yydefact_[] =
  {
     243,     0,    58,     1,     2,   245,     0,   244,     0,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,     0,     4,    63,    59,     0,   233,   236,   239,
     237,     0,     0,    62,   235,   240,    58,    56,     0,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   230,   229,   228,   238,     0,     0,
      58,    58,     0,     0,     0,     0,     3,     5,     8,    68,
       7,    12,     0,    73,     6,    58,    58,   220,    58,     0,
       0,     0,    58,    58,    64,     0,    58,     0,     0,    95,
       0,     0,     0,     0,     0,     0,    14,    19,    21,    25,
      28,    31,    36,    39,    41,    43,    45,    47,    49,    51,
      54,     0,     0,     0,     0,     0,   133,     0,     0,     0,
       0,     0,   214,    58,   221,   223,     0,     0,     0,     0,
       0,   136,    61,     0,     0,   241,    58,     0,    86,    87,
      88,    58,    58,    60,   101,     0,    93,     0,    58,     0,
      65,     0,     0,     0,    68,     0,     0,     0,    18,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    57,     0,     0,     0,     0,     0,     0,    58,
      58,     0,     0,    68,     0,   117,   212,   213,   152,     0,
     211,   219,   215,     0,   225,     0,     9,    11,    10,     0,
      72,   135,   137,     0,    71,     0,    69,   232,   242,     0,
       0,     0,   226,    89,   227,     0,     0,   217,     0,     0,
       0,    96,     0,     0,     0,     0,    22,    23,    24,    26,
      27,    30,    29,    33,    32,    35,    34,    37,    38,    40,
      42,    44,    46,     0,    48,    55,     0,    90,     0,     0,
     126,    58,   134,     0,     0,     0,   183,   177,   136,     0,
       0,   163,     0,   164,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   222,   224,     0,    13,     0,    70,     0,
      58,     0,    58,     0,     0,     0,    58,    66,   177,   231,
       0,     0,    97,    68,    20,    53,     0,     0,     0,   128,
       0,     0,    58,    58,    68,   117,   119,     0,    58,     0,
      58,   192,     0,    58,     0,   153,   155,   154,   156,   157,
     158,   159,   160,   162,   161,    75,   138,     0,    58,    58,
      58,    58,     0,     0,    76,    94,    58,    58,     0,     0,
      50,     0,     0,     0,     0,   131,   127,   218,     0,   204,
      58,    58,     0,    58,   206,     0,     0,   184,   193,   207,
     208,     0,   178,   118,    74,     0,    58,     0,    58,     0,
       0,   216,   179,     0,    98,    91,     0,   130,   129,     0,
       0,   210,   205,    58,   120,     0,     0,     0,   176,     0,
      58,     0,     0,     0,     0,   167,   166,   173,   174,   171,
     169,   172,   170,   175,   168,    80,     0,   226,    83,     0,
     227,     0,    77,     0,    99,     0,   107,   109,     0,   203,
     209,     0,   177,     0,   182,   125,     0,    58,     0,   105,
       0,     0,   124,   123,    58,    82,    81,    85,    84,     0,
      78,     0,     0,     0,     0,   201,   197,    58,    58,     0,
       0,     0,     0,     0,    58,   136,   104,     0,     0,     0,
     100,    92,   108,   110,   197,   194,   195,   196,   198,     0,
       0,   189,    58,   180,   181,     0,     0,     0,    58,   103,
     106,     0,     0,     0,   148,     0,     0,     0,   202,   199,
       0,     0,   191,   190,     0,     0,     0,   140,     0,     0,
       0,     0,   148,    79,   200,     0,   188,   139,    58,     0,
      58,     0,     0,   115,     0,     0,   102,   151,     0,     0,
     149,     0,   186,   183,   143,     0,   141,     0,   114,   122,
     116,     0,     0,    58,   150,   183,    58,    58,   112,   113,
     121,    58,   146,    58,   187,   142,   111,   144,   185
  };

  const short
  P5Parser::yypgoto_[] =
  {
    -437,  -437,  -437,     4,  -437,  -437,   520,  -437,   -55,   456,
     436,   430,   472,   571,   572,   575,   577,   569,  -437,   447,
     305,   686,  -437,    -2,    55,  -437,   -89,  -437,  -437,  -136,
     -77,     1,  -437,     2,  -436,  -437,   297,  -144,  -153,   231,
    -242,  -334,  -437,  -437,  -437,  -185,   474,   470,  -259,  -437,
    -437,  -437,  -437,   249,  -437,   240,  -118,  -387,  -275,   389,
    -437,  -139,   280,  -437,  -437,   442,  -137,   290,  -306,   404,
    -112,   -66,  -437,  -437,   561,  -437,  -437,   761,  -437,  -437,
    -437,   -12,  -437,  -437
  };

  const short
  P5Parser::yydefgoto_[] =
  {
       0,     1,    68,    69,    70,    71,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     426,   111,    25,   137,   194,    73,    74,   138,   139,   140,
     141,   475,    28,   476,   442,   463,   427,   428,   523,   524,
     198,   265,   443,   407,   408,   116,   117,   212,   213,   409,
     410,   411,   530,   511,   412,   199,   477,   372,   323,   299,
     367,   320,   481,   482,   321,   322,   478,   479,   359,   360,
     122,   123,    30,    31,   125,   126,    32,    39,    34,    35,
      36,     7,   136,     2
  };

  const short
  P5Parser::yytable_[] =
  {
       6,   142,   157,   200,   262,   223,   223,    27,    29,   324,
      24,   202,    37,   436,    24,    40,    41,   148,    43,    44,
      24,    46,   316,   347,    57,    24,    50,   490,   290,   395,
      53,   156,   195,     8,     6,   112,   202,   158,   159,   160,
     161,   210,    59,   156,   113,   181,   433,     4,   268,    77,
     181,   -64,    80,    81,   392,    84,    85,     3,   115,   121,
     232,    26,   130,   135,   201,    38,   124,   439,    63,   364,
      64,    45,    65,     6,   439,   489,    49,   292,   439,    52,
     115,   121,   181,   434,   115,   554,    90,   392,    64,   181,
      65,   214,   465,    91,   154,    92,   149,     5,   227,   558,
      93,   507,   549,    94,   268,    23,    23,   236,   237,   238,
     468,    23,   556,    95,   150,   114,   130,   471,    23,    24,
     394,   121,   196,   197,   218,   193,     8,   -63,   118,   -64,
     492,   534,   440,   536,     6,   119,   206,   120,   216,   259,
     466,    24,   365,   210,    23,   155,   121,    23,    66,    67,
     181,    23,   258,   228,    23,    23,   552,   458,   365,   386,
     555,    42,   118,     8,   557,    23,    66,    67,   181,   119,
     187,   120,   365,   300,   415,   315,   145,    47,   304,   156,
      13,     8,   301,     8,    23,   357,    15,   115,   264,    17,
      18,   260,   221,    20,    87,   312,   381,    48,   269,    23,
     202,   231,   223,    88,   223,    23,   493,   449,   389,   124,
     486,   390,    90,   338,    64,   340,    65,   302,     8,    91,
     146,    92,   423,   291,   293,   294,    93,    10,   500,    94,
     346,   501,   498,   156,   202,    13,   303,   527,    89,    95,
     223,    15,   223,   181,    17,    18,    19,   487,    20,   118,
     181,   450,   461,   413,    23,   539,   119,   424,   120,   121,
     118,   544,   376,   309,   378,   418,   550,   119,   314,   120,
      90,    51,    64,   315,    65,  -147,   257,    91,   179,    92,
    -145,    10,   195,   384,    93,   528,   181,    94,   529,    13,
      52,    23,    66,    67,   121,    15,    23,    95,    17,    18,
      19,    54,    20,   521,   342,   181,   522,   180,    23,   528,
     121,   358,   529,   343,   521,    55,   362,   522,   366,   385,
      90,   371,    64,  -147,    65,   131,  -147,    91,  -145,    92,
      13,  -145,   181,   181,    93,    56,    15,    94,   422,    17,
      18,   181,   499,    20,   121,   371,   -63,    95,   344,    23,
      66,    67,   131,   310,   453,   132,   515,   232,   358,   358,
     499,   264,   311,   110,   488,   470,   314,   195,   127,   110,
     129,   540,   405,   406,   519,   193,    52,   537,   181,   416,
       8,   419,   143,    86,   542,   195,    58,    87,   540,   517,
     195,   358,   152,   153,   546,   127,    88,   518,   371,    23,
      66,    67,    60,   181,    61,   230,   553,   441,   195,   514,
     156,   181,    90,   256,    64,   181,    65,   184,   185,   186,
      62,    92,   208,   181,   133,    75,    93,   134,   209,    94,
     195,    89,   181,   235,    13,   115,   211,   459,   215,    95,
     219,   295,   264,   220,    18,   209,   144,    20,   353,   181,
     225,   181,    76,    23,   335,   480,   371,   354,    10,   156,
     193,   234,   264,   288,   181,   162,    13,   441,   163,   289,
     164,   374,    15,   181,    78,    17,    18,    19,   193,    20,
     480,   181,  -132,   193,   253,    23,   371,   383,   255,  -132,
      13,    23,    66,    67,   421,   496,    15,   181,   306,    17,
      18,   193,   181,    20,   181,   181,   182,    10,   283,    23,
     118,   173,   174,   183,   285,    13,   371,   119,   371,   120,
     188,    15,   226,   314,    17,    18,    19,   189,    20,   189,
     229,   286,   317,    82,    23,    83,   373,   189,   287,   318,
     305,   371,   441,   287,   366,   371,   431,   495,   509,   371,
     510,   366,   441,   318,   318,   318,   147,   287,   175,   204,
     151,   298,    72,   156,   205,     8,   207,    79,   131,   165,
     130,   183,   166,   211,   177,   325,   178,   326,   176,   327,
     328,   329,   330,   331,   332,   333,   334,   454,   133,     8,
     455,   134,   211,   181,   337,   169,   170,   171,   172,   243,
     244,   245,   246,   241,   242,   348,   349,   398,   190,   399,
     191,    10,   351,   352,   400,   192,   356,   401,   402,    13,
     521,   239,   240,   522,   403,    15,   404,   203,    17,    18,
      19,     9,    20,   217,   454,    10,    11,   532,    23,   454,
      12,   222,   548,    13,    14,   247,   248,   379,   380,    15,
     224,    16,    17,    18,    19,   133,    20,   233,   134,   388,
      21,    22,    23,   261,   270,   454,   271,   272,   551,   273,
     274,   397,   167,   275,   168,   276,   263,   277,   266,   267,
     282,   296,   297,   298,   307,   308,   313,   319,   339,   341,
     345,   278,   361,   279,   355,   280,   363,   281,   369,   387,
     370,   375,   377,   382,   391,   396,   417,   420,   425,   430,
     432,   435,   437,   429,   438,   444,   445,   446,   447,   456,
     448,   457,   460,   464,   474,   467,   484,   485,   451,   483,
     452,   491,   502,   494,   508,   512,   513,   525,   520,   516,
     533,   526,   545,   462,   547,   538,   249,   543,   250,   254,
     128,   473,   251,   350,   469,   252,   541,   336,   472,   535,
     414,   531,   503,   368,   497,   393,   284,    33,     0,     0,
     211,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     504,   505,   506
  };

  const short
  P5Parser::yycheck_[] =
  {
       2,    78,    91,   121,   189,   141,   142,     6,     6,   268,
       6,   123,     8,   400,    10,    11,    12,    83,    14,    15,
      16,    17,   264,   298,    36,    21,    22,   463,     7,   363,
      26,     9,   121,    11,    36,     9,   148,    92,    93,    94,
      95,   130,    38,     9,    18,    20,    16,     3,     5,    45,
      20,     6,    48,    49,   360,    51,    52,     0,    60,    61,
      17,     6,    17,    75,     8,    10,    62,     7,     5,     8,
       7,    16,     9,    75,     7,     8,    21,     7,     7,    36,
      82,    83,    20,    53,    86,     8,     5,   393,     7,    20,
       9,    10,     5,    12,    90,    14,    17,    53,     8,     8,
      19,   488,   538,    22,     5,    84,    84,   162,   163,   164,
     444,    84,   548,    32,    35,    89,    17,    92,    84,   115,
     362,   123,   121,   121,   136,   121,    11,    84,    72,    84,
     464,   518,    72,   520,   136,    79,     6,    81,   134,    39,
      53,   137,    81,   232,    84,    90,   148,    84,    85,    86,
      20,    84,    90,   149,    84,    84,   543,   432,    81,    90,
     547,    36,    72,    11,   551,    84,    85,    86,    20,    79,
     115,    81,    81,     9,    53,   264,     9,    36,   233,     9,
      65,    11,    18,    11,    84,     8,    71,   189,   190,    74,
      75,   187,   137,    78,     9,   261,     8,    66,   194,    84,
     312,    53,   338,    18,   340,    84,   465,     9,    56,   205,
      16,    59,     5,   290,     7,   292,     9,    53,    11,    12,
      53,    14,    18,   219,   220,   221,    19,    57,    56,    22,
     296,    59,     8,     9,   346,    65,   232,     8,    53,    32,
     376,    71,   378,    20,    74,    75,    76,    53,    78,    72,
      20,    53,   437,   371,    84,     8,    79,    53,    81,   261,
      72,     8,   339,   259,   341,    53,     8,    79,   264,    81,
       5,    17,     7,   362,     9,     8,    53,    12,    15,    14,
       8,    57,   371,    53,    19,    56,    20,    22,    59,    65,
      36,    84,    85,    86,   296,    71,    84,    32,    74,    75,
      76,    53,    78,    56,     9,    20,    59,    44,    84,    56,
     312,   313,    59,    18,    56,    53,   318,    59,   320,    53,
       5,   323,     7,    56,     9,     5,    59,    12,    56,    14,
      65,    59,    20,    20,    19,    53,    71,    22,    53,    74,
      75,    20,   479,    78,   346,   347,     6,    32,    53,    84,
      85,    86,     5,     9,    41,    35,   500,    17,   360,   361,
     497,   363,    18,    58,     6,    53,   362,   456,    63,    64,
      65,   524,   371,   371,    53,   371,    36,   521,    20,   375,
      11,   377,    35,     5,   528,   474,     5,     9,   541,     6,
     479,   393,    87,    88,   533,    90,    18,     6,   400,    84,
      85,    86,     5,    20,     7,    10,   545,   403,   497,     8,
       9,    20,     5,    10,     7,    20,     9,   112,   113,   114,
       7,    14,    10,    20,     9,     7,    19,    12,    16,    22,
     519,    53,    20,    18,    65,   437,   131,   433,   133,    32,
      71,    10,   444,    74,    75,    16,    53,    78,     9,    20,
     145,    20,     7,    84,    10,   457,   458,    18,    57,     9,
     456,   156,   464,    10,    20,    25,    65,   463,    28,    16,
      30,    10,    71,    20,     7,    74,    75,    76,   474,    78,
     482,    20,     6,   479,   179,    84,   488,    10,   183,    13,
      65,    84,    85,    86,    10,    10,    71,    20,    16,    74,
      75,   497,    20,    78,    20,    20,     6,    57,   203,    84,
      72,    33,    34,    13,   209,    65,   518,    79,   520,    81,
       6,    71,     6,   519,    74,    75,    76,    13,    78,    13,
       6,     6,     6,     5,    84,     7,     6,    13,    13,    13,
     235,   543,   538,    13,   546,   547,     6,     6,     6,   551,
       6,   553,   548,    13,    13,    13,    82,    13,    39,     8,
      86,     7,    42,     9,    13,    11,     8,    47,     5,    19,
      17,    13,    22,   268,    43,   270,    40,   272,    46,   274,
     275,   276,   277,   278,   279,   280,   281,    13,     9,    11,
      16,    12,   287,    20,   289,    35,    36,    37,    38,   169,
     170,   171,   172,   167,   168,   300,   301,    53,     5,    55,
      18,    57,   307,   308,    60,    18,   311,    63,    64,    65,
      56,   165,   166,    59,    70,    71,    72,    18,    74,    75,
      76,    53,    78,     8,    13,    57,    58,    16,    84,    13,
      62,     8,    16,    65,    66,   173,   174,   342,   343,    71,
       8,    73,    74,    75,    76,     9,    78,     6,    12,   354,
      82,    83,    84,     7,    18,    13,    20,    21,    16,    23,
      24,   366,    48,    27,    50,    29,     6,    31,     7,     7,
      53,     7,    35,     7,    18,    89,     7,    72,     7,     7,
      53,    45,     7,    47,    10,    49,     5,    51,     8,    10,
       8,     8,     8,     8,     8,    18,     8,     8,    91,     8,
       7,    53,     5,    16,     5,     5,    53,    53,    53,     7,
      53,     7,    77,     5,     7,     6,    53,     5,   423,     8,
     425,     6,     8,     7,     7,     7,    53,     7,    61,    16,
       7,    53,     7,   438,     6,    16,   175,    16,   176,   180,
      64,   454,   177,   306,   449,   178,   525,   287,   453,   519,
     371,   512,   482,   321,   474,   361,   205,     6,    -1,    -1,
     465,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     485,   486,   487
  };

  const unsigned char
  P5Parser::yystos_[] =
  {
       0,    94,   176,     0,     3,    53,   116,   174,    11,    53,
      57,    58,    62,    65,    66,    71,    73,    74,    75,    76,
      78,    82,    83,    84,    96,   115,   117,   124,   125,   126,
     165,   166,   169,   170,   171,   172,   173,    96,   117,   170,
      96,    96,    36,    96,    96,   117,    96,    36,    66,   117,
      96,    17,    36,    96,    53,    53,    53,   174,     5,    96,
       5,     7,     7,     5,     7,     9,    85,    86,    95,    96,
      97,    98,    99,   118,   119,     7,     7,    96,     7,    99,
      96,    96,     5,     7,    96,    96,     5,     9,    18,    53,
       5,    12,    14,    19,    22,    32,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,     9,    18,    89,   116,   138,   139,    72,    79,
      81,   116,   163,   164,    96,   167,   168,   113,   114,   113,
      17,     5,    35,     9,    12,   174,   175,   116,   120,   121,
     122,   123,   123,    35,    53,     9,    53,   139,   164,    17,
      35,   139,   113,   113,    96,   117,     9,   119,   101,   101,
     101,   101,    25,    28,    30,    19,    22,    48,    50,    35,
      36,    37,    38,    33,    34,    39,    46,    43,    40,    15,
      44,    20,     6,    13,   113,   113,   113,   117,     6,    13,
       5,    18,    18,    96,   117,   119,   124,   126,   133,   148,
     149,     8,   163,    18,     8,    13,     6,     8,    10,    16,
     119,   113,   140,   141,    10,   113,    96,     8,   174,    71,
      74,   117,     8,   122,     8,   113,     6,     8,    96,     6,
      10,    53,    17,     6,   113,    18,   101,   101,   101,   102,
     102,   103,   103,   104,   104,   104,   104,   105,   105,   106,
     107,   108,   109,   113,   110,   113,    10,    53,    90,    39,
      96,     7,   138,     6,   116,   134,     7,     7,     5,    96,
      18,    20,    21,    23,    24,    27,    29,    31,    45,    47,
      49,    51,    53,   113,   167,   113,     6,    13,    10,    16,
       7,    96,     7,    96,    96,    10,     7,    35,     7,   152,
       9,    18,    53,    96,   101,   113,    16,    18,    89,    96,
       9,    18,   164,     7,    96,   119,   133,     6,    13,    72,
     154,   157,   158,   151,   141,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,    10,   140,   113,   123,     7,
     123,     7,     9,    18,    53,    53,   164,   151,   113,   113,
     112,   113,   113,     9,    18,    10,   113,     8,   116,   161,
     162,     7,   116,     5,     8,    81,   116,   153,   158,     8,
       8,   116,   150,     6,    10,     8,   123,     8,   123,   113,
     113,     8,     8,    10,    53,    53,    90,    10,   113,    56,
      59,     8,   161,   162,   133,   134,    18,   113,    53,    55,
      60,    63,    64,    70,    72,   124,   126,   136,   137,   142,
     143,   144,   147,   149,   152,    53,    96,     8,    53,    96,
       8,    10,    53,    18,    53,    91,   113,   129,   130,    16,
       8,     6,     7,    16,    53,    53,   150,     5,     5,     7,
      72,    96,   127,   135,     5,    53,    53,    53,    53,     9,
      53,   113,   113,    41,    13,    16,     7,     7,   151,    96,
      77,   138,   113,   128,     5,     5,    53,     6,   134,   113,
      53,    92,   113,   129,     7,   124,   126,   149,   159,   160,
     116,   155,   156,     8,    53,     5,    16,    53,     6,     8,
     127,     6,   134,   141,     7,     6,    10,   160,     8,   159,
      56,    59,     8,   155,   113,   113,   113,   150,     7,     6,
       6,   146,     7,    53,     8,   130,    16,     6,     6,    53,
      61,    56,    59,   131,   132,     7,    53,     8,    56,    59,
     145,   146,    16,     7,   150,   148,   150,   130,    16,     8,
     131,   132,   130,    16,     8,     7,   154,     6,    16,   127,
       8,    16,   150,   154,     8,   150,   127,   150,     8
  };

  const unsigned char
  P5Parser::yyr1_[] =
  {
       0,    93,    94,    95,    96,    97,    98,    98,    98,    98,
      98,    98,    99,    99,   100,   100,   100,   100,   100,   101,
     101,   102,   102,   102,   102,   103,   103,   103,   104,   104,
     104,   105,   105,   105,   105,   105,   106,   106,   106,   107,
     107,   108,   108,   109,   109,   110,   110,   111,   111,   112,
     112,   113,   113,   113,   114,   114,   115,   115,   116,   116,
     117,   117,   117,   117,   117,   117,   117,   117,   118,   118,
     118,   118,   118,   119,   119,   119,   120,   120,   120,   120,
     121,   121,   121,   121,   121,   121,   122,   122,   123,   123,
     124,   124,   124,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   127,   127,   127,   128,   128,   129,   129,   130,
     130,   131,   131,   131,   131,   132,   132,   133,   133,   134,
     134,   135,   135,   136,   136,   137,   138,   138,   138,   138,
     138,   138,   139,   139,   139,   140,   141,   141,   141,   142,
     143,   143,   144,   144,   145,   145,   145,   145,   146,   146,
     147,   147,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   149,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   151,   151,   152,
     153,   153,   153,   154,   154,   155,   155,   155,   155,   156,
     156,   157,   158,   158,   159,   159,   159,   160,   160,   160,
     161,   161,   161,   161,   162,   162,   163,   163,   163,   163,
     163,   163,   163,   163,   164,   164,   165,   165,   165,   165,
     166,   167,   167,   168,   168,   169,   170,   170,   171,   171,
     171,   172,   173,   174,   174,   174,   174,   174,   174,   174,
     174,   175,   175,   176,   176,   176
  };

  const signed char
  P5Parser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     4,     1,     2,     2,     2,     2,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     2,     4,     1,     3,     2,     5,     0,     2,
       4,     4,     1,     1,     3,     4,     6,     1,     1,     3,
       4,     3,     3,     1,     6,     5,     4,     6,     7,    10,
       6,     7,     7,     6,     7,     7,     1,     1,     1,     2,
       6,     9,    12,     4,     7,     3,     5,     6,     8,     9,
      11,     4,     5,     3,     2,     0,     2,     1,     3,     1,
       3,     4,     3,     3,     2,     1,     2,     1,     4,     2,
       4,     7,     6,     2,     2,     2,     3,     5,     4,     6,
       6,     5,     0,     1,     3,     1,     0,     1,     3,     6,
       5,     7,     9,     7,     4,     3,     3,     2,     0,     2,
       7,     6,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     0,     2,     3,
       5,     5,     3,     0,     2,     7,     4,     6,     3,     1,
       2,     7,     1,     2,     1,     1,     1,     0,     1,     2,
       7,     4,     6,     3,     1,     2,     5,     5,     5,     7,
       6,     2,     2,     2,     1,     2,     8,     5,     8,     5,
       3,     1,     3,     1,     3,     5,     5,     5,     2,     2,
       2,     6,     5,     2,     2,     2,     2,     2,     3,     2,
       2,     1,     2,     0,     2,     2
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
  "case", "switch_cases", "switch_statement", "assignment_or_call",
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
     358,   359,   363,   364,   368,   369,   370,   371,   372,   376,
     377,   381,   382,   383,   384,   388,   390,   391,   395,   396,
     397,   401,   402,   403,   404,   405,   409,   410,   411,   415,
     416,   420,   421,   425,   426,   430,   431,   435,   436,   440,
     441,   445,   447,   452,   462,   465,   476,   482,   489,   492,
     506,   514,   522,   525,   529,   533,   537,   541,   546,   548,
     549,   550,   551,   556,   557,   558,   561,   568,   576,   584,
     595,   604,   613,   622,   633,   643,   655,   656,   660,   666,
     680,   684,   689,   697,   701,   707,   708,   709,   713,   717,
     722,   727,   736,   742,   743,   749,   752,   758,   759,   762,
     768,   775,   786,   792,   803,   811,   816,   823,   826,   833,
     839,   846,   849,   854,   855,   858,   866,   873,   880,   887,
     894,   904,   916,   917,   922,   930,   933,   934,   940,   948,
     964,   970,   981,  1001,  1039,  1049,  1055,  1064,  1071,  1072,
    1078,  1081,  1086,  1093,  1096,  1100,  1104,  1108,  1112,  1116,
    1120,  1124,  1128,  1132,  1137,  1144,  1147,  1151,  1155,  1159,
    1160,  1161,  1162,  1163,  1164,  1165,  1166,  1172,  1173,  1179,
    1188,  1193,  1200,  1208,  1211,  1217,  1226,  1237,  1246,  1258,
    1263,  1269,  1276,  1281,  1288,  1289,  1290,  1293,  1296,  1301,
    1307,  1317,  1322,  1332,  1339,  1345,  1353,  1358,  1363,  1368,
    1371,  1374,  1377,  1380,  1386,  1390,  1398,  1401,  1404,  1407,
    1419,  1426,  1430,  1436,  1446,  1460,  1467,  1471,  1480,  1481,
    1482,  1485,  1493,  1503,  1508,  1513,  1518,  1523,  1527,  1528,
    1533,  1540,  1545,  1553,  1554,  1557
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
#line 5984 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"

#line 1560 "/root/p4c/frontends/parsers/p5/p5parser.ypp"


namespace P4 {

void P5::P5Parser::error(const Util::SourceInfo& location,
                         const std::string& message) {
    driver.onParseError(location, message);
}

}  // namespace P4
