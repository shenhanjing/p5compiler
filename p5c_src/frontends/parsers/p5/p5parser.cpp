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
#line 145 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
      case symbol_kind::S_method_call: // method_call
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

      case symbol_kind::S_method_args: // method_args
        value.YY_MOVE_OR_COPY< P4::P5::MethodArgs* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< UnparsedConstant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_ref_explicit: // type_ref_explicit
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
      case symbol_kind::S_method_call: // method_call
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

      case symbol_kind::S_method_args: // method_args
        value.move< P4::P5::MethodArgs* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< UnparsedConstant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_ref_explicit: // type_ref_explicit
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
      case symbol_kind::S_method_call: // method_call
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

      case symbol_kind::S_method_args: // method_args
        value.copy< P4::P5::MethodArgs* > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< UnparsedConstant > (that.value);
        break;

      case symbol_kind::S_type_ref_explicit: // type_ref_explicit
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
      case symbol_kind::S_method_call: // method_call
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

      case symbol_kind::S_method_args: // method_args
        value.move< P4::P5::MethodArgs* > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< UnparsedConstant > (that.value);
        break;

      case symbol_kind::S_type_ref_explicit: // type_ref_explicit
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
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1264 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_CASE: // CASE
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1270 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_CONST: // CONST
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1276 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_CLASS: // CLASS
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1282 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_DEFAULT: // DEFAULT
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1288 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_DO: // DO
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1294 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1300 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_ENUM: // ENUM
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1306 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1312 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1318 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_INT: // INT
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1324 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_NAMESPACE: // NAMESPACE
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1330 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_PRIVATE: // PRIVATE
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1336 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_PROTECTED: // PROTECTED
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1342 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_PUBLIC: // PUBLIC
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1348 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1354 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_STRUCT: // STRUCT
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1360 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_SWITCH: // SWITCH
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1366 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_TYPEDEF: // TYPEDEF
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1372 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_UNION: // UNION
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1378 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_UINT: // UINT
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1384 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_USING: // USING
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1390 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1396 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_VOID: // VOID
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1402 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_KEY: // KEY
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1408 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_SIZE: // SIZE
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1414 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_CONTROL_PARAMETERS: // CONTROL_PARAMETERS
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1420 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_HEADER: // HEADER
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1426 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_TABLE: // TABLE
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1432 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1438 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < cstring > (); }
#line 1444 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_INTEGER: // INTEGER
#line 169 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yyoutput << yysym.value.template as < UnparsedConstant > (); }
#line 1450 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_string_lit: // string_lit
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::StringLiteral* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1463 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::ID* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1476 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_const_value: // const_value
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Constant* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1489 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_primary_expression: // primary_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1502 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_postfix_expression: // postfix_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1515 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_method_call: // method_call
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1528 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_method_args: // method_args
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < P4::P5::MethodArgs* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1541 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_unary_expression: // unary_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1554 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_cast_expression: // cast_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1567 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1580 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_additive_expression: // additive_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1593 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_shift_expression: // shift_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1606 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_relational_expression: // relational_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1619 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_equality_expression: // equality_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1632 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_and_expression: // and_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1645 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1658 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1671 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1684 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_logical_or_expression: // logical_or_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1697 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_conditional_expression: // conditional_expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1710 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_expression: // expression
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1723 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_expression_list: // expression_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::Expression>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1736 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_annotation: // annotation
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Annotation* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1749 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_annotations: // annotations
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::Annotation>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1762 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_type_ref_explicit: // type_ref_explicit
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < const IR::Type* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1775 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_type_ref: // type_ref
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < const IR::Type* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1788 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_field_ref_no_slice: // field_ref_no_slice
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1801 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_field_ref: // field_ref
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1814 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_field_dec: // field_dec
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::StructField* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1827 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_anonymous_struct_union_dec: // anonymous_struct_union_dec
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::StructField* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1840 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_struct_field_dec: // struct_field_dec
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::StructField* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1853 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_struct_field_list: // struct_field_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::IndexedVector<IR::StructField>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1866 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_constant_declaration: // constant_declaration
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Declaration_Constant* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1879 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_header_declaration: // header_declaration
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Declaration* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1892 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Declaration_Variable* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1905 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_return_value_type: // return_value_type
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1918 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_return_value_type_list: // return_value_type_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::BlockStatement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1931 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_value_masked_or_set: // value_masked_or_set
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1944 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_value_list: // value_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::Expression>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1957 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_case_entry: // case_entry
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::SwitchCase* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1970 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_case_list: // case_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::SwitchCase>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1983 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_field_ref_or_func: // field_ref_or_func
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1996 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_select_exp: // select_exp
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::ListExpression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2009 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_return_select_statement: // return_select_statement
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2022 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_return_statement: // return_statement
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2035 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_break_statement: // break_statement
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2048 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_parameter: // parameter
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Parameter* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2061 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_param_list: // param_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::ParameterList* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2074 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_arg: // arg
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Argument* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2087 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_arg_list: // arg_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::Argument>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2100 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_do_while_statement: // do_while_statement
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2113 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_conditional_statement: // conditional_statement
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2126 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_for_loop_statement: // for_loop_statement
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2139 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_case: // case
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::SwitchCase* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2152 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_switch_cases: // switch_cases
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::SwitchCase>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2165 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_switch_statement: // switch_statement
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2178 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_assignment_or_call: // assignment_or_call
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2191 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_assignment_or_call_statement: // assignment_or_call_statement
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Statement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2204 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_action_statement: // action_statement
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::StatOrDecl* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2217 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_action_statement_list: // action_statement_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::BlockStatement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2230 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_action_compound_statement: // action_compound_statement
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::BlockStatement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2243 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_key_element: // key_element
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::P5KeyElement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2256 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_key_element_list: // key_element_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::P5KeyElement>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2269 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_key_case_entry: // key_case_entry
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::P5KeyCase* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2282 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_key_case_list: // key_case_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::P5KeyCase>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2295 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_key_switch_entry: // key_switch_entry
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::P5KeySwitch* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2308 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_key_switch_list: // key_switch_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::P5KeySwitch>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2321 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_program_selection_statement: // program_selection_statement
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::StatOrDecl* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2334 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_program_selection_statement_list: // program_selection_statement_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::BlockStatement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2347 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_table_case_entry: // table_case_entry
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::SwitchCase* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2360 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_table_case_list: // table_case_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::SwitchCase>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2373 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_table_property: // table_property
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::StatOrDecl* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2386 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_table_property_list: // table_property_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::BlockStatement* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2399 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_table_declaration: // table_declaration
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::P5Table* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2412 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_typedef_declaration: // typedef_declaration
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Type_Typedef* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2425 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_enumerator: // enumerator
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < P4::P5::EnumItem* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2438 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::IndexedVector<IR::SerEnumMember>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2451 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_enum_declaration: // enum_declaration
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Type_Declaration* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2464 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_struct_union_type_declaration: // struct_union_type_declaration
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Type_Struct* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2477 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_type_declaration: // type_declaration
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Type_Declaration* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2490 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_function_declaration: // function_declaration
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Function* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2503 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_declaration: // declaration
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Node* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2516 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
        break;

      case symbol_kind::S_declaration_list: // declaration_list
#line 170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
    auto val = yysym.value.template as < IR::Vector<IR::Node>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2529 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
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
      case symbol_kind::S_method_call: // method_call
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

      case symbol_kind::S_method_args: // method_args
        yylhs.value.emplace< P4::P5::MethodArgs* > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        yylhs.value.emplace< UnparsedConstant > ();
        break;

      case symbol_kind::S_type_ref_explicit: // type_ref_explicit
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
#line 335 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                    { YYACCEPT; }
#line 3020 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 3: // string_lit: STRING_LITERAL
#line 344 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         { yylhs.value.as < IR::StringLiteral* > () = new IR::StringLiteral(yystack_[0].location, yystack_[0].value.as < cstring > ()); }
#line 3026 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 4: // ID: IDENTIFIER
#line 348 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     { yylhs.value.as < IR::ID* > () = new IR::ID(yystack_[0].location, yystack_[0].value.as < cstring > ()); }
#line 3032 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 5: // const_value: INTEGER
#line 358 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                  { yylhs.value.as < IR::Constant* > () = parseConstant(yystack_[0].location, yystack_[0].value.as < UnparsedConstant > (), 0); }
#line 3038 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 6: // primary_expression: field_ref
#line 361 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3044 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 7: // primary_expression: const_value
#line 362 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Constant* > (); }
#line 3050 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 8: // primary_expression: string_lit
#line 363 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::StringLiteral* > (); }
#line 3056 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 9: // primary_expression: "(" expression ")"
#line 364 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[1].value.as < IR::Expression* > (); }
#line 3062 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 10: // primary_expression: "[" expression "]"
#line 365 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[1].value.as < IR::Expression* > (); }
#line 3068 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 11: // primary_expression: "{" expression_list "}"
#line 366 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = new IR::ListExpression(yystack_[2].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ()); }
#line 3074 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 12: // postfix_expression: primary_expression
#line 370 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3080 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 13: // postfix_expression: method_call
#line 371 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3086 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 14: // method_call: postfix_expression "(" method_args ")"
#line 375 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                 {
            auto margs = yystack_[1].value.as < P4::P5::MethodArgs* > ();
            auto typeArgs = margs->typeArgs ? margs->typeArgs : new IR::Vector<IR::Type>();
            auto args = margs->args ? margs->args : new IR::Vector<IR::Argument>();
            yylhs.value.as < IR::Expression* > () = new IR::MethodCallExpression(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), typeArgs, args);
        }
#line 3097 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 15: // method_args: arg_list
#line 384 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                   {
            yylhs.value.as < P4::P5::MethodArgs* > () = new P4::P5::MethodArgs();
            yylhs.value.as < P4::P5::MethodArgs* > ()->args = yystack_[0].value.as < IR::Vector<IR::Argument>* > ();
        }
#line 3106 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 16: // method_args: type_ref_explicit
#line 388 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            {
            yylhs.value.as < P4::P5::MethodArgs* > () = new P4::P5::MethodArgs();
            yylhs.value.as < P4::P5::MethodArgs* > ()->typeArgs = new IR::Vector<IR::Type>();
            yylhs.value.as < P4::P5::MethodArgs* > ()->typeArgs->push_back(yystack_[0].value.as < const IR::Type* > ());
        }
