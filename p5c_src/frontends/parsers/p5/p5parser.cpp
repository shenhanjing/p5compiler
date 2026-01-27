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

  case 71: // field_ref_no_slice: ID "::" field_ref
#line 550 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            { auto path = new IR::Path(yystack_[2].location, *yystack_[2].value.as < IR::ID* > ());
                              auto base = new IR::PathExpression(yystack_[2].location, path);
                              yylhs.value.as < IR::Expression* > () = new IR::Member(yystack_[1].location, base, yystack_[0].value.as < IR::Expression* > ()->toString()); }
#line 3420 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 72: // field_ref: field_ref_no_slice
#line 555 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                             { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3426 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 73: // field_ref: field_ref "[" expression ":" expression "]"
#line 556 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      { yylhs.value.as < IR::Expression* > () = new IR::Slice(yystack_[4].location, yystack_[5].value.as < IR::Expression* > (), yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3432 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 74: // field_ref: "[" expression ":" expression "]"
#line 557 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            { yylhs.value.as < IR::Expression* > () = new IR::Slice(yystack_[4].location, nullptr, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3438 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 75: // field_dec: annotations type_ref ID ";"
#line 560 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                auto field = new IR::StructField(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), yystack_[2].value.as < const IR::Type* > ());
                if (yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3450 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 76: // field_dec: annotations type_ref ID "=" expression ";"
#line 567 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      {
                // 只能忽略初始化值，或者记录表达式用于后续处理
                auto field = new IR::StructField(yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), yystack_[4].value.as < const IR::Type* > ());
                if (yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3463 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 77: // field_dec: annotations type_ref ID "[" expression "]" ";"
#line 575 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                         {
                auto arrayType = new IR::Type_Stack(yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::Expression* > ());
                auto field = new IR::StructField(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), arrayType);
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3476 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 78: // field_dec: annotations type_ref ID "[" expression "]" "[" expression "]" ";"
#line 583 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                            {
                auto innerArray = new IR::Type_Stack(yystack_[8].value.as < const IR::Type* > (), yystack_[5].value.as < IR::Expression* > ());
                auto outerArray = new IR::Type_Stack(innerArray, yystack_[2].value.as < IR::Expression* > ());
                auto field = new IR::StructField(yystack_[7].location, *yystack_[7].value.as < IR::ID* > (), outerArray);
                if (yystack_[9].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[9].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3490 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 79: // anonymous_struct_union_dec: annotations STRUCT "{" struct_field_list "}" ";"
#line 595 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[4].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[2].value.as < IR::IndexedVector<IR::StructField>* > ());
                if (yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[4].location, anonName, type);
        }
#line 3503 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 80: // anonymous_struct_union_dec: annotations STRUCT ID "{" struct_field_list "}" ";"
#line 604 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[5].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[2].value.as < IR::IndexedVector<IR::StructField>* > ());
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), type);
        }
#line 3516 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 81: // anonymous_struct_union_dec: annotations STRUCT "{" struct_field_list "}" ID ";"
#line 613 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[5].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[3].value.as < IR::IndexedVector<IR::StructField>* > ());
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), type);
        }
#line 3529 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 82: // anonymous_struct_union_dec: annotations UNION "{" struct_field_list "}" ";"
#line 622 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 3544 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 83: // anonymous_struct_union_dec: annotations UNION ID "{" struct_field_list "}" ";"
#line 633 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[5].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[2].value.as < IR::IndexedVector<IR::StructField>* > ());
                type->annotations.push_back(new IR::Annotation("union", {}));
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), type);
        }
#line 3558 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 84: // anonymous_struct_union_dec: annotations UNION "{" struct_field_list "}" ID ";"
#line 643 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[5].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[3].value.as < IR::IndexedVector<IR::StructField>* > ());
                type->annotations.push_back(new IR::Annotation("union", {}));
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), type);
        }
#line 3572 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 85: // struct_field_dec: field_dec
#line 654 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                    { yylhs.value.as < IR::StructField* > () = yystack_[0].value.as < IR::StructField* > (); }
#line 3578 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 86: // struct_field_dec: anonymous_struct_union_dec
#line 655 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                     { yylhs.value.as < IR::StructField* > () = yystack_[0].value.as < IR::StructField* > (); }
#line 3584 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 87: // struct_field_list: struct_field_dec
#line 660 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto vec = new IR::IndexedVector<IR::StructField>();
                vec->push_back(yystack_[0].value.as < IR::StructField* > ());
                yylhs.value.as < IR::IndexedVector<IR::StructField>* > () = vec;
        }
#line 3594 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 88: // struct_field_list: struct_field_list struct_field_dec
#line 666 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ()->push_back(yystack_[0].value.as < IR::StructField* > ());
                yylhs.value.as < IR::IndexedVector<IR::StructField>* > () = yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ();
        }
#line 3603 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 89: // constant_declaration: CONST type_ref ID "=" expression ";"
#line 680 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Declaration_Constant* > () = new IR::Declaration_Constant(yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), yystack_[4].value.as < const IR::Type* > (), yystack_[1].value.as < IR::Expression* > ());
        }
#line 3611 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 90: // constant_declaration: CONST type_ref ID "[" expression "]" "=" expression ";"
#line 684 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto type = new IR::Type_Stack(yystack_[7].location, yystack_[7].value.as < const IR::Type* > (), yystack_[4].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Declaration_Constant* > () = new IR::Declaration_Constant(yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3620 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 91: // constant_declaration: CONST type_ref ID '[' expression ']' '[' expression ']' '=' expression ';'
#line 689 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto innerType = new IR::Type_Stack(yystack_[10].location, yystack_[10].value.as < const IR::Type* > (), yystack_[7].value.as < IR::Expression* > ());
                auto type = new IR::Type_Stack(yystack_[10].location, innerType, yystack_[4].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Declaration_Constant* > () = new IR::Declaration_Constant(yystack_[9].location, *yystack_[9].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3630 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 92: // header_declaration: HEADER type_ref ID ";"
#line 696 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 {
                auto args = new IR::Vector<IR::Argument>();
                yylhs.value.as < IR::Declaration* > () = new IR::Declaration_Instance(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), yystack_[2].value.as < const IR::Type* > (), args);
        }
#line 3639 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 93: // header_declaration: HEADER type_ref ID "[" expression "]" ";"
#line 700 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   {
                auto type = new IR::Type_Stack(yystack_[5].location, yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Declaration* > () = new IR::Declaration_Instance(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), type, {});
        }
#line 3648 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 94: // variable_declaration: type_ref ID ";"
#line 706 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          { yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), yystack_[2].value.as < const IR::Type* > (), nullptr); }
#line 3654 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 95: // variable_declaration: type_ref ID "=" expression ";"
#line 707 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), yystack_[4].value.as < const IR::Type* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3660 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 96: // variable_declaration: type_ref ID "[" expression "]" ";"
#line 708 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                             {
            auto type = new IR::Type_Stack(yystack_[5].location, yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), type, nullptr);
        }
#line 3669 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 97: // variable_declaration: type_ref ID "[" expression "]" "=" expression ";"
#line 712 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                            {
            auto type = new IR::Type_Stack(yystack_[7].location, yystack_[7].value.as < const IR::Type* > (), yystack_[4].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3678 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 98: // variable_declaration: type_ref ID "[" expression "]" "[" expression "]" ";"
#line 716 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                {
            auto innerType = new IR::Type_Stack(yystack_[8].location, yystack_[8].value.as < const IR::Type* > (), yystack_[5].value.as < IR::Expression* > ());
            auto type = new IR::Type_Stack(yystack_[8].location, innerType, yystack_[2].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[7].location, *yystack_[7].value.as < IR::ID* > (), type, nullptr);
        }
