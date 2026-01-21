// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file /root/p4c/build/frontends/parsers/p5/p5parser.hpp
 ** Define the P4::P5::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_ROOT_P4C_BUILD_FRONTENDS_PARSERS_P5_P5PARSER_HPP_INCLUDED
# define YY_YY_ROOT_P4C_BUILD_FRONTENDS_PARSERS_P5_P5PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 23 "/root/p4c/frontends/parsers/p5/p5parser.ypp"

// 在 %code requires 顶部加入
#include <vector>

namespace P4 {
namespace P5 {

// 简单 POD，不继承 IR::Node，避免必须实现 clone() 等纯虚函数
struct TableCase {
    Util::SourceInfo srcInfo;
    IR::Vector<IR::Expression>* keys;
    IR::Vector<IR::StatOrDecl>* actions;

    TableCase(const Util::SourceInfo &s,
              IR::Vector<IR::Expression>* k = nullptr,
              IR::Vector<IR::StatOrDecl>* a = nullptr)
        : srcInfo(s), keys(k), actions(a) {}
};

// 使用 std::vector 指针作为列表，避免实例化 IR::Vector<...>
using TableCaseList = std::vector<TableCase*>*;

struct EnumItem {
    Util::SourceInfo srcInfo;
    IR::ID* name;
    IR::Expression* value;
    EnumItem(const Util::SourceInfo &s, IR::ID* n, IR::Expression* v)
        : srcInfo(s), name(n), value(v) {}
};

}  // namespace P5
}  // namespace P4

#include "ir/ir.h"
#include "frontends/parsers/caseValue.h"

namespace P4 {
namespace P5 {
class P5Lexer;
class P5ParserDriver;

using namespace P4::literals;

struct BBoxType {
    IR::Vector<IR::Method>* methods;
    IR::NameMap<IR::Attribute, ordered_map>* attribs;
};

struct HeaderType {
    IR::Vector<IR::Annotation>* annotations;
    IR::IndexedVector<IR::StructField>* fields;
};

struct Attributes {
    bool signed_ = false;
    bool saturating = false;
    IR::Vector<IR::Annotation> annotations;
    Attributes &merge(const Attributes &a) {
        signed_ |= a.signed_;
        saturating |= a.saturating;
        annotations.append(a.annotations);
        return *this; }
};

}  // namespace P5

inline std::ostream& operator<<(std::ostream& out, const P5::BBoxType& bboxType) {
    out << "BBoxType(" << bboxType.methods << ',' << bboxType.attribs << ')';
    return out;
}

inline std::ostream& operator<<(std::ostream& out, const P5::HeaderType& headerType) {
    out << "HeaderType(" << headerType.annotations << ',' << headerType.fields << ')';
    return out;
}

inline std::ostream& operator<<(std::ostream& out, const P5::Attributes& a) {
    return out << "Attributes(" << (a.signed_ ? "signed," : "") <<
                  (a.saturating ? "saturating," : "") << a.annotations << ')'; }

inline void attachAnnotations(IR::Node *node, IR::Vector<IR::Annotation> *annotations) {
    if (!node || !annotations) return;
    if (auto *annotated = dynamic_cast<IR::IAnnotated *>(node)) {
        for (auto *ann : *annotations) annotated->addAnnotation(ann);
    }
}


// Bison uses the types you provide to %type to make constructors for the
// variant type it uses under the hood, but its code generation is a little
// naive and it always prepends 'const' to the type. This is problematic when
// the symbol type we want is itself const, since duplicate const qualifiers are
// forbidden in C++. We avoid the problem using a typedef.
typedef const IR::Type ConstType;

}  // namespace P4

#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#define YY_NULLPTR nullptr

#include "frontends/common/constantParsing.h"
#include "lib/cstring.h"
#include "lib/error.h"
#include "lib/source_file.h"

#line 158 "/root/p4c/build/frontends/parsers/p5/p5parser.hpp"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif

#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 7 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
namespace P4 { namespace P5 {
#line 299 "/root/p4c/build/frontends/parsers/p5/p5parser.hpp"




  /// A Bison parser.
  class P5Parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // annotation
      char dummy1[sizeof (IR::Annotation*)];

      // arg
      char dummy2[sizeof (IR::Argument*)];

      // return_value_type_list
      // action_statement_list
      // action_compound_statement
      // program_selection_statement_list
      // table_property_list
      char dummy3[sizeof (IR::BlockStatement*)];

      // const_value
      char dummy4[sizeof (IR::Constant*)];

      // header_declaration
      char dummy5[sizeof (IR::Declaration*)];

      // constant_declaration
      char dummy6[sizeof (IR::Declaration_Constant*)];

      // variable_declaration
      char dummy7[sizeof (IR::Declaration_Variable*)];

      // primary_expression
      // postfix_expression
      // unary_expression
      // cast_expression
      // multiplicative_expression
      // additive_expression
      // shift_expression
      // relational_expression
      // equality_expression
      // and_expression
      // exclusive_or_expression
      // inclusive_or_expression
      // logical_and_expression
      // logical_or_expression
      // conditional_expression
      // expression
      // field_ref_no_slice
      // field_ref
      // value_masked_or_set
      // field_ref_or_func
      char dummy8[sizeof (IR::Expression*)];

      // function_declaration
      char dummy9[sizeof (IR::Function*)];

      // ID
      char dummy10[sizeof (IR::ID*)];

      // enumerator_list
      char dummy11[sizeof (IR::IndexedVector<IR::SerEnumMember>*)];

      // struct_field_list
      char dummy12[sizeof (IR::IndexedVector<IR::StructField>*)];

      // select_exp
      char dummy13[sizeof (IR::ListExpression*)];

      // declaration
      char dummy14[sizeof (IR::Node*)];

      // key_case_entry
      char dummy15[sizeof (IR::P5KeyCase*)];

      // key_element
      char dummy16[sizeof (IR::P5KeyElement*)];

      // key_switch_entry
      char dummy17[sizeof (IR::P5KeySwitch*)];

      // table_declaration
      char dummy18[sizeof (IR::P5Table*)];

      // parameter
      char dummy19[sizeof (IR::Parameter*)];

      // param_list
      char dummy20[sizeof (IR::ParameterList*)];

      // action_statement
      // program_selection_statement
      // table_property
      char dummy21[sizeof (IR::StatOrDecl*)];

      // return_value_type
      // return_select_statement
      // return_statement
      // break_statement
      // do_while_statement
      // conditional_statement
      // for_loop_statement
      // switch_statement
      // assignment_or_call_statement
      char dummy22[sizeof (IR::Statement*)];

      // string_lit
      char dummy23[sizeof (IR::StringLiteral*)];

      // field_dec
      // anonymous_struct_union_dec
      // struct_field_dec
      char dummy24[sizeof (IR::StructField*)];

      // case_entry
      // case
      // table_case_entry
      char dummy25[sizeof (IR::SwitchCase*)];

      // enum_declaration
      // type_declaration
      char dummy26[sizeof (IR::Type_Declaration*)];

      // struct_union_type_declaration
      char dummy27[sizeof (IR::Type_Struct*)];

      // typedef_declaration
      char dummy28[sizeof (IR::Type_Typedef*)];