#line 3116 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 17: // unary_expression: postfix_expression
#line 396 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3122 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 18: // unary_expression: "+" cast_expression
#line 397 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3128 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 19: // unary_expression: "-" cast_expression
#line 398 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = new IR::Neg(yystack_[1].location, yystack_[0].value.as < IR::Expression* > ()); }
#line 3134 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 20: // unary_expression: "!" cast_expression
#line 399 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = new IR::LNot(yystack_[1].location, yystack_[0].value.as < IR::Expression* > ()); }
#line 3140 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 21: // unary_expression: "~" cast_expression
#line 400 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = new IR::Cmpl(yystack_[1].location, yystack_[0].value.as < IR::Expression* > ()); }
#line 3146 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 22: // cast_expression: unary_expression
#line 404 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3152 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 23: // cast_expression: "(" type_ref ")" cast_expression
#line 405 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           { yylhs.value.as < IR::Expression* > () = new IR::Cast(yystack_[3].location, yystack_[2].value.as < const IR::Type* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3158 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 24: // multiplicative_expression: cast_expression
#line 409 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3164 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 25: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 410 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                        { yylhs.value.as < IR::Expression* > () = new IR::Mul(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3170 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 26: // multiplicative_expression: multiplicative_expression "/" cast_expression
#line 411 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                        { yylhs.value.as < IR::Expression* > () = new IR::Div(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3176 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 27: // multiplicative_expression: multiplicative_expression "%" cast_expression
#line 412 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                        { yylhs.value.as < IR::Expression* > () = new IR::Mod(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3182 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 28: // additive_expression: multiplicative_expression
#line 416 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3188 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 29: // additive_expression: additive_expression "+" multiplicative_expression
#line 418 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                            { yylhs.value.as < IR::Expression* > () = new IR::Add(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3194 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 30: // additive_expression: additive_expression "-" multiplicative_expression
#line 419 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                            { yylhs.value.as < IR::Expression* > () = new IR::Sub(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3200 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 31: // shift_expression: additive_expression
#line 423 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3206 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 32: // shift_expression: shift_expression "<<" additive_expression
#line 424 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                       { yylhs.value.as < IR::Expression* > () = new IR::Shl(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3212 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 33: // shift_expression: shift_expression ">>" additive_expression
#line 425 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                        { yylhs.value.as < IR::Expression* > () = new IR::Shr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3218 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 34: // relational_expression: shift_expression
#line 429 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                           { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3224 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 35: // relational_expression: relational_expression "<" shift_expression
#line 430 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                     { yylhs.value.as < IR::Expression* > () = new IR::Lss(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3230 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 36: // relational_expression: relational_expression ">" shift_expression
#line 431 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      { yylhs.value.as < IR::Expression* > () = new IR::Grt(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3236 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 37: // relational_expression: relational_expression "<=" shift_expression
#line 432 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      { yylhs.value.as < IR::Expression* > () = new IR::Leq(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3242 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 38: // relational_expression: relational_expression ">=" shift_expression
#line 433 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      { yylhs.value.as < IR::Expression* > () = new IR::Geq(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3248 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 39: // equality_expression: relational_expression
#line 437 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3254 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 40: // equality_expression: equality_expression "==" relational_expression
#line 438 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                           { yylhs.value.as < IR::Expression* > () = new IR::Equ(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3260 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 41: // equality_expression: equality_expression "!=" relational_expression
#line 439 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                           { yylhs.value.as < IR::Expression* > () = new IR::Neq(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3266 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 42: // and_expression: equality_expression
#line 443 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                              { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3272 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 43: // and_expression: and_expression "&" equality_expression
#line 444 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                 { yylhs.value.as < IR::Expression* > () = new IR::BAnd(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3278 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 44: // exclusive_or_expression: and_expression
#line 448 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3284 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 45: // exclusive_or_expression: exclusive_or_expression "^" and_expression
#line 449 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                     { yylhs.value.as < IR::Expression* > () = new IR::BXor(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3290 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 46: // inclusive_or_expression: exclusive_or_expression
#line 453 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3296 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 47: // inclusive_or_expression: inclusive_or_expression "|" exclusive_or_expression
#line 454 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                              { yylhs.value.as < IR::Expression* > () = new IR::BOr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3302 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 48: // logical_and_expression: inclusive_or_expression
#line 458 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3308 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 49: // logical_and_expression: logical_and_expression "&&" inclusive_or_expression
#line 459 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                { yylhs.value.as < IR::Expression* > () = new IR::LAnd(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3314 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 50: // logical_or_expression: logical_and_expression
#line 463 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3320 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 51: // logical_or_expression: logical_or_expression "||" logical_and_expression
#line 464 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                             { yylhs.value.as < IR::Expression* > () = new IR::LOr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3326 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 52: // conditional_expression: logical_or_expression
#line 468 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3332 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 53: // conditional_expression: logical_or_expression "?" expression ":" conditional_expression
#line 469 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                          { yylhs.value.as < IR::Expression* > () = new IR::Mux(yystack_[3].location, yystack_[4].value.as < IR::Expression* > (), yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3338 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 54: // expression: conditional_expression
#line 473 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3344 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 55: // expression: expression "++"
#line 475 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          {
                yylhs.value.as < IR::Expression* > () = new IR::P5PostIncrement(yystack_[1].location + yystack_[0].location, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3352 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 56: // expression: "." field_ref "=" expression
#line 480 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                yylhs.value.as < IR::Expression* > () = new IR::P5DesignatedInitializer(yystack_[3].location + yystack_[0].location, /*isMember=*/true, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
        }
#line 3360 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 57: // expression_list: expression
#line 490 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     { auto v = new IR::Vector<IR::Expression>();
                       v->push_back(yystack_[0].value.as < IR::Expression* > ());
                       yylhs.value.as < IR::Vector<IR::Expression>* > () = v; }
#line 3368 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 58: // expression_list: expression_list "," expression
#line 493 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yystack_[2].value.as < IR::Vector<IR::Expression>* > ()->push_back(yystack_[0].value.as < IR::Expression* > ());
                                           yylhs.value.as < IR::Vector<IR::Expression>* > () = yystack_[2].value.as < IR::Vector<IR::Expression>* > (); }
#line 3375 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 59: // annotation: "@" ID
#line 504 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   {
                // 无参数：生成一个空的、已结构化的表达式列表
                IR::Vector<IR::Expression> args;
                yylhs.value.as < IR::Annotation* > () = new IR::Annotation(yystack_[1].location + yystack_[0].location, *yystack_[0].value.as < IR::ID* > (), args, /*structured=*/true);
        }
#line 3385 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 60: // annotation: "@" ID "(" expression_list ")"
#line 510 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         {
                // expression_list: IR::Vector<IR::Expression>*
                yylhs.value.as < IR::Annotation* > () = new IR::Annotation(yystack_[4].location + yystack_[0].location, *yystack_[3].value.as < IR::ID* > (), *yystack_[1].value.as < IR::Vector<IR::Expression>* > (), /*structured=*/true);
        }
#line 3394 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 61: // annotations: %empty
#line 517 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::Vector<IR::Annotation>* > () = new IR::Vector<IR::Annotation>();
        }
#line 3402 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 62: // annotations: annotations annotation
#line 520 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 {
                yylhs.value.as < IR::Vector<IR::Annotation>* > () = yystack_[1].value.as < IR::Vector<IR::Annotation>* > ();
                if (yystack_[0].value.as < IR::Annotation* > () != nullptr) {
                        yylhs.value.as < IR::Vector<IR::Annotation>* > ()->push_back(yystack_[0].value.as < IR::Annotation* > ());
                        yylhs.value.as < IR::Vector<IR::Annotation>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
                }
        }
#line 3414 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 63: // type_ref_explicit: UINT "<" postfix_expression ">"
#line 535 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                          {
                auto expr = yystack_[1].value.as < IR::Expression* > ();
                if (auto c = expr->to<IR::Constant>()) {
                    yylhs.value.as < const IR::Type* > () = IR::Type_Bits::get(c->asInt(), false);
                } else {
                    yylhs.value.as < const IR::Type* > () = IR::Type_Bits::get(yystack_[3].location, expr, false);
                }
        }
#line 3427 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 64: // type_ref_explicit: INT "<" postfix_expression ">"
#line 543 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                          {
                auto expr = yystack_[1].value.as < IR::Expression* > ();
                if (auto c = expr->to<IR::Constant>()) {
                    yylhs.value.as < const IR::Type* > () = IR::Type_Bits::get(c->asInt(), true);
                } else {
                    yylhs.value.as < const IR::Type* > () = IR::Type_Bits::get(yystack_[3].location, expr, true);
                }
        }
#line 3440 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 65: // type_ref_explicit: struct_union_type_declaration
#line 551 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                yylhs.value.as < const IR::Type* > () = yystack_[0].value.as < IR::Type_Struct* > ();
        }
#line 3448 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 66: // type_ref_explicit: VOID
#line 554 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
               {
                yylhs.value.as < const IR::Type* > () = IR::Type_Void::get();
        }
#line 3456 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 67: // type_ref: type_ref_explicit
#line 560 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            { yylhs.value.as < const IR::Type* > () = yystack_[0].value.as < const IR::Type* > (); }
#line 3462 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 68: // type_ref: ID
#line 561 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
             {
                auto path = new IR::Path(yystack_[0].location, *yystack_[0].value.as < IR::ID* > ());
                yylhs.value.as < const IR::Type* > () = new IR::Type_Name(yystack_[0].location, path);
        }
#line 3471 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 69: // type_ref: ID "::" ID
#line 565 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     {
                auto p = new IR::Path(yystack_[2].location, *yystack_[2].value.as < IR::ID* > () + "::" + *yystack_[0].value.as < IR::ID* > ());
                yylhs.value.as < const IR::Type* > () = new IR::Type_Name(yystack_[2].location, p);
        }
#line 3480 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 70: // type_ref: ID "<" ID ">"
#line 569 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                        {
                auto p = new IR::Path(yystack_[3].location, *yystack_[3].value.as < IR::ID* > () + "<" + *yystack_[1].value.as < IR::ID* > () + ">");
                yylhs.value.as < const IR::Type* > () = new IR::Type_Name(yystack_[3].location, p);
        }
#line 3489 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 71: // type_ref: ID "<" ID "::" ID ">"
#line 573 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                {
                auto p = new IR::Path(yystack_[5].location, *yystack_[5].value.as < IR::ID* > () + "<" + *yystack_[3].value.as < IR::ID* > () + "::" + *yystack_[1].value.as < IR::ID* > () + ">");
                yylhs.value.as < const IR::Type* > () = new IR::Type_Name(yystack_[5].location, p);
        }
#line 3498 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 72: // field_ref_no_slice: ID
#line 579 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
             { auto path = new IR::Path(yystack_[0].location, *yystack_[0].value.as < IR::ID* > ());
               yylhs.value.as < IR::Expression* > () = new IR::PathExpression(yystack_[0].location, path); }
#line 3505 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 73: // field_ref_no_slice: field_ref "." ID
#line 581 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                           { yylhs.value.as < IR::Expression* > () = new IR::Member(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), *yystack_[0].value.as < IR::ID* > ()); }
#line 3511 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 74: // field_ref_no_slice: field_ref "[" expression "]"
#line 582 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       { yylhs.value.as < IR::Expression* > () = new IR::ArrayIndex(yystack_[2].location, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3517 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 75: // field_ref_no_slice: field_ref "[" "]"
#line 583 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            { yylhs.value.as < IR::Expression* > () = new IR::ArrayIndex(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), new IR::DefaultExpression(yystack_[1].location)); }
#line 3523 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 76: // field_ref_no_slice: ID "::" field_ref
#line 584 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            { auto path = new IR::Path(yystack_[2].location, *yystack_[2].value.as < IR::ID* > ());
                              auto base = new IR::PathExpression(yystack_[2].location, path);
                              yylhs.value.as < IR::Expression* > () = new IR::Member(yystack_[1].location, base, yystack_[0].value.as < IR::Expression* > ()->toString()); }
#line 3531 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 77: // field_ref: field_ref_no_slice
#line 589 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                             { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3537 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 78: // field_ref: field_ref "[" expression ":" expression "]"
#line 590 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      { yylhs.value.as < IR::Expression* > () = new IR::Slice(yystack_[4].location, yystack_[5].value.as < IR::Expression* > (), yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3543 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 79: // field_ref: "[" expression ":" expression "]"
#line 591 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            { yylhs.value.as < IR::Expression* > () = new IR::Slice(yystack_[4].location, nullptr, yystack_[3].value.as < IR::Expression* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3549 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 80: // field_dec: annotations type_ref ID ";"
#line 594 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                auto field = new IR::StructField(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), yystack_[2].value.as < const IR::Type* > ());
                if (yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3561 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 81: // field_dec: annotations type_ref ID "=" expression ";"
#line 601 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      {
                // 只能忽略初始化值，或者记录表达式用于后续处理
                auto field = new IR::StructField(yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), yystack_[4].value.as < const IR::Type* > ());
                if (yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3574 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 82: // field_dec: annotations type_ref ID "[" expression "]" ";"
#line 609 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                         {
                auto arrayType = new IR::Type_Stack(yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::Expression* > ());
                auto field = new IR::StructField(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), arrayType);
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3587 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 83: // field_dec: annotations type_ref ID "[" expression "]" "[" expression "]" ";"
#line 617 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                            {
                auto innerArray = new IR::Type_Stack(yystack_[8].value.as < const IR::Type* > (), yystack_[5].value.as < IR::Expression* > ());
                auto outerArray = new IR::Type_Stack(innerArray, yystack_[2].value.as < IR::Expression* > ());
                auto field = new IR::StructField(yystack_[7].location, *yystack_[7].value.as < IR::ID* > (), outerArray);
                if (yystack_[9].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[9].value.as < IR::Vector<IR::Annotation>* > ()) field->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = field;
        }