#line 3688 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 99: // variable_declaration: type_ref ID "[" expression "]" "[" expression "]" "=" expression ";"
#line 721 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                               {
            auto innerType = new IR::Type_Stack(yystack_[10].location, yystack_[10].value.as < const IR::Type* > (), yystack_[7].value.as < IR::Expression* > ());
            auto type = new IR::Type_Stack(yystack_[10].location, innerType, yystack_[4].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[9].location, *yystack_[9].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3698 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 100: // variable_declaration: USING NAMESPACE ID ";"
#line 726 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::Declaration_Variable* > () = nullptr; /* TODO: maybe handle 'using namespace' */ }
#line 3704 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 101: // return_value_type: ID "(" arg_list ")" ";"
#line 735 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  {
                auto pe = new IR::PathExpression(*yystack_[4].value.as < IR::ID* > ());
                auto mc = new IR::MethodCallExpression(yystack_[4].location, pe,
                                                 new IR::Vector<IR::Type>(), yystack_[2].value.as < IR::Vector<IR::Argument>* > ());
                yylhs.value.as < IR::Statement* > () = new IR::ReturnStatement(yystack_[4].location + yystack_[1].location, mc);
        }
#line 3715 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 102: // return_value_type: "{" return_value_type_list "}"
#line 741 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Statement* > () = yystack_[1].value.as < IR::BlockStatement* > (); }
#line 3721 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 103: // return_value_type: ID ";"
#line 742 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                auto pe = new IR::PathExpression(*yystack_[1].value.as < IR::ID* > ());
                yylhs.value.as < IR::Statement* > () = new IR::ReturnStatement(yystack_[1].location + yystack_[0].location, pe);
        }
#line 3730 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 104: // return_value_type_list: %empty
#line 748 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yylhs.location);
        }
#line 3738 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 105: // return_value_type_list: return_value_type_list return_value_type
#line 751 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   {
                yystack_[1].value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::Statement* > ());
                yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 3747 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 106: // value_masked_or_set: expression
#line 757 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3753 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 107: // value_masked_or_set: expression "&&&" expression
#line 758 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      { yylhs.value.as < IR::Expression* > () = new IR::Mask(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3759 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 108: // value_list: value_masked_or_set
#line 762 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto vec = new IR::Vector<IR::Expression>();
                vec->push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Vector<IR::Expression>* > () = vec;
        }
#line 3769 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 109: // value_list: value_list "," value_masked_or_set
#line 768 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[2].value.as < IR::Vector<IR::Expression>* > ()->push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Vector<IR::Expression>* > () = yystack_[2].value.as < IR::Vector<IR::Expression>* > ();
        }
#line 3778 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 110: // case_entry: CASE value_list ":" return_value_type
#line 775 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 3793 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 111: // case_entry: CASE value_list ":"
#line 786 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                // Empty case body (fallthrough): "case ...:" with nothing after ':'
                IR::Expression* le =  new IR::ListExpression(yystack_[2].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ());
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, le, nullptr);
        }
#line 3803 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 112: // case_entry: DEFAULT ":" return_value_type
#line 792 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 3818 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 113: // case_entry: DEFAULT ":"
#line 803 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                // Empty default body (fallthrough).
                auto label = new IR::DefaultExpression(yystack_[1].location);
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[1].location, label, nullptr);
        }
#line 3828 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 114: // case_list: case_entry
#line 810 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = new IR::Vector<IR::SwitchCase>();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[0].location;
        }
#line 3838 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 115: // case_list: case_list case_entry
#line 815 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                               {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
        }
#line 3848 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 116: // field_ref_or_func: field_ref
#line 822 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                    {
                yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > ();
        }
#line 3856 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 117: // field_ref_or_func: ID "(" arg_list ")"
#line 825 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                              {
                auto path   = new IR::Path(yystack_[3].location, *yystack_[3].value.as < IR::ID* > ());
                auto callee = new IR::PathExpression(yystack_[3].location, path);
                yylhs.value.as < IR::Expression* > () = new IR::MethodCallExpression(yystack_[2].location, callee, yystack_[1].value.as < IR::Vector<IR::Argument>* > ());
        }
#line 3866 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 118: // select_exp: annotations field_ref_or_func
#line 832 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                auto vec = new IR::Vector<IR::Expression>();
                // Ignore annotations for select list entries.
                vec->push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::ListExpression* > () = new IR::ListExpression(yystack_[1].location, *vec);
        }
#line 3877 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 119: // select_exp: select_exp "," annotations field_ref_or_func
#line 838 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                       {
                // Ignore annotations for select list entries.
                yystack_[3].value.as < IR::ListExpression* > ()->components.push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::ListExpression* > () = yystack_[3].value.as < IR::ListExpression* > ();
        }
#line 3887 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 120: // return_select_statement: SWITCH "(" select_exp ")" "{" case_list "}"
#line 845 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      {
                yylhs.value.as < IR::Statement* > () = new IR::SwitchStatement(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 3895 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 121: // return_statement: RETURN return_select_statement
#line 850 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Statement* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 3901 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 122: // return_statement: RETURN return_value_type
#line 851 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   { yylhs.value.as < IR::Statement* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 3907 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 123: // break_statement: BREAK ";"
#line 854 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                    { yylhs.value.as < IR::Statement* > () = new IR::BreakStatement(yystack_[1].location); }
#line 3913 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 124: // parameter: annotations type_ref ID
#line 862 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  {
                auto param = new IR::Parameter(yystack_[0].location, *yystack_[0].value.as < IR::ID* > (), IR::Direction::In, yystack_[1].value.as < const IR::Type* > ());
                if (yystack_[2].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[2].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 3925 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 125: // parameter: annotations type_ref ID "=" expression
#line 869 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                 {
                auto param = new IR::Parameter(yystack_[2].location, *yystack_[2].value.as < IR::ID* > (), IR::Direction::In, yystack_[3].value.as < const IR::Type* > (), yystack_[0].value.as < IR::Expression* > ());
                if (yystack_[4].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[4].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 3937 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 126: // parameter: annotations type_ref "&" ID
#line 876 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      {
                auto param = new IR::Parameter(yystack_[0].location, *yystack_[0].value.as < IR::ID* > (), IR::Direction::InOut, yystack_[2].value.as < const IR::Type* > ());
                if (yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 3949 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 127: // parameter: annotations type_ref "&" ID "=" expression
#line 883 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                     {
                auto param = new IR::Parameter(yystack_[2].location, *yystack_[2].value.as < IR::ID* > (), IR::Direction::InOut, yystack_[4].value.as < const IR::Type* > (), yystack_[0].value.as < IR::Expression* > ());
                if (yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 3961 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 128: // parameter: annotations type_ref "&" ID "[" "]"
#line 890 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 3976 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 129: // parameter: annotations type_ref ID "[" "]"
#line 900 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 3991 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 130: // param_list: %empty
#line 912 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::ParameterList* > () = new IR::ParameterList(); }
#line 3997 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 131: // param_list: parameter
#line 914 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto pl = new IR::ParameterList(); pl->push_back(yystack_[0].value.as < IR::Parameter* > ());
                yylhs.value.as < IR::ParameterList* > () = pl;
        }
#line 4006 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 132: // param_list: param_list "," parameter
#line 919 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[2].value.as < IR::ParameterList* > ()->push_back(yystack_[0].value.as < IR::Parameter* > ());
                yylhs.value.as < IR::ParameterList* > () = yystack_[2].value.as < IR::ParameterList* > ();
        }
#line 4015 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 133: // arg: expression
#line 926 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     { yylhs.value.as < IR::Argument* > () = new IR::Argument(yystack_[0].location, yystack_[0].value.as < IR::Expression* > ()); }
#line 4021 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 134: // arg_list: %empty
#line 929 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::Vector<IR::Argument>* > () = new IR::Vector<IR::Argument>(); }
#line 4027 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 135: // arg_list: arg
#line 931 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto v = new IR::Vector<IR::Argument>();
                v->push_back(yystack_[0].value.as < IR::Argument* > ());
                yylhs.value.as < IR::Vector<IR::Argument>* > () = v;
        }
#line 4037 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 136: // arg_list: arg_list "," arg
#line 937 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[2].value.as < IR::Vector<IR::Argument>* > ()->push_back(yystack_[0].value.as < IR::Argument* > ());
                yylhs.value.as < IR::Vector<IR::Argument>* > () = yystack_[2].value.as < IR::Vector<IR::Argument>* > ();
        }
#line 4046 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 137: // do_while_statement: DO action_statement WHILE "(" expression ")"
#line 945 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4063 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 138: // conditional_statement: IF "(" expression ")" action_statement
#line 960 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                   {
                IR::IndexedVector<IR::StatOrDecl> as;
                as.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto bs = new IR::BlockStatement(yystack_[0].location, as);
                yylhs.value.as < IR::Statement* > () = new IR::IfStatement(yystack_[4].location, yystack_[2].value.as < IR::Expression* > (), bs, nullptr);
        }