      // annotations
      char dummy29[sizeof (IR::Vector<IR::Annotation>*)];

      // arg_list
      char dummy30[sizeof (IR::Vector<IR::Argument>*)];

      // expression_list
      // value_list
      char dummy31[sizeof (IR::Vector<IR::Expression>*)];

      // declaration_list
      char dummy32[sizeof (IR::Vector<IR::Node>*)];

      // key_case_list
      char dummy33[sizeof (IR::Vector<IR::P5KeyCase>*)];

      // key_element_list
      char dummy34[sizeof (IR::Vector<IR::P5KeyElement>*)];

      // key_switch_list
      char dummy35[sizeof (IR::Vector<IR::P5KeySwitch>*)];

      // case_list
      // switch_cases
      // table_case_list
      char dummy36[sizeof (IR::Vector<IR::SwitchCase>*)];

      // enumerator
      char dummy37[sizeof (P4::P5::EnumItem*)];

      // INTEGER
      char dummy38[sizeof (UnparsedConstant)];

      // type_ref
      char dummy39[sizeof (const IR::Type*)];

      // BREAK
      // CASE
      // CONST
      // CLASS
      // DEFAULT
      // DO
      // ELSE
      // ENUM
      // FOR
      // IF
      // INT
      // NAMESPACE
      // PRIVATE
      // PROTECTED
      // PUBLIC
      // RETURN
      // STRUCT
      // SWITCH
      // TYPEDEF
      // UNION
      // UINT
      // USING
      // WHILE
      // VOID
      // KEY
      // SIZE
      // CONTROL_PARAMETERS
      // HEADER
      // TABLE
      // IDENTIFIER
      // STRING_LITERAL
      char dummy40[sizeof (cstring)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef P4::Util::SourceInfo location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOK_YYEMPTY = -2,
    TOK_YYEOF = 0,                 // "end of file"
    TOK_YYerror = 256,             // error
    TOK_YYUNDEF = 257,             // "invalid token"
    TOK_END = 258,                 // END
    TOK_UNEXPECTED_TOKEN = 259,    // UNEXPECTED_TOKEN
    TOK_L_PAREN = 260,             // "("
    TOK_R_PAREN = 261,             // ")"
    TOK_L_BRACE = 262,             // "{"
    TOK_R_BRACE = 263,             // "}"
    TOK_L_BRACKET = 264,           // "["
    TOK_R_BRACKET = 265,           // "]"
    TOK_AT = 266,                  // "@"
    TOK_DOT = 267,                 // "."
    TOK_COMMA = 268,               // ","
    TOK_COMPLEMENT = 269,          // "~"
    TOK_QUESTION = 270,            // "?"
    TOK_COLON = 271,               // ":"
    TOK_SCOPE = 272,               // "::"
    TOK_ASSIGN = 273,              // "="
    TOK_PLUS = 274,                // "+"
    TOK_PP = 275,                  // "++"
    TOK_ASSIGN_PLUS = 276,         // "+="
    TOK_MINUS = 277,               // "-"
    TOK_MM = 278,                  // "--"
    TOK_ASSIGN_MINUS = 279,        // "-="
    TOK_MUL = 280,                 // "*"
    TOK_POW = 281,                 // "**"
    TOK_ASSIGN_MUL = 282,          // "*="
    TOK_DIV = 283,                 // "/"
    TOK_ASSIGN_DIV = 284,          // "/="
    TOK_MOD = 285,                 // "%"
    TOK_ASSIGN_MOD = 286,          // "%="
    TOK_NOT = 287,                 // "!"
    TOK_EQ_OP = 288,               // "=="
    TOK_NE_OP = 289,               // "!="
    TOK_R_ANGLE = 290,             // ">"
    TOK_L_ANGLE = 291,             // "<"
    TOK_GE = 292,                  // ">="
    TOK_LE = 293,                  // "<="
    TOK_BIT_AND = 294,             // "&"
    TOK_AND_OP = 295,              // "&&"
    TOK_MASK = 296,                // "&&&"
    TOK_ASSIGN_BIT_AND = 297,      // "&="
    TOK_BIT_OR = 298,              // "|"
    TOK_OR_OP = 299,               // "||"
    TOK_ASSIGN_BIT_OR = 300,       // "|="
    TOK_BIT_XOR = 301,             // "^"
    TOK_ASSIGN_BIT_XOR = 302,      // "^="
    TOK_RIGHT_OP = 303,            // ">>"
    TOK_ASSIGN_SHR = 304,          // ">>="
    TOK_LEFT_OP = 305,             // "<<"
    TOK_ASSIGN_SHL = 306,          // "<<="
    TOK_SHARP = 307,               // "#"
    TOK_SEMICOLON = 308,           // ";"
    TOK_NEWLINE = 309,             // NEWLINE
    TOK_BREAK = 310,               // BREAK
    TOK_CASE = 311,                // CASE
    TOK_CONST = 312,               // CONST
    TOK_CLASS = 313,               // CLASS
    TOK_DEFAULT = 314,             // DEFAULT
    TOK_DO = 315,                  // DO
    TOK_ELSE = 316,                // ELSE
    TOK_ENUM = 317,                // ENUM
    TOK_FOR = 318,                 // FOR
    TOK_IF = 319,                  // IF
    TOK_INT = 320,                 // INT
    TOK_NAMESPACE = 321,           // NAMESPACE
    TOK_PRIVATE = 322,             // PRIVATE
    TOK_PROTECTED = 323,           // PROTECTED
    TOK_PUBLIC = 324,              // PUBLIC
    TOK_RETURN = 325,              // RETURN
    TOK_STRUCT = 326,              // STRUCT
    TOK_SWITCH = 327,              // SWITCH
    TOK_TYPEDEF = 328,             // TYPEDEF
    TOK_UNION = 329,               // UNION
    TOK_UINT = 330,                // UINT
    TOK_USING = 331,               // USING
    TOK_WHILE = 332,               // WHILE
    TOK_VOID = 333,                // VOID
    TOK_KEY = 334,                 // KEY
    TOK_SIZE = 335,                // SIZE
    TOK_CONTROL_PARAMETERS = 336,  // CONTROL_PARAMETERS
    TOK_HEADER = 337,              // HEADER
    TOK_TABLE = 338,               // TABLE
    TOK_IDENTIFIER = 339,          // IDENTIFIER
    TOK_STRING_LITERAL = 340,      // STRING_LITERAL
    TOK_INTEGER = 341,             // INTEGER
    TOK_LPAREN_PREC = 342,         // LPAREN_PREC
    TOK_THEN = 343                 // THEN
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 93, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_END = 3,                               // END
        S_UNEXPECTED_TOKEN = 4,                  // UNEXPECTED_TOKEN
        S_L_PAREN = 5,                           // "("
        S_R_PAREN = 6,                           // ")"
        S_L_BRACE = 7,                           // "{"
        S_R_BRACE = 8,                           // "}"
        S_L_BRACKET = 9,                         // "["
        S_R_BRACKET = 10,                        // "]"
        S_AT = 11,                               // "@"
        S_DOT = 12,                              // "."
        S_COMMA = 13,                            // ","
        S_COMPLEMENT = 14,                       // "~"
        S_QUESTION = 15,                         // "?"
        S_COLON = 16,                            // ":"
        S_SCOPE = 17,                            // "::"
        S_ASSIGN = 18,                           // "="
        S_PLUS = 19,                             // "+"
        S_PP = 20,                               // "++"
        S_ASSIGN_PLUS = 21,                      // "+="
        S_MINUS = 22,                            // "-"
        S_MM = 23,                               // "--"
        S_ASSIGN_MINUS = 24,                     // "-="
        S_MUL = 25,                              // "*"
        S_POW = 26,                              // "**"
        S_ASSIGN_MUL = 27,                       // "*="
        S_DIV = 28,                              // "/"
        S_ASSIGN_DIV = 29,                       // "/="
        S_MOD = 30,                              // "%"
        S_ASSIGN_MOD = 31,                       // "%="
        S_NOT = 32,                              // "!"
        S_EQ_OP = 33,                            // "=="
        S_NE_OP = 34,                            // "!="
        S_R_ANGLE = 35,                          // ">"
        S_L_ANGLE = 36,                          // "<"
        S_GE = 37,                               // ">="
        S_LE = 38,                               // "<="
        S_BIT_AND = 39,                          // "&"
        S_AND_OP = 40,                           // "&&"
        S_MASK = 41,                             // "&&&"
        S_ASSIGN_BIT_AND = 42,                   // "&="
        S_BIT_OR = 43,                           // "|"
        S_OR_OP = 44,                            // "||"
        S_ASSIGN_BIT_OR = 45,                    // "|="
        S_BIT_XOR = 46,                          // "^"
        S_ASSIGN_BIT_XOR = 47,                   // "^="
        S_RIGHT_OP = 48,                         // ">>"
        S_ASSIGN_SHR = 49,                       // ">>="
        S_LEFT_OP = 50,                          // "<<"
        S_ASSIGN_SHL = 51,                       // "<<="
        S_SHARP = 52,                            // "#"
        S_SEMICOLON = 53,                        // ";"
        S_NEWLINE = 54,                          // NEWLINE
        S_BREAK = 55,                            // BREAK
        S_CASE = 56,                             // CASE
        S_CONST = 57,                            // CONST
        S_CLASS = 58,                            // CLASS
        S_DEFAULT = 59,                          // DEFAULT
        S_DO = 60,                               // DO
        S_ELSE = 61,                             // ELSE
        S_ENUM = 62,                             // ENUM
        S_FOR = 63,                              // FOR
        S_IF = 64,                               // IF
        S_INT = 65,                              // INT
        S_NAMESPACE = 66,                        // NAMESPACE
        S_PRIVATE = 67,                          // PRIVATE
        S_PROTECTED = 68,                        // PROTECTED
        S_PUBLIC = 69,                           // PUBLIC
        S_RETURN = 70,                           // RETURN
        S_STRUCT = 71,                           // STRUCT
        S_SWITCH = 72,                           // SWITCH
        S_TYPEDEF = 73,                          // TYPEDEF
        S_UNION = 74,                            // UNION
        S_UINT = 75,                             // UINT
        S_USING = 76,                            // USING
        S_WHILE = 77,                            // WHILE
        S_VOID = 78,                             // VOID
        S_KEY = 79,                              // KEY
        S_SIZE = 80,                             // SIZE
        S_CONTROL_PARAMETERS = 81,               // CONTROL_PARAMETERS
        S_HEADER = 82,                           // HEADER
        S_TABLE = 83,                            // TABLE
        S_IDENTIFIER = 84,                       // IDENTIFIER
        S_STRING_LITERAL = 85,                   // STRING_LITERAL
        S_INTEGER = 86,                          // INTEGER
        S_LPAREN_PREC = 87,                      // LPAREN_PREC
        S_THEN = 88,                             // THEN
        S_89_ = 89,                              // '['
        S_90_ = 90,                              // ']'
        S_91_ = 91,                              // '='
        S_92_ = 92,                              // ';'
        S_YYACCEPT = 93,                         // $accept
        S_program = 94,                          // program
        S_string_lit = 95,                       // string_lit
        S_ID = 96,                               // ID
        S_const_value = 97,                      // const_value
        S_primary_expression = 98,               // primary_expression
        S_postfix_expression = 99,               // postfix_expression
        S_unary_expression = 100,                // unary_expression
        S_cast_expression = 101,                 // cast_expression
        S_multiplicative_expression = 102,       // multiplicative_expression
        S_additive_expression = 103,             // additive_expression
        S_shift_expression = 104,                // shift_expression
        S_relational_expression = 105,           // relational_expression
        S_equality_expression = 106,             // equality_expression
        S_and_expression = 107,                  // and_expression
        S_exclusive_or_expression = 108,         // exclusive_or_expression
        S_inclusive_or_expression = 109,         // inclusive_or_expression
        S_logical_and_expression = 110,          // logical_and_expression
        S_logical_or_expression = 111,           // logical_or_expression
        S_conditional_expression = 112,          // conditional_expression
        S_expression = 113,                      // expression
        S_expression_list = 114,                 // expression_list
        S_annotation = 115,                      // annotation
        S_annotations = 116,                     // annotations
        S_type_ref = 117,                        // type_ref
        S_field_ref_no_slice = 118,              // field_ref_no_slice
        S_field_ref = 119,                       // field_ref
        S_field_dec = 120,                       // field_dec
        S_anonymous_struct_union_dec = 121,      // anonymous_struct_union_dec
        S_struct_field_dec = 122,                // struct_field_dec
        S_struct_field_list = 123,               // struct_field_list
        S_constant_declaration = 124,            // constant_declaration
        S_header_declaration = 125,              // header_declaration
        S_variable_declaration = 126,            // variable_declaration
        S_return_value_type = 127,               // return_value_type
        S_return_value_type_list = 128,          // return_value_type_list
        S_value_masked_or_set = 129,             // value_masked_or_set
        S_value_list = 130,                      // value_list
        S_case_entry = 131,                      // case_entry
        S_case_list = 132,                       // case_list
        S_field_ref_or_func = 133,               // field_ref_or_func
        S_select_exp = 134,                      // select_exp
        S_return_select_statement = 135,         // return_select_statement
        S_return_statement = 136,                // return_statement
        S_break_statement = 137,                 // break_statement
        S_parameter = 138,                       // parameter
        S_param_list = 139,                      // param_list
        S_arg = 140,                             // arg
        S_arg_list = 141,                        // arg_list
        S_do_while_statement = 142,              // do_while_statement
        S_conditional_statement = 143,           // conditional_statement
        S_for_loop_statement = 144,              // for_loop_statement
        S_case = 145,                            // case
        S_switch_cases = 146,                    // switch_cases
        S_switch_statement = 147,                // switch_statement
        S_assignment_or_call_statement = 148,    // assignment_or_call_statement
        S_action_statement = 149,                // action_statement
        S_action_statement_list = 150,           // action_statement_list
        S_action_compound_statement = 151,       // action_compound_statement
        S_key_element = 152,                     // key_element
        S_key_element_list = 153,                // key_element_list
        S_key_case_entry = 154,                  // key_case_entry
        S_key_case_list = 155,                   // key_case_list
        S_key_switch_entry = 156,                // key_switch_entry
        S_key_switch_list = 157,                 // key_switch_list
        S_program_selection_statement = 158,     // program_selection_statement
        S_program_selection_statement_list = 159, // program_selection_statement_list
        S_table_case_entry = 160,                // table_case_entry
        S_table_case_list = 161,                 // table_case_list
        S_table_property = 162,                  // table_property
        S_table_property_list = 163,             // table_property_list
        S_table_declaration = 164,               // table_declaration
        S_typedef_declaration = 165,             // typedef_declaration
        S_enumerator = 166,                      // enumerator
        S_enumerator_list = 167,                 // enumerator_list
        S_enum_declaration = 168,                // enum_declaration
        S_struct_union_type_declaration = 169,   // struct_union_type_declaration
        S_type_declaration = 170,                // type_declaration
        S_function_declaration = 171,            // function_declaration
        S_namespace = 172,                       // namespace
        S_declaration = 173,                     // declaration
        S_declaration_list = 174,                // declaration_list
        S_input = 175                            // input
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_annotation: // annotation
        value.move< IR::Annotation* > (std::move (that.value));
        break;

      case symbol_kind::S_arg: // arg
        value.move< IR::Argument* > (std::move (that.value));
        break;

      case symbol_kind::S_return_value_type_list: // return_value_type_list
      case symbol_kind::S_action_statement_list: // action_statement_list
      case symbol_kind::S_action_compound_statement: // action_compound_statement
      case symbol_kind::S_program_selection_statement_list: // program_selection_statement_list
      case symbol_kind::S_table_property_list: // table_property_list
        value.move< IR::BlockStatement* > (std::move (that.value));
        break;

      case symbol_kind::S_const_value: // const_value
        value.move< IR::Constant* > (std::move (that.value));
        break;

      case symbol_kind::S_header_declaration: // header_declaration
        value.move< IR::Declaration* > (std::move (that.value));
        break;

      case symbol_kind::S_constant_declaration: // constant_declaration
        value.move< IR::Declaration_Constant* > (std::move (that.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.move< IR::Declaration_Variable* > (std::move (that.value));
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
        value.move< IR::Expression* > (std::move (that.value));
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.move< IR::Function* > (std::move (that.value));
        break;

      case symbol_kind::S_ID: // ID
        value.move< IR::ID* > (std::move (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< IR::IndexedVector<IR::SerEnumMember>* > (std::move (that.value));
        break;

      case symbol_kind::S_struct_field_list: // struct_field_list
        value.move< IR::IndexedVector<IR::StructField>* > (std::move (that.value));
        break;

      case symbol_kind::S_select_exp: // select_exp
        value.move< IR::ListExpression* > (std::move (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< IR::Node* > (std::move (that.value));
        break;

      case symbol_kind::S_key_case_entry: // key_case_entry
        value.move< IR::P5KeyCase* > (std::move (that.value));
        break;

      case symbol_kind::S_key_element: // key_element
        value.move< IR::P5KeyElement* > (std::move (that.value));
        break;

      case symbol_kind::S_key_switch_entry: // key_switch_entry
        value.move< IR::P5KeySwitch* > (std::move (that.value));
        break;

      case symbol_kind::S_table_declaration: // table_declaration
        value.move< IR::P5Table* > (std::move (that.value));
        break;

      case symbol_kind::S_parameter: // parameter
        value.move< IR::Parameter* > (std::move (that.value));
        break;

      case symbol_kind::S_param_list: // param_list
        value.move< IR::ParameterList* > (std::move (that.value));
        break;

      case symbol_kind::S_action_statement: // action_statement
      case symbol_kind::S_program_selection_statement: // program_selection_statement
      case symbol_kind::S_table_property: // table_property
        value.move< IR::StatOrDecl* > (std::move (that.value));
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
        value.move< IR::Statement* > (std::move (that.value));
        break;

      case symbol_kind::S_string_lit: // string_lit
        value.move< IR::StringLiteral* > (std::move (that.value));
        break;

      case symbol_kind::S_field_dec: // field_dec
      case symbol_kind::S_anonymous_struct_union_dec: // anonymous_struct_union_dec
      case symbol_kind::S_struct_field_dec: // struct_field_dec
        value.move< IR::StructField* > (std::move (that.value));
        break;

      case symbol_kind::S_case_entry: // case_entry
      case symbol_kind::S_case: // case
      case symbol_kind::S_table_case_entry: // table_case_entry
        value.move< IR::SwitchCase* > (std::move (that.value));
        break;

      case symbol_kind::S_enum_declaration: // enum_declaration
      case symbol_kind::S_type_declaration: // type_declaration
        value.move< IR::Type_Declaration* > (std::move (that.value));
        break;

      case symbol_kind::S_struct_union_type_declaration: // struct_union_type_declaration
        value.move< IR::Type_Struct* > (std::move (that.value));
        break;

      case symbol_kind::S_typedef_declaration: // typedef_declaration
        value.move< IR::Type_Typedef* > (std::move (that.value));
        break;

      case symbol_kind::S_annotations: // annotations
        value.move< IR::Vector<IR::Annotation>* > (std::move (that.value));
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.move< IR::Vector<IR::Argument>* > (std::move (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_value_list: // value_list
        value.move< IR::Vector<IR::Expression>* > (std::move (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.move< IR::Vector<IR::Node>* > (std::move (that.value));
        break;

      case symbol_kind::S_key_case_list: // key_case_list
        value.move< IR::Vector<IR::P5KeyCase>* > (std::move (that.value));
        break;

      case symbol_kind::S_key_element_list: // key_element_list
        value.move< IR::Vector<IR::P5KeyElement>* > (std::move (that.value));
        break;

      case symbol_kind::S_key_switch_list: // key_switch_list
        value.move< IR::Vector<IR::P5KeySwitch>* > (std::move (that.value));
        break;

      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_switch_cases: // switch_cases
      case symbol_kind::S_table_case_list: // table_case_list
        value.move< IR::Vector<IR::SwitchCase>* > (std::move (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< P4::P5::EnumItem* > (std::move (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< UnparsedConstant > (std::move (that.value));
        break;

      case symbol_kind::S_type_ref: // type_ref
        value.move< const IR::Type* > (std::move (that.value));
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
        value.move< cstring > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Annotation*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Annotation*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Argument*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Argument*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::BlockStatement*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::BlockStatement*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Constant*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Constant*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Declaration*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Declaration*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Declaration_Constant*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Declaration_Constant*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Declaration_Variable*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Declaration_Variable*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Expression*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Expression*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Function*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Function*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::ID*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::ID*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::IndexedVector<IR::SerEnumMember>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::SerEnumMember>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::IndexedVector<IR::StructField>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::StructField>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::ListExpression*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::ListExpression*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Node*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Node*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::P5KeyCase*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::P5KeyCase*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::P5KeyElement*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::P5KeyElement*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::P5KeySwitch*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::P5KeySwitch*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::P5Table*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::P5Table*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Parameter*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Parameter*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::ParameterList*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::ParameterList*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::StatOrDecl*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::StatOrDecl*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Statement*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Statement*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::StringLiteral*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::StringLiteral*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::StructField*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::StructField*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::SwitchCase*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::SwitchCase*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Type_Declaration*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Type_Declaration*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Type_Struct*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Type_Struct*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Type_Typedef*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Type_Typedef*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Vector<IR::Annotation>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Annotation>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Vector<IR::Argument>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Argument>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Vector<IR::Expression>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Expression>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Vector<IR::Node>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Node>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Vector<IR::P5KeyCase>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Vector<IR::P5KeyCase>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Vector<IR::P5KeyElement>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Vector<IR::P5KeyElement>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Vector<IR::P5KeySwitch>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Vector<IR::P5KeySwitch>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IR::Vector<IR::SwitchCase>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IR::Vector<IR::SwitchCase>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, P4::P5::EnumItem*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const P4::P5::EnumItem*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, UnparsedConstant&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const UnparsedConstant& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, const IR::Type*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const const IR::Type*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, cstring&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const cstring& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_annotation: // annotation
        value.template destroy< IR::Annotation* > ();
        break;

      case symbol_kind::S_arg: // arg
        value.template destroy< IR::Argument* > ();
        break;

      case symbol_kind::S_return_value_type_list: // return_value_type_list
      case symbol_kind::S_action_statement_list: // action_statement_list
      case symbol_kind::S_action_compound_statement: // action_compound_statement
      case symbol_kind::S_program_selection_statement_list: // program_selection_statement_list
      case symbol_kind::S_table_property_list: // table_property_list
        value.template destroy< IR::BlockStatement* > ();
        break;

      case symbol_kind::S_const_value: // const_value
        value.template destroy< IR::Constant* > ();
        break;

      case symbol_kind::S_header_declaration: // header_declaration
        value.template destroy< IR::Declaration* > ();
        break;

      case symbol_kind::S_constant_declaration: // constant_declaration
        value.template destroy< IR::Declaration_Constant* > ();
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.template destroy< IR::Declaration_Variable* > ();
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
        value.template destroy< IR::Expression* > ();
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.template destroy< IR::Function* > ();
        break;

      case symbol_kind::S_ID: // ID
        value.template destroy< IR::ID* > ();
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.template destroy< IR::IndexedVector<IR::SerEnumMember>* > ();
        break;

      case symbol_kind::S_struct_field_list: // struct_field_list
        value.template destroy< IR::IndexedVector<IR::StructField>* > ();
        break;

      case symbol_kind::S_select_exp: // select_exp
        value.template destroy< IR::ListExpression* > ();
        break;

      case symbol_kind::S_declaration: // declaration
        value.template destroy< IR::Node* > ();
        break;

      case symbol_kind::S_key_case_entry: // key_case_entry
        value.template destroy< IR::P5KeyCase* > ();
        break;

      case symbol_kind::S_key_element: // key_element
        value.template destroy< IR::P5KeyElement* > ();
        break;

      case symbol_kind::S_key_switch_entry: // key_switch_entry
        value.template destroy< IR::P5KeySwitch* > ();
        break;

      case symbol_kind::S_table_declaration: // table_declaration
        value.template destroy< IR::P5Table* > ();
        break;

      case symbol_kind::S_parameter: // parameter
        value.template destroy< IR::Parameter* > ();
        break;

      case symbol_kind::S_param_list: // param_list
        value.template destroy< IR::ParameterList* > ();
        break;

      case symbol_kind::S_action_statement: // action_statement
      case symbol_kind::S_program_selection_statement: // program_selection_statement
      case symbol_kind::S_table_property: // table_property
        value.template destroy< IR::StatOrDecl* > ();
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
        value.template destroy< IR::Statement* > ();
        break;

      case symbol_kind::S_string_lit: // string_lit
        value.template destroy< IR::StringLiteral* > ();
        break;

      case symbol_kind::S_field_dec: // field_dec
      case symbol_kind::S_anonymous_struct_union_dec: // anonymous_struct_union_dec
      case symbol_kind::S_struct_field_dec: // struct_field_dec
        value.template destroy< IR::StructField* > ();
        break;

      case symbol_kind::S_case_entry: // case_entry
      case symbol_kind::S_case: // case
      case symbol_kind::S_table_case_entry: // table_case_entry
        value.template destroy< IR::SwitchCase* > ();
        break;

      case symbol_kind::S_enum_declaration: // enum_declaration
      case symbol_kind::S_type_declaration: // type_declaration
        value.template destroy< IR::Type_Declaration* > ();
        break;

      case symbol_kind::S_struct_union_type_declaration: // struct_union_type_declaration
        value.template destroy< IR::Type_Struct* > ();
        break;

      case symbol_kind::S_typedef_declaration: // typedef_declaration
        value.template destroy< IR::Type_Typedef* > ();
        break;

      case symbol_kind::S_annotations: // annotations
        value.template destroy< IR::Vector<IR::Annotation>* > ();
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.template destroy< IR::Vector<IR::Argument>* > ();
        break;

      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_value_list: // value_list
        value.template destroy< IR::Vector<IR::Expression>* > ();
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.template destroy< IR::Vector<IR::Node>* > ();
        break;

      case symbol_kind::S_key_case_list: // key_case_list
        value.template destroy< IR::Vector<IR::P5KeyCase>* > ();
        break;

      case symbol_kind::S_key_element_list: // key_element_list
        value.template destroy< IR::Vector<IR::P5KeyElement>* > ();
        break;

      case symbol_kind::S_key_switch_list: // key_switch_list
        value.template destroy< IR::Vector<IR::P5KeySwitch>* > ();
        break;

      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_switch_cases: // switch_cases
      case symbol_kind::S_table_case_list: // table_case_list
        value.template destroy< IR::Vector<IR::SwitchCase>* > ();
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.template destroy< P4::P5::EnumItem* > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.template destroy< UnparsedConstant > ();
        break;

      case symbol_kind::S_type_ref: // type_ref
        value.template destroy< const IR::Type* > ();
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
        value.template destroy< cstring > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return P5Parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOK_YYEOF
                   || (token::TOK_YYerror <= tok && tok <= token::TOK_NEWLINE)
                   || (token::TOK_LPAREN_PREC <= tok && tok <= token::TOK_THEN)
                   || tok == 91
                   || tok == 93
                   || tok == 61
                   || tok == 59);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, UnparsedConstant v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const UnparsedConstant& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOK_INTEGER);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, cstring v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const cstring& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::TOK_BREAK <= tok && tok <= token::TOK_STRING_LITERAL));
#endif
      }
    };

    /// Build a parser object.
    P5Parser (P4::P5::P5ParserDriver& driver_yyarg, P4::P5::P5Lexer& lexer_yyarg);
    virtual ~P5Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    P5Parser (const P5Parser&) = delete;
    /// Non copyable.
    P5Parser& operator= (const P5Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::TOK_YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::TOK_YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::TOK_YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::TOK_YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::TOK_YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::TOK_YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::TOK_END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::TOK_END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNEXPECTED_TOKEN (location_type l)
      {
        return symbol_type (token::TOK_UNEXPECTED_TOKEN, std::move (l));
      }
#else
      static
      symbol_type
      make_UNEXPECTED_TOKEN (const location_type& l)
      {
        return symbol_type (token::TOK_UNEXPECTED_TOKEN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_L_PAREN (location_type l)
      {
        return symbol_type (token::TOK_L_PAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_L_PAREN (const location_type& l)
      {
        return symbol_type (token::TOK_L_PAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_R_PAREN (location_type l)
      {
        return symbol_type (token::TOK_R_PAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_R_PAREN (const location_type& l)
      {
        return symbol_type (token::TOK_R_PAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_L_BRACE (location_type l)
      {
        return symbol_type (token::TOK_L_BRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_L_BRACE (const location_type& l)
      {
        return symbol_type (token::TOK_L_BRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_R_BRACE (location_type l)
      {
        return symbol_type (token::TOK_R_BRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_R_BRACE (const location_type& l)
      {
        return symbol_type (token::TOK_R_BRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_L_BRACKET (location_type l)
      {
        return symbol_type (token::TOK_L_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_L_BRACKET (const location_type& l)
      {
        return symbol_type (token::TOK_L_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_R_BRACKET (location_type l)
      {
        return symbol_type (token::TOK_R_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_R_BRACKET (const location_type& l)
      {
        return symbol_type (token::TOK_R_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AT (location_type l)
      {
        return symbol_type (token::TOK_AT, std::move (l));
      }
#else
      static
      symbol_type
      make_AT (const location_type& l)
      {
        return symbol_type (token::TOK_AT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (location_type l)
      {
        return symbol_type (token::TOK_DOT, std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const location_type& l)
      {
        return symbol_type (token::TOK_DOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::TOK_COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::TOK_COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPLEMENT (location_type l)
      {
        return symbol_type (token::TOK_COMPLEMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_COMPLEMENT (const location_type& l)
      {
        return symbol_type (token::TOK_COMPLEMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUESTION (location_type l)
      {
        return symbol_type (token::TOK_QUESTION, std::move (l));
      }
#else
      static
      symbol_type
      make_QUESTION (const location_type& l)
      {
        return symbol_type (token::TOK_QUESTION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::TOK_COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::TOK_COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SCOPE (location_type l)
      {
        return symbol_type (token::TOK_SCOPE, std::move (l));
      }
#else
      static
      symbol_type
      make_SCOPE (const location_type& l)
      {
        return symbol_type (token::TOK_SCOPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (location_type l)
      {
        return symbol_type (token::TOK_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::TOK_PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::TOK_PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PP (location_type l)
      {
        return symbol_type (token::TOK_PP, std::move (l));
      }
#else
      static
      symbol_type
      make_PP (const location_type& l)
      {
        return symbol_type (token::TOK_PP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_PLUS (location_type l)
      {
        return symbol_type (token::TOK_ASSIGN_PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_PLUS (const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN_PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::TOK_MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::TOK_MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MM (location_type l)
      {
        return symbol_type (token::TOK_MM, std::move (l));
      }
#else
      static
      symbol_type
      make_MM (const location_type& l)
      {
        return symbol_type (token::TOK_MM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_MINUS (location_type l)
      {
        return symbol_type (token::TOK_ASSIGN_MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_MINUS (const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN_MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL (location_type l)
      {
        return symbol_type (token::TOK_MUL, std::move (l));
      }
#else
      static
      symbol_type
      make_MUL (const location_type& l)
      {
        return symbol_type (token::TOK_MUL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POW (location_type l)
      {
        return symbol_type (token::TOK_POW, std::move (l));
      }
#else
      static
      symbol_type
      make_POW (const location_type& l)
      {
        return symbol_type (token::TOK_POW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_MUL (location_type l)
      {
        return symbol_type (token::TOK_ASSIGN_MUL, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_MUL (const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN_MUL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (location_type l)
      {
        return symbol_type (token::TOK_DIV, std::move (l));
      }
#else
      static
      symbol_type
      make_DIV (const location_type& l)
      {
        return symbol_type (token::TOK_DIV, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_DIV (location_type l)
      {
        return symbol_type (token::TOK_ASSIGN_DIV, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_DIV (const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN_DIV, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (location_type l)
      {
        return symbol_type (token::TOK_MOD, std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const location_type& l)
      {
        return symbol_type (token::TOK_MOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_MOD (location_type l)
      {
        return symbol_type (token::TOK_ASSIGN_MOD, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_MOD (const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN_MOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (location_type l)
      {
        return symbol_type (token::TOK_NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const location_type& l)
      {
        return symbol_type (token::TOK_NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ_OP (location_type l)
      {
        return symbol_type (token::TOK_EQ_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_EQ_OP (const location_type& l)
      {
        return symbol_type (token::TOK_EQ_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE_OP (location_type l)
      {
        return symbol_type (token::TOK_NE_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_NE_OP (const location_type& l)
      {
        return symbol_type (token::TOK_NE_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_R_ANGLE (location_type l)
      {
        return symbol_type (token::TOK_R_ANGLE, std::move (l));
      }
#else
      static
      symbol_type
      make_R_ANGLE (const location_type& l)
      {
        return symbol_type (token::TOK_R_ANGLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_L_ANGLE (location_type l)
      {
        return symbol_type (token::TOK_L_ANGLE, std::move (l));
      }
#else
      static
      symbol_type
      make_L_ANGLE (const location_type& l)
      {
        return symbol_type (token::TOK_L_ANGLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE (location_type l)
      {
        return symbol_type (token::TOK_GE, std::move (l));
      }
#else
      static
      symbol_type
      make_GE (const location_type& l)
      {
        return symbol_type (token::TOK_GE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE (location_type l)
      {
        return symbol_type (token::TOK_LE, std::move (l));
      }
#else
      static
      symbol_type
      make_LE (const location_type& l)
      {
        return symbol_type (token::TOK_LE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT_AND (location_type l)
      {
        return symbol_type (token::TOK_BIT_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_BIT_AND (const location_type& l)
      {
        return symbol_type (token::TOK_BIT_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND_OP (location_type l)
      {
        return symbol_type (token::TOK_AND_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_AND_OP (const location_type& l)
      {
        return symbol_type (token::TOK_AND_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MASK (location_type l)
      {
        return symbol_type (token::TOK_MASK, std::move (l));
      }
#else
      static
      symbol_type
      make_MASK (const location_type& l)
      {
        return symbol_type (token::TOK_MASK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_BIT_AND (location_type l)
      {
        return symbol_type (token::TOK_ASSIGN_BIT_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_BIT_AND (const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN_BIT_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT_OR (location_type l)
      {
        return symbol_type (token::TOK_BIT_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_BIT_OR (const location_type& l)
      {
        return symbol_type (token::TOK_BIT_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR_OP (location_type l)
      {
        return symbol_type (token::TOK_OR_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_OR_OP (const location_type& l)
      {
        return symbol_type (token::TOK_OR_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_BIT_OR (location_type l)
      {
        return symbol_type (token::TOK_ASSIGN_BIT_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_BIT_OR (const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN_BIT_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT_XOR (location_type l)
      {
        return symbol_type (token::TOK_BIT_XOR, std::move (l));
      }
#else
      static
      symbol_type
      make_BIT_XOR (const location_type& l)
      {
        return symbol_type (token::TOK_BIT_XOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_BIT_XOR (location_type l)
      {
        return symbol_type (token::TOK_ASSIGN_BIT_XOR, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_BIT_XOR (const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN_BIT_XOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_OP (location_type l)
      {
        return symbol_type (token::TOK_RIGHT_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_OP (const location_type& l)
      {
        return symbol_type (token::TOK_RIGHT_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_SHR (location_type l)
      {
        return symbol_type (token::TOK_ASSIGN_SHR, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_SHR (const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN_SHR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_OP (location_type l)
      {
        return symbol_type (token::TOK_LEFT_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_OP (const location_type& l)
      {
        return symbol_type (token::TOK_LEFT_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN_SHL (location_type l)
      {
        return symbol_type (token::TOK_ASSIGN_SHL, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN_SHL (const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN_SHL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHARP (location_type l)
      {
        return symbol_type (token::TOK_SHARP, std::move (l));
      }
#else
      static
      symbol_type
      make_SHARP (const location_type& l)
      {
        return symbol_type (token::TOK_SHARP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (location_type l)
      {
        return symbol_type (token::TOK_SEMICOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const location_type& l)
      {
        return symbol_type (token::TOK_SEMICOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEWLINE (location_type l)
      {
        return symbol_type (token::TOK_NEWLINE, std::move (l));
      }
#else
      static
      symbol_type
      make_NEWLINE (const location_type& l)
      {
        return symbol_type (token::TOK_NEWLINE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (cstring v, location_type l)
      {
        return symbol_type (token::TOK_BREAK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_BREAK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASE (cstring v, location_type l)
      {
        return symbol_type (token::TOK_CASE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CASE (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_CASE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONST (cstring v, location_type l)
      {
        return symbol_type (token::TOK_CONST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONST (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_CONST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLASS (cstring v, location_type l)
      {
        return symbol_type (token::TOK_CLASS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CLASS (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_CLASS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT (cstring v, location_type l)
      {
        return symbol_type (token::TOK_DEFAULT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DEFAULT (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_DEFAULT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO (cstring v, location_type l)
      {
        return symbol_type (token::TOK_DO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DO (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_DO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (cstring v, location_type l)
      {
        return symbol_type (token::TOK_ELSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_ELSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENUM (cstring v, location_type l)
      {
        return symbol_type (token::TOK_ENUM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ENUM (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_ENUM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (cstring v, location_type l)
      {
        return symbol_type (token::TOK_FOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_FOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (cstring v, location_type l)
      {
        return symbol_type (token::TOK_IF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_IF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (cstring v, location_type l)
      {
        return symbol_type (token::TOK_INT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_INT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAMESPACE (cstring v, location_type l)
      {
        return symbol_type (token::TOK_NAMESPACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NAMESPACE (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_NAMESPACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRIVATE (cstring v, location_type l)
      {
        return symbol_type (token::TOK_PRIVATE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PRIVATE (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_PRIVATE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PROTECTED (cstring v, location_type l)
      {
        return symbol_type (token::TOK_PROTECTED, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PROTECTED (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_PROTECTED, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUBLIC (cstring v, location_type l)
      {
        return symbol_type (token::TOK_PUBLIC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PUBLIC (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_PUBLIC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (cstring v, location_type l)
      {
        return symbol_type (token::TOK_RETURN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_RETURN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRUCT (cstring v, location_type l)
      {
        return symbol_type (token::TOK_STRUCT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRUCT (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_STRUCT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SWITCH (cstring v, location_type l)
      {
        return symbol_type (token::TOK_SWITCH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SWITCH (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_SWITCH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEDEF (cstring v, location_type l)
      {
        return symbol_type (token::TOK_TYPEDEF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPEDEF (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_TYPEDEF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNION (cstring v, location_type l)
      {
        return symbol_type (token::TOK_UNION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UNION (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_UNION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UINT (cstring v, location_type l)
      {
        return symbol_type (token::TOK_UINT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UINT (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_UINT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USING (cstring v, location_type l)
      {
        return symbol_type (token::TOK_USING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_USING (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_USING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (cstring v, location_type l)
      {
        return symbol_type (token::TOK_WHILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_WHILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID (cstring v, location_type l)
      {
        return symbol_type (token::TOK_VOID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VOID (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_VOID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KEY (cstring v, location_type l)
      {
        return symbol_type (token::TOK_KEY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_KEY (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_KEY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZE (cstring v, location_type l)
      {
        return symbol_type (token::TOK_SIZE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SIZE (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_SIZE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTROL_PARAMETERS (cstring v, location_type l)
      {
        return symbol_type (token::TOK_CONTROL_PARAMETERS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONTROL_PARAMETERS (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_CONTROL_PARAMETERS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HEADER (cstring v, location_type l)
      {
        return symbol_type (token::TOK_HEADER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_HEADER (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_HEADER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TABLE (cstring v, location_type l)
      {
        return symbol_type (token::TOK_TABLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TABLE (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_TABLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (cstring v, location_type l)
      {
        return symbol_type (token::TOK_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_LITERAL (cstring v, location_type l)
      {
        return symbol_type (token::TOK_STRING_LITERAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING_LITERAL (const cstring& v, const location_type& l)
      {
        return symbol_type (token::TOK_STRING_LITERAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER (UnparsedConstant v, location_type l)
      {
        return symbol_type (token::TOK_INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTEGER (const UnparsedConstant& v, const location_type& l)
      {
        return symbol_type (token::TOK_INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN_PREC (location_type l)
      {
        return symbol_type (token::TOK_LPAREN_PREC, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN_PREC (const location_type& l)
      {
        return symbol_type (token::TOK_LPAREN_PREC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THEN (location_type l)
      {
        return symbol_type (token::TOK_THEN, std::move (l));
      }
#else
      static
      symbol_type
      make_THEN (const location_type& l)
      {
        return symbol_type (token::TOK_THEN, l);
      }
#endif


    class context
    {
    public:
      context (const P5Parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const P5Parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    P5Parser (const P5Parser&);
    /// Non copyable.
    P5Parser& operator= (const P5Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const unsigned char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 833,     ///< Last index in yytable_.
      yynnts_ = 83,  ///< Number of nonterminal symbols.
      yyfinal_ = 3 ///< Termination state number.
    };


    // User arguments.
    P4::P5::P5ParserDriver& driver;
    P4::P5::P5Lexer& lexer;

  };

  inline
  P5Parser::symbol_kind_type
  P5Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    92,
       2,    91,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    89,     2,    90,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88
    };
    // Last valid token kind.
    const int code_max = 343;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  P5Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_annotation: // annotation
        value.copy< IR::Annotation* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arg: // arg
        value.copy< IR::Argument* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_return_value_type_list: // return_value_type_list
      case symbol_kind::S_action_statement_list: // action_statement_list
      case symbol_kind::S_action_compound_statement: // action_compound_statement
      case symbol_kind::S_program_selection_statement_list: // program_selection_statement_list
      case symbol_kind::S_table_property_list: // table_property_list
        value.copy< IR::BlockStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_value: // const_value
        value.copy< IR::Constant* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_header_declaration: // header_declaration
        value.copy< IR::Declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_constant_declaration: // constant_declaration
        value.copy< IR::Declaration_Constant* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.copy< IR::Declaration_Variable* > (YY_MOVE (that.value));
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
        value.copy< IR::Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.copy< IR::Function* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
        value.copy< IR::ID* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.copy< IR::IndexedVector<IR::SerEnumMember>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_field_list: // struct_field_list
        value.copy< IR::IndexedVector<IR::StructField>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_select_exp: // select_exp
        value.copy< IR::ListExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.copy< IR::Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_case_entry: // key_case_entry
        value.copy< IR::P5KeyCase* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_element: // key_element
        value.copy< IR::P5KeyElement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_switch_entry: // key_switch_entry
        value.copy< IR::P5KeySwitch* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_table_declaration: // table_declaration
        value.copy< IR::P5Table* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter: // parameter
        value.copy< IR::Parameter* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_param_list: // param_list
        value.copy< IR::ParameterList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_action_statement: // action_statement
      case symbol_kind::S_program_selection_statement: // program_selection_statement
      case symbol_kind::S_table_property: // table_property
        value.copy< IR::StatOrDecl* > (YY_MOVE (that.value));
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
        value.copy< IR::Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string_lit: // string_lit
        value.copy< IR::StringLiteral* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field_dec: // field_dec
      case symbol_kind::S_anonymous_struct_union_dec: // anonymous_struct_union_dec
      case symbol_kind::S_struct_field_dec: // struct_field_dec
        value.copy< IR::StructField* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_case_entry: // case_entry
      case symbol_kind::S_case: // case
      case symbol_kind::S_table_case_entry: // table_case_entry
        value.copy< IR::SwitchCase* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enum_declaration: // enum_declaration
      case symbol_kind::S_type_declaration: // type_declaration
        value.copy< IR::Type_Declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_union_type_declaration: // struct_union_type_declaration
        value.copy< IR::Type_Struct* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_typedef_declaration: // typedef_declaration
        value.copy< IR::Type_Typedef* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_annotations: // annotations
        value.copy< IR::Vector<IR::Annotation>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.copy< IR::Vector<IR::Argument>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_value_list: // value_list
        value.copy< IR::Vector<IR::Expression>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.copy< IR::Vector<IR::Node>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_case_list: // key_case_list
        value.copy< IR::Vector<IR::P5KeyCase>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_element_list: // key_element_list
        value.copy< IR::Vector<IR::P5KeyElement>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_key_switch_list: // key_switch_list
        value.copy< IR::Vector<IR::P5KeySwitch>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_switch_cases: // switch_cases
      case symbol_kind::S_table_case_list: // table_case_list
        value.copy< IR::Vector<IR::SwitchCase>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.copy< P4::P5::EnumItem* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< UnparsedConstant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_ref: // type_ref
        value.copy< const IR::Type* > (YY_MOVE (that.value));
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
        value.copy< cstring > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  P5Parser::symbol_kind_type
  P5Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  P5Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  P5Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_annotation: // annotation
        value.move< IR::Annotation* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_arg: // arg
        value.move< IR::Argument* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_return_value_type_list: // return_value_type_list
      case symbol_kind::S_action_statement_list: // action_statement_list
      case symbol_kind::S_action_compound_statement: // action_compound_statement
      case symbol_kind::S_program_selection_statement_list: // program_selection_statement_list
      case symbol_kind::S_table_property_list: // table_property_list
        value.move< IR::BlockStatement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_const_value: // const_value
        value.move< IR::Constant* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_header_declaration: // header_declaration
        value.move< IR::Declaration* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_constant_declaration: // constant_declaration
        value.move< IR::Declaration_Constant* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.move< IR::Declaration_Variable* > (YY_MOVE (s.value));
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
        value.move< IR::Expression* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.move< IR::Function* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ID: // ID
        value.move< IR::ID* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< IR::IndexedVector<IR::SerEnumMember>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_struct_field_list: // struct_field_list
        value.move< IR::IndexedVector<IR::StructField>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_select_exp: // select_exp
        value.move< IR::ListExpression* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< IR::Node* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_key_case_entry: // key_case_entry
        value.move< IR::P5KeyCase* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_key_element: // key_element
        value.move< IR::P5KeyElement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_key_switch_entry: // key_switch_entry
        value.move< IR::P5KeySwitch* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_table_declaration: // table_declaration
        value.move< IR::P5Table* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parameter: // parameter
        value.move< IR::Parameter* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_param_list: // param_list
        value.move< IR::ParameterList* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_action_statement: // action_statement
      case symbol_kind::S_program_selection_statement: // program_selection_statement
      case symbol_kind::S_table_property: // table_property
        value.move< IR::StatOrDecl* > (YY_MOVE (s.value));
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
        value.move< IR::Statement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_string_lit: // string_lit
        value.move< IR::StringLiteral* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_field_dec: // field_dec
      case symbol_kind::S_anonymous_struct_union_dec: // anonymous_struct_union_dec
      case symbol_kind::S_struct_field_dec: // struct_field_dec
        value.move< IR::StructField* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_case_entry: // case_entry
      case symbol_kind::S_case: // case
      case symbol_kind::S_table_case_entry: // table_case_entry
        value.move< IR::SwitchCase* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_enum_declaration: // enum_declaration
      case symbol_kind::S_type_declaration: // type_declaration
        value.move< IR::Type_Declaration* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_struct_union_type_declaration: // struct_union_type_declaration
        value.move< IR::Type_Struct* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_typedef_declaration: // typedef_declaration
        value.move< IR::Type_Typedef* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_annotations: // annotations
        value.move< IR::Vector<IR::Annotation>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_arg_list: // arg_list
        value.move< IR::Vector<IR::Argument>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
      case symbol_kind::S_value_list: // value_list
        value.move< IR::Vector<IR::Expression>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.move< IR::Vector<IR::Node>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_key_case_list: // key_case_list
        value.move< IR::Vector<IR::P5KeyCase>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_key_element_list: // key_element_list
        value.move< IR::Vector<IR::P5KeyElement>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_key_switch_list: // key_switch_list
        value.move< IR::Vector<IR::P5KeySwitch>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_case_list: // case_list
      case symbol_kind::S_switch_cases: // switch_cases
      case symbol_kind::S_table_case_list: // table_case_list
        value.move< IR::Vector<IR::SwitchCase>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< P4::P5::EnumItem* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< UnparsedConstant > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type_ref: // type_ref
        value.move< const IR::Type* > (YY_MOVE (s.value));
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
        value.move< cstring > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  P5Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  P5Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  P5Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  P5Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  P5Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  P5Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  P5Parser::symbol_kind_type
  P5Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  P5Parser::symbol_kind_type
  P5Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


#line 7 "/root/p4c/frontends/parsers/p5/p5parser.ypp"
} } // P4::P5
#line 4626 "/root/p4c/build/frontends/parsers/p5/p5parser.hpp"




#endif // !YY_YY_ROOT_P4C_BUILD_FRONTENDS_PARSERS_P5_P5PARSER_HPP_INCLUDED