#line 3601 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 84: // anonymous_struct_union_dec: annotations STRUCT "{" struct_field_list "}" ";"
#line 629 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[4].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[2].value.as < IR::IndexedVector<IR::StructField>* > ());
                if (yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[4].location, anonName, type);
        }
#line 3614 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 85: // anonymous_struct_union_dec: annotations STRUCT ID "{" struct_field_list "}" ";"
#line 638 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[5].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[2].value.as < IR::IndexedVector<IR::StructField>* > ());
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[5].location, anonName, type);
        }
#line 3627 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 86: // anonymous_struct_union_dec: annotations STRUCT "{" struct_field_list "}" ID ";"
#line 647 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[5].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[3].value.as < IR::IndexedVector<IR::StructField>* > ());
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), type);
        }
#line 3640 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 87: // anonymous_struct_union_dec: annotations UNION "{" struct_field_list "}" ";"
#line 656 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 3655 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 88: // anonymous_struct_union_dec: annotations UNION ID "{" struct_field_list "}" ";"
#line 667 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[5].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[2].value.as < IR::IndexedVector<IR::StructField>* > ());
                type->annotations.push_back(new IR::Annotation("union", {}));
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[5].location, anonName, type);
        }
#line 3669 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 89: // anonymous_struct_union_dec: annotations UNION "{" struct_field_list "}" ID ";"
#line 677 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring anonName = cstring("_anon_" + Util::toString(globalAnonCount++));
                auto type = new IR::Type_Struct(yystack_[5].location, IR::ID(anonName), IR::Vector<IR::Annotation>(), *yystack_[3].value.as < IR::IndexedVector<IR::StructField>* > ());
                type->annotations.push_back(new IR::Annotation("union", {}));
                if (yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ()) type->addAnnotation(ann);
                }
                yylhs.value.as < IR::StructField* > () = new IR::StructField(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), type);
        }
#line 3683 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 90: // struct_field_dec: field_dec
#line 688 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                    { yylhs.value.as < IR::StructField* > () = yystack_[0].value.as < IR::StructField* > (); }
#line 3689 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 91: // struct_field_dec: anonymous_struct_union_dec
#line 689 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                     { yylhs.value.as < IR::StructField* > () = yystack_[0].value.as < IR::StructField* > (); }
#line 3695 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 92: // struct_field_list: struct_field_dec
#line 694 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto vec = new IR::IndexedVector<IR::StructField>();
                vec->push_back(yystack_[0].value.as < IR::StructField* > ());
                yylhs.value.as < IR::IndexedVector<IR::StructField>* > () = vec;
        }
#line 3705 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 93: // struct_field_list: struct_field_list struct_field_dec
#line 700 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ()->push_back(yystack_[0].value.as < IR::StructField* > ());
                yylhs.value.as < IR::IndexedVector<IR::StructField>* > () = yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ();
        }
#line 3714 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 94: // constant_declaration: CONST type_ref ID "=" expression ";"
#line 714 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Declaration_Constant* > () = new IR::Declaration_Constant(yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), yystack_[4].value.as < const IR::Type* > (), yystack_[1].value.as < IR::Expression* > ());
        }
#line 3722 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 95: // constant_declaration: CONST type_ref ID "[" expression "]" "=" expression ";"
#line 718 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto type = new IR::Type_Stack(yystack_[7].location, yystack_[7].value.as < const IR::Type* > (), yystack_[4].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Declaration_Constant* > () = new IR::Declaration_Constant(yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3731 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 96: // constant_declaration: CONST type_ref ID '[' expression ']' '[' expression ']' '=' expression ';'
#line 723 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto innerType = new IR::Type_Stack(yystack_[10].location, yystack_[10].value.as < const IR::Type* > (), yystack_[7].value.as < IR::Expression* > ());
                auto type = new IR::Type_Stack(yystack_[10].location, innerType, yystack_[4].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Declaration_Constant* > () = new IR::Declaration_Constant(yystack_[9].location, *yystack_[9].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3741 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 97: // header_declaration: HEADER type_ref ID ";"
#line 730 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 {
                auto args = new IR::Vector<IR::Argument>();
                yylhs.value.as < IR::Declaration* > () = new IR::Declaration_Instance(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), yystack_[2].value.as < const IR::Type* > (), args);
        }
#line 3750 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 98: // header_declaration: HEADER type_ref ID "[" expression "]" ";"
#line 734 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   {
                auto type = new IR::Type_Stack(yystack_[5].location, yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Declaration* > () = new IR::Declaration_Instance(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), type, new IR::Vector<IR::Argument>());
        }
#line 3759 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 99: // variable_declaration: type_ref ID ";"
#line 740 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          { yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[1].location, *yystack_[1].value.as < IR::ID* > (), yystack_[2].value.as < const IR::Type* > (), nullptr); }
#line 3765 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 100: // variable_declaration: type_ref ID "=" expression ";"
#line 741 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), yystack_[4].value.as < const IR::Type* > (), yystack_[1].value.as < IR::Expression* > ()); }
#line 3771 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 101: // variable_declaration: type_ref ID "[" expression "]" ";"
#line 742 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                             {
            auto type = new IR::Type_Stack(yystack_[5].location, yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[4].location, *yystack_[4].value.as < IR::ID* > (), type, nullptr);
        }
#line 3780 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 102: // variable_declaration: type_ref ID "[" expression "]" "=" expression ";"
#line 746 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                            {
            auto type = new IR::Type_Stack(yystack_[7].location, yystack_[7].value.as < const IR::Type* > (), yystack_[4].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3789 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 103: // variable_declaration: type_ref ID "[" expression "]" "[" expression "]" ";"
#line 750 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                {
            auto innerType = new IR::Type_Stack(yystack_[8].location, yystack_[8].value.as < const IR::Type* > (), yystack_[5].value.as < IR::Expression* > ());
            auto type = new IR::Type_Stack(yystack_[8].location, innerType, yystack_[2].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[7].location, *yystack_[7].value.as < IR::ID* > (), type, nullptr);
        }
#line 3799 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 104: // variable_declaration: type_ref ID "[" expression "]" "[" expression "]" "=" expression ";"
#line 755 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                               {
            auto innerType = new IR::Type_Stack(yystack_[10].location, yystack_[10].value.as < const IR::Type* > (), yystack_[7].value.as < IR::Expression* > ());
            auto type = new IR::Type_Stack(yystack_[10].location, innerType, yystack_[4].value.as < IR::Expression* > ());
            yylhs.value.as < IR::Declaration_Variable* > () = new IR::Declaration_Variable(yystack_[9].location, *yystack_[9].value.as < IR::ID* > (), type, yystack_[1].value.as < IR::Expression* > ());
        }
#line 3809 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 105: // variable_declaration: USING NAMESPACE ID ";"
#line 760 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::Declaration_Variable* > () = nullptr; /* TODO: maybe handle 'using namespace' */ }
#line 3815 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 106: // return_value_type: ID "(" arg_list ")" ";"
#line 769 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  {
                auto pe = new IR::PathExpression(*yystack_[4].value.as < IR::ID* > ());
                auto mc = new IR::MethodCallExpression(yystack_[4].location, pe,
                                                 new IR::Vector<IR::Type>(), yystack_[2].value.as < IR::Vector<IR::Argument>* > ());
                yylhs.value.as < IR::Statement* > () = new IR::ReturnStatement(yystack_[4].location + yystack_[1].location, mc);
        }
#line 3826 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 107: // return_value_type: "{" return_value_type_list "}"
#line 775 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Statement* > () = yystack_[1].value.as < IR::BlockStatement* > (); }
#line 3832 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 108: // return_value_type: ID ";"
#line 776 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                auto pe = new IR::PathExpression(*yystack_[1].value.as < IR::ID* > ());
                yylhs.value.as < IR::Statement* > () = new IR::ReturnStatement(yystack_[1].location + yystack_[0].location, pe);
        }
#line 3841 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 109: // return_value_type_list: %empty
#line 782 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yylhs.location);
        }
#line 3849 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 110: // return_value_type_list: return_value_type_list return_value_type
#line 785 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   {
                yystack_[1].value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::Statement* > ());
                yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 3858 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 111: // value_masked_or_set: expression
#line 791 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     { yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > (); }
#line 3864 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 112: // value_masked_or_set: expression "&&&" expression
#line 792 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      { yylhs.value.as < IR::Expression* > () = new IR::Mask(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ()); }
#line 3870 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 113: // value_list: value_masked_or_set
#line 796 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto vec = new IR::Vector<IR::Expression>();
                vec->push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Vector<IR::Expression>* > () = vec;
        }
#line 3880 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 114: // value_list: value_list "," value_masked_or_set
#line 802 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[2].value.as < IR::Vector<IR::Expression>* > ()->push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Vector<IR::Expression>* > () = yystack_[2].value.as < IR::Vector<IR::Expression>* > ();
        }
#line 3889 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 115: // case_entry: CASE value_list ":" return_value_type
#line 809 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 3904 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 116: // case_entry: CASE value_list ":"
#line 820 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                // Empty case body (fallthrough): "case ...:" with nothing after ':'
                IR::Expression* le =  new IR::ListExpression(yystack_[2].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ());
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, le, nullptr);
        }
#line 3914 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 117: // case_entry: DEFAULT ":" return_value_type
#line 826 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 3929 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 118: // case_entry: DEFAULT ":"
#line 837 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                // Empty default body (fallthrough).
                auto label = new IR::DefaultExpression(yystack_[1].location);
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[1].location, label, nullptr);
        }
#line 3939 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 119: // case_list: case_entry
#line 844 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = new IR::Vector<IR::SwitchCase>();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[0].location;
        }
#line 3949 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 120: // case_list: case_list case_entry
#line 849 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                               {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
        }
#line 3959 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 121: // field_ref_or_func: field_ref
#line 856 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                    {
                yylhs.value.as < IR::Expression* > () = yystack_[0].value.as < IR::Expression* > ();
        }
#line 3967 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 122: // field_ref_or_func: ID "(" arg_list ")"
#line 859 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                              {
                auto path   = new IR::Path(yystack_[3].location, *yystack_[3].value.as < IR::ID* > ());
                auto callee = new IR::PathExpression(yystack_[3].location, path);
                yylhs.value.as < IR::Expression* > () = new IR::MethodCallExpression(yystack_[2].location, callee, yystack_[1].value.as < IR::Vector<IR::Argument>* > ());
        }
#line 3977 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 123: // select_exp: annotations field_ref_or_func
#line 866 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        {
                auto vec = new IR::Vector<IR::Expression>();
                // Ignore annotations for select list entries.
                vec->push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::ListExpression* > () = new IR::ListExpression(yystack_[1].location, *vec);
        }
#line 3988 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 124: // select_exp: select_exp "," annotations field_ref_or_func
#line 872 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                       {
                // Ignore annotations for select list entries.
                yystack_[3].value.as < IR::ListExpression* > ()->components.push_back(yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::ListExpression* > () = yystack_[3].value.as < IR::ListExpression* > ();
        }