#line 4074 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 139: // conditional_statement: IF "(" expression ")" action_statement ELSE action_statement
#line 966 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                                   {
                IR::IndexedVector<IR::StatOrDecl> as0;
                as0.push_back(yystack_[2].value.as < IR::StatOrDecl* > ());
                auto bs0 = new IR::BlockStatement(yystack_[2].location, as0);
                IR::IndexedVector<IR::StatOrDecl> as1;
                as1.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto bs1 = new IR::BlockStatement(yystack_[0].location, as1);
                yylhs.value.as < IR::Statement* > () = new IR::IfStatement(yystack_[6].location, yystack_[4].value.as < IR::Expression* > (), bs0, bs1);
        }
#line 4088 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 140: // for_loop_statement: FOR "(" parameter ";" expression ";" assignment_or_call ")" action_statement
#line 978 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4112 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 141: // for_loop_statement: FOR "(" parameter ":" expression ")" action_statement
#line 998 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4153 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 142: // case: CASE value_list ":" action_statement
#line 1036 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                IR::Expression* vl = new IR::ListExpression(yystack_[3].location, *yystack_[2].value.as < IR::Vector<IR::Expression>* > ());

                IR::IndexedVector<IR::StatOrDecl> as_vec;
                as_vec.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto as = new IR::BlockStatement(yystack_[0].location, as_vec);

                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[3].location, vl, as);
        }
#line 4167 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 143: // case: CASE value_list ":"
#line 1046 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                // Empty case body (fallthrough).
                IR::Expression* vl = new IR::ListExpression(yystack_[2].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ());
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, vl, nullptr);
        }
#line 4177 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 144: // case: DEFAULT ":" action_statement
#line 1051 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                IR::IndexedVector<IR::StatOrDecl> as_vec;
                as_vec.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto as = new IR::BlockStatement(yystack_[0].location, as_vec);

                auto label = new IR::DefaultExpression(yystack_[2].location);

                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, label, as);
        }
#line 4191 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 145: // case: DEFAULT ":"
#line 1060 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                      {
                // Empty default body (fallthrough).
                auto label = new IR::DefaultExpression(yystack_[1].location);
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[1].location, label, nullptr);
        }
#line 4201 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 146: // switch_cases: %empty
#line 1067 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = new IR::Vector<IR::SwitchCase>; }
#line 4207 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 147: // switch_cases: switch_cases case
#line 1068 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            {
                yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ();
        }
#line 4216 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 148: // switch_statement: SWITCH "(" select_exp ")" "{" switch_cases "}"
#line 1074 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                         {
                yylhs.value.as < IR::Statement* > () = new IR::SwitchStatement(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 4224 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 149: // assignment_or_call: field_ref_or_func
#line 1079 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            {
                if (auto mc = yystack_[0].value.as < IR::Expression* > ()->to<IR::MethodCallExpression>()) {
                        yylhs.value.as < IR::Statement* > () = new IR::MethodCallStatement(yystack_[0].location, mc);
                } else {
                        yylhs.value.as < IR::Statement* > () = new IR::EmptyStatement(yystack_[0].location);
                }
        }
#line 4236 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 150: // assignment_or_call: field_ref "=" expression
#line 1086 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   {
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
        }
#line 4244 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 151: // assignment_or_call: field_ref "-=" expression
#line 1089 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto sub = new IR::Sub(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), sub);
        }
#line 4253 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 152: // assignment_or_call: field_ref "+=" expression
#line 1093 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto sub = new IR::Sub(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), sub);
        }
#line 4262 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 153: // assignment_or_call: field_ref "*=" expression
#line 1097 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto mul = new IR::Mul(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), mul);
        }
#line 4271 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 154: // assignment_or_call: field_ref "/=" expression
#line 1101 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto div = new IR::Div(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), div);
        }
#line 4280 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 155: // assignment_or_call: field_ref "%=" expression
#line 1105 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto mod = new IR::Mod(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), mod);
        }
#line 4289 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 156: // assignment_or_call: field_ref "|=" expression
#line 1109 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto bor = new IR::BOr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), bor);
        }
#line 4298 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 157: // assignment_or_call: field_ref "^=" expression
#line 1113 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto bxor = new IR::BXor(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), bxor);
        }
#line 4307 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 158: // assignment_or_call: field_ref "<<=" expression
#line 1117 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                     {
                auto shl = new IR::Shl(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), shl);
        }
#line 4316 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 159: // assignment_or_call: field_ref ">>=" expression
#line 1121 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                     {
                auto shr = new IR::Shr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), shr);
        }
#line 4325 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 160: // assignment_or_call: field_ref "++"
#line 1125 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         {
                auto one = new IR::Constant(IR::Type_Bits::get(32), 1);
                auto add = new IR::Add(yystack_[0].location, yystack_[1].value.as < IR::Expression* > (), one);
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[0].location, yystack_[1].value.as < IR::Expression* > (), add);
        }
#line 4335 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 161: // assignment_or_call: field_ref "--"
#line 1130 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         {
                auto one = new IR::Constant(IR::Type_Bits::get(32), 1);
                auto sub = new IR::Sub(yystack_[0].location, yystack_[1].value.as < IR::Expression* > (), one);
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[0].location, yystack_[1].value.as < IR::Expression* > (), sub);
        }
#line 4345 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 162: // assignment_or_call_statement: assignment_or_call ";"
#line 1137 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::Statement* > () = yystack_[1].value.as < IR::Statement* > (); }
#line 4351 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 163: // action_statement: annotations variable_declaration
#line 1140 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Variable* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Variable* > ();
        }
#line 4360 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 164: // action_statement: annotations constant_declaration
#line 1144 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Constant* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Constant* > ();
        }
#line 4369 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 165: // action_statement: annotations action_compound_statement
#line 1148 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                {
                attachAnnotations(yystack_[0].value.as < IR::BlockStatement* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::BlockStatement* > ();
        }
#line 4378 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 166: // action_statement: annotations conditional_statement
#line 1152 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4384 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 167: // action_statement: annotations switch_statement
#line 1153 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4390 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 168: // action_statement: annotations do_while_statement
#line 1154 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4396 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 169: // action_statement: annotations for_loop_statement
#line 1155 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4402 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 170: // action_statement: annotations return_statement
#line 1156 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4408 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 171: // action_statement: annotations break_statement
#line 1157 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4414 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 172: // action_statement: annotations assignment_or_call_statement
#line 1158 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4420 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 173: // action_statement: annotations ";"
#line 1159 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          {
            yylhs.value.as < IR::StatOrDecl* > () = new IR::EmptyStatement(yylhs.location);
        }
#line 4428 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 174: // action_statement_list: %empty
#line 1165 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yylhs.location); }
#line 4434 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 175: // action_statement_list: action_statement_list action_statement
#line 1166 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                 {
              yystack_[1].value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
              yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 4443 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 176: // action_compound_statement: "{" action_statement_list "}"
#line 1172 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > (); }
#line 4449 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 177: // key_element: CONTROL_PARAMETERS "=" "{" action_statement_list "}"
#line 1181 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                               {
                auto ke = new IR::P5KeyElement(yystack_[4].location);
                ke->control = *yystack_[1].value.as < IR::BlockStatement* > ();
                yylhs.value.as < IR::P5KeyElement* > () = ke;
        }
#line 4459 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 178: // key_element: annotations expression ":" ID ";"
#line 1186 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            {
                auto ke = new IR::P5KeyElement(yystack_[4].location);
                ke->annotations = *yystack_[4].value.as < IR::Vector<IR::Annotation>* > ();
                ke->expr = yystack_[3].value.as < IR::Expression* > ();
                ke->matchType = *yystack_[1].value.as < IR::ID* > ();
                yylhs.value.as < IR::P5KeyElement* > () = ke;
        }
#line 4471 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 179: // key_element: annotations expression ";"
#line 1193 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                     {
                auto ke = new IR::P5KeyElement(yystack_[2].location);
                ke->annotations = *yystack_[2].value.as < IR::Vector<IR::Annotation>* > ();
                ke->expr = yystack_[1].value.as < IR::Expression* > ();
                yylhs.value.as < IR::P5KeyElement* > () = ke;
        }
#line 4482 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 180: // key_element_list: %empty
#line 1201 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::Vector<IR::P5KeyElement>* > () = new IR::Vector<IR::P5KeyElement>();
        }
#line 4490 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 181: // key_element_list: key_element_list key_element
#line 1204 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ()->push_back(yystack_[0].value.as < IR::P5KeyElement* > ());
                yylhs.value.as < IR::Vector<IR::P5KeyElement>* > () = yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
        }
#line 4499 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 182: // key_case_entry: annotations CASE value_list ":" "{" key_element_list "}"
#line 1210 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                   {
                auto label = new IR::ListExpression(yystack_[4].location, *yystack_[4].value.as < IR::Vector<IR::Expression>* > ());
                auto kce = new IR::P5KeyCase(yystack_[6].location, false);
                kce->annotations = *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ();
                kce->label = label;
                kce->elements = *yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
                kce->fallthrough = false;
                yylhs.value.as < IR::P5KeyCase* > () = kce;
        }
#line 4513 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 183: // key_case_entry: annotations CASE value_list ":"
#line 1219 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4529 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 184: // key_case_entry: annotations DEFAULT ":" "{" key_element_list "}"
#line 1230 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                           {
                auto label = new IR::DefaultExpression(yystack_[4].location);
                auto kce = new IR::P5KeyCase(yystack_[5].location, false);
                kce->annotations = *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ();
                kce->label = label;
                kce->elements = *yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
                kce->fallthrough = false;
                yylhs.value.as < IR::P5KeyCase* > () = kce;
        }
#line 4543 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 185: // key_case_entry: annotations DEFAULT ":"
#line 1239 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4558 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 186: // key_case_list: key_case_entry
#line 1251 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         {
                auto v = new IR::Vector<IR::P5KeyCase>();
                v->push_back(yystack_[0].value.as < IR::P5KeyCase* > ());
                yylhs.value.as < IR::Vector<IR::P5KeyCase>* > () = v;
        }
#line 4568 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 187: // key_case_list: key_case_list key_case_entry
#line 1256 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                yystack_[1].value.as < IR::Vector<IR::P5KeyCase>* > ()->push_back(yystack_[0].value.as < IR::P5KeyCase* > ());
                yylhs.value.as < IR::Vector<IR::P5KeyCase>* > () = yystack_[1].value.as < IR::Vector<IR::P5KeyCase>* > ();
        }
#line 4577 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 188: // key_switch_entry: SWITCH "(" select_exp ")" "{" key_case_list "}"
#line 1262 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                          {
                // P5KeySwitch is a dedicated IR node so a single key={...} can contain
                // multiple switch blocks in source order.
                yylhs.value.as < IR::P5KeySwitch* > () = new IR::P5KeySwitch(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::P5KeyCase>* > ());
        }
#line 4587 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 189: // key_switch_list: key_switch_entry
#line 1269 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                           {
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > () = new IR::Vector<IR::P5KeySwitch>();
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->push_back(yystack_[0].value.as < IR::P5KeySwitch* > ());
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->srcInfo = yystack_[0].location;
        }
#line 4597 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 190: // key_switch_list: key_switch_entry key_switch_list
#line 1274 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > () = yystack_[0].value.as < IR::Vector<IR::P5KeySwitch>* > ();
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->insert(yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->begin(), yystack_[1].value.as < IR::P5KeySwitch* > ());
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
        }
#line 4607 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 191: // program_selection_statement: constant_declaration
#line 1281 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Constant* > (); }
#line 4613 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 192: // program_selection_statement: variable_declaration
#line 1282 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Variable* > (); }
#line 4619 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 193: // program_selection_statement: assignment_or_call_statement
#line 1283 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4625 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 194: // program_selection_statement_list: %empty
#line 1286 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yylhs.location);
        }
#line 4633 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 195: // program_selection_statement_list: program_selection_statement
#line 1289 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      {
                auto blk = new IR::BlockStatement(yystack_[0].location);
                blk->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                yylhs.value.as < IR::BlockStatement* > () = blk;
        }
#line 4643 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 196: // program_selection_statement_list: program_selection_statement_list program_selection_statement
#line 1294 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                       {
                yystack_[1].value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 4652 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 197: // table_case_entry: annotations CASE value_list ":" "{" program_selection_statement_list "}"
#line 1300 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4667 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 198: // table_case_entry: annotations CASE value_list ":"
#line 1310 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                          {
                // Empty case body (fallthrough).
                IR::Expression* label = new IR::ListExpression(yystack_[1].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ());
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, label, nullptr);
        }
#line 4677 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 199: // table_case_entry: annotations DEFAULT ":" "{" program_selection_statement_list "}"
#line 1315 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4692 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 200: // table_case_entry: annotations DEFAULT ":"
#line 1325 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  {
                // Empty default body (fallthrough).
                IR::Expression* label = new IR::DefaultExpression(yystack_[1].location);
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[1].location, label, nullptr);
        }
#line 4702 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 201: // table_case_list: table_case_entry
#line 1333 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = new IR::Vector<IR::SwitchCase>();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[0].location;
        }
#line 4712 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 202: // table_case_list: table_case_list table_case_entry
#line 1339 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
        }
#line 4722 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 203: // table_property: KEY "=" "{" key_element_list "}"
#line 1346 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                auto key = new IR::P5Key(yystack_[4].location);
                key->elements = *yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
                yylhs.value.as < IR::StatOrDecl* > () = key;
        }
#line 4732 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 204: // table_property: KEY "=" "{" key_switch_list "}"
#line 1351 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                          {
                auto key = new IR::P5Key(yystack_[4].location);
                key->switches = *yystack_[1].value.as < IR::Vector<IR::P5KeySwitch>* > ();
                yylhs.value.as < IR::StatOrDecl* > () = key;
        }
#line 4742 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 205: // table_property: CONTROL_PARAMETERS "=" "{" action_statement_list "}"
#line 1356 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                               {
                // Similar to key_element's CONTROL_PARAMETERS form, but table properties
                // don't wrap this in a P5KeyElement: return the action block directly.
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 4752 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 206: // table_property: SWITCH "(" select_exp ")" "{" table_case_list "}"
#line 1361 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                            {
                yylhs.value.as < IR::StatOrDecl* > () = new IR::SwitchStatement(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 4760 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 207: // table_property: annotations assignment_or_call_statement
#line 1364 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   {
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > ();
        }
#line 4768 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 208: // table_property: annotations constant_declaration
#line 1367 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Constant* > ();
        }
#line 4776 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 209: // table_property: annotations variable_declaration
#line 1370 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Variable* > ();
        }
#line 4784 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 210: // table_property_list: table_property
#line 1376 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         {
                yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yystack_[0].location);
                if (yystack_[0].value.as < IR::StatOrDecl* > ()) yylhs.value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
        }
#line 4793 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 211: // table_property_list: table_property_list table_property
#line 1380 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                             {
                yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
                if (yystack_[0].value.as < IR::StatOrDecl* > ()) yylhs.value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
        }
#line 4802 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 212: // table_declaration: TABLE ID "(" param_list ")" "{" table_property_list "}"
#line 1388 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                  {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[7].location+yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), yystack_[4].value.as < IR::ParameterList* > (), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4810 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 213: // table_declaration: TABLE ID "{" table_property_list "}"
#line 1391 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                               {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[4].location+yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), new IR::ParameterList(), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4818 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 214: // table_declaration: CLASS ID "(" param_list ")" "{" table_property_list "}"
#line 1394 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                  {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[7].location+yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), yystack_[4].value.as < IR::ParameterList* > (), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4826 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 215: // table_declaration: CLASS ID "{" table_property_list "}"
#line 1397 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                               {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[4].location+yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), new IR::ParameterList(), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4834 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 216: // typedef_declaration: TYPEDEF type_ref ID
#line 1410 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto id = IR::ID(yystack_[0].location, *yystack_[0].value.as < IR::ID* > ());
                yylhs.value.as < IR::Type_Typedef* > () = new IR::Type_Typedef(yystack_[2].location, id, yystack_[1].value.as < const IR::Type* > ());
        }