#line 3998 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 125: // return_select_statement: SWITCH "(" select_exp ")" "{" case_list "}"
#line 879 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                      {
                yylhs.value.as < IR::Statement* > () = new IR::SwitchStatement(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 4006 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 126: // return_select_statement: SWITCH "(" ")" "{" case_list "}"
#line 882 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                yylhs.value.as < IR::Statement* > () = new IR::SwitchStatement(yystack_[5].location, nullptr, *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 4014 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 127: // return_statement: RETURN return_select_statement
#line 887 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::Statement* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4020 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 128: // return_statement: RETURN return_value_type
#line 888 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   { yylhs.value.as < IR::Statement* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4026 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 129: // break_statement: BREAK ";"
#line 891 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                    { yylhs.value.as < IR::Statement* > () = new IR::BreakStatement(yystack_[1].location); }
#line 4032 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 130: // parameter: annotations type_ref ID
#line 899 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  {
                auto param = new IR::Parameter(yystack_[0].location, *yystack_[0].value.as < IR::ID* > (), IR::Direction::In, yystack_[1].value.as < const IR::Type* > ());
                if (yystack_[2].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[2].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 4044 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 131: // parameter: annotations type_ref ID "=" expression
#line 906 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                 {
                auto param = new IR::Parameter(yystack_[2].location, *yystack_[2].value.as < IR::ID* > (), IR::Direction::In, yystack_[3].value.as < const IR::Type* > (), yystack_[0].value.as < IR::Expression* > ());
                if (yystack_[4].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[4].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 4056 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 132: // parameter: annotations type_ref "&" ID
#line 913 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      {
                auto param = new IR::Parameter(yystack_[0].location, *yystack_[0].value.as < IR::ID* > (), IR::Direction::InOut, yystack_[2].value.as < const IR::Type* > ());
                if (yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[3].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 4068 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 133: // parameter: annotations type_ref "&" ID "=" expression
#line 920 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                     {
                auto param = new IR::Parameter(yystack_[2].location, *yystack_[2].value.as < IR::ID* > (), IR::Direction::InOut, yystack_[4].value.as < const IR::Type* > (), yystack_[0].value.as < IR::Expression* > ());
                if (yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) {
                        for (auto *ann : *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ()) param->addAnnotation(ann);
                }
                yylhs.value.as < IR::Parameter* > () = param;
        }
#line 4080 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 134: // parameter: annotations type_ref "&" ID "[" "]"
#line 927 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4095 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 135: // parameter: annotations type_ref ID "[" "]"
#line 937 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4110 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 136: // param_list: %empty
#line 949 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::ParameterList* > () = new IR::ParameterList(); }
#line 4116 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 137: // param_list: parameter
#line 951 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto pl = new IR::ParameterList(); pl->push_back(yystack_[0].value.as < IR::Parameter* > ());
                yylhs.value.as < IR::ParameterList* > () = pl;
        }
#line 4125 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 138: // param_list: param_list "," parameter
#line 956 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[2].value.as < IR::ParameterList* > ()->push_back(yystack_[0].value.as < IR::Parameter* > ());
                yylhs.value.as < IR::ParameterList* > () = yystack_[2].value.as < IR::ParameterList* > ();
        }
#line 4134 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 139: // arg: expression
#line 963 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                     { yylhs.value.as < IR::Argument* > () = new IR::Argument(yystack_[0].location, yystack_[0].value.as < IR::Expression* > ()); }
#line 4140 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 140: // arg_list: %empty
#line 966 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::Vector<IR::Argument>* > () = new IR::Vector<IR::Argument>(); }
#line 4146 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 141: // arg_list: arg
#line 968 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto v = new IR::Vector<IR::Argument>();
                v->push_back(yystack_[0].value.as < IR::Argument* > ());
                yylhs.value.as < IR::Vector<IR::Argument>* > () = v;
        }
#line 4156 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 142: // arg_list: arg_list "," arg
#line 974 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yystack_[2].value.as < IR::Vector<IR::Argument>* > ()->push_back(yystack_[0].value.as < IR::Argument* > ());
                yylhs.value.as < IR::Vector<IR::Argument>* > () = yystack_[2].value.as < IR::Vector<IR::Argument>* > ();
        }
#line 4165 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 143: // do_while_statement: DO action_statement WHILE "(" expression ")"
#line 982 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4182 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 144: // conditional_statement: IF "(" expression ")" action_statement
#line 997 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                   {
                IR::IndexedVector<IR::StatOrDecl> as;
                as.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto bs = new IR::BlockStatement(yystack_[0].location, as);
                yylhs.value.as < IR::Statement* > () = new IR::IfStatement(yystack_[4].location, yystack_[2].value.as < IR::Expression* > (), bs, nullptr);
        }
#line 4193 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 145: // conditional_statement: IF "(" expression ")" action_statement ELSE action_statement
#line 1003 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                                   {
                IR::IndexedVector<IR::StatOrDecl> as0;
                as0.push_back(yystack_[2].value.as < IR::StatOrDecl* > ());
                auto bs0 = new IR::BlockStatement(yystack_[2].location, as0);
                IR::IndexedVector<IR::StatOrDecl> as1;
                as1.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto bs1 = new IR::BlockStatement(yystack_[0].location, as1);
                yylhs.value.as < IR::Statement* > () = new IR::IfStatement(yystack_[6].location, yystack_[4].value.as < IR::Expression* > (), bs0, bs1);
        }
#line 4207 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 146: // for_loop_statement: FOR "(" parameter ";" expression ";" assignment_or_call ")" action_statement
#line 1015 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4231 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 147: // for_loop_statement: FOR "(" parameter ":" expression ")" action_statement
#line 1035 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4272 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 148: // case: CASE value_list ":" action_statement
#line 1073 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                IR::Expression* vl = new IR::ListExpression(yystack_[3].location, *yystack_[2].value.as < IR::Vector<IR::Expression>* > ());

                IR::IndexedVector<IR::StatOrDecl> as_vec;
                as_vec.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto as = new IR::BlockStatement(yystack_[0].location, as_vec);

                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[3].location, vl, as);
        }
#line 4286 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 149: // case: CASE value_list ":"
#line 1083 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                // Empty case body (fallthrough).
                IR::Expression* vl = new IR::ListExpression(yystack_[2].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ());
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, vl, nullptr);
        }
#line 4296 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 150: // case: DEFAULT ":" action_statement
#line 1088 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                IR::IndexedVector<IR::StatOrDecl> as_vec;
                as_vec.push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                auto as = new IR::BlockStatement(yystack_[0].location, as_vec);

                auto label = new IR::DefaultExpression(yystack_[2].location);

                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, label, as);
        }
#line 4310 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 151: // case: DEFAULT ":"
#line 1097 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                      {
                // Empty default body (fallthrough).
                auto label = new IR::DefaultExpression(yystack_[1].location);
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[1].location, label, nullptr);
        }
#line 4320 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 152: // switch_cases: %empty
#line 1104 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = new IR::Vector<IR::SwitchCase>; }
#line 4326 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 153: // switch_cases: switch_cases case
#line 1105 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            {
                yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ();
        }
#line 4335 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 154: // switch_statement: SWITCH "(" select_exp ")" "{" switch_cases "}"
#line 1111 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                         {
                yylhs.value.as < IR::Statement* > () = new IR::SwitchStatement(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 4343 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 155: // switch_statement: SWITCH "(" ")" "{" switch_cases "}"
#line 1114 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                              {
                yylhs.value.as < IR::Statement* > () = new IR::SwitchStatement(yystack_[5].location, nullptr, *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 4351 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 156: // assignment_or_call: field_ref_or_func
#line 1119 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                            {
                if (auto mc = yystack_[0].value.as < IR::Expression* > ()->to<IR::MethodCallExpression>()) {
                        yylhs.value.as < IR::Statement* > () = new IR::MethodCallStatement(yystack_[0].location, mc);
                } else {
                        yylhs.value.as < IR::Statement* > () = new IR::EmptyStatement(yystack_[0].location);
                }
        }
#line 4363 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 157: // assignment_or_call: field_ref "=" expression
#line 1126 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   {
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
        }
#line 4371 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 158: // assignment_or_call: field_ref "-=" expression
#line 1129 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto sub = new IR::Sub(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), sub);
        }
#line 4380 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 159: // assignment_or_call: field_ref "+=" expression
#line 1133 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto sub = new IR::Sub(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), sub);
        }
#line 4389 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 160: // assignment_or_call: field_ref "*=" expression
#line 1137 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto mul = new IR::Mul(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), mul);
        }
#line 4398 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 161: // assignment_or_call: field_ref "/=" expression
#line 1141 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto div = new IR::Div(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), div);
        }
#line 4407 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 162: // assignment_or_call: field_ref "%=" expression
#line 1145 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto mod = new IR::Mod(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), mod);
        }
#line 4416 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 163: // assignment_or_call: field_ref "|=" expression
#line 1149 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto bor = new IR::BOr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), bor);
        }
#line 4425 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 164: // assignment_or_call: field_ref "^=" expression
#line 1153 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                    {
                auto bxor = new IR::BXor(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), bxor);
        }
#line 4434 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 165: // assignment_or_call: field_ref "<<=" expression
#line 1157 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                     {
                auto shl = new IR::Shl(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), shl);
        }
#line 4443 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 166: // assignment_or_call: field_ref ">>=" expression
#line 1161 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                     {
                auto shr = new IR::Shr(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), yystack_[0].value.as < IR::Expression* > ());
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[1].location, yystack_[2].value.as < IR::Expression* > (), shr);
        }
#line 4452 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 167: // assignment_or_call: field_ref "++"
#line 1165 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         {
                auto one = new IR::Constant(IR::Type_Bits::get(32), 1);
                auto add = new IR::Add(yystack_[0].location, yystack_[1].value.as < IR::Expression* > (), one);
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[0].location, yystack_[1].value.as < IR::Expression* > (), add);
        }
#line 4462 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 168: // assignment_or_call: field_ref "--"
#line 1170 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         {
                auto one = new IR::Constant(IR::Type_Bits::get(32), 1);
                auto sub = new IR::Sub(yystack_[0].location, yystack_[1].value.as < IR::Expression* > (), one);
                yylhs.value.as < IR::Statement* > () = new IR::AssignmentStatement(yystack_[0].location, yystack_[1].value.as < IR::Expression* > (), sub);
        }
#line 4472 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 169: // assignment_or_call_statement: assignment_or_call ";"
#line 1177 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::Statement* > () = yystack_[1].value.as < IR::Statement* > (); }
#line 4478 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 170: // action_statement: annotations variable_declaration
#line 1180 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Variable* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Variable* > ();
        }
#line 4487 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 171: // action_statement: annotations constant_declaration
#line 1184 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Constant* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Constant* > ();
        }
#line 4496 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 172: // action_statement: annotations action_compound_statement
#line 1188 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                {
                attachAnnotations(yystack_[0].value.as < IR::BlockStatement* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::BlockStatement* > ();
        }
#line 4505 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 173: // action_statement: annotations conditional_statement
#line 1192 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4511 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 174: // action_statement: annotations switch_statement
#line 1193 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4517 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 175: // action_statement: annotations do_while_statement
#line 1194 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4523 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 176: // action_statement: annotations for_loop_statement
#line 1195 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4529 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 177: // action_statement: annotations return_statement
#line 1196 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4535 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 178: // action_statement: annotations break_statement
#line 1197 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4541 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 179: // action_statement: annotations assignment_or_call_statement
#line 1198 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4547 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 180: // action_statement: annotations ";"
#line 1199 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          {
            yylhs.value.as < IR::StatOrDecl* > () = new IR::EmptyStatement(yylhs.location);
        }
#line 4555 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 181: // action_statement_list: %empty
#line 1205 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 { yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yylhs.location); }
#line 4561 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 182: // action_statement_list: action_statement_list action_statement
#line 1206 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                 {
              yystack_[1].value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
              yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 4570 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 183: // action_compound_statement: "{" action_statement_list "}"
#line 1212 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                        { yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > (); }
#line 4576 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 184: // key_element: CONTROL_PARAMETERS "=" "{" action_statement_list "}"
#line 1221 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                               {
                auto ke = new IR::P5KeyElement(yystack_[4].location);
                ke->control = *yystack_[1].value.as < IR::BlockStatement* > ();
                yylhs.value.as < IR::P5KeyElement* > () = ke;
        }
#line 4586 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 185: // key_element: annotations expression ":" ID ";"
#line 1226 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            {
                auto ke = new IR::P5KeyElement(yystack_[4].location);
                ke->annotations = *yystack_[4].value.as < IR::Vector<IR::Annotation>* > ();
                ke->expr = yystack_[3].value.as < IR::Expression* > ();
                ke->matchType = *yystack_[1].value.as < IR::ID* > ();
                yylhs.value.as < IR::P5KeyElement* > () = ke;
        }
#line 4598 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 186: // key_element: annotations expression ";"
#line 1233 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                     {
                auto ke = new IR::P5KeyElement(yystack_[2].location);
                ke->annotations = *yystack_[2].value.as < IR::Vector<IR::Annotation>* > ();
                ke->expr = yystack_[1].value.as < IR::Expression* > ();
                yylhs.value.as < IR::P5KeyElement* > () = ke;
        }
#line 4609 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 187: // key_element_list: %empty
#line 1241 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::Vector<IR::P5KeyElement>* > () = new IR::Vector<IR::P5KeyElement>();
        }