#line 4843 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 217: // enumerator: ID
#line 1417 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < P4::P5::EnumItem* > () = new P4::P5::EnumItem(yystack_[0].location, yystack_[0].value.as < IR::ID* > (), nullptr);
        }
#line 4851 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 218: // enumerator: ID "=" expression
#line 1421 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < P4::P5::EnumItem* > () = new P4::P5::EnumItem(yystack_[2].location + yystack_[0].location, yystack_[2].value.as < IR::ID* > (), yystack_[0].value.as < IR::Expression* > ());
        }
#line 4859 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 219: // enumerator_list: enumerator
#line 1426 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4874 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 220: // enumerator_list: enumerator_list "," enumerator
#line 1436 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4891 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 221: // enum_declaration: ENUM ID "{" enumerator_list "}"
#line 1451 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                const IR::Type* underlying = IR::Type_Bits::get(32, false);
                yylhs.value.as < IR::Type_Declaration* > () = new IR::Type_SerEnum(*yystack_[3].value.as < IR::ID* > (), underlying, *yystack_[1].value.as < IR::IndexedVector<IR::SerEnumMember>* > ());
        }
#line 4900 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 222: // struct_union_type_declaration: STRUCT ID "{" struct_field_list "}"
#line 1458 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Type_Struct* > () = new IR::Type_Struct(yystack_[3].location + yystack_[0].location, *yystack_[3].value.as < IR::ID* > (), *yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ());
        }
#line 4908 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 223: // struct_union_type_declaration: UNION ID "{" struct_field_list "}"
#line 1462 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto st = new IR::Type_Struct(yystack_[3].location + yystack_[0].location, *yystack_[3].value.as < IR::ID* > (), *yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ());
                st->annotations.push_back(new IR::Annotation("union", {}));
                yylhs.value.as < IR::Type_Struct* > () = st;
        }
#line 4918 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 224: // type_declaration: struct_union_type_declaration ";"
#line 1470 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            { yylhs.value.as < IR::Type_Declaration* > () = yystack_[1].value.as < IR::Type_Struct* > (); }
#line 4924 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 225: // type_declaration: enum_declaration ";"
#line 1471 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                               { yylhs.value.as < IR::Type_Declaration* > () = yystack_[1].value.as < IR::Type_Declaration* > (); }
#line 4930 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 226: // type_declaration: typedef_declaration ";"
#line 1472 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   { yylhs.value.as < IR::Type_Declaration* > () = yystack_[1].value.as < IR::Type_Typedef* > (); }
#line 4936 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 227: // function_declaration: type_ref ID "(" param_list ")" action_compound_statement
#line 1476 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring funcName = yystack_[4].value.as < IR::ID* > ()->name;  // ID* -> cstring
                auto funcType = new IR::Type_Method(yystack_[5].location + yystack_[1].location, yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::ParameterList* > (), funcName);
                yylhs.value.as < IR::Function* > () = new IR::Function(yystack_[4].location + yystack_[0].location, funcName, funcType, yystack_[0].value.as < IR::BlockStatement* > ());
        }
#line 4946 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 229: // declaration: annotations constant_declaration
#line 1494 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Constant* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Declaration_Constant* > ();
        }
#line 4955 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 230: // declaration: annotations ";"
#line 1498 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          {
                // Standalone annotation statement (e.g. @u_version(...);).
                // Ignore it completely and keep parsing.
                yylhs.value.as < IR::Node* > () = nullptr;
        }
#line 4965 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 231: // declaration: annotations type_declaration
#line 1504 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Type_Declaration* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Type_Declaration* > ();
        }
#line 4974 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 232: // declaration: annotations header_declaration
#line 1509 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Declaration* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Declaration* > ();
        }
#line 4983 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 233: // declaration: annotations table_declaration
#line 1514 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::P5Table* > ();
        }
#line 4991 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 235: // declaration: annotations variable_declaration
#line 1519 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Variable* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Declaration_Variable* > ();
        }
#line 5000 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 236: // declaration: annotations function_declaration
#line 1524 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Function* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Function* > ();
        }
#line 5009 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 237: // declaration_list: declaration
#line 1531 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Vector<IR::Node>* > () = new IR::IndexedVector<IR::Node>();
                if (yystack_[0].value.as < IR::Node* > ()) yylhs.value.as < IR::Vector<IR::Node>* > ()->push_back(yystack_[0].value.as < IR::Node* > ());
        }
#line 5018 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 238: // declaration_list: declaration_list declaration
#line 1536 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                if (yystack_[0].value.as < IR::Node* > ()) yystack_[1].value.as < IR::Vector<IR::Node>* > ()->push_back(yystack_[0].value.as < IR::Node* > ());
                yylhs.value.as < IR::Vector<IR::Node>* > () = yystack_[1].value.as < IR::Vector<IR::Node>* > ();
        }
#line 5027 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 240: // input: input declaration
#line 1544 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                             {
                if (yystack_[0].value.as < IR::Node* > ()) driver.nodes->push_back(yystack_[0].value.as < IR::Node* > ()->getNode());
        }
#line 5035 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 241: // input: input ";"
#line 1547 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                           {}
#line 5041 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;