#line 4617 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 188: // key_element_list: key_element_list key_element
#line 1244 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ()->push_back(yystack_[0].value.as < IR::P5KeyElement* > ());
                yylhs.value.as < IR::Vector<IR::P5KeyElement>* > () = yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
        }
#line 4626 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 189: // key_case_entry: annotations CASE value_list ":" "{" key_element_list "}"
#line 1250 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                   {
                auto label = new IR::ListExpression(yystack_[4].location, *yystack_[4].value.as < IR::Vector<IR::Expression>* > ());
                auto kce = new IR::P5KeyCase(yystack_[6].location, false);
                kce->annotations = *yystack_[6].value.as < IR::Vector<IR::Annotation>* > ();
                kce->label = label;
                kce->elements = *yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
                kce->fallthrough = false;
                yylhs.value.as < IR::P5KeyCase* > () = kce;
        }
#line 4640 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 190: // key_case_entry: annotations CASE value_list ":"
#line 1259 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4656 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 191: // key_case_entry: annotations DEFAULT ":" "{" key_element_list "}"
#line 1270 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                           {
                auto label = new IR::DefaultExpression(yystack_[4].location);
                auto kce = new IR::P5KeyCase(yystack_[5].location, false);
                kce->annotations = *yystack_[5].value.as < IR::Vector<IR::Annotation>* > ();
                kce->label = label;
                kce->elements = *yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
                kce->fallthrough = false;
                yylhs.value.as < IR::P5KeyCase* > () = kce;
        }
#line 4670 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 192: // key_case_entry: annotations DEFAULT ":"
#line 1279 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4685 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 193: // key_case_list: key_case_entry
#line 1291 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         {
                auto v = new IR::Vector<IR::P5KeyCase>();
                v->push_back(yystack_[0].value.as < IR::P5KeyCase* > ());
                yylhs.value.as < IR::Vector<IR::P5KeyCase>* > () = v;
        }
#line 4695 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 194: // key_case_list: key_case_list key_case_entry
#line 1296 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                       {
                yystack_[1].value.as < IR::Vector<IR::P5KeyCase>* > ()->push_back(yystack_[0].value.as < IR::P5KeyCase* > ());
                yylhs.value.as < IR::Vector<IR::P5KeyCase>* > () = yystack_[1].value.as < IR::Vector<IR::P5KeyCase>* > ();
        }
#line 4704 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 195: // key_switch_entry: SWITCH "(" select_exp ")" "{" key_case_list "}"
#line 1302 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                          {
                // P5KeySwitch is a dedicated IR node so a single key={...} can contain
                // multiple switch blocks in source order.
                yylhs.value.as < IR::P5KeySwitch* > () = new IR::P5KeySwitch(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::P5KeyCase>* > ());
        }
#line 4714 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 196: // key_switch_entry: SWITCH "(" ")" "{" key_case_list "}"
#line 1307 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                               {
                yylhs.value.as < IR::P5KeySwitch* > () = new IR::P5KeySwitch(yystack_[5].location, nullptr, *yystack_[1].value.as < IR::Vector<IR::P5KeyCase>* > ());
        }
#line 4722 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 197: // key_switch_list: key_switch_entry
#line 1312 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                           {
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > () = new IR::Vector<IR::P5KeySwitch>();
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->push_back(yystack_[0].value.as < IR::P5KeySwitch* > ());
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->srcInfo = yystack_[0].location;
        }
#line 4732 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 198: // key_switch_list: key_switch_entry key_switch_list
#line 1317 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > () = yystack_[0].value.as < IR::Vector<IR::P5KeySwitch>* > ();
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->insert(yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->begin(), yystack_[1].value.as < IR::P5KeySwitch* > ());
                yylhs.value.as < IR::Vector<IR::P5KeySwitch>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
        }
#line 4742 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 199: // program_selection_statement: constant_declaration
#line 1324 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Constant* > (); }
#line 4748 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 200: // program_selection_statement: variable_declaration
#line 1325 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                 { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Variable* > (); }
#line 4754 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 201: // program_selection_statement: assignment_or_call_statement
#line 1326 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                         { yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > (); }
#line 4760 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 202: // program_selection_statement_list: %empty
#line 1329 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                 {
                yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yylhs.location);
        }
#line 4768 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 203: // program_selection_statement_list: program_selection_statement
#line 1332 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                      {
                auto blk = new IR::BlockStatement(yystack_[0].location);
                blk->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                yylhs.value.as < IR::BlockStatement* > () = blk;
        }
#line 4778 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 204: // program_selection_statement_list: program_selection_statement_list program_selection_statement
#line 1337 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                       {
                yystack_[1].value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
                yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 4787 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 205: // table_case_entry: annotations CASE value_list ":" "{" program_selection_statement_list "}"
#line 1343 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4802 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 206: // table_case_entry: annotations CASE value_list ":"
#line 1353 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                          {
                // Empty case body (fallthrough).
                IR::Expression* label = new IR::ListExpression(yystack_[1].location, *yystack_[1].value.as < IR::Vector<IR::Expression>* > ());
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location, label, nullptr);
        }
#line 4812 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 207: // table_case_entry: annotations DEFAULT ":" "{" program_selection_statement_list "}"
#line 1358 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 4827 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 208: // table_case_entry: annotations DEFAULT ":"
#line 1368 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                  {
                // Empty default body (fallthrough).
                IR::Expression* label = new IR::DefaultExpression(yystack_[1].location);
                yylhs.value.as < IR::SwitchCase* > () = new IR::SwitchCase(yystack_[1].location, label, nullptr);
        }
#line 4837 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 209: // table_case_list: table_case_entry
#line 1376 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = new IR::Vector<IR::SwitchCase>();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[0].location;
        }
#line 4847 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 210: // table_case_list: table_case_list table_case_entry
#line 1382 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > () = yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ();
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as < IR::SwitchCase* > ());
                yylhs.value.as < IR::Vector<IR::SwitchCase>* > ()->srcInfo = yystack_[1].location + yystack_[0].location;
        }
#line 4857 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 211: // table_property: KEY "=" "{" key_element_list "}"
#line 1389 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                auto key = new IR::P5Key(yystack_[4].location);
                key->elements = *yystack_[1].value.as < IR::Vector<IR::P5KeyElement>* > ();
                yylhs.value.as < IR::StatOrDecl* > () = key;
        }
#line 4867 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 212: // table_property: KEY "=" "{" key_switch_list "}"
#line 1394 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                          {
                auto key = new IR::P5Key(yystack_[4].location);
                key->switches = *yystack_[1].value.as < IR::Vector<IR::P5KeySwitch>* > ();
                yylhs.value.as < IR::StatOrDecl* > () = key;
        }
#line 4877 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 213: // table_property: CONTROL_PARAMETERS "=" "{" action_statement_list "}"
#line 1399 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                               {
                // Similar to key_element's CONTROL_PARAMETERS form, but table properties
                // don't wrap this in a P5KeyElement: return the action block directly.
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[1].value.as < IR::BlockStatement* > ();
        }
#line 4887 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 214: // table_property: SWITCH "(" select_exp ")" "{" table_case_list "}"
#line 1404 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                            {
                yylhs.value.as < IR::StatOrDecl* > () = new IR::SwitchStatement(yystack_[6].location, yystack_[4].value.as < IR::ListExpression* > (), *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 4895 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 215: // table_property: SWITCH "(" ")" "{" table_case_list "}"
#line 1407 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                 {
                yylhs.value.as < IR::StatOrDecl* > () = new IR::SwitchStatement(yystack_[5].location, nullptr, *yystack_[1].value.as < IR::Vector<IR::SwitchCase>* > ());
        }
#line 4903 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 216: // table_property: annotations assignment_or_call_statement
#line 1410 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                   {
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Statement* > ();
        }
#line 4911 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 217: // table_property: annotations constant_declaration
#line 1413 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Constant* > ();
        }
#line 4919 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 218: // table_property: annotations variable_declaration
#line 1416 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                           {
                yylhs.value.as < IR::StatOrDecl* > () = yystack_[0].value.as < IR::Declaration_Variable* > ();
        }
#line 4927 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 219: // table_property_list: table_property
#line 1422 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                         {
                yylhs.value.as < IR::BlockStatement* > () = new IR::BlockStatement(yystack_[0].location);
                if (yystack_[0].value.as < IR::StatOrDecl* > ()) yylhs.value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
        }
#line 4936 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 220: // table_property_list: table_property_list table_property
#line 1426 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                             {
                yylhs.value.as < IR::BlockStatement* > () = yystack_[1].value.as < IR::BlockStatement* > ();
                if (yystack_[0].value.as < IR::StatOrDecl* > ()) yylhs.value.as < IR::BlockStatement* > ()->push_back(yystack_[0].value.as < IR::StatOrDecl* > ());
        }
#line 4945 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 221: // table_declaration: TABLE ID "(" param_list ")" "{" table_property_list "}"
#line 1434 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                  {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[7].location+yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), yystack_[4].value.as < IR::ParameterList* > (), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4953 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 222: // table_declaration: TABLE ID "{" table_property_list "}"
#line 1437 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                               {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[4].location+yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), new IR::ParameterList(), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4961 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 223: // table_declaration: CLASS ID "(" param_list ")" "{" table_property_list "}"
#line 1440 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                                                  {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[7].location+yystack_[6].location, *yystack_[6].value.as < IR::ID* > (), yystack_[4].value.as < IR::ParameterList* > (), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4969 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 224: // table_declaration: CLASS ID "{" table_property_list "}"
#line 1443 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                               {
                yylhs.value.as < IR::P5Table* > () = new IR::P5Table(yystack_[4].location+yystack_[3].location, *yystack_[3].value.as < IR::ID* > (), new IR::ParameterList(), yystack_[1].value.as < IR::BlockStatement* > ());
        }
#line 4977 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 225: // typedef_declaration: TYPEDEF type_ref ID
#line 1456 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto id = IR::ID(yystack_[0].location, *yystack_[0].value.as < IR::ID* > ());
                yylhs.value.as < IR::Type_Typedef* > () = new IR::Type_Typedef(yystack_[2].location, id, yystack_[1].value.as < const IR::Type* > ());
        }
#line 4986 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 226: // enumerator: ID
#line 1463 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < P4::P5::EnumItem* > () = new P4::P5::EnumItem(yystack_[0].location, yystack_[0].value.as < IR::ID* > (), nullptr);
        }
#line 4994 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 227: // enumerator: ID "=" expression
#line 1467 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < P4::P5::EnumItem* > () = new P4::P5::EnumItem(yystack_[2].location + yystack_[0].location, yystack_[2].value.as < IR::ID* > (), yystack_[0].value.as < IR::Expression* > ());
        }
#line 5002 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 228: // enumerator_list: enumerator
#line 1472 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 5017 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 229: // enumerator_list: enumerator_list "," enumerator
#line 1482 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
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
#line 5034 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 230: // enum_declaration: ENUM ID "{" enumerator_list "}"
#line 1497 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                const IR::Type* underlying = IR::Type_Bits::get(32, false);
                yylhs.value.as < IR::Type_Declaration* > () = new IR::Type_SerEnum(*yystack_[3].value.as < IR::ID* > (), underlying, *yystack_[1].value.as < IR::IndexedVector<IR::SerEnumMember>* > ());
        }
#line 5043 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 231: // struct_union_type_declaration: STRUCT ID "{" struct_field_list "}"
#line 1504 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Type_Struct* > () = new IR::Type_Struct(yystack_[3].location + yystack_[0].location, *yystack_[3].value.as < IR::ID* > (), *yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ());
        }
#line 5051 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 232: // struct_union_type_declaration: UNION ID "{" struct_field_list "}"
#line 1508 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                auto st = new IR::Type_Struct(yystack_[3].location + yystack_[0].location, *yystack_[3].value.as < IR::ID* > (), *yystack_[1].value.as < IR::IndexedVector<IR::StructField>* > ());
                st->annotations.push_back(new IR::Annotation("union", {}));
                yylhs.value.as < IR::Type_Struct* > () = st;
        }