#line 5045 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"

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


  const short P5Parser::yypact_ninf_ = -427;

  const short P5Parser::yytable_ninf_ = -146;

  const short
  P5Parser::yypact_[] =
  {
    -427,   169,    75,  -427,  -427,  -427,   592,  -427,   -37,  -427,
     307,   -37,   -37,   339,   -37,   -37,   307,   -37,   362,    32,
    -427,   307,   -37,  -427,   300,  -427,   -37,  -427,  -427,  -427,
    -427,    39,   357,   389,  -427,  -427,  -427,   484,   -37,  -427,
     558,   445,    33,   492,   517,   -37,   539,    33,   -37,   -37,
     561,   -37,   -37,   180,  -427,  -427,  -427,  -427,   259,    51,
     367,   360,   -37,   259,   259,   259,  -427,  -427,  -427,   540,
    -427,  -427,    67,  -427,   318,  -427,  -427,  -427,  -427,   186,
     514,    98,   367,   360,  -427,   311,   367,   259,   259,  -427,
     416,    27,   213,   213,   213,   213,   564,  -427,  -427,   326,
     516,   415,   460,   254,   531,   525,   529,   536,   288,  -427,
     562,   438,   259,   259,   259,    88,  -427,   444,   578,   567,
     569,   521,  -427,    92,   570,  -427,   344,    95,   405,   376,
      27,   259,  -427,   259,   -37,  -427,   581,   119,  -427,  -427,
    -427,   583,   585,  -427,  -427,   259,  -427,   454,    96,   -37,
    -427,   455,   374,   176,   289,   588,   259,   431,  -427,  -427,
    -427,  -427,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   259,
     213,  -427,  -427,   259,   385,   188,    42,     7,   593,  -427,
    -427,   594,   595,    47,   -37,   660,  -427,  -427,  -427,   553,
    -427,  -427,  -427,   259,  -427,   -37,  -427,  -427,  -427,   259,
     318,   562,  -427,   456,   383,  -427,  -427,  -427,    22,    26,
     -37,  -427,  -427,  -427,   391,   603,  -427,   577,   606,   177,
    -427,    27,   213,   199,   259,  -427,  -427,  -427,   326,   326,
     516,   516,   415,   415,   415,   415,   460,   460,   254,   531,
     525,   529,   396,   536,   562,   598,  -427,   530,   -37,   161,
     360,  -427,    59,   458,   546,  -427,   259,   256,   259,  -427,
     259,  -427,   259,   259,   259,   259,   259,   259,   259,   259,
    -427,   562,  -427,   394,  -427,   259,  -427,   259,  -427,   613,
    -427,   615,   267,   571,   360,  -427,  -427,  -427,   259,   259,
    -427,    24,  -427,  -427,   213,   259,   259,   427,   617,   259,
     159,   332,   318,  -427,   622,  -427,   625,    57,   546,   626,
     628,   467,   562,   562,   562,   562,   562,   562,   562,   562,
     562,   562,  -427,  -427,   397,   629,  -427,   633,  -427,   259,
     259,  -427,  -427,   203,   639,   399,   241,  -427,   252,    62,
     638,   259,  -427,   562,  -427,  -427,    59,  -427,  -427,   635,
     237,  -427,  -427,  -427,  -427,   568,  -427,  -427,  -427,   227,
     643,   247,   647,   414,   263,  -427,  -427,   156,  -427,  -427,
     565,  -427,   562,   194,  -427,   651,  -427,   469,   653,   273,
    -427,   608,  -427,   657,   659,    25,   666,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,   620,   624,
    -427,   632,   640,   128,  -427,   259,  -427,   259,   259,   663,
    -427,  -427,   675,  -427,   -37,  -427,  -427,   609,  -427,   259,
    -427,   683,   175,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
     259,  -427,   266,    56,   294,  -427,   524,   687,  -427,   688,
     642,   692,   125,   284,    41,  -427,   259,  -427,   470,   417,
    -427,  -427,   259,   259,   691,   533,   196,  -427,   693,  -427,
    -427,   259,   259,   259,  -427,  -427,  -427,   473,   479,   695,
     646,   562,  -427,   533,  -427,  -427,  -427,  -427,   293,   259,
     684,  -427,  -427,   304,   328,   276,   645,   696,   655,  -427,
    -427,   447,  -427,  -427,   542,   703,  -427,  -427,    27,  -427,
     418,  -427,    37,  -427,   705,  -427,  -427,   707,  -427,   259,
     698,  -427,    77,  -427,   259,   700,  -427,  -427,    63,  -427,
     543,    30,  -427,  -427,   548,   157,    66,  -427,  -427,    30,
    -427,   198,  -427,  -427,  -427,  -427
  };

  const unsigned char
  P5Parser::yydefact_[] =
  {
     239,     0,    58,     1,     2,   241,     0,   240,     0,   230,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,     0,     4,    63,    59,     0,   229,   232,   235,
     233,     0,     0,    62,   231,   236,    58,    56,     0,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,   225,   224,   234,     0,     0,
      58,    58,     0,     0,     0,     0,     3,     5,     8,    68,
       7,    12,     0,    72,     6,    58,    58,   216,    58,     0,
       0,     0,    58,    58,    64,     0,    58,     0,     0,    94,
       0,     0,     0,     0,     0,     0,    14,    19,    21,    25,
      28,    31,    36,    39,    41,    43,    45,    47,    49,    51,
      54,     0,     0,     0,     0,     0,   131,     0,     0,     0,
       0,     0,   210,    58,   217,   219,     0,     0,     0,     0,
       0,   134,    61,     0,     0,   237,    58,     0,    85,    86,
      87,    58,    58,    60,   100,     0,    92,     0,    58,     0,
      65,     0,     0,     0,    68,     0,     0,     0,    18,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    57,     0,     0,     0,     0,     0,     0,    58,
      58,     0,     0,    68,     0,   116,   208,   209,   149,     0,
     207,   215,   211,     0,   221,     0,     9,    11,    10,     0,
      71,   133,   135,     0,     0,    69,   228,   238,     0,     0,
       0,   222,    88,   223,     0,     0,   213,     0,     0,     0,
      95,     0,     0,     0,     0,    22,    23,    24,    26,    27,
      30,    29,    33,    32,    35,    34,    37,    38,    40,    42,
      44,    46,     0,    48,    55,     0,    89,     0,     0,   124,
      58,   132,     0,     0,   180,   174,   134,     0,     0,   160,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
     162,   218,   220,     0,    13,     0,    70,     0,    58,     0,
      58,     0,     0,     0,    58,    66,   174,   227,     0,     0,
      96,    68,    20,    53,     0,     0,     0,   126,     0,     0,
      58,    68,   116,   118,     0,    58,     0,    58,   189,     0,
      58,     0,   150,   152,   151,   153,   154,   155,   156,   157,
     159,   158,    74,   136,     0,    58,    58,    58,    58,     0,
       0,    75,    93,    58,    58,     0,     0,    50,     0,     0,
       0,     0,   129,   125,   214,    58,     0,    58,   203,     0,
       0,   181,   190,   204,   205,     0,   175,   117,    73,     0,
      58,     0,    58,     0,     0,   212,   176,     0,    97,    90,
       0,   128,   127,     0,   201,    58,   119,     0,     0,     0,
     173,     0,    58,     0,     0,     0,     0,   164,   163,   170,
     171,   168,   166,   169,   167,   172,   165,    79,     0,   222,
      82,     0,   223,     0,    76,     0,    98,     0,     0,     0,
     206,   202,     0,   174,     0,   179,   123,     0,    58,     0,
     104,     0,     0,   122,   121,    58,    81,    80,    84,    83,
       0,    77,     0,     0,   106,   108,     0,   200,    58,    58,
       0,     0,     0,     0,     0,    58,   134,   103,     0,     0,
      99,    91,     0,     0,   198,   194,     0,   186,    58,   177,
     178,     0,     0,     0,    58,   102,   105,     0,     0,     0,
       0,   107,   109,   194,   191,   192,   193,   195,     0,     0,
       0,   188,   187,     0,     0,     0,   138,     0,     0,   146,
      78,     0,   199,   196,     0,   185,   137,    58,     0,    58,
       0,   101,     0,   197,   183,   180,   141,     0,   139,     0,
       0,   114,     0,   148,     0,     0,   147,   180,    58,    58,
       0,   113,   120,   115,     0,    58,    58,   184,   140,   111,
     112,    58,   144,   182,   110,   142
  };

  const short
  P5Parser::yypgoto_[] =
  {
    -427,  -427,  -427,     5,  -427,  -427,   461,  -427,    -6,   354,
     343,   345,   355,   544,   541,   545,   547,   538,  -427,   419,
     275,   656,  -427,    -2,    45,  -427,   -86,  -427,  -427,  -133,
     -76,    -5,  -427,     1,  -426,  -427,   258,  -212,   202,  -427,
    -244,  -332,  -427,  -427,  -427,  -185,    -7,   441,  -256,  -427,
    -427,  -427,  -427,  -427,  -427,   219,  -118,  -380,  -273,   363,
    -427,  -168,   261,  -427,  -427,   412,  -411,   249,   348,  -427,
    -109,   -77,  -427,  -427,   534,  -427,  -427,   728,  -427,  -427,
    -427,   -12,  -427,  -427
  };

  const short
  P5Parser::yydefgoto_[] =
  {
       0,     1,    68,    69,    70,    71,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     444,   111,    25,   137,   194,    73,    74,   138,   139,   140,
     141,   484,    28,   485,   433,   454,   445,   446,   521,   522,
     198,   263,   434,   399,   400,   116,   117,   212,   213,   401,
     402,   403,   526,   512,   404,   199,   486,   366,   320,   297,
     361,   317,   467,   468,   318,   319,   487,   488,   384,   385,
     122,   123,    30,    31,   125,   126,    32,    39,    34,    35,
      36,     7,   136,     2
  };

  const short
  P5Parser::yytable_[] =
  {
       6,    27,   142,   200,   261,   157,   148,    29,   222,   222,
     321,    24,   427,    37,   202,    24,    40,    41,   313,    43,
      44,    24,    46,   344,    57,   387,    24,    50,   476,   288,
     -64,    53,   430,   290,     6,   195,   156,   430,    63,   202,
      64,   130,    65,    59,   210,   523,   258,    23,   430,   475,
      77,    26,   266,    80,    81,    38,    84,    85,   115,   121,
     112,    45,   181,   135,   231,   358,    49,   124,   156,   113,
       8,   537,   131,     6,   543,   147,   181,   503,     4,   151,
     115,   121,   181,    52,   115,   532,   158,   159,   160,   161,
     503,    23,    54,   524,   496,   154,   525,   431,    48,     8,
     201,   206,   132,   458,   226,   540,    23,   145,   -64,    23,
      23,    23,   386,   544,    23,   181,   196,    23,    66,    67,
      24,   121,   197,   477,   217,    23,   193,   516,     5,   518,
       8,   -63,   257,   519,     6,   155,   520,   440,   359,   215,
     114,   472,    24,    23,   359,   210,   121,   359,   461,   538,
     449,   146,   380,    13,   227,   542,   235,   236,   237,    15,
     187,   545,    17,    18,   118,  -145,    20,   354,   118,     3,
     308,   119,    23,   120,   415,   119,   312,   120,   473,   309,
     456,   441,   220,   310,    13,    86,   298,   115,   262,    87,
     218,   131,   259,   219,    18,   299,   181,    20,    88,   267,
     478,   202,   222,    23,   222,     8,  -143,     8,   181,   416,
     124,   375,   335,  -145,   337,   209,  -145,   343,    90,   181,
      64,   143,    65,   289,   291,   292,   302,    92,   457,   230,
     300,   118,    93,    89,   202,    94,   301,   222,   119,   222,
     120,   256,    90,   452,    64,    95,    65,   405,     8,    91,
     418,    92,   489,   419,  -143,   490,    93,  -143,   121,    94,
     370,   181,   372,   307,    90,    87,    64,   311,    65,    95,
     312,    91,   181,    92,    88,   118,   339,   504,    93,   195,
     407,    94,   119,   181,   120,   340,   181,   173,   174,   424,
     474,    95,   121,   181,   378,   -63,   181,    23,    66,    67,
     410,   502,   156,   179,   181,   379,   231,   530,   121,    89,
     506,    23,   534,   356,   181,   360,   414,    51,   365,   460,
     341,    23,    66,    67,   181,    52,   425,   133,   149,   508,
     134,    23,   180,   110,   507,   462,    52,   266,   127,   110,
     129,   121,   365,    23,    66,    67,   150,   528,   181,   130,
      10,   162,   204,   383,   163,   262,   164,   205,    13,   536,
     397,   311,   152,   153,    15,   127,   398,    17,    18,    19,
     193,    20,    13,  -130,   408,    42,   411,    23,    15,   195,
    -130,    17,    18,   383,   229,    20,   208,   184,   185,   186,
     365,    23,   209,   286,   181,   255,   181,   195,    47,   287,
     432,   293,   195,   181,   332,   181,   211,   368,   214,   377,
      55,   181,   304,   207,   181,   195,   181,   181,   183,   181,
     224,    90,   195,    64,   413,    65,   115,   480,    91,   450,
      92,   233,   118,   262,   181,    93,   350,   181,    94,   119,
     133,   120,    56,   134,   182,   351,   466,   365,    95,   234,
     188,   183,    62,   262,   252,   513,   156,   189,   254,   432,
     225,   228,   284,   167,   314,   168,   466,   189,   189,   285,
     193,   315,   365,   367,   519,   422,   479,   520,   281,   497,
     285,    13,   315,   315,   283,   498,   315,    15,   193,    58,
      17,    18,   285,   193,    20,   169,   170,   171,   172,    75,
      23,    66,    67,    72,    10,   365,   193,   365,    79,   303,
     240,   241,    13,   311,   242,   243,   244,   245,    15,   238,
     239,    17,    18,    19,    76,    20,   360,   365,   246,   247,
     156,    23,     8,   365,   360,   165,   432,   463,   166,   365,
     464,   211,   156,   322,   432,   323,    78,   324,   325,   326,
     327,   328,   329,   330,   331,   463,   463,   130,   514,   539,
     211,   463,   334,    60,   541,    61,    82,   144,    83,   131,
     175,   176,   177,   345,   346,   296,   178,   156,    10,     8,
     348,   349,   181,   190,   353,   191,    13,   192,   203,   216,
      10,   221,    15,   223,   232,    17,    18,    19,    13,    20,
     260,   264,   265,     8,    15,    23,   280,    17,    18,    19,
     294,    20,   295,   296,   373,   374,   305,    23,   316,   306,
     336,   390,   338,   391,   342,    10,   382,   352,   392,   355,
     357,   393,   394,    13,   363,   389,   364,   369,   395,    15,
     396,   371,    17,    18,    19,     9,    20,   376,   381,    10,
      11,   409,    23,   388,    12,   412,   417,    13,    14,   420,
     423,   426,   428,    15,   429,    16,    17,    18,    19,   133,
      20,   435,   134,   436,    21,    22,    23,   437,   268,   447,
     269,   270,   448,   271,   272,   438,   451,   273,   455,   274,
     442,   275,   443,   439,   465,   470,   469,   471,   483,   500,
     505,   491,   499,   510,   453,   276,   509,   277,   511,   278,
     515,   279,   527,   529,   531,   459,   535,   249,   253,   248,
     128,   482,   250,   347,   533,   251,   333,   517,   406,   492,
     362,   211,   501,   421,    33,     0,     0,   481,     0,   282,
       0,     0,     0,     0,     0,     0,   493,   494,   495
  };

  const short
  P5Parser::yycheck_[] =
  {
       2,     6,    78,   121,   189,    91,    83,     6,   141,   142,
     266,     6,   392,     8,   123,    10,    11,    12,   262,    14,
      15,    16,    17,   296,    36,   357,    21,    22,   454,     7,
       6,    26,     7,     7,    36,   121,     9,     7,     5,   148,
       7,    17,     9,    38,   130,     8,    39,    84,     7,     8,
      45,     6,     5,    48,    49,    10,    51,    52,    60,    61,
       9,    16,    20,    75,    17,     8,    21,    62,     9,    18,
      11,     8,     5,    75,     8,    82,    20,   488,     3,    86,
      82,    83,    20,    36,    86,     8,    92,    93,    94,    95,
     501,    84,    53,    56,   474,    90,    59,    72,    66,    11,
       8,     6,    35,   435,     8,   531,    84,     9,    84,    84,
      84,    84,   356,   539,    84,    20,   121,    84,    85,    86,
     115,   123,   121,   455,   136,    84,   121,   507,    53,   509,
      11,    84,    90,    56,   136,    90,    59,     9,    81,   134,
      89,    16,   137,    84,    81,   231,   148,    81,    92,   529,
     423,    53,    90,    65,   149,   535,   162,   163,   164,    71,
     115,   541,    74,    75,    72,     8,    78,     8,    72,     0,
       9,    79,    84,    81,    18,    79,   262,    81,    53,    18,
       5,    53,   137,   260,    65,     5,     9,   189,   190,     9,
      71,     5,   187,    74,    75,    18,    20,    78,    18,   194,
     456,   310,   335,    84,   337,    11,     8,    11,    20,    53,
     205,     8,   288,    56,   290,    16,    59,   294,     5,    20,
       7,    35,     9,   218,   219,   220,   232,    14,    53,    53,
      53,    72,    19,    53,   343,    22,   231,   370,    79,   372,
      81,    53,     5,   428,     7,    32,     9,   365,    11,    12,
      56,    14,    56,    59,    56,    59,    19,    59,   260,    22,
     336,    20,   338,   258,     5,     9,     7,   262,     9,    32,
     356,    12,    20,    14,    18,    72,     9,   489,    19,   365,
      53,    22,    79,    20,    81,    18,    20,    33,    34,    16,
       6,    32,   294,    20,    53,     6,    20,    84,    85,    86,
      53,     8,     9,    15,    20,    53,    17,   519,   310,    53,
       6,    84,   524,   315,    20,   317,    53,    17,   320,    53,
      53,    84,    85,    86,    20,    36,    53,     9,    17,    53,
      12,    84,    44,    58,     6,    41,    36,     5,    63,    64,
      65,   343,   344,    84,    85,    86,    35,   515,    20,    17,
      57,    25,     8,   355,    28,   357,    30,    13,    65,   527,
     365,   356,    87,    88,    71,    90,   365,    74,    75,    76,
     365,    78,    65,     6,   369,    36,   371,    84,    71,   465,
      13,    74,    75,   385,    10,    78,    10,   112,   113,   114,
     392,    84,    16,    10,    20,    10,    20,   483,    36,    16,
     395,    10,   488,    20,    10,    20,   131,    10,   133,    10,
      53,    20,    16,     8,    20,   501,    20,    20,    13,    20,
     145,     5,   508,     7,    10,     9,   428,    10,    12,   424,
      14,   156,    72,   435,    20,    19,     9,    20,    22,    79,
       9,    81,    53,    12,     6,    18,   448,   449,    32,    18,
       6,    13,     7,   455,   179,     8,     9,    13,   183,   454,
       6,     6,     6,    48,     6,    50,   468,    13,    13,    13,
     465,    13,   474,     6,    56,     6,     6,    59,   203,     6,
      13,    65,    13,    13,   209,     6,    13,    71,   483,     5,
      74,    75,    13,   488,    78,    35,    36,    37,    38,     7,
      84,    85,    86,    42,    57,   507,   501,   509,    47,   234,
     167,   168,    65,   508,   169,   170,   171,   172,    71,   165,
     166,    74,    75,    76,     7,    78,   528,   529,   173,   174,
       9,    84,    11,   535,   536,    19,   531,    13,    22,   541,
      16,   266,     9,   268,   539,   270,     7,   272,   273,   274,
     275,   276,   277,   278,   279,    13,    13,    17,    16,    16,
     285,    13,   287,     5,    16,     7,     5,    53,     7,     5,
      39,    46,    43,   298,   299,     7,    40,     9,    57,    11,
     305,   306,    20,     5,   309,    18,    65,    18,    18,     8,
      57,     8,    71,     8,     6,    74,    75,    76,    65,    78,
       7,     7,     7,    11,    71,    84,    53,    74,    75,    76,
       7,    78,    35,     7,   339,   340,    18,    84,    72,    89,
       7,    53,     7,    55,    53,    57,   351,    10,    60,     7,
       5,    63,    64,    65,     8,   360,     8,     8,    70,    71,
      72,     8,    74,    75,    76,    53,    78,     8,    10,    57,
      58,     8,    84,    18,    62,     8,    91,    65,    66,     8,
       7,    53,     5,    71,     5,    73,    74,    75,    76,     9,
      78,     5,    12,    53,    82,    83,    84,    53,    18,    16,
      20,    21,     7,    23,    24,    53,    77,    27,     5,    29,
     415,    31,   417,    53,     7,    53,     8,     5,     7,    53,
      16,     8,     7,     7,   429,    45,    61,    47,    53,    49,
       7,    51,     7,     6,    16,   440,    16,   176,   180,   175,
      64,   463,   177,   304,   522,   178,   285,   508,   365,   468,
     318,   456,   483,   385,     6,    -1,    -1,   462,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,   471,   472,   473
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
     119,   113,   140,   141,   113,    96,     8,   174,    71,    74,
     117,     8,   122,     8,   113,     6,     8,    96,     6,    10,
      53,    17,     6,   113,    18,   101,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   105,   105,   106,   107,
     108,   109,   113,   110,   113,    10,    53,    90,    39,    96,
       7,   138,   116,   134,     7,     7,     5,    96,    18,    20,
      21,    23,    24,    27,    29,    31,    45,    47,    49,    51,
      53,   113,   167,   113,     6,    13,    10,    16,     7,    96,
       7,    96,    96,    10,     7,    35,     7,   152,     9,    18,
      53,    96,   101,   113,    16,    18,    89,    96,     9,    18,
     164,    96,   119,   133,     6,    13,    72,   154,   157,   158,
     151,   141,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,    10,   140,   113,   123,     7,   123,     7,     9,
      18,    53,    53,   164,   151,   113,   113,   112,   113,   113,
       9,    18,    10,   113,     8,     7,   116,     5,     8,    81,
     116,   153,   158,     8,     8,   116,   150,     6,    10,     8,
     123,     8,   123,   113,   113,     8,     8,    10,    53,    53,
      90,    10,   113,   116,   161,   162,   133,   134,    18,   113,
      53,    55,    60,    63,    64,    70,    72,   124,   126,   136,
     137,   142,   143,   144,   147,   149,   152,    53,    96,     8,
      53,    96,     8,    10,    53,    18,    53,    91,    56,    59,
       8,   161,     6,     7,    16,    53,    53,   150,     5,     5,
       7,    72,    96,   127,   135,     5,    53,    53,    53,    53,
       9,    53,   113,   113,   113,   129,   130,    16,     7,   151,
      96,    77,   138,   113,   128,     5,     5,    53,   134,   113,
      53,    92,    41,    13,    16,     7,   116,   155,   156,     8,
      53,     5,    16,    53,     6,     8,   127,   134,   141,     6,
      10,   113,   129,     7,   124,   126,   149,   159,   160,    56,
      59,     8,   155,   113,   113,   113,   150,     6,     6,     7,
      53,   160,     8,   159,   130,    16,     6,     6,    53,    61,
       7,    53,   146,     8,    16,     7,   150,   148,   150,    56,
      59,   131,   132,     8,    56,    59,   145,     7,   154,     6,
     130,    16,     8,   131,   130,    16,   154,     8,   150,    16,
     127,    16,   150,     8,   127,   150
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
     118,   118,   119,   119,   119,   120,   120,   120,   120,   121,
     121,   121,   121,   121,   121,   122,   122,   123,   123,   124,
     124,   124,   125,   125,   126,   126,   126,   126,   126,   126,
     126,   127,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   131,   131,   132,   132,   133,   133,   134,   134,
     135,   136,   136,   137,   138,   138,   138,   138,   138,   138,
     139,   139,   139,   140,   141,   141,   141,   142,   143,   143,
     144,   144,   145,   145,   145,   145,   146,   146,   147,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   149,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   151,   151,   152,   153,   153,   153,
     154,   154,   155,   155,   155,   155,   156,   156,   157,   158,
     158,   159,   159,   159,   160,   160,   160,   161,   161,   161,
     161,   162,   162,   163,   163,   163,   163,   163,   163,   163,
     164,   164,   165,   165,   165,   165,   166,   167,   167,   168,
     168,   169,   170,   170,   171,   171,   171,   172,   173,   174,
     174,   174,   174,   174,   174,   174,   174,   175,   175,   176,
     176,   176
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
       4,     3,     1,     6,     5,     4,     6,     7,    10,     6,
       7,     7,     6,     7,     7,     1,     1,     1,     2,     6,
       9,    12,     4,     7,     3,     5,     6,     8,     9,    11,
       4,     5,     3,     2,     0,     2,     1,     3,     1,     3,
       4,     3,     3,     2,     1,     2,     1,     4,     2,     4,
       7,     2,     2,     2,     3,     5,     4,     6,     6,     5,
       0,     1,     3,     1,     0,     1,     3,     6,     5,     7,
       9,     7,     4,     3,     3,     2,     0,     2,     7,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     0,     2,     3,     5,     5,     3,
       0,     2,     7,     4,     6,     3,     1,     2,     7,     1,
       2,     1,     1,     1,     0,     1,     2,     7,     4,     6,
       3,     1,     2,     5,     5,     5,     7,     2,     2,     2,
       1,     2,     8,     5,     8,     5,     3,     1,     3,     1,
       3,     5,     5,     5,     2,     2,     2,     6,     5,     2,
       2,     2,     2,     2,     3,     2,     2,     1,     2,     0,
       2,     2
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
     549,   550,   555,   556,   557,   560,   567,   575,   583,   594,
     603,   612,   621,   632,   642,   654,   655,   659,   665,   679,
     683,   688,   696,   700,   706,   707,   708,   712,   716,   721,
     726,   735,   741,   742,   748,   751,   757,   758,   761,   767,
     774,   785,   791,   802,   810,   815,   822,   825,   832,   838,
     845,   850,   851,   854,   862,   869,   876,   883,   890,   900,
     912,   913,   918,   926,   929,   930,   936,   944,   960,   966,
     977,   997,  1035,  1045,  1051,  1060,  1067,  1068,  1074,  1079,
    1086,  1089,  1093,  1097,  1101,  1105,  1109,  1113,  1117,  1121,
    1125,  1130,  1137,  1140,  1144,  1148,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1165,  1166,  1172,  1181,  1186,  1193,
    1201,  1204,  1210,  1219,  1230,  1239,  1251,  1256,  1262,  1269,
    1274,  1281,  1282,  1283,  1286,  1289,  1294,  1300,  1310,  1315,
    1325,  1332,  1338,  1346,  1351,  1356,  1361,  1364,  1367,  1370,
    1376,  1380,  1388,  1391,  1394,  1397,  1409,  1416,  1420,  1426,
    1436,  1450,  1457,  1461,  1470,  1471,  1472,  1475,  1483,  1493,
    1498,  1503,  1508,  1513,  1517,  1518,  1523,  1530,  1535,  1543,
    1544,  1547
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
#line 5941 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"

#line 1550 "/root/p4c/frontends/parsers/p5/p5parser.ypp"


namespace P4 {

void P5::P5Parser::error(const Util::SourceInfo& location,
                         const std::string& message) {
    driver.onParseError(location, message);
}

}  // namespace P4