#line 5061 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 233: // type_declaration: struct_union_type_declaration ";"
#line 1516 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                            { yylhs.value.as < IR::Type_Declaration* > () = yystack_[1].value.as < IR::Type_Struct* > (); }
#line 5067 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 234: // type_declaration: enum_declaration ";"
#line 1517 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                               { yylhs.value.as < IR::Type_Declaration* > () = yystack_[1].value.as < IR::Type_Declaration* > (); }
#line 5073 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 235: // type_declaration: typedef_declaration ";"
#line 1518 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                                   { yylhs.value.as < IR::Type_Declaration* > () = yystack_[1].value.as < IR::Type_Typedef* > (); }
#line 5079 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 236: // function_declaration: type_ref ID "(" param_list ")" action_compound_statement
#line 1522 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                cstring funcName = yystack_[4].value.as < IR::ID* > ()->name;  // ID* -> cstring
                auto funcType = new IR::Type_Method(yystack_[5].location + yystack_[1].location, yystack_[5].value.as < const IR::Type* > (), yystack_[2].value.as < IR::ParameterList* > (), funcName);
                yylhs.value.as < IR::Function* > () = new IR::Function(yystack_[4].location + yystack_[0].location, funcName, funcType, yystack_[0].value.as < IR::BlockStatement* > ());
        }
#line 5089 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 238: // declaration: annotations constant_declaration
#line 1540 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Constant* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Declaration_Constant* > ();
        }
#line 5098 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 239: // declaration: annotations ";"
#line 1544 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                          {
                // Standalone annotation statement (e.g. @u_version(...);).
                // Ignore it completely and keep parsing.
                yylhs.value.as < IR::Node* > () = nullptr;
        }
#line 5108 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 240: // declaration: annotations type_declaration
#line 1550 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Type_Declaration* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Type_Declaration* > ();
        }
#line 5117 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 241: // declaration: annotations header_declaration
#line 1555 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Declaration* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Declaration* > ();
        }
#line 5126 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 242: // declaration: annotations table_declaration
#line 1560 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::P5Table* > ();
        }
#line 5134 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 244: // declaration: annotations variable_declaration
#line 1565 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Declaration_Variable* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Declaration_Variable* > ();
        }
#line 5143 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 245: // declaration: annotations function_declaration
#line 1570 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                attachAnnotations(yystack_[0].value.as < IR::Function* > (), yystack_[1].value.as < IR::Vector<IR::Annotation>* > ());
                yylhs.value.as < IR::Node* > () = yystack_[0].value.as < IR::Function* > ();
        }
#line 5152 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 246: // declaration_list: declaration
#line 1577 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                yylhs.value.as < IR::Vector<IR::Node>* > () = new IR::IndexedVector<IR::Node>();
                if (yystack_[0].value.as < IR::Node* > ()) yylhs.value.as < IR::Vector<IR::Node>* > ()->push_back(yystack_[0].value.as < IR::Node* > ());
        }
#line 5161 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 247: // declaration_list: declaration_list declaration
#line 1582 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
        {
                if (yystack_[0].value.as < IR::Node* > ()) yystack_[1].value.as < IR::Vector<IR::Node>* > ()->push_back(yystack_[0].value.as < IR::Node* > ());
                yylhs.value.as < IR::Vector<IR::Node>* > () = yystack_[1].value.as < IR::Vector<IR::Node>* > ();
        }
#line 5170 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 249: // input: input declaration
#line 1590 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                             {
                if (yystack_[0].value.as < IR::Node* > ()) driver.nodes->push_back(yystack_[0].value.as < IR::Node* > ()->getNode());
        }
#line 5178 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;

  case 250: // input: input ";"
#line 1593 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
                           {}
#line 5184 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"
    break;


#line 5188 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"

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


  const short P5Parser::yypact_ninf_ = -447;

  const short P5Parser::yytable_ninf_ = -152;

  const short
  P5Parser::yypact_[] =
  {
    -447,   142,   122,  -447,  -447,  -447,   619,  -447,   115,  -447,
     362,   115,   115,   247,   115,   115,   362,   115,   346,   165,
    -447,   362,   115,  -447,    64,  -447,  -447,   115,  -447,  -447,
    -447,  -447,   305,   360,   379,  -447,  -447,  -447,   450,   115,
    -447,   567,   476,    67,   500,   533,   115,   538,    67,   115,
     115,   573,   115,   115,   294,  -447,  -447,  -447,  -447,   491,
      33,   467,   398,   115,   491,   491,   491,  -447,  -447,  -447,
     539,  -447,  -447,   303,  -447,  -447,    98,  -447,  -447,  -447,
    -447,   361,   507,    38,   467,   398,  -447,   288,   467,   491,
     491,  -447,   211,    30,   164,   164,   164,   164,   563,  -447,
    -447,   499,   371,   279,   528,   485,   547,   551,   556,   544,
      58,  -447,   591,   468,   491,   491,   491,   117,  -447,   480,
     607,   598,   600,   203,  -447,    36,   605,  -447,   445,   274,
     446,   399,    30,   211,  -447,   321,   115,  -447,   620,   187,
    -447,  -447,  -447,   621,   623,  -447,  -447,   491,  -447,   482,
      82,   115,  -447,   493,   174,    25,   374,   629,   491,   466,
    -447,  -447,  -447,  -447,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   491,   164,  -447,  -447,   491,   322,    51,    41,   129,
     632,  -447,   635,   636,   638,    29,   115,   687,  -447,  -447,
    -447,   589,  -447,  -447,  -447,   491,  -447,   115,  -447,  -447,
    -447,   491,    98,   641,   591,  -447,  -447,   637,  -447,   429,
    -447,  -447,  -447,    48,    55,   115,  -447,  -447,  -447,   408,
     642,  -447,   613,   644,   298,  -447,    30,   164,   469,   491,
    -447,  -447,  -447,   499,   499,   371,   371,   279,   279,   279,
     279,   528,   528,   485,   547,   551,   556,   527,   544,   591,
     639,  -447,   564,   115,   402,   398,  -447,   647,    76,   495,
     588,  -447,   491,   351,   491,  -447,   491,  -447,   491,   491,
     491,   491,   491,   491,   491,   491,  -447,   591,  -447,   437,
    -447,   491,  -447,   491,  -447,   652,  -447,   657,   369,   615,
     398,  -447,  -447,  -447,   491,   491,  -447,    32,  -447,  -447,
     164,   491,   491,   417,   656,   491,    85,  -447,   229,    98,
    -447,   662,  -447,   665,    81,   588,   666,   667,   496,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,  -447,
    -447,   440,   670,  -447,   672,  -447,   491,   491,  -447,  -447,
     265,   674,   441,   184,  -447,   186,    60,   663,   491,  -447,
     591,  -447,   163,  -447,   675,  -447,    76,   680,  -447,   669,
     345,  -447,  -447,  -447,  -447,   562,  -447,  -447,  -447,   157,
     681,   171,   683,   442,   206,  -447,  -447,    77,  -447,  -447,
     597,  -447,   591,   491,   682,  -447,  -447,   692,  -447,   697,
     498,   699,   368,  -447,   659,  -447,   704,   708,    72,   710,
    -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,  -447,
    -447,   664,   668,  -447,   671,   673,   126,  -447,   491,  -447,
     491,   314,  -447,   541,   712,  -447,  -447,   713,  -447,   115,
    -447,  -447,   645,  -447,   491,  -447,   718,   132,  -447,  -447,
     719,  -447,  -447,  -447,  -447,   491,  -447,   249,    20,   491,
     491,   720,   235,   330,  -447,   721,  -447,   722,   678,   723,
      50,   388,    62,   727,   491,  -447,   728,   509,   462,  -447,
    -447,   591,  -447,   235,  -447,  -447,  -447,  -447,   460,   491,
     724,  -447,  -447,   733,  -447,  -447,   491,   491,   491,  -447,
    -447,  -447,   735,   524,   526,  -447,   736,   691,   587,  -447,
    -447,   545,   738,  -447,   394,   396,   271,   685,   511,   740,
     695,   179,  -447,  -447,  -447,   742,  -447,  -447,  -447,    30,
    -447,   491,   734,  -447,   195,   511,  -447,  -447,   491,   739,
    -447,   234,  -447,    84,  -447,   745,  -447,   566,    57,  -447,
    -447,   245,   585,   262,  -447,    86,  -447,  -447,    57,  -447,
    -447,   280,  -447,  -447,  -447,  -447,  -447
  };

  const unsigned char
  P5Parser::yydefact_[] =
  {
     248,     0,    61,     1,     2,   250,     0,   249,     0,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,     0,     0,     4,    68,    62,    67,     0,   238,   241,
     244,   242,     0,     0,    65,   240,   245,    61,    59,     0,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   235,   234,   233,   243,     0,
       0,    61,    61,     0,     0,     0,     0,     3,     5,     8,
      72,     7,    12,     0,    13,    77,     6,    61,    61,   225,
      61,     0,     0,     0,    61,    61,    69,     0,    61,     0,
       0,    99,     0,     0,     0,     0,     0,     0,    17,    22,
      24,    28,    31,    34,    39,    42,    44,    46,    48,    50,
      52,    54,    57,     0,     0,     0,     0,     0,   137,     0,
       0,     0,     0,     0,   219,    61,   226,   228,     0,     0,
       0,     0,     0,   140,    64,     0,     0,   246,    61,     0,
      90,    91,    92,    61,    61,    63,   105,     0,    97,     0,
      61,     0,    70,     0,     0,     0,    72,     0,     0,     0,
      21,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    60,     0,     0,     0,     0,     0,
       0,    61,    61,     0,     0,    72,     0,   121,   217,   218,
     156,     0,   216,   224,   220,     0,   230,     0,     9,    11,
      10,     0,    76,     0,   139,    16,   141,    15,    75,     0,
      73,   237,   247,     0,     0,     0,   231,    93,   232,     0,
       0,   222,     0,     0,     0,   100,     0,     0,     0,     0,
      25,    26,    27,    29,    30,    33,    32,    36,    35,    38,
      37,    40,    41,    43,    45,    47,    49,     0,    51,    58,
       0,    94,     0,     0,   130,    61,   138,     0,     0,     0,
     187,   181,   140,     0,     0,   167,     0,   168,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   227,   229,     0,
      14,     0,    74,     0,    61,     0,    61,     0,     0,     0,
      61,    71,   181,   236,     0,     0,   101,    72,    23,    56,
       0,     0,     0,   132,     0,     0,    61,    61,    72,   121,
     123,     0,    61,     0,    61,   197,     0,    61,     0,   157,
     159,   158,   160,   161,   162,   163,   164,   166,   165,    79,
     142,     0,    61,    61,    61,    61,     0,     0,    80,    98,
      61,    61,     0,     0,    53,     0,     0,     0,     0,   135,
     131,   223,     0,   209,    61,    61,     0,    61,   211,     0,
       0,   188,   198,   212,   213,     0,   182,   122,    78,     0,
      61,     0,    61,     0,     0,   221,   183,     0,   102,    95,
       0,   134,   133,     0,     0,   215,   210,    61,   124,     0,
       0,     0,     0,   180,     0,    61,     0,     0,     0,     0,
     171,   170,   177,   178,   175,   173,   176,   174,   179,   172,
      84,     0,   231,    87,     0,   232,     0,    81,     0,   103,
       0,   111,   113,     0,   208,   214,    61,     0,   181,     0,
     186,   129,     0,    61,     0,   109,     0,     0,   128,   127,
      61,    86,    85,    89,    88,     0,    82,     0,     0,     0,
       0,   206,   202,     0,   193,    61,    61,    61,     0,     0,
       0,     0,     0,    61,   140,   108,     0,     0,     0,   104,
      96,   112,   114,   202,   199,   200,   201,   203,     0,     0,
       0,   196,   194,    61,   184,   185,     0,     0,     0,    61,
     107,   110,     0,     0,     0,   152,     0,     0,     0,   207,
     204,     0,   192,   195,     0,     0,     0,   144,     0,     0,
       0,     0,   152,    83,   205,   190,   187,   143,    61,     0,
      61,     0,     0,   119,     0,     0,   106,   155,     0,     0,
     153,     0,   187,    61,   147,     0,   145,     0,   118,   126,
     120,     0,     0,    61,   154,    61,   191,    61,   116,   117,
     125,    61,   150,   189,   146,   115,   148
  };

  const short
  P5Parser::yypgoto_[] =
  {
    -447,  -447,  -447,     4,  -447,  -447,   473,  -447,  -447,  -447,
     -67,   382,   438,   432,   434,   575,   576,   577,   578,   579,
    -447,   447,   309,   694,  -447,    -2,   627,    42,  -447,   -91,
    -447,  -447,  -135,   -79,    -3,  -447,     1,  -439,  -447,   302,
    -405,  -446,   228,  -255,  -344,  -447,  -447,  -447,  -187,   458,
     474,  -266,  -447,  -447,  -447,  -447,   244,  -447,   238,  -118,
    -381,  -280,   395,  -447,  -321,  -148,   306,  -447,   444,  -127,
     290,  -296,   406,  -114,   -68,  -447,  -447,   568,  -447,  -447,
     768,  -447,  -447,  -447,     0,  -447,  -447
  };

  const short
  P5Parser::yydefgoto_[] =
  {
       0,     1,    69,    70,    71,    72,    98,    74,   213,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   431,   113,    25,   139,    26,   196,    75,    76,
     140,   141,   142,   143,   484,    29,   485,   448,   472,   432,
     433,   533,   534,   200,   269,   449,   412,   413,   118,   119,
     216,   217,   414,   415,   416,   540,   521,   417,   201,   486,
     376,   327,   303,   371,   324,   464,   465,   325,   326,   487,
     488,   363,   364,   124,   125,    31,    32,   127,   128,    33,
      40,    35,    36,    37,     7,   138,     2
  };

  const short
  P5Parser::yytable_[] =
  {
       6,   144,   159,    28,   266,   202,   328,    30,   227,   227,
      24,   204,    38,   320,    24,    41,    42,   150,    44,    45,
      24,    47,   351,   400,   442,    24,    51,   160,   161,   162,
     163,    54,   197,   501,   272,     6,   204,    58,   -69,   158,
     183,   212,   114,    60,   203,   183,   236,   147,    27,   132,
      79,   115,    39,    82,    83,   294,    86,    87,    46,   117,
     123,   183,   296,    50,   445,    53,   497,   126,   396,   445,
     500,   183,    64,   181,    65,     6,    66,   137,   235,   445,
     183,    52,   117,   123,   511,   158,   117,     8,   550,   368,
     231,   148,   556,   361,   563,   428,   156,   240,   241,   242,
      53,   396,   182,   498,   261,   550,   477,   135,   120,   559,
     136,   398,   480,   -68,    23,   121,   -69,   122,   517,   565,
     198,    24,   116,   123,   199,     4,   547,   195,     8,   503,
     429,   262,    23,   552,   157,   455,     6,   474,   222,    23,
     220,    23,     3,    24,   446,   212,    23,   544,   123,   546,
     390,    23,    67,    68,   120,   232,    23,   120,   467,   189,
      23,   121,   369,   122,   121,   369,   122,   369,   263,    92,
     308,    65,   562,    66,     8,     5,   564,   319,    94,   456,
     566,   225,    13,    95,   234,   475,    96,   537,    15,   117,
     268,    17,    18,   264,   183,    20,    97,   316,     8,    23,
     273,    23,   204,   549,   183,   543,   183,   227,   504,   227,
     420,   126,   158,    23,     8,   342,    92,   344,    65,   393,
      66,   555,   394,    93,   423,    94,   183,   295,   297,   298,
      95,    49,   350,    96,   272,   538,   204,   388,   539,   389,
     307,    23,   554,    97,   158,   227,   132,   227,    23,    67,
      68,   531,    13,   560,   532,    23,   470,   418,   223,   427,
      10,   224,    18,   123,   380,    20,   382,   313,    13,   183,
    -151,    23,   318,   385,    15,   319,    13,    17,    18,    19,
     208,    20,    15,    43,   197,    17,    18,    23,  -149,    20,
     538,   183,    10,   539,   183,    23,    67,    68,   123,    88,
      13,   531,   479,    89,   532,   151,    15,   304,   133,    17,
      18,    19,    90,    20,   123,   362,   305,   492,  -151,    23,
     366,  -151,   370,   152,   529,   375,    92,   169,    65,   170,
      66,   218,   260,    93,   183,    94,  -149,   120,   134,  -149,
      95,     8,   183,    96,   121,   492,   122,    91,   123,   375,
      92,   306,    65,    97,    66,   459,     8,    93,    55,    94,
      89,   510,   362,   362,    95,   268,   133,    96,   112,    90,
     318,   197,   410,   129,   112,   131,   411,    97,   346,   195,
     -68,   510,    48,   421,   439,   424,   489,   347,   183,   490,
     167,   236,   197,   168,   499,   362,   145,   197,   154,   155,
     527,   129,   528,   375,    91,    23,    67,    68,   183,   210,
      53,   314,   447,    56,   183,   211,   183,   197,   299,   183,
     315,   440,   348,   186,   187,   188,   357,    13,   183,    23,
      67,    68,    57,    15,   463,   358,    17,    18,   197,   292,
      20,   117,   214,   468,   219,   293,    23,   339,   268,   183,
     378,   387,   426,   206,   209,    59,   229,   183,   207,   185,
     183,   183,   183,   463,   463,   375,   195,   238,   509,   158,
     120,   268,   507,  -136,   184,   135,   447,   121,   136,   122,
    -136,   185,   183,    63,   239,   211,   190,   195,   230,   183,
     257,   463,   195,   191,   259,   191,    92,   375,    65,   233,
      66,   321,   377,    93,   437,    94,   191,    77,   322,   291,
      95,   322,   195,    96,   287,   506,    73,    10,   175,   176,
     289,    81,   322,    97,   164,    13,   375,   165,   375,   166,
     519,    15,   520,   318,    17,    18,    19,   322,    20,   291,
      78,   370,   149,   310,    23,    80,   153,   183,   309,   243,
     244,   375,   447,   370,   460,   375,   132,   461,   460,   375,
     146,   525,   447,   171,   172,   173,   174,   531,   133,   302,
     532,   158,    61,     8,    62,    23,    67,    68,    84,   460,
      85,   214,   558,   329,   180,   330,   177,   331,   332,   333,
     334,   335,   336,   337,   338,   524,   158,   178,   460,   179,
     214,   561,   341,   247,   248,   249,   250,   245,   246,   251,
     252,   183,   192,   352,   353,   403,   193,   404,   194,    10,
     355,   356,   405,   205,   360,   406,   407,    13,   221,   226,
       8,   228,   408,    15,   409,   237,    17,    18,    19,   265,
      20,   267,   286,   270,    10,   271,    23,   290,   301,   300,
     291,   302,    13,   312,   317,   383,   384,   311,    15,   343,
     323,    17,    18,    19,   345,    20,   359,   392,   349,   365,
     367,    23,     9,   391,   373,   374,    10,    11,   379,   402,
     381,    12,   386,   395,    13,    14,   399,   401,   430,   422,
      15,   425,    16,    17,    18,    19,   135,    20,   434,   136,
     435,    21,    22,    23,   436,   274,   438,   275,   276,   443,
     277,   278,   441,   444,   279,   450,   280,   451,   281,   462,
     466,   452,   469,   473,   453,   476,   454,   483,   496,   491,
     494,   495,   282,   502,   283,   505,   284,   457,   285,   458,
     512,   513,   518,   522,   523,   526,   530,   535,   536,   542,
     548,   557,   253,   471,   254,   553,   255,   354,   256,   130,
     215,   258,   482,   551,   478,   340,   541,   545,   481,   372,
     419,   397,   493,   508,    34,   288,     0,     0,     0,     0,
       0,     0,     0,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   514,   515,   516
  };

  const short
  P5Parser::yycheck_[] =
  {
       2,    80,    93,     6,   191,   123,   272,     6,   143,   144,
       6,   125,     8,   268,    10,    11,    12,    85,    14,    15,
      16,    17,   302,   367,   405,    21,    22,    94,    95,    96,
      97,    27,   123,   472,     5,    37,   150,    37,     6,     9,
      20,   132,     9,    39,     8,    20,    17,     9,     6,    17,
      46,    18,    10,    49,    50,     7,    52,    53,    16,    61,
      62,    20,     7,    21,     7,    36,    16,    63,   364,     7,
       8,    20,     5,    15,     7,    77,     9,    77,    53,     7,
      20,    17,    84,    85,   489,     9,    88,    11,   534,     8,
       8,    53,     8,     8,     8,    18,    92,   164,   165,   166,
      36,   397,    44,    53,    53,   551,   450,     9,    72,   548,
      12,   366,    92,    84,    84,    79,    84,    81,   499,   558,
     123,   117,    89,   125,   123,     3,   531,   123,    11,   473,
      53,    90,    84,   538,    92,     9,   138,     5,   138,    84,
     136,    84,     0,   139,    72,   236,    84,   528,   150,   530,
      90,    84,    85,    86,    72,   151,    84,    72,   438,   117,
      84,    79,    81,    81,    79,    81,    81,    81,    39,     5,
     237,     7,   553,     9,    11,    53,   557,   268,    14,    53,
     561,   139,    65,    19,    10,    53,    22,     8,    71,   191,
     192,    74,    75,   189,    20,    78,    32,   265,    11,    84,
     196,    84,   316,     8,    20,   526,    20,   342,   474,   344,
      53,   207,     9,    84,    11,   294,     5,   296,     7,    56,
       9,   542,    59,    12,    53,    14,    20,   223,   224,   225,
      19,    66,   300,    22,     5,    56,   350,    53,    59,    53,
     236,    84,     8,    32,     9,   380,    17,   382,    84,    85,
      86,    56,    65,     8,    59,    84,   443,   375,    71,    53,
      57,    74,    75,   265,   343,    78,   345,   263,    65,    20,
       8,    84,   268,     8,    71,   366,    65,    74,    75,    76,
       6,    78,    71,    36,   375,    74,    75,    84,     8,    78,
      56,    20,    57,    59,    20,    84,    85,    86,   300,     5,
      65,    56,    53,     9,    59,    17,    71,     9,     5,    74,
      75,    76,    18,    78,   316,   317,    18,   465,    56,    84,
     322,    59,   324,    35,    53,   327,     5,    48,     7,    50,
       9,    10,    10,    12,    20,    14,    56,    72,    35,    59,
      19,    11,    20,    22,    79,   493,    81,    53,   350,   351,
       5,    53,     7,    32,     9,    41,    11,    12,    53,    14,
       9,   488,   364,   365,    19,   367,     5,    22,    59,    18,
     366,   462,   375,    64,    65,    66,   375,    32,     9,   375,
       6,   508,    36,   379,    16,   381,    56,    18,    20,    59,
      19,    17,   483,    22,     6,   397,    35,   488,    89,    90,
       6,    92,     6,   405,    53,    84,    85,    86,    20,    10,
      36,     9,   408,    53,    20,    16,    20,   508,    10,    20,
      18,    53,    53,   114,   115,   116,     9,    65,    20,    84,
      85,    86,    53,    71,   436,    18,    74,    75,   529,    10,
      78,   443,   133,   439,   135,    16,    84,    10,   450,    20,
      10,    10,    10,     8,     8,     5,   147,    20,    13,    13,
      20,    20,    20,   465,   466,   467,   462,   158,     8,     9,
      72,   473,    10,     6,     6,     9,   472,    79,    12,    81,
      13,    13,    20,     7,    18,    16,     6,   483,     6,    20,
     181,   493,   488,    13,   185,    13,     5,   499,     7,     6,
       9,     6,     6,    12,     6,    14,    13,     7,    13,    13,
      19,    13,   508,    22,   205,     6,    43,    57,    33,    34,
     211,    48,    13,    32,    25,    65,   528,    28,   530,    30,
       6,    71,     6,   529,    74,    75,    76,    13,    78,    13,
       7,   543,    84,    16,    84,     7,    88,    20,   239,   167,
     168,   553,   548,   555,    13,   557,    17,    16,    13,   561,
      53,    16,   558,    35,    36,    37,    38,    56,     5,     7,
      59,     9,     5,    11,     7,    84,    85,    86,     5,    13,
       7,   272,    16,   274,    40,   276,    39,   278,   279,   280,
     281,   282,   283,   284,   285,     8,     9,    46,    13,    43,
     291,    16,   293,   171,   172,   173,   174,   169,   170,   175,
     176,    20,     5,   304,   305,    53,    18,    55,    18,    57,
     311,   312,    60,    18,   315,    63,    64,    65,     8,     8,
      11,     8,    70,    71,    72,     6,    74,    75,    76,     7,
      78,     6,    53,     7,    57,     7,    84,     6,    35,     7,
      13,     7,    65,    89,     7,   346,   347,    18,    71,     7,
      72,    74,    75,    76,     7,    78,    10,   358,    53,     7,
       5,    84,    53,    10,     8,     8,    57,    58,     8,   370,
       8,    62,     8,     8,    65,    66,     6,    18,    91,     8,
      71,     8,    73,    74,    75,    76,     9,    78,    16,    12,
       8,    82,    83,    84,     7,    18,     7,    20,    21,     5,
      23,    24,    53,     5,    27,     5,    29,    53,    31,     7,
       7,    53,    77,     5,    53,     6,    53,     7,     5,     8,
       8,    53,    45,     6,    47,     7,    49,   428,    51,   430,
      16,     8,     7,     7,    53,     7,    61,     7,    53,     7,
      16,     6,   177,   444,   178,    16,   179,   310,   180,    65,
     133,   182,   460,   535,   455,   291,   522,   529,   459,   325,
     375,   365,   466,   483,     6,   207,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   496,   497,   498
  };

  const unsigned char
  P5Parser::yystos_[] =
  {
       0,    94,   179,     0,     3,    53,   118,   177,    11,    53,
      57,    58,    62,    65,    66,    71,    73,    74,    75,    76,
      78,    82,    83,    84,    96,   117,   119,   120,   127,   128,
     129,   168,   169,   172,   173,   174,   175,   176,    96,   120,
     173,    96,    96,    36,    96,    96,   120,    96,    36,    66,
     120,    96,    17,    36,    96,    53,    53,    53,   177,     5,
      96,     5,     7,     7,     5,     7,     9,    85,    86,    95,
      96,    97,    98,    99,   100,   121,   122,     7,     7,    96,
       7,    99,    96,    96,     5,     7,    96,    96,     5,     9,
      18,    53,     5,    12,    14,    19,    22,    32,    99,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     9,    18,    89,   118,   141,   142,
      72,    79,    81,   118,   166,   167,    96,   170,   171,   115,
     116,   115,    17,     5,    35,     9,    12,   177,   178,   118,
     123,   124,   125,   126,   126,    35,    53,     9,    53,   142,
     167,    17,    35,   142,   115,   115,    96,   120,     9,   122,
     103,   103,   103,   103,    25,    28,    30,    19,    22,    48,
      50,    35,    36,    37,    38,    33,    34,    39,    46,    43,
      40,    15,    44,    20,     6,    13,   115,   115,   115,   120,
       6,    13,     5,    18,    18,    96,   120,   122,   127,   129,
     136,   151,   152,     8,   166,    18,     8,    13,     6,     8,
      10,    16,   122,   101,   115,   119,   143,   144,    10,   115,
      96,     8,   177,    71,    74,   120,     8,   125,     8,   115,
       6,     8,    96,     6,    10,    53,    17,     6,   115,    18,
     103,   103,   103,   104,   104,   105,   105,   106,   106,   106,
     106,   107,   107,   108,   109,   110,   111,   115,   112,   115,
      10,    53,    90,    39,    96,     7,   141,     6,   118,   137,
       7,     7,     5,    96,    18,    20,    21,    23,    24,    27,
      29,    31,    45,    47,    49,    51,    53,   115,   170,   115,
       6,    13,    10,    16,     7,    96,     7,    96,    96,    10,
       7,    35,     7,   155,     9,    18,    53,    96,   103,   115,
      16,    18,    89,    96,     9,    18,   167,     7,    96,   122,
     136,     6,    13,    72,   157,   160,   161,   154,   144,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,    10,
     143,   115,   126,     7,   126,     7,     9,    18,    53,    53,
     167,   154,   115,   115,   114,   115,   115,     9,    18,    10,
     115,     8,   118,   164,   165,     7,   118,     5,     8,    81,
     118,   156,   161,     8,     8,   118,   153,     6,    10,     8,
     126,     8,   126,   115,   115,     8,     8,    10,    53,    53,
      90,    10,   115,    56,    59,     8,   164,   165,   136,     6,
     137,    18,   115,    53,    55,    60,    63,    64,    70,    72,
     127,   129,   139,   140,   145,   146,   147,   150,   152,   155,
      53,    96,     8,    53,    96,     8,    10,    53,    18,    53,
      91,   115,   132,   133,    16,     8,     7,     6,     7,    16,
      53,    53,   153,     5,     5,     7,    72,    96,   130,   138,
       5,    53,    53,    53,    53,     9,    53,   115,   115,    41,
      13,    16,     7,   118,   158,   159,     7,   154,    96,    77,
     141,   115,   131,     5,     5,    53,     6,   137,   115,    53,
      92,   115,   132,     7,   127,   129,   152,   162,   163,    56,
      59,     8,   158,   159,     8,    53,     5,    16,    53,     6,
       8,   130,     6,   137,   144,     7,     6,    10,   163,     8,
     162,   133,    16,     8,   115,   115,   115,   153,     7,     6,
       6,   149,     7,    53,     8,    16,     7,     6,     6,    53,
      61,    56,    59,   134,   135,     7,    53,     8,    56,    59,
     148,   149,     7,   157,   153,   151,   153,   133,    16,     8,
     134,   135,   133,    16,     8,   157,     8,     6,    16,   130,
       8,    16,   153,     8,   153,   130,   153
  };

  const unsigned char
  P5Parser::yyr1_[] =
  {
       0,    93,    94,    95,    96,    97,    98,    98,    98,    98,
      98,    98,    99,    99,   100,   101,   101,   102,   102,   102,
     102,   102,   103,   103,   104,   104,   104,   104,   105,   105,
     105,   106,   106,   106,   107,   107,   107,   107,   107,   108,
     108,   108,   109,   109,   110,   110,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   115,   116,   116,   117,
     117,   118,   118,   119,   119,   119,   119,   120,   120,   120,
     120,   120,   121,   121,   121,   121,   121,   122,   122,   122,
     123,   123,   123,   123,   124,   124,   124,   124,   124,   124,
     125,   125,   126,   126,   127,   127,   127,   128,   128,   129,
     129,   129,   129,   129,   129,   129,   130,   130,   130,   131,
     131,   132,   132,   133,   133,   134,   134,   134,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   139,   139,   140,
     141,   141,   141,   141,   141,   141,   142,   142,   142,   143,
     144,   144,   144,   145,   146,   146,   147,   147,   148,   148,
     148,   148,   149,   149,   150,   150,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   152,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   154,   154,   155,   156,   156,   156,   157,   157,   158,
     158,   158,   158,   159,   159,   160,   160,   161,   161,   162,
     162,   162,   163,   163,   163,   164,   164,   164,   164,   165,
     165,   166,   166,   166,   166,   166,   166,   166,   166,   167,
     167,   168,   168,   168,   168,   169,   170,   170,   171,   171,
     172,   173,   173,   174,   174,   174,   175,   176,   177,   177,
     177,   177,   177,   177,   177,   177,   178,   178,   179,   179,
     179
  };

  const signed char
  P5Parser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     1,     4,     1,     1,     1,     2,     2,
       2,     2,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     2,     4,     1,     3,     2,
       5,     0,     2,     4,     4,     1,     1,     1,     1,     3,
       4,     6,     1,     3,     4,     3,     3,     1,     6,     5,
       4,     6,     7,    10,     6,     7,     7,     6,     7,     7,
       1,     1,     1,     2,     6,     9,    12,     4,     7,     3,
       5,     6,     8,     9,    11,     4,     5,     3,     2,     0,
       2,     1,     3,     1,     3,     4,     3,     3,     2,     1,
       2,     1,     4,     2,     4,     7,     6,     2,     2,     2,
       3,     5,     4,     6,     6,     5,     0,     1,     3,     1,
       0,     1,     3,     6,     5,     7,     9,     7,     4,     3,
       3,     2,     0,     2,     7,     6,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     0,     2,     3,     5,     5,     3,     0,     2,     7,
       4,     6,     3,     1,     2,     7,     6,     1,     2,     1,
       1,     1,     0,     1,     2,     7,     4,     6,     3,     1,
       2,     5,     5,     5,     7,     6,     2,     2,     2,     1,
       2,     8,     5,     8,     5,     3,     1,     3,     1,     3,
       5,     5,     5,     2,     2,     2,     6,     5,     2,     2,
       2,     2,     2,     3,     2,     2,     1,     2,     0,     2,
       2
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
  "method_call", "method_args", "unary_expression", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "expression", "expression_list", "annotation",
  "annotations", "type_ref_explicit", "type_ref", "field_ref_no_slice",
  "field_ref", "field_dec", "anonymous_struct_union_dec",
  "struct_field_dec", "struct_field_list", "constant_declaration",
  "header_declaration", "variable_declaration", "return_value_type",
  "return_value_type_list", "value_masked_or_set", "value_list",
  "case_entry", "case_list", "field_ref_or_func", "select_exp",
  "return_select_statement", "return_statement", "break_statement",
  "parameter", "param_list", "arg", "arg_list", "do_while_statement",
  "conditional_statement", "for_loop_statement", "case", "switch_cases",
  "switch_statement", "assignment_or_call", "assignment_or_call_statement",
  "action_statement", "action_statement_list", "action_compound_statement",
  "key_element", "key_element_list", "key_case_entry", "key_case_list",
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
       0,   335,   335,   344,   348,   358,   361,   362,   363,   364,
     365,   366,   370,   371,   375,   384,   388,   396,   397,   398,
     399,   400,   404,   405,   409,   410,   411,   412,   416,   418,
     419,   423,   424,   425,   429,   430,   431,   432,   433,   437,
     438,   439,   443,   444,   448,   449,   453,   454,   458,   459,
     463,   464,   468,   469,   473,   475,   480,   490,   493,   504,
     510,   517,   520,   535,   543,   551,   554,   560,   561,   565,
     569,   573,   579,   581,   582,   583,   584,   589,   590,   591,
     594,   601,   609,   617,   628,   637,   646,   655,   666,   676,
     688,   689,   693,   699,   713,   717,   722,   730,   734,   740,
     741,   742,   746,   750,   755,   760,   769,   775,   776,   782,
     785,   791,   792,   795,   801,   808,   819,   825,   836,   844,
     849,   856,   859,   866,   872,   879,   882,   887,   888,   891,
     899,   906,   913,   920,   927,   937,   949,   950,   955,   963,
     966,   967,   973,   981,   997,  1003,  1014,  1034,  1072,  1082,
    1088,  1097,  1104,  1105,  1111,  1114,  1119,  1126,  1129,  1133,
    1137,  1141,  1145,  1149,  1153,  1157,  1161,  1165,  1170,  1177,
    1180,  1184,  1188,  1192,  1193,  1194,  1195,  1196,  1197,  1198,
    1199,  1205,  1206,  1212,  1221,  1226,  1233,  1241,  1244,  1250,
    1259,  1270,  1279,  1291,  1296,  1302,  1307,  1312,  1317,  1324,
    1325,  1326,  1329,  1332,  1337,  1343,  1353,  1358,  1368,  1375,
    1381,  1389,  1394,  1399,  1404,  1407,  1410,  1413,  1416,  1422,
    1426,  1434,  1437,  1440,  1443,  1455,  1462,  1466,  1472,  1482,
    1496,  1503,  1507,  1516,  1517,  1518,  1521,  1529,  1539,  1544,
    1549,  1554,  1559,  1563,  1564,  1569,  1576,  1581,  1589,  1590,
    1593
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
#line 6105 "/root/p4c/build/frontends/parsers/p5/p5parser.cpp"

#line 1596 "/root/p4c/frontends/parsers/p5/p5parser.ypp"


namespace P4 {

void P5::P5Parser::error(const Util::SourceInfo& location,
                         const std::string& message) {
    driver.onParseError(location, message);
}

}  // namespace P4
