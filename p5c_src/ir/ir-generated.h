#ifndef IR_GENERATED_H_
#define IR_GENERATED_H_

#include <functional>
#include <map>

#include "lib/big_int.h"        // IWYU pragma: keep
// Special IR classes and types
#include "ir/dbprint.h"         // IWYU pragma: keep
#include "ir/id.h"              // IWYU pragma: keep
#include "ir/indexed_vector.h"  // IWYU pragma: keep
#include "ir/namemap.h"         // IWYU pragma: keep
#include "ir/node.h"            // IWYU pragma: keep
#include "ir/nodemap.h"         // IWYU pragma: keep
#include "ir/vector.h"          // IWYU pragma: keep
#include "lib/ordered_map.h"    // IWYU pragma: keep

namespace P4 {

class JSONLoader;
using NodeFactoryFn = IR::Node*(*)(JSONLoader&);

namespace IR {
extern std::map<cstring, NodeFactoryFn> unpacker_table;
using namespace P4::literals;
}
extern template class IR::Vector<IR::Node>;
extern template class IR::IndexedVector<IR::Node>;
extern template class IR::Vector<IR::Type>;
extern template class IR::Vector<IR::StatOrDecl>;
extern template class IR::IndexedVector<IR::StatOrDecl>;
extern template class IR::Vector<IR::Declaration>;
extern template class IR::IndexedVector<IR::Declaration>;
extern template class IR::Vector<IR::Expression>;
extern template class IR::Vector<IR::NamedExpression>;
extern template class IR::IndexedVector<IR::NamedExpression>;
extern template class IR::Vector<IR::AnnotationToken>;
extern template class IR::Vector<IR::Annotation>;
extern template class IR::Vector<IR::Argument>;
extern template class IR::Vector<IR::Parameter>;
extern template class IR::IndexedVector<IR::Parameter>;
extern template class IR::Vector<IR::Type_Var>;
extern template class IR::IndexedVector<IR::Type_Var>;
extern template class IR::Vector<IR::StructField>;
extern template class IR::IndexedVector<IR::StructField>;
extern template class IR::Vector<IR::Declaration_ID>;
extern template class IR::IndexedVector<IR::Declaration_ID>;
extern template class IR::Vector<IR::SerEnumMember>;
extern template class IR::IndexedVector<IR::SerEnumMember>;
extern template class IR::Vector<IR::ArgumentInfo>;
extern template class IR::Vector<IR::Method>;
extern template class IR::Vector<IR::SelectCase>;
extern template class IR::Vector<IR::ParserState>;
extern template class IR::IndexedVector<IR::ParserState>;
extern template class IR::Vector<IR::ActionListElement>;
extern template class IR::IndexedVector<IR::ActionListElement>;
extern template class IR::Vector<IR::KeyElement>;
extern template class IR::Vector<IR::Entry>;
extern template class IR::Vector<IR::Property>;
extern template class IR::IndexedVector<IR::Property>;
extern template class IR::Vector<IR::SwitchCase>;
extern template class IR::Vector<IR::Primitive>;
extern template class IR::Vector<IR::CaseEntry>;
extern template class IR::Vector<IR::P5KeyElement>;
extern template class IR::Vector<IR::P5KeyCase>;
extern template class IR::Vector<IR::DpdkDeclaration>;
extern template class IR::IndexedVector<IR::DpdkDeclaration>;
extern template class IR::Vector<IR::DpdkExternDeclaration>;
extern template class IR::IndexedVector<IR::DpdkExternDeclaration>;
extern template class IR::Vector<IR::DpdkHeaderType>;
extern template class IR::IndexedVector<IR::DpdkHeaderType>;
extern template class IR::Vector<IR::DpdkHeaderInstance>;
extern template class IR::IndexedVector<IR::DpdkHeaderInstance>;
extern template class IR::Vector<IR::DpdkStructType>;
extern template class IR::IndexedVector<IR::DpdkStructType>;
extern template class IR::Vector<IR::DpdkAsmStatement>;
extern template class IR::IndexedVector<IR::DpdkAsmStatement>;
extern template class IR::Vector<IR::DpdkAction>;
extern template class IR::IndexedVector<IR::DpdkAction>;
extern template class IR::Vector<IR::DpdkTable>;
extern template class IR::IndexedVector<IR::DpdkTable>;
extern template class IR::Vector<IR::DpdkSelector>;
extern template class IR::IndexedVector<IR::DpdkSelector>;
extern template class IR::Vector<IR::DpdkLearner>;
extern template class IR::IndexedVector<IR::DpdkLearner>;
}  // namespace P4

#line 16 "/root/p4c/ir/base.def"
#include "absl/strings/str_cat.h"
#line 91 "/root/p4c/build/ir/ir-generated.h"
#line 17 "/root/p4c/ir/base.def"
#include "absl/strings/str_join.h"
#line 94 "/root/p4c/build/ir/ir-generated.h"
#line 18 "/root/p4c/ir/base.def"
#include "frontends/common/constantParsing.h"
#line 97 "/root/p4c/build/ir/ir-generated.h"
#line 19 "/root/p4c/ir/base.def"
#include "ir/annotations.h"
#line 100 "/root/p4c/build/ir/ir-generated.h"
namespace P4::IR {
/// a value that can be evaluated at compile-time
class CompileTimeValue : public virtual INode {
 public:
#line 22 "/root/p4c/ir/base.def"
    bool equiv(IR::CompileTimeValue const & other) const;
#line 107 "/root/p4c/build/ir/ir-generated.h"
    DECLARE_TYPEINFO_WITH_TYPEID(CompileTimeValue, NodeKind::CompileTimeValue, INode);
};
}  // namespace P4::IR
namespace P4::IR {
/// Base class for P4 types
class Type : public Node {
 public:
    static const cstring minSizeInBits;
    static const cstring minSizeInBytes;
    static const cstring maxSizeInBits;
    static const cstring maxSizeInBytes;
#line 34 "/root/p4c/ir/base.def"
    typedef Type_Unknown        Unknown;
    typedef Type_Boolean        Boolean;
    typedef Type_Bits           Bits;
    typedef Type_String         String;
    typedef Type_Varbits        Varbits;
    typedef Type_Void           Void;
#line 126 "/root/p4c/build/ir/ir-generated.h"
/// Well-defined only for types with fixed width
#line 42 "/root/p4c/ir/base.def"
    virtual int width_bits() const;
#line 130 "/root/p4c/build/ir/ir-generated.h"
/// When possible returns the corresponding type that can be inserted
/// in a P4 program; may return a Type_Name
#line 45 "/root/p4c/ir/base.def"
    virtual IR::Type const * getP4Type() const = 0;
#line 135 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type"_cs; }
    static cstring static_type_name() { return "Type"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
 protected:
    Type(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    Type() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Type)
    DECLARE_TYPEINFO_WITH_TYPEID(Type, NodeKind::Type, Node);
};
}  // namespace P4::IR
namespace P4::IR {
/// Implemented by all types that may be generic:
/// Control, Extern, Method, Package, and Parser
class IMayBeGenericType : public virtual INode {
 public:
/// Allows the retrieval of type parameters
#line 52 "/root/p4c/ir/base.def"
    virtual IR::TypeParameters const * getTypeParameters() const = 0;
#line 161 "/root/p4c/build/ir/ir-generated.h"
    DECLARE_TYPEINFO_WITH_TYPEID(IMayBeGenericType, NodeKind::IMayBeGenericType, INode);
};
}  // namespace P4::IR
namespace P4::IR {
/// Implemented by objects with an 'apply' method: Parser, Control, Table
class IApply : public virtual INode {
 public:
    static const cstring applyMethodName;
/// @returns the type signature of the apply method
#line 59 "/root/p4c/ir/base.def"
    virtual IR::Type_Method const * getApplyMethodType() const = 0;
#line 173 "/root/p4c/build/ir/ir-generated.h"
#line 60 "/root/p4c/ir/base.def"
    virtual IR::ParameterList const * getApplyParameters() const = 0;
#line 176 "/root/p4c/build/ir/ir-generated.h"
    DECLARE_TYPEINFO_WITH_TYPEID(IApply, NodeKind::IApply, INode);
};
}  // namespace P4::IR
namespace P4::IR {
/// base class for namespaces
class INamespace : public virtual INode {
 public:
#line 65 "/root/p4c/ir/base.def"
    virtual Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const = 0;
#line 186 "/root/p4c/build/ir/ir-generated.h"
    DECLARE_TYPEINFO_WITH_TYPEID(INamespace, NodeKind::INamespace, INode);
};
}  // namespace P4::IR
namespace P4::IR {
/// Does not allow two declarations with the same name
class ISimpleNamespace : public virtual INode, public virtual INamespace {
 public:
#line 70 "/root/p4c/ir/base.def"
    virtual const IR::IDeclaration *getDeclByName(cstring name) const = 0;
#line 196 "/root/p4c/build/ir/ir-generated.h"
#line 71 "/root/p4c/ir/base.def"
    virtual const IR::IDeclaration *getDeclByName(std::string_view name) const = 0;
#line 199 "/root/p4c/build/ir/ir-generated.h"
    DECLARE_TYPEINFO_WITH_TYPEID(ISimpleNamespace, NodeKind::ISimpleNamespace, INode, INamespace);
};
}  // namespace P4::IR
namespace P4::IR {
/// A general namespace can have multiple declarations with the same name
/// E.g., an extern can have multiple methods with the same name.
class IGeneralNamespace : public virtual INode, public virtual INamespace {
 public:
#line 77 "/root/p4c/ir/base.def"
    virtual Util::Enumerator<const IR::IDeclaration *> * getDeclsByName(cstring name) const;
#line 210 "/root/p4c/build/ir/ir-generated.h"
/// prints an error if it finds duplicate names
#line 79 "/root/p4c/ir/base.def"
    void checkDuplicateDeclarations() const;
#line 214 "/root/p4c/build/ir/ir-generated.h"
#line 80 "/root/p4c/ir/base.def"
    void validate() const override;
#line 217 "/root/p4c/build/ir/ir-generated.h"
    DECLARE_TYPEINFO_WITH_TYPEID(IGeneralNamespace, NodeKind::IGeneralNamespace, INode, INamespace);
};
}  // namespace P4::IR
namespace P4::IR {

class INestedNamespace : public virtual INode, public virtual INamespace {
 public:
#line 86 "/root/p4c/ir/base.def"
    virtual std::vector<const IR::INamespace *> getNestedNamespaces() const = 0;
#line 227 "/root/p4c/build/ir/ir-generated.h"
#line 87 "/root/p4c/ir/base.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 230 "/root/p4c/build/ir/ir-generated.h"
    DECLARE_TYPEINFO_WITH_TYPEID(INestedNamespace, NodeKind::INestedNamespace, INode, INamespace);
};
}  // namespace P4::IR
namespace P4::IR {
/// Interface implemented by something that can be called
/// like a function.
class IFunctional : public virtual INode {
 public:
/// The parameters of the functional object
#line 94 "/root/p4c/ir/base.def"
    virtual const IR::ParameterList *getParameters() const = 0;
#line 242 "/root/p4c/build/ir/ir-generated.h"
/// Returns true if the parameters can be matched with the
/// supplied arguments.
#line 97 "/root/p4c/ir/base.def"
    bool callMatches(const IR::Vector<IR::Argument>* arguments) const;
#line 247 "/root/p4c/build/ir/ir-generated.h"
    DECLARE_TYPEINFO_WITH_TYPEID(IFunctional, NodeKind::IFunctional, INode);
};
}  // namespace P4::IR
namespace P4::IR {
/// Implemented by things that look like type variables
class ITypeVar : public virtual INode {
 public:
#line 102 "/root/p4c/ir/base.def"
    virtual cstring getVarName() const = 0;
#line 257 "/root/p4c/build/ir/ir-generated.h"
#line 103 "/root/p4c/ir/base.def"
    const IR::Type *asType() const { return to<Type>(); }
#line 260 "/root/p4c/build/ir/ir-generated.h"
#line 104 "/root/p4c/ir/base.def"
    virtual int getDeclId() const = 0;
#line 263 "/root/p4c/build/ir/ir-generated.h"
    DECLARE_TYPEINFO_WITH_TYPEID(ITypeVar, NodeKind::ITypeVar, INode);
};
}  // namespace P4::IR
namespace P4::IR {
/// Implemented by P4Parser, P4Control and Type_Package
class IContainer : public virtual INode, public virtual IMayBeGenericType, public virtual IDeclaration, public virtual IFunctional {
 public:
#line 109 "/root/p4c/ir/base.def"
    virtual const IR::Type *getType() const = 0;
#line 273 "/root/p4c/build/ir/ir-generated.h"
/// The type of the constructor as a method
#line 111 "/root/p4c/ir/base.def"
    virtual const IR::Type_Method *getConstructorMethodType() const = 0;
#line 277 "/root/p4c/build/ir/ir-generated.h"
#line 112 "/root/p4c/ir/base.def"
    virtual const IR::ParameterList *getConstructorParameters() const = 0;
#line 280 "/root/p4c/build/ir/ir-generated.h"

#line 114 "/root/p4c/ir/base.def"
    const IR::ParameterList *getParameters() const override;
#line 284 "/root/p4c/build/ir/ir-generated.h"
    DECLARE_TYPEINFO_WITH_TYPEID(IContainer, NodeKind::IContainer, INode, IMayBeGenericType, IDeclaration, IFunctional);
};
}  // namespace P4::IR
namespace P4::IR {
/// This represents a primitive type
/// (called base type in the spec)
class Type_Base : public Type {
 public:
#line 120 "/root/p4c/ir/base.def"
    IR::Type const * getP4Type() const override;
#line 295 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Base const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Base"_cs; }
    static cstring static_type_name() { return "Type_Base"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Base(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Type_Base(Util::SourceInfo srcInfo) :
    Type(srcInfo)
    { validate(); }
    Type_Base() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Type_Base)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Base, NodeKind::Type_Base, Type);
};
}  // namespace P4::IR
namespace P4::IR {
/// This is needed by Expression
class Type_Unknown : public Type_Base {
 public:
#line 126 "/root/p4c/ir/base.def"
    static const IR::Type_Unknown *get();
#line 320 "/root/p4c/build/ir/ir-generated.h"
#line 127 "/root/p4c/ir/base.def"
    static const IR::Type_Unknown *get(Util::SourceInfo const & si);
#line 323 "/root/p4c/build/ir/ir-generated.h"
#line 128 "/root/p4c/ir/base.def"
    cstring toString() const override;
#line 326 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Unknown const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Unknown"_cs; }
    static cstring static_type_name() { return "Type_Unknown"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Unknown(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Unknown(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_Unknown() 
    { validate(); }
    IRNODE_SUBCLASS(Type_Unknown)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Unknown, NodeKind::Type_Unknown, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
/// A statement or a declaration
class StatOrDecl : public Node {
 public:
    bool operator==(IR::StatOrDecl const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "StatOrDecl"_cs; }
    static cstring static_type_name() { return "StatOrDecl"_cs; }
    void toJSON(JSONGenerator & json) const override;
    StatOrDecl(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
 protected:
    StatOrDecl(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    StatOrDecl() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(StatOrDecl)
    DECLARE_TYPEINFO_WITH_TYPEID(StatOrDecl, NodeKind::StatOrDecl, Node);
};
}  // namespace P4::IR
namespace P4::IR {
/// Two declarations with the same name are not necessarily the same declaration.
/// That's why declid is used to distinguish them.
class Declaration : public StatOrDecl, public virtual IDeclaration {
 public:
    IR::ID name;
    long declid = nextId++;
#line 139 "/root/p4c/ir/base.def"
    IR::ID getName() const override;
#line 376 "/root/p4c/build/ir/ir-generated.h"
#line 140 "/root/p4c/ir/base.def"
    bool equiv(IR::Node const & a_) const override;
#line 379 "/root/p4c/build/ir/ir-generated.h"
 private:
    static long nextId;
 public:
#line 144 "/root/p4c/ir/base.def"
    cstring toString() const override;
#line 385 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Declaration const & a) const override;
    cstring node_type_name() const override { return "Declaration"_cs; }
    static cstring static_type_name() { return "Declaration"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Declaration(JSONLoader & json);
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Declaration(Util::SourceInfo srcInfo, IR::ID name) :
    StatOrDecl(srcInfo), name(name)
    { validate(); }
    Declaration(IR::ID name) :
    name(name)
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Declaration)
    DECLARE_TYPEINFO_WITH_TYPEID(Declaration, NodeKind::Declaration, StatOrDecl, IDeclaration);
};
}  // namespace P4::IR
namespace P4::IR {
/// A declaration which introduces a type.
/// Two declarations with the same name are not the same declaration
/// That's why declid is used to distinguish them.
/// (We don't use multiple inheritance, so we can't
/// inherit both Type and Declaration.)
class Type_Declaration : public Type, public virtual IDeclaration {
 public:
    IR::ID name;
    long declid = nextId++;
#line 155 "/root/p4c/ir/base.def"
    IR::ID getName() const override;
#line 417 "/root/p4c/build/ir/ir-generated.h"
#line 156 "/root/p4c/ir/base.def"
    bool equiv(IR::Node const & a_) const override;
#line 420 "/root/p4c/build/ir/ir-generated.h"
 private:
    static long nextId;
 public:
#line 160 "/root/p4c/ir/base.def"
    cstring toString() const override;
#line 426 "/root/p4c/build/ir/ir-generated.h"
#line 161 "/root/p4c/ir/base.def"
    IR::Type const * getP4Type() const override;
#line 429 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Declaration const & a) const override;
    cstring node_type_name() const override { return "Type_Declaration"_cs; }
    static cstring static_type_name() { return "Type_Declaration"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Declaration(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Type_Declaration(Util::SourceInfo srcInfo, IR::ID name) :
    Type(srcInfo), name(name)
    { validate(); }
    Type_Declaration(IR::ID name) :
    name(name)
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Type_Declaration)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Declaration, NodeKind::Type_Declaration, Type, IDeclaration);
};
}  // namespace P4::IR
namespace P4::IR {
/// base class for expressions
class Expression : public Node {
 public:
/// Note that the type field is not visited.
/// Most P4_16 passes don't use this field.
/// It is a used to hold the result of TypeInferencing for the expression.
/// It is used by the P4_14 front-end and by some back-ends.
/// It is not visited by the visitors by default (can be visited explicitly in preorder)
    const IR::Type* type = Type::Unknown::get();
#line 172 "/root/p4c/ir/base.def"
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
#line 462 "/root/p4c/build/ir/ir-generated.h"
    IRNODE_DECLARE_APPLY_OVERLOAD(Expression)
    bool operator==(IR::Expression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Expression"_cs; }
    static cstring static_type_name() { return "Expression"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Expression(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
 protected:
    Expression(Util::SourceInfo srcInfo, const IR::Type* type) :
    Node(srcInfo), type(type)
    { validate(); }
    Expression(const IR::Type* type) :
    type(type)
    { validate(); }
    Expression(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    Expression() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Expression)
    DECLARE_TYPEINFO_WITH_TYPEID(Expression, NodeKind::Expression, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class Operation : public Expression {
 public:
#line 177 "/root/p4c/ir/base.def"
    virtual int getPrecedence() const = 0;
#line 493 "/root/p4c/build/ir/ir-generated.h"
#line 178 "/root/p4c/ir/base.def"
    virtual cstring getStringOp() const = 0;
#line 496 "/root/p4c/build/ir/ir-generated.h"
#line 180 "/root/p4c/ir/base.def"
    typedef Operation_Unary Unary;
    typedef Operation_Binary Binary;
    typedef Operation_Relation Relation;
#line 501 "/root/p4c/build/ir/ir-generated.h"
#line 184 "/root/p4c/ir/base.def"
    cstring toString() const override;
#line 504 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Operation const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Operation"_cs; }
    static cstring static_type_name() { return "Operation"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Operation(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Operation(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
    Operation(const IR::Type* type) :
    Expression(type)
    { validate(); }
    Operation(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
    Operation() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Operation)
    DECLARE_TYPEINFO_WITH_TYPEID(Operation, NodeKind::Operation, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
/// Currently paths can be absolute (starting with a dot) or relative
/// (just an identifier).  In a previous design paths could have
/// multiple components.
class Path : public Node {
 public:
    IR::ID name;
    bool absolute = false;
#line 194 "/root/p4c/ir/base.def"
    bool isDontCare() const { return name.isDontCare(); }
#line 539 "/root/p4c/build/ir/ir-generated.h"
#line 195 "/root/p4c/ir/base.def"
    cstring toString() const override;
#line 542 "/root/p4c/build/ir/ir-generated.h"
#line 199 "/root/p4c/ir/base.def"
    cstring asString() const {
        // The CURRENT internal name
        return absl::StrCat(absolute ? "." : "", name);
    }
#line 548 "/root/p4c/build/ir/ir-generated.h"
#line 203 "/root/p4c/ir/base.def"
    void dbprint(std::ostream & out) const override;
#line 551 "/root/p4c/build/ir/ir-generated.h"
#line 204 "/root/p4c/ir/base.def"
    void validate() const override;
#line 554 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Path const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Path"_cs; }
    static cstring static_type_name() { return "Path"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Path(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    Path(Util::SourceInfo srcInfo, IR::ID name, bool absolute) :
    Node(srcInfo), name(name), absolute(absolute)
    {
#line 193 "/root/p4c/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 569 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Path(IR::ID name, bool absolute) :
    name(name), absolute(absolute)
    {
#line 193 "/root/p4c/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 576 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Path(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    {
#line 193 "/root/p4c/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 583 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Path(IR::ID name) :
    name(name)
    {
#line 193 "/root/p4c/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 590 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(Path)
    DECLARE_TYPEINFO_WITH_TYPEID(Path, NodeKind::Path, Node);
};
}  // namespace P4::IR
namespace P4::IR {
/// Handy class used in several NamedMaps
class NamedExpression : public Declaration {
 public:
    const IR::Expression* expression = nullptr;
    bool operator==(IR::NamedExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "NamedExpression"_cs; }
    static cstring static_type_name() { return "NamedExpression"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    NamedExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    NamedExpression(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* expression) :
    Declaration(srcInfo, name), expression(expression)
    { validate(); }
    NamedExpression(IR::ID name, const IR::Expression* expression) :
    Declaration(name), expression(expression)
    { validate(); }
    IRNODE_SUBCLASS(NamedExpression)
    DECLARE_TYPEINFO_WITH_TYPEID(NamedExpression, NodeKind::NamedExpression, Declaration);
};
}  // namespace P4::IR
namespace P4::IR {
/// A token in an unparsed annotation.
/// This should really be P4::P4Parser::symbol_type, but p4parser.hpp depends
/// on the IR in a way that makes it difficult to #include in this file.
class AnnotationToken : public Node {
 public:
    int token_type;

    cstring text;
    UnparsedConstant * constInfo = nullptr;
#line 219 "/root/p4c/ir/base.def"
    void dbprint(std::ostream & out) const override;
#line 637 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::AnnotationToken const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "AnnotationToken"_cs; }
    static cstring static_type_name() { return "AnnotationToken"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    AnnotationToken(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    AnnotationToken(Util::SourceInfo srcInfo, int token_type, cstring text, UnparsedConstant * constInfo) :
    Node(srcInfo), token_type(token_type), text(text), constInfo(constInfo)
    { validate(); }
    AnnotationToken(int token_type, cstring text, UnparsedConstant * constInfo) :
    token_type(token_type), text(text), constInfo(constInfo)
    { validate(); }
    AnnotationToken(Util::SourceInfo srcInfo, int token_type, cstring text) :
    Node(srcInfo), token_type(token_type), text(text)
    { validate(); }
    AnnotationToken(int token_type, cstring text) :
    token_type(token_type), text(text)
    { validate(); }
    IRNODE_SUBCLASS(AnnotationToken)
    DECLARE_TYPEINFO_WITH_TYPEID(AnnotationToken, NodeKind::AnnotationToken, Node);
};
}  // namespace P4::IR
namespace P4::IR {
/// Annotations are used to provide additional information to the compiler
/// Most P4 entities can be optionally annotated
class Annotation : public Node {
 public:
    IR::ID name;
#line 228 "/root/p4c/ir/base.def"
    using UnparsedAnnotation = IR::Vector<IR::AnnotationToken>;
    using ExpressionAnnotation = IR::Vector<IR::Expression>;
    using KVAnnotation = IR::IndexedVector<IR::NamedExpression>;
#line 673 "/root/p4c/build/ir/ir-generated.h"
/// For annotations parsed from P4-16 source.
#line 235 "/root/p4c/ir/base.def"
    Annotation(Util::SourceInfo si, IR::ID n, IR::Vector<IR::AnnotationToken> const & a) : Node(si), name(n), body(a), structured(false) {}
#line 677 "/root/p4c/build/ir/ir-generated.h"

#line 238 "/root/p4c/ir/base.def"
    Annotation(Util::SourceInfo si, IR::ID n, IR::Vector<IR::AnnotationToken> const & a, bool structured) : Node(si), name(n), body(a), structured(structured) {}
#line 681 "/root/p4c/build/ir/ir-generated.h"

#line 242 "/root/p4c/ir/base.def"
    Annotation(Util::SourceInfo si, IR::ID n, std::initializer_list<IR::Expression const *> a, bool structured = false) : Node(si), name(n), body(a), structured(structured) {}
#line 685 "/root/p4c/build/ir/ir-generated.h"
#line 245 "/root/p4c/ir/base.def"
    Annotation(Util::SourceInfo si, IR::ID n, IR::Expression const * a, bool structured = false) : Node(si), name(n), body(), structured(structured) {
        body.emplace<ExpressionAnnotation>(a);
    }
#line 690 "/root/p4c/build/ir/ir-generated.h"
#line 250 "/root/p4c/ir/base.def"
    Annotation(Util::SourceInfo si, IR::ID n, IR::Vector<IR::Expression> const & a, bool structured = false) : Node(si), name(n), body(a), structured(structured) {}
#line 693 "/root/p4c/build/ir/ir-generated.h"
#line 252 "/root/p4c/ir/base.def"
    Annotation(Util::SourceInfo si, IR::ID n, IR::IndexedVector<IR::NamedExpression> const & kv, bool structured = false) : Node(si), name(n), body(kv), structured(structured) {}
#line 696 "/root/p4c/build/ir/ir-generated.h"
#line 255 "/root/p4c/ir/base.def"
    Annotation(IR::ID n, IR::Expression const * a, bool structured = false) : name(n), body(), structured(structured) {
        body.emplace<ExpressionAnnotation>(a);
    }
#line 701 "/root/p4c/build/ir/ir-generated.h"
#line 259 "/root/p4c/ir/base.def"
    Annotation(IR::ID n, std::initializer_list<IR::Expression const *> a, bool structured = false) : name(n), body(a), structured(structured) {}
#line 704 "/root/p4c/build/ir/ir-generated.h"
#line 261 "/root/p4c/ir/base.def"
    Annotation(IR::ID n, IR::Vector<IR::Expression> const & a, bool structured = false) : name(n), body(a), structured(structured) {}
#line 707 "/root/p4c/build/ir/ir-generated.h"
#line 263 "/root/p4c/ir/base.def"
    Annotation(IR::ID n, intmax_t v, bool structured = false);
#line 710 "/root/p4c/build/ir/ir-generated.h"


#line 269 "/root/p4c/ir/base.def"
    Annotation(IR::ID n, cstring v, bool structured = false);
#line 715 "/root/p4c/build/ir/ir-generated.h"

    static const cstring nameAnnotation;
/// Indicates the control-plane name.
    static const cstring tableOnlyAnnotation;
/// Action cannot be a default_action.
    static const cstring defaultOnlyAnnotation;
/// action can only be a default_action.
    static const cstring atomicAnnotation;
/// Code should be executed atomically.
    static const cstring hiddenAnnotation;
/// Object should not be exposed to the control-plane.
    static const cstring lengthAnnotation;
/// P4-14 annotation for varbit fields.
    static const cstring maxLengthAnnotation;
/// P4-14 annotation for varbit fields.
    static const cstring optionalAnnotation;
/// Optional parameter annotation
    static const cstring pkginfoAnnotation;
/// Package documentation annotation.
    static const cstring deprecatedAnnotation;
/// Deprecation annotation.
    static const cstring synchronousAnnotation;
/// Synchronous annotation.
    static const cstring pureAnnotation;
/// extern function/method annotation.
    static const cstring noSideEffectsAnnotation;
/// extern function/method annotation.
    static const cstring noWarnAnnotation;
/// noWarn annotation.
    static const cstring matchAnnotation;
/// Match annotation (for value sets).
    static const cstring fieldListAnnotation;
/// Used for recirculate, etc.
    static const cstring debugLoggingAnnotation;
/// Used by compiler implementer to limit debug log to the annotated IR context.
    static const cstring disableOptimizationAnnotation;
/// annotation to disable certain optimization
    static const cstring inlinedFromAnnotation;
/// annotation to mark block of inlined function
    static const cstring likelyAnnotation;
/// annotation for likely taken blocks/branchs
    static const cstring unlikelyAnnotation;
/// annotation for likely not taken blocks/branchs
#line 296 "/root/p4c/ir/base.def"
    cstring toString() const override;
#line 761 "/root/p4c/build/ir/ir-generated.h"
#line 297 "/root/p4c/ir/base.def"
    void validate() const override;
#line 764 "/root/p4c/build/ir/ir-generated.h"
/// Extracts name value from a name annotation
#line 302 "/root/p4c/ir/base.def"
    cstring getName() const;
#line 768 "/root/p4c/build/ir/ir-generated.h"
/// Extracts a single string argument; error if the argument is not a string
#line 304 "/root/p4c/ir/base.def"
    cstring getSingleString() const;
#line 772 "/root/p4c/build/ir/ir-generated.h"
/// Whether the annotation body needs to be parsed.
#line 306 "/root/p4c/ir/base.def"
    bool needsParsing() const {
        return std::holds_alternative<UnparsedAnnotation>(body);
    }
#line 778 "/root/p4c/build/ir/ir-generated.h"
enum class Kind
#line 311 "/root/p4c/ir/base.def"
{
        Unparsed,
        Unstructured,
        StructuredKVList,
        StructuredExpressionList
    };
#line 787 "/root/p4c/build/ir/ir-generated.h"
#line 317 "/root/p4c/ir/base.def"
    IR::Annotation::Kind annotationKind() const {
        if (needsParsing())
            return Kind::Unparsed;
        if (!structured)
            return Kind::Unstructured;
        if (std::holds_alternative<ExpressionAnnotation>(body))
            return Kind::StructuredExpressionList;
        if (std::holds_alternative<KVAnnotation>(body))
            return Kind::StructuredKVList;

        BUG("Invalid annotation kind");
    }
#line 801 "/root/p4c/build/ir/ir-generated.h"



    using body_variant = std::variant<IR::Vector<IR::AnnotationToken>, IR::Vector<IR::Expression>, IR::IndexedVector<IR::NamedExpression>>;
    body_variant body;
#line 337 "/root/p4c/ir/base.def"
    auto & getUnparsed() {
        try {
            return std::get<UnparsedAnnotation>(body);
        } catch (const std::bad_variant_access &) {
            BUG("Annotation has been parsed already.");
        }
    }
#line 815 "/root/p4c/build/ir/ir-generated.h"
#line 344 "/root/p4c/ir/base.def"
    auto const & getUnparsed() const {
        try {
            return std::get<UnparsedAnnotation>(body);
        } catch (const std::bad_variant_access &) {
            BUG("Annotation has been parsed already.");
        }
    }
#line 824 "/root/p4c/build/ir/ir-generated.h"
#line 351 "/root/p4c/ir/base.def"
    auto & getExpr() {
        try {
            return std::get<ExpressionAnnotation>(body);
        } catch (const std::bad_variant_access &) {
            BUG("Annotation does not contain an expression list.");
        }
     }
#line 833 "/root/p4c/build/ir/ir-generated.h"
#line 358 "/root/p4c/ir/base.def"
    auto const & getExpr() const {
        try {
            return std::get<ExpressionAnnotation>(body);
        } catch (const std::bad_variant_access &) {
            BUG("Annotation does not contain an expression list.");
        }
    }
#line 842 "/root/p4c/build/ir/ir-generated.h"
#line 365 "/root/p4c/ir/base.def"
    const IR::Expression *getExpr(size_t idx) const {
        try {
            const auto &expr = getExpr();
            return expr[idx];
        } catch (const std::out_of_range &) {
            BUG("invalid annotation expression index");
        } catch (const std::bad_variant_access &) {
            BUG("Annotation does not contain an expression list.");
        }
    }
#line 854 "/root/p4c/build/ir/ir-generated.h"
#line 375 "/root/p4c/ir/base.def"
    auto & getKV() {
        try {
            return std::get<KVAnnotation>(body);
        } catch (const std::bad_variant_access &) {
            BUG("Annotation does not contain a key-value list.");
        }
    }
#line 863 "/root/p4c/build/ir/ir-generated.h"
#line 382 "/root/p4c/ir/base.def"
    auto const & getKV() const {
        try {
            return std::get<KVAnnotation>(body);
        } catch (const std::bad_variant_access &) {
            BUG("Annotation does not contain a key-value list.");
        }
    }
#line 872 "/root/p4c/build/ir/ir-generated.h"
/// If this is true this is a structured annotation, and there are some
/// constraints on its contents.
    bool structured;
    bool operator==(IR::Annotation const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Annotation"_cs; }
    static cstring static_type_name() { return "Annotation"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Annotation(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    Annotation(Util::SourceInfo srcInfo, IR::ID name, body_variant body, bool structured) :
    Node(srcInfo), name(name), body(body), structured(structured)
    {
#line 232 "/root/p4c/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 893 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Annotation(IR::ID name, body_variant body, bool structured) :
    name(name), body(body), structured(structured)
    {
#line 232 "/root/p4c/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 900 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(Annotation)
    DECLARE_TYPEINFO_WITH_TYPEID(Annotation, NodeKind::Annotation, Node);
};
}  // namespace P4::IR
namespace P4::IR {
/// Implemented by all objects that can have annotations
// FIXME: Use CRTP to get access to the fields directly
class IAnnotated : public virtual INode {
 public:
#line 398 "/root/p4c/ir/base.def"
    virtual IR::Vector<IR::Annotation> const & getAnnotations() const = 0;
#line 913 "/root/p4c/build/ir/ir-generated.h"
#line 399 "/root/p4c/ir/base.def"
    virtual IR::Vector<IR::Annotation> & getAnnotations() = 0;
#line 916 "/root/p4c/build/ir/ir-generated.h"
#line 401 "/root/p4c/ir/base.def"
    const IR::Annotation *getAnnotation(cstring name) const {
        const auto &annotations = getAnnotations();
        return get(annotations, name);
    }
#line 922 "/root/p4c/build/ir/ir-generated.h"
/// Checks if there is annotation @name
#line 406 "/root/p4c/ir/base.def"
    bool hasAnnotation(cstring name) const {
        const auto &annotations = getAnnotations();
        return get(annotations, name) != nullptr;
    }
#line 929 "/root/p4c/build/ir/ir-generated.h"
/// Checks if there is annotation @name and it is the only annotation on the
/// node
#line 412 "/root/p4c/ir/base.def"
    bool hasOnlyAnnotation(cstring name) const {
        const auto &annotations = getAnnotations();
        return annotations.size() == 1 && get(annotations, name) != nullptr;
    }
#line 937 "/root/p4c/build/ir/ir-generated.h"
/// Check if there are any annotations
#line 417 "/root/p4c/ir/base.def"
    bool hasAnnotations() const {
        const auto &annotations = getAnnotations();
        return !annotations.empty();
    }
#line 944 "/root/p4c/build/ir/ir-generated.h"
#line 421 "/root/p4c/ir/base.def"
    void addAnnotation(const IR::Annotation* annot) {
        auto &annotations = getAnnotations();
        annotations.push_back(annot);
    }
#line 950 "/root/p4c/build/ir/ir-generated.h"
#line 425 "/root/p4c/ir/base.def"
    void addAnnotation(cstring name, const IR::Expression* expr, bool structured = false) {
        addAnnotation(new Annotation(name, { expr }, structured));
    }
#line 955 "/root/p4c/build/ir/ir-generated.h"
/// Add annotation if another annotation with the same name is not
/// already present.
#line 431 "/root/p4c/ir/base.def"
    void addAnnotationIfNew(cstring name, const IR::Expression* expr, bool structured = false) {
        Annotations::addIfNew(getAnnotations(), name, expr, structured);
    }
#line 962 "/root/p4c/build/ir/ir-generated.h"
#line 435 "/root/p4c/ir/base.def"
    void addAnnotationIfNew(const IR::Annotation* ann) {
        Annotations::addIfNew(getAnnotations(), ann);
    }
#line 967 "/root/p4c/build/ir/ir-generated.h"
/// If annotations with the same name are already present, remove them;
/// add this annotation.
#line 441 "/root/p4c/ir/base.def"
    void addOrReplaceAnnotation(cstring name, const IR::Expression* expr, bool structured = false) {
        Annotations::addOrReplace(getAnnotations(), name, expr, structured);
    }
#line 974 "/root/p4c/build/ir/ir-generated.h"
#line 445 "/root/p4c/ir/base.def"
    void addOrReplaceAnnotation(const IR::Annotation* ann) {
        Annotations::addOrReplace(getAnnotations(), ann);
    }
#line 979 "/root/p4c/build/ir/ir-generated.h"
    DECLARE_TYPEINFO_WITH_TYPEID(IAnnotated, NodeKind::IAnnotated, INode);
};
}  // namespace P4::IR
namespace P4::IR {
class IInstance : public virtual INode {
 public:
#line 451 "/root/p4c/ir/base.def"
    virtual IR::ID Name() const = 0;
#line 988 "/root/p4c/build/ir/ir-generated.h"
#line 452 "/root/p4c/ir/base.def"
    virtual const IR::Type *getType() const = 0;
#line 991 "/root/p4c/build/ir/ir-generated.h"
    DECLARE_TYPEINFO_WITH_TYPEID(IInstance, NodeKind::IInstance, INode);
};
}  // namespace P4::IR
namespace P4::IR {
/// An argument to a function call (or constructor call)
/// Arguments may have optional names
class Argument : public Node {
 public:
/// If an argument has no name the name.name is nullptr.
    IR::ID name;
    const IR::Expression* expression = nullptr;
#line 462 "/root/p4c/ir/base.def"
    void dbprint(std::ostream & out) const override;
#line 1005 "/root/p4c/build/ir/ir-generated.h"
#line 463 "/root/p4c/ir/base.def"
    void validate() const override;
#line 1008 "/root/p4c/build/ir/ir-generated.h"
#line 464 "/root/p4c/ir/base.def"
    cstring toString() const override;
#line 1011 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Argument const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Argument"_cs; }
    static cstring static_type_name() { return "Argument"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Argument(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    Argument(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* expression) :
    Node(srcInfo), name(name), expression(expression)
    {
#line 461 "/root/p4c/ir/base.def"
{ if (!srcInfo && expression) srcInfo = expression->srcInfo; }
#line 1028 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Argument(IR::ID name, const IR::Expression* expression) :
    name(name), expression(expression)
    {
#line 461 "/root/p4c/ir/base.def"
{ if (!srcInfo && expression) srcInfo = expression->srcInfo; }
#line 1035 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Argument(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    Node(srcInfo), expression(expression)
    {
#line 461 "/root/p4c/ir/base.def"
{ if (!srcInfo && expression) srcInfo = expression->srcInfo; }
#line 1042 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Argument(const IR::Expression* expression) :
    expression(expression)
    {
#line 461 "/root/p4c/ir/base.def"
{ if (!srcInfo && expression) srcInfo = expression->srcInfo; }
#line 1049 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(Argument)
    DECLARE_TYPEINFO_WITH_TYPEID(Argument, NodeKind::Argument, Node);
};
}  // namespace P4::IR
/** @} */
/* end group irdefs */
/* -*-C++-*- */
/** \addtogroup irdefs
  * @{
  */
/*
   This file contains IR related to representating the type hierarchy.
   Some of these classes never appear in the IR tree, they are just
   synthesized by the type-checker.
*/
#line 12 "/root/p4c/ir/type.def"
namespace P4 {
namespace IR {
enum class Direction {
    None,
    In,
    Out,
    InOut
};

inline cstring directionToString(IR::Direction direction) {
    switch (direction) {
        case IR::Direction::None:
            return "<none>"_cs;
        case IR::Direction::In:
            return "in"_cs;
        case IR::Direction::Out:
            return "out"_cs;
        case IR::Direction::InOut:
            return "inout"_cs;
        default:
            BUG("Unhandled case");
    }
}
}  // namespace IR

inline std::ostream& operator<<(std::ostream &out, IR::Direction d) {
    switch (d) {
        case IR::Direction::None:
            break;
        case IR::Direction::In:
            out << "in";
            break;
        case IR::Direction::Out:
            out << "out";
            break;
        case IR::Direction::InOut:
            out << "inout";
            break;
        default:
            BUG("Unhandled case");
    }
    return out;
}

// FIXME: should accept string_view
inline bool operator>>(cstring s, IR::Direction &d) {
    if (!s || s == cstring::empty) d = IR::Direction::None;
    else if (s == "in") d = IR::Direction::In;
    else if (s == "out") d = IR::Direction::Out;
    else if (s == "inout") d = IR::Direction::InOut;
    else return false;
    return true;
}

}  // namespace P4

#line 1123 "/root/p4c/build/ir/ir-generated.h"
namespace P4::IR {
/// This represents a type that can unify with any other type.
/// It is the original type of Dots (...) expressions.
/// There is no syntax to represent this type.
/// Treated like a type variable so that unification can assign it a value.
class Type_Any : public Type, public virtual ITypeVar {
 protected:
#line 77 "/root/p4c/ir/type.def"
    void *operator new(size_t size) { return ::operator new(size); }
// FIXME: Remove this #ifdefine check once we switch to C++20
#if defined(__cpp_sized_deallocation) && __cpp_sized_deallocation >= 201309L
    void operator delete(void *p, size_t size) { return ::operator delete(p, size); }
#else
    void operator delete(void *p) { return ::operator delete(p); }
#endif
#line 1139 "/root/p4c/build/ir/ir-generated.h"
    static long nextId;
 public:
    long declid = nextId++;
#line 88 "/root/p4c/ir/type.def"
    cstring getVarName() const override;
#line 1145 "/root/p4c/build/ir/ir-generated.h"
#line 89 "/root/p4c/ir/type.def"
    int getDeclId() const override;
#line 1148 "/root/p4c/build/ir/ir-generated.h"
#line 90 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1151 "/root/p4c/build/ir/ir-generated.h"
#line 91 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 1154 "/root/p4c/build/ir/ir-generated.h"
#line 92 "/root/p4c/ir/type.def"
    bool operator==(IR::Type_Any const & a) const override;
#line 1157 "/root/p4c/build/ir/ir-generated.h"
#line 93 "/root/p4c/ir/type.def"
    static const IR::Type_Any *get();
#line 1160 "/root/p4c/build/ir/ir-generated.h"
#line 94 "/root/p4c/ir/type.def"
    static const IR::Type_Any *get(Util::SourceInfo const & si);
#line 1163 "/root/p4c/build/ir/ir-generated.h"
#line 95 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 1166 "/root/p4c/build/ir/ir-generated.h"
#line 96 "/root/p4c/ir/type.def"
    bool equiv(IR::Node const & a_) const override;
#line 1169 "/root/p4c/build/ir/ir-generated.h"
    cstring node_type_name() const override { return "Type_Any"_cs; }
    static cstring static_type_name() { return "Type_Any"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Any(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Any(Util::SourceInfo srcInfo) :
    Type(srcInfo)
    { validate(); }
    Type_Any() 
    { validate(); }
    IRNODE_SUBCLASS(Type_Any)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Any, NodeKind::Type_Any, Type, ITypeVar);
};
}  // namespace P4::IR
namespace P4::IR {
/// This type is a fragment of another type.
/// This is used in conjunction with Type_Any to typecheck
/// expressions containing ... (Dots).
/// After unification this type replaces Type_Any.
/// For example:
/// struct S { bit<32> s; bit<16> t; }
/// S s = { s = 2, ... };
/// The type assigned to 'type' by unification will be
/// Type_Fragment { type = Type_UnknownStruct { t: Type_Bits<15> } }.
/// In other words, the type of the ... expression is a
/// fragment of a struct that contains just the field t.
class Type_Fragment : public Type {
 public:
    const IR::Type* type = nullptr;
#line 115 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1204 "/root/p4c/build/ir/ir-generated.h"
#line 116 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 1207 "/root/p4c/build/ir/ir-generated.h"
#line 117 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 1210 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Fragment const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Fragment"_cs; }
    static cstring static_type_name() { return "Type_Fragment"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Fragment(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Fragment(Util::SourceInfo srcInfo, const IR::Type* type) :
    Type(srcInfo), type(type)
    { validate(); }
    Type_Fragment(const IR::Type* type) :
    type(type)
    { validate(); }
    IRNODE_SUBCLASS(Type_Fragment)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Fragment, NodeKind::Type_Fragment, Type);
};
}  // namespace P4::IR
namespace P4::IR {
/// Represents the type of a type.
/// For example, in a declaration like
/// bit<32> x;
/// The type of x is Type_Bits(32);
/// The type of 'bit<32>' is Type_Type(Type_Bits(32))
/// TypeType should not appear in the program IR, just in the TypeMap produced
/// by type-checking.
class Type_Type : public Type {
 public:
    const IR::Type* type = nullptr;
#line 129 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 1246 "/root/p4c/build/ir/ir-generated.h"
#line 130 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1249 "/root/p4c/build/ir/ir-generated.h"
#line 131 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 1252 "/root/p4c/build/ir/ir-generated.h"
#line 132 "/root/p4c/ir/type.def"
    void validate() const override;
#line 1255 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Type const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Type_Type"_cs; }
    static cstring static_type_name() { return "Type_Type"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Type(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Type(Util::SourceInfo srcInfo, const IR::Type* type) :
    Type(srcInfo), type(type)
    { validate(); }
    Type_Type(const IR::Type* type) :
    type(type)
    { validate(); }
    IRNODE_SUBCLASS(Type_Type)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Type, NodeKind::Type_Type, Type);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Boolean : public Type_Base {
 protected:
#line 138 "/root/p4c/ir/type.def"
    void *operator new(size_t size) { return ::operator new(size); }
// FIXME: Remove this #ifdefine check once we switch to C++20
#if defined(__cpp_sized_deallocation) && __cpp_sized_deallocation >= 201309L
    void operator delete(void *p, size_t size) { return ::operator delete(p, size); }
#else
    void operator delete(void *p) { return ::operator delete(p); }
#endif
#line 1288 "/root/p4c/build/ir/ir-generated.h"
 public:
#line 147 "/root/p4c/ir/type.def"
    static const IR::Type_Boolean *get();
#line 1292 "/root/p4c/build/ir/ir-generated.h"
#line 148 "/root/p4c/ir/type.def"
    static const IR::Type_Boolean *get(Util::SourceInfo const & si);
#line 1295 "/root/p4c/build/ir/ir-generated.h"
#line 149 "/root/p4c/ir/type.def"
    int width_bits() const override;
#line 1298 "/root/p4c/build/ir/ir-generated.h"
#line 150 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 1301 "/root/p4c/build/ir/ir-generated.h"
#line 151 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1304 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Boolean const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Boolean"_cs; }
    static cstring static_type_name() { return "Type_Boolean"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Boolean(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Boolean(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_Boolean() 
    { validate(); }
    IRNODE_SUBCLASS(Type_Boolean)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Boolean, NodeKind::Type_Boolean, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
/// The type of a parser state
class Type_State : public Type_Base {
 protected:
#line 158 "/root/p4c/ir/type.def"
    void *operator new(size_t size) { return ::operator new(size); }
// FIXME: Remove this #ifdefine check once we switch to C++20
#if defined(__cpp_sized_deallocation) && __cpp_sized_deallocation >= 201309L
    void operator delete(void *p, size_t size) { return ::operator delete(p, size); }
#else
    void operator delete(void *p) { return ::operator delete(p); }
#endif
#line 1336 "/root/p4c/build/ir/ir-generated.h"
 public:
#line 167 "/root/p4c/ir/type.def"
    static const IR::Type_State *get();
#line 1340 "/root/p4c/build/ir/ir-generated.h"
#line 168 "/root/p4c/ir/type.def"
    static const IR::Type_State *get(Util::SourceInfo const & si);
#line 1343 "/root/p4c/build/ir/ir-generated.h"
#line 169 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 1346 "/root/p4c/build/ir/ir-generated.h"
#line 170 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1349 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_State const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_State"_cs; }
    static cstring static_type_name() { return "Type_State"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_State(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_State(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_State() 
    { validate(); }
    IRNODE_SUBCLASS(Type_State)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_State, NodeKind::Type_State, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
/// Represents both bit<> and int<> types in P4-14 and P4-16
class Type_Bits : public Type_Base {
 protected:
#line 177 "/root/p4c/ir/type.def"
    void *operator new(size_t size) { return ::operator new(size); }
// FIXME: Remove this #ifdefine check once we switch to C++20
#if defined(__cpp_sized_deallocation) && __cpp_sized_deallocation >= 201309L
    void operator delete(void *p, size_t size) { return ::operator delete(p, size); }
#else
    void operator delete(void *p) { return ::operator delete(p); }
#endif
#line 1381 "/root/p4c/build/ir/ir-generated.h"
 public:
    int size = 0;

    const IR::Expression* expression = nullptr;

    bool isSigned;
#line 189 "/root/p4c/ir/type.def"
    static const IR::Type_Bits *get(Util::SourceInfo const & si, const IR::Expression* expression, bool isSigned = false);
#line 1390 "/root/p4c/build/ir/ir-generated.h"
#line 190 "/root/p4c/ir/type.def"
    static const IR::Type_Bits *get(Util::SourceInfo const & si, int sz, bool isSigned = false);
#line 1393 "/root/p4c/build/ir/ir-generated.h"
#line 191 "/root/p4c/ir/type.def"
    static const IR::Type_Bits *get(int sz, bool isSigned = false);
#line 1396 "/root/p4c/build/ir/ir-generated.h"
#line 192 "/root/p4c/ir/type.def"
    cstring baseName() const { return isSigned ? "int"_cs : "bit"_cs; }
#line 1399 "/root/p4c/build/ir/ir-generated.h"
#line 193 "/root/p4c/ir/type.def"
    int width_bits() const override;
#line 1402 "/root/p4c/build/ir/ir-generated.h"
#line 195 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 1405 "/root/p4c/build/ir/ir-generated.h"
#line 196 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1408 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Bits const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Type_Bits"_cs; }
    static cstring static_type_name() { return "Type_Bits"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Bits(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Bits(Util::SourceInfo srcInfo, int size, const IR::Expression* expression, bool isSigned) :
    Type_Base(srcInfo), size(size), expression(expression), isSigned(isSigned)
    { validate(); }
    Type_Bits(int size, const IR::Expression* expression, bool isSigned) :
    size(size), expression(expression), isSigned(isSigned)
    { validate(); }
    Type_Bits(Util::SourceInfo srcInfo, const IR::Expression* expression, bool isSigned) :
    Type_Base(srcInfo), expression(expression), isSigned(isSigned)
    { validate(); }
    Type_Bits(const IR::Expression* expression, bool isSigned) :
    expression(expression), isSigned(isSigned)
    { validate(); }
    Type_Bits(Util::SourceInfo srcInfo, int size, bool isSigned) :
    Type_Base(srcInfo), size(size), isSigned(isSigned)
    { validate(); }
    Type_Bits(int size, bool isSigned) :
    size(size), isSigned(isSigned)
    { validate(); }
    Type_Bits(Util::SourceInfo srcInfo, bool isSigned) :
    Type_Base(srcInfo), isSigned(isSigned)
    { validate(); }
    Type_Bits(bool isSigned) :
    isSigned(isSigned)
    { validate(); }
    IRNODE_SUBCLASS(Type_Bits)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Bits, NodeKind::Type_Bits, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Varbits : public Type_Base {
 protected:
#line 202 "/root/p4c/ir/type.def"
    void *operator new(size_t size) { return ::operator new(size); }
// FIXME: Remove this #ifdefine check once we switch to C++20
#if defined(__cpp_sized_deallocation) && __cpp_sized_deallocation >= 201309L
    void operator delete(void *p, size_t size) { return ::operator delete(p, size); }
#else
    void operator delete(void *p) { return ::operator delete(p); }
#endif
#line 1461 "/root/p4c/build/ir/ir-generated.h"
 public:
    int size = 0;

    const IR::Expression* expression = nullptr;

#line 213 "/root/p4c/ir/type.def"
    static const IR::Type_Varbits *get(Util::SourceInfo const & si, const IR::Expression* expr);
#line 1469 "/root/p4c/build/ir/ir-generated.h"
#line 214 "/root/p4c/ir/type.def"
    static const IR::Type_Varbits *get(Util::SourceInfo const & si, int size);
#line 1472 "/root/p4c/build/ir/ir-generated.h"
#line 215 "/root/p4c/ir/type.def"
    static const IR::Type_Varbits *get(int size);
#line 1475 "/root/p4c/build/ir/ir-generated.h"
#line 216 "/root/p4c/ir/type.def"
    static const IR::Type_Varbits *get();
#line 1478 "/root/p4c/build/ir/ir-generated.h"
#line 217 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 1481 "/root/p4c/build/ir/ir-generated.h"
#line 218 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1484 "/root/p4c/build/ir/ir-generated.h"
#line 219 "/root/p4c/ir/type.def"
    int width_bits() const override;
#line 1487 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Varbits const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Type_Varbits"_cs; }
    static cstring static_type_name() { return "Type_Varbits"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Varbits(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Varbits(Util::SourceInfo srcInfo, int size, const IR::Expression* expression) :
    Type_Base(srcInfo), size(size), expression(expression)
    { validate(); }
    Type_Varbits(int size, const IR::Expression* expression) :
    size(size), expression(expression)
    { validate(); }
    Type_Varbits(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    Type_Base(srcInfo), expression(expression)
    { validate(); }
    Type_Varbits(const IR::Expression* expression) :
    expression(expression)
    { validate(); }
    Type_Varbits(Util::SourceInfo srcInfo, int size) :
    Type_Base(srcInfo), size(size)
    { validate(); }
    Type_Varbits(int size) :
    size(size)
    { validate(); }
    Type_Varbits(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_Varbits() 
    { validate(); }
    IRNODE_SUBCLASS(Type_Varbits)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Varbits, NodeKind::Type_Varbits, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
class Parameter : public Declaration, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    Direction direction;
    const IR::Type* type = nullptr;
    const IR::Expression* defaultValue = nullptr;
#line 227 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 1537 "/root/p4c/build/ir/ir-generated.h"
#line 228 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 1540 "/root/p4c/build/ir/ir-generated.h"
#line 229 "/root/p4c/ir/type.def"
    bool hasOut() const { return direction == IR::Direction::Out || direction == IR::Direction::InOut; }
#line 1543 "/root/p4c/build/ir/ir-generated.h"
#line 231 "/root/p4c/ir/type.def"
    bool isOptional() const {
        return getAnnotation(Annotation::optionalAnnotation) != nullptr; }
#line 1547 "/root/p4c/build/ir/ir-generated.h"
#line 233 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1550 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Parameter const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Parameter"_cs; }
    static cstring static_type_name() { return "Parameter"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Parameter(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Parameter(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, Direction direction, const IR::Type* type, const IR::Expression* defaultValue) :
    Declaration(srcInfo, name), annotations(annotations), direction(direction), type(type), defaultValue(defaultValue)
    { validate(); }
    Parameter(IR::ID name, IR::Vector<IR::Annotation> annotations, Direction direction, const IR::Type* type, const IR::Expression* defaultValue) :
    Declaration(name), annotations(annotations), direction(direction), type(type), defaultValue(defaultValue)
    { validate(); }
    Parameter(Util::SourceInfo srcInfo, IR::ID name, Direction direction, const IR::Type* type, const IR::Expression* defaultValue) :
    Declaration(srcInfo, name), direction(direction), type(type), defaultValue(defaultValue)
    { validate(); }
    Parameter(IR::ID name, Direction direction, const IR::Type* type, const IR::Expression* defaultValue) :
    Declaration(name), direction(direction), type(type), defaultValue(defaultValue)
    { validate(); }
    Parameter(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, Direction direction, const IR::Type* type) :
    Declaration(srcInfo, name), annotations(annotations), direction(direction), type(type)
    { validate(); }
    Parameter(IR::ID name, IR::Vector<IR::Annotation> annotations, Direction direction, const IR::Type* type) :
    Declaration(name), annotations(annotations), direction(direction), type(type)
    { validate(); }
    Parameter(Util::SourceInfo srcInfo, IR::ID name, Direction direction, const IR::Type* type) :
    Declaration(srcInfo, name), direction(direction), type(type)
    { validate(); }
    Parameter(IR::ID name, Direction direction, const IR::Type* type) :
    Declaration(name), direction(direction), type(type)
    { validate(); }
    IRNODE_SUBCLASS(Parameter)
    DECLARE_TYPEINFO_WITH_TYPEID(Parameter, NodeKind::Parameter, Declaration, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class ParameterList : public Node, public virtual ISimpleNamespace {
 public:
    IR::IndexedVector<IR::Parameter> parameters;
#line 239 "/root/p4c/ir/type.def"
    void validate() const override;
#line 1599 "/root/p4c/build/ir/ir-generated.h"
#line 240 "/root/p4c/ir/type.def"
    Util::Enumerator<const IR::Parameter *> * getEnumerator() const {
        return parameters.getEnumerator(); }
#line 1603 "/root/p4c/build/ir/ir-generated.h"
#line 242 "/root/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 1606 "/root/p4c/build/ir/ir-generated.h"
#line 244 "/root/p4c/ir/type.def"
    size_t size() const { return parameters.size(); }
#line 1609 "/root/p4c/build/ir/ir-generated.h"
#line 245 "/root/p4c/ir/type.def"
    bool empty() const { return size() == 0; }
#line 1612 "/root/p4c/build/ir/ir-generated.h"
#line 246 "/root/p4c/ir/type.def"
    const IR::Parameter *getParameter(cstring name) const {
        return parameters.getDeclaration<Parameter>(name); }
#line 1616 "/root/p4c/build/ir/ir-generated.h"
#line 248 "/root/p4c/ir/type.def"
    const IR::Parameter *getParameter(std::string_view name) const {
        return parameters.getDeclaration<Parameter>(name); }
#line 1620 "/root/p4c/build/ir/ir-generated.h"
#line 250 "/root/p4c/ir/type.def"
    const IR::Parameter *getParameter(unsigned index) const {
        for (auto &param : parameters)
            if (0 == index--) return param;
        BUG("Only %1% parameters; index #%2% requested", size(), size()+index); }
#line 1626 "/root/p4c/build/ir/ir-generated.h"
#line 254 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 1629 "/root/p4c/build/ir/ir-generated.h"
#line 255 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 1632 "/root/p4c/build/ir/ir-generated.h"
#line 256 "/root/p4c/ir/type.def"
    void push_back(IR::Parameter const * p) { parameters.push_back(p); }
#line 1635 "/root/p4c/build/ir/ir-generated.h"
#line 257 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 1638 "/root/p4c/build/ir/ir-generated.h"
#line 264 "/root/p4c/ir/type.def"
    auto begin() const -> decltype(parameters.begin()) { return parameters.begin(); }
    auto end() const -> decltype(parameters.end()) { return parameters.end(); }
#line 1642 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ParameterList const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "ParameterList"_cs; }
    static cstring static_type_name() { return "ParameterList"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ParameterList(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    ParameterList(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Parameter> parameters) :
    Node(srcInfo), parameters(parameters)
    { validate(); }
    ParameterList(IR::IndexedVector<IR::Parameter> parameters) :
    parameters(parameters)
    { validate(); }
    ParameterList(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    ParameterList() 
    { validate(); }
    IRNODE_SUBCLASS(ParameterList)
    DECLARE_TYPEINFO_WITH_TYPEID(ParameterList, NodeKind::ParameterList, Node, ISimpleNamespace);
};
}  // namespace P4::IR
namespace P4::IR {
/// Represents a type variable written by the user
class Type_Var : public Type_Declaration, public virtual ITypeVar {
 public:
#line 271 "/root/p4c/ir/type.def"
    cstring getVarName() const override;
#line 1675 "/root/p4c/build/ir/ir-generated.h"
#line 272 "/root/p4c/ir/type.def"
    int getDeclId() const override;
#line 1678 "/root/p4c/build/ir/ir-generated.h"
#line 273 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1681 "/root/p4c/build/ir/ir-generated.h"
#line 274 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 1684 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Var const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Var"_cs; }
    static cstring static_type_name() { return "Type_Var"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Var(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Var(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
    Type_Var(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
    IRNODE_SUBCLASS(Type_Var)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Var, NodeKind::Type_Var, Type_Declaration, ITypeVar);
};
}  // namespace P4::IR
namespace P4::IR {
/// Stands for the 'int' type: infinite precision constant
/// However, we represent it as a type variable, because we use
/// type unification to discover the correct type for the constants
/// in some contexts.
class Type_InfInt : public Type, public virtual ITypeVar {
 protected:
#line 284 "/root/p4c/ir/type.def"
    void *operator new(size_t size) { return ::operator new(size); }
// FIXME: Remove this #ifdefine check once we switch to C++20
#if defined(__cpp_sized_deallocation) && __cpp_sized_deallocation >= 201309L
    void operator delete(void *p, size_t size) { return ::operator delete(p, size); }
#else
    void operator delete(void *p) { return ::operator delete(p); }
#endif
#line 1720 "/root/p4c/build/ir/ir-generated.h"
    long declid = nextId++;
 private:
    static long nextId;
 public:
#line 296 "/root/p4c/ir/type.def"
    cstring getVarName() const override;
#line 1727 "/root/p4c/build/ir/ir-generated.h"
#line 297 "/root/p4c/ir/type.def"
    int getDeclId() const override;
#line 1730 "/root/p4c/build/ir/ir-generated.h"
#line 298 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1733 "/root/p4c/build/ir/ir-generated.h"
#line 299 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 1736 "/root/p4c/build/ir/ir-generated.h"
#line 300 "/root/p4c/ir/type.def"
    bool operator==(IR::Type_InfInt const & a) const override;
#line 1739 "/root/p4c/build/ir/ir-generated.h"
#line 301 "/root/p4c/ir/type.def"
    static const IR::Type_InfInt *get();
#line 1742 "/root/p4c/build/ir/ir-generated.h"
#line 302 "/root/p4c/ir/type.def"
    static const IR::Type_InfInt *get(Util::SourceInfo const & si);
#line 1745 "/root/p4c/build/ir/ir-generated.h"
#line 303 "/root/p4c/ir/type.def"
    bool equiv(IR::Node const & a_) const override;
#line 1748 "/root/p4c/build/ir/ir-generated.h"
#line 307 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 1751 "/root/p4c/build/ir/ir-generated.h"
#line 308 "/root/p4c/ir/type.def"
    int width_bits() const override;
#line 1754 "/root/p4c/build/ir/ir-generated.h"
    cstring node_type_name() const override { return "Type_InfInt"_cs; }
    static cstring static_type_name() { return "Type_InfInt"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_InfInt(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_InfInt(Util::SourceInfo srcInfo) :
    Type(srcInfo)
    { validate(); }
    Type_InfInt() 
    { validate(); }
    IRNODE_SUBCLASS(Type_InfInt)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_InfInt, NodeKind::Type_InfInt, Type, ITypeVar);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Dontcare : public Type_Base {
 protected:
#line 314 "/root/p4c/ir/type.def"
    void *operator new(size_t size) { return ::operator new(size); }
// FIXME: Remove this #ifdefine check once we switch to C++20
#if defined(__cpp_sized_deallocation) && __cpp_sized_deallocation >= 201309L
    void operator delete(void *p, size_t size) { return ::operator delete(p, size); }
#else
    void operator delete(void *p) { return ::operator delete(p); }
#endif
#line 1783 "/root/p4c/build/ir/ir-generated.h"
 public:
#line 323 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 1787 "/root/p4c/build/ir/ir-generated.h"
#line 324 "/root/p4c/ir/type.def"
    static const IR::Type_Dontcare *get();
#line 1790 "/root/p4c/build/ir/ir-generated.h"
#line 325 "/root/p4c/ir/type.def"
    static const IR::Type_Dontcare *get(Util::SourceInfo const & si);
#line 1793 "/root/p4c/build/ir/ir-generated.h"
#line 326 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1796 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Dontcare const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Dontcare"_cs; }
    static cstring static_type_name() { return "Type_Dontcare"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Dontcare(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Dontcare(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_Dontcare() 
    { validate(); }
    IRNODE_SUBCLASS(Type_Dontcare)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Dontcare, NodeKind::Type_Dontcare, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Void : public Type_Base {
 protected:
#line 332 "/root/p4c/ir/type.def"
    void *operator new(size_t size) { return ::operator new(size); }
// FIXME: Remove this #ifdefine check once we switch to C++20
#if defined(__cpp_sized_deallocation) && __cpp_sized_deallocation >= 201309L
    void operator delete(void *p, size_t size) { return ::operator delete(p, size); }
#else
    void operator delete(void *p) { return ::operator delete(p); }
#endif
#line 1827 "/root/p4c/build/ir/ir-generated.h"
 public:
#line 341 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 1831 "/root/p4c/build/ir/ir-generated.h"
#line 342 "/root/p4c/ir/type.def"
    static const IR::Type_Void *get();
#line 1834 "/root/p4c/build/ir/ir-generated.h"
#line 343 "/root/p4c/ir/type.def"
    static const IR::Type_Void *get(Util::SourceInfo const & si);
#line 1837 "/root/p4c/build/ir/ir-generated.h"
#line 344 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1840 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Void const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Void"_cs; }
    static cstring static_type_name() { return "Type_Void"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Void(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Void(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_Void() 
    { validate(); }
    IRNODE_SUBCLASS(Type_Void)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Void, NodeKind::Type_Void, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_MatchKind : public Type_Base {
 protected:
#line 350 "/root/p4c/ir/type.def"
    void *operator new(size_t size) { return ::operator new(size); }
// FIXME: Remove this #ifdefine check once we switch to C++20
#if defined(__cpp_sized_deallocation) && __cpp_sized_deallocation >= 201309L
    void operator delete(void *p, size_t size) { return ::operator delete(p, size); }
#else
    void operator delete(void *p) { return ::operator delete(p); }
#endif
#line 1871 "/root/p4c/build/ir/ir-generated.h"
 public:
#line 359 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 1875 "/root/p4c/build/ir/ir-generated.h"
#line 360 "/root/p4c/ir/type.def"
    static const IR::Type_MatchKind *get();
#line 1878 "/root/p4c/build/ir/ir-generated.h"
#line 361 "/root/p4c/ir/type.def"
    static const IR::Type_MatchKind *get(Util::SourceInfo const & si);
#line 1881 "/root/p4c/build/ir/ir-generated.h"
#line 362 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1884 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_MatchKind const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_MatchKind"_cs; }
    static cstring static_type_name() { return "Type_MatchKind"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_MatchKind(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_MatchKind(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_MatchKind() 
    { validate(); }
    IRNODE_SUBCLASS(Type_MatchKind)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_MatchKind, NodeKind::Type_MatchKind, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
class TypeParameters : public Node, public virtual ISimpleNamespace {
 public:
    IR::IndexedVector<IR::Type_Var> parameters;
#line 367 "/root/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 1910 "/root/p4c/build/ir/ir-generated.h"
#line 369 "/root/p4c/ir/type.def"
    bool empty() const { return parameters.empty(); }
#line 1913 "/root/p4c/build/ir/ir-generated.h"
#line 370 "/root/p4c/ir/type.def"
    size_t size() const { return parameters.size(); }
#line 1916 "/root/p4c/build/ir/ir-generated.h"
#line 371 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 1919 "/root/p4c/build/ir/ir-generated.h"
#line 373 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 1922 "/root/p4c/build/ir/ir-generated.h"
#line 375 "/root/p4c/ir/type.def"
    void push_back(const IR::Type_Var* tv) { parameters.push_back(tv); }
#line 1925 "/root/p4c/build/ir/ir-generated.h"
#line 376 "/root/p4c/ir/type.def"
    void validate() const override;
#line 1928 "/root/p4c/build/ir/ir-generated.h"
#line 377 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 1931 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TypeParameters const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "TypeParameters"_cs; }
    static cstring static_type_name() { return "TypeParameters"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TypeParameters(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    TypeParameters(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Type_Var> parameters) :
    Node(srcInfo), parameters(parameters)
    { validate(); }
    TypeParameters(IR::IndexedVector<IR::Type_Var> parameters) :
    parameters(parameters)
    { validate(); }
    TypeParameters(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    TypeParameters() 
    { validate(); }
    IRNODE_SUBCLASS(TypeParameters)
    DECLARE_TYPEINFO_WITH_TYPEID(TypeParameters, NodeKind::TypeParameters, Node, ISimpleNamespace);
};
}  // namespace P4::IR
namespace P4::IR {
class StructField : public Declaration, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::Type* type = nullptr;
#line 392 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 1965 "/root/p4c/build/ir/ir-generated.h"
#line 393 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 1968 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::StructField const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "StructField"_cs; }
    static cstring static_type_name() { return "StructField"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    StructField(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    StructField(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type) :
    Declaration(srcInfo, name), annotations(annotations), type(type)
    { validate(); }
    StructField(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type) :
    Declaration(name), annotations(annotations), type(type)
    { validate(); }
    StructField(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type) :
    Declaration(srcInfo, name), type(type)
    { validate(); }
    StructField(IR::ID name, const IR::Type* type) :
    Declaration(name), type(type)
    { validate(); }
    IRNODE_SUBCLASS(StructField)
    DECLARE_TYPEINFO_WITH_TYPEID(StructField, NodeKind::StructField, Declaration, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_StructLike : public Type_Declaration, public virtual INestedNamespace, public virtual ISimpleNamespace, public virtual IAnnotated, public virtual IMayBeGenericType {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::TypeParameters* typeParameters = new TypeParameters();
    IR::IndexedVector<IR::StructField> fields;
#line 400 "/root/p4c/ir/type.def"
    const IR::TypeParameters *getTypeParameters() const override;
#line 2007 "/root/p4c/build/ir/ir-generated.h"
#line 401 "/root/p4c/ir/type.def"
    std::vector<const IR::INamespace *> getNestedNamespaces() const override;
#line 2010 "/root/p4c/build/ir/ir-generated.h"
#line 402 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 2013 "/root/p4c/build/ir/ir-generated.h"
#line 403 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 2016 "/root/p4c/build/ir/ir-generated.h"
#line 404 "/root/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 2019 "/root/p4c/build/ir/ir-generated.h"
#line 406 "/root/p4c/ir/type.def"
    const IR::StructField *getField(cstring name) const {
        return fields.getDeclaration<StructField>(name); }
#line 2023 "/root/p4c/build/ir/ir-generated.h"
#line 408 "/root/p4c/ir/type.def"
    int getFieldIndex(cstring name) const {
        int index_pos = 0;
        for (auto f : fields) {
            if (f->name == name)
                return index_pos;
            index_pos++;
        }
        return -1;
    }
#line 2034 "/root/p4c/build/ir/ir-generated.h"
/// This function returns start offset of the given field name in bits.
/// If the given name is not a valid field name, -1 is returned.
/// The given offset may not be correct if varbit field(s) present in between.
/// Offset for all fields will be correct if:
///  - the type has only fixed width fields
///  - the type has fixed width fields with only one varbit field as a last member.
#line 423 "/root/p4c/ir/type.def"
    int getFieldBitOffset(cstring name) const {
        int offset = 0;
        for (auto f : fields) {
            if (f->name == name) {
                return offset;
            }
            offset += f->type->width_bits();
        }
        return -1;
    }
#line 2052 "/root/p4c/build/ir/ir-generated.h"
#line 433 "/root/p4c/ir/type.def"
    int width_bits() const override;
#line 2055 "/root/p4c/build/ir/ir-generated.h"
#line 439 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 2058 "/root/p4c/build/ir/ir-generated.h"
#line 441 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 2061 "/root/p4c/build/ir/ir-generated.h"
#line 443 "/root/p4c/ir/type.def"
    void validate() const override;
#line 2064 "/root/p4c/build/ir/ir-generated.h"
#line 444 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 2067 "/root/p4c/build/ir/ir-generated.h"
    IRNODE_DECLARE_APPLY_OVERLOAD(Type_StructLike)
    bool operator==(IR::Type_StructLike const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Type_StructLike"_cs; }
    static cstring static_type_name() { return "Type_StructLike"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_StructLike(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(srcInfo, name), annotations(annotations), typeParameters(typeParameters), fields(fields)
    { validate(); }
    Type_StructLike(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(name), annotations(annotations), typeParameters(typeParameters), fields(fields)
    { validate(); }
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), fields(fields)
    { validate(); }
    Type_StructLike(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(name), typeParameters(typeParameters), fields(fields)
    { validate(); }
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(srcInfo, name), annotations(annotations), fields(fields)
    { validate(); }
    Type_StructLike(IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(name), annotations(annotations), fields(fields)
    { validate(); }
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(srcInfo, name), fields(fields)
    { validate(); }
    Type_StructLike(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(name), fields(fields)
    { validate(); }
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), annotations(annotations), typeParameters(typeParameters)
    { validate(); }
    Type_StructLike(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), annotations(annotations), typeParameters(typeParameters)
    { validate(); }
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters)
    { validate(); }
    Type_StructLike(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), typeParameters(typeParameters)
    { validate(); }
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(srcInfo, name), annotations(annotations)
    { validate(); }
    Type_StructLike(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(name), annotations(annotations)
    { validate(); }
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
    Type_StructLike(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Type_StructLike)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_StructLike, NodeKind::Type_StructLike, Type_Declaration, INestedNamespace, ISimpleNamespace, IAnnotated, IMayBeGenericType);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Struct : public Type_StructLike {
 public:
#line 450 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 2138 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Struct const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Struct"_cs; }
    static cstring static_type_name() { return "Type_Struct"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Struct(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_StructLike const & a) const override;
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
    Type_Struct(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, typeParameters, fields)
    { validate(); }
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, typeParameters, fields)
    { validate(); }
    Type_Struct(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, typeParameters, fields)
    { validate(); }
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, fields)
    { validate(); }
    Type_Struct(IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, fields)
    { validate(); }
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, fields)
    { validate(); }
    Type_Struct(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, fields)
    { validate(); }
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, annotations, typeParameters)
    { validate(); }
    Type_Struct(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, annotations, typeParameters)
    { validate(); }
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, typeParameters)
    { validate(); }
    Type_Struct(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, typeParameters)
    { validate(); }
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_StructLike(srcInfo, name, annotations)
    { validate(); }
    Type_Struct(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_StructLike(name, annotations)
    { validate(); }
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name) :
    Type_StructLike(srcInfo, name)
    { validate(); }
    Type_Struct(IR::ID name) :
    Type_StructLike(name)
    { validate(); }
    IRNODE_SUBCLASS(Type_Struct)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Struct, NodeKind::Type_Struct, Type_StructLike);
};
}  // namespace P4::IR
namespace P4::IR {
/// This is the type of a struct-valued expression whose
/// exact struct type is yet unknown; we only know the field names
/// and some information about their types.
class Type_UnknownStruct : public Type_StructLike {
 public:
    bool operator==(IR::Type_UnknownStruct const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_UnknownStruct"_cs; }
    static cstring static_type_name() { return "Type_UnknownStruct"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_UnknownStruct(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_StructLike const & a) const override;
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
    Type_UnknownStruct(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, typeParameters, fields)
    { validate(); }
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, typeParameters, fields)
    { validate(); }
    Type_UnknownStruct(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, typeParameters, fields)
    { validate(); }
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, fields)
    { validate(); }
    Type_UnknownStruct(IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, fields)
    { validate(); }
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, fields)
    { validate(); }
    Type_UnknownStruct(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, fields)
    { validate(); }
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, annotations, typeParameters)
    { validate(); }
    Type_UnknownStruct(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, annotations, typeParameters)
    { validate(); }
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, typeParameters)
    { validate(); }
    Type_UnknownStruct(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, typeParameters)
    { validate(); }
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_StructLike(srcInfo, name, annotations)
    { validate(); }
    Type_UnknownStruct(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_StructLike(name, annotations)
    { validate(); }
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name) :
    Type_StructLike(srcInfo, name)
    { validate(); }
    Type_UnknownStruct(IR::ID name) :
    Type_StructLike(name)
    { validate(); }
    IRNODE_SUBCLASS(Type_UnknownStruct)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_UnknownStruct, NodeKind::Type_UnknownStruct, Type_StructLike);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_HeaderUnion : public Type_StructLike {
 public:
#line 462 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 2276 "/root/p4c/build/ir/ir-generated.h"

#line 464 "/root/p4c/ir/type.def"
    int width_bits() const override;
#line 2280 "/root/p4c/build/ir/ir-generated.h"
/// start offset of any field in a union is 0
#line 470 "/root/p4c/ir/type.def"
    int getFieldBitOffset(cstring name) const {
        for (auto f : fields) {
            if (f->name == name) {
                return 0;
            }
        }
        return -1; }
#line 2290 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_HeaderUnion const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_HeaderUnion"_cs; }
    static cstring static_type_name() { return "Type_HeaderUnion"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_HeaderUnion(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_StructLike const & a) const override;
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
    Type_HeaderUnion(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, typeParameters, fields)
    { validate(); }
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, typeParameters, fields)
    { validate(); }
    Type_HeaderUnion(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, typeParameters, fields)
    { validate(); }
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, fields)
    { validate(); }
    Type_HeaderUnion(IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, fields)
    { validate(); }
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, fields)
    { validate(); }
    Type_HeaderUnion(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, fields)
    { validate(); }
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, annotations, typeParameters)
    { validate(); }
    Type_HeaderUnion(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, annotations, typeParameters)
    { validate(); }
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, typeParameters)
    { validate(); }
    Type_HeaderUnion(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, typeParameters)
    { validate(); }
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_StructLike(srcInfo, name, annotations)
    { validate(); }
    Type_HeaderUnion(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_StructLike(name, annotations)
    { validate(); }
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name) :
    Type_StructLike(srcInfo, name)
    { validate(); }
    Type_HeaderUnion(IR::ID name) :
    Type_StructLike(name)
    { validate(); }
    IRNODE_SUBCLASS(Type_HeaderUnion)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_HeaderUnion, NodeKind::Type_HeaderUnion, Type_StructLike);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Header : public Type_StructLike {
 public:
    static const cstring setValid;
    static const cstring setInvalid;
    static const cstring isValid;
#line 484 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 2362 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Header const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Header"_cs; }
    static cstring static_type_name() { return "Type_Header"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Header(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_StructLike const & a) const override;
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Header(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
    Type_Header(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, typeParameters, fields)
    { validate(); }
    Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, typeParameters, fields)
    { validate(); }
    Type_Header(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, typeParameters, fields)
    { validate(); }
    Type_Header(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, fields)
    { validate(); }
    Type_Header(IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, fields)
    { validate(); }
    Type_Header(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, fields)
    { validate(); }
    Type_Header(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, fields)
    { validate(); }
    Type_Header(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, annotations, typeParameters)
    { validate(); }
    Type_Header(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, annotations, typeParameters)
    { validate(); }
    Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, typeParameters)
    { validate(); }
    Type_Header(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, typeParameters)
    { validate(); }
    Type_Header(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_StructLike(srcInfo, name, annotations)
    { validate(); }
    Type_Header(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_StructLike(name, annotations)
    { validate(); }
    Type_Header(Util::SourceInfo srcInfo, IR::ID name) :
    Type_StructLike(srcInfo, name)
    { validate(); }
    Type_Header(IR::ID name) :
    Type_StructLike(name)
    { validate(); }
    IRNODE_SUBCLASS(Type_Header)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Header, NodeKind::Type_Header, Type_StructLike);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Set : public Type {
 public:
    const IR::Type* elementType = nullptr;
#line 489 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 2432 "/root/p4c/build/ir/ir-generated.h"
#line 490 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 2435 "/root/p4c/build/ir/ir-generated.h"
#line 491 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2438 "/root/p4c/build/ir/ir-generated.h"
#line 492 "/root/p4c/ir/type.def"
    int width_bits() const override;
#line 2441 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Set const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Set"_cs; }
    static cstring static_type_name() { return "Type_Set"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Set(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Set(Util::SourceInfo srcInfo, const IR::Type* elementType) :
    Type(srcInfo), elementType(elementType)
    { validate(); }
    Type_Set(const IR::Type* elementType) :
    elementType(elementType)
    { validate(); }
    IRNODE_SUBCLASS(Type_Set)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Set, NodeKind::Type_Set, Type);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Indexed : public virtual INode {
 public:


#line 501 "/root/p4c/ir/type.def"
    virtual size_t getSize() const = 0;
#line 2471 "/root/p4c/build/ir/ir-generated.h"
#line 502 "/root/p4c/ir/type.def"
    virtual const IR::Type *at(size_t index) const = 0;
#line 2474 "/root/p4c/build/ir/ir-generated.h"
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Indexed, NodeKind::Type_Indexed, INode);
};
}  // namespace P4::IR
namespace P4::IR {
/// Base class for Type_List, and Type_Tuple
class Type_BaseList : public Type, public virtual Type_Indexed {
 public:
    IR::Vector<IR::Type> components;
#line 508 "/root/p4c/ir/type.def"
    void validate() const override;
#line 2485 "/root/p4c/build/ir/ir-generated.h"
#line 509 "/root/p4c/ir/type.def"
    size_t getSize() const override;
#line 2488 "/root/p4c/build/ir/ir-generated.h"
#line 510 "/root/p4c/ir/type.def"
    const IR::Type *at(size_t index) const override;
#line 2491 "/root/p4c/build/ir/ir-generated.h"
#line 511 "/root/p4c/ir/type.def"
    int width_bits() const override;
#line 2494 "/root/p4c/build/ir/ir-generated.h"
#line 518 "/root/p4c/ir/type.def"
    cstring asString(char const * name) const;
#line 2497 "/root/p4c/build/ir/ir-generated.h"
#line 528 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 2500 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_BaseList const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Type_BaseList"_cs; }
    static cstring static_type_name() { return "Type_BaseList"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_BaseList(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Type_BaseList(Util::SourceInfo srcInfo, IR::Vector<IR::Type> components) :
    Type(srcInfo), components(components)
    { validate(); }
    Type_BaseList(IR::Vector<IR::Type> components) :
    components(components)
    { validate(); }
    Type_BaseList(Util::SourceInfo srcInfo) :
    Type(srcInfo)
    { validate(); }
    Type_BaseList() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Type_BaseList)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_BaseList, NodeKind::Type_BaseList, Type, Type_Indexed);
};
}  // namespace P4::IR
namespace P4::IR {
/// The type of an expressionList; can be unified with both Type_Tuple and Type_Struct
class Type_List : public Type_BaseList {
 public:
#line 535 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2533 "/root/p4c/build/ir/ir-generated.h"

#line 537 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 2537 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_List const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_List"_cs; }
    static cstring static_type_name() { return "Type_List"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_List(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_BaseList const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_List(Util::SourceInfo srcInfo, IR::Vector<IR::Type> components) :
    Type_BaseList(srcInfo, components)
    { validate(); }
    Type_List(IR::Vector<IR::Type> components) :
    Type_BaseList(components)
    { validate(); }
    Type_List(Util::SourceInfo srcInfo) :
    Type_BaseList(srcInfo)
    { validate(); }
    Type_List() 
    { validate(); }
    IRNODE_SUBCLASS(Type_List)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_List, NodeKind::Type_List, Type_BaseList);
};
}  // namespace P4::IR
namespace P4::IR {
/// The type of a tuple.
class Type_Tuple : public Type_BaseList {
 public:
#line 544 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2570 "/root/p4c/build/ir/ir-generated.h"
#line 545 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 2573 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Tuple const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Tuple"_cs; }
    static cstring static_type_name() { return "Type_Tuple"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Tuple(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_BaseList const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Tuple(Util::SourceInfo srcInfo, IR::Vector<IR::Type> components) :
    Type_BaseList(srcInfo, components)
    { validate(); }
    Type_Tuple(IR::Vector<IR::Type> components) :
    Type_BaseList(components)
    { validate(); }
    Type_Tuple(Util::SourceInfo srcInfo) :
    Type_BaseList(srcInfo)
    { validate(); }
    Type_Tuple() 
    { validate(); }
    IRNODE_SUBCLASS(Type_Tuple)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Tuple, NodeKind::Type_Tuple, Type_BaseList);
};
}  // namespace P4::IR
namespace P4::IR {
/// The type of a P4ListExpression.
class Type_P4List : public Type {
 public:
    const IR::Type* elementType = nullptr;
#line 553 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2607 "/root/p4c/build/ir/ir-generated.h"
#line 554 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 2610 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_P4List const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_P4List"_cs; }
    static cstring static_type_name() { return "Type_P4List"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_P4List(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_P4List(Util::SourceInfo srcInfo, const IR::Type* elementType) :
    Type(srcInfo), elementType(elementType)
    { validate(); }
    Type_P4List(const IR::Type* elementType) :
    elementType(elementType)
    { validate(); }
    IRNODE_SUBCLASS(Type_P4List)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_P4List, NodeKind::Type_P4List, Type);
};
}  // namespace P4::IR
namespace P4::IR {
/// The type of an architectural block.
/// Abstract base for Type_Control, Type_Parser and Type_Package
class Type_ArchBlock : public Type_Declaration, public virtual IMayBeGenericType, public virtual IAnnotated, public virtual ISimpleNamespace {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::TypeParameters* typeParameters = new TypeParameters;
#line 564 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 2643 "/root/p4c/build/ir/ir-generated.h"
#line 565 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 2646 "/root/p4c/build/ir/ir-generated.h"
#line 566 "/root/p4c/ir/type.def"
    const IR::TypeParameters *getTypeParameters() const override;
#line 2649 "/root/p4c/build/ir/ir-generated.h"
#line 567 "/root/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 2652 "/root/p4c/build/ir/ir-generated.h"
#line 569 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 2655 "/root/p4c/build/ir/ir-generated.h"
#line 571 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 2658 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_ArchBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_ArchBlock"_cs; }
    static cstring static_type_name() { return "Type_ArchBlock"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_ArchBlock(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), annotations(annotations), typeParameters(typeParameters)
    { validate(); }
    Type_ArchBlock(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), annotations(annotations), typeParameters(typeParameters)
    { validate(); }
    Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters)
    { validate(); }
    Type_ArchBlock(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), typeParameters(typeParameters)
    { validate(); }
    Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(srcInfo, name), annotations(annotations)
    { validate(); }
    Type_ArchBlock(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(name), annotations(annotations)
    { validate(); }
    Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
    Type_ArchBlock(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Type_ArchBlock)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_ArchBlock, NodeKind::Type_ArchBlock, Type_Declaration, IMayBeGenericType, IAnnotated, ISimpleNamespace);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Package : public Type_ArchBlock, public virtual IContainer, public virtual ISimpleNamespace {
 public:
#line 576 "/root/p4c/ir/type.def"
    const IR::Type *getType() const override;
#line 2705 "/root/p4c/build/ir/ir-generated.h"
    const IR::ParameterList* constructorParams = nullptr;
#line 578 "/root/p4c/ir/type.def"
    const IR::Type_Method *getConstructorMethodType() const override;
#line 2709 "/root/p4c/build/ir/ir-generated.h"
#line 579 "/root/p4c/ir/type.def"
    const IR::ParameterList *getConstructorParameters() const override;
#line 2712 "/root/p4c/build/ir/ir-generated.h"
#line 580 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 2715 "/root/p4c/build/ir/ir-generated.h"
#line 581 "/root/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 2718 "/root/p4c/build/ir/ir-generated.h"
#line 583 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 2721 "/root/p4c/build/ir/ir-generated.h"
#line 587 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 2724 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Package const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Package"_cs; }
    static cstring static_type_name() { return "Type_Package"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Package(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_ArchBlock const & a) const override;
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Package(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(srcInfo, name, annotations, typeParameters), constructorParams(constructorParams)
    { validate(); }
    Type_Package(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(name, annotations, typeParameters), constructorParams(constructorParams)
    { validate(); }
    Type_Package(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(srcInfo, name, typeParameters), constructorParams(constructorParams)
    { validate(); }
    Type_Package(IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(name, typeParameters), constructorParams(constructorParams)
    { validate(); }
    Type_Package(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(srcInfo, name, annotations), constructorParams(constructorParams)
    { validate(); }
    Type_Package(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(name, annotations), constructorParams(constructorParams)
    { validate(); }
    Type_Package(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(srcInfo, name), constructorParams(constructorParams)
    { validate(); }
    Type_Package(IR::ID name, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(name), constructorParams(constructorParams)
    { validate(); }
    IRNODE_SUBCLASS(Type_Package)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Package, NodeKind::Type_Package, Type_ArchBlock, IContainer, ISimpleNamespace);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Parser : public Type_ArchBlock, public virtual IApply {
 public:
    const IR::ParameterList* applyParams = nullptr;
#line 595 "/root/p4c/ir/type.def"
    const IR::Type_Method *getApplyMethodType() const override;
#line 2774 "/root/p4c/build/ir/ir-generated.h"
#line 596 "/root/p4c/ir/type.def"
    const IR::ParameterList *getApplyParameters() const override;
#line 2777 "/root/p4c/build/ir/ir-generated.h"
#line 597 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 2780 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Parser const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Parser"_cs; }
    static cstring static_type_name() { return "Type_Parser"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Parser(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_ArchBlock const & a) const override;
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Parser(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, annotations, typeParameters), applyParams(applyParams)
    { validate(); }
    Type_Parser(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, annotations, typeParameters), applyParams(applyParams)
    { validate(); }
    Type_Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, typeParameters), applyParams(applyParams)
    { validate(); }
    Type_Parser(IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, typeParameters), applyParams(applyParams)
    { validate(); }
    Type_Parser(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, annotations), applyParams(applyParams)
    { validate(); }
    Type_Parser(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, annotations), applyParams(applyParams)
    { validate(); }
    Type_Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name), applyParams(applyParams)
    { validate(); }
    Type_Parser(IR::ID name, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name), applyParams(applyParams)
    { validate(); }
    IRNODE_SUBCLASS(Type_Parser)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Parser, NodeKind::Type_Parser, Type_ArchBlock, IApply);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Control : public Type_ArchBlock, public virtual IApply {
 public:
    const IR::ParameterList* applyParams = nullptr;
#line 602 "/root/p4c/ir/type.def"
    const IR::Type_Method *getApplyMethodType() const override;
#line 2830 "/root/p4c/build/ir/ir-generated.h"
#line 603 "/root/p4c/ir/type.def"
    const IR::ParameterList *getApplyParameters() const override;
#line 2833 "/root/p4c/build/ir/ir-generated.h"
#line 604 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 2836 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Control const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Control"_cs; }
    static cstring static_type_name() { return "Type_Control"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Control(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_ArchBlock const & a) const override;
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Control(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, annotations, typeParameters), applyParams(applyParams)
    { validate(); }
    Type_Control(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, annotations, typeParameters), applyParams(applyParams)
    { validate(); }
    Type_Control(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, typeParameters), applyParams(applyParams)
    { validate(); }
    Type_Control(IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, typeParameters), applyParams(applyParams)
    { validate(); }
    Type_Control(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, annotations), applyParams(applyParams)
    { validate(); }
    Type_Control(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, annotations), applyParams(applyParams)
    { validate(); }
    Type_Control(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name), applyParams(applyParams)
    { validate(); }
    Type_Control(IR::ID name, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name), applyParams(applyParams)
    { validate(); }
    IRNODE_SUBCLASS(Type_Control)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Control, NodeKind::Type_Control, Type_ArchBlock, IApply);
};
}  // namespace P4::IR
namespace P4::IR {
/// A type referred by name
class Type_Name : public Type {
 public:
    const IR::Path* path = nullptr;
#line 610 "/root/p4c/ir/type.def"
    Type_Name(IR::ID id);
#line 2887 "/root/p4c/build/ir/ir-generated.h"
#line 611 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 2890 "/root/p4c/build/ir/ir-generated.h"
#line 612 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 2893 "/root/p4c/build/ir/ir-generated.h"
#line 613 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2896 "/root/p4c/build/ir/ir-generated.h"
#line 614 "/root/p4c/ir/type.def"
    int width_bits() const override;
#line 2899 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Name const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Name"_cs; }
    static cstring static_type_name() { return "Type_Name"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Name(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Name(Util::SourceInfo srcInfo, const IR::Path* path) :
    Type(srcInfo), path(path)
    { validate(); }
    Type_Name(const IR::Path* path) :
    path(path)
    { validate(); }
    IRNODE_SUBCLASS(Type_Name)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Name, NodeKind::Type_Name, Type);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Stack : public virtual Type_Indexed, public Type {
 public:
    const IR::Type* elementType = nullptr;
    const IR::Expression* size = nullptr;
#line 623 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 2929 "/root/p4c/build/ir/ir-generated.h"
#line 629 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 2932 "/root/p4c/build/ir/ir-generated.h"
#line 630 "/root/p4c/ir/type.def"
    bool sizeKnown() const;
#line 2935 "/root/p4c/build/ir/ir-generated.h"
#line 631 "/root/p4c/ir/type.def"
    size_t getSize() const override;
#line 2938 "/root/p4c/build/ir/ir-generated.h"
#line 632 "/root/p4c/ir/type.def"
    const IR::Type *at(size_t index) const override;
#line 2941 "/root/p4c/build/ir/ir-generated.h"
    static const cstring next;
    static const cstring last;
    static const cstring arraySize;
    static const cstring lastIndex;
    static const cstring push_front;
    static const cstring pop_front;
#line 639 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2950 "/root/p4c/build/ir/ir-generated.h"
#line 641 "/root/p4c/ir/type.def"
    int width_bits() const override;
#line 2953 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Stack const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Stack"_cs; }
    static cstring static_type_name() { return "Type_Stack"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Stack(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Stack(Util::SourceInfo srcInfo, const IR::Type* elementType, const IR::Expression* size) :
    Type(srcInfo), elementType(elementType), size(size)
    { validate(); }
    Type_Stack(const IR::Type* elementType, const IR::Expression* size) :
    elementType(elementType), size(size)
    { validate(); }
    IRNODE_SUBCLASS(Type_Stack)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Stack, NodeKind::Type_Stack, Type_Indexed, Type);
};
}  // namespace P4::IR
namespace P4::IR {
/** Given a declaration
   extern E<T> { ... }
   Type_Specialized represents a type such
   E<bit<32>>
   baseType is Type_Name E, arguments is a vector containing Type_Bits(32) */
class Type_Specialized : public Type {
 public:
    const IR::Type_Name* baseType = nullptr;
    const IR::Vector<IR::Type>* arguments = nullptr;
#line 652 "/root/p4c/ir/type.def"
    void validate() const override;
#line 2988 "/root/p4c/build/ir/ir-generated.h"
#line 653 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2991 "/root/p4c/build/ir/ir-generated.h"
#line 654 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 2994 "/root/p4c/build/ir/ir-generated.h"
#line 664 "/root/p4c/ir/type.def"
    Type_Specialized(cstring bt, std::initializer_list<const IR::Type *> args);
#line 2997 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Specialized const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Type_Specialized"_cs; }
    static cstring static_type_name() { return "Type_Specialized"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Specialized(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Specialized(Util::SourceInfo srcInfo, const IR::Type_Name* baseType, const IR::Vector<IR::Type>* arguments) :
    Type(srcInfo), baseType(baseType), arguments(arguments)
    { validate(); }
    Type_Specialized(const IR::Type_Name* baseType, const IR::Vector<IR::Type>* arguments) :
    baseType(baseType), arguments(arguments)
    { validate(); }
    IRNODE_SUBCLASS(Type_Specialized)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Specialized, NodeKind::Type_Specialized, Type);
};
}  // namespace P4::IR
namespace P4::IR {
/** Canonical representation of a Type_Specialized;
   only used by the type-checker, never in the IR tree. */
class Type_SpecializedCanonical : public Type {
 public:
    const IR::Type* baseType = nullptr;
/// canonical baseType; always IMayBeGenericType
    const IR::Vector<IR::Type>* arguments = nullptr;
/// canonical type arguments
/// 'substituted' is baseType with all type
/// variables substituted with the arguments.
    const IR::Type* substituted = nullptr;

#line 677 "/root/p4c/ir/type.def"
    void validate() const override;
#line 3035 "/root/p4c/build/ir/ir-generated.h"
#line 682 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 3038 "/root/p4c/build/ir/ir-generated.h"
#line 683 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 3041 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_SpecializedCanonical const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Type_SpecializedCanonical"_cs; }
    static cstring static_type_name() { return "Type_SpecializedCanonical"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_SpecializedCanonical(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_SpecializedCanonical(Util::SourceInfo srcInfo, const IR::Type* baseType, const IR::Vector<IR::Type>* arguments, const IR::Type* substituted) :
    Type(srcInfo), baseType(baseType), arguments(arguments), substituted(substituted)
    { validate(); }
    Type_SpecializedCanonical(const IR::Type* baseType, const IR::Vector<IR::Type>* arguments, const IR::Type* substituted) :
    baseType(baseType), arguments(arguments), substituted(substituted)
    { validate(); }
    IRNODE_SUBCLASS(Type_SpecializedCanonical)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_SpecializedCanonical, NodeKind::Type_SpecializedCanonical, Type);
};
}  // namespace P4::IR
namespace P4::IR {
/// A declaration that consists of just an identifier, e.g., an enum member
class Declaration_ID : public Declaration, public virtual CompileTimeValue {
 public:
    bool operator==(IR::Declaration_ID const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Declaration_ID"_cs; }
    static cstring static_type_name() { return "Declaration_ID"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Declaration_ID(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Declaration_ID(Util::SourceInfo srcInfo, IR::ID name) :
    Declaration(srcInfo, name)
    { validate(); }
    Declaration_ID(IR::ID name) :
    Declaration(name)
    { validate(); }
    IRNODE_SUBCLASS(Declaration_ID)
    DECLARE_TYPEINFO_WITH_TYPEID(Declaration_ID, NodeKind::Declaration_ID, Declaration, CompileTimeValue);
};
}  // namespace P4::IR
namespace P4::IR {
/// The type of a string literal
class Type_String : public Type_Base {
 public:
 protected:
#line 696 "/root/p4c/ir/type.def"
    void *operator new(size_t size) { return ::operator new(size); }
// FIXME: Remove this #ifdefine check once we switch to C++20
#if defined(__cpp_sized_deallocation) && __cpp_sized_deallocation >= 201309L
    void operator delete(void *p, size_t size) { return ::operator delete(p, size); }
#else
    void operator delete(void *p) { return ::operator delete(p); }
#endif
#line 3100 "/root/p4c/build/ir/ir-generated.h"
 public:
#line 705 "/root/p4c/ir/type.def"
    static const IR::Type_String *get();
#line 3104 "/root/p4c/build/ir/ir-generated.h"
#line 706 "/root/p4c/ir/type.def"
    static const IR::Type_String *get(Util::SourceInfo const & si);
#line 3107 "/root/p4c/build/ir/ir-generated.h"
#line 707 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 3110 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_String const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_String"_cs; }
    static cstring static_type_name() { return "Type_String"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_String(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_String(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_String() 
    { validate(); }
    IRNODE_SUBCLASS(Type_String)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_String, NodeKind::Type_String, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Enum : public Type_Declaration, public virtual ISimpleNamespace, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    IR::IndexedVector<IR::Declaration_ID> members;
#line 713 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 3137 "/root/p4c/build/ir/ir-generated.h"
#line 714 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 3140 "/root/p4c/build/ir/ir-generated.h"
#line 715 "/root/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 3143 "/root/p4c/build/ir/ir-generated.h"
#line 717 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 3146 "/root/p4c/build/ir/ir-generated.h"
#line 719 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 3149 "/root/p4c/build/ir/ir-generated.h"
#line 722 "/root/p4c/ir/type.def"
    void validate() const override;
#line 3152 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Enum const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Type_Enum"_cs; }
    static cstring static_type_name() { return "Type_Enum"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Enum(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Enum(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(srcInfo, name), annotations(annotations), members(members)
    { validate(); }
    Type_Enum(IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(name), annotations(annotations), members(members)
    { validate(); }
    Type_Enum(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(srcInfo, name), members(members)
    { validate(); }
    Type_Enum(IR::ID name, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(name), members(members)
    { validate(); }
    IRNODE_SUBCLASS(Type_Enum)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Enum, NodeKind::Type_Enum, Type_Declaration, ISimpleNamespace, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
/// A member of a serializable enum with a backing value
class SerEnumMember : public Declaration, public virtual CompileTimeValue {
 public:
    const IR::Expression* value = nullptr;
#line 728 "/root/p4c/ir/type.def"
    void validate() const override;
#line 3188 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::SerEnumMember const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "SerEnumMember"_cs; }
    static cstring static_type_name() { return "SerEnumMember"_cs; }
    void toJSON(JSONGenerator & json) const override;
    SerEnumMember(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    SerEnumMember(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* value) :
    Declaration(srcInfo, name), value(value)
    { validate(); }
    SerEnumMember(IR::ID name, const IR::Expression* value) :
    Declaration(name), value(value)
    { validate(); }
    IRNODE_SUBCLASS(SerEnumMember)
    DECLARE_TYPEINFO_WITH_TYPEID(SerEnumMember, NodeKind::SerEnumMember, Declaration, CompileTimeValue);
};
}  // namespace P4::IR
namespace P4::IR {
/** A serializable enumeration with a backing type */
class Type_SerEnum : public Type_Declaration, public virtual ISimpleNamespace, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::Type* type = nullptr;
    IR::IndexedVector<IR::SerEnumMember> members;
#line 737 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 3220 "/root/p4c/build/ir/ir-generated.h"
#line 738 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 3223 "/root/p4c/build/ir/ir-generated.h"
#line 739 "/root/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 3226 "/root/p4c/build/ir/ir-generated.h"
#line 741 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 3229 "/root/p4c/build/ir/ir-generated.h"
#line 743 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 3232 "/root/p4c/build/ir/ir-generated.h"
#line 746 "/root/p4c/ir/type.def"
    void validate() const override;
#line 3235 "/root/p4c/build/ir/ir-generated.h"
#line 747 "/root/p4c/ir/type.def"
    int width_bits() const override;
#line 3238 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_SerEnum const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Type_SerEnum"_cs; }
    static cstring static_type_name() { return "Type_SerEnum"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_SerEnum(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_SerEnum(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members) :
    Type_Declaration(srcInfo, name), annotations(annotations), type(type), members(members)
    { validate(); }
    Type_SerEnum(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members) :
    Type_Declaration(name), annotations(annotations), type(type), members(members)
    { validate(); }
    Type_SerEnum(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members) :
    Type_Declaration(srcInfo, name), type(type), members(members)
    { validate(); }
    Type_SerEnum(IR::ID name, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members) :
    Type_Declaration(name), type(type), members(members)
    { validate(); }
    IRNODE_SUBCLASS(Type_SerEnum)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_SerEnum, NodeKind::Type_SerEnum, Type_Declaration, ISimpleNamespace, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Table : public Type, public virtual IApply {
 public:
    const IR::P4Table* table = nullptr;
#line 752 "/root/p4c/ir/type.def"
    const IR::Type_Method *getApplyMethodType() const override;
#line 3273 "/root/p4c/build/ir/ir-generated.h"
#line 753 "/root/p4c/ir/type.def"
    const IR::ParameterList *getApplyParameters() const override;
#line 3276 "/root/p4c/build/ir/ir-generated.h"
/// names for the fields of the struct returned
/// by applying a table
    static const IR::ID hit;
    static const IR::ID miss;
    static const IR::ID action_run;
#line 759 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 3284 "/root/p4c/build/ir/ir-generated.h"
#line 760 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 3287 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Table const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Table"_cs; }
    static cstring static_type_name() { return "Type_Table"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Table(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Table(Util::SourceInfo srcInfo, const IR::P4Table* table) :
    Type(srcInfo), table(table)
    { validate(); }
    Type_Table(const IR::P4Table* table) :
    table(table)
    { validate(); }
    IRNODE_SUBCLASS(Type_Table)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Table, NodeKind::Type_Table, Type, IApply);
};
}  // namespace P4::IR
namespace P4::IR {
/// A special enum-like anonymous type that
/// represents all actions in a table's action list.
/// Used for 'switch' statements.
class Type_ActionEnum : public Type {
 public:
    const IR::ActionList* actionList = nullptr;
#line 768 "/root/p4c/ir/type.def"
    bool contains(cstring name) const;
#line 3319 "/root/p4c/build/ir/ir-generated.h"
#line 769 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 3322 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_ActionEnum const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_ActionEnum"_cs; }
    static cstring static_type_name() { return "Type_ActionEnum"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_ActionEnum(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_ActionEnum(Util::SourceInfo srcInfo, const IR::ActionList* actionList) :
    Type(srcInfo), actionList(actionList)
    { validate(); }
    Type_ActionEnum(const IR::ActionList* actionList) :
    actionList(actionList)
    { validate(); }
    IRNODE_SUBCLASS(Type_ActionEnum)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_ActionEnum, NodeKind::Type_ActionEnum, Type);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_MethodBase : public Type, public virtual IMayBeGenericType, public virtual ISimpleNamespace {
 public:

    const IR::TypeParameters* typeParameters = new TypeParameters();
    const IR::Type* returnType = nullptr;

    const IR::ParameterList* parameters = nullptr;
#line 779 "/root/p4c/ir/type.def"
    size_t maxParameterCount() const { return parameters->size(); }
#line 3356 "/root/p4c/build/ir/ir-generated.h"
#line 780 "/root/p4c/ir/type.def"
    size_t minParameterCount() const {
        size_t rv = 0;
        for (auto p : *parameters)
            if (!p->isOptional()) ++rv;
        return rv;
    }
#line 3364 "/root/p4c/build/ir/ir-generated.h"
#line 786 "/root/p4c/ir/type.def"
    const IR::TypeParameters *getTypeParameters() const override;
#line 3367 "/root/p4c/build/ir/ir-generated.h"
#line 787 "/root/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 3370 "/root/p4c/build/ir/ir-generated.h"
#line 788 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 3373 "/root/p4c/build/ir/ir-generated.h"
#line 789 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 3376 "/root/p4c/build/ir/ir-generated.h"
#line 790 "/root/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 3379 "/root/p4c/build/ir/ir-generated.h"
#line 792 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 3382 "/root/p4c/build/ir/ir-generated.h"
#line 796 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 3385 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_MethodBase const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_MethodBase"_cs; }
    static cstring static_type_name() { return "Type_MethodBase"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_MethodBase(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Type_MethodBase(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type(srcInfo), typeParameters(typeParameters), returnType(returnType), parameters(parameters)
    { validate(); }
    Type_MethodBase(const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters) :
    typeParameters(typeParameters), returnType(returnType), parameters(parameters)
    { validate(); }
    Type_MethodBase(Util::SourceInfo srcInfo, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type(srcInfo), returnType(returnType), parameters(parameters)
    { validate(); }
    Type_MethodBase(const IR::Type* returnType, const IR::ParameterList* parameters) :
    returnType(returnType), parameters(parameters)
    { validate(); }
    Type_MethodBase(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters) :
    Type(srcInfo), typeParameters(typeParameters), parameters(parameters)
    { validate(); }
    Type_MethodBase(const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters) :
    typeParameters(typeParameters), parameters(parameters)
    { validate(); }
    Type_MethodBase(Util::SourceInfo srcInfo, const IR::ParameterList* parameters) :
    Type(srcInfo), parameters(parameters)
    { validate(); }
    Type_MethodBase(const IR::ParameterList* parameters) :
    parameters(parameters)
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Type_MethodBase)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_MethodBase, NodeKind::Type_MethodBase, Type, IMayBeGenericType, ISimpleNamespace);
};
}  // namespace P4::IR
namespace P4::IR {
/// Type for a method or function.
class Type_Method : public Type_MethodBase {
 public:

    cstring name;
#line 807 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 3434 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Method const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Method"_cs; }
    static cstring static_type_name() { return "Type_Method"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Method(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_MethodBase const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Method(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(srcInfo, typeParameters, returnType, parameters), name(name)
    { validate(); }
    Type_Method(const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(typeParameters, returnType, parameters), name(name)
    { validate(); }
    Type_Method(Util::SourceInfo srcInfo, const IR::Type* returnType, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(srcInfo, returnType, parameters), name(name)
    { validate(); }
    Type_Method(const IR::Type* returnType, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(returnType, parameters), name(name)
    { validate(); }
    Type_Method(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(srcInfo, typeParameters, parameters), name(name)
    { validate(); }
    Type_Method(const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(typeParameters, parameters), name(name)
    { validate(); }
    Type_Method(Util::SourceInfo srcInfo, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(srcInfo, parameters), name(name)
    { validate(); }
    Type_Method(const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(parameters), name(name)
    { validate(); }
    IRNODE_SUBCLASS(Type_Method)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Method, NodeKind::Type_Method, Type_MethodBase);
};
}  // namespace P4::IR
namespace P4::IR {
/// Describes an argument of a MethodCall
/// Never used in the program IR; only used by typechecker.
class ArgumentInfo : public Node {
 public:
    bool leftValue;
    bool compileTimeConstant;
    const IR::Type* type = nullptr;
    const IR::Argument* argument = nullptr;
#line 817 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 3485 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ArgumentInfo const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ArgumentInfo"_cs; }
    static cstring static_type_name() { return "ArgumentInfo"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ArgumentInfo(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    ArgumentInfo(Util::SourceInfo srcInfo, bool leftValue, bool compileTimeConstant, const IR::Type* type, const IR::Argument* argument) :
    Node(srcInfo), leftValue(leftValue), compileTimeConstant(compileTimeConstant), type(type), argument(argument)
    { validate(); }
    ArgumentInfo(bool leftValue, bool compileTimeConstant, const IR::Type* type, const IR::Argument* argument) :
    leftValue(leftValue), compileTimeConstant(compileTimeConstant), type(type), argument(argument)
    { validate(); }
    IRNODE_SUBCLASS(ArgumentInfo)
    DECLARE_TYPEINFO_WITH_TYPEID(ArgumentInfo, NodeKind::ArgumentInfo, Node);
};
}  // namespace P4::IR
namespace P4::IR {
/// Used to represent the type of a MethodCallExpression
/// for unification.
/// Never appears in the program IR; only used by the typechecker.
class Type_MethodCall : public Type {
 public:
    const IR::Vector<IR::Type>* typeArguments = nullptr;
    const IR::Type_Var* returnType = nullptr;
    const IR::Vector<IR::ArgumentInfo>* arguments = nullptr;
#line 828 "/root/p4c/ir/type.def"
    void validate() const override;
#line 3519 "/root/p4c/build/ir/ir-generated.h"
#line 829 "/root/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 3522 "/root/p4c/build/ir/ir-generated.h"
#line 830 "/root/p4c/ir/type.def"
    cstring toString() const override;
#line 3525 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_MethodCall const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Type_MethodCall"_cs; }
    static cstring static_type_name() { return "Type_MethodCall"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_MethodCall(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_MethodCall(Util::SourceInfo srcInfo, const IR::Vector<IR::Type>* typeArguments, const IR::Type_Var* returnType, const IR::Vector<IR::ArgumentInfo>* arguments) :
    Type(srcInfo), typeArguments(typeArguments), returnType(returnType), arguments(arguments)
    { validate(); }
    Type_MethodCall(const IR::Vector<IR::Type>* typeArguments, const IR::Type_Var* returnType, const IR::Vector<IR::ArgumentInfo>* arguments) :
    typeArguments(typeArguments), returnType(returnType), arguments(arguments)
    { validate(); }
    IRNODE_SUBCLASS(Type_MethodCall)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_MethodCall, NodeKind::Type_MethodCall, Type);
};
}  // namespace P4::IR
namespace P4::IR {
/// Actions look a lot like methods in many respects.
/// However, invoking an action returns another action
/// Having different IR nodes allows performing different transforms in visitors
class Type_Action : public Type_MethodBase {
 public:
    bool operator==(IR::Type_Action const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Action"_cs; }
    static cstring static_type_name() { return "Type_Action"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Action(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_MethodBase const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Action(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type_MethodBase(srcInfo, typeParameters, returnType, parameters)
    { validate(); }
    Type_Action(const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type_MethodBase(typeParameters, returnType, parameters)
    { validate(); }
    Type_Action(Util::SourceInfo srcInfo, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type_MethodBase(srcInfo, returnType, parameters)
    { validate(); }
    Type_Action(const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type_MethodBase(returnType, parameters)
    { validate(); }
    Type_Action(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters) :
    Type_MethodBase(srcInfo, typeParameters, parameters)
    { validate(); }
    Type_Action(const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters) :
    Type_MethodBase(typeParameters, parameters)
    { validate(); }
    Type_Action(Util::SourceInfo srcInfo, const IR::ParameterList* parameters) :
    Type_MethodBase(srcInfo, parameters)
    { validate(); }
    Type_Action(const IR::ParameterList* parameters) :
    Type_MethodBase(parameters)
    { validate(); }
    IRNODE_SUBCLASS(Type_Action)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Action, NodeKind::Type_Action, Type_MethodBase);
};
}  // namespace P4::IR
namespace P4::IR {
class Method : public Declaration, public virtual IAnnotated, public virtual IFunctional, public virtual ISimpleNamespace {
 public:
    const IR::Type_Method* type = nullptr;
    bool isAbstract = false;
    IR::Vector<IR::Annotation> annotations;
#line 844 "/root/p4c/ir/type.def"
    size_t maxParameterCount() const { return type->maxParameterCount(); }
#line 3600 "/root/p4c/build/ir/ir-generated.h"
#line 845 "/root/p4c/ir/type.def"
    size_t minParameterCount() const { return type->minParameterCount(); }
#line 3603 "/root/p4c/build/ir/ir-generated.h"
#line 846 "/root/p4c/ir/type.def"
    void setAbstract() { isAbstract = true; }
#line 3606 "/root/p4c/build/ir/ir-generated.h"
#line 847 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 3609 "/root/p4c/build/ir/ir-generated.h"
#line 848 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 3612 "/root/p4c/build/ir/ir-generated.h"
#line 849 "/root/p4c/ir/type.def"
    const IR::ParameterList *getParameters() const override;
#line 3615 "/root/p4c/build/ir/ir-generated.h"

#line 851 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 3619 "/root/p4c/build/ir/ir-generated.h"
#line 853 "/root/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 3622 "/root/p4c/build/ir/ir-generated.h"
#line 855 "/root/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 3625 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Method const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Method"_cs; }
    static cstring static_type_name() { return "Method"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Method(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, bool isAbstract, IR::Vector<IR::Annotation> annotations) :
    Declaration(srcInfo, name), type(type), isAbstract(isAbstract), annotations(annotations)
    { validate(); }
    Method(IR::ID name, const IR::Type_Method* type, bool isAbstract, IR::Vector<IR::Annotation> annotations) :
    Declaration(name), type(type), isAbstract(isAbstract), annotations(annotations)
    { validate(); }
    Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, IR::Vector<IR::Annotation> annotations) :
    Declaration(srcInfo, name), type(type), annotations(annotations)
    { validate(); }
    Method(IR::ID name, const IR::Type_Method* type, IR::Vector<IR::Annotation> annotations) :
    Declaration(name), type(type), annotations(annotations)
    { validate(); }
    Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, bool isAbstract) :
    Declaration(srcInfo, name), type(type), isAbstract(isAbstract)
    { validate(); }
    Method(IR::ID name, const IR::Type_Method* type, bool isAbstract) :
    Declaration(name), type(type), isAbstract(isAbstract)
    { validate(); }
    Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type) :
    Declaration(srcInfo, name), type(type)
    { validate(); }
    Method(IR::ID name, const IR::Type_Method* type) :
    Declaration(name), type(type)
    { validate(); }
    IRNODE_SUBCLASS(Method)
    DECLARE_TYPEINFO_WITH_TYPEID(Method, NodeKind::Method, Declaration, IAnnotated, IFunctional, ISimpleNamespace);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Typedef : public Type_Declaration, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::Type* type = nullptr;
#line 862 "/root/p4c/ir/type.def"
    int width_bits() const override;
#line 3676 "/root/p4c/build/ir/ir-generated.h"
#line 863 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 3679 "/root/p4c/build/ir/ir-generated.h"
#line 864 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 3682 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Typedef const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Typedef"_cs; }
    static cstring static_type_name() { return "Type_Typedef"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Typedef(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Typedef(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type) :
    Type_Declaration(srcInfo, name), annotations(annotations), type(type)
    { validate(); }
    Type_Typedef(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type) :
    Type_Declaration(name), annotations(annotations), type(type)
    { validate(); }
    Type_Typedef(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type) :
    Type_Declaration(srcInfo, name), type(type)
    { validate(); }
    Type_Typedef(IR::ID name, const IR::Type* type) :
    Type_Declaration(name), type(type)
    { validate(); }
    IRNODE_SUBCLASS(Type_Typedef)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Typedef, NodeKind::Type_Typedef, Type_Declaration, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
/// A newtype is similar to typedef, but it introduces a new type; the
/// the new type does not inherit any
/// of the operations of the original type.  The new type has
/// assignment, equality, and casts to/from the original type.
/// The keyword for newtype is actually `type'.
class Type_Newtype : public Type_Declaration, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::Type* type = nullptr;
#line 876 "/root/p4c/ir/type.def"
    int width_bits() const override;
#line 3724 "/root/p4c/build/ir/ir-generated.h"
#line 877 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 3727 "/root/p4c/build/ir/ir-generated.h"
#line 878 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 3730 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Newtype const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Newtype"_cs; }
    static cstring static_type_name() { return "Type_Newtype"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Newtype(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Newtype(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type) :
    Type_Declaration(srcInfo, name), annotations(annotations), type(type)
    { validate(); }
    Type_Newtype(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type) :
    Type_Declaration(name), annotations(annotations), type(type)
    { validate(); }
    Type_Newtype(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type) :
    Type_Declaration(srcInfo, name), type(type)
    { validate(); }
    Type_Newtype(IR::ID name, const IR::Type* type) :
    Type_Declaration(name), type(type)
    { validate(); }
    IRNODE_SUBCLASS(Type_Newtype)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Newtype, NodeKind::Type_Newtype, Type_Declaration, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
/// An 'extern' black-box (not a function)
class Type_Extern : public Type_Declaration, public virtual INestedNamespace, public virtual IGeneralNamespace, public virtual IMayBeGenericType, public virtual IAnnotated {
 public:
    const IR::TypeParameters* typeParameters = new TypeParameters;
    IR::Vector<IR::Method> methods;

    IR::NameMap<IR::Attribute, ordered_map> attributes;

    IR::Vector<IR::Annotation> annotations;
#line 890 "/root/p4c/ir/type.def"
    std::vector<const IR::INamespace *> getNestedNamespaces() const override;
#line 3772 "/root/p4c/build/ir/ir-generated.h"
#line 891 "/root/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 3775 "/root/p4c/build/ir/ir-generated.h"
#line 894 "/root/p4c/ir/type.def"
    const IR::TypeParameters *getTypeParameters() const override;
#line 3778 "/root/p4c/build/ir/ir-generated.h"
#line 895 "/root/p4c/ir/type.def"
    void validate() const override;
#line 3781 "/root/p4c/build/ir/ir-generated.h"
#line 896 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 3784 "/root/p4c/build/ir/ir-generated.h"
#line 897 "/root/p4c/ir/type.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 3787 "/root/p4c/build/ir/ir-generated.h"
/// Returns the method that matches the specified arguments.
/// Returns nullptr if no method or more than one method match.
/// In the latter case it also reports an error.
#line 901 "/root/p4c/ir/type.def"
    const IR::Method *lookupMethod(IR::ID name, const IR::Vector<IR::Argument>* arguments) const;
#line 3793 "/root/p4c/build/ir/ir-generated.h"
/// Returns the constructor that matches the specified arguments.
/// Returns nullptr if no constructor or more than one constructor matches.
/// In the latter case it also reports an error.
#line 905 "/root/p4c/ir/type.def"
    const IR::Method *lookupConstructor(const IR::Vector<IR::Argument>* arguments) const;
#line 3799 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Extern const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Type_Extern"_cs; }
    static cstring static_type_name() { return "Type_Extern"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Extern(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), methods(methods), attributes(attributes), annotations(annotations)
    { validate(); }
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(name), typeParameters(typeParameters), methods(methods), attributes(attributes), annotations(annotations)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(srcInfo, name), methods(methods), attributes(attributes), annotations(annotations)
    { validate(); }
    Type_Extern(IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(name), methods(methods), attributes(attributes), annotations(annotations)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), attributes(attributes), annotations(annotations)
    { validate(); }
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(name), typeParameters(typeParameters), attributes(attributes), annotations(annotations)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(srcInfo, name), attributes(attributes), annotations(annotations)
    { validate(); }
    Type_Extern(IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(name), attributes(attributes), annotations(annotations)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), methods(methods), annotations(annotations)
    { validate(); }
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(name), typeParameters(typeParameters), methods(methods), annotations(annotations)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(srcInfo, name), methods(methods), annotations(annotations)
    { validate(); }
    Type_Extern(IR::ID name, IR::Vector<IR::Method> methods, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(name), methods(methods), annotations(annotations)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), annotations(annotations)
    { validate(); }
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(name), typeParameters(typeParameters), annotations(annotations)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(srcInfo, name), annotations(annotations)
    { validate(); }
    Type_Extern(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_Declaration(name), annotations(annotations)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), methods(methods), attributes(attributes)
    { validate(); }
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(name), typeParameters(typeParameters), methods(methods), attributes(attributes)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(srcInfo, name), methods(methods), attributes(attributes)
    { validate(); }
    Type_Extern(IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(name), methods(methods), attributes(attributes)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), attributes(attributes)
    { validate(); }
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(name), typeParameters(typeParameters), attributes(attributes)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(srcInfo, name), attributes(attributes)
    { validate(); }
    Type_Extern(IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(name), attributes(attributes)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), methods(methods)
    { validate(); }
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods) :
    Type_Declaration(name), typeParameters(typeParameters), methods(methods)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods) :
    Type_Declaration(srcInfo, name), methods(methods)
    { validate(); }
    Type_Extern(IR::ID name, IR::Vector<IR::Method> methods) :
    Type_Declaration(name), methods(methods)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters)
    { validate(); }
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), typeParameters(typeParameters)
    { validate(); }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
    Type_Extern(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
    IRNODE_SUBCLASS(Type_Extern)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Extern, NodeKind::Type_Extern, Type_Declaration, INestedNamespace, IGeneralNamespace, IMayBeGenericType, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
/** @} */
/* end group irdefs */
/* -*-C++-*- */
/* This file contains the IR classes for all expressions.
   The base classes are in base.def */
/** \addtogroup irdefs
  * @{
  */
class Operation_Unary : public Operation {
 public:
    const IR::Expression* expr = nullptr;
    int getPrecedence() const override { return DBPrint::Prec_Prefix; }
#line 15 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 3928 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Operation_Unary const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Operation_Unary"_cs; }
    static cstring static_type_name() { return "Operation_Unary"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Operation_Unary(JSONLoader & json);
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Operation_Unary(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation(srcInfo, type), expr(expr)
    {
#line 11 "/root/p4c/ir/expression.def"
{
        if (!srcInfo && expr) srcInfo = expr->srcInfo;
        if (type->is<Type::Unknown>() && expr) type = expr->type; }
#line 3949 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Operation_Unary(const IR::Type* type, const IR::Expression* expr) :
    Operation(type), expr(expr)
    {
#line 11 "/root/p4c/ir/expression.def"
{
        if (!srcInfo && expr) srcInfo = expr->srcInfo;
        if (type->is<Type::Unknown>() && expr) type = expr->type; }
#line 3958 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Operation_Unary(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation(srcInfo), expr(expr)
    {
#line 11 "/root/p4c/ir/expression.def"
{
        if (!srcInfo && expr) srcInfo = expr->srcInfo;
        if (type->is<Type::Unknown>() && expr) type = expr->type; }
#line 3967 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Operation_Unary(const IR::Expression* expr) :
    expr(expr)
    {
#line 11 "/root/p4c/ir/expression.def"
{
        if (!srcInfo && expr) srcInfo = expr->srcInfo;
        if (type->is<Type::Unknown>() && expr) type = expr->type; }
#line 3976 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Operation_Unary)
    DECLARE_TYPEINFO_WITH_TYPEID(Operation_Unary, NodeKind::Operation_Unary, Operation);
};
}  // namespace P4::IR
namespace P4::IR {
class Neg : public Operation_Unary {
 public:
    cstring getStringOp() const override { return cstring("-"); }
    bool operator==(IR::Neg const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Neg"_cs; }
    static cstring static_type_name() { return "Neg"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Neg(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Unary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Neg(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(srcInfo, type, expr)
    { validate(); }
    Neg(const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(type, expr)
    { validate(); }
    Neg(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation_Unary(srcInfo, expr)
    { validate(); }
    Neg(const IR::Expression* expr) :
    Operation_Unary(expr)
    { validate(); }
    IRNODE_SUBCLASS(Neg)
    DECLARE_TYPEINFO_WITH_TYPEID(Neg, NodeKind::Neg, Operation_Unary);
};
}  // namespace P4::IR
namespace P4::IR {
class UPlus : public Operation_Unary {
 public:
    cstring getStringOp() const override { return cstring("+"); }
    bool operator==(IR::UPlus const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "UPlus"_cs; }
    static cstring static_type_name() { return "UPlus"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    UPlus(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Unary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    UPlus(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(srcInfo, type, expr)
    { validate(); }
    UPlus(const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(type, expr)
    { validate(); }
    UPlus(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation_Unary(srcInfo, expr)
    { validate(); }
    UPlus(const IR::Expression* expr) :
    Operation_Unary(expr)
    { validate(); }
    IRNODE_SUBCLASS(UPlus)
    DECLARE_TYPEINFO_WITH_TYPEID(UPlus, NodeKind::UPlus, Operation_Unary);
};
}  // namespace P4::IR
namespace P4::IR {
class Cmpl : public Operation_Unary {
 public:
    cstring getStringOp() const override { return cstring("~"); }
    bool operator==(IR::Cmpl const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Cmpl"_cs; }
    static cstring static_type_name() { return "Cmpl"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Cmpl(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Unary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Cmpl(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(srcInfo, type, expr)
    { validate(); }
    Cmpl(const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(type, expr)
    { validate(); }
    Cmpl(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation_Unary(srcInfo, expr)
    { validate(); }
    Cmpl(const IR::Expression* expr) :
    Operation_Unary(expr)
    { validate(); }
    IRNODE_SUBCLASS(Cmpl)
    DECLARE_TYPEINFO_WITH_TYPEID(Cmpl, NodeKind::Cmpl, Operation_Unary);
};
}  // namespace P4::IR
namespace P4::IR {
class LNot : public Operation_Unary {
 public:
    cstring getStringOp() const override { return cstring("!"); }
    bool operator==(IR::LNot const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "LNot"_cs; }
    static cstring static_type_name() { return "LNot"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    LNot(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Unary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    LNot(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(srcInfo, type, expr)
    {
#line 32 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 4104 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    LNot(const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(type, expr)
    {
#line 32 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 4116 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    LNot(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation_Unary(srcInfo, expr)
    {
#line 32 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 4128 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    LNot(const IR::Expression* expr) :
    Operation_Unary(expr)
    {
#line 32 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 4140 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(LNot)
    DECLARE_TYPEINFO_WITH_TYPEID(LNot, NodeKind::LNot, Operation_Unary);
};
}  // namespace P4::IR
namespace P4::IR {
class Operation_Binary : public Operation {
 public:
    const IR::Expression* left = nullptr;
    const IR::Expression* right = nullptr;
#line 47 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 4153 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Operation_Binary const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Operation_Binary"_cs; }
    static cstring static_type_name() { return "Operation_Binary"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Operation_Binary(JSONLoader & json);
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Operation_Binary(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation(srcInfo, type), left(left), right(right)
    {
#line 43 "/root/p4c/ir/expression.def"
{
        if (!srcInfo && left && right) srcInfo = left->srcInfo + right->srcInfo;
        if (type->is<Type::Unknown>() && left && right && left->type == right->type)
            type = left->type; }
#line 4175 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Operation_Binary(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation(type), left(left), right(right)
    {
#line 43 "/root/p4c/ir/expression.def"
{
        if (!srcInfo && left && right) srcInfo = left->srcInfo + right->srcInfo;
        if (type->is<Type::Unknown>() && left && right && left->type == right->type)
            type = left->type; }
#line 4185 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Operation_Binary(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation(srcInfo), left(left), right(right)
    {
#line 43 "/root/p4c/ir/expression.def"
{
        if (!srcInfo && left && right) srcInfo = left->srcInfo + right->srcInfo;
        if (type->is<Type::Unknown>() && left && right && left->type == right->type)
            type = left->type; }
#line 4195 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Operation_Binary(const IR::Expression* left, const IR::Expression* right) :
    left(left), right(right)
    {
#line 43 "/root/p4c/ir/expression.def"
{
        if (!srcInfo && left && right) srcInfo = left->srcInfo + right->srcInfo;
        if (type->is<Type::Unknown>() && left && right && left->type == right->type)
            type = left->type; }
#line 4205 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Operation_Binary)
    DECLARE_TYPEINFO_WITH_TYPEID(Operation_Binary, NodeKind::Operation_Binary, Operation);
};
}  // namespace P4::IR
namespace P4::IR {
class Operation_Ternary : public Operation {
 public:
    const IR::Expression* e0 = nullptr;
    const IR::Expression* e1 = nullptr;
    const IR::Expression* e2 = nullptr;
    bool operator==(IR::Operation_Ternary const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Operation_Ternary"_cs; }
    static cstring static_type_name() { return "Operation_Ternary"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Operation_Ternary(JSONLoader & json);
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Operation_Ternary(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation(srcInfo, type), e0(e0), e1(e1), e2(e2)
    {
#line 60 "/root/p4c/ir/expression.def"
{ if (!srcInfo && e0 && e2) srcInfo = e0->srcInfo + e2->srcInfo; }
#line 4235 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Operation_Ternary(const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation(type), e0(e0), e1(e1), e2(e2)
    {
#line 60 "/root/p4c/ir/expression.def"
{ if (!srcInfo && e0 && e2) srcInfo = e0->srcInfo + e2->srcInfo; }
#line 4242 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Operation_Ternary(Util::SourceInfo srcInfo, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation(srcInfo), e0(e0), e1(e1), e2(e2)
    {
#line 60 "/root/p4c/ir/expression.def"
{ if (!srcInfo && e0 && e2) srcInfo = e0->srcInfo + e2->srcInfo; }
#line 4249 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Operation_Ternary(const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    e0(e0), e1(e1), e2(e2)
    {
#line 60 "/root/p4c/ir/expression.def"
{ if (!srcInfo && e0 && e2) srcInfo = e0->srcInfo + e2->srcInfo; }
#line 4256 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Operation_Ternary)
    DECLARE_TYPEINFO_WITH_TYPEID(Operation_Ternary, NodeKind::Operation_Ternary, Operation);
};
}  // namespace P4::IR
namespace P4::IR {
class Operation_Relation : public Operation_Binary {
 public:
    bool operator==(IR::Operation_Relation const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Operation_Relation"_cs; }
    static cstring static_type_name() { return "Operation_Relation"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Operation_Relation(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Operation_Relation(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 64 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 4286 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Operation_Relation(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 64 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 4298 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Operation_Relation(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 64 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 4310 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Operation_Relation(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 64 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 4322 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Operation_Relation)
    DECLARE_TYPEINFO_WITH_TYPEID(Operation_Relation, NodeKind::Operation_Relation, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class Mul : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("*"); }
    int getPrecedence() const override { return DBPrint::Prec_Mul; }
    bool operator==(IR::Mul const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Mul"_cs; }
    static cstring static_type_name() { return "Mul"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Mul(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Mul(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
    Mul(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
    Mul(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
    Mul(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
    IRNODE_SUBCLASS(Mul)
    DECLARE_TYPEINFO_WITH_TYPEID(Mul, NodeKind::Mul, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
///////////////////////////// Statements //////////////////////////
class Statement : public StatOrDecl {
 public:
    IRNODE_DECLARE_APPLY_OVERLOAD(Statement)
    bool operator==(IR::Statement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Statement"_cs; }
    static cstring static_type_name() { return "Statement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Statement(JSONLoader & json);
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Statement(Util::SourceInfo srcInfo) :
    StatOrDecl(srcInfo)
    { validate(); }
    Statement() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Statement)
    DECLARE_TYPEINFO_WITH_TYPEID(Statement, NodeKind::Statement, StatOrDecl);
};
}  // namespace P4::IR
namespace P4::IR {
class BaseAssignmentStatement : public Statement {
 public:
    const IR::Expression* left = nullptr;
    const IR::Expression* right = nullptr;
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "BaseAssignmentStatement"_cs; }
    static cstring static_type_name() { return "BaseAssignmentStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    BaseAssignmentStatement(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    BaseAssignmentStatement(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Statement(srcInfo), left(left), right(right)
    { validate(); }
    BaseAssignmentStatement(const IR::Expression* left, const IR::Expression* right) :
    left(left), right(right)
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(BaseAssignmentStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(BaseAssignmentStatement, NodeKind::BaseAssignmentStatement, Statement);
};
}  // namespace P4::IR
namespace P4::IR {
class OpAssignmentStatement : public BaseAssignmentStatement {
 public:
#line 481 "/root/p4c/ir/ir.def"
    virtual cstring getStringOp() const = 0;
#line 4417 "/root/p4c/build/ir/ir-generated.h"
#line 482 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 4420 "/root/p4c/build/ir/ir-generated.h"
#line 483 "/root/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 4423 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::OpAssignmentStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "OpAssignmentStatement"_cs; }
    static cstring static_type_name() { return "OpAssignmentStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    OpAssignmentStatement(JSONLoader & json);
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    OpAssignmentStatement(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    BaseAssignmentStatement(srcInfo, left, right)
    { validate(); }
    OpAssignmentStatement(const IR::Expression* left, const IR::Expression* right) :
    BaseAssignmentStatement(left, right)
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(OpAssignmentStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(OpAssignmentStatement, NodeKind::OpAssignmentStatement, BaseAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class MulAssign : public OpAssignmentStatement {
 public:
#line 78 "/root/p4c/ir/expression.def"
    typedef Mul BinOp;
#line 4450 "/root/p4c/build/ir/ir-generated.h"
    cstring getStringOp() const override { return cstring("*"); }
    bool operator==(IR::MulAssign const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "MulAssign"_cs; }
    static cstring static_type_name() { return "MulAssign"_cs; }
    void toJSON(JSONGenerator & json) const override;
    MulAssign(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::OpAssignmentStatement const & a) const override;
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    MulAssign(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(srcInfo, left, right)
    { validate(); }
    MulAssign(const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(left, right)
    { validate(); }
    IRNODE_SUBCLASS(MulAssign)
    DECLARE_TYPEINFO_WITH_TYPEID(MulAssign, NodeKind::MulAssign, OpAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class Div : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("/"); }
    int getPrecedence() const override { return DBPrint::Prec_Div; }
    bool operator==(IR::Div const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Div"_cs; }
    static cstring static_type_name() { return "Div"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Div(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Div(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
    Div(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
    Div(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
    Div(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
    IRNODE_SUBCLASS(Div)
    DECLARE_TYPEINFO_WITH_TYPEID(Div, NodeKind::Div, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class DivAssign : public OpAssignmentStatement {
 public:
#line 90 "/root/p4c/ir/expression.def"
    typedef Div BinOp;
#line 4512 "/root/p4c/build/ir/ir-generated.h"
    cstring getStringOp() const override { return cstring("/"); }
    bool operator==(IR::DivAssign const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DivAssign"_cs; }
    static cstring static_type_name() { return "DivAssign"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DivAssign(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::OpAssignmentStatement const & a) const override;
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DivAssign(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(srcInfo, left, right)
    { validate(); }
    DivAssign(const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(left, right)
    { validate(); }
    IRNODE_SUBCLASS(DivAssign)
    DECLARE_TYPEINFO_WITH_TYPEID(DivAssign, NodeKind::DivAssign, OpAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class Mod : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("%"); }
    int getPrecedence() const override { return DBPrint::Prec_Mod; }
    bool operator==(IR::Mod const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Mod"_cs; }
    static cstring static_type_name() { return "Mod"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Mod(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Mod(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
    Mod(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
    Mod(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
    Mod(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
    IRNODE_SUBCLASS(Mod)
    DECLARE_TYPEINFO_WITH_TYPEID(Mod, NodeKind::Mod, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class ModAssign : public OpAssignmentStatement {
 public:
#line 101 "/root/p4c/ir/expression.def"
    typedef Mod BinOp;
#line 4574 "/root/p4c/build/ir/ir-generated.h"
    cstring getStringOp() const override { return cstring("%"); }
    bool operator==(IR::ModAssign const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ModAssign"_cs; }
    static cstring static_type_name() { return "ModAssign"_cs; }
    void toJSON(JSONGenerator & json) const override;
    ModAssign(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::OpAssignmentStatement const & a) const override;
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ModAssign(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(srcInfo, left, right)
    { validate(); }
    ModAssign(const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(left, right)
    { validate(); }
    IRNODE_SUBCLASS(ModAssign)
    DECLARE_TYPEINFO_WITH_TYPEID(ModAssign, NodeKind::ModAssign, OpAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class Add : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("+"); }
    int getPrecedence() const override { return DBPrint::Prec_Add; }
    bool operator==(IR::Add const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Add"_cs; }
    static cstring static_type_name() { return "Add"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Add(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Add(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
    Add(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
    Add(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
    Add(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
    IRNODE_SUBCLASS(Add)
    DECLARE_TYPEINFO_WITH_TYPEID(Add, NodeKind::Add, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class AddAssign : public OpAssignmentStatement {
 public:
#line 112 "/root/p4c/ir/expression.def"
    typedef Add BinOp;
#line 4636 "/root/p4c/build/ir/ir-generated.h"
    cstring getStringOp() const override { return cstring("+"); }
    bool operator==(IR::AddAssign const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "AddAssign"_cs; }
    static cstring static_type_name() { return "AddAssign"_cs; }
    void toJSON(JSONGenerator & json) const override;
    AddAssign(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::OpAssignmentStatement const & a) const override;
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    AddAssign(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(srcInfo, left, right)
    { validate(); }
    AddAssign(const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(left, right)
    { validate(); }
    IRNODE_SUBCLASS(AddAssign)
    DECLARE_TYPEINFO_WITH_TYPEID(AddAssign, NodeKind::AddAssign, OpAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class Sub : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("-"); }
    int getPrecedence() const override { return DBPrint::Prec_Sub; }
    bool operator==(IR::Sub const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Sub"_cs; }
    static cstring static_type_name() { return "Sub"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Sub(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Sub(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
    Sub(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
    Sub(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
    Sub(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
    IRNODE_SUBCLASS(Sub)
    DECLARE_TYPEINFO_WITH_TYPEID(Sub, NodeKind::Sub, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class SubAssign : public OpAssignmentStatement {
 public:
#line 123 "/root/p4c/ir/expression.def"
    typedef Sub BinOp;
#line 4698 "/root/p4c/build/ir/ir-generated.h"
    cstring getStringOp() const override { return cstring("-"); }
    bool operator==(IR::SubAssign const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "SubAssign"_cs; }
    static cstring static_type_name() { return "SubAssign"_cs; }
    void toJSON(JSONGenerator & json) const override;
    SubAssign(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::OpAssignmentStatement const & a) const override;
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    SubAssign(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(srcInfo, left, right)
    { validate(); }
    SubAssign(const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(left, right)
    { validate(); }
    IRNODE_SUBCLASS(SubAssign)
    DECLARE_TYPEINFO_WITH_TYPEID(SubAssign, NodeKind::SubAssign, OpAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class AddSat : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("|+|"); }
    int getPrecedence() const override { return DBPrint::Prec_AddSat; }
    bool operator==(IR::AddSat const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "AddSat"_cs; }
    static cstring static_type_name() { return "AddSat"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    AddSat(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    AddSat(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
    AddSat(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
    AddSat(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
    AddSat(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
    IRNODE_SUBCLASS(AddSat)
    DECLARE_TYPEINFO_WITH_TYPEID(AddSat, NodeKind::AddSat, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class AddSatAssign : public OpAssignmentStatement {
 public:
#line 134 "/root/p4c/ir/expression.def"
    typedef AddSat BinOp;
#line 4760 "/root/p4c/build/ir/ir-generated.h"
    cstring getStringOp() const override { return cstring("|+|"); }
    bool operator==(IR::AddSatAssign const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "AddSatAssign"_cs; }
    static cstring static_type_name() { return "AddSatAssign"_cs; }
    void toJSON(JSONGenerator & json) const override;
    AddSatAssign(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::OpAssignmentStatement const & a) const override;
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    AddSatAssign(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(srcInfo, left, right)
    { validate(); }
    AddSatAssign(const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(left, right)
    { validate(); }
    IRNODE_SUBCLASS(AddSatAssign)
    DECLARE_TYPEINFO_WITH_TYPEID(AddSatAssign, NodeKind::AddSatAssign, OpAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class SubSat : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("|-|"); }
    int getPrecedence() const override { return DBPrint::Prec_SubSat; }
    bool operator==(IR::SubSat const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "SubSat"_cs; }
    static cstring static_type_name() { return "SubSat"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    SubSat(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    SubSat(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
    SubSat(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
    SubSat(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
    SubSat(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
    IRNODE_SUBCLASS(SubSat)
    DECLARE_TYPEINFO_WITH_TYPEID(SubSat, NodeKind::SubSat, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class SubSatAssign : public OpAssignmentStatement {
 public:
#line 145 "/root/p4c/ir/expression.def"
    typedef SubSat BinOp;
#line 4822 "/root/p4c/build/ir/ir-generated.h"
    cstring getStringOp() const override { return cstring("|-|"); }
    bool operator==(IR::SubSatAssign const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "SubSatAssign"_cs; }
    static cstring static_type_name() { return "SubSatAssign"_cs; }
    void toJSON(JSONGenerator & json) const override;
    SubSatAssign(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::OpAssignmentStatement const & a) const override;
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    SubSatAssign(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(srcInfo, left, right)
    { validate(); }
    SubSatAssign(const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(left, right)
    { validate(); }
    IRNODE_SUBCLASS(SubSatAssign)
    DECLARE_TYPEINFO_WITH_TYPEID(SubSatAssign, NodeKind::SubSatAssign, OpAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class Shl : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("<<"); }
    int getPrecedence() const override { return DBPrint::Prec_Shl; }
    bool operator==(IR::Shl const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Shl"_cs; }
    static cstring static_type_name() { return "Shl"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Shl(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Shl(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 153 "/root/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4868 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Shl(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 153 "/root/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4875 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Shl(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 153 "/root/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4882 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Shl(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 153 "/root/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4889 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(Shl)
    DECLARE_TYPEINFO_WITH_TYPEID(Shl, NodeKind::Shl, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class ShlAssign : public OpAssignmentStatement {
 public:
#line 157 "/root/p4c/ir/expression.def"
    typedef Shl BinOp;
#line 4900 "/root/p4c/build/ir/ir-generated.h"
    cstring getStringOp() const override { return cstring("<<"); }
    bool operator==(IR::ShlAssign const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ShlAssign"_cs; }
    static cstring static_type_name() { return "ShlAssign"_cs; }
    void toJSON(JSONGenerator & json) const override;
    ShlAssign(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::OpAssignmentStatement const & a) const override;
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ShlAssign(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(srcInfo, left, right)
    { validate(); }
    ShlAssign(const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(left, right)
    { validate(); }
    IRNODE_SUBCLASS(ShlAssign)
    DECLARE_TYPEINFO_WITH_TYPEID(ShlAssign, NodeKind::ShlAssign, OpAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class Shr : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring(">>"); }
    int getPrecedence() const override { return DBPrint::Prec_Shr; }
    bool operator==(IR::Shr const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Shr"_cs; }
    static cstring static_type_name() { return "Shr"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Shr(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Shr(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 165 "/root/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4946 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Shr(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 165 "/root/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4953 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Shr(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 165 "/root/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4960 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Shr(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 165 "/root/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4967 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(Shr)
    DECLARE_TYPEINFO_WITH_TYPEID(Shr, NodeKind::Shr, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class ShrAssign : public OpAssignmentStatement {
 public:
#line 169 "/root/p4c/ir/expression.def"
    typedef Shr BinOp;
#line 4978 "/root/p4c/build/ir/ir-generated.h"
    cstring getStringOp() const override { return cstring(">>"); }
    bool operator==(IR::ShrAssign const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ShrAssign"_cs; }
    static cstring static_type_name() { return "ShrAssign"_cs; }
    void toJSON(JSONGenerator & json) const override;
    ShrAssign(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::OpAssignmentStatement const & a) const override;
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ShrAssign(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(srcInfo, left, right)
    { validate(); }
    ShrAssign(const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(left, right)
    { validate(); }
    IRNODE_SUBCLASS(ShrAssign)
    DECLARE_TYPEINFO_WITH_TYPEID(ShrAssign, NodeKind::ShrAssign, OpAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class Equ : public Operation_Relation {
 public:
    cstring getStringOp() const override { return cstring("=="); }
    int getPrecedence() const override { return DBPrint::Prec_Equ; }
    bool operator==(IR::Equ const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Equ"_cs; }
    static cstring static_type_name() { return "Equ"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Equ(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Relation const & a) const override;
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Equ(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
    Equ(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
    Equ(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
    Equ(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
    IRNODE_SUBCLASS(Equ)
    DECLARE_TYPEINFO_WITH_TYPEID(Equ, NodeKind::Equ, Operation_Relation);
};
}  // namespace P4::IR
namespace P4::IR {
class Neq : public Operation_Relation {
 public:
    cstring getStringOp() const override { return cstring("!="); }
    int getPrecedence() const override { return DBPrint::Prec_Neq; }
    bool operator==(IR::Neq const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Neq"_cs; }
    static cstring static_type_name() { return "Neq"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Neq(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Relation const & a) const override;
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Neq(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
    Neq(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
    Neq(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
    Neq(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
    IRNODE_SUBCLASS(Neq)
    DECLARE_TYPEINFO_WITH_TYPEID(Neq, NodeKind::Neq, Operation_Relation);
};
}  // namespace P4::IR
namespace P4::IR {
class Lss : public Operation_Relation {
 public:
    cstring getStringOp() const override { return cstring("<"); }
    int getPrecedence() const override { return DBPrint::Prec_Lss; }
    bool operator==(IR::Lss const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Lss"_cs; }
    static cstring static_type_name() { return "Lss"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Lss(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Relation const & a) const override;
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Lss(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
    Lss(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
    Lss(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
    Lss(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
    IRNODE_SUBCLASS(Lss)
    DECLARE_TYPEINFO_WITH_TYPEID(Lss, NodeKind::Lss, Operation_Relation);
};
}  // namespace P4::IR
namespace P4::IR {
class Leq : public Operation_Relation {
 public:
    cstring getStringOp() const override { return cstring("<="); }
    int getPrecedence() const override { return DBPrint::Prec_Leq; }
    bool operator==(IR::Leq const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Leq"_cs; }
    static cstring static_type_name() { return "Leq"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Leq(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Relation const & a) const override;
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Leq(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
    Leq(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
    Leq(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
    Leq(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
    IRNODE_SUBCLASS(Leq)
    DECLARE_TYPEINFO_WITH_TYPEID(Leq, NodeKind::Leq, Operation_Relation);
};
}  // namespace P4::IR
namespace P4::IR {
class Grt : public Operation_Relation {
 public:
    cstring getStringOp() const override { return cstring(">"); }
    int getPrecedence() const override { return DBPrint::Prec_Grt; }
    bool operator==(IR::Grt const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Grt"_cs; }
    static cstring static_type_name() { return "Grt"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Grt(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Relation const & a) const override;
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Grt(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
    Grt(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
    Grt(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
    Grt(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
    IRNODE_SUBCLASS(Grt)
    DECLARE_TYPEINFO_WITH_TYPEID(Grt, NodeKind::Grt, Operation_Relation);
};
}  // namespace P4::IR
namespace P4::IR {
class Geq : public Operation_Relation {
 public:
    cstring getStringOp() const override { return cstring(">="); }
    int getPrecedence() const override { return DBPrint::Prec_Geq; }
    bool operator==(IR::Geq const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Geq"_cs; }
    static cstring static_type_name() { return "Geq"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Geq(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Relation const & a) const override;
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Geq(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
    Geq(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
    Geq(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
    Geq(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
    IRNODE_SUBCLASS(Geq)
    DECLARE_TYPEINFO_WITH_TYPEID(Geq, NodeKind::Geq, Operation_Relation);
};
}  // namespace P4::IR
namespace P4::IR {
class BAnd : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("&"); }
    int getPrecedence() const override { return DBPrint::Prec_BAnd; }
    bool operator==(IR::BAnd const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "BAnd"_cs; }
    static cstring static_type_name() { return "BAnd"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    BAnd(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    BAnd(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
    BAnd(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
    BAnd(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
    BAnd(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
    IRNODE_SUBCLASS(BAnd)
    DECLARE_TYPEINFO_WITH_TYPEID(BAnd, NodeKind::BAnd, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class BAndAssign : public OpAssignmentStatement {
 public:
#line 204 "/root/p4c/ir/expression.def"
    typedef BAnd BinOp;
#line 5244 "/root/p4c/build/ir/ir-generated.h"
    cstring getStringOp() const override { return cstring("&"); }
    bool operator==(IR::BAndAssign const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "BAndAssign"_cs; }
    static cstring static_type_name() { return "BAndAssign"_cs; }
    void toJSON(JSONGenerator & json) const override;
    BAndAssign(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::OpAssignmentStatement const & a) const override;
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    BAndAssign(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(srcInfo, left, right)
    { validate(); }
    BAndAssign(const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(left, right)
    { validate(); }
    IRNODE_SUBCLASS(BAndAssign)
    DECLARE_TYPEINFO_WITH_TYPEID(BAndAssign, NodeKind::BAndAssign, OpAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class BOr : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("|"); }
    int getPrecedence() const override { return DBPrint::Prec_BOr; }
    bool operator==(IR::BOr const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "BOr"_cs; }
    static cstring static_type_name() { return "BOr"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    BOr(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    BOr(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
    BOr(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
    BOr(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
    BOr(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
    IRNODE_SUBCLASS(BOr)
    DECLARE_TYPEINFO_WITH_TYPEID(BOr, NodeKind::BOr, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class BOrAssign : public OpAssignmentStatement {
 public:
#line 215 "/root/p4c/ir/expression.def"
    typedef BOr BinOp;
#line 5306 "/root/p4c/build/ir/ir-generated.h"
    cstring getStringOp() const override { return cstring("|"); }
    bool operator==(IR::BOrAssign const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "BOrAssign"_cs; }
    static cstring static_type_name() { return "BOrAssign"_cs; }
    void toJSON(JSONGenerator & json) const override;
    BOrAssign(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::OpAssignmentStatement const & a) const override;
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    BOrAssign(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(srcInfo, left, right)
    { validate(); }
    BOrAssign(const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(left, right)
    { validate(); }
    IRNODE_SUBCLASS(BOrAssign)
    DECLARE_TYPEINFO_WITH_TYPEID(BOrAssign, NodeKind::BOrAssign, OpAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class BXor : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("^"); }
    int getPrecedence() const override { return DBPrint::Prec_BXor; }
    bool operator==(IR::BXor const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "BXor"_cs; }
    static cstring static_type_name() { return "BXor"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    BXor(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    BXor(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
    BXor(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
    BXor(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
    BXor(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
    IRNODE_SUBCLASS(BXor)
    DECLARE_TYPEINFO_WITH_TYPEID(BXor, NodeKind::BXor, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class BXorAssign : public OpAssignmentStatement {
 public:
#line 226 "/root/p4c/ir/expression.def"
    typedef BXor BinOp;
#line 5368 "/root/p4c/build/ir/ir-generated.h"
    cstring getStringOp() const override { return cstring("^"); }
    bool operator==(IR::BXorAssign const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "BXorAssign"_cs; }
    static cstring static_type_name() { return "BXorAssign"_cs; }
    void toJSON(JSONGenerator & json) const override;
    BXorAssign(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::OpAssignmentStatement const & a) const override;
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    BXorAssign(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(srcInfo, left, right)
    { validate(); }
    BXorAssign(const IR::Expression* left, const IR::Expression* right) :
    OpAssignmentStatement(left, right)
    { validate(); }
    IRNODE_SUBCLASS(BXorAssign)
    DECLARE_TYPEINFO_WITH_TYPEID(BXorAssign, NodeKind::BXorAssign, OpAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class LAnd : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("&&"); }
    int getPrecedence() const override { return DBPrint::Prec_LAnd; }
    bool operator==(IR::LAnd const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "LAnd"_cs; }
    static cstring static_type_name() { return "LAnd"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    LAnd(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    LAnd(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 234 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 5419 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    LAnd(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 234 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 5431 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    LAnd(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 234 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 5443 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    LAnd(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 234 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 5455 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(LAnd)
    DECLARE_TYPEINFO_WITH_TYPEID(LAnd, NodeKind::LAnd, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class LOr : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("||"); }
    int getPrecedence() const override { return DBPrint::Prec_LOr; }
    bool operator==(IR::LOr const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "LOr"_cs; }
    static cstring static_type_name() { return "LOr"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    LOr(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    LOr(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 244 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 5488 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    LOr(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 244 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 5500 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    LOr(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 244 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 5512 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    LOr(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 244 "/root/p4c/ir/expression.def"
{
        // This sets the type only when no type is explicitly provided in the constructor.
        // If a type is provided in the constructor this assignment has no effect
        // because the type member is shadowed by the type parameter.
        type = Type::Boolean::get();
    }
#line 5524 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(LOr)
    DECLARE_TYPEINFO_WITH_TYPEID(LOr, NodeKind::LOr, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
/// Represents the ... default initializer expression
class Dots : public Expression {
 public:
#line 253 "/root/p4c/ir/expression.def"
    void dbprint(std::ostream & out) const override;
#line 5536 "/root/p4c/build/ir/ir-generated.h"
#line 254 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 5539 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Dots const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Dots"_cs; }
    static cstring static_type_name() { return "Dots"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Dots(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Dots(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
    Dots(const IR::Type* type) :
    Expression(type)
    { validate(); }
    Dots(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
    Dots() 
    { validate(); }
    IRNODE_SUBCLASS(Dots)
    DECLARE_TYPEINFO_WITH_TYPEID(Dots, NodeKind::Dots, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
/// Represents the ... default initializer expression
/// when used in a StructExpression.
class NamedDots : public NamedExpression {
 public:
#line 260 "/root/p4c/ir/expression.def"
    NamedDots() : NamedExpression("...", new Dots()) {}
#line 5571 "/root/p4c/build/ir/ir-generated.h"
#line 261 "/root/p4c/ir/expression.def"
    NamedDots(Util::SourceInfo srcInfo, const IR::Dots* dots) : NamedExpression(srcInfo, "..."_cs, dots) { CHECK_NULL(dots); }
#line 5574 "/root/p4c/build/ir/ir-generated.h"
#line 262 "/root/p4c/ir/expression.def"
    NamedDots(Util::SourceInfo srcInfo) : NamedExpression(srcInfo, "...", new Dots()) {}
#line 5577 "/root/p4c/build/ir/ir-generated.h"
#line 263 "/root/p4c/ir/expression.def"
    void dbprint(std::ostream & out) const override;
#line 5580 "/root/p4c/build/ir/ir-generated.h"
#line 264 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 5583 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::NamedDots const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "NamedDots"_cs; }
    static cstring static_type_name() { return "NamedDots"_cs; }
    void toJSON(JSONGenerator & json) const override;
    NamedDots(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::NamedExpression const & a) const override;
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    NamedDots(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* expression) :
    NamedExpression(srcInfo, name, expression)
    { validate(); }
    NamedDots(IR::ID name, const IR::Expression* expression) :
    NamedExpression(name, expression)
    { validate(); }
    IRNODE_SUBCLASS(NamedDots)
    DECLARE_TYPEINFO_WITH_TYPEID(NamedDots, NodeKind::NamedDots, NamedExpression);
};
}  // namespace P4::IR
namespace P4::IR {
class Literal : public Expression, public virtual CompileTimeValue {
 public:
    bool operator==(IR::Literal const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Literal"_cs; }
    static cstring static_type_name() { return "Literal"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Literal(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Literal(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
    Literal(const IR::Type* type) :
    Expression(type)
    { validate(); }
    Literal(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
    Literal() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Literal)
    DECLARE_TYPEINFO_WITH_TYPEID(Literal, NodeKind::Literal, Expression, CompileTimeValue);
};
}  // namespace P4::IR
namespace P4::IR {
/// This is an integer literal on arbitrary-precision.
class Constant : public Literal {
 public:
    big_int value;
    unsigned base;
/// base used when reading/writing
/// if noWarning is true, no warning is emitted
#line 275 "/root/p4c/ir/expression.def"
    void handleOverflow(bool noWarning);
#line 5642 "/root/p4c/build/ir/ir-generated.h"



#line 279 "/root/p4c/ir/expression.def"
    Constant(int v, unsigned base = 10) :
        Literal(Type_InfInt::get()), value(v), base(base) {}
#line 5649 "/root/p4c/build/ir/ir-generated.h"
#line 281 "/root/p4c/ir/expression.def"
    Constant(unsigned v, unsigned base = 10) :
        Literal(Type_InfInt::get()), value(v), base(base) {}
#line 5653 "/root/p4c/build/ir/ir-generated.h"
#line 284 "/root/p4c/ir/expression.def"
#if __WORDSIZE == 64
    Constant(intmax_t v, unsigned base = 10) :
        Literal(Type_InfInt::get()), value(v), base(base) {}
#else
    Constant(long v, unsigned base = 10) :
        Literal(Type_InfInt::get()), value(v), base(base) {}
    Constant(unsigned long v, unsigned base = 10) :
        Literal(Type_InfInt::get()), value(v), base(base) {}
    Constant(intmax_t v, unsigned base = 10) :
        Literal(Type_InfInt::get()), value(v), base(base) {}
#endif
#line 5666 "/root/p4c/build/ir/ir-generated.h"
#line 296 "/root/p4c/ir/expression.def"
    Constant(uint64_t v, unsigned base = 10) :
        Literal(Type_InfInt::get()), value(v), base(base) {}
#line 5670 "/root/p4c/build/ir/ir-generated.h"
#line 298 "/root/p4c/ir/expression.def"
    Constant(big_int v, unsigned base = 10) :
        Literal(Type_InfInt::get()), value(v), base(base) {}
#line 5674 "/root/p4c/build/ir/ir-generated.h"
#line 300 "/root/p4c/ir/expression.def"
    Constant(Util::SourceInfo si, big_int v, unsigned base = 10) :
        Literal(si, Type_InfInt::get()), value(v), base(base) {}
#line 5678 "/root/p4c/build/ir/ir-generated.h"
#line 302 "/root/p4c/ir/expression.def"
    Constant(IR::Type const * t, big_int v, unsigned base = 10, bool noWarning = false) :
        Literal(t), value(v), base(base) { CHECK_NULL(t); handleOverflow(noWarning); }
#line 5682 "/root/p4c/build/ir/ir-generated.h"
#line 304 "/root/p4c/ir/expression.def"
    Constant(Util::SourceInfo si, IR::Type const * t, big_int v, unsigned base = 10, bool noWarning = false) :
        Literal(si, t), value(v), base(base) { CHECK_NULL(t); handleOverflow(noWarning); }
#line 5686 "/root/p4c/build/ir/ir-generated.h"
#line 308 "/root/p4c/ir/expression.def"
    static Constant GetMask(unsigned width);
#line 5689 "/root/p4c/build/ir/ir-generated.h"
/// @return a constant. Any constant returned here is interned. Base is always 10.
#line 312 "/root/p4c/ir/expression.def"
    static IR::Constant const * get(IR::Type const * t, big_int v, Util::SourceInfo si = {});
#line 5693 "/root/p4c/build/ir/ir-generated.h"
#line 314 "/root/p4c/ir/expression.def"
    bool fitsInt() const { return value >= INT_MIN && value <= INT_MAX; }
#line 5696 "/root/p4c/build/ir/ir-generated.h"
#line 315 "/root/p4c/ir/expression.def"
    bool fitsLong() const { return value >= LONG_MIN && value <= LONG_MAX; }
#line 5699 "/root/p4c/build/ir/ir-generated.h"
#line 316 "/root/p4c/ir/expression.def"
    bool fitsUint() const { return value >= 0 && value <= UINT_MAX; }
#line 5702 "/root/p4c/build/ir/ir-generated.h"
#line 317 "/root/p4c/ir/expression.def"
    bool fitsUint64() const { return value >= 0 && value <= UINT64_MAX; }
#line 5705 "/root/p4c/build/ir/ir-generated.h"
#line 318 "/root/p4c/ir/expression.def"
    bool fitsInt64() const { return value >= INT64_MIN && value <= INT64_MAX; }
#line 5708 "/root/p4c/build/ir/ir-generated.h"
#line 319 "/root/p4c/ir/expression.def"
    long asLong() const {
        if (!fitsLong())
            ::P4::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for long", this);
        return static_cast<long>(value); }
#line 5714 "/root/p4c/build/ir/ir-generated.h"
#line 323 "/root/p4c/ir/expression.def"
    int asInt() const {
        if (!fitsInt())
            ::P4::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for int", this);
        return static_cast<int>(value); }
#line 5720 "/root/p4c/build/ir/ir-generated.h"
#line 327 "/root/p4c/ir/expression.def"
    unsigned asUnsigned() const {
        if (!fitsUint())
            ::P4::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for unsigned int", this);
        return static_cast<unsigned>(value);
    }
#line 5727 "/root/p4c/build/ir/ir-generated.h"
#line 332 "/root/p4c/ir/expression.def"
    uint64_t asUint64() const {
        if (!fitsUint64())
            ::P4::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for uint64", this);
        return static_cast<uint64_t>(value);
    }
#line 5734 "/root/p4c/build/ir/ir-generated.h"
#line 337 "/root/p4c/ir/expression.def"
    int64_t asInt64() const {
        if (!fitsInt64())
            ::P4::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for int64", this);
        return static_cast<int64_t>(value);
    }
#line 5741 "/root/p4c/build/ir/ir-generated.h"



#line 346 "/root/p4c/ir/expression.def"
    Constant operator<<(const unsigned &shift) const;
    Constant operator>>(const unsigned &shift) const;
    Constant operator&(const Constant &c) const;
    Constant operator|(const Constant &c) const;
    Constant operator^(const Constant &c) const;
    Constant operator-(const Constant &c) const;
    Constant operator-() const;
#line 5753 "/root/p4c/build/ir/ir-generated.h"
#line 354 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 5756 "/root/p4c/build/ir/ir-generated.h"
#line 366 "/root/p4c/ir/expression.def"
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
#line 5760 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Constant const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Constant"_cs; }
    static cstring static_type_name() { return "Constant"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Constant(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Literal const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(Constant)
    DECLARE_TYPEINFO_WITH_TYPEID(Constant, NodeKind::Constant, Literal);
};
}  // namespace P4::IR
namespace P4::IR {
class BoolLiteral : public Literal {
 public:
    bool value;
#line 371 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 5783 "/root/p4c/build/ir/ir-generated.h"
/// @return a bool literal. Both booleans are interned.
#line 374 "/root/p4c/ir/expression.def"
    static IR::BoolLiteral const * get(bool value, Util::SourceInfo const & si = {});
#line 5787 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::BoolLiteral const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "BoolLiteral"_cs; }
    static cstring static_type_name() { return "BoolLiteral"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    BoolLiteral(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Literal const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    BoolLiteral(Util::SourceInfo srcInfo, const IR::Type* type, bool value) :
    Literal(srcInfo, type), value(value)
    { validate(); }
    BoolLiteral(const IR::Type* type, bool value) :
    Literal(type), value(value)
    { validate(); }
    BoolLiteral(Util::SourceInfo srcInfo, bool value) :
    Literal(srcInfo), value(value)
    { validate(); }
    BoolLiteral(bool value) :
    value(value)
    { validate(); }
    IRNODE_SUBCLASS(BoolLiteral)
    DECLARE_TYPEINFO_WITH_TYPEID(BoolLiteral, NodeKind::BoolLiteral, Literal);
};
}  // namespace P4::IR
namespace P4::IR {
class StringLiteral : public Literal {
 public:
    cstring value;
#line 379 "/root/p4c/ir/expression.def"
    void validate() const override;
#line 5822 "/root/p4c/build/ir/ir-generated.h"
#line 380 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 5825 "/root/p4c/build/ir/ir-generated.h"
#line 381 "/root/p4c/ir/expression.def"
    StringLiteral(IR::ID v) : Literal(v.srcInfo), value(v.name) {}
#line 5828 "/root/p4c/build/ir/ir-generated.h"
#line 383 "/root/p4c/ir/expression.def"
    operator IR::ID() const { return IR::ID(srcInfo, value); }
#line 5831 "/root/p4c/build/ir/ir-generated.h"
/// @returns a string literal. The value is cached.
#line 387 "/root/p4c/ir/expression.def"
    static IR::StringLiteral const * get(cstring value, IR::Type const * t = Type_String::get(), Util::SourceInfo const & si = {});
#line 5835 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::StringLiteral const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "StringLiteral"_cs; }
    static cstring static_type_name() { return "StringLiteral"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    StringLiteral(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Literal const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    StringLiteral(Util::SourceInfo srcInfo, const IR::Type* type, cstring value) :
    Literal(srcInfo, type), value(value)
    { validate(); }
    StringLiteral(const IR::Type* type, cstring value) :
    Literal(type), value(value)
    { validate(); }
    StringLiteral(Util::SourceInfo srcInfo, cstring value) :
    Literal(srcInfo), value(value)
    { validate(); }
    StringLiteral(cstring value) :
    value(value)
    { validate(); }
    IRNODE_SUBCLASS(StringLiteral)
    DECLARE_TYPEINFO_WITH_TYPEID(StringLiteral, NodeKind::StringLiteral, Literal);
};
}  // namespace P4::IR
namespace P4::IR {
class PathExpression : public Expression {
 public:
    const IR::Path* path = nullptr;
#line 393 "/root/p4c/ir/expression.def"
    PathExpression(const IR::Type* t, IR::ID id) : Expression(id.srcInfo, t), path(new IR::Path(id)) {}
#line 5870 "/root/p4c/build/ir/ir-generated.h"
#line 394 "/root/p4c/ir/expression.def"
    PathExpression(IR::ID id) : Expression(id.srcInfo), path(new IR::Path(id)) {}
#line 5873 "/root/p4c/build/ir/ir-generated.h"
#line 395 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 5876 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::PathExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "PathExpression"_cs; }
    static cstring static_type_name() { return "PathExpression"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    PathExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    PathExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Path* path) :
    Expression(srcInfo, type), path(path)
    {
#line 392 "/root/p4c/ir/expression.def"
{ if (!srcInfo && path) srcInfo = path->srcInfo; }
#line 5895 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    PathExpression(const IR::Type* type, const IR::Path* path) :
    Expression(type), path(path)
    {
#line 392 "/root/p4c/ir/expression.def"
{ if (!srcInfo && path) srcInfo = path->srcInfo; }
#line 5902 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    PathExpression(Util::SourceInfo srcInfo, const IR::Path* path) :
    Expression(srcInfo), path(path)
    {
#line 392 "/root/p4c/ir/expression.def"
{ if (!srcInfo && path) srcInfo = path->srcInfo; }
#line 5909 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    PathExpression(const IR::Path* path) :
    path(path)
    {
#line 392 "/root/p4c/ir/expression.def"
{ if (!srcInfo && path) srcInfo = path->srcInfo; }
#line 5916 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(PathExpression)
    DECLARE_TYPEINFO_WITH_TYPEID(PathExpression, NodeKind::PathExpression, Expression);
};
}  // namespace P4::IR
namespace P4::IR {

class TypeNameExpression : public Expression {
 public:
    const IR::Type* typeName = nullptr;
#line 404 "/root/p4c/ir/expression.def"
    TypeNameExpression(IR::ID id) : Expression(id.srcInfo),
                                typeName(new IR::Type_Name(new IR::Path(id))) {}
#line 5930 "/root/p4c/build/ir/ir-generated.h"
#line 406 "/root/p4c/ir/expression.def"
    void dbprint(std::ostream & out) const override;
#line 5933 "/root/p4c/build/ir/ir-generated.h"
#line 407 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 5936 "/root/p4c/build/ir/ir-generated.h"
#line 408 "/root/p4c/ir/expression.def"
    void validate() const override;
#line 5939 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TypeNameExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "TypeNameExpression"_cs; }
    static cstring static_type_name() { return "TypeNameExpression"_cs; }
    void toJSON(JSONGenerator & json) const override;
    TypeNameExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    TypeNameExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Type* typeName) :
    Expression(srcInfo, type), typeName(typeName)
    {
#line 403 "/root/p4c/ir/expression.def"
{ if (!srcInfo && typeName) srcInfo = typeName->srcInfo; }
#line 5956 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    TypeNameExpression(const IR::Type* type, const IR::Type* typeName) :
    Expression(type), typeName(typeName)
    {
#line 403 "/root/p4c/ir/expression.def"
{ if (!srcInfo && typeName) srcInfo = typeName->srcInfo; }
#line 5963 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    TypeNameExpression(Util::SourceInfo srcInfo, const IR::Type* typeName) :
    Expression(srcInfo), typeName(typeName)
    {
#line 403 "/root/p4c/ir/expression.def"
{ if (!srcInfo && typeName) srcInfo = typeName->srcInfo; }
#line 5970 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    TypeNameExpression(const IR::Type* typeName) :
    typeName(typeName)
    {
#line 403 "/root/p4c/ir/expression.def"
{ if (!srcInfo && typeName) srcInfo = typeName->srcInfo; }
#line 5977 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(TypeNameExpression)
    DECLARE_TYPEINFO_WITH_TYPEID(TypeNameExpression, NodeKind::TypeNameExpression, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
class AbstractSlice : public Operation_Ternary {
 public:
#line 413 "/root/p4c/ir/expression.def"
    virtual unsigned getH() const = 0;
#line 5988 "/root/p4c/build/ir/ir-generated.h"
#line 414 "/root/p4c/ir/expression.def"
    virtual unsigned getL() const = 0;
#line 5991 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::AbstractSlice const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "AbstractSlice"_cs; }
    static cstring static_type_name() { return "AbstractSlice"_cs; }
    void toJSON(JSONGenerator & json) const override;
    AbstractSlice(JSONLoader & json);
    bool operator==(IR::Operation_Ternary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    AbstractSlice(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(srcInfo, type, e0, e1, e2)
    { validate(); }
    AbstractSlice(const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(type, e0, e1, e2)
    { validate(); }
    AbstractSlice(Util::SourceInfo srcInfo, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(srcInfo, e0, e1, e2)
    { validate(); }
    AbstractSlice(const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(e0, e1, e2)
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(AbstractSlice)
    DECLARE_TYPEINFO_WITH_TYPEID(AbstractSlice, NodeKind::AbstractSlice, Operation_Ternary);
};
}  // namespace P4::IR
namespace P4::IR {
class Slice : public AbstractSlice {
 public:
    int getPrecedence() const override { return DBPrint::Prec_Postfix; }
    cstring getStringOp() const override { return cstring("[:]"); }
#line 420 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 6026 "/root/p4c/build/ir/ir-generated.h"

#line 422 "/root/p4c/ir/expression.def"
    unsigned getH() const override;
#line 6030 "/root/p4c/build/ir/ir-generated.h"
#line 423 "/root/p4c/ir/expression.def"
    unsigned getL() const override;
#line 6033 "/root/p4c/build/ir/ir-generated.h"
#line 424 "/root/p4c/ir/expression.def"
    Slice(const IR::Expression* a, int hi, int lo) : AbstractSlice(IR::Type::Bits::get(hi-lo+1), a, new Constant(hi), new Constant(lo)) {}
#line 6036 "/root/p4c/build/ir/ir-generated.h"
#line 426 "/root/p4c/ir/expression.def"
    Slice(Util::SourceInfo si, const IR::Expression* a, int hi, int lo) : AbstractSlice(si, IR::Type::Bits::get(hi-lo+1), a, new Constant(hi), new Constant(lo)) {}
#line 6039 "/root/p4c/build/ir/ir-generated.h"

#line 432 "/root/p4c/ir/expression.def"
    static const IR::Expression *make(const IR::Expression* a, unsigned hi, unsigned lo);
#line 6043 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Slice const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Slice"_cs; }
    static cstring static_type_name() { return "Slice"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Slice(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::AbstractSlice const & a) const override;
    bool operator==(IR::Operation_Ternary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Slice(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    AbstractSlice(srcInfo, type, e0, e1, e2)
    {
#line 428 "/root/p4c/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e1 && e1->is<Constant>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(getH() - getL() + 1); }
#line 6064 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Slice(const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    AbstractSlice(type, e0, e1, e2)
    {
#line 428 "/root/p4c/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e1 && e1->is<Constant>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(getH() - getL() + 1); }
#line 6073 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Slice(Util::SourceInfo srcInfo, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    AbstractSlice(srcInfo, e0, e1, e2)
    {
#line 428 "/root/p4c/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e1 && e1->is<Constant>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(getH() - getL() + 1); }
#line 6082 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Slice(const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    AbstractSlice(e0, e1, e2)
    {
#line 428 "/root/p4c/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e1 && e1->is<Constant>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(getH() - getL() + 1); }
#line 6091 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(Slice)
    DECLARE_TYPEINFO_WITH_TYPEID(Slice, NodeKind::Slice, AbstractSlice);
};
}  // namespace P4::IR
namespace P4::IR {
class PlusSlice : public AbstractSlice {
 public:
    int getPrecedence() const override { return DBPrint::Prec_Postfix; }
    cstring getStringOp() const override { return cstring("[+:]"); }
#line 438 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 6104 "/root/p4c/build/ir/ir-generated.h"
#line 439 "/root/p4c/ir/expression.def"
    unsigned getH() const override;
#line 6107 "/root/p4c/build/ir/ir-generated.h"
#line 442 "/root/p4c/ir/expression.def"
    unsigned getL() const override;
#line 6110 "/root/p4c/build/ir/ir-generated.h"
#line 445 "/root/p4c/ir/expression.def"
    PlusSlice(const IR::Expression* a, const IR::Expression* lo, int width) : AbstractSlice(IR::Type::Bits::get(width), a, lo, new Constant(width)) {}
#line 6113 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::PlusSlice const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "PlusSlice"_cs; }
    static cstring static_type_name() { return "PlusSlice"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    PlusSlice(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::AbstractSlice const & a) const override;
    bool operator==(IR::Operation_Ternary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    PlusSlice(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    AbstractSlice(srcInfo, type, e0, e1, e2)
    {
#line 447 "/root/p4c/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(e2->to<IR::Constant>()->asUnsigned()); }
#line 6134 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    PlusSlice(const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    AbstractSlice(type, e0, e1, e2)
    {
#line 447 "/root/p4c/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(e2->to<IR::Constant>()->asUnsigned()); }
#line 6143 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    PlusSlice(Util::SourceInfo srcInfo, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    AbstractSlice(srcInfo, e0, e1, e2)
    {
#line 447 "/root/p4c/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(e2->to<IR::Constant>()->asUnsigned()); }
#line 6152 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    PlusSlice(const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    AbstractSlice(e0, e1, e2)
    {
#line 447 "/root/p4c/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(e2->to<IR::Constant>()->asUnsigned()); }
#line 6161 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(PlusSlice)
    DECLARE_TYPEINFO_WITH_TYPEID(PlusSlice, NodeKind::PlusSlice, AbstractSlice);
};
}  // namespace P4::IR
namespace P4::IR {
class Member : public Operation_Unary {
 public:
    int getPrecedence() const override { return DBPrint::Prec_Postfix; }
    IR::ID member;
#line 455 "/root/p4c/ir/expression.def"
    virtual int offset_bits() const;
#line 6174 "/root/p4c/build/ir/ir-generated.h"
#line 456 "/root/p4c/ir/expression.def"
    int lsb() const;
#line 6177 "/root/p4c/build/ir/ir-generated.h"
#line 457 "/root/p4c/ir/expression.def"
    int msb() const;
#line 6180 "/root/p4c/build/ir/ir-generated.h"
    cstring getStringOp() const override { return cstring("."); }
#line 459 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 6184 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Member const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Member"_cs; }
    static cstring static_type_name() { return "Member"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Member(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Unary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Member(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr, IR::ID member) :
    Operation_Unary(srcInfo, type, expr), member(member)
    { validate(); }
    Member(const IR::Type* type, const IR::Expression* expr, IR::ID member) :
    Operation_Unary(type, expr), member(member)
    { validate(); }
    Member(Util::SourceInfo srcInfo, const IR::Expression* expr, IR::ID member) :
    Operation_Unary(srcInfo, expr), member(member)
    { validate(); }
    Member(const IR::Expression* expr, IR::ID member) :
    Operation_Unary(expr), member(member)
    { validate(); }
    IRNODE_SUBCLASS(Member)
    DECLARE_TYPEINFO_WITH_TYPEID(Member, NodeKind::Member, Operation_Unary);
};
}  // namespace P4::IR
namespace P4::IR {
class Concat : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("++"); }
    int getPrecedence() const override { return DBPrint::Prec_Add; }
    bool operator==(IR::Concat const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Concat"_cs; }
    static cstring static_type_name() { return "Concat"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Concat(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Concat(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 465 "/root/p4c/ir/expression.def"
{
        if (left && right) {
            auto lt = left->type->to<IR::Type::Bits>();
            auto rt = right->type->to<IR::Type::Bits>();
            if (lt && rt)
                type = IR::Type::Bits::get(lt->size + rt->size, lt->isSigned); } }
#line 6241 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Concat(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 465 "/root/p4c/ir/expression.def"
{
        if (left && right) {
            auto lt = left->type->to<IR::Type::Bits>();
            auto rt = right->type->to<IR::Type::Bits>();
            if (lt && rt)
                type = IR::Type::Bits::get(lt->size + rt->size, lt->isSigned); } }
#line 6253 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Concat(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 465 "/root/p4c/ir/expression.def"
{
        if (left && right) {
            auto lt = left->type->to<IR::Type::Bits>();
            auto rt = right->type->to<IR::Type::Bits>();
            if (lt && rt)
                type = IR::Type::Bits::get(lt->size + rt->size, lt->isSigned); } }
#line 6265 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Concat(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 465 "/root/p4c/ir/expression.def"
{
        if (left && right) {
            auto lt = left->type->to<IR::Type::Bits>();
            auto rt = right->type->to<IR::Type::Bits>();
            if (lt && rt)
                type = IR::Type::Bits::get(lt->size + rt->size, lt->isSigned); } }
#line 6277 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(Concat)
    DECLARE_TYPEINFO_WITH_TYPEID(Concat, NodeKind::Concat, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class ArrayIndex : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("[]"); }
    int getPrecedence() const override { return DBPrint::Prec_Postfix; }
#line 479 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 6290 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ArrayIndex const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ArrayIndex"_cs; }
    static cstring static_type_name() { return "ArrayIndex"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ArrayIndex(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ArrayIndex(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 476 "/root/p4c/ir/expression.def"
{
        if (auto st = left ? left->type->to<IR::Type_Stack>() : nullptr)
            type = st->elementType; }
#line 6310 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ArrayIndex(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 476 "/root/p4c/ir/expression.def"
{
        if (auto st = left ? left->type->to<IR::Type_Stack>() : nullptr)
            type = st->elementType; }
#line 6319 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ArrayIndex(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 476 "/root/p4c/ir/expression.def"
{
        if (auto st = left ? left->type->to<IR::Type_Stack>() : nullptr)
            type = st->elementType; }
#line 6328 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ArrayIndex(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 476 "/root/p4c/ir/expression.def"
{
        if (auto st = left ? left->type->to<IR::Type_Stack>() : nullptr)
            type = st->elementType; }
#line 6337 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(ArrayIndex)
    DECLARE_TYPEINFO_WITH_TYPEID(ArrayIndex, NodeKind::ArrayIndex, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class Range : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring(".."); }
    int getPrecedence() const override { return DBPrint::Prec_Low; }
    bool operator==(IR::Range const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Range"_cs; }
    static cstring static_type_name() { return "Range"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Range(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Range(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 485 "/root/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 6366 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Range(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 485 "/root/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 6374 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Range(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 485 "/root/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 6382 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Range(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 485 "/root/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 6390 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(Range)
    DECLARE_TYPEINFO_WITH_TYPEID(Range, NodeKind::Range, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class Mask : public Operation_Binary {
 public:
    cstring getStringOp() const override { return cstring("&&&"); }
    int getPrecedence() const override { return DBPrint::Prec_Low; }
    bool operator==(IR::Mask const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Mask"_cs; }
    static cstring static_type_name() { return "Mask"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Mask(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Mask(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 492 "/root/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 6419 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Mask(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 492 "/root/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 6427 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Mask(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 492 "/root/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 6435 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Mask(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 492 "/root/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 6443 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(Mask)
    DECLARE_TYPEINFO_WITH_TYPEID(Mask, NodeKind::Mask, Operation_Binary);
};
}  // namespace P4::IR
namespace P4::IR {
class Mux : public Operation_Ternary {
 public:
    cstring getStringOp() const override { return cstring("?:"); }
    int getPrecedence() const override { return DBPrint::Prec_Low; }
#line 499 "/root/p4c/ir/expression.def"
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
#line 6457 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Mux const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Mux"_cs; }
    static cstring static_type_name() { return "Mux"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Mux(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Ternary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Mux(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(srcInfo, type, e0, e1, e2)
    {
#line 503 "/root/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && e1 && e2 && e1->type == e2->type) type = e1->type; }
#line 6475 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Mux(const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(type, e0, e1, e2)
    {
#line 503 "/root/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && e1 && e2 && e1->type == e2->type) type = e1->type; }
#line 6482 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Mux(Util::SourceInfo srcInfo, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(srcInfo, e0, e1, e2)
    {
#line 503 "/root/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && e1 && e2 && e1->type == e2->type) type = e1->type; }
#line 6489 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    Mux(const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(e0, e1, e2)
    {
#line 503 "/root/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && e1 && e2 && e1->type == e2->type) type = e1->type; }
#line 6496 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(Mux)
    DECLARE_TYPEINFO_WITH_TYPEID(Mux, NodeKind::Mux, Operation_Ternary);
};
}  // namespace P4::IR
namespace P4::IR {
class DefaultExpression : public Expression {
 public:
    bool operator==(IR::DefaultExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DefaultExpression"_cs; }
    static cstring static_type_name() { return "DefaultExpression"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DefaultExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DefaultExpression(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
    DefaultExpression(const IR::Type* type) :
    Expression(type)
    { validate(); }
    DefaultExpression(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
    DefaultExpression() 
    { validate(); }
    IRNODE_SUBCLASS(DefaultExpression)
    DECLARE_TYPEINFO_WITH_TYPEID(DefaultExpression, NodeKind::DefaultExpression, Expression);
};
}  // namespace P4::IR
namespace P4::IR {

class This : public Expression {
 public:
    long id = nextId++;
#line 512 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 6537 "/root/p4c/build/ir/ir-generated.h"
 private:
    static long nextId;
 public:
    bool operator==(IR::This const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "This"_cs; }
    static cstring static_type_name() { return "This"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    This(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    This(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
    This(const IR::Type* type) :
    Expression(type)
    { validate(); }
    This(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
    This() 
    { validate(); }
    IRNODE_SUBCLASS(This)
    DECLARE_TYPEINFO_WITH_TYPEID(This, NodeKind::This, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
class Cast : public Operation_Unary {
 public:
    const IR::Type* destType = type;
/// These will generally always be the same, except when a cast to a type argument of
/// a generic occurs.  Then at some point, the 'destType' will be specialized to a concrete
/// type, and 'type' will only be updated later when type inferencing occurs
    int getPrecedence() const override { return DBPrint::Prec_Prefix; }
    cstring getStringOp() const override { return cstring("(cast)"); }
#line 524 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 6578 "/root/p4c/build/ir/ir-generated.h"
#line 525 "/root/p4c/ir/expression.def"
    void validate() const override;
#line 6581 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Cast const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Cast"_cs; }
    static cstring static_type_name() { return "Cast"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Cast(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Unary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Cast(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(srcInfo, type, expr)
    { validate(); }
    Cast(const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(type, expr)
    { validate(); }
    Cast(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation_Unary(srcInfo, expr)
    { validate(); }
    Cast(const IR::Expression* expr) :
    Operation_Unary(expr)
    { validate(); }
    IRNODE_SUBCLASS(Cast)
    DECLARE_TYPEINFO_WITH_TYPEID(Cast, NodeKind::Cast, Operation_Unary);
};
}  // namespace P4::IR
namespace P4::IR {
class SelectCase : public Node {
 public:
    const IR::Expression* keyset = nullptr;
    const IR::PathExpression* state = nullptr;
#line 531 "/root/p4c/ir/expression.def"
    void dbprint(std::ostream & out) const override;
#line 6619 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::SelectCase const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "SelectCase"_cs; }
    static cstring static_type_name() { return "SelectCase"_cs; }
    void toJSON(JSONGenerator & json) const override;
    SelectCase(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    SelectCase(Util::SourceInfo srcInfo, const IR::Expression* keyset, const IR::PathExpression* state) :
    Node(srcInfo), keyset(keyset), state(state)
    { validate(); }
    SelectCase(const IR::Expression* keyset, const IR::PathExpression* state) :
    keyset(keyset), state(state)
    { validate(); }
    IRNODE_SUBCLASS(SelectCase)
    DECLARE_TYPEINFO_WITH_TYPEID(SelectCase, NodeKind::SelectCase, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class SelectExpression : public Expression {
 public:
    const IR::ListExpression* select = nullptr;
    IR::Vector<IR::SelectCase> selectCases;
#line 537 "/root/p4c/ir/expression.def"
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
#line 6649 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::SelectExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "SelectExpression"_cs; }
    static cstring static_type_name() { return "SelectExpression"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    SelectExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    SelectExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases) :
    Expression(srcInfo, type), select(select), selectCases(selectCases)
    { validate(); }
    SelectExpression(const IR::Type* type, const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases) :
    Expression(type), select(select), selectCases(selectCases)
    { validate(); }
    SelectExpression(Util::SourceInfo srcInfo, const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases) :
    Expression(srcInfo), select(select), selectCases(selectCases)
    { validate(); }
    SelectExpression(const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases) :
    select(select), selectCases(selectCases)
    { validate(); }
    IRNODE_SUBCLASS(SelectExpression)
    DECLARE_TYPEINFO_WITH_TYPEID(SelectExpression, NodeKind::SelectExpression, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
class MethodCallExpression : public Expression {
 public:
    const IR::Expression* method = nullptr;
    const IR::Vector<IR::Type>* typeArguments = new Vector<Type>;
    const IR::Vector<IR::Argument>* arguments = new Vector<Argument>;
#line 547 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 6685 "/root/p4c/build/ir/ir-generated.h"
#line 556 "/root/p4c/ir/expression.def"
    void validate() const override;
#line 6688 "/root/p4c/build/ir/ir-generated.h"
#line 557 "/root/p4c/ir/expression.def"
    MethodCallExpression(Util::SourceInfo si, IR::ID m, std::initializer_list<const IR::Argument *> a) : Expression(si), method(new PathExpression(m)), arguments(new Vector<Argument>(a)) {}
#line 6691 "/root/p4c/build/ir/ir-generated.h"
#line 559 "/root/p4c/ir/expression.def"
    MethodCallExpression(Util::SourceInfo si, const IR::Expression* m, std::initializer_list<const IR::Argument *> const & a) : Expression(si), method(m), arguments(new Vector<Argument>(a)) {}
#line 6694 "/root/p4c/build/ir/ir-generated.h"
#line 562 "/root/p4c/ir/expression.def"
    MethodCallExpression(const IR::Expression* m, std::initializer_list<IR::Expression const *> const & a);
#line 6697 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::MethodCallExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "MethodCallExpression"_cs; }
    static cstring static_type_name() { return "MethodCallExpression"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    MethodCallExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo, type), method(method), typeArguments(typeArguments), arguments(arguments)
    { validate(); }
    MethodCallExpression(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    Expression(type), method(method), typeArguments(typeArguments), arguments(arguments)
    { validate(); }
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo), method(method), typeArguments(typeArguments), arguments(arguments)
    { validate(); }
    MethodCallExpression(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    method(method), typeArguments(typeArguments), arguments(arguments)
    { validate(); }
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo, type), method(method), arguments(arguments)
    { validate(); }
    MethodCallExpression(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    Expression(type), method(method), arguments(arguments)
    { validate(); }
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo), method(method), arguments(arguments)
    { validate(); }
    MethodCallExpression(const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    method(method), arguments(arguments)
    { validate(); }
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    Expression(srcInfo, type), method(method), typeArguments(typeArguments)
    { validate(); }
    MethodCallExpression(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    Expression(type), method(method), typeArguments(typeArguments)
    { validate(); }
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    Expression(srcInfo), method(method), typeArguments(typeArguments)
    { validate(); }
    MethodCallExpression(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    method(method), typeArguments(typeArguments)
    { validate(); }
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method) :
    Expression(srcInfo, type), method(method)
    { validate(); }
    MethodCallExpression(const IR::Type* type, const IR::Expression* method) :
    Expression(type), method(method)
    { validate(); }
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method) :
    Expression(srcInfo), method(method)
    { validate(); }
    MethodCallExpression(const IR::Expression* method) :
    method(method)
    { validate(); }
    IRNODE_SUBCLASS(MethodCallExpression)
    DECLARE_TYPEINFO_WITH_TYPEID(MethodCallExpression, NodeKind::MethodCallExpression, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
class ConstructorCallExpression : public Expression {
 public:
    const IR::Type* constructedType = type;

    const IR::Vector<IR::Argument>* arguments = nullptr;
#line 572 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 6770 "/root/p4c/build/ir/ir-generated.h"
#line 573 "/root/p4c/ir/expression.def"
    void validate() const override;
#line 6773 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ConstructorCallExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "ConstructorCallExpression"_cs; }
    static cstring static_type_name() { return "ConstructorCallExpression"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ConstructorCallExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ConstructorCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo, type), arguments(arguments)
    { validate(); }
    ConstructorCallExpression(const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Expression(type), arguments(arguments)
    { validate(); }
    ConstructorCallExpression(Util::SourceInfo srcInfo, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo), arguments(arguments)
    { validate(); }
    ConstructorCallExpression(const IR::Vector<IR::Argument>* arguments) :
    arguments(arguments)
    { validate(); }
    IRNODE_SUBCLASS(ConstructorCallExpression)
    DECLARE_TYPEINFO_WITH_TYPEID(ConstructorCallExpression, NodeKind::ConstructorCallExpression, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
class BaseListExpression : public Expression {
 public:
    IR::Vector<IR::Expression> components;
#line 581 "/root/p4c/ir/expression.def"
    void validate() const override;
#line 6808 "/root/p4c/build/ir/ir-generated.h"
#line 582 "/root/p4c/ir/expression.def"
    size_t size() const { return components.size(); }
#line 6811 "/root/p4c/build/ir/ir-generated.h"
#line 583 "/root/p4c/ir/expression.def"
    void push_back(const IR::Expression* e) { components.push_back(e); }
#line 6814 "/root/p4c/build/ir/ir-generated.h"
#line 584 "/root/p4c/ir/expression.def"
    bool containsDots() const {
        if (components.empty())
            return false;
        size_t size = components.size();
        return components.at(size - 1)->is<IR::Dots>();
    }
#line 6822 "/root/p4c/build/ir/ir-generated.h"
#line 590 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 6825 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::BaseListExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "BaseListExpression"_cs; }
    static cstring static_type_name() { return "BaseListExpression"_cs; }
    void toJSON(JSONGenerator & json) const override;
    BaseListExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    BaseListExpression(Util::SourceInfo srcInfo, const IR::Type* type, IR::Vector<IR::Expression> components) :
    Expression(srcInfo, type), components(components)
    { validate(); }
    BaseListExpression(const IR::Type* type, IR::Vector<IR::Expression> components) :
    Expression(type), components(components)
    { validate(); }
    BaseListExpression(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> components) :
    Expression(srcInfo), components(components)
    { validate(); }
    BaseListExpression(IR::Vector<IR::Expression> components) :
    components(components)
    { validate(); }
    IRNODE_SUBCLASS(BaseListExpression)
    DECLARE_TYPEINFO_WITH_TYPEID(BaseListExpression, NodeKind::BaseListExpression, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
/// Represents a list of expressions separated by commas
class ListExpression : public BaseListExpression {
 public:
    bool operator==(IR::ListExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ListExpression"_cs; }
    static cstring static_type_name() { return "ListExpression"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ListExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::BaseListExpression const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ListExpression(Util::SourceInfo srcInfo, const IR::Type* type, IR::Vector<IR::Expression> components) :
    BaseListExpression(srcInfo, type, components)
    {
#line 604 "/root/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            Vector<Type> tuple;
            for (auto e : components)
                tuple.push_back(e->type);
            type = new Type_List(tuple); } }
#line 6879 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ListExpression(const IR::Type* type, IR::Vector<IR::Expression> components) :
    BaseListExpression(type, components)
    {
#line 604 "/root/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            Vector<Type> tuple;
            for (auto e : components)
                tuple.push_back(e->type);
            type = new Type_List(tuple); } }
#line 6892 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ListExpression(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> components) :
    BaseListExpression(srcInfo, components)
    {
#line 604 "/root/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            Vector<Type> tuple;
            for (auto e : components)
                tuple.push_back(e->type);
            type = new Type_List(tuple); } }
#line 6905 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ListExpression(IR::Vector<IR::Expression> components) :
    BaseListExpression(components)
    {
#line 604 "/root/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            Vector<Type> tuple;
            for (auto e : components)
                tuple.push_back(e->type);
            type = new Type_List(tuple); } }
#line 6918 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(ListExpression)
    DECLARE_TYPEINFO_WITH_TYPEID(ListExpression, NodeKind::ListExpression, BaseListExpression);
};
}  // namespace P4::IR
namespace P4::IR {
/// Represents P4 list expression, not to be confused with
/// ListExpression from above.
class P4ListExpression : public BaseListExpression {
 public:
    const IR::Type* elementType = nullptr;
    bool operator==(IR::P4ListExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "P4ListExpression"_cs; }
    static cstring static_type_name() { return "P4ListExpression"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P4ListExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::BaseListExpression const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    P4ListExpression(Util::SourceInfo srcInfo, const IR::Type* type, IR::Vector<IR::Expression> components, const IR::Type* elementType) :
    BaseListExpression(srcInfo, type, components), elementType(elementType)
    {
#line 617 "/root/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            type = new Type_P4List(elementType); } }
#line 6952 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    P4ListExpression(const IR::Type* type, IR::Vector<IR::Expression> components, const IR::Type* elementType) :
    BaseListExpression(type, components), elementType(elementType)
    {
#line 617 "/root/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            type = new Type_P4List(elementType); } }
#line 6962 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    P4ListExpression(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> components, const IR::Type* elementType) :
    BaseListExpression(srcInfo, components), elementType(elementType)
    {
#line 617 "/root/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            type = new Type_P4List(elementType); } }
#line 6972 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    P4ListExpression(IR::Vector<IR::Expression> components, const IR::Type* elementType) :
    BaseListExpression(components), elementType(elementType)
    {
#line 617 "/root/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            type = new Type_P4List(elementType); } }
#line 6982 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(P4ListExpression)
    DECLARE_TYPEINFO_WITH_TYPEID(P4ListExpression, NodeKind::P4ListExpression, BaseListExpression);
};
}  // namespace P4::IR
namespace P4::IR {
/// An expression that evaluates to a struct.
class StructExpression : public Expression {
 public:
/// The struct or header type that is being intialized.
/// May only be known after type checking; so it can be nullptr.
    const IR::Type* structType = nullptr;
    IR::IndexedVector<IR::NamedExpression> components;
#line 629 "/root/p4c/ir/expression.def"
    void validate() const override;
#line 6998 "/root/p4c/build/ir/ir-generated.h"
#line 635 "/root/p4c/ir/expression.def"
    size_t size() const { return components.size(); }
#line 7001 "/root/p4c/build/ir/ir-generated.h"
#line 636 "/root/p4c/ir/expression.def"
    const IR::NamedExpression *getField(cstring name) const {
        return components.getDeclaration<NamedExpression>(name); }
#line 7005 "/root/p4c/build/ir/ir-generated.h"
#line 638 "/root/p4c/ir/expression.def"
    bool containsDots() const {
        if (components.empty())
            return false;
        size_t size = components.size();
        return components.at(size - 1)->is<IR::NamedDots>();
    }
#line 7013 "/root/p4c/build/ir/ir-generated.h"
#line 644 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 7016 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::StructExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "StructExpression"_cs; }
    static cstring static_type_name() { return "StructExpression"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    StructExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    StructExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components) :
    Expression(srcInfo, type), structType(structType), components(components)
    { validate(); }
    StructExpression(const IR::Type* type, const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components) :
    Expression(type), structType(structType), components(components)
    { validate(); }
    StructExpression(Util::SourceInfo srcInfo, const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components) :
    Expression(srcInfo), structType(structType), components(components)
    { validate(); }
    StructExpression(const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components) :
    structType(structType), components(components)
    { validate(); }
    IRNODE_SUBCLASS(StructExpression)
    DECLARE_TYPEINFO_WITH_TYPEID(StructExpression, NodeKind::StructExpression, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
/// Can be an invalid header or header_union
class Invalid : public Expression {
 public:
    bool operator==(IR::Invalid const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Invalid"_cs; }
    static cstring static_type_name() { return "Invalid"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Invalid(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Invalid(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
    Invalid(const IR::Type* type) :
    Expression(type)
    { validate(); }
    Invalid(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
    Invalid() 
    { validate(); }
    IRNODE_SUBCLASS(Invalid)
    DECLARE_TYPEINFO_WITH_TYPEID(Invalid, NodeKind::Invalid, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
/// An expression that evaluates to an invalid header with the specified type.
class InvalidHeader : public Expression {
 public:
    const IR::Type* headerType = nullptr;
    bool operator==(IR::InvalidHeader const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "InvalidHeader"_cs; }
    static cstring static_type_name() { return "InvalidHeader"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    InvalidHeader(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    InvalidHeader(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Type* headerType) :
    Expression(srcInfo, type), headerType(headerType)
    { validate(); }
    InvalidHeader(const IR::Type* type, const IR::Type* headerType) :
    Expression(type), headerType(headerType)
    { validate(); }
    InvalidHeader(Util::SourceInfo srcInfo, const IR::Type* headerType) :
    Expression(srcInfo), headerType(headerType)
    { validate(); }
    InvalidHeader(const IR::Type* headerType) :
    headerType(headerType)
    { validate(); }
    IRNODE_SUBCLASS(InvalidHeader)
    DECLARE_TYPEINFO_WITH_TYPEID(InvalidHeader, NodeKind::InvalidHeader, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
/// An expression that evaluates to an invalid header union with the specified type.
class InvalidHeaderUnion : public Expression {
 public:
    const IR::Type* headerUnionType = nullptr;
    bool operator==(IR::InvalidHeaderUnion const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "InvalidHeaderUnion"_cs; }
    static cstring static_type_name() { return "InvalidHeaderUnion"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    InvalidHeaderUnion(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    InvalidHeaderUnion(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Type* headerUnionType) :
    Expression(srcInfo, type), headerUnionType(headerUnionType)
    { validate(); }
    InvalidHeaderUnion(const IR::Type* type, const IR::Type* headerUnionType) :
    Expression(type), headerUnionType(headerUnionType)
    { validate(); }
    InvalidHeaderUnion(Util::SourceInfo srcInfo, const IR::Type* headerUnionType) :
    Expression(srcInfo), headerUnionType(headerUnionType)
    { validate(); }
    InvalidHeaderUnion(const IR::Type* headerUnionType) :
    headerUnionType(headerUnionType)
    { validate(); }
    IRNODE_SUBCLASS(InvalidHeaderUnion)
    DECLARE_TYPEINFO_WITH_TYPEID(InvalidHeaderUnion, NodeKind::InvalidHeaderUnion, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
/// An expression that evaluates to a header stack
class HeaderStackExpression : public BaseListExpression {
 public:
/// May only be known after type checking; so it can be nullptr.
    const IR::Type* headerStackType = nullptr;
#line 673 "/root/p4c/ir/expression.def"
    void validate() const override;
#line 7150 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::HeaderStackExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "HeaderStackExpression"_cs; }
    static cstring static_type_name() { return "HeaderStackExpression"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    HeaderStackExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::BaseListExpression const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    HeaderStackExpression(Util::SourceInfo srcInfo, const IR::Type* type, IR::Vector<IR::Expression> components, const IR::Type* headerStackType) :
    BaseListExpression(srcInfo, type, components), headerStackType(headerStackType)
    { validate(); }
    HeaderStackExpression(const IR::Type* type, IR::Vector<IR::Expression> components, const IR::Type* headerStackType) :
    BaseListExpression(type, components), headerStackType(headerStackType)
    { validate(); }
    HeaderStackExpression(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> components, const IR::Type* headerStackType) :
    BaseListExpression(srcInfo, components), headerStackType(headerStackType)
    { validate(); }
    HeaderStackExpression(IR::Vector<IR::Expression> components, const IR::Type* headerStackType) :
    BaseListExpression(components), headerStackType(headerStackType)
    { validate(); }
    IRNODE_SUBCLASS(HeaderStackExpression)
    DECLARE_TYPEINFO_WITH_TYPEID(HeaderStackExpression, NodeKind::HeaderStackExpression, BaseListExpression);
};
}  // namespace P4::IR
namespace P4::IR {
/// A ListExpression where all the components are compile-time values.
/// This is used by the evaluator pass.
class ListCompileTimeValue : public Node, public virtual CompileTimeValue {
 public:
    IR::Vector<IR::Node> components;
#line 682 "/root/p4c/ir/expression.def"
    void validate() const override;
#line 7188 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ListCompileTimeValue const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "ListCompileTimeValue"_cs; }
    static cstring static_type_name() { return "ListCompileTimeValue"_cs; }
    void toJSON(JSONGenerator & json) const override;
    ListCompileTimeValue(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    ListCompileTimeValue(Util::SourceInfo srcInfo, IR::Vector<IR::Node> components) :
    Node(srcInfo), components(components)
    { validate(); }
    ListCompileTimeValue(IR::Vector<IR::Node> components) :
    components(components)
    { validate(); }
    IRNODE_SUBCLASS(ListCompileTimeValue)
    DECLARE_TYPEINFO_WITH_TYPEID(ListCompileTimeValue, NodeKind::ListCompileTimeValue, Node, CompileTimeValue);
};
}  // namespace P4::IR
namespace P4::IR {
/// A P4ListExpression where all the components are compile-time values.
/// This is used by the evaluator pass.
class P4ListCompileTimeValue : public Node, public virtual CompileTimeValue {
 public:
    IR::Vector<IR::Node> components;
#line 692 "/root/p4c/ir/expression.def"
    void validate() const override;
#line 7217 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P4ListCompileTimeValue const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "P4ListCompileTimeValue"_cs; }
    static cstring static_type_name() { return "P4ListCompileTimeValue"_cs; }
    void toJSON(JSONGenerator & json) const override;
    P4ListCompileTimeValue(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    P4ListCompileTimeValue(Util::SourceInfo srcInfo, IR::Vector<IR::Node> components) :
    Node(srcInfo), components(components)
    { validate(); }
    P4ListCompileTimeValue(IR::Vector<IR::Node> components) :
    components(components)
    { validate(); }
    IRNODE_SUBCLASS(P4ListCompileTimeValue)
    DECLARE_TYPEINFO_WITH_TYPEID(P4ListCompileTimeValue, NodeKind::P4ListCompileTimeValue, Node, CompileTimeValue);
};
}  // namespace P4::IR
namespace P4::IR {
/// A StructExpression where all the components are compile-time values.
/// This is used by the evaluator pass.
class StructCompileTimeValue : public Node, public virtual CompileTimeValue {
 public:
    IR::Vector<IR::Node> components;
#line 702 "/root/p4c/ir/expression.def"
    void validate() const override;
#line 7246 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::StructCompileTimeValue const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "StructCompileTimeValue"_cs; }
    static cstring static_type_name() { return "StructCompileTimeValue"_cs; }
    void toJSON(JSONGenerator & json) const override;
    StructCompileTimeValue(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    StructCompileTimeValue(Util::SourceInfo srcInfo, IR::Vector<IR::Node> components) :
    Node(srcInfo), components(components)
    { validate(); }
    StructCompileTimeValue(IR::Vector<IR::Node> components) :
    components(components)
    { validate(); }
    IRNODE_SUBCLASS(StructCompileTimeValue)
    DECLARE_TYPEINFO_WITH_TYPEID(StructCompileTimeValue, NodeKind::StructCompileTimeValue, Node, CompileTimeValue);
};
}  // namespace P4::IR
namespace P4::IR {
/// Experimental: an extern methond/function call with constant arguments to be
/// evaluated at compile time
class CompileTimeMethodCall : public MethodCallExpression, public virtual CompileTimeValue {
 public:
#line 711 "/root/p4c/ir/expression.def"
    CompileTimeMethodCall(const IR::MethodCallExpression* e) : MethodCallExpression(*e) {}
#line 7274 "/root/p4c/build/ir/ir-generated.h"
#line 712 "/root/p4c/ir/expression.def"
    void validate() const override;
#line 7277 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::CompileTimeMethodCall const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "CompileTimeMethodCall"_cs; }
    static cstring static_type_name() { return "CompileTimeMethodCall"_cs; }
    void toJSON(JSONGenerator & json) const override;
    CompileTimeMethodCall(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::MethodCallExpression const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(srcInfo, type, method, typeArguments, arguments)
    { validate(); }
    CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(type, method, typeArguments, arguments)
    { validate(); }
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(srcInfo, method, typeArguments, arguments)
    { validate(); }
    CompileTimeMethodCall(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(method, typeArguments, arguments)
    { validate(); }
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(srcInfo, type, method, arguments)
    { validate(); }
    CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(type, method, arguments)
    { validate(); }
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(srcInfo, method, arguments)
    { validate(); }
    CompileTimeMethodCall(const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(method, arguments)
    { validate(); }
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    MethodCallExpression(srcInfo, type, method, typeArguments)
    { validate(); }
    CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    MethodCallExpression(type, method, typeArguments)
    { validate(); }
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    MethodCallExpression(srcInfo, method, typeArguments)
    { validate(); }
    CompileTimeMethodCall(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    MethodCallExpression(method, typeArguments)
    { validate(); }
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method) :
    MethodCallExpression(srcInfo, type, method)
    { validate(); }
    CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method) :
    MethodCallExpression(type, method)
    { validate(); }
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method) :
    MethodCallExpression(srcInfo, method)
    { validate(); }
    CompileTimeMethodCall(const IR::Expression* method) :
    MethodCallExpression(method)
    { validate(); }
    IRNODE_SUBCLASS(CompileTimeMethodCall)
    DECLARE_TYPEINFO_WITH_TYPEID(CompileTimeMethodCall, NodeKind::CompileTimeMethodCall, MethodCallExpression, CompileTimeValue);
};
}  // namespace P4::IR
namespace P4::IR {
/// Signifies that a particular expression is a symbolic variable with a label.
/// These variables are intended to be consumed by SMT/SAT solvers.
class SymbolicVariable : public Expression {
 public:
/// The label of the symbolic variable.
    cstring label;
/// A symbolic variable always has a type and no source info.
#line 727 "/root/p4c/ir/expression.def"
    SymbolicVariable(const IR::Type* type, cstring label) : Expression(type), label(label) {}
#line 7350 "/root/p4c/build/ir/ir-generated.h"
/// Implements comparisons so that SymbolicVariables can be used as map keys.
#line 730 "/root/p4c/ir/expression.def"
    bool operator<(IR::SymbolicVariable const & other) const {
        return label < other.label;
    }
#line 7356 "/root/p4c/build/ir/ir-generated.h"
#line 734 "/root/p4c/ir/expression.def"
    cstring toString() const override;
#line 7359 "/root/p4c/build/ir/ir-generated.h"
#line 736 "/root/p4c/ir/expression.def"
    void dbprint(std::ostream & out) const override;
#line 7362 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::SymbolicVariable const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "SymbolicVariable"_cs; }
    static cstring static_type_name() { return "SymbolicVariable"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    SymbolicVariable(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(SymbolicVariable)
    DECLARE_TYPEINFO_WITH_TYPEID(SymbolicVariable, NodeKind::SymbolicVariable, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
/** @} */
/* end group irdefs */
/* -*-C++-*- */
/** \addtogroup irdefs
  * @{
  */
/**
  P4 compiler IR definition file.
  To understand this you really have to understand the shape of the generated IR code.

  The IR builder "knows" the following methods for a class T:

  cstring toString() const override;
  void dbprint(std::ostream &out) const override;
  bool operator==(const T &a) const;
  void validate() const;
  const char *node_type_name() const;
  void visit_children(Visitor &v, const char *name);
  void dump_fields(std::ostream& out) const;

  C comments are ignored.
  C++ line comments can appear in some places and are emitted in the output.

  #emit/#end      -> copy text literally to output header file
  #emit_impl/#end -> copy text literally to output C++ file
  #noXXX          -> do not emit the specified implementation for the XXX method
                     e.g., #noconstructor, #nodbprint, #novisit_children, #nomethod_constructor
  #apply          -> generate apply overload for visitors
  method{ ... }   -> specifies an implementation for a default method
                     method can be 'operator=='

  Some assignments are turned into methods returning constant values:
  stringOp     -> cstring getStringOp() const
  precedence   -> int getPrecedence() const

  When defining fields and methods in an IR class, all fields and arguments of any IR
  class type are automatically converted into const IR::class * fields or arguments, unless
  they are identified as 'inline'.  It is not possible to create a non-const pointer to
  an IR class in any other IR class.

  There are some special keywords that can be applied (as decl modifiers) to fields that
  affect how they are created, checked, and initialized.

  inline      The field (of IR class type) should be defined directly in the object
              rather than being converted to a const T * as described above.
  NullOK      The field is a pointer and may be null (verify will check that it is not otherwise)
  optional    The field may be provided as an argument to the constructor but need not be.
              (overloaded constructors will be created as needed)

  Unless there is a '#noconstructor' tag in the class, a constructor
  will automatically be generated that takes as arguments values to
  initialize all fields of the IR class and its bases that do not have
  explicit initializers. There are some special method constructors which ignore #noconstructor, such as Class(JSONLoader &json). #nomethod_constructor will prevent these files from being generated. Fields marked 'optional' will create multiple constructors both with and without an argument for that field.
 */
class ParserState : public virtual ISimpleNamespace, public Declaration, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    IR::IndexedVector<IR::StatOrDecl> components;

    const IR::Expression* selectExpression = nullptr;
#line 63 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 7440 "/root/p4c/build/ir/ir-generated.h"
#line 64 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 7443 "/root/p4c/build/ir/ir-generated.h"
#line 65 "/root/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 7446 "/root/p4c/build/ir/ir-generated.h"
#line 67 "/root/p4c/ir/ir.def"
    IR::IDeclaration const * getDeclByName(cstring name) const override;
#line 7449 "/root/p4c/build/ir/ir-generated.h"
#line 69 "/root/p4c/ir/ir.def"
    IR::IDeclaration const * getDeclByName(std::string_view name) const override;
#line 7452 "/root/p4c/build/ir/ir-generated.h"
    static const cstring accept;
    static const cstring reject;
    static const cstring start;
    static const cstring verify;
#line 76 "/root/p4c/ir/ir.def"
    bool isBuiltin() const { return name == ParserState::accept || name == ParserState::reject; }
#line 7459 "/root/p4c/build/ir/ir-generated.h"
#line 77 "/root/p4c/ir/ir.def"
    void validate() const override;
#line 7462 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ParserState const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "ParserState"_cs; }
    static cstring static_type_name() { return "ParserState"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ParserState(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ParserState(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression) :
    Declaration(srcInfo, name), annotations(annotations), components(components), selectExpression(selectExpression)
    { validate(); }
    ParserState(IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression) :
    Declaration(name), annotations(annotations), components(components), selectExpression(selectExpression)
    { validate(); }
    ParserState(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression) :
    Declaration(srcInfo, name), components(components), selectExpression(selectExpression)
    { validate(); }
    ParserState(IR::ID name, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression) :
    Declaration(name), components(components), selectExpression(selectExpression)
    { validate(); }
    ParserState(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Expression* selectExpression) :
    Declaration(srcInfo, name), annotations(annotations), selectExpression(selectExpression)
    { validate(); }
    ParserState(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Expression* selectExpression) :
    Declaration(name), annotations(annotations), selectExpression(selectExpression)
    { validate(); }
    ParserState(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* selectExpression) :
    Declaration(srcInfo, name), selectExpression(selectExpression)
    { validate(); }
    ParserState(IR::ID name, const IR::Expression* selectExpression) :
    Declaration(name), selectExpression(selectExpression)
    { validate(); }
    IRNODE_SUBCLASS(ParserState)
    DECLARE_TYPEINFO_WITH_TYPEID(ParserState, NodeKind::ParserState, ISimpleNamespace, Declaration, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {

class P4Parser : public Type_Declaration, public virtual INestedNamespace, public virtual ISimpleNamespace, public virtual IApply, public virtual IContainer, public virtual IAnnotated {
 public:
    const IR::Type_Parser* type = nullptr;
    const IR::ParameterList* constructorParams = new ParameterList;
    IR::IndexedVector<IR::Declaration> parserLocals;
    IR::IndexedVector<IR::ParserState> states;
#line 92 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 7514 "/root/p4c/build/ir/ir-generated.h"
#line 93 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 7517 "/root/p4c/build/ir/ir-generated.h"
#line 94 "/root/p4c/ir/ir.def"
    const IR::TypeParameters *getTypeParameters() const override;
#line 7520 "/root/p4c/build/ir/ir-generated.h"
#line 95 "/root/p4c/ir/ir.def"
    std::vector<const IR::INamespace *> getNestedNamespaces() const override;
#line 7523 "/root/p4c/build/ir/ir-generated.h"
#line 97 "/root/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 7526 "/root/p4c/build/ir/ir-generated.h"
#line 99 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 7529 "/root/p4c/build/ir/ir-generated.h"
#line 103 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 7532 "/root/p4c/build/ir/ir-generated.h"
#line 108 "/root/p4c/ir/ir.def"
    const IR::Type_Method *getApplyMethodType() const override;
#line 7535 "/root/p4c/build/ir/ir-generated.h"
#line 109 "/root/p4c/ir/ir.def"
    const IR::ParameterList *getApplyParameters() const override;
#line 7538 "/root/p4c/build/ir/ir-generated.h"
#line 110 "/root/p4c/ir/ir.def"
    const IR::Type_Method *getConstructorMethodType() const override;
#line 7541 "/root/p4c/build/ir/ir-generated.h"
#line 111 "/root/p4c/ir/ir.def"
    const IR::ParameterList *getConstructorParameters() const override;
#line 7544 "/root/p4c/build/ir/ir-generated.h"
#line 112 "/root/p4c/ir/ir.def"
    void checkDuplicates() const;
#line 7547 "/root/p4c/build/ir/ir-generated.h"
#line 113 "/root/p4c/ir/ir.def"
    const IR::Type *getType() const override;
#line 7550 "/root/p4c/build/ir/ir-generated.h"
    IRNODE_DECLARE_APPLY_OVERLOAD(P4Parser)
#line 115 "/root/p4c/ir/ir.def"
    void validate() const override;
#line 7554 "/root/p4c/build/ir/ir-generated.h"
#line 124 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 7557 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P4Parser const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "P4Parser"_cs; }
    static cstring static_type_name() { return "P4Parser"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P4Parser(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), parserLocals(parserLocals), states(states)
    { validate(); }
    P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), parserLocals(parserLocals), states(states)
    { validate(); }
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(srcInfo, name), type(type), parserLocals(parserLocals), states(states)
    { validate(); }
    P4Parser(IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(name), type(type), parserLocals(parserLocals), states(states)
    { validate(); }
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), states(states)
    { validate(); }
    P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), states(states)
    { validate(); }
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(srcInfo, name), type(type), states(states)
    { validate(); }
    P4Parser(IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(name), type(type), states(states)
    { validate(); }
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), parserLocals(parserLocals)
    { validate(); }
    P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), parserLocals(parserLocals)
    { validate(); }
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals) :
    Type_Declaration(srcInfo, name), type(type), parserLocals(parserLocals)
    { validate(); }
    P4Parser(IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals) :
    Type_Declaration(name), type(type), parserLocals(parserLocals)
    { validate(); }
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams)
    { validate(); }
    P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams) :
    Type_Declaration(name), type(type), constructorParams(constructorParams)
    { validate(); }
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type) :
    Type_Declaration(srcInfo, name), type(type)
    { validate(); }
    P4Parser(IR::ID name, const IR::Type_Parser* type) :
    Type_Declaration(name), type(type)
    { validate(); }
    IRNODE_SUBCLASS(P4Parser)
    DECLARE_TYPEINFO_WITH_TYPEID(P4Parser, NodeKind::P4Parser, Type_Declaration, INestedNamespace, ISimpleNamespace, IApply, IContainer, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class P4Control : public Type_Declaration, public virtual INestedNamespace, public virtual ISimpleNamespace, public virtual IApply, public virtual IContainer, public virtual IAnnotated {
 public:
    const IR::Type_Control* type = nullptr;
    const IR::ParameterList* constructorParams = new ParameterList;
    IR::IndexedVector<IR::Declaration> controlLocals;
    const IR::BlockStatement* body = nullptr;
#line 133 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 7632 "/root/p4c/build/ir/ir-generated.h"
#line 134 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 7635 "/root/p4c/build/ir/ir-generated.h"
#line 135 "/root/p4c/ir/ir.def"
    const IR::TypeParameters *getTypeParameters() const override;
#line 7638 "/root/p4c/build/ir/ir-generated.h"
#line 136 "/root/p4c/ir/ir.def"
    std::vector<const IR::INamespace *> getNestedNamespaces() const override;
#line 7641 "/root/p4c/build/ir/ir-generated.h"
#line 138 "/root/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 7644 "/root/p4c/build/ir/ir-generated.h"
#line 140 "/root/p4c/ir/ir.def"
    const IR::Type_Method *getApplyMethodType() const override;
#line 7647 "/root/p4c/build/ir/ir-generated.h"
#line 141 "/root/p4c/ir/ir.def"
    const IR::ParameterList *getApplyParameters() const override;
#line 7650 "/root/p4c/build/ir/ir-generated.h"
#line 142 "/root/p4c/ir/ir.def"
    const IR::Type_Method *getConstructorMethodType() const override;
#line 7653 "/root/p4c/build/ir/ir-generated.h"
#line 143 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 7656 "/root/p4c/build/ir/ir-generated.h"
#line 145 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 7659 "/root/p4c/build/ir/ir-generated.h"
#line 147 "/root/p4c/ir/ir.def"
    const IR::ParameterList *getConstructorParameters() const override;
#line 7662 "/root/p4c/build/ir/ir-generated.h"
#line 148 "/root/p4c/ir/ir.def"
    const IR::Type *getType() const override;
#line 7665 "/root/p4c/build/ir/ir-generated.h"
    IRNODE_DECLARE_APPLY_OVERLOAD(P4Control)
#line 150 "/root/p4c/ir/ir.def"
    void validate() const override;
#line 7669 "/root/p4c/build/ir/ir-generated.h"
#line 155 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 7672 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P4Control const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "P4Control"_cs; }
    static cstring static_type_name() { return "P4Control"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P4Control(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), controlLocals(controlLocals), body(body)
    { validate(); }
    P4Control(IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), controlLocals(controlLocals), body(body)
    { validate(); }
    P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body) :
    Type_Declaration(srcInfo, name), type(type), controlLocals(controlLocals), body(body)
    { validate(); }
    P4Control(IR::ID name, const IR::Type_Control* type, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body) :
    Type_Declaration(name), type(type), controlLocals(controlLocals), body(body)
    { validate(); }
    P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, const IR::BlockStatement* body) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), body(body)
    { validate(); }
    P4Control(IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, const IR::BlockStatement* body) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), body(body)
    { validate(); }
    P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, const IR::BlockStatement* body) :
    Type_Declaration(srcInfo, name), type(type), body(body)
    { validate(); }
    P4Control(IR::ID name, const IR::Type_Control* type, const IR::BlockStatement* body) :
    Type_Declaration(name), type(type), body(body)
    { validate(); }
    IRNODE_SUBCLASS(P4Control)
    DECLARE_TYPEINFO_WITH_TYPEID(P4Control, NodeKind::P4Control, Type_Declaration, INestedNamespace, ISimpleNamespace, IApply, IContainer, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
/// A P4-16 action
class P4Action : public Declaration, public virtual ISimpleNamespace, public virtual IAnnotated, public virtual IFunctional {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::ParameterList* parameters = nullptr;
    const IR::BlockStatement* body = nullptr;
#line 163 "/root/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 7723 "/root/p4c/build/ir/ir-generated.h"
#line 165 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 7726 "/root/p4c/build/ir/ir-generated.h"
#line 167 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 7729 "/root/p4c/build/ir/ir-generated.h"
#line 169 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 7732 "/root/p4c/build/ir/ir-generated.h"
#line 170 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 7735 "/root/p4c/build/ir/ir-generated.h"
#line 171 "/root/p4c/ir/ir.def"
    const IR::ParameterList *getParameters() const override;
#line 7738 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P4Action const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "P4Action"_cs; }
    static cstring static_type_name() { return "P4Action"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P4Action(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    P4Action(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(srcInfo, name), annotations(annotations), parameters(parameters), body(body)
    { validate(); }
    P4Action(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(name), annotations(annotations), parameters(parameters), body(body)
    { validate(); }
    P4Action(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(srcInfo, name), parameters(parameters), body(body)
    { validate(); }
    P4Action(IR::ID name, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(name), parameters(parameters), body(body)
    { validate(); }
    IRNODE_SUBCLASS(P4Action)
    DECLARE_TYPEINFO_WITH_TYPEID(P4Action, NodeKind::P4Action, Declaration, ISimpleNamespace, IAnnotated, IFunctional);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Error : public virtual ISimpleNamespace, public Type_Declaration {
 public:
    static const cstring error;
    IR::IndexedVector<IR::Declaration_ID> members;
#line 177 "/root/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 7776 "/root/p4c/build/ir/ir-generated.h"
#line 179 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 7779 "/root/p4c/build/ir/ir-generated.h"
#line 181 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 7782 "/root/p4c/build/ir/ir-generated.h"
#line 183 "/root/p4c/ir/ir.def"
    void validate() const override;
#line 7785 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Error const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Type_Error"_cs; }
    static cstring static_type_name() { return "Type_Error"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Error(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Error(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(srcInfo, name), members(members)
    { validate(); }
    Type_Error(IR::ID name, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(name), members(members)
    { validate(); }
    Type_Error(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
    Type_Error(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
    IRNODE_SUBCLASS(Type_Error)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Error, NodeKind::Type_Error, ISimpleNamespace, Type_Declaration);
};
}  // namespace P4::IR
namespace P4::IR {

class Declaration_MatchKind : public Node, public virtual ISimpleNamespace {
 public:
    IR::IndexedVector<IR::Declaration_ID> members;
#line 189 "/root/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 7822 "/root/p4c/build/ir/ir-generated.h"
#line 191 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 7825 "/root/p4c/build/ir/ir-generated.h"
#line 193 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 7828 "/root/p4c/build/ir/ir-generated.h"
#line 195 "/root/p4c/ir/ir.def"
    void validate() const override;
#line 7831 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Declaration_MatchKind const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Declaration_MatchKind"_cs; }
    static cstring static_type_name() { return "Declaration_MatchKind"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Declaration_MatchKind(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    Declaration_MatchKind(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Declaration_ID> members) :
    Node(srcInfo), members(members)
    { validate(); }
    Declaration_MatchKind(IR::IndexedVector<IR::Declaration_ID> members) :
    members(members)
    { validate(); }
    Declaration_MatchKind(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    Declaration_MatchKind() 
    { validate(); }
    IRNODE_SUBCLASS(Declaration_MatchKind)
    DECLARE_TYPEINFO_WITH_TYPEID(Declaration_MatchKind, NodeKind::Declaration_MatchKind, Node, ISimpleNamespace);
};
}  // namespace P4::IR
namespace P4::IR {
/// Table property value abstract base class
class PropertyValue : public Node {
 public:
    bool operator==(IR::PropertyValue const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "PropertyValue"_cs; }
    static cstring static_type_name() { return "PropertyValue"_cs; }
    void toJSON(JSONGenerator & json) const override;
    PropertyValue(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
 protected:
    PropertyValue(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    PropertyValue() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(PropertyValue)
    DECLARE_TYPEINFO_WITH_TYPEID(PropertyValue, NodeKind::PropertyValue, Node);
};
}  // namespace P4::IR
namespace P4::IR {
/// A table property whose value is an expression
class ExpressionValue : public PropertyValue {
 public:
    const IR::Expression* expression = nullptr;
#line 204 "/root/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 7886 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ExpressionValue const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ExpressionValue"_cs; }
    static cstring static_type_name() { return "ExpressionValue"_cs; }
    void toJSON(JSONGenerator & json) const override;
    ExpressionValue(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::PropertyValue const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ExpressionValue(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    PropertyValue(srcInfo), expression(expression)
    { validate(); }
    ExpressionValue(const IR::Expression* expression) :
    expression(expression)
    { validate(); }
    IRNODE_SUBCLASS(ExpressionValue)
    DECLARE_TYPEINFO_WITH_TYPEID(ExpressionValue, NodeKind::ExpressionValue, PropertyValue);
};
}  // namespace P4::IR
namespace P4::IR {
class ExpressionListValue : public PropertyValue {
 public:
    IR::Vector<IR::Expression> expressions;
#line 209 "/root/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 7915 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ExpressionListValue const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ExpressionListValue"_cs; }
    static cstring static_type_name() { return "ExpressionListValue"_cs; }
    void toJSON(JSONGenerator & json) const override;
    ExpressionListValue(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::PropertyValue const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ExpressionListValue(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> expressions) :
    PropertyValue(srcInfo), expressions(expressions)
    { validate(); }
    ExpressionListValue(IR::Vector<IR::Expression> expressions) :
    expressions(expressions)
    { validate(); }
    IRNODE_SUBCLASS(ExpressionListValue)
    DECLARE_TYPEINFO_WITH_TYPEID(ExpressionListValue, NodeKind::ExpressionListValue, PropertyValue);
};
}  // namespace P4::IR
namespace P4::IR {

class ActionListElement : public Node, public virtual IAnnotated, public virtual IDeclaration {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::Expression* expression = nullptr;

#line 216 "/root/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 7947 "/root/p4c/build/ir/ir-generated.h"
#line 217 "/root/p4c/ir/ir.def"
    IR::ID getName() const override;
#line 7950 "/root/p4c/build/ir/ir-generated.h"
#line 218 "/root/p4c/ir/ir.def"
    const IR::Path *getPath() const;
#line 7953 "/root/p4c/build/ir/ir-generated.h"
#line 219 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 7956 "/root/p4c/build/ir/ir-generated.h"
#line 220 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 7959 "/root/p4c/build/ir/ir-generated.h"
#line 221 "/root/p4c/ir/ir.def"
    void validate() const override;
#line 7962 "/root/p4c/build/ir/ir-generated.h"
#line 226 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 7965 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ActionListElement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "ActionListElement"_cs; }
    static cstring static_type_name() { return "ActionListElement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    ActionListElement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    ActionListElement(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, const IR::Expression* expression) :
    Node(srcInfo), annotations(annotations), expression(expression)
    { validate(); }
    ActionListElement(IR::Vector<IR::Annotation> annotations, const IR::Expression* expression) :
    annotations(annotations), expression(expression)
    { validate(); }
    ActionListElement(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    Node(srcInfo), expression(expression)
    { validate(); }
    ActionListElement(const IR::Expression* expression) :
    expression(expression)
    { validate(); }
    IRNODE_SUBCLASS(ActionListElement)
    DECLARE_TYPEINFO_WITH_TYPEID(ActionListElement, NodeKind::ActionListElement, Node, IAnnotated, IDeclaration);
};
}  // namespace P4::IR
namespace P4::IR {

class ActionList : public PropertyValue {
 public:
    IR::IndexedVector<IR::ActionListElement> actionList;
#line 232 "/root/p4c/ir/ir.def"
    void validate() const override;
#line 7999 "/root/p4c/build/ir/ir-generated.h"
#line 233 "/root/p4c/ir/ir.def"
    size_t size() const { return actionList.size(); }
#line 8002 "/root/p4c/build/ir/ir-generated.h"
#line 234 "/root/p4c/ir/ir.def"
    void push_back(const IR::ActionListElement* e) { actionList.push_back(e); }
#line 8005 "/root/p4c/build/ir/ir-generated.h"
#line 235 "/root/p4c/ir/ir.def"
    const IR::ActionListElement *getDeclaration(cstring n) const {
        return actionList.getDeclaration<ActionListElement>(n); }
#line 8009 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ActionList const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "ActionList"_cs; }
    static cstring static_type_name() { return "ActionList"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ActionList(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::PropertyValue const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ActionList(Util::SourceInfo srcInfo, IR::IndexedVector<IR::ActionListElement> actionList) :
    PropertyValue(srcInfo), actionList(actionList)
    { validate(); }
    ActionList(IR::IndexedVector<IR::ActionListElement> actionList) :
    actionList(actionList)
    { validate(); }
    IRNODE_SUBCLASS(ActionList)
    DECLARE_TYPEINFO_WITH_TYPEID(ActionList, NodeKind::ActionList, PropertyValue);
};
}  // namespace P4::IR
namespace P4::IR {
class KeyElement : public Node, public virtual IAnnotated {
 public:
    const IR::Expression* expression = nullptr;
    const IR::PathExpression* matchType = nullptr;
    IR::Vector<IR::Annotation> annotations;
#line 244 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 8040 "/root/p4c/build/ir/ir-generated.h"
#line 245 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 8043 "/root/p4c/build/ir/ir-generated.h"
#line 246 "/root/p4c/ir/ir.def"
    IR::Node const * transform_visit(Transform & v);
#line 8046 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::KeyElement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "KeyElement"_cs; }
    static cstring static_type_name() { return "KeyElement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    KeyElement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    KeyElement(Util::SourceInfo srcInfo, const IR::Expression* expression, const IR::PathExpression* matchType, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), expression(expression), matchType(matchType), annotations(annotations)
    { validate(); }
    KeyElement(const IR::Expression* expression, const IR::PathExpression* matchType, IR::Vector<IR::Annotation> annotations) :
    expression(expression), matchType(matchType), annotations(annotations)
    { validate(); }
    KeyElement(Util::SourceInfo srcInfo, const IR::Expression* expression, const IR::PathExpression* matchType) :
    Node(srcInfo), expression(expression), matchType(matchType)
    { validate(); }
    KeyElement(const IR::Expression* expression, const IR::PathExpression* matchType) :
    expression(expression), matchType(matchType)
    { validate(); }
    IRNODE_SUBCLASS(KeyElement)
    DECLARE_TYPEINFO_WITH_TYPEID(KeyElement, NodeKind::KeyElement, Node, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {

class Key : public PropertyValue {
 public:
    IR::Vector<IR::KeyElement> keyElements;
#line 269 "/root/p4c/ir/ir.def"
    void validate() const override;
#line 8082 "/root/p4c/build/ir/ir-generated.h"
#line 270 "/root/p4c/ir/ir.def"
    void push_back(const IR::KeyElement* ke) { keyElements.push_back(ke); }
#line 8085 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Key const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Key"_cs; }
    static cstring static_type_name() { return "Key"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Key(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::PropertyValue const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Key(Util::SourceInfo srcInfo, IR::Vector<IR::KeyElement> keyElements) :
    PropertyValue(srcInfo), keyElements(keyElements)
    { validate(); }
    Key(IR::Vector<IR::KeyElement> keyElements) :
    keyElements(keyElements)
    { validate(); }
    IRNODE_SUBCLASS(Key)
    DECLARE_TYPEINFO_WITH_TYPEID(Key, NodeKind::Key, PropertyValue);
};
}  // namespace P4::IR
namespace P4::IR {
/// Pre-defined entry in a table
class Entry : public Node, public virtual IAnnotated {
 public:
/// annotations are optional (supported annotations: @priority(value))
    IR::Vector<IR::Annotation> annotations;
    bool isConst;
/// optional const annotation
    const IR::Expression* priority = nullptr;
/// optional entry priority
    const IR::ListExpression* keys = nullptr;
/// must be a tuple expression
    const IR::Expression* action = nullptr;
/// typically a MethodCallExpression.
/// The action must be defined in action list
    bool singleton;
/// True if the entry is not a list.
#line 284 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 8127 "/root/p4c/build/ir/ir-generated.h"
#line 285 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 8130 "/root/p4c/build/ir/ir-generated.h"
#line 286 "/root/p4c/ir/ir.def"
    const IR::ListExpression *getKeys() const { return keys; }
#line 8133 "/root/p4c/build/ir/ir-generated.h"
#line 287 "/root/p4c/ir/ir.def"
    const IR::Expression *getAction() const { return action; }
#line 8136 "/root/p4c/build/ir/ir-generated.h"
#line 288 "/root/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 8139 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Entry const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Entry"_cs; }
    static cstring static_type_name() { return "Entry"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Entry(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    Entry(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, bool isConst, const IR::Expression* priority, const IR::ListExpression* keys, const IR::Expression* action, bool singleton) :
    Node(srcInfo), annotations(annotations), isConst(isConst), priority(priority), keys(keys), action(action), singleton(singleton)
    { validate(); }
    Entry(IR::Vector<IR::Annotation> annotations, bool isConst, const IR::Expression* priority, const IR::ListExpression* keys, const IR::Expression* action, bool singleton) :
    annotations(annotations), isConst(isConst), priority(priority), keys(keys), action(action), singleton(singleton)
    { validate(); }
    Entry(Util::SourceInfo srcInfo, bool isConst, const IR::Expression* priority, const IR::ListExpression* keys, const IR::Expression* action, bool singleton) :
    Node(srcInfo), isConst(isConst), priority(priority), keys(keys), action(action), singleton(singleton)
    { validate(); }
    Entry(bool isConst, const IR::Expression* priority, const IR::ListExpression* keys, const IR::Expression* action, bool singleton) :
    isConst(isConst), priority(priority), keys(keys), action(action), singleton(singleton)
    { validate(); }
    IRNODE_SUBCLASS(Entry)
    DECLARE_TYPEINFO_WITH_TYPEID(Entry, NodeKind::Entry, Node, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
/// List of predefined entries. Part of table properties
class EntriesList : public PropertyValue {
 public:
    IR::Vector<IR::Entry> entries;
#line 294 "/root/p4c/ir/ir.def"
    size_t size() const { return entries.size(); }
#line 8175 "/root/p4c/build/ir/ir-generated.h"
#line 295 "/root/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 8178 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::EntriesList const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "EntriesList"_cs; }
    static cstring static_type_name() { return "EntriesList"_cs; }
    void toJSON(JSONGenerator & json) const override;
    EntriesList(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::PropertyValue const & a) const override;
    bool operator==(IR::Node const & a) const override;
    EntriesList(Util::SourceInfo srcInfo, IR::Vector<IR::Entry> entries) :
    PropertyValue(srcInfo), entries(entries)
    { validate(); }
    EntriesList(IR::Vector<IR::Entry> entries) :
    entries(entries)
    { validate(); }
    IRNODE_SUBCLASS(EntriesList)
    DECLARE_TYPEINFO_WITH_TYPEID(EntriesList, NodeKind::EntriesList, PropertyValue);
};
}  // namespace P4::IR
namespace P4::IR {
class Property : public Declaration, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::PropertyValue* value = nullptr;
    bool isConstant;
#line 302 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 8209 "/root/p4c/build/ir/ir-generated.h"
#line 303 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 8212 "/root/p4c/build/ir/ir-generated.h"
#line 304 "/root/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 8215 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Property const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Property"_cs; }
    static cstring static_type_name() { return "Property"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Property(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Property(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::PropertyValue* value, bool isConstant) :
    Declaration(srcInfo, name), annotations(annotations), value(value), isConstant(isConstant)
    { validate(); }
    Property(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::PropertyValue* value, bool isConstant) :
    Declaration(name), annotations(annotations), value(value), isConstant(isConstant)
    { validate(); }
    Property(Util::SourceInfo srcInfo, IR::ID name, const IR::PropertyValue* value, bool isConstant) :
    Declaration(srcInfo, name), value(value), isConstant(isConstant)
    { validate(); }
    Property(IR::ID name, const IR::PropertyValue* value, bool isConstant) :
    Declaration(name), value(value), isConstant(isConstant)
    { validate(); }
    IRNODE_SUBCLASS(Property)
    DECLARE_TYPEINFO_WITH_TYPEID(Property, NodeKind::Property, Declaration, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class TableProperties : public Node, public virtual ISimpleNamespace {
 public:
    IR::IndexedVector<IR::Property> properties;
#line 309 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 8252 "/root/p4c/build/ir/ir-generated.h"
#line 310 "/root/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 8255 "/root/p4c/build/ir/ir-generated.h"
#line 312 "/root/p4c/ir/ir.def"
    const IR::Property *getProperty(cstring name) const {
        return properties.getDeclaration<Property>(name); }
#line 8259 "/root/p4c/build/ir/ir-generated.h"
#line 314 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 8262 "/root/p4c/build/ir/ir-generated.h"
#line 316 "/root/p4c/ir/ir.def"
    const IR::Property *getProperty(std::string_view name) const {
        return properties.getDeclaration<Property>(name); }
#line 8266 "/root/p4c/build/ir/ir-generated.h"
#line 318 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 8269 "/root/p4c/build/ir/ir-generated.h"
#line 320 "/root/p4c/ir/ir.def"
    void push_back(const IR::Property* prop) { properties.push_back(prop); }
#line 8272 "/root/p4c/build/ir/ir-generated.h"
    static const cstring actionsPropertyName;
    static const cstring keyPropertyName;
    static const cstring defaultActionPropertyName;
    static const cstring entriesPropertyName;
    static const cstring sizePropertyName;
#line 328 "/root/p4c/ir/ir.def"
    void validate() const override;
#line 8280 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TableProperties const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "TableProperties"_cs; }
    static cstring static_type_name() { return "TableProperties"_cs; }
    void toJSON(JSONGenerator & json) const override;
    TableProperties(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    TableProperties(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Property> properties) :
    Node(srcInfo), properties(properties)
    { validate(); }
    TableProperties(IR::IndexedVector<IR::Property> properties) :
    properties(properties)
    { validate(); }
    TableProperties(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    TableProperties() 
    { validate(); }
    IRNODE_SUBCLASS(TableProperties)
    DECLARE_TYPEINFO_WITH_TYPEID(TableProperties, NodeKind::TableProperties, Node, ISimpleNamespace);
};
}  // namespace P4::IR
namespace P4::IR {
class P4Table : public Declaration, public virtual IAnnotated, public virtual IApply {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::TableProperties* properties = nullptr;
#line 335 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 8313 "/root/p4c/build/ir/ir-generated.h"
#line 336 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 8316 "/root/p4c/build/ir/ir-generated.h"
#line 337 "/root/p4c/ir/ir.def"
    const IR::Type_Method *getApplyMethodType() const override;
#line 8319 "/root/p4c/build/ir/ir-generated.h"
#line 338 "/root/p4c/ir/ir.def"
    const IR::ParameterList *getApplyParameters() const override;
#line 8322 "/root/p4c/build/ir/ir-generated.h"
#line 339 "/root/p4c/ir/ir.def"
    const IR::ActionList *getActionList() const {
        if (auto ap = properties->getProperty(TableProperties::actionsPropertyName)) {
            if (auto al = ap->value->to<IR::ActionList>()) return al;
            ::P4::error(ErrorType::ERR_INVALID, "%1%: must be an action list", ap);
        }
        return nullptr;
    }
#line 8331 "/root/p4c/build/ir/ir-generated.h"
#line 346 "/root/p4c/ir/ir.def"
    const IR::Key *getKey() const {
        if (auto kp = properties->getProperty(TableProperties::keyPropertyName)) {
            if (auto k = kp->value->to<IR::Key>()) return k;
            ::P4::error(ErrorType::ERR_INVALID, "%1%: must be a key", kp);
        }
        return nullptr;
    }
#line 8340 "/root/p4c/build/ir/ir-generated.h"
#line 353 "/root/p4c/ir/ir.def"
    const IR::Expression *getDefaultAction() const {
        if (auto d = properties->getProperty(TableProperties::defaultActionPropertyName)) {
            if (auto ev = d->value->to<IR::ExpressionValue>()) return ev->expression;
            ::P4::error(ErrorType::ERR_INVALID, "%1%: must be an expression", d);
        }
        return nullptr;
    }
#line 8349 "/root/p4c/build/ir/ir-generated.h"
#line 360 "/root/p4c/ir/ir.def"
    const IR::Constant *getConstantProperty(cstring name) const {
        if (auto d = properties->getProperty(name)) {
            if (auto ev = d->value->to<IR::ExpressionValue>()) {
                if (auto k = ev->expression->to<IR::Constant>()) {
                    return k; } }
            error(ErrorType::ERR_INVALID, "%1% must be a constant numeric expression", d); }
        return nullptr; }
#line 8358 "/root/p4c/build/ir/ir-generated.h"
#line 367 "/root/p4c/ir/ir.def"
    const IR::BoolLiteral *getBooleanProperty(cstring name) const {
        if (auto d = properties->getProperty(name)) {
            if (auto ev = d->value->to<IR::ExpressionValue>()) {
                if (auto k = ev->expression->to<IR::BoolLiteral>()) {
                    return k; } }
            error(ErrorType::ERR_INVALID, "%1% must be a boolean expression", d); }
        return nullptr; }
#line 8367 "/root/p4c/build/ir/ir-generated.h"
#line 374 "/root/p4c/ir/ir.def"
    const IR::Constant *getSizeProperty() const {
        return getConstantProperty(TableProperties::sizePropertyName);
    }
#line 8372 "/root/p4c/build/ir/ir-generated.h"
#line 377 "/root/p4c/ir/ir.def"
    const IR::EntriesList *getEntries() const {
        if (auto ep = properties->getProperty(TableProperties::entriesPropertyName)) {
            if (auto el = ep->value->to<IR::EntriesList>()) return el;
            ::P4::error(ErrorType::ERR_INVALID, "%1%: must be a list of entries", ep);
        }
        return nullptr;
    }
#line 8381 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P4Table const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "P4Table"_cs; }
    static cstring static_type_name() { return "P4Table"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P4Table(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    P4Table(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TableProperties* properties) :
    Declaration(srcInfo, name), annotations(annotations), properties(properties)
    { validate(); }
    P4Table(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TableProperties* properties) :
    Declaration(name), annotations(annotations), properties(properties)
    { validate(); }
    P4Table(Util::SourceInfo srcInfo, IR::ID name, const IR::TableProperties* properties) :
    Declaration(srcInfo, name), properties(properties)
    { validate(); }
    P4Table(IR::ID name, const IR::TableProperties* properties) :
    Declaration(name), properties(properties)
    { validate(); }
    IRNODE_SUBCLASS(P4Table)
    DECLARE_TYPEINFO_WITH_TYPEID(P4Table, NodeKind::P4Table, Declaration, IAnnotated, IApply);
};
}  // namespace P4::IR
namespace P4::IR {
class P4ValueSet : public Declaration, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::Type* elementType = nullptr;
    const IR::Expression* size = nullptr;

#line 390 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 8421 "/root/p4c/build/ir/ir-generated.h"
#line 391 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 8424 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P4ValueSet const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "P4ValueSet"_cs; }
    static cstring static_type_name() { return "P4ValueSet"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P4ValueSet(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    P4ValueSet(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* elementType, const IR::Expression* size) :
    Declaration(srcInfo, name), annotations(annotations), elementType(elementType), size(size)
    { validate(); }
    P4ValueSet(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* elementType, const IR::Expression* size) :
    Declaration(name), annotations(annotations), elementType(elementType), size(size)
    { validate(); }
    P4ValueSet(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* elementType, const IR::Expression* size) :
    Declaration(srcInfo, name), elementType(elementType), size(size)
    { validate(); }
    P4ValueSet(IR::ID name, const IR::Type* elementType, const IR::Expression* size) :
    Declaration(name), elementType(elementType), size(size)
    { validate(); }
    IRNODE_SUBCLASS(P4ValueSet)
    DECLARE_TYPEINFO_WITH_TYPEID(P4ValueSet, NodeKind::P4ValueSet, Declaration, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class Declaration_Variable : public Declaration, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::Type* type = nullptr;
    const IR::Expression* initializer = nullptr;
#line 399 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 8463 "/root/p4c/build/ir/ir-generated.h"
#line 400 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 8466 "/root/p4c/build/ir/ir-generated.h"
#line 401 "/root/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 8469 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Declaration_Variable const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Declaration_Variable"_cs; }
    static cstring static_type_name() { return "Declaration_Variable"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Declaration_Variable(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(srcInfo, name), annotations(annotations), type(type), initializer(initializer)
    { validate(); }
    Declaration_Variable(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(name), annotations(annotations), type(type), initializer(initializer)
    { validate(); }
    Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(srcInfo, name), type(type), initializer(initializer)
    { validate(); }
    Declaration_Variable(IR::ID name, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(name), type(type), initializer(initializer)
    { validate(); }
    Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type) :
    Declaration(srcInfo, name), annotations(annotations), type(type)
    { validate(); }
    Declaration_Variable(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type) :
    Declaration(name), annotations(annotations), type(type)
    { validate(); }
    Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type) :
    Declaration(srcInfo, name), type(type)
    { validate(); }
    Declaration_Variable(IR::ID name, const IR::Type* type) :
    Declaration(name), type(type)
    { validate(); }
    IRNODE_SUBCLASS(Declaration_Variable)
    DECLARE_TYPEINFO_WITH_TYPEID(Declaration_Variable, NodeKind::Declaration_Variable, Declaration, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class Declaration_Constant : public Declaration, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::Type* type = nullptr;
    const IR::Expression* initializer = nullptr;
#line 411 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 8519 "/root/p4c/build/ir/ir-generated.h"
#line 412 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 8522 "/root/p4c/build/ir/ir-generated.h"
#line 413 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 8525 "/root/p4c/build/ir/ir-generated.h"
#line 414 "/root/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 8528 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Declaration_Constant const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Declaration_Constant"_cs; }
    static cstring static_type_name() { return "Declaration_Constant"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Declaration_Constant(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Declaration_Constant(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(srcInfo, name), annotations(annotations), type(type), initializer(initializer)
    { validate(); }
    Declaration_Constant(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(name), annotations(annotations), type(type), initializer(initializer)
    { validate(); }
    Declaration_Constant(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(srcInfo, name), type(type), initializer(initializer)
    { validate(); }
    Declaration_Constant(IR::ID name, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(name), type(type), initializer(initializer)
    { validate(); }
    IRNODE_SUBCLASS(Declaration_Constant)
    DECLARE_TYPEINFO_WITH_TYPEID(Declaration_Constant, NodeKind::Declaration_Constant, Declaration, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
/// Like a variable, but for a statically allocated instance.
/// The syntax is Contructor(args) name = initializer;
/// Initializers are an experimental features, used for externs with
/// abstract methods.
class Declaration_Instance : public Declaration, public virtual IAnnotated, public virtual IInstance {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::Type* type = nullptr;

    const IR::Vector<IR::Argument>* arguments = nullptr;
    IR::NameMap<IR::Property> properties = {};

    const IR::BlockStatement* initializer = nullptr;

#line 429 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 8575 "/root/p4c/build/ir/ir-generated.h"
#line 430 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 8578 "/root/p4c/build/ir/ir-generated.h"
#line 431 "/root/p4c/ir/ir.def"
    const IR::Type *getType() const override;
#line 8581 "/root/p4c/build/ir/ir-generated.h"
#line 432 "/root/p4c/ir/ir.def"
    IR::ID Name() const override;
#line 8584 "/root/p4c/build/ir/ir-generated.h"
#line 433 "/root/p4c/ir/ir.def"
    void validate() const override;
#line 8587 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Declaration_Instance const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Declaration_Instance"_cs; }
    static cstring static_type_name() { return "Declaration_Instance"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Declaration_Instance(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration(srcInfo, name), annotations(annotations), type(type), arguments(arguments), initializer(initializer)
    { validate(); }
    Declaration_Instance(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration(name), annotations(annotations), type(type), arguments(arguments), initializer(initializer)
    { validate(); }
    Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration(srcInfo, name), type(type), arguments(arguments), initializer(initializer)
    { validate(); }
    Declaration_Instance(IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration(name), type(type), arguments(arguments), initializer(initializer)
    { validate(); }
    Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration(srcInfo, name), annotations(annotations), type(type), arguments(arguments)
    { validate(); }
    Declaration_Instance(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration(name), annotations(annotations), type(type), arguments(arguments)
    { validate(); }
    Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration(srcInfo, name), type(type), arguments(arguments)
    { validate(); }
    Declaration_Instance(IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration(name), type(type), arguments(arguments)
    { validate(); }
    IRNODE_SUBCLASS(Declaration_Instance)
    DECLARE_TYPEINFO_WITH_TYPEID(Declaration_Instance, NodeKind::Declaration_Instance, Declaration, IAnnotated, IInstance);
};
}  // namespace P4::IR
namespace P4::IR {
/// Toplevel program representation
class P4Program : public Node, public virtual IGeneralNamespace {
 public:
/// Top-level program objects.
/// This is not an IndexedVector because:
/// - we allow overloaded function-like objects.
/// - not all objects in a P4Program are declarations (e.g., match_kind is not).
    IR::Vector<IR::Node> objects;
#line 443 "/root/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 8640 "/root/p4c/build/ir/ir-generated.h"
#line 444 "/root/p4c/ir/ir.def"
    void validate() const override;
#line 8643 "/root/p4c/build/ir/ir-generated.h"
    static const cstring main;
    IRNODE_DECLARE_APPLY_OVERLOAD(P4Program)
    bool operator==(IR::P4Program const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "P4Program"_cs; }
    static cstring static_type_name() { return "P4Program"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P4Program(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    P4Program(Util::SourceInfo srcInfo, IR::Vector<IR::Node> objects) :
    Node(srcInfo), objects(objects)
    { validate(); }
    P4Program(IR::Vector<IR::Node> objects) :
    objects(objects)
    { validate(); }
    P4Program(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    P4Program() 
    { validate(); }
    IRNODE_SUBCLASS(P4Program)
    DECLARE_TYPEINFO_WITH_TYPEID(P4Program, NodeKind::P4Program, Node, IGeneralNamespace);
};
}  // namespace P4::IR
namespace P4::IR {
class ExitStatement : public Statement {
 public:
#line 456 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 8677 "/root/p4c/build/ir/ir-generated.h"
#line 457 "/root/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 8680 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ExitStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ExitStatement"_cs; }
    static cstring static_type_name() { return "ExitStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    ExitStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ExitStatement(Util::SourceInfo srcInfo) :
    Statement(srcInfo)
    { validate(); }
    ExitStatement() 
    { validate(); }
    IRNODE_SUBCLASS(ExitStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(ExitStatement, NodeKind::ExitStatement, Statement);
};
}  // namespace P4::IR
namespace P4::IR {
class ReturnStatement : public Statement {
 public:
    const IR::Expression* expression = nullptr;
#line 462 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 8706 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ReturnStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "ReturnStatement"_cs; }
    static cstring static_type_name() { return "ReturnStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ReturnStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ReturnStatement(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    Statement(srcInfo), expression(expression)
    { validate(); }
    ReturnStatement(const IR::Expression* expression) :
    expression(expression)
    { validate(); }
    IRNODE_SUBCLASS(ReturnStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(ReturnStatement, NodeKind::ReturnStatement, Statement);
};
}  // namespace P4::IR
namespace P4::IR {
class EmptyStatement : public Statement {
 public:
#line 468 "/root/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 8735 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::EmptyStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "EmptyStatement"_cs; }
    static cstring static_type_name() { return "EmptyStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    EmptyStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    EmptyStatement(Util::SourceInfo srcInfo) :
    Statement(srcInfo)
    { validate(); }
    EmptyStatement() 
    { validate(); }
    IRNODE_SUBCLASS(EmptyStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(EmptyStatement, NodeKind::EmptyStatement, Statement);
};
}  // namespace P4::IR
namespace P4::IR {
class AssignmentStatement : public BaseAssignmentStatement {
 public:
#line 477 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 8760 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::AssignmentStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "AssignmentStatement"_cs; }
    static cstring static_type_name() { return "AssignmentStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    AssignmentStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::BaseAssignmentStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    AssignmentStatement(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    BaseAssignmentStatement(srcInfo, left, right)
    { validate(); }
    AssignmentStatement(const IR::Expression* left, const IR::Expression* right) :
    BaseAssignmentStatement(left, right)
    { validate(); }
    IRNODE_SUBCLASS(AssignmentStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(AssignmentStatement, NodeKind::AssignmentStatement, BaseAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class IfStatement : public Statement {
 public:
    const IR::Expression* condition = nullptr;
    const IR::Statement* ifTrue = nullptr;
    const IR::Statement* ifFalse = nullptr;
#line 490 "/root/p4c/ir/ir.def"
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
#line 8792 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::IfStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "IfStatement"_cs; }
    static cstring static_type_name() { return "IfStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    IfStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IfStatement(Util::SourceInfo srcInfo, const IR::Expression* condition, const IR::Statement* ifTrue, const IR::Statement* ifFalse) :
    Statement(srcInfo), condition(condition), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
    IfStatement(const IR::Expression* condition, const IR::Statement* ifTrue, const IR::Statement* ifFalse) :
    condition(condition), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
    IRNODE_SUBCLASS(IfStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(IfStatement, NodeKind::IfStatement, Statement);
};
}  // namespace P4::IR
namespace P4::IR {
class BreakStatement : public Statement {
 public:
#line 497 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 8820 "/root/p4c/build/ir/ir-generated.h"
#line 498 "/root/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 8823 "/root/p4c/build/ir/ir-generated.h"
#line 499 "/root/p4c/ir/ir.def"
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
#line 8827 "/root/p4c/build/ir/ir-generated.h"

    bool operator==(IR::BreakStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "BreakStatement"_cs; }
    static cstring static_type_name() { return "BreakStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    BreakStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    BreakStatement(Util::SourceInfo srcInfo) :
    Statement(srcInfo)
    { validate(); }
    BreakStatement() 
    { validate(); }
    IRNODE_SUBCLASS(BreakStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(BreakStatement, NodeKind::BreakStatement, Statement);
};
}  // namespace P4::IR
namespace P4::IR {
class ContinueStatement : public Statement {
 public:
#line 503 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 8853 "/root/p4c/build/ir/ir-generated.h"
#line 504 "/root/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 8856 "/root/p4c/build/ir/ir-generated.h"
#line 505 "/root/p4c/ir/ir.def"
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
#line 8860 "/root/p4c/build/ir/ir-generated.h"

    bool operator==(IR::ContinueStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ContinueStatement"_cs; }
    static cstring static_type_name() { return "ContinueStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    ContinueStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ContinueStatement(Util::SourceInfo srcInfo) :
    Statement(srcInfo)
    { validate(); }
    ContinueStatement() 
    { validate(); }
    IRNODE_SUBCLASS(ContinueStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(ContinueStatement, NodeKind::ContinueStatement, Statement);
};
}  // namespace P4::IR
namespace P4::IR {
class BlockStatement : public Statement, public virtual ISimpleNamespace, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    IR::IndexedVector<IR::StatOrDecl> components;
#line 511 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 8888 "/root/p4c/build/ir/ir-generated.h"
#line 513 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 8891 "/root/p4c/build/ir/ir-generated.h"
#line 515 "/root/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 8894 "/root/p4c/build/ir/ir-generated.h"
#line 517 "/root/p4c/ir/ir.def"
    void push_back(const IR::StatOrDecl* st);
#line 8897 "/root/p4c/build/ir/ir-generated.h"
#line 518 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 8900 "/root/p4c/build/ir/ir-generated.h"
#line 519 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 8903 "/root/p4c/build/ir/ir-generated.h"
#line 520 "/root/p4c/ir/ir.def"
    bool empty() const { return components.empty(); }
#line 8906 "/root/p4c/build/ir/ir-generated.h"
#line 521 "/root/p4c/ir/ir.def"
    void append(const IR::StatOrDecl* stmt);
#line 8909 "/root/p4c/build/ir/ir-generated.h"
#line 522 "/root/p4c/ir/ir.def"
    BlockStatement(std::initializer_list<const IR::StatOrDecl *> il) { for (auto el : il) append(el); }
#line 8912 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::BlockStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "BlockStatement"_cs; }
    static cstring static_type_name() { return "BlockStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    BlockStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    BlockStatement(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StatOrDecl> components) :
    Statement(srcInfo), annotations(annotations), components(components)
    { validate(); }
    BlockStatement(IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StatOrDecl> components) :
    annotations(annotations), components(components)
    { validate(); }
    BlockStatement(Util::SourceInfo srcInfo, IR::IndexedVector<IR::StatOrDecl> components) :
    Statement(srcInfo), components(components)
    { validate(); }
    BlockStatement(IR::IndexedVector<IR::StatOrDecl> components) :
    components(components)
    { validate(); }
    BlockStatement(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Statement(srcInfo), annotations(annotations)
    { validate(); }
    BlockStatement(IR::Vector<IR::Annotation> annotations) :
    annotations(annotations)
    { validate(); }
    BlockStatement(Util::SourceInfo srcInfo) :
    Statement(srcInfo)
    { validate(); }
    BlockStatement() 
    { validate(); }
    IRNODE_SUBCLASS(BlockStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(BlockStatement, NodeKind::BlockStatement, Statement, ISimpleNamespace, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class MethodCallStatement : public Statement {
 public:
    const IR::MethodCallExpression* methodCall = nullptr;
#line 528 "/root/p4c/ir/ir.def"
    MethodCallStatement(Util::SourceInfo si, IR::ID m, std::initializer_list<const IR::Argument *> const & a) : Statement(si), methodCall(new MethodCallExpression(si, m, a)) {}
#line 8960 "/root/p4c/build/ir/ir-generated.h"
#line 530 "/root/p4c/ir/ir.def"
    MethodCallStatement(Util::SourceInfo si, const IR::Expression* m, std::initializer_list<const IR::Argument *> const & a) : Statement(si), methodCall(new MethodCallExpression(si, m, a)) {}
#line 8963 "/root/p4c/build/ir/ir-generated.h"
#line 533 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 8966 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::MethodCallStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "MethodCallStatement"_cs; }
    static cstring static_type_name() { return "MethodCallStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    MethodCallStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    MethodCallStatement(Util::SourceInfo srcInfo, const IR::MethodCallExpression* methodCall) :
    Statement(srcInfo), methodCall(methodCall)
    {
#line 527 "/root/p4c/ir/ir.def"
{ if (!srcInfo) srcInfo = methodCall->srcInfo; }
#line 8986 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    MethodCallStatement(const IR::MethodCallExpression* methodCall) :
    methodCall(methodCall)
    {
#line 527 "/root/p4c/ir/ir.def"
{ if (!srcInfo) srcInfo = methodCall->srcInfo; }
#line 8993 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(MethodCallStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(MethodCallStatement, NodeKind::MethodCallStatement, Statement);
};
}  // namespace P4::IR
namespace P4::IR {
class SwitchCase : public Node {
 public:
    const IR::Expression* label = nullptr;
    const IR::Statement* statement = nullptr;

#line 540 "/root/p4c/ir/ir.def"
    void validate() const override;
#line 9007 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::SwitchCase const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "SwitchCase"_cs; }
    static cstring static_type_name() { return "SwitchCase"_cs; }
    void toJSON(JSONGenerator & json) const override;
    SwitchCase(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    SwitchCase(Util::SourceInfo srcInfo, const IR::Expression* label, const IR::Statement* statement) :
    Node(srcInfo), label(label), statement(statement)
    { validate(); }
    SwitchCase(const IR::Expression* label, const IR::Statement* statement) :
    label(label), statement(statement)
    { validate(); }
    IRNODE_SUBCLASS(SwitchCase)
    DECLARE_TYPEINFO_WITH_TYPEID(SwitchCase, NodeKind::SwitchCase, Node);
};
}  // namespace P4::IR
namespace P4::IR {

class SwitchStatement : public Statement {
 public:
    const IR::Expression* expression = nullptr;
    IR::Vector<IR::SwitchCase> cases;
#line 552 "/root/p4c/ir/ir.def"
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
#line 9037 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::SwitchStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "SwitchStatement"_cs; }
    static cstring static_type_name() { return "SwitchStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    SwitchStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    SwitchStatement(Util::SourceInfo srcInfo, const IR::Expression* expression, IR::Vector<IR::SwitchCase> cases) :
    Statement(srcInfo), expression(expression), cases(cases)
    { validate(); }
    SwitchStatement(const IR::Expression* expression, IR::Vector<IR::SwitchCase> cases) :
    expression(expression), cases(cases)
    { validate(); }
    IRNODE_SUBCLASS(SwitchStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(SwitchStatement, NodeKind::SwitchStatement, Statement);
};
}  // namespace P4::IR
namespace P4::IR {

class LoopStatement : public Statement, public virtual ISimpleNamespace, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
#line 563 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 9067 "/root/p4c/build/ir/ir-generated.h"
#line 564 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 9070 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::LoopStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "LoopStatement"_cs; }
    static cstring static_type_name() { return "LoopStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    LoopStatement(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    LoopStatement(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Statement(srcInfo), annotations(annotations)
    { validate(); }
    LoopStatement(IR::Vector<IR::Annotation> annotations) :
    annotations(annotations)
    { validate(); }
    LoopStatement(Util::SourceInfo srcInfo) :
    Statement(srcInfo)
    { validate(); }
    LoopStatement() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(LoopStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(LoopStatement, NodeKind::LoopStatement, Statement, ISimpleNamespace, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class ForStatement : public LoopStatement {
 public:
    IR::IndexedVector<IR::StatOrDecl> init;
    const IR::Expression* condition = nullptr;
    IR::IndexedVector<IR::StatOrDecl> updates;
    const IR::Statement* body = nullptr;
#line 572 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 9108 "/root/p4c/build/ir/ir-generated.h"
#line 574 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 9111 "/root/p4c/build/ir/ir-generated.h"
#line 576 "/root/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 9114 "/root/p4c/build/ir/ir-generated.h"
#line 578 "/root/p4c/ir/ir.def"
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
#line 9118 "/root/p4c/build/ir/ir-generated.h"
#line 580 "/root/p4c/ir/ir.def"
    // template single implementation of const vs non-const ForStatement
    template<class THIS> static void visit_children(THIS *, Visitor &v);
#line 9122 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ForStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ForStatement"_cs; }
    static cstring static_type_name() { return "ForStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ForStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::LoopStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ForStatement(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StatOrDecl> init, const IR::Expression* condition, IR::IndexedVector<IR::StatOrDecl> updates, const IR::Statement* body) :
    LoopStatement(srcInfo, annotations), init(init), condition(condition), updates(updates), body(body)
    { validate(); }
    ForStatement(IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StatOrDecl> init, const IR::Expression* condition, IR::IndexedVector<IR::StatOrDecl> updates, const IR::Statement* body) :
    LoopStatement(annotations), init(init), condition(condition), updates(updates), body(body)
    { validate(); }
    ForStatement(Util::SourceInfo srcInfo, IR::IndexedVector<IR::StatOrDecl> init, const IR::Expression* condition, IR::IndexedVector<IR::StatOrDecl> updates, const IR::Statement* body) :
    LoopStatement(srcInfo), init(init), condition(condition), updates(updates), body(body)
    { validate(); }
    ForStatement(IR::IndexedVector<IR::StatOrDecl> init, const IR::Expression* condition, IR::IndexedVector<IR::StatOrDecl> updates, const IR::Statement* body) :
    init(init), condition(condition), updates(updates), body(body)
    { validate(); }
    IRNODE_SUBCLASS(ForStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(ForStatement, NodeKind::ForStatement, LoopStatement);
};
}  // namespace P4::IR
namespace P4::IR {

class ForInStatement : public LoopStatement {
 public:
    const IR::Declaration_Variable* decl = nullptr;


    const IR::PathExpression* ref = nullptr;
    const IR::Expression* collection = nullptr;
    const IR::Statement* body = nullptr;
#line 594 "/root/p4c/ir/ir.def"
    ForInStatement(Util::SourceInfo si, const IR::Vector<IR::Annotation>* a, const IR::PathExpression* pe, const IR::Expression* c, const IR::Statement* b);
#line 9164 "/root/p4c/build/ir/ir-generated.h"
#line 596 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 9167 "/root/p4c/build/ir/ir-generated.h"
#line 598 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 9170 "/root/p4c/build/ir/ir-generated.h"
#line 600 "/root/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 9173 "/root/p4c/build/ir/ir-generated.h"
#line 603 "/root/p4c/ir/ir.def"
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
#line 9177 "/root/p4c/build/ir/ir-generated.h"
#line 605 "/root/p4c/ir/ir.def"
    // template single implementation of const vs non-const ForInStatement
    template<class THIS> static void visit_children(THIS *, Visitor &v);
#line 9181 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ForInStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ForInStatement"_cs; }
    static cstring static_type_name() { return "ForInStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ForInStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::LoopStatement const & a) const override;
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ForInStatement(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, const IR::Declaration_Variable* decl, const IR::Expression* collection, const IR::Statement* body) :
    LoopStatement(srcInfo, annotations), decl(decl), collection(collection), body(body)
    {
#line 593 "/root/p4c/ir/ir.def"
{ ref = new PathExpression(decl->name); }
#line 9200 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ForInStatement(IR::Vector<IR::Annotation> annotations, const IR::Declaration_Variable* decl, const IR::Expression* collection, const IR::Statement* body) :
    LoopStatement(annotations), decl(decl), collection(collection), body(body)
    {
#line 593 "/root/p4c/ir/ir.def"
{ ref = new PathExpression(decl->name); }
#line 9207 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ForInStatement(Util::SourceInfo srcInfo, const IR::Declaration_Variable* decl, const IR::Expression* collection, const IR::Statement* body) :
    LoopStatement(srcInfo), decl(decl), collection(collection), body(body)
    {
#line 593 "/root/p4c/ir/ir.def"
{ ref = new PathExpression(decl->name); }
#line 9214 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ForInStatement(const IR::Declaration_Variable* decl, const IR::Expression* collection, const IR::Statement* body) :
    decl(decl), collection(collection), body(body)
    {
#line 593 "/root/p4c/ir/ir.def"
{ ref = new PathExpression(decl->name); }
#line 9221 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(ForInStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(ForInStatement, NodeKind::ForInStatement, LoopStatement);
};
}  // namespace P4::IR
namespace P4::IR {
/////////////////////////////////////////////////////////////
class Function : public Declaration, public virtual IFunctional, public virtual IAnnotated, public virtual ISimpleNamespace, public virtual INestedNamespace {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::Type_Method* type = nullptr;
    const IR::BlockStatement* body = nullptr;
#line 616 "/root/p4c/ir/ir.def"
    const IR::ParameterList *getParameters() const override;
#line 9236 "/root/p4c/build/ir/ir-generated.h"
#line 619 "/root/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 9239 "/root/p4c/build/ir/ir-generated.h"
#line 621 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 9242 "/root/p4c/build/ir/ir-generated.h"
#line 623 "/root/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 9245 "/root/p4c/build/ir/ir-generated.h"
#line 625 "/root/p4c/ir/ir.def"
    std::vector<const IR::INamespace *> getNestedNamespaces() const override;
#line 9248 "/root/p4c/build/ir/ir-generated.h"
#line 627 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 9251 "/root/p4c/build/ir/ir-generated.h"
#line 628 "/root/p4c/ir/ir.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 9254 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Function const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Function"_cs; }
    static cstring static_type_name() { return "Function"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Function(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Function(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type_Method* type, const IR::BlockStatement* body) :
    Declaration(srcInfo, name), annotations(annotations), type(type), body(body)
    { validate(); }
    Function(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type_Method* type, const IR::BlockStatement* body) :
    Declaration(name), annotations(annotations), type(type), body(body)
    { validate(); }
    Function(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, const IR::BlockStatement* body) :
    Declaration(srcInfo, name), type(type), body(body)
    { validate(); }
    Function(IR::ID name, const IR::Type_Method* type, const IR::BlockStatement* body) :
    Declaration(name), type(type), body(body)
    { validate(); }
    IRNODE_SUBCLASS(Function)
    DECLARE_TYPEINFO_WITH_TYPEID(Function, NodeKind::Function, Declaration, IFunctional, IAnnotated, ISimpleNamespace, INestedNamespace);
};
}  // namespace P4::IR
namespace P4::IR {
/////////////////////////////////////////////////////////////
/**
 * Block is the base class for IR nodes produced by the evaluator.
 * A block represents a compile-time allocated resource.
 * Blocks are not visited using visitors, so the visit_children()
 * method is empty.  Users have to write custom visitors to
 * traverse the constantValue map.
 */
class Block : public Node, public virtual CompileTimeValue {
 public:
    const IR::Node* node = nullptr;
/// Node that evaluates to this block.
/// This is either a Declaration_Instance or a ConstructorCallExpression.
/// One value for each Node inside that evaluates to a compile-time constant.
/// This includes all constructor parameters, and all inner nested blocks.
    ordered_map<const IR::Node *, const IR::CompileTimeValue *> constantValue = {};
#line 648 "/root/p4c/ir/ir.def"
    virtual void dbprint(std::ostream & out) const override;
#line 9304 "/root/p4c/build/ir/ir-generated.h"
#line 649 "/root/p4c/ir/ir.def"
    virtual void dbprint_recursive(std::ostream & out) const;
#line 9307 "/root/p4c/build/ir/ir-generated.h"
/// value can be null for parameters which are optional
#line 651 "/root/p4c/ir/ir.def"
    void setValue(const IR::Node* node, const IR::CompileTimeValue* value);
#line 9311 "/root/p4c/build/ir/ir-generated.h"
#line 652 "/root/p4c/ir/ir.def"
    bool hasValue(const IR::Node* node) const {
        return constantValue.find(node) != constantValue.end();
    }
#line 9316 "/root/p4c/build/ir/ir-generated.h"
#line 655 "/root/p4c/ir/ir.def"
    const IR::CompileTimeValue *getValue(const IR::Node* node) const {
        CHECK_NULL(node);
        auto it = constantValue.find(node);
        BUG_CHECK(it != constantValue.end(), "%1%: No such node %2%", this, node);
        return it->second; }
#line 9323 "/root/p4c/build/ir/ir-generated.h"
#line 660 "/root/p4c/ir/ir.def"
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
#line 9327 "/root/p4c/build/ir/ir-generated.h"
#line 661 "/root/p4c/ir/ir.def"
    virtual IR::IDeclaration const * getContainer() const;
#line 9330 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Block const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Block"_cs; }
    static cstring static_type_name() { return "Block"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Block(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
 protected:
    Block(Util::SourceInfo srcInfo, const IR::Node* node) :
    Node(srcInfo), node(node)
    { validate(); }
    Block(const IR::Node* node) :
    node(node)
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Block)
    DECLARE_TYPEINFO_WITH_TYPEID(Block, NodeKind::Block, Node, CompileTimeValue);
};
}  // namespace P4::IR
namespace P4::IR {
class TableBlock : public Block {
 public:
    const IR::P4Table* container = nullptr;
#line 666 "/root/p4c/ir/ir.def"
    IR::IDeclaration const * getContainer() const override;
#line 9356 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TableBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "TableBlock"_cs; }
    static cstring static_type_name() { return "TableBlock"_cs; }
    void toJSON(JSONGenerator & json) const override;
    TableBlock(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Block const & a) const override;
    bool operator==(IR::Node const & a) const override;
    TableBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::P4Table* container) :
    Block(srcInfo, node), container(container)
    { validate(); }
    TableBlock(const IR::Node* node, const IR::P4Table* container) :
    Block(node), container(container)
    { validate(); }
    IRNODE_SUBCLASS(TableBlock)
    DECLARE_TYPEINFO_WITH_TYPEID(TableBlock, NodeKind::TableBlock, Block);
};
}  // namespace P4::IR
namespace P4::IR {
/// An object that has been instantiated
class InstantiatedBlock : public Block, public virtual IDeclaration {
 public:
    const IR::Type* instanceType = nullptr;

#line 674 "/root/p4c/ir/ir.def"
    virtual const IR::ParameterList *getConstructorParameters() const = 0;
#line 9387 "/root/p4c/build/ir/ir-generated.h"
#line 675 "/root/p4c/ir/ir.def"
    void instantiate(std::vector<const IR::CompileTimeValue *> * args);
#line 9390 "/root/p4c/build/ir/ir-generated.h"
/// @return the argument that the given parameter was instantiated with.
/// It's a fatal error if no such parameter exists.
#line 679 "/root/p4c/ir/ir.def"
    const IR::CompileTimeValue *getParameterValue(cstring paramName) const;
#line 9395 "/root/p4c/build/ir/ir-generated.h"
/// @return the argument that the given parameter was instantiated with, or
/// null if no such parameter exists.
#line 683 "/root/p4c/ir/ir.def"
    const IR::CompileTimeValue *findParameterValue(cstring paramName) const;
#line 9400 "/root/p4c/build/ir/ir-generated.h"
#line 685 "/root/p4c/ir/ir.def"
    virtual void dbprint(std::ostream & out) const override;
#line 9403 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::InstantiatedBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "InstantiatedBlock"_cs; }
    static cstring static_type_name() { return "InstantiatedBlock"_cs; }
    void toJSON(JSONGenerator & json) const override;
    InstantiatedBlock(JSONLoader & json);
    bool operator==(IR::Block const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    InstantiatedBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType) :
    Block(srcInfo, node), instanceType(instanceType)
    { validate(); }
    InstantiatedBlock(const IR::Node* node, const IR::Type* instanceType) :
    Block(node), instanceType(instanceType)
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(InstantiatedBlock)
    DECLARE_TYPEINFO_WITH_TYPEID(InstantiatedBlock, NodeKind::InstantiatedBlock, Block, IDeclaration);
};
}  // namespace P4::IR
namespace P4::IR {
class ParserBlock : public InstantiatedBlock {
 public:
    const IR::P4Parser* container = nullptr;
#line 690 "/root/p4c/ir/ir.def"
    const IR::ParameterList *getConstructorParameters() const override;
#line 9432 "/root/p4c/build/ir/ir-generated.h"
#line 692 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 9435 "/root/p4c/build/ir/ir-generated.h"
#line 693 "/root/p4c/ir/ir.def"
    IR::ID getName() const override;
#line 9438 "/root/p4c/build/ir/ir-generated.h"
#line 694 "/root/p4c/ir/ir.def"
    IR::IDeclaration const * getContainer() const override;
#line 9441 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ParserBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ParserBlock"_cs; }
    static cstring static_type_name() { return "ParserBlock"_cs; }
    void toJSON(JSONGenerator & json) const override;
    ParserBlock(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::InstantiatedBlock const & a) const override;
    bool operator==(IR::Block const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ParserBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::P4Parser* container) :
    InstantiatedBlock(srcInfo, node, instanceType), container(container)
    { validate(); }
    ParserBlock(const IR::Node* node, const IR::Type* instanceType, const IR::P4Parser* container) :
    InstantiatedBlock(node, instanceType), container(container)
    { validate(); }
    IRNODE_SUBCLASS(ParserBlock)
    DECLARE_TYPEINFO_WITH_TYPEID(ParserBlock, NodeKind::ParserBlock, InstantiatedBlock);
};
}  // namespace P4::IR
namespace P4::IR {
class ControlBlock : public InstantiatedBlock {
 public:
    const IR::P4Control* container = nullptr;
#line 700 "/root/p4c/ir/ir.def"
    const IR::ParameterList *getConstructorParameters() const override;
#line 9471 "/root/p4c/build/ir/ir-generated.h"
#line 702 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 9474 "/root/p4c/build/ir/ir-generated.h"
#line 703 "/root/p4c/ir/ir.def"
    IR::ID getName() const override;
#line 9477 "/root/p4c/build/ir/ir-generated.h"
#line 704 "/root/p4c/ir/ir.def"
    IR::IDeclaration const * getContainer() const override;
#line 9480 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ControlBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ControlBlock"_cs; }
    static cstring static_type_name() { return "ControlBlock"_cs; }
    void toJSON(JSONGenerator & json) const override;
    ControlBlock(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::InstantiatedBlock const & a) const override;
    bool operator==(IR::Block const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ControlBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::P4Control* container) :
    InstantiatedBlock(srcInfo, node, instanceType), container(container)
    { validate(); }
    ControlBlock(const IR::Node* node, const IR::Type* instanceType, const IR::P4Control* container) :
    InstantiatedBlock(node, instanceType), container(container)
    { validate(); }
    IRNODE_SUBCLASS(ControlBlock)
    DECLARE_TYPEINFO_WITH_TYPEID(ControlBlock, NodeKind::ControlBlock, InstantiatedBlock);
};
}  // namespace P4::IR
namespace P4::IR {
class PackageBlock : public InstantiatedBlock {
 public:
    const IR::Type_Package* type = nullptr;
#line 710 "/root/p4c/ir/ir.def"
    const IR::ParameterList *getConstructorParameters() const override;
#line 9510 "/root/p4c/build/ir/ir-generated.h"
#line 711 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 9513 "/root/p4c/build/ir/ir-generated.h"
#line 712 "/root/p4c/ir/ir.def"
    IR::ID getName() const override;
#line 9516 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::PackageBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "PackageBlock"_cs; }
    static cstring static_type_name() { return "PackageBlock"_cs; }
    void toJSON(JSONGenerator & json) const override;
    PackageBlock(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::InstantiatedBlock const & a) const override;
    bool operator==(IR::Block const & a) const override;
    bool operator==(IR::Node const & a) const override;
    PackageBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::Type_Package* type) :
    InstantiatedBlock(srcInfo, node, instanceType), type(type)
    { validate(); }
    PackageBlock(const IR::Node* node, const IR::Type* instanceType, const IR::Type_Package* type) :
    InstantiatedBlock(node, instanceType), type(type)
    { validate(); }
    IRNODE_SUBCLASS(PackageBlock)
    DECLARE_TYPEINFO_WITH_TYPEID(PackageBlock, NodeKind::PackageBlock, InstantiatedBlock);
};
}  // namespace P4::IR
namespace P4::IR {
class ExternBlock : public InstantiatedBlock {
 public:
    const IR::Type_Extern* type = nullptr;
    const IR::Method* constructor = nullptr;

#line 719 "/root/p4c/ir/ir.def"
    const IR::ParameterList *getConstructorParameters() const override;
#line 9548 "/root/p4c/build/ir/ir-generated.h"
#line 721 "/root/p4c/ir/ir.def"
    cstring toString() const override;
#line 9551 "/root/p4c/build/ir/ir-generated.h"
#line 722 "/root/p4c/ir/ir.def"
    IR::ID getName() const override;
#line 9554 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ExternBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ExternBlock"_cs; }
    static cstring static_type_name() { return "ExternBlock"_cs; }
    void toJSON(JSONGenerator & json) const override;
    ExternBlock(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::InstantiatedBlock const & a) const override;
    bool operator==(IR::Block const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ExternBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::Type_Extern* type, const IR::Method* constructor) :
    InstantiatedBlock(srcInfo, node, instanceType), type(type), constructor(constructor)
    { validate(); }
    ExternBlock(const IR::Node* node, const IR::Type* instanceType, const IR::Type_Extern* type, const IR::Method* constructor) :
    InstantiatedBlock(node, instanceType), type(type), constructor(constructor)
    { validate(); }
    IRNODE_SUBCLASS(ExternBlock)
    DECLARE_TYPEINFO_WITH_TYPEID(ExternBlock, NodeKind::ExternBlock, InstantiatedBlock);
};
}  // namespace P4::IR
namespace P4::IR {
/// Represents the program as a whole
class ToplevelBlock : public Block, public virtual IDeclaration {
 public:
#line 728 "/root/p4c/ir/ir.def"
    const IR::P4Program *getProgram() const;
#line 9584 "/root/p4c/build/ir/ir-generated.h"
#line 729 "/root/p4c/ir/ir.def"
    const IR::PackageBlock *getMain() const;
#line 9587 "/root/p4c/build/ir/ir-generated.h"
#line 730 "/root/p4c/ir/ir.def"
    IR::ID getName() const override;
#line 9590 "/root/p4c/build/ir/ir-generated.h"
#line 732 "/root/p4c/ir/ir.def"
    void validate() const override;
#line 9593 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ToplevelBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ToplevelBlock"_cs; }
    static cstring static_type_name() { return "ToplevelBlock"_cs; }
    void toJSON(JSONGenerator & json) const override;
    ToplevelBlock(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Block const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ToplevelBlock(Util::SourceInfo srcInfo, const IR::Node* node) :
    Block(srcInfo, node)
    { validate(); }
    ToplevelBlock(const IR::Node* node) :
    Block(node)
    { validate(); }
    IRNODE_SUBCLASS(ToplevelBlock)
    DECLARE_TYPEINFO_WITH_TYPEID(ToplevelBlock, NodeKind::ToplevelBlock, Block, IDeclaration);
};
}  // namespace P4::IR
/** @} */
/* end group irdefs */
/* -*-C++-*- */
/*
  This file contains IR classes needed just for the P4 v1.0/v1.1 front-end.
*/
/** \addtogroup irdefs
  * @{
  */
#line 11 "/root/p4c/frontends/p4-14/ir-v1.def"
namespace P4 {

namespace IR {
enum class CounterType { NONE, PACKETS, BYTES, BOTH };
}

inline std::ostream& operator<<(std::ostream &out, IR::CounterType d) {
    switch (d) {
        case IR::CounterType::NONE:
            out << "NONE";
            break;
        case IR::CounterType::PACKETS:
            out << "PACKETS";
            break;
        case IR::CounterType::BYTES:
            out << "BYTES";
            break;
        case IR::CounterType::BOTH:
            out << "BOTH";
            break;
        default:
            BUG("Unhandled case");
    }
    return out;
}

inline bool operator>>(cstring s, IR::CounterType &ctr) {
    if (!s || s == "" || s == "NONE") ctr = IR::CounterType::NONE;
    else if (s == "PACKETS") ctr = IR::CounterType::PACKETS;
    else if (s == "BYTES") ctr = IR::CounterType::BYTES;
    else if (s == "BOTH") ctr = IR::CounterType::BOTH;
    else return false;
    return true;
}

}  // namespace P4

#line 9660 "/root/p4c/build/ir/ir-generated.h"
namespace P4::IR {
class Type_Block : public Type_Base {
 public:
#line 51 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 9666 "/root/p4c/build/ir/ir-generated.h"
#line 52 "/root/p4c/frontends/p4-14/ir-v1.def"
    static const IR::Type_Block *get();
#line 9669 "/root/p4c/build/ir/ir-generated.h"
#line 53 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 9672 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Block const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Block"_cs; }
    static cstring static_type_name() { return "Type_Block"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Block(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Block(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_Block() 
    { validate(); }
    IRNODE_SUBCLASS(Type_Block)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Block, NodeKind::Type_Block, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Counter : public Type_Base {
 public:
#line 56 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 9697 "/root/p4c/build/ir/ir-generated.h"
#line 57 "/root/p4c/frontends/p4-14/ir-v1.def"
    static const IR::Type_Counter *get();
#line 9700 "/root/p4c/build/ir/ir-generated.h"
#line 58 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 9703 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Counter const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Counter"_cs; }
    static cstring static_type_name() { return "Type_Counter"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Counter(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Counter(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_Counter() 
    { validate(); }
    IRNODE_SUBCLASS(Type_Counter)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Counter, NodeKind::Type_Counter, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Expression : public Type_Base {
 public:
#line 61 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 9728 "/root/p4c/build/ir/ir-generated.h"
#line 62 "/root/p4c/frontends/p4-14/ir-v1.def"
    static const IR::Type_Expression *get();
#line 9731 "/root/p4c/build/ir/ir-generated.h"
#line 63 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 9734 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Expression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Expression"_cs; }
    static cstring static_type_name() { return "Type_Expression"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Expression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Expression(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_Expression() 
    { validate(); }
    IRNODE_SUBCLASS(Type_Expression)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Expression, NodeKind::Type_Expression, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_FieldListCalculation : public Type_Base {
 public:
#line 66 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 9759 "/root/p4c/build/ir/ir-generated.h"
#line 67 "/root/p4c/frontends/p4-14/ir-v1.def"
    static const IR::Type_FieldListCalculation *get();
#line 9762 "/root/p4c/build/ir/ir-generated.h"
#line 68 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 9765 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_FieldListCalculation const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_FieldListCalculation"_cs; }
    static cstring static_type_name() { return "Type_FieldListCalculation"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_FieldListCalculation(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_FieldListCalculation(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_FieldListCalculation() 
    { validate(); }
    IRNODE_SUBCLASS(Type_FieldListCalculation)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_FieldListCalculation, NodeKind::Type_FieldListCalculation, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Meter : public Type_Base {
 public:
#line 71 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 9790 "/root/p4c/build/ir/ir-generated.h"
#line 72 "/root/p4c/frontends/p4-14/ir-v1.def"
    static const IR::Type_Meter *get();
#line 9793 "/root/p4c/build/ir/ir-generated.h"
#line 73 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 9796 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Meter const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Meter"_cs; }
    static cstring static_type_name() { return "Type_Meter"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Meter(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Meter(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_Meter() 
    { validate(); }
    IRNODE_SUBCLASS(Type_Meter)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Meter, NodeKind::Type_Meter, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_Register : public Type_Base {
 public:
#line 76 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 9821 "/root/p4c/build/ir/ir-generated.h"
#line 77 "/root/p4c/frontends/p4-14/ir-v1.def"
    static const IR::Type_Register *get();
#line 9824 "/root/p4c/build/ir/ir-generated.h"
#line 78 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 9827 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Register const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Register"_cs; }
    static cstring static_type_name() { return "Type_Register"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_Register(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_Register(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_Register() 
    { validate(); }
    IRNODE_SUBCLASS(Type_Register)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_Register, NodeKind::Type_Register, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
class Type_AnyTable : public Type_Base {
 public:
#line 81 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 9852 "/root/p4c/build/ir/ir-generated.h"
#line 82 "/root/p4c/frontends/p4-14/ir-v1.def"
    static const IR::Type_AnyTable *get();
#line 9855 "/root/p4c/build/ir/ir-generated.h"
#line 83 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 9858 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_AnyTable const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_AnyTable"_cs; }
    static cstring static_type_name() { return "Type_AnyTable"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Type_AnyTable(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Type_AnyTable(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
    Type_AnyTable() 
    { validate(); }
    IRNODE_SUBCLASS(Type_AnyTable)
    DECLARE_TYPEINFO_WITH_TYPEID(Type_AnyTable, NodeKind::Type_AnyTable, Type_Base);
};
}  // namespace P4::IR
namespace P4::IR {
class HeaderOrMetadata : public Node, public virtual IAnnotated {
 public:
    IR::ID type_name;
    IR::ID name;
    IR::Vector<IR::Annotation> annotations;
    const IR::Type_StructLike* type = nullptr;
#line 92 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 9887 "/root/p4c/build/ir/ir-generated.h"
#line 93 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 9890 "/root/p4c/build/ir/ir-generated.h"
#line 94 "/root/p4c/frontends/p4-14/ir-v1.def"
    HeaderOrMetadata(IR::ID n, const IR::Type_StructLike* t);
#line 9893 "/root/p4c/build/ir/ir-generated.h"
#line 96 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 9896 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::HeaderOrMetadata const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "HeaderOrMetadata"_cs; }
    static cstring static_type_name() { return "HeaderOrMetadata"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    HeaderOrMetadata(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
 protected:
    HeaderOrMetadata(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), type_name(type_name), name(name), annotations(annotations)
    { validate(); }
    HeaderOrMetadata(IR::ID type_name, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    type_name(type_name), name(name), annotations(annotations)
    { validate(); }
    HeaderOrMetadata(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name) :
    Node(srcInfo), type_name(type_name), name(name)
    { validate(); }
    HeaderOrMetadata(IR::ID type_name, IR::ID name) :
    type_name(type_name), name(name)
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(HeaderOrMetadata)
    DECLARE_TYPEINFO_WITH_TYPEID(HeaderOrMetadata, NodeKind::HeaderOrMetadata, Node, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class Header : public HeaderOrMetadata {
 public:
#line 100 "/root/p4c/frontends/p4-14/ir-v1.def"
    Header(IR::ID n, const IR::Type_Header* t);
#line 9930 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Header const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Header"_cs; }
    static cstring static_type_name() { return "Header"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Header(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::HeaderOrMetadata const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Header(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    HeaderOrMetadata(srcInfo, type_name, name, annotations)
    { validate(); }
    Header(IR::ID type_name, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    HeaderOrMetadata(type_name, name, annotations)
    { validate(); }
    Header(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name) :
    HeaderOrMetadata(srcInfo, type_name, name)
    { validate(); }
    Header(IR::ID type_name, IR::ID name) :
    HeaderOrMetadata(type_name, name)
    { validate(); }
    IRNODE_SUBCLASS(Header)
    DECLARE_TYPEINFO_WITH_TYPEID(Header, NodeKind::Header, HeaderOrMetadata);
};
}  // namespace P4::IR
namespace P4::IR {
class HeaderStack : public HeaderOrMetadata {
 public:
    int size;
#line 106 "/root/p4c/frontends/p4-14/ir-v1.def"
    HeaderStack(IR::ID n, const IR::Type_Header* t, int sz);
#line 9962 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::HeaderStack const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "HeaderStack"_cs; }
    static cstring static_type_name() { return "HeaderStack"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    HeaderStack(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::HeaderOrMetadata const & a) const override;
    bool operator==(IR::Node const & a) const override;
    HeaderStack(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, IR::Vector<IR::Annotation> annotations, int size) :
    HeaderOrMetadata(srcInfo, type_name, name, annotations), size(size)
    { validate(); }
    HeaderStack(IR::ID type_name, IR::ID name, IR::Vector<IR::Annotation> annotations, int size) :
    HeaderOrMetadata(type_name, name, annotations), size(size)
    { validate(); }
    HeaderStack(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, int size) :
    HeaderOrMetadata(srcInfo, type_name, name), size(size)
    { validate(); }
    HeaderStack(IR::ID type_name, IR::ID name, int size) :
    HeaderOrMetadata(type_name, name), size(size)
    { validate(); }
    IRNODE_SUBCLASS(HeaderStack)
    DECLARE_TYPEINFO_WITH_TYPEID(HeaderStack, NodeKind::HeaderStack, HeaderOrMetadata);
};
}  // namespace P4::IR
namespace P4::IR {
class v1HeaderType : public Node {
 public:
    IR::ID name;
    const IR::Type_Struct* as_metadata = nullptr;
    const IR::Type_Header* as_header = nullptr;
#line 115 "/root/p4c/frontends/p4-14/ir-v1.def"
    v1HeaderType(IR::Type_Struct const * m, IR::Type_Header const * h = nullptr);
#line 9997 "/root/p4c/build/ir/ir-generated.h"
#line 117 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 10000 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::v1HeaderType const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "v1HeaderType"_cs; }
    static cstring static_type_name() { return "v1HeaderType"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    v1HeaderType(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    v1HeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Struct* as_metadata, const IR::Type_Header* as_header) :
    Node(srcInfo), name(name), as_metadata(as_metadata), as_header(as_header)
    { validate(); }
    v1HeaderType(IR::ID name, const IR::Type_Struct* as_metadata, const IR::Type_Header* as_header) :
    name(name), as_metadata(as_metadata), as_header(as_header)
    { validate(); }
    IRNODE_SUBCLASS(v1HeaderType)
    DECLARE_TYPEINFO_WITH_TYPEID(v1HeaderType, NodeKind::v1HeaderType, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class Metadata : public HeaderOrMetadata {
 public:
#line 121 "/root/p4c/frontends/p4-14/ir-v1.def"
    Metadata(IR::ID n, const IR::Type_StructLike* t);
#line 10028 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Metadata const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Metadata"_cs; }
    static cstring static_type_name() { return "Metadata"_cs; }
    void toJSON(JSONGenerator & json) const override;
    Metadata(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::HeaderOrMetadata const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Metadata(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    HeaderOrMetadata(srcInfo, type_name, name, annotations)
    { validate(); }
    Metadata(IR::ID type_name, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    HeaderOrMetadata(type_name, name, annotations)
    { validate(); }
    Metadata(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name) :
    HeaderOrMetadata(srcInfo, type_name, name)
    { validate(); }
    Metadata(IR::ID type_name, IR::ID name) :
    HeaderOrMetadata(type_name, name)
    { validate(); }
    IRNODE_SUBCLASS(Metadata)
    DECLARE_TYPEINFO_WITH_TYPEID(Metadata, NodeKind::Metadata, HeaderOrMetadata);
};
}  // namespace P4::IR
namespace P4::IR {
class HeaderRef : public Expression {
 public:
#line 126 "/root/p4c/frontends/p4-14/ir-v1.def"
    virtual const IR::HeaderOrMetadata *baseRef() const = 0;
#line 10059 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::HeaderRef const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "HeaderRef"_cs; }
    static cstring static_type_name() { return "HeaderRef"_cs; }
    void toJSON(JSONGenerator & json) const override;
    HeaderRef(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    HeaderRef(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
    HeaderRef(const IR::Type* type) :
    Expression(type)
    { validate(); }
    HeaderRef(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
    HeaderRef() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(HeaderRef)
    DECLARE_TYPEINFO_WITH_TYPEID(HeaderRef, NodeKind::HeaderRef, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
class ConcreteHeaderRef : public HeaderRef {
 public:
    const IR::HeaderOrMetadata* ref = nullptr;
#line 132 "/root/p4c/frontends/p4-14/ir-v1.def"
    const IR::HeaderOrMetadata *baseRef() const override;
#line 10090 "/root/p4c/build/ir/ir-generated.h"
#line 133 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 10093 "/root/p4c/build/ir/ir-generated.h"
#line 134 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 10096 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ConcreteHeaderRef const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ConcreteHeaderRef"_cs; }
    static cstring static_type_name() { return "ConcreteHeaderRef"_cs; }
    void toJSON(JSONGenerator & json) const override;
    ConcreteHeaderRef(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::HeaderRef const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ConcreteHeaderRef(Util::SourceInfo srcInfo, const IR::Type* type, const IR::HeaderOrMetadata* ref) :
    HeaderRef(srcInfo, type), ref(ref)
    {
#line 131 "/root/p4c/frontends/p4-14/ir-v1.def"
{ if (type->is<Type::Unknown>() && ref) type = ref->type; }
#line 10115 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ConcreteHeaderRef(const IR::Type* type, const IR::HeaderOrMetadata* ref) :
    HeaderRef(type), ref(ref)
    {
#line 131 "/root/p4c/frontends/p4-14/ir-v1.def"
{ if (type->is<Type::Unknown>() && ref) type = ref->type; }
#line 10122 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ConcreteHeaderRef(Util::SourceInfo srcInfo, const IR::HeaderOrMetadata* ref) :
    HeaderRef(srcInfo), ref(ref)
    {
#line 131 "/root/p4c/frontends/p4-14/ir-v1.def"
{ if (type->is<Type::Unknown>() && ref) type = ref->type; }
#line 10129 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ConcreteHeaderRef(const IR::HeaderOrMetadata* ref) :
    ref(ref)
    {
#line 131 "/root/p4c/frontends/p4-14/ir-v1.def"
{ if (type->is<Type::Unknown>() && ref) type = ref->type; }
#line 10136 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(ConcreteHeaderRef)
    DECLARE_TYPEINFO_WITH_TYPEID(ConcreteHeaderRef, NodeKind::ConcreteHeaderRef, HeaderRef);
};
}  // namespace P4::IR
namespace P4::IR {
class HeaderStackItemRef : public HeaderRef {
 public:
    const IR::Expression* base_ = nullptr;
    const IR::Expression* index_ = nullptr;
#line 144 "/root/p4c/frontends/p4-14/ir-v1.def"
    const IR::Expression *base() const;
#line 10149 "/root/p4c/build/ir/ir-generated.h"
/// Returns `nullptr` if the base is not `HeaderOrMetadata` (e.g. when this
/// is stack ref of an expression such as `lookahead`).
#line 147 "/root/p4c/frontends/p4-14/ir-v1.def"
    const IR::HeaderOrMetadata *baseRef() const override;
#line 10154 "/root/p4c/build/ir/ir-generated.h"
#line 151 "/root/p4c/frontends/p4-14/ir-v1.def"
    const IR::Expression *index() const;
#line 10157 "/root/p4c/build/ir/ir-generated.h"
#line 152 "/root/p4c/frontends/p4-14/ir-v1.def"
    void set_base(const IR::Expression* b);
#line 10160 "/root/p4c/build/ir/ir-generated.h"
#line 153 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 10163 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::HeaderStackItemRef const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "HeaderStackItemRef"_cs; }
    static cstring static_type_name() { return "HeaderStackItemRef"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    HeaderStackItemRef(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::HeaderRef const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    HeaderStackItemRef(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* base_, const IR::Expression* index_) :
    HeaderRef(srcInfo, type), base_(base_), index_(index_)
    {
#line 140 "/root/p4c/frontends/p4-14/ir-v1.def"
{
        if (type->is<Type::Unknown>() && base_)
            if (auto *hr = base_->to<HeaderRef>())
                type = hr->baseRef()->type; }
#line 10186 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    HeaderStackItemRef(const IR::Type* type, const IR::Expression* base_, const IR::Expression* index_) :
    HeaderRef(type), base_(base_), index_(index_)
    {
#line 140 "/root/p4c/frontends/p4-14/ir-v1.def"
{
        if (type->is<Type::Unknown>() && base_)
            if (auto *hr = base_->to<HeaderRef>())
                type = hr->baseRef()->type; }
#line 10196 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    HeaderStackItemRef(Util::SourceInfo srcInfo, const IR::Expression* base_, const IR::Expression* index_) :
    HeaderRef(srcInfo), base_(base_), index_(index_)
    {
#line 140 "/root/p4c/frontends/p4-14/ir-v1.def"
{
        if (type->is<Type::Unknown>() && base_)
            if (auto *hr = base_->to<HeaderRef>())
                type = hr->baseRef()->type; }
#line 10206 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    HeaderStackItemRef(const IR::Expression* base_, const IR::Expression* index_) :
    base_(base_), index_(index_)
    {
#line 140 "/root/p4c/frontends/p4-14/ir-v1.def"
{
        if (type->is<Type::Unknown>() && base_)
            if (auto *hr = base_->to<HeaderRef>())
                type = hr->baseRef()->type; }
#line 10216 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(HeaderStackItemRef)
    DECLARE_TYPEINFO_WITH_TYPEID(HeaderStackItemRef, NodeKind::HeaderStackItemRef, HeaderRef);
};
}  // namespace P4::IR
namespace P4::IR {
class If : public Expression {
 public:
    const IR::Expression* pred = nullptr;
    const IR::Vector<IR::Expression>* ifTrue = nullptr;
    const IR::Vector<IR::Expression>* ifFalse = nullptr;
#line 160 "/root/p4c/frontends/p4-14/ir-v1.def"
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
#line 10231 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::If const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "If"_cs; }
    static cstring static_type_name() { return "If"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    If(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    If(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse) :
    Expression(srcInfo, type), pred(pred), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
    If(const IR::Type* type, const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse) :
    Expression(type), pred(pred), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
    If(Util::SourceInfo srcInfo, const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse) :
    Expression(srcInfo), pred(pred), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
    If(const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse) :
    pred(pred), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
    IRNODE_SUBCLASS(If)
    DECLARE_TYPEINFO_WITH_TYPEID(If, NodeKind::If, Expression);
};
}  // namespace P4::IR
namespace P4::IR {

class NamedCond : public If {
 public:
    cstring name = unique_name();
#line 171 "/root/p4c/frontends/p4-14/ir-v1.def"
    static cstring unique_name();
#line 10266 "/root/p4c/build/ir/ir-generated.h"
#line 172 "/root/p4c/frontends/p4-14/ir-v1.def"
    NamedCond(IR::If const & i);
#line 10269 "/root/p4c/build/ir/ir-generated.h"
#line 173 "/root/p4c/frontends/p4-14/ir-v1.def"
    bool operator==(IR::NamedCond const & a) const override;
#line 10272 "/root/p4c/build/ir/ir-generated.h"
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "NamedCond"_cs; }
    static cstring static_type_name() { return "NamedCond"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    NamedCond(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::If const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(NamedCond)
    DECLARE_TYPEINFO_WITH_TYPEID(NamedCond, NodeKind::NamedCond, If);
};
}  // namespace P4::IR
namespace P4::IR {
class Apply : public Expression {
 public:
    IR::ID name;

    IR::NameMap<IR::Vector<IR::Expression>, ordered_map> actions = {};

    IR::NameMap<IR::Path> position = {};
    bool operator==(IR::Apply const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Apply"_cs; }
    static cstring static_type_name() { return "Apply"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Apply(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Apply(Util::SourceInfo srcInfo, const IR::Type* type, IR::ID name) :
    Expression(srcInfo, type), name(name)
    { validate(); }
    Apply(const IR::Type* type, IR::ID name) :
    Expression(type), name(name)
    { validate(); }
    Apply(Util::SourceInfo srcInfo, IR::ID name) :
    Expression(srcInfo), name(name)
    { validate(); }
    Apply(IR::ID name) :
    name(name)
    { validate(); }
    Apply(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
    Apply(const IR::Type* type) :
    Expression(type)
    { validate(); }
    Apply(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
    Apply() 
    { validate(); }
    IRNODE_SUBCLASS(Apply)
    DECLARE_TYPEINFO_WITH_TYPEID(Apply, NodeKind::Apply, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
class Primitive : public Operation {
 public:
    cstring name;
    IR::Vector<IR::Expression> operands = {};
#line 190 "/root/p4c/frontends/p4-14/ir-v1.def"
    Primitive(cstring n, const IR::Vector<IR::Expression>* l);
#line 10343 "/root/p4c/build/ir/ir-generated.h"
#line 192 "/root/p4c/frontends/p4-14/ir-v1.def"
    Primitive(Util::SourceInfo si, cstring n, const IR::Vector<IR::Expression>* l);
#line 10346 "/root/p4c/build/ir/ir-generated.h"
#line 194 "/root/p4c/frontends/p4-14/ir-v1.def"
    Primitive(cstring n, const IR::Expression* a1);
#line 10349 "/root/p4c/build/ir/ir-generated.h"
#line 196 "/root/p4c/frontends/p4-14/ir-v1.def"
    Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1);
#line 10352 "/root/p4c/build/ir/ir-generated.h"
#line 198 "/root/p4c/frontends/p4-14/ir-v1.def"
    Primitive(cstring n, const IR::Expression* a1, const IR::Expression* a2);
#line 10355 "/root/p4c/build/ir/ir-generated.h"
#line 200 "/root/p4c/frontends/p4-14/ir-v1.def"
    Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Expression* a2);
#line 10358 "/root/p4c/build/ir/ir-generated.h"
#line 203 "/root/p4c/frontends/p4-14/ir-v1.def"
    Primitive(cstring n, const IR::Expression* a1, const IR::Vector<IR::Expression>* a2);
#line 10361 "/root/p4c/build/ir/ir-generated.h"
#line 206 "/root/p4c/frontends/p4-14/ir-v1.def"
    Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Vector<IR::Expression>* a2);
#line 10364 "/root/p4c/build/ir/ir-generated.h"
#line 210 "/root/p4c/frontends/p4-14/ir-v1.def"
    Primitive(cstring n, const IR::Expression* a1, const IR::Expression* a2, const IR::Expression* a3);
#line 10367 "/root/p4c/build/ir/ir-generated.h"
#line 212 "/root/p4c/frontends/p4-14/ir-v1.def"
    Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Expression* a2, const IR::Expression* a3);
#line 10370 "/root/p4c/build/ir/ir-generated.h"
#line 215 "/root/p4c/frontends/p4-14/ir-v1.def"
    virtual bool isOutput(int operand_index) const;
#line 10373 "/root/p4c/build/ir/ir-generated.h"
#line 216 "/root/p4c/frontends/p4-14/ir-v1.def"
    virtual unsigned inferOperandTypes() const;
#line 10376 "/root/p4c/build/ir/ir-generated.h"
#line 217 "/root/p4c/frontends/p4-14/ir-v1.def"
    virtual const IR::Type *inferOperandType(int operand) const;
#line 10379 "/root/p4c/build/ir/ir-generated.h"
#line 218 "/root/p4c/frontends/p4-14/ir-v1.def"
    virtual void typecheck() const;
#line 10382 "/root/p4c/build/ir/ir-generated.h"
    IRNODE_DECLARE_APPLY_OVERLOAD(Primitive)
    cstring getStringOp() const override { return cstring(name); }
    int getPrecedence() const override { return DBPrint::Prec_Postfix; }
    bool operator==(IR::Primitive const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Primitive"_cs; }
    static cstring static_type_name() { return "Primitive"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Primitive(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Primitive(Util::SourceInfo srcInfo, const IR::Type* type, cstring name) :
    Operation(srcInfo, type), name(name)
    { validate(); }
    Primitive(const IR::Type* type, cstring name) :
    Operation(type), name(name)
    { validate(); }
    Primitive(Util::SourceInfo srcInfo, cstring name) :
    Operation(srcInfo), name(name)
    { validate(); }
    Primitive(cstring name) :
    name(name)
    { validate(); }
    IRNODE_SUBCLASS(Primitive)
    DECLARE_TYPEINFO_WITH_TYPEID(Primitive, NodeKind::Primitive, Operation);
};
}  // namespace P4::IR
namespace P4::IR {
class FieldList : public Node, public virtual IAnnotated {
 public:
    IR::ID name;
    bool payload = false;
    IR::Vector<IR::Annotation> annotations;
    IR::Vector<IR::Expression> fields = {};
#line 229 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 10426 "/root/p4c/build/ir/ir-generated.h"
#line 230 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 10429 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::FieldList const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "FieldList"_cs; }
    static cstring static_type_name() { return "FieldList"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    FieldList(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    FieldList(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
    FieldList(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    name(name), annotations(annotations)
    { validate(); }
    FieldList(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
    FieldList(IR::Vector<IR::Annotation> annotations) :
    annotations(annotations)
    { validate(); }
    FieldList(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
    FieldList(IR::ID name) :
    name(name)
    { validate(); }
    FieldList(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    FieldList() 
    { validate(); }
    IRNODE_SUBCLASS(FieldList)
    DECLARE_TYPEINFO_WITH_TYPEID(FieldList, NodeKind::FieldList, Node, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class FieldListCalculation : public Node, public virtual IAnnotated {
 public:
    IR::ID name;
    const IR::NameList* input = nullptr;
    const IR::FieldList* input_fields = nullptr;
    const IR::NameList* algorithm = nullptr;
    int output_width = 0;
    IR::Vector<IR::Annotation> annotations;
#line 240 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 10481 "/root/p4c/build/ir/ir-generated.h"
#line 241 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 10484 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::FieldListCalculation const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "FieldListCalculation"_cs; }
    static cstring static_type_name() { return "FieldListCalculation"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    FieldListCalculation(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    FieldListCalculation(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
    FieldListCalculation(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    name(name), annotations(annotations)
    { validate(); }
    FieldListCalculation(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
    FieldListCalculation(IR::Vector<IR::Annotation> annotations) :
    annotations(annotations)
    { validate(); }
    FieldListCalculation(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
    FieldListCalculation(IR::ID name) :
    name(name)
    { validate(); }
    FieldListCalculation(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    FieldListCalculation() 
    { validate(); }
    IRNODE_SUBCLASS(FieldListCalculation)
    DECLARE_TYPEINFO_WITH_TYPEID(FieldListCalculation, NodeKind::FieldListCalculation, Node, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class CalculatedField : public Node, public virtual IAnnotated {
 public:
    const IR::Expression* field = nullptr;
class update_or_verify {
 public:
    Util::SourceInfo srcInfo;
    bool update = false;
    IR::ID name;
    const IR::Expression* cond = nullptr;
#line 251 "/root/p4c/frontends/p4-14/ir-v1.def"
    update_or_verify();
#line 10537 "/root/p4c/build/ir/ir-generated.h"

    bool operator==(IR::CalculatedField::update_or_verify const & a) const;
    void toJSON(JSONGenerator & json) const;
    update_or_verify(JSONLoader & json);
    static IR::CalculatedField::update_or_verify * fromJSON(JSONLoader & json);
    update_or_verify(Util::SourceInfo srcInfo, bool update, IR::ID name, const IR::Expression* cond) :
    srcInfo(srcInfo), update(update), name(name), cond(cond)
    {}
    update_or_verify(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* cond) :
    srcInfo(srcInfo), name(name), cond(cond)
    {}
};
    safe_vector<update_or_verify> specs = {};
    IR::Vector<IR::Annotation> annotations;
#line 255 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 10554 "/root/p4c/build/ir/ir-generated.h"
#line 256 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 10557 "/root/p4c/build/ir/ir-generated.h"
#line 257 "/root/p4c/frontends/p4-14/ir-v1.def"
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
#line 10561 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::CalculatedField const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "CalculatedField"_cs; }
    static cstring static_type_name() { return "CalculatedField"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    CalculatedField(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    CalculatedField(Util::SourceInfo srcInfo, const IR::Expression* field, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), field(field), annotations(annotations)
    { validate(); }
    CalculatedField(const IR::Expression* field, IR::Vector<IR::Annotation> annotations) :
    field(field), annotations(annotations)
    { validate(); }
    CalculatedField(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
    CalculatedField(IR::Vector<IR::Annotation> annotations) :
    annotations(annotations)
    { validate(); }
    CalculatedField(Util::SourceInfo srcInfo, const IR::Expression* field) :
    Node(srcInfo), field(field)
    { validate(); }
    CalculatedField(const IR::Expression* field) :
    field(field)
    { validate(); }
    CalculatedField(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    CalculatedField() 
    { validate(); }
    IRNODE_SUBCLASS(CalculatedField)
    DECLARE_TYPEINFO_WITH_TYPEID(CalculatedField, NodeKind::CalculatedField, Node, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class ParserValueSet : public Node, public virtual IAnnotated {
 public:
    IR::ID name;
    IR::Vector<IR::Annotation> annotations;
#line 267 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 10606 "/root/p4c/build/ir/ir-generated.h"
#line 268 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 10609 "/root/p4c/build/ir/ir-generated.h"
#line 269 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 10612 "/root/p4c/build/ir/ir-generated.h"
#line 270 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 10615 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ParserValueSet const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ParserValueSet"_cs; }
    static cstring static_type_name() { return "ParserValueSet"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ParserValueSet(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    ParserValueSet(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
    ParserValueSet(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    name(name), annotations(annotations)
    { validate(); }
    ParserValueSet(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
    ParserValueSet(IR::ID name) :
    name(name)
    { validate(); }
    IRNODE_SUBCLASS(ParserValueSet)
    DECLARE_TYPEINFO_WITH_TYPEID(ParserValueSet, NodeKind::ParserValueSet, Node, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class CaseEntry : public Node {
 public:
    safe_vector<std::pair<const IR::Expression *, const IR::Constant *>> values = {};
    IR::ID action;
    bool operator==(IR::CaseEntry const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "CaseEntry"_cs; }
    static cstring static_type_name() { return "CaseEntry"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    CaseEntry(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    CaseEntry(Util::SourceInfo srcInfo, IR::ID action) :
    Node(srcInfo), action(action)
    { validate(); }
    CaseEntry(IR::ID action) :
    action(action)
    { validate(); }
    CaseEntry(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    CaseEntry() 
    { validate(); }
    IRNODE_SUBCLASS(CaseEntry)
    DECLARE_TYPEINFO_WITH_TYPEID(CaseEntry, NodeKind::CaseEntry, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class V1Parser : public Node, public virtual IAnnotated {
 public:
    IR::ID name;
    IR::Vector<IR::Expression> stmts = {};
    const IR::Vector<IR::Expression>* select = nullptr;
    const IR::Vector<IR::CaseEntry>* cases = nullptr;
    IR::ID default_return = {};
    IR::ID parse_error = {};
    bool drop = false;
    IR::Vector<IR::Annotation> annotations;
#line 287 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 10687 "/root/p4c/build/ir/ir-generated.h"
#line 288 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 10690 "/root/p4c/build/ir/ir-generated.h"
#line 289 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 10693 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::V1Parser const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "V1Parser"_cs; }
    static cstring static_type_name() { return "V1Parser"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    V1Parser(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    V1Parser(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
    V1Parser(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    name(name), annotations(annotations)
    { validate(); }
    V1Parser(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
    V1Parser(IR::Vector<IR::Annotation> annotations) :
    annotations(annotations)
    { validate(); }
    V1Parser(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
    V1Parser(IR::ID name) :
    name(name)
    { validate(); }
    V1Parser(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    V1Parser() 
    { validate(); }
    IRNODE_SUBCLASS(V1Parser)
    DECLARE_TYPEINFO_WITH_TYPEID(V1Parser, NodeKind::V1Parser, Node, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class ParserException : public Node {
 public:
    bool operator==(IR::ParserException const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ParserException"_cs; }
    static cstring static_type_name() { return "ParserException"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ParserException(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    ParserException(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    ParserException() 
    { validate(); }
    IRNODE_SUBCLASS(ParserException)
    DECLARE_TYPEINFO_WITH_TYPEID(ParserException, NodeKind::ParserException, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class Attached : public Node, public virtual IInstance, public virtual IAnnotated {
 public:
    IR::ID name;
    IR::Vector<IR::Annotation> annotations;
#line 297 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::ID Name() const override;
#line 10762 "/root/p4c/build/ir/ir-generated.h"
#line 298 "/root/p4c/frontends/p4-14/ir-v1.def"
    virtual char const * kind() const = 0;
#line 10765 "/root/p4c/build/ir/ir-generated.h"
#line 299 "/root/p4c/frontends/p4-14/ir-v1.def"
    const IR::Type *getType() const override;
#line 10768 "/root/p4c/build/ir/ir-generated.h"
#line 300 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 10771 "/root/p4c/build/ir/ir-generated.h"
#line 301 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 10774 "/root/p4c/build/ir/ir-generated.h"
#line 302 "/root/p4c/frontends/p4-14/ir-v1.def"
    virtual bool indexed() const;
#line 10777 "/root/p4c/build/ir/ir-generated.h"
#line 303 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Attached * clone_rename(char const * ext) const;
#line 10780 "/root/p4c/build/ir/ir-generated.h"
#line 307 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 10783 "/root/p4c/build/ir/ir-generated.h"
#line 308 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 10786 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Attached const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Attached"_cs; }
    static cstring static_type_name() { return "Attached"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Attached(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
 protected:
    Attached(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
    Attached(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    name(name), annotations(annotations)
    { validate(); }
    Attached(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
    Attached(IR::Vector<IR::Annotation> annotations) :
    annotations(annotations)
    { validate(); }
    Attached(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
    Attached(IR::ID name) :
    name(name)
    { validate(); }
    Attached(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    Attached() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Attached)
    DECLARE_TYPEINFO_WITH_TYPEID(Attached, NodeKind::Attached, Node, IInstance, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class Stateful : public Attached {
 public:
    IR::ID table = {};
    bool direct = false;
    bool saturating = false;
    int instance_count = -1;
#line 316 "/root/p4c/frontends/p4-14/ir-v1.def"
    virtual bool indexed() const override;
#line 10835 "/root/p4c/build/ir/ir-generated.h"
#line 317 "/root/p4c/frontends/p4-14/ir-v1.def"
    int index_width() const;
#line 10838 "/root/p4c/build/ir/ir-generated.h"

    bool operator==(IR::Stateful const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Stateful"_cs; }
    static cstring static_type_name() { return "Stateful"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Stateful(JSONLoader & json);
    bool operator==(IR::Attached const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    Stateful(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Attached(srcInfo, name, annotations)
    { validate(); }
    Stateful(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Attached(name, annotations)
    { validate(); }
    Stateful(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Attached(srcInfo, annotations)
    { validate(); }
    Stateful(IR::Vector<IR::Annotation> annotations) :
    Attached(annotations)
    { validate(); }
    Stateful(Util::SourceInfo srcInfo, IR::ID name) :
    Attached(srcInfo, name)
    { validate(); }
    Stateful(IR::ID name) :
    Attached(name)
    { validate(); }
    Stateful(Util::SourceInfo srcInfo) :
    Attached(srcInfo)
    { validate(); }
    Stateful() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(Stateful)
    DECLARE_TYPEINFO_WITH_TYPEID(Stateful, NodeKind::Stateful, Attached);
};
}  // namespace P4::IR
namespace P4::IR {
class CounterOrMeter : public Stateful {
 public:
    CounterType type = CounterType::NONE;
#line 322 "/root/p4c/frontends/p4-14/ir-v1.def"
    void settype(cstring t);
#line 10883 "/root/p4c/build/ir/ir-generated.h"

    bool operator==(IR::CounterOrMeter const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "CounterOrMeter"_cs; }
    static cstring static_type_name() { return "CounterOrMeter"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    CounterOrMeter(JSONLoader & json);
    bool operator==(IR::Stateful const & a) const override;
    bool operator==(IR::Attached const & a) const override;
    bool operator==(IR::Node const & a) const override;
 protected:
    CounterOrMeter(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Stateful(srcInfo, name, annotations)
    { validate(); }
    CounterOrMeter(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Stateful(name, annotations)
    { validate(); }
    CounterOrMeter(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Stateful(srcInfo, annotations)
    { validate(); }
    CounterOrMeter(IR::Vector<IR::Annotation> annotations) :
    Stateful(annotations)
    { validate(); }
    CounterOrMeter(Util::SourceInfo srcInfo, IR::ID name) :
    Stateful(srcInfo, name)
    { validate(); }
    CounterOrMeter(IR::ID name) :
    Stateful(name)
    { validate(); }
    CounterOrMeter(Util::SourceInfo srcInfo) :
    Stateful(srcInfo)
    { validate(); }
    CounterOrMeter() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(CounterOrMeter)
    DECLARE_TYPEINFO_WITH_TYPEID(CounterOrMeter, NodeKind::CounterOrMeter, Stateful);
};
}  // namespace P4::IR
namespace P4::IR {
class Counter : public CounterOrMeter {
 public:
    int max_width = -1;
    int min_width = -1;
#line 333 "/root/p4c/frontends/p4-14/ir-v1.def"
    char const * kind() const override;
#line 10930 "/root/p4c/build/ir/ir-generated.h"
#line 334 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Type const * getType() const override;
#line 10933 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Counter const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Counter"_cs; }
    static cstring static_type_name() { return "Counter"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Counter(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::CounterOrMeter const & a) const override;
    bool operator==(IR::Stateful const & a) const override;
    bool operator==(IR::Attached const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Counter(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    CounterOrMeter(srcInfo, name, annotations)
    { validate(); }
    Counter(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    CounterOrMeter(name, annotations)
    { validate(); }
    Counter(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    CounterOrMeter(srcInfo, annotations)
    { validate(); }
    Counter(IR::Vector<IR::Annotation> annotations) :
    CounterOrMeter(annotations)
    { validate(); }
    Counter(Util::SourceInfo srcInfo, IR::ID name) :
    CounterOrMeter(srcInfo, name)
    { validate(); }
    Counter(IR::ID name) :
    CounterOrMeter(name)
    { validate(); }
    Counter(Util::SourceInfo srcInfo) :
    CounterOrMeter(srcInfo)
    { validate(); }
    Counter() 
    { validate(); }
    IRNODE_SUBCLASS(Counter)
    DECLARE_TYPEINFO_WITH_TYPEID(Counter, NodeKind::Counter, CounterOrMeter);
};
}  // namespace P4::IR
namespace P4::IR {
class Meter : public CounterOrMeter {
 public:
    const IR::Expression* result = nullptr;
    const IR::Expression* pre_color = nullptr;
    IR::ID implementation = {};
#line 341 "/root/p4c/frontends/p4-14/ir-v1.def"
    char const * kind() const override;
#line 10982 "/root/p4c/build/ir/ir-generated.h"
#line 342 "/root/p4c/frontends/p4-14/ir-v1.def"
    const IR::Type *getType() const override;
#line 10985 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Meter const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Meter"_cs; }
    static cstring static_type_name() { return "Meter"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Meter(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::CounterOrMeter const & a) const override;
    bool operator==(IR::Stateful const & a) const override;
    bool operator==(IR::Attached const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Meter(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    CounterOrMeter(srcInfo, name, annotations)
    { validate(); }
    Meter(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    CounterOrMeter(name, annotations)
    { validate(); }
    Meter(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    CounterOrMeter(srcInfo, annotations)
    { validate(); }
    Meter(IR::Vector<IR::Annotation> annotations) :
    CounterOrMeter(annotations)
    { validate(); }
    Meter(Util::SourceInfo srcInfo, IR::ID name) :
    CounterOrMeter(srcInfo, name)
    { validate(); }
    Meter(IR::ID name) :
    CounterOrMeter(name)
    { validate(); }
    Meter(Util::SourceInfo srcInfo) :
    CounterOrMeter(srcInfo)
    { validate(); }
    Meter() 
    { validate(); }
    IRNODE_SUBCLASS(Meter)
    DECLARE_TYPEINFO_WITH_TYPEID(Meter, NodeKind::Meter, CounterOrMeter);
};
}  // namespace P4::IR
namespace P4::IR {
class Register : public Stateful {
 public:
    IR::ID layout = {};
    int width = -1;
    bool signed_ = false;

#line 350 "/root/p4c/frontends/p4-14/ir-v1.def"
    char const * kind() const override;
#line 11037 "/root/p4c/build/ir/ir-generated.h"
#line 351 "/root/p4c/frontends/p4-14/ir-v1.def"
    const IR::Type *getType() const override;
#line 11040 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Register const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Register"_cs; }
    static cstring static_type_name() { return "Register"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Register(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Stateful const & a) const override;
    bool operator==(IR::Attached const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Register(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Stateful(srcInfo, name, annotations)
    { validate(); }
    Register(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Stateful(name, annotations)
    { validate(); }
    Register(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Stateful(srcInfo, annotations)
    { validate(); }
    Register(IR::Vector<IR::Annotation> annotations) :
    Stateful(annotations)
    { validate(); }
    Register(Util::SourceInfo srcInfo, IR::ID name) :
    Stateful(srcInfo, name)
    { validate(); }
    Register(IR::ID name) :
    Stateful(name)
    { validate(); }
    Register(Util::SourceInfo srcInfo) :
    Stateful(srcInfo)
    { validate(); }
    Register() 
    { validate(); }
    IRNODE_SUBCLASS(Register)
    DECLARE_TYPEINFO_WITH_TYPEID(Register, NodeKind::Register, Stateful);
};
}  // namespace P4::IR
namespace P4::IR {
class PrimitiveAction : public Node {
 public:
    bool operator==(IR::PrimitiveAction const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "PrimitiveAction"_cs; }
    static cstring static_type_name() { return "PrimitiveAction"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    PrimitiveAction(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    PrimitiveAction(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    PrimitiveAction() 
    { validate(); }
    IRNODE_SUBCLASS(PrimitiveAction)
    DECLARE_TYPEINFO_WITH_TYPEID(PrimitiveAction, NodeKind::PrimitiveAction, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class NameList : public Node {
 public:
    safe_vector<IR::ID> names = {};
#line 358 "/root/p4c/frontends/p4-14/ir-v1.def"
    NameList(Util::SourceInfo si, cstring n);
#line 11107 "/root/p4c/build/ir/ir-generated.h"
#line 359 "/root/p4c/frontends/p4-14/ir-v1.def"
    NameList(Util::SourceInfo si, IR::ID n);
#line 11110 "/root/p4c/build/ir/ir-generated.h"
#line 360 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dump_fields(std::ostream & out) const override;
#line 11113 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::NameList const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "NameList"_cs; }
    static cstring static_type_name() { return "NameList"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    NameList(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    NameList(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    NameList() 
    { validate(); }
    IRNODE_SUBCLASS(NameList)
    DECLARE_TYPEINFO_WITH_TYPEID(NameList, NodeKind::NameList, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class ActionArg : public Expression {
 public:
    cstring action_name;
    IR::ID name;
    bool read = false;
    bool write = false;
#line 369 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 11141 "/root/p4c/build/ir/ir-generated.h"
#line 370 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 11144 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ActionArg const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ActionArg"_cs; }
    static cstring static_type_name() { return "ActionArg"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ActionArg(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ActionArg(Util::SourceInfo srcInfo, const IR::Type* type, cstring action_name, IR::ID name) :
    Expression(srcInfo, type), action_name(action_name), name(name)
    {
#line 368 "/root/p4c/frontends/p4-14/ir-v1.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 11160 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ActionArg(const IR::Type* type, cstring action_name, IR::ID name) :
    Expression(type), action_name(action_name), name(name)
    {
#line 368 "/root/p4c/frontends/p4-14/ir-v1.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 11167 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ActionArg(Util::SourceInfo srcInfo, cstring action_name, IR::ID name) :
    Expression(srcInfo), action_name(action_name), name(name)
    {
#line 368 "/root/p4c/frontends/p4-14/ir-v1.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 11174 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    ActionArg(cstring action_name, IR::ID name) :
    action_name(action_name), name(name)
    {
#line 368 "/root/p4c/frontends/p4-14/ir-v1.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 11181 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(ActionArg)
    DECLARE_TYPEINFO_WITH_TYPEID(ActionArg, NodeKind::ActionArg, Expression);
};
}  // namespace P4::IR
namespace P4::IR {

class ActionFunction : public Node, public virtual IAnnotated {
 public:
    IR::ID name;
    IR::Vector<IR::Primitive> action = {};
    safe_vector<const IR::ActionArg *> args = {};
    IR::Vector<IR::Annotation> annotations;
#line 380 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 11197 "/root/p4c/build/ir/ir-generated.h"
#line 381 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 11200 "/root/p4c/build/ir/ir-generated.h"
#line 382 "/root/p4c/frontends/p4-14/ir-v1.def"
    const IR::ActionArg *arg(cstring n) const;
#line 11203 "/root/p4c/build/ir/ir-generated.h"
#line 387 "/root/p4c/frontends/p4-14/ir-v1.def"
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
#line 11207 "/root/p4c/build/ir/ir-generated.h"
#line 395 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 11210 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ActionFunction const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ActionFunction"_cs; }
    static cstring static_type_name() { return "ActionFunction"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ActionFunction(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    ActionFunction(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
    ActionFunction(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    name(name), annotations(annotations)
    { validate(); }
    ActionFunction(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
    ActionFunction(IR::Vector<IR::Annotation> annotations) :
    annotations(annotations)
    { validate(); }
    ActionFunction(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
    ActionFunction(IR::ID name) :
    name(name)
    { validate(); }
    ActionFunction(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    ActionFunction() 
    { validate(); }
    IRNODE_SUBCLASS(ActionFunction)
    DECLARE_TYPEINFO_WITH_TYPEID(ActionFunction, NodeKind::ActionFunction, Node, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class ActionProfile : public Attached {
 public:
    IR::ID selector = {};
    safe_vector<IR::ID> actions = {};
    int size = 0;
#line 405 "/root/p4c/frontends/p4-14/ir-v1.def"
    char const * kind() const override;
#line 11257 "/root/p4c/build/ir/ir-generated.h"
#line 406 "/root/p4c/frontends/p4-14/ir-v1.def"
    bool indexed() const override;
#line 11260 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ActionProfile const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ActionProfile"_cs; }
    static cstring static_type_name() { return "ActionProfile"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ActionProfile(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Attached const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ActionProfile(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Attached(srcInfo, name, annotations)
    { validate(); }
    ActionProfile(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Attached(name, annotations)
    { validate(); }
    ActionProfile(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Attached(srcInfo, annotations)
    { validate(); }
    ActionProfile(IR::Vector<IR::Annotation> annotations) :
    Attached(annotations)
    { validate(); }
    ActionProfile(Util::SourceInfo srcInfo, IR::ID name) :
    Attached(srcInfo, name)
    { validate(); }
    ActionProfile(IR::ID name) :
    Attached(name)
    { validate(); }
    ActionProfile(Util::SourceInfo srcInfo) :
    Attached(srcInfo)
    { validate(); }
    ActionProfile() 
    { validate(); }
    IRNODE_SUBCLASS(ActionProfile)
    DECLARE_TYPEINFO_WITH_TYPEID(ActionProfile, NodeKind::ActionProfile, Attached);
};
}  // namespace P4::IR
namespace P4::IR {
class ActionSelector : public Attached {
 public:
    IR::ID key = {};
    const IR::FieldListCalculation* key_fields = nullptr;
    IR::ID mode = {};
    IR::ID type = {};
#line 414 "/root/p4c/frontends/p4-14/ir-v1.def"
    char const * kind() const override;
#line 11308 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ActionSelector const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "ActionSelector"_cs; }
    static cstring static_type_name() { return "ActionSelector"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ActionSelector(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Attached const & a) const override;
    bool operator==(IR::Node const & a) const override;
    ActionSelector(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Attached(srcInfo, name, annotations)
    { validate(); }
    ActionSelector(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Attached(name, annotations)
    { validate(); }
    ActionSelector(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Attached(srcInfo, annotations)
    { validate(); }
    ActionSelector(IR::Vector<IR::Annotation> annotations) :
    Attached(annotations)
    { validate(); }
    ActionSelector(Util::SourceInfo srcInfo, IR::ID name) :
    Attached(srcInfo, name)
    { validate(); }
    ActionSelector(IR::ID name) :
    Attached(name)
    { validate(); }
    ActionSelector(Util::SourceInfo srcInfo) :
    Attached(srcInfo)
    { validate(); }
    ActionSelector() 
    { validate(); }
    IRNODE_SUBCLASS(ActionSelector)
    DECLARE_TYPEINFO_WITH_TYPEID(ActionSelector, NodeKind::ActionSelector, Attached);
};
}  // namespace P4::IR
namespace P4::IR {
class V1Table : public Node, public virtual IInstance, public virtual IAnnotated {
 public:
    IR::ID name;
    const IR::Vector<IR::Expression>* reads = 0;
    safe_vector<IR::ID> reads_types = {};
    int min_size = 0;
    int max_size = 0;
    int size = 0;
    IR::ID action_profile = {};
    safe_vector<IR::ID> actions = {};
    IR::ID default_action = {};
    bool default_action_is_const = false;
    const IR::Vector<IR::Expression>* default_action_args = 0;
    IR::TableProperties properties = {};

    IR::Vector<IR::Annotation> annotations;
#line 432 "/root/p4c/frontends/p4-14/ir-v1.def"
    void addProperty(const IR::Property* prop);
#line 11368 "/root/p4c/build/ir/ir-generated.h"
#line 433 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 11371 "/root/p4c/build/ir/ir-generated.h"
#line 434 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 11374 "/root/p4c/build/ir/ir-generated.h"
#line 435 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 11377 "/root/p4c/build/ir/ir-generated.h"
#line 436 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::ID Name() const override;
#line 11380 "/root/p4c/build/ir/ir-generated.h"
#line 437 "/root/p4c/frontends/p4-14/ir-v1.def"
    const IR::Type *getType() const override;
#line 11383 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::V1Table const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "V1Table"_cs; }
    static cstring static_type_name() { return "V1Table"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    V1Table(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    V1Table(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
    V1Table(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    name(name), annotations(annotations)
    { validate(); }
    V1Table(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
    V1Table(IR::Vector<IR::Annotation> annotations) :
    annotations(annotations)
    { validate(); }
    V1Table(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
    V1Table(IR::ID name) :
    name(name)
    { validate(); }
    V1Table(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    V1Table() 
    { validate(); }
    IRNODE_SUBCLASS(V1Table)
    DECLARE_TYPEINFO_WITH_TYPEID(V1Table, NodeKind::V1Table, Node, IInstance, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class V1Control : public Node, public virtual IAnnotated {
 public:
    IR::ID name;
    const IR::Vector<IR::Expression>* code = nullptr;
    IR::Vector<IR::Annotation> annotations;
#line 445 "/root/p4c/frontends/p4-14/ir-v1.def"
    V1Control(IR::ID n);
#line 11432 "/root/p4c/build/ir/ir-generated.h"
#line 446 "/root/p4c/frontends/p4-14/ir-v1.def"
    V1Control(Util::SourceInfo si, IR::ID n);
#line 11435 "/root/p4c/build/ir/ir-generated.h"
    IRNODE_DECLARE_APPLY_OVERLOAD(V1Control)
#line 448 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 11439 "/root/p4c/build/ir/ir-generated.h"
#line 449 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 11442 "/root/p4c/build/ir/ir-generated.h"
#line 450 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 11445 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::V1Control const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "V1Control"_cs; }
    static cstring static_type_name() { return "V1Control"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    V1Control(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    V1Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Vector<IR::Expression>* code, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), name(name), code(code), annotations(annotations)
    { validate(); }
    V1Control(IR::ID name, const IR::Vector<IR::Expression>* code, IR::Vector<IR::Annotation> annotations) :
    name(name), code(code), annotations(annotations)
    { validate(); }
    V1Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Vector<IR::Expression>* code) :
    Node(srcInfo), name(name), code(code)
    { validate(); }
    V1Control(IR::ID name, const IR::Vector<IR::Expression>* code) :
    name(name), code(code)
    { validate(); }
    IRNODE_SUBCLASS(V1Control)
    DECLARE_TYPEINFO_WITH_TYPEID(V1Control, NodeKind::V1Control, Node, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class AttribLocal : public Expression, public virtual IDeclaration {
 public:
    IR::ID name;
#line 455 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::ID getName() const override;
#line 11481 "/root/p4c/build/ir/ir-generated.h"
#line 456 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 11484 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::AttribLocal const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "AttribLocal"_cs; }
    static cstring static_type_name() { return "AttribLocal"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    AttribLocal(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    AttribLocal(Util::SourceInfo srcInfo, const IR::Type* type, IR::ID name) :
    Expression(srcInfo, type), name(name)
    { validate(); }
    AttribLocal(const IR::Type* type, IR::ID name) :
    Expression(type), name(name)
    { validate(); }
    AttribLocal(Util::SourceInfo srcInfo, IR::ID name) :
    Expression(srcInfo), name(name)
    { validate(); }
    AttribLocal(IR::ID name) :
    name(name)
    { validate(); }
    IRNODE_SUBCLASS(AttribLocal)
    DECLARE_TYPEINFO_WITH_TYPEID(AttribLocal, NodeKind::AttribLocal, Expression, IDeclaration);
};
}  // namespace P4::IR
namespace P4::IR {
class AttribLocals : public Node, public virtual ISimpleNamespace {
 public:
    IR::NameMap<IR::AttribLocal> locals = {};
#line 462 "/root/p4c/frontends/p4-14/ir-v1.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 11517 "/root/p4c/build/ir/ir-generated.h"
#line 464 "/root/p4c/frontends/p4-14/ir-v1.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 11520 "/root/p4c/build/ir/ir-generated.h"
#line 465 "/root/p4c/frontends/p4-14/ir-v1.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 11523 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::AttribLocals const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "AttribLocals"_cs; }
    static cstring static_type_name() { return "AttribLocals"_cs; }
    void toJSON(JSONGenerator & json) const override;
    AttribLocals(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    AttribLocals(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    AttribLocals() 
    { validate(); }
    IRNODE_SUBCLASS(AttribLocals)
    DECLARE_TYPEINFO_WITH_TYPEID(AttribLocals, NodeKind::AttribLocals, Node, ISimpleNamespace);
};
}  // namespace P4::IR
namespace P4::IR {
class Attribute : public Declaration {
 public:
    const IR::Type* type = nullptr;
    const IR::AttribLocals* locals = nullptr;
    bool optional = false;
#line 472 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 11552 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Attribute const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "Attribute"_cs; }
    static cstring static_type_name() { return "Attribute"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Attribute(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    Attribute(Util::SourceInfo srcInfo, IR::ID name) :
    Declaration(srcInfo, name)
    { validate(); }
    Attribute(IR::ID name) :
    Declaration(name)
    { validate(); }
    IRNODE_SUBCLASS(Attribute)
    DECLARE_TYPEINFO_WITH_TYPEID(Attribute, NodeKind::Attribute, Declaration);
};
}  // namespace P4::IR
namespace P4::IR {
class GlobalRef : public Expression {
 public:
    const IR::Node* obj = nullptr;


#line 479 "/root/p4c/frontends/p4-14/ir-v1.def"
    void validate() const override;
#line 11584 "/root/p4c/build/ir/ir-generated.h"
#line 480 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 11587 "/root/p4c/build/ir/ir-generated.h"
#line 481 "/root/p4c/frontends/p4-14/ir-v1.def"
    IR::ID Name() const;
#line 11590 "/root/p4c/build/ir/ir-generated.h"
#line 482 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 11593 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::GlobalRef const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "GlobalRef"_cs; }
    static cstring static_type_name() { return "GlobalRef"_cs; }
    void toJSON(JSONGenerator & json) const override;
    GlobalRef(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    GlobalRef(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Node* obj) :
    Expression(srcInfo, type), obj(obj)
    {
#line 478 "/root/p4c/frontends/p4-14/ir-v1.def"
{ type = obj->to<IInstance>()->getType(); }
#line 11610 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    GlobalRef(const IR::Type* type, const IR::Node* obj) :
    Expression(type), obj(obj)
    {
#line 478 "/root/p4c/frontends/p4-14/ir-v1.def"
{ type = obj->to<IInstance>()->getType(); }
#line 11617 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    GlobalRef(Util::SourceInfo srcInfo, const IR::Node* obj) :
    Expression(srcInfo), obj(obj)
    {
#line 478 "/root/p4c/frontends/p4-14/ir-v1.def"
{ type = obj->to<IInstance>()->getType(); }
#line 11624 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    GlobalRef(const IR::Node* obj) :
    obj(obj)
    {
#line 478 "/root/p4c/frontends/p4-14/ir-v1.def"
{ type = obj->to<IInstance>()->getType(); }
#line 11631 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(GlobalRef)
    DECLARE_TYPEINFO_WITH_TYPEID(GlobalRef, NodeKind::GlobalRef, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
class AttributeRef : public Expression {
 public:
    cstring extern_name;
    const IR::Type_Extern* extern_type = nullptr;
    const IR::Attribute* attrib = nullptr;
#line 490 "/root/p4c/frontends/p4-14/ir-v1.def"
    cstring toString() const override;
#line 11645 "/root/p4c/build/ir/ir-generated.h"
#line 491 "/root/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 11648 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::AttributeRef const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "AttributeRef"_cs; }
    static cstring static_type_name() { return "AttributeRef"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    AttributeRef(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    AttributeRef(Util::SourceInfo srcInfo, const IR::Type* type, cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib) :
    Expression(srcInfo, type), extern_name(extern_name), extern_type(extern_type), attrib(attrib)
    {
#line 489 "/root/p4c/frontends/p4-14/ir-v1.def"
{ type = attrib->type; }
#line 11667 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    AttributeRef(const IR::Type* type, cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib) :
    Expression(type), extern_name(extern_name), extern_type(extern_type), attrib(attrib)
    {
#line 489 "/root/p4c/frontends/p4-14/ir-v1.def"
{ type = attrib->type; }
#line 11674 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    AttributeRef(Util::SourceInfo srcInfo, cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib) :
    Expression(srcInfo), extern_name(extern_name), extern_type(extern_type), attrib(attrib)
    {
#line 489 "/root/p4c/frontends/p4-14/ir-v1.def"
{ type = attrib->type; }
#line 11681 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    AttributeRef(cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib) :
    extern_name(extern_name), extern_type(extern_type), attrib(attrib)
    {
#line 489 "/root/p4c/frontends/p4-14/ir-v1.def"
{ type = attrib->type; }
#line 11688 "/root/p4c/build/ir/ir-generated.h"
     validate(); }
    IRNODE_SUBCLASS(AttributeRef)
    DECLARE_TYPEINFO_WITH_TYPEID(AttributeRef, NodeKind::AttributeRef, Expression);
};
}  // namespace P4::IR
namespace P4::IR {
class V1Program : public Node {
 public:
    IR::NameMap<IR::Node, std::multimap> scope;
#line 498 "/root/p4c/frontends/p4-14/ir-v1.def"
    explicit V1Program();
#line 11700 "/root/p4c/build/ir/ir-generated.h"
#line 500 "/root/p4c/frontends/p4-14/ir-v1.def"
    template<class T> const T *get(cstring name) const { return scope.get<T>(name); }
#line 11703 "/root/p4c/build/ir/ir-generated.h"
#line 502 "/root/p4c/frontends/p4-14/ir-v1.def"
    void add(cstring name, IR::Node const * n);
#line 11706 "/root/p4c/build/ir/ir-generated.h"
    IRNODE_DECLARE_APPLY_OVERLOAD(V1Program)
    bool operator==(IR::V1Program const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "V1Program"_cs; }
    static cstring static_type_name() { return "V1Program"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    V1Program(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(V1Program)
    DECLARE_TYPEINFO_WITH_TYPEID(V1Program, NodeKind::V1Program, Node);
};
}  // namespace P4::IR
namespace P4::IR {
/** @} */
/* end group irdefs */
class P5Table : public Declaration, public virtual IAnnotated, public virtual ISimpleNamespace {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::ParameterList* parameters = nullptr;
    const IR::BlockStatement* body = nullptr;
#line 6 "/root/p4c/frontends/p5/ir-p5.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 11734 "/root/p4c/build/ir/ir-generated.h"
#line 7 "/root/p4c/frontends/p5/ir-p5.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 11737 "/root/p4c/build/ir/ir-generated.h"
#line 9 "/root/p4c/frontends/p5/ir-p5.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 11740 "/root/p4c/build/ir/ir-generated.h"
#line 11 "/root/p4c/frontends/p5/ir-p5.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 11743 "/root/p4c/build/ir/ir-generated.h"
#line 13 "/root/p4c/frontends/p5/ir-p5.def"
    const IR::IDeclaration *getDeclByName(std::string_view name) const override;
#line 11746 "/root/p4c/build/ir/ir-generated.h"
#line 16 "/root/p4c/frontends/p5/ir-p5.def"
    void dbprint(std::ostream & out) const override;
#line 11749 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P5Table const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "P5Table"_cs; }
    static cstring static_type_name() { return "P5Table"_cs; }
    void toJSON(JSONGenerator & json) const override;
    P5Table(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    P5Table(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(srcInfo, name), annotations(annotations), parameters(parameters), body(body)
    { validate(); }
    P5Table(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(name), annotations(annotations), parameters(parameters), body(body)
    { validate(); }
    P5Table(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(srcInfo, name), parameters(parameters), body(body)
    { validate(); }
    P5Table(IR::ID name, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(name), parameters(parameters), body(body)
    { validate(); }
    IRNODE_SUBCLASS(P5Table)
    DECLARE_TYPEINFO_WITH_TYPEID(P5Table, NodeKind::P5Table, Declaration, IAnnotated, ISimpleNamespace);
};
}  // namespace P4::IR
namespace P4::IR {
class P5KeyElement : public Node, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::Expression* expr = nullptr;
    IR::ID matchType;
    IR::BlockStatement control;
#line 24 "/root/p4c/frontends/p5/ir-p5.def"
    void dbprint(std::ostream & out) const override;
#line 11788 "/root/p4c/build/ir/ir-generated.h"
#line 26 "/root/p4c/frontends/p5/ir-p5.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 11791 "/root/p4c/build/ir/ir-generated.h"
#line 27 "/root/p4c/frontends/p5/ir-p5.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 11794 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P5KeyElement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "P5KeyElement"_cs; }
    static cstring static_type_name() { return "P5KeyElement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P5KeyElement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    P5KeyElement(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, const IR::Expression* expr, IR::ID matchType, IR::BlockStatement control) :
    Node(srcInfo), annotations(annotations), expr(expr), matchType(matchType), control(control)
    { validate(); }
    P5KeyElement(IR::Vector<IR::Annotation> annotations, const IR::Expression* expr, IR::ID matchType, IR::BlockStatement control) :
    annotations(annotations), expr(expr), matchType(matchType), control(control)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo, const IR::Expression* expr, IR::ID matchType, IR::BlockStatement control) :
    Node(srcInfo), expr(expr), matchType(matchType), control(control)
    { validate(); }
    P5KeyElement(const IR::Expression* expr, IR::ID matchType, IR::BlockStatement control) :
    expr(expr), matchType(matchType), control(control)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, IR::ID matchType, IR::BlockStatement control) :
    Node(srcInfo), annotations(annotations), matchType(matchType), control(control)
    { validate(); }
    P5KeyElement(IR::Vector<IR::Annotation> annotations, IR::ID matchType, IR::BlockStatement control) :
    annotations(annotations), matchType(matchType), control(control)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo, IR::ID matchType, IR::BlockStatement control) :
    Node(srcInfo), matchType(matchType), control(control)
    { validate(); }
    P5KeyElement(IR::ID matchType, IR::BlockStatement control) :
    matchType(matchType), control(control)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, const IR::Expression* expr, IR::BlockStatement control) :
    Node(srcInfo), annotations(annotations), expr(expr), control(control)
    { validate(); }
    P5KeyElement(IR::Vector<IR::Annotation> annotations, const IR::Expression* expr, IR::BlockStatement control) :
    annotations(annotations), expr(expr), control(control)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo, const IR::Expression* expr, IR::BlockStatement control) :
    Node(srcInfo), expr(expr), control(control)
    { validate(); }
    P5KeyElement(const IR::Expression* expr, IR::BlockStatement control) :
    expr(expr), control(control)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, IR::BlockStatement control) :
    Node(srcInfo), annotations(annotations), control(control)
    { validate(); }
    P5KeyElement(IR::Vector<IR::Annotation> annotations, IR::BlockStatement control) :
    annotations(annotations), control(control)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo, IR::BlockStatement control) :
    Node(srcInfo), control(control)
    { validate(); }
    P5KeyElement(IR::BlockStatement control) :
    control(control)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, const IR::Expression* expr, IR::ID matchType) :
    Node(srcInfo), annotations(annotations), expr(expr), matchType(matchType)
    { validate(); }
    P5KeyElement(IR::Vector<IR::Annotation> annotations, const IR::Expression* expr, IR::ID matchType) :
    annotations(annotations), expr(expr), matchType(matchType)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo, const IR::Expression* expr, IR::ID matchType) :
    Node(srcInfo), expr(expr), matchType(matchType)
    { validate(); }
    P5KeyElement(const IR::Expression* expr, IR::ID matchType) :
    expr(expr), matchType(matchType)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, IR::ID matchType) :
    Node(srcInfo), annotations(annotations), matchType(matchType)
    { validate(); }
    P5KeyElement(IR::Vector<IR::Annotation> annotations, IR::ID matchType) :
    annotations(annotations), matchType(matchType)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo, IR::ID matchType) :
    Node(srcInfo), matchType(matchType)
    { validate(); }
    P5KeyElement(IR::ID matchType) :
    matchType(matchType)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, const IR::Expression* expr) :
    Node(srcInfo), annotations(annotations), expr(expr)
    { validate(); }
    P5KeyElement(IR::Vector<IR::Annotation> annotations, const IR::Expression* expr) :
    annotations(annotations), expr(expr)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Node(srcInfo), expr(expr)
    { validate(); }
    P5KeyElement(const IR::Expression* expr) :
    expr(expr)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
    P5KeyElement(IR::Vector<IR::Annotation> annotations) :
    annotations(annotations)
    { validate(); }
    P5KeyElement(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    P5KeyElement() 
    { validate(); }
    IRNODE_SUBCLASS(P5KeyElement)
    DECLARE_TYPEINFO_WITH_TYPEID(P5KeyElement, NodeKind::P5KeyElement, Node, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class P5KeyCase : public Node, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    const IR::Expression* label = nullptr;
    IR::Vector<IR::P5KeyElement> elements;
#line 34 "/root/p4c/frontends/p5/ir-p5.def"
    void dbprint(std::ostream & out) const override;
#line 11914 "/root/p4c/build/ir/ir-generated.h"
#line 36 "/root/p4c/frontends/p5/ir-p5.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 11917 "/root/p4c/build/ir/ir-generated.h"
#line 37 "/root/p4c/frontends/p5/ir-p5.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 11920 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P5KeyCase const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "P5KeyCase"_cs; }
    static cstring static_type_name() { return "P5KeyCase"_cs; }
    void toJSON(JSONGenerator & json) const override;
    P5KeyCase(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    P5KeyCase(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, const IR::Expression* label, IR::Vector<IR::P5KeyElement> elements) :
    Node(srcInfo), annotations(annotations), label(label), elements(elements)
    { validate(); }
    P5KeyCase(IR::Vector<IR::Annotation> annotations, const IR::Expression* label, IR::Vector<IR::P5KeyElement> elements) :
    annotations(annotations), label(label), elements(elements)
    { validate(); }
    P5KeyCase(Util::SourceInfo srcInfo, const IR::Expression* label, IR::Vector<IR::P5KeyElement> elements) :
    Node(srcInfo), label(label), elements(elements)
    { validate(); }
    P5KeyCase(const IR::Expression* label, IR::Vector<IR::P5KeyElement> elements) :
    label(label), elements(elements)
    { validate(); }
    P5KeyCase(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, IR::Vector<IR::P5KeyElement> elements) :
    Node(srcInfo), annotations(annotations), elements(elements)
    { validate(); }
    P5KeyCase(IR::Vector<IR::Annotation> annotations, IR::Vector<IR::P5KeyElement> elements) :
    annotations(annotations), elements(elements)
    { validate(); }
    P5KeyCase(Util::SourceInfo srcInfo, IR::Vector<IR::P5KeyElement> elements) :
    Node(srcInfo), elements(elements)
    { validate(); }
    P5KeyCase(IR::Vector<IR::P5KeyElement> elements) :
    elements(elements)
    { validate(); }
    P5KeyCase(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, const IR::Expression* label) :
    Node(srcInfo), annotations(annotations), label(label)
    { validate(); }
    P5KeyCase(IR::Vector<IR::Annotation> annotations, const IR::Expression* label) :
    annotations(annotations), label(label)
    { validate(); }
    P5KeyCase(Util::SourceInfo srcInfo, const IR::Expression* label) :
    Node(srcInfo), label(label)
    { validate(); }
    P5KeyCase(const IR::Expression* label) :
    label(label)
    { validate(); }
    P5KeyCase(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
    P5KeyCase(IR::Vector<IR::Annotation> annotations) :
    annotations(annotations)
    { validate(); }
    P5KeyCase(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    P5KeyCase() 
    { validate(); }
    IRNODE_SUBCLASS(P5KeyCase)
    DECLARE_TYPEINFO_WITH_TYPEID(P5KeyCase, NodeKind::P5KeyCase, Node, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class P5Key : public Statement {
 public:
    const IR::Expression* select = nullptr;

    IR::Vector<IR::P5KeyCase> cases;

    IR::Vector<IR::P5KeyElement> elements;

#line 44 "/root/p4c/frontends/p5/ir-p5.def"
    void dbprint(std::ostream & out) const override;
#line 11994 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P5Key const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "P5Key"_cs; }
    static cstring static_type_name() { return "P5Key"_cs; }
    void toJSON(JSONGenerator & json) const override;
    P5Key(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    P5Key(Util::SourceInfo srcInfo, const IR::Expression* select, IR::Vector<IR::P5KeyCase> cases, IR::Vector<IR::P5KeyElement> elements) :
    Statement(srcInfo), select(select), cases(cases), elements(elements)
    { validate(); }
    P5Key(const IR::Expression* select, IR::Vector<IR::P5KeyCase> cases, IR::Vector<IR::P5KeyElement> elements) :
    select(select), cases(cases), elements(elements)
    { validate(); }
    P5Key(Util::SourceInfo srcInfo, IR::Vector<IR::P5KeyCase> cases, IR::Vector<IR::P5KeyElement> elements) :
    Statement(srcInfo), cases(cases), elements(elements)
    { validate(); }
    P5Key(IR::Vector<IR::P5KeyCase> cases, IR::Vector<IR::P5KeyElement> elements) :
    cases(cases), elements(elements)
    { validate(); }
    P5Key(Util::SourceInfo srcInfo, const IR::Expression* select, IR::Vector<IR::P5KeyElement> elements) :
    Statement(srcInfo), select(select), elements(elements)
    { validate(); }
    P5Key(const IR::Expression* select, IR::Vector<IR::P5KeyElement> elements) :
    select(select), elements(elements)
    { validate(); }
    P5Key(Util::SourceInfo srcInfo, IR::Vector<IR::P5KeyElement> elements) :
    Statement(srcInfo), elements(elements)
    { validate(); }
    P5Key(IR::Vector<IR::P5KeyElement> elements) :
    elements(elements)
    { validate(); }
    P5Key(Util::SourceInfo srcInfo, const IR::Expression* select, IR::Vector<IR::P5KeyCase> cases) :
    Statement(srcInfo), select(select), cases(cases)
    { validate(); }
    P5Key(const IR::Expression* select, IR::Vector<IR::P5KeyCase> cases) :
    select(select), cases(cases)
    { validate(); }
    P5Key(Util::SourceInfo srcInfo, IR::Vector<IR::P5KeyCase> cases) :
    Statement(srcInfo), cases(cases)
    { validate(); }
    P5Key(IR::Vector<IR::P5KeyCase> cases) :
    cases(cases)
    { validate(); }
    P5Key(Util::SourceInfo srcInfo, const IR::Expression* select) :
    Statement(srcInfo), select(select)
    { validate(); }
    P5Key(const IR::Expression* select) :
    select(select)
    { validate(); }
    P5Key(Util::SourceInfo srcInfo) :
    Statement(srcInfo)
    { validate(); }
    P5Key() 
    { validate(); }
    IRNODE_SUBCLASS(P5Key)
    DECLARE_TYPEINFO_WITH_TYPEID(P5Key, NodeKind::P5Key, Statement);
};
}  // namespace P4::IR
namespace P4::IR {

class IntMod : public Operation_Unary {
 public:
    unsigned width;
    cstring getStringOp() const override { return cstring("><"); }
    int getPrecedence() const override { return DBPrint::Prec_Low; }
    bool operator==(IR::IntMod const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "IntMod"_cs; }
    static cstring static_type_name() { return "IntMod"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    IntMod(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Unary const & a) const override;
    bool operator==(IR::Operation const & a) const override;
    bool operator==(IR::Expression const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IntMod(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr, unsigned width) :
    Operation_Unary(srcInfo, type, expr), width(width)
    { validate(); }
    IntMod(const IR::Type* type, const IR::Expression* expr, unsigned width) :
    Operation_Unary(type, expr), width(width)
    { validate(); }
    IntMod(Util::SourceInfo srcInfo, const IR::Expression* expr, unsigned width) :
    Operation_Unary(srcInfo, expr), width(width)
    { validate(); }
    IntMod(const IR::Expression* expr, unsigned width) :
    Operation_Unary(expr), width(width)
    { validate(); }
    IRNODE_SUBCLASS(IntMod)
    DECLARE_TYPEINFO_WITH_TYPEID(IntMod, NodeKind::IntMod, Operation_Unary);
};
}  // namespace P4::IR
namespace P4::IR {
class IDPDKNode : public virtual INode {
 public:
#line 2 "/root/p4c/backends/dpdk/dpdk.def"
    virtual std::ostream & toSpec(std::ostream & out) const = 0;
#line 12099 "/root/p4c/build/ir/ir-generated.h"
    DECLARE_TYPEINFO_WITH_TYPEID(IDPDKNode, NodeKind::IDPDKNode, INode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkDeclaration : public Node, public virtual IDPDKNode {
 public:
    const IR::Declaration* global = nullptr;
#line 7 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12109 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkDeclaration const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkDeclaration"_cs; }
    static cstring static_type_name() { return "DpdkDeclaration"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkDeclaration(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    DpdkDeclaration(Util::SourceInfo srcInfo, const IR::Declaration* global) :
    Node(srcInfo), global(global)
    { validate(); }
    DpdkDeclaration(const IR::Declaration* global) :
    global(global)
    { validate(); }
    IRNODE_SUBCLASS(DpdkDeclaration)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkDeclaration, NodeKind::DpdkDeclaration, Node, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkExternDeclaration : public Declaration_Instance, public virtual IDPDKNode {
 public:
#line 12 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12136 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkExternDeclaration const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkExternDeclaration"_cs; }
    static cstring static_type_name() { return "DpdkExternDeclaration"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkExternDeclaration(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration_Instance const & a) const override;
    bool operator==(IR::Declaration const & a) const override;
    bool operator==(IR::StatOrDecl const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkExternDeclaration(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration_Instance(srcInfo, name, annotations, type, arguments, initializer)
    { validate(); }
    DpdkExternDeclaration(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration_Instance(name, annotations, type, arguments, initializer)
    { validate(); }
    DpdkExternDeclaration(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration_Instance(srcInfo, name, type, arguments, initializer)
    { validate(); }
    DpdkExternDeclaration(IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration_Instance(name, type, arguments, initializer)
    { validate(); }
    DpdkExternDeclaration(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration_Instance(srcInfo, name, annotations, type, arguments)
    { validate(); }
    DpdkExternDeclaration(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration_Instance(name, annotations, type, arguments)
    { validate(); }
    DpdkExternDeclaration(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration_Instance(srcInfo, name, type, arguments)
    { validate(); }
    DpdkExternDeclaration(IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration_Instance(name, type, arguments)
    { validate(); }
    IRNODE_SUBCLASS(DpdkExternDeclaration)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkExternDeclaration, NodeKind::DpdkExternDeclaration, Declaration_Instance, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkHeaderType : public Type_Header, public virtual IDPDKNode {
 public:
#line 17 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12181 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkHeaderType const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkHeaderType"_cs; }
    static cstring static_type_name() { return "DpdkHeaderType"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkHeaderType(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Header const & a) const override;
    bool operator==(IR::Type_StructLike const & a) const override;
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
    DpdkHeaderType(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(name, annotations, typeParameters, fields)
    { validate(); }
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(srcInfo, name, typeParameters, fields)
    { validate(); }
    DpdkHeaderType(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(name, typeParameters, fields)
    { validate(); }
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(srcInfo, name, annotations, fields)
    { validate(); }
    DpdkHeaderType(IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(name, annotations, fields)
    { validate(); }
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(srcInfo, name, fields)
    { validate(); }
    DpdkHeaderType(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(name, fields)
    { validate(); }
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_Header(srcInfo, name, annotations, typeParameters)
    { validate(); }
    DpdkHeaderType(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_Header(name, annotations, typeParameters)
    { validate(); }
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Header(srcInfo, name, typeParameters)
    { validate(); }
    DpdkHeaderType(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Header(name, typeParameters)
    { validate(); }
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_Header(srcInfo, name, annotations)
    { validate(); }
    DpdkHeaderType(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_Header(name, annotations)
    { validate(); }
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Header(srcInfo, name)
    { validate(); }
    DpdkHeaderType(IR::ID name) :
    Type_Header(name)
    { validate(); }
    IRNODE_SUBCLASS(DpdkHeaderType)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkHeaderType, NodeKind::DpdkHeaderType, Type_Header, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkHeaderInstance : public Node, public virtual IDPDKNode {
 public:
    const IR::Declaration_Variable* name = nullptr;
    const IR::Type_Header* headerType = nullptr;
#line 24 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12253 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkHeaderInstance const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkHeaderInstance"_cs; }
    static cstring static_type_name() { return "DpdkHeaderInstance"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkHeaderInstance(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    DpdkHeaderInstance(Util::SourceInfo srcInfo, const IR::Declaration_Variable* name, const IR::Type_Header* headerType) :
    Node(srcInfo), name(name), headerType(headerType)
    { validate(); }
    DpdkHeaderInstance(const IR::Declaration_Variable* name, const IR::Type_Header* headerType) :
    name(name), headerType(headerType)
    { validate(); }
    IRNODE_SUBCLASS(DpdkHeaderInstance)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkHeaderInstance, NodeKind::DpdkHeaderInstance, Node, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkStructType : public Type_Struct, public virtual IDPDKNode {
 public:
#line 29 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12280 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkStructType const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkStructType"_cs; }
    static cstring static_type_name() { return "DpdkStructType"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkStructType(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Struct const & a) const override;
    bool operator==(IR::Type_StructLike const & a) const override;
    bool operator==(IR::Type_Declaration const & a) const override;
    bool operator==(IR::Type const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
    DpdkStructType(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(name, annotations, typeParameters, fields)
    { validate(); }
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(srcInfo, name, typeParameters, fields)
    { validate(); }
    DpdkStructType(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(name, typeParameters, fields)
    { validate(); }
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(srcInfo, name, annotations, fields)
    { validate(); }
    DpdkStructType(IR::ID name, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(name, annotations, fields)
    { validate(); }
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(srcInfo, name, fields)
    { validate(); }
    DpdkStructType(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(name, fields)
    { validate(); }
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_Struct(srcInfo, name, annotations, typeParameters)
    { validate(); }
    DpdkStructType(IR::ID name, IR::Vector<IR::Annotation> annotations, const IR::TypeParameters* typeParameters) :
    Type_Struct(name, annotations, typeParameters)
    { validate(); }
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Struct(srcInfo, name, typeParameters)
    { validate(); }
    DpdkStructType(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Struct(name, typeParameters)
    { validate(); }
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_Struct(srcInfo, name, annotations)
    { validate(); }
    DpdkStructType(IR::ID name, IR::Vector<IR::Annotation> annotations) :
    Type_Struct(name, annotations)
    { validate(); }
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Struct(srcInfo, name)
    { validate(); }
    DpdkStructType(IR::ID name) :
    Type_Struct(name)
    { validate(); }
    IRNODE_SUBCLASS(DpdkStructType)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkStructType, NodeKind::DpdkStructType, Type_Struct, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkAsmStatement : public Node, public virtual IDPDKNode {
 public:
#line 34 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12350 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkAsmStatement"_cs; }
    static cstring static_type_name() { return "DpdkAsmStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkAsmStatement(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
 protected:
    DpdkAsmStatement(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
    DpdkAsmStatement() 
    { validate(); }
    IRNODE_ABSTRACT_SUBCLASS(DpdkAsmStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkAsmStatement, NodeKind::DpdkAsmStatement, Node, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkAction : public Node, public virtual IAnnotated {
 public:
    IR::Vector<IR::Annotation> annotations;
    IR::IndexedVector<IR::DpdkAsmStatement> statements;
    IR::ID name;
    IR::ParameterList para;
#line 42 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const;
#line 12377 "/root/p4c/build/ir/ir-generated.h"
#line 43 "/root/p4c/backends/dpdk/dpdk.def"
    IR::Vector<IR::Annotation> const & getAnnotations() const override;
#line 12380 "/root/p4c/build/ir/ir-generated.h"
#line 44 "/root/p4c/backends/dpdk/dpdk.def"
    IR::Vector<IR::Annotation> & getAnnotations() override;
#line 12383 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkAction const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkAction"_cs; }
    static cstring static_type_name() { return "DpdkAction"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkAction(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    DpdkAction(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::ID name, IR::ParameterList para) :
    Node(srcInfo), annotations(annotations), statements(statements), name(name), para(para)
    { validate(); }
    DpdkAction(IR::Vector<IR::Annotation> annotations, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::ID name, IR::ParameterList para) :
    annotations(annotations), statements(statements), name(name), para(para)
    { validate(); }
    DpdkAction(Util::SourceInfo srcInfo, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::ID name, IR::ParameterList para) :
    Node(srcInfo), statements(statements), name(name), para(para)
    { validate(); }
    DpdkAction(IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::ID name, IR::ParameterList para) :
    statements(statements), name(name), para(para)
    { validate(); }
    IRNODE_SUBCLASS(DpdkAction)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkAction, NodeKind::DpdkAction, Node, IAnnotated);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkTable : public Node {
 public:
    cstring name;
    const IR::Key* match_keys = nullptr;
    const IR::ActionList* actions = nullptr;
    const IR::Expression* default_action = nullptr;
    const IR::TableProperties* properties = nullptr;
    IR::ParameterList default_action_paraList;
#line 55 "/root/p4c/backends/dpdk/dpdk.def"
    const IR::Key *getKey() const;
#line 12423 "/root/p4c/build/ir/ir-generated.h"
#line 63 "/root/p4c/backends/dpdk/dpdk.def"
    const IR::EntriesList *getEntries() const;
#line 12426 "/root/p4c/build/ir/ir-generated.h"
#line 73 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const;
#line 12429 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkTable const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "DpdkTable"_cs; }
    static cstring static_type_name() { return "DpdkTable"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkTable(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    DpdkTable(Util::SourceInfo srcInfo, cstring name, const IR::Key* match_keys, const IR::ActionList* actions, const IR::Expression* default_action, const IR::TableProperties* properties, IR::ParameterList default_action_paraList) :
    Node(srcInfo), name(name), match_keys(match_keys), actions(actions), default_action(default_action), properties(properties), default_action_paraList(default_action_paraList)
    { validate(); }
    DpdkTable(cstring name, const IR::Key* match_keys, const IR::ActionList* actions, const IR::Expression* default_action, const IR::TableProperties* properties, IR::ParameterList default_action_paraList) :
    name(name), match_keys(match_keys), actions(actions), default_action(default_action), properties(properties), default_action_paraList(default_action_paraList)
    { validate(); }
    IRNODE_SUBCLASS(DpdkTable)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkTable, NodeKind::DpdkTable, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkSelector : public Node {
 public:
    cstring name;
    const IR::Expression* group_id = nullptr;
    const IR::Expression* member_id = nullptr;
    const IR::Key* selectors = nullptr;
    int n_groups_max;
    int n_members_per_group_max;
#line 86 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const;
#line 12462 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkSelector const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "DpdkSelector"_cs; }
    static cstring static_type_name() { return "DpdkSelector"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkSelector(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    DpdkSelector(Util::SourceInfo srcInfo, cstring name, const IR::Expression* group_id, const IR::Expression* member_id, const IR::Key* selectors, int n_groups_max, int n_members_per_group_max) :
    Node(srcInfo), name(name), group_id(group_id), member_id(member_id), selectors(selectors), n_groups_max(n_groups_max), n_members_per_group_max(n_members_per_group_max)
    { validate(); }
    DpdkSelector(cstring name, const IR::Expression* group_id, const IR::Expression* member_id, const IR::Key* selectors, int n_groups_max, int n_members_per_group_max) :
    name(name), group_id(group_id), member_id(member_id), selectors(selectors), n_groups_max(n_groups_max), n_members_per_group_max(n_members_per_group_max)
    { validate(); }
    IRNODE_SUBCLASS(DpdkSelector)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkSelector, NodeKind::DpdkSelector, Node);
};
}  // namespace P4::IR
namespace P4::IR {

class DpdkLearner : public Node {
 public:
    cstring name;
    const IR::Key* match_keys = nullptr;
    const IR::ActionList* actions = nullptr;
    const IR::Expression* default_action = nullptr;
    const IR::TableProperties* properties = nullptr;
#line 102 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const;
#line 12495 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkLearner const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "DpdkLearner"_cs; }
    static cstring static_type_name() { return "DpdkLearner"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkLearner(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    DpdkLearner(Util::SourceInfo srcInfo, cstring name, const IR::Key* match_keys, const IR::ActionList* actions, const IR::Expression* default_action, const IR::TableProperties* properties) :
    Node(srcInfo), name(name), match_keys(match_keys), actions(actions), default_action(default_action), properties(properties)
    { validate(); }
    DpdkLearner(cstring name, const IR::Key* match_keys, const IR::ActionList* actions, const IR::Expression* default_action, const IR::TableProperties* properties) :
    name(name), match_keys(match_keys), actions(actions), default_action(default_action), properties(properties)
    { validate(); }
    IRNODE_SUBCLASS(DpdkLearner)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkLearner, NodeKind::DpdkLearner, Node);
};
}  // namespace P4::IR
namespace P4::IR {

class DpdkAsmProgram : public Node {
 public:
    IR::IndexedVector<IR::DpdkHeaderType> headerType;
    IR::IndexedVector<IR::DpdkStructType> structType;
    IR::IndexedVector<IR::DpdkHeaderInstance> headerInstance;
    IR::IndexedVector<IR::DpdkExternDeclaration> externDeclarations;
    IR::IndexedVector<IR::DpdkAction> actions;
    IR::IndexedVector<IR::DpdkTable> tables;
    IR::IndexedVector<IR::DpdkSelector> selectors;
    IR::IndexedVector<IR::DpdkLearner> learners;
    IR::IndexedVector<IR::DpdkAsmStatement> statements;
    IR::IndexedVector<IR::DpdkDeclaration> globals;
#line 119 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const;
#line 12533 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkAsmProgram const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkAsmProgram"_cs; }
    static cstring static_type_name() { return "DpdkAsmProgram"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkAsmProgram(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    DpdkAsmProgram(Util::SourceInfo srcInfo, IR::IndexedVector<IR::DpdkHeaderType> headerType, IR::IndexedVector<IR::DpdkStructType> structType, IR::IndexedVector<IR::DpdkHeaderInstance> headerInstance, IR::IndexedVector<IR::DpdkExternDeclaration> externDeclarations, IR::IndexedVector<IR::DpdkAction> actions, IR::IndexedVector<IR::DpdkTable> tables, IR::IndexedVector<IR::DpdkSelector> selectors, IR::IndexedVector<IR::DpdkLearner> learners, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::IndexedVector<IR::DpdkDeclaration> globals) :
    Node(srcInfo), headerType(headerType), structType(structType), headerInstance(headerInstance), externDeclarations(externDeclarations), actions(actions), tables(tables), selectors(selectors), learners(learners), statements(statements), globals(globals)
    { validate(); }
    DpdkAsmProgram(IR::IndexedVector<IR::DpdkHeaderType> headerType, IR::IndexedVector<IR::DpdkStructType> structType, IR::IndexedVector<IR::DpdkHeaderInstance> headerInstance, IR::IndexedVector<IR::DpdkExternDeclaration> externDeclarations, IR::IndexedVector<IR::DpdkAction> actions, IR::IndexedVector<IR::DpdkTable> tables, IR::IndexedVector<IR::DpdkSelector> selectors, IR::IndexedVector<IR::DpdkLearner> learners, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::IndexedVector<IR::DpdkDeclaration> globals) :
    headerType(headerType), structType(structType), headerInstance(headerInstance), externDeclarations(externDeclarations), actions(actions), tables(tables), selectors(selectors), learners(learners), statements(statements), globals(globals)
    { validate(); }
    IRNODE_SUBCLASS(DpdkAsmProgram)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkAsmProgram, NodeKind::DpdkAsmProgram, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkListStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    IR::IndexedVector<IR::DpdkAsmStatement> statements;
#line 124 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12562 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkListStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkListStatement"_cs; }
    static cstring static_type_name() { return "DpdkListStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkListStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkListStatement(Util::SourceInfo srcInfo, IR::IndexedVector<IR::DpdkAsmStatement> statements) :
    DpdkAsmStatement(srcInfo), statements(statements)
    { validate(); }
    DpdkListStatement(IR::IndexedVector<IR::DpdkAsmStatement> statements) :
    statements(statements)
    { validate(); }
    DpdkListStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
    DpdkListStatement() 
    { validate(); }
    IRNODE_SUBCLASS(DpdkListStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkListStatement, NodeKind::DpdkListStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkApplyStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring table;
#line 129 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12597 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkApplyStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkApplyStatement"_cs; }
    static cstring static_type_name() { return "DpdkApplyStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkApplyStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkApplyStatement(Util::SourceInfo srcInfo, cstring table) :
    DpdkAsmStatement(srcInfo), table(table)
    { validate(); }
    DpdkApplyStatement(cstring table) :
    table(table)
    { validate(); }
    IRNODE_SUBCLASS(DpdkApplyStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkApplyStatement, NodeKind::DpdkApplyStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkLearnStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    IR::ID action;
    const IR::Expression* timeout = nullptr;
    const IR::Expression* argument = nullptr;
#line 136 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12627 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkLearnStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkLearnStatement"_cs; }
    static cstring static_type_name() { return "DpdkLearnStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkLearnStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkLearnStatement(Util::SourceInfo srcInfo, IR::ID action, const IR::Expression* timeout, const IR::Expression* argument) :
    DpdkAsmStatement(srcInfo), action(action), timeout(timeout), argument(argument)
    { validate(); }
    DpdkLearnStatement(IR::ID action, const IR::Expression* timeout, const IR::Expression* argument) :
    action(action), timeout(timeout), argument(argument)
    { validate(); }
    DpdkLearnStatement(Util::SourceInfo srcInfo, IR::ID action, const IR::Expression* timeout) :
    DpdkAsmStatement(srcInfo), action(action), timeout(timeout)
    { validate(); }
    DpdkLearnStatement(IR::ID action, const IR::Expression* timeout) :
    action(action), timeout(timeout)
    { validate(); }
    IRNODE_SUBCLASS(DpdkLearnStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkLearnStatement, NodeKind::DpdkLearnStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkMirrorStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* slotId = nullptr;
    const IR::Expression* sessionId = nullptr;
#line 142 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12665 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkMirrorStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkMirrorStatement"_cs; }
    static cstring static_type_name() { return "DpdkMirrorStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkMirrorStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkMirrorStatement(Util::SourceInfo srcInfo, const IR::Expression* slotId, const IR::Expression* sessionId) :
    DpdkAsmStatement(srcInfo), slotId(slotId), sessionId(sessionId)
    { validate(); }
    DpdkMirrorStatement(const IR::Expression* slotId, const IR::Expression* sessionId) :
    slotId(slotId), sessionId(sessionId)
    { validate(); }
    IRNODE_SUBCLASS(DpdkMirrorStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkMirrorStatement, NodeKind::DpdkMirrorStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkEmitStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* header = nullptr;
#line 147 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12695 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkEmitStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkEmitStatement"_cs; }
    static cstring static_type_name() { return "DpdkEmitStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkEmitStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkEmitStatement(Util::SourceInfo srcInfo, const IR::Expression* header) :
    DpdkAsmStatement(srcInfo), header(header)
    { validate(); }
    DpdkEmitStatement(const IR::Expression* header) :
    header(header)
    { validate(); }
    IRNODE_SUBCLASS(DpdkEmitStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkEmitStatement, NodeKind::DpdkEmitStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkExtractStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* header = nullptr;
    const IR::Expression* length = nullptr;
#line 153 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12726 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkExtractStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkExtractStatement"_cs; }
    static cstring static_type_name() { return "DpdkExtractStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkExtractStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkExtractStatement(Util::SourceInfo srcInfo, const IR::Expression* header, const IR::Expression* length) :
    DpdkAsmStatement(srcInfo), header(header), length(length)
    { validate(); }
    DpdkExtractStatement(const IR::Expression* header, const IR::Expression* length) :
    header(header), length(length)
    { validate(); }
    DpdkExtractStatement(Util::SourceInfo srcInfo, const IR::Expression* header) :
    DpdkAsmStatement(srcInfo), header(header)
    { validate(); }
    DpdkExtractStatement(const IR::Expression* header) :
    header(header)
    { validate(); }
    IRNODE_SUBCLASS(DpdkExtractStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkExtractStatement, NodeKind::DpdkExtractStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkLookaheadStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* header = nullptr;
#line 158 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12762 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkLookaheadStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkLookaheadStatement"_cs; }
    static cstring static_type_name() { return "DpdkLookaheadStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkLookaheadStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkLookaheadStatement(Util::SourceInfo srcInfo, const IR::Expression* header) :
    DpdkAsmStatement(srcInfo), header(header)
    { validate(); }
    DpdkLookaheadStatement(const IR::Expression* header) :
    header(header)
    { validate(); }
    IRNODE_SUBCLASS(DpdkLookaheadStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkLookaheadStatement, NodeKind::DpdkLookaheadStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpStatement : public DpdkAsmStatement {
 public:
    cstring instruction;
    cstring label;
#line 164 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12793 "/root/p4c/build/ir/ir-generated.h"
#line 166 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpStatement(cstring instruction, cstring l);
#line 12796 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpStatement(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_ABSTRACT_SUBCLASS(DpdkJmpStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpStatement, NodeKind::DpdkJmpStatement, DpdkAsmStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpLabelStatement : public DpdkJmpStatement {
 public:
#line 172 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpLabelStatement(cstring label);
#line 12815 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpLabelStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpLabelStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpLabelStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpLabelStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkJmpLabelStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpLabelStatement, NodeKind::DpdkJmpLabelStatement, DpdkJmpStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpHitStatement : public DpdkJmpStatement {
 public:
#line 179 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpHitStatement(cstring label);
#line 12836 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpHitStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpHitStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpHitStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpHitStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkJmpHitStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpHitStatement, NodeKind::DpdkJmpHitStatement, DpdkJmpStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpMissStatement : public DpdkJmpStatement {
 public:
#line 186 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpMissStatement(cstring label);
#line 12856 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpMissStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpMissStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpMissStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpMissStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkJmpMissStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpMissStatement, NodeKind::DpdkJmpMissStatement, DpdkJmpStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpActionStatement : public DpdkJmpStatement {
 public:
    IR::ID action;
#line 192 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12877 "/root/p4c/build/ir/ir-generated.h"
#line 195 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpActionStatement(cstring instruction, cstring label, IR::ID action);
#line 12880 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpActionStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpActionStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpActionStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpActionStatement(JSONLoader & json);
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_ABSTRACT_SUBCLASS(DpdkJmpActionStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpActionStatement, NodeKind::DpdkJmpActionStatement, DpdkJmpStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpIfActionRunStatement : public DpdkJmpActionStatement {
 public:
#line 202 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpIfActionRunStatement(cstring label, cstring act);
#line 12900 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpIfActionRunStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpIfActionRunStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpIfActionRunStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpIfActionRunStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpActionStatement const & a) const override;
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkJmpIfActionRunStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpIfActionRunStatement, NodeKind::DpdkJmpIfActionRunStatement, DpdkJmpActionStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpIfActionNotRunStatement : public DpdkJmpActionStatement {
 public:
#line 209 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpIfActionNotRunStatement(cstring label, cstring act);
#line 12921 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpIfActionNotRunStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpIfActionNotRunStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpIfActionNotRunStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpIfActionNotRunStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpActionStatement const & a) const override;
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkJmpIfActionNotRunStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpIfActionNotRunStatement, NodeKind::DpdkJmpIfActionNotRunStatement, DpdkJmpActionStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpHeaderStatement : public DpdkJmpStatement {
 public:
    const IR::Expression* header = nullptr;
#line 215 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 12943 "/root/p4c/build/ir/ir-generated.h"
#line 217 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpHeaderStatement(cstring instruction, cstring label, const IR::Expression* hdr);
#line 12946 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpHeaderStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkJmpHeaderStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpHeaderStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpHeaderStatement(JSONLoader & json);
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_ABSTRACT_SUBCLASS(DpdkJmpHeaderStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpHeaderStatement, NodeKind::DpdkJmpHeaderStatement, DpdkJmpStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpIfInvalidStatement : public DpdkJmpHeaderStatement {
 public:
#line 223 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpIfInvalidStatement(cstring label, const IR::Expression* hdr);
#line 12968 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpIfInvalidStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpIfInvalidStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpIfInvalidStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpIfInvalidStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpHeaderStatement const & a) const override;
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkJmpIfInvalidStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpIfInvalidStatement, NodeKind::DpdkJmpIfInvalidStatement, DpdkJmpHeaderStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpIfValidStatement : public DpdkJmpHeaderStatement {
 public:
#line 230 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpIfValidStatement(cstring label, const IR::Expression* hdr);
#line 12990 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpIfValidStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpIfValidStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpIfValidStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpIfValidStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpHeaderStatement const & a) const override;
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkJmpIfValidStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpIfValidStatement, NodeKind::DpdkJmpIfValidStatement, DpdkJmpHeaderStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpCondStatement : public DpdkJmpStatement {
 public:
    const IR::Expression* src1 = nullptr;
    const IR::Expression* src2 = nullptr;
#line 237 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13013 "/root/p4c/build/ir/ir-generated.h"
#line 239 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpCondStatement(cstring instruction, cstring label, const IR::Expression* src1, const IR::Expression* src2);
#line 13016 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpCondStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkJmpCondStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpCondStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpCondStatement(JSONLoader & json);
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_ABSTRACT_SUBCLASS(DpdkJmpCondStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpCondStatement, NodeKind::DpdkJmpCondStatement, DpdkJmpStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpEqualStatement : public DpdkJmpCondStatement, public virtual IDPDKNode {
 public:
#line 244 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2);
#line 13038 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpEqualStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpEqualStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpEqualStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpEqualStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpCondStatement const & a) const override;
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkJmpEqualStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpEqualStatement, NodeKind::DpdkJmpEqualStatement, DpdkJmpCondStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpNotEqualStatement : public DpdkJmpCondStatement, public virtual IDPDKNode {
 public:
#line 251 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpNotEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2);
#line 13060 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpNotEqualStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpNotEqualStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpNotEqualStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpNotEqualStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpCondStatement const & a) const override;
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkJmpNotEqualStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpNotEqualStatement, NodeKind::DpdkJmpNotEqualStatement, DpdkJmpCondStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpGreaterEqualStatement : public DpdkJmpCondStatement, public virtual IDPDKNode {
 public:
#line 258 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpGreaterEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2);
#line 13082 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpGreaterEqualStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpGreaterEqualStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpGreaterEqualStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpGreaterEqualStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpCondStatement const & a) const override;
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkJmpGreaterEqualStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpGreaterEqualStatement, NodeKind::DpdkJmpGreaterEqualStatement, DpdkJmpCondStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpGreaterStatement : public DpdkJmpCondStatement, public virtual IDPDKNode {
 public:
#line 265 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpGreaterStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2);
#line 13103 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpGreaterStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpGreaterStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpGreaterStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpGreaterStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpCondStatement const & a) const override;
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkJmpGreaterStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpGreaterStatement, NodeKind::DpdkJmpGreaterStatement, DpdkJmpCondStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpLessOrEqualStatement : public DpdkJmpCondStatement, public virtual IDPDKNode {
 public:
#line 272 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpLessOrEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2);
#line 13124 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpLessOrEqualStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpLessOrEqualStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpLessOrEqualStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpLessOrEqualStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpCondStatement const & a) const override;
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkJmpLessOrEqualStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpLessOrEqualStatement, NodeKind::DpdkJmpLessOrEqualStatement, DpdkJmpCondStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkJmpLessStatement : public DpdkJmpCondStatement, public virtual IDPDKNode {
 public:
#line 279 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkJmpLessStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2);
#line 13145 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpLessStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpLessStatement"_cs; }
    static cstring static_type_name() { return "DpdkJmpLessStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpLessStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpCondStatement const & a) const override;
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkJmpLessStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkJmpLessStatement, NodeKind::DpdkJmpLessStatement, DpdkJmpCondStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkRxStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* port = nullptr;
#line 285 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13167 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkRxStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkRxStatement"_cs; }
    static cstring static_type_name() { return "DpdkRxStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkRxStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkRxStatement(Util::SourceInfo srcInfo, const IR::Expression* port) :
    DpdkAsmStatement(srcInfo), port(port)
    { validate(); }
    DpdkRxStatement(const IR::Expression* port) :
    port(port)
    { validate(); }
    IRNODE_SUBCLASS(DpdkRxStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkRxStatement, NodeKind::DpdkRxStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkTxStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* port = nullptr;
#line 291 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13196 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkTxStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkTxStatement"_cs; }
    static cstring static_type_name() { return "DpdkTxStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkTxStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkTxStatement(Util::SourceInfo srcInfo, const IR::Expression* port) :
    DpdkAsmStatement(srcInfo), port(port)
    { validate(); }
    DpdkTxStatement(const IR::Expression* port) :
    port(port)
    { validate(); }
    IRNODE_SUBCLASS(DpdkTxStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkTxStatement, NodeKind::DpdkTxStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkAssignmentStatement : public DpdkAsmStatement {
 public:
    cstring instruction;
    const IR::Expression* dst = nullptr;
#line 299 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkAssignmentStatement(cstring instruction, const IR::Expression* dst);
#line 13226 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkAssignmentStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkAssignmentStatement"_cs; }
    static cstring static_type_name() { return "DpdkAssignmentStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkAssignmentStatement(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_ABSTRACT_SUBCLASS(DpdkAssignmentStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkAssignmentStatement, NodeKind::DpdkAssignmentStatement, DpdkAsmStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkUnaryStatement : public DpdkAssignmentStatement {
 public:
    const IR::Expression* src = nullptr;
#line 305 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13249 "/root/p4c/build/ir/ir-generated.h"
#line 307 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkUnaryStatement(cstring instruction, const IR::Expression* dst, const IR::Expression* src);
#line 13252 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkUnaryStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkUnaryStatement"_cs; }
    static cstring static_type_name() { return "DpdkUnaryStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkUnaryStatement(JSONLoader & json);
    bool operator==(IR::DpdkAssignmentStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_ABSTRACT_SUBCLASS(DpdkUnaryStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkUnaryStatement, NodeKind::DpdkUnaryStatement, DpdkAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkMovStatement : public DpdkUnaryStatement {
 public:
#line 312 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkMovStatement(const IR::Expression* dst, const IR::Expression* src);
#line 13274 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkMovStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkMovStatement"_cs; }
    static cstring static_type_name() { return "DpdkMovStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkMovStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkUnaryStatement const & a) const override;
    bool operator==(IR::DpdkAssignmentStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkMovStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkMovStatement, NodeKind::DpdkMovStatement, DpdkUnaryStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkMovhStatement : public DpdkUnaryStatement {
 public:
#line 318 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkMovhStatement(const IR::Expression* dst, const IR::Expression* src);
#line 13296 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkMovhStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkMovhStatement"_cs; }
    static cstring static_type_name() { return "DpdkMovhStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkMovhStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkUnaryStatement const & a) const override;
    bool operator==(IR::DpdkAssignmentStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkMovhStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkMovhStatement, NodeKind::DpdkMovhStatement, DpdkUnaryStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkBinaryStatement : public DpdkAssignmentStatement {
 public:
    const IR::Expression* src1 = nullptr;
    const IR::Expression* src2 = nullptr;
#line 326 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13320 "/root/p4c/build/ir/ir-generated.h"
#line 328 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkBinaryStatement(cstring instruction, const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 13323 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkBinaryStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkBinaryStatement"_cs; }
    static cstring static_type_name() { return "DpdkBinaryStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkBinaryStatement(JSONLoader & json);
    bool operator==(IR::DpdkAssignmentStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_ABSTRACT_SUBCLASS(DpdkBinaryStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkBinaryStatement, NodeKind::DpdkBinaryStatement, DpdkAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkAddStatement : public DpdkBinaryStatement {
 public:
#line 335 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkAddStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 13345 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkAddStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkAddStatement"_cs; }
    static cstring static_type_name() { return "DpdkAddStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkAddStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkBinaryStatement const & a) const override;
    bool operator==(IR::DpdkAssignmentStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkAddStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkAddStatement, NodeKind::DpdkAddStatement, DpdkBinaryStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkAndStatement : public DpdkBinaryStatement, public virtual IDPDKNode {
 public:
#line 342 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkAndStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 13366 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkAndStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkAndStatement"_cs; }
    static cstring static_type_name() { return "DpdkAndStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkAndStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkBinaryStatement const & a) const override;
    bool operator==(IR::DpdkAssignmentStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkAndStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkAndStatement, NodeKind::DpdkAndStatement, DpdkBinaryStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkShlStatement : public DpdkBinaryStatement, public virtual IDPDKNode {
 public:
#line 349 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkShlStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 13387 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkShlStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkShlStatement"_cs; }
    static cstring static_type_name() { return "DpdkShlStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkShlStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkBinaryStatement const & a) const override;
    bool operator==(IR::DpdkAssignmentStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkShlStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkShlStatement, NodeKind::DpdkShlStatement, DpdkBinaryStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkShrStatement : public DpdkBinaryStatement, public virtual IDPDKNode {
 public:
#line 356 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkShrStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 13408 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkShrStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkShrStatement"_cs; }
    static cstring static_type_name() { return "DpdkShrStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkShrStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkBinaryStatement const & a) const override;
    bool operator==(IR::DpdkAssignmentStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkShrStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkShrStatement, NodeKind::DpdkShrStatement, DpdkBinaryStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkSubStatement : public DpdkBinaryStatement, public virtual IDPDKNode {
 public:
#line 363 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkSubStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 13429 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkSubStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkSubStatement"_cs; }
    static cstring static_type_name() { return "DpdkSubStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkSubStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkBinaryStatement const & a) const override;
    bool operator==(IR::DpdkAssignmentStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkSubStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkSubStatement, NodeKind::DpdkSubStatement, DpdkBinaryStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkOrStatement : public DpdkBinaryStatement, public virtual IDPDKNode {
 public:
#line 370 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkOrStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 13450 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkOrStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkOrStatement"_cs; }
    static cstring static_type_name() { return "DpdkOrStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkOrStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkBinaryStatement const & a) const override;
    bool operator==(IR::DpdkAssignmentStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkOrStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkOrStatement, NodeKind::DpdkOrStatement, DpdkBinaryStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkXorStatement : public DpdkBinaryStatement, public virtual IDPDKNode {
 public:
#line 377 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkXorStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 13471 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkXorStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkXorStatement"_cs; }
    static cstring static_type_name() { return "DpdkXorStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkXorStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkBinaryStatement const & a) const override;
    bool operator==(IR::DpdkAssignmentStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkXorStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkXorStatement, NodeKind::DpdkXorStatement, DpdkBinaryStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkRecircidStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* pass = nullptr;
#line 383 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13493 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkRecircidStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkRecircidStatement"_cs; }
    static cstring static_type_name() { return "DpdkRecircidStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkRecircidStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkRecircidStatement(Util::SourceInfo srcInfo, const IR::Expression* pass) :
    DpdkAsmStatement(srcInfo), pass(pass)
    { validate(); }
    DpdkRecircidStatement(const IR::Expression* pass) :
    pass(pass)
    { validate(); }
    IRNODE_SUBCLASS(DpdkRecircidStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkRecircidStatement, NodeKind::DpdkRecircidStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkReturnStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
#line 388 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13521 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkReturnStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkReturnStatement"_cs; }
    static cstring static_type_name() { return "DpdkReturnStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkReturnStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkReturnStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
    DpdkReturnStatement() 
    { validate(); }
    IRNODE_SUBCLASS(DpdkReturnStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkReturnStatement, NodeKind::DpdkReturnStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkRearmStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* timeout = nullptr;
#line 394 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13546 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkRearmStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    cstring node_type_name() const override { return "DpdkRearmStatement"_cs; }
    static cstring static_type_name() { return "DpdkRearmStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkRearmStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkRearmStatement(Util::SourceInfo srcInfo, const IR::Expression* timeout) :
    DpdkAsmStatement(srcInfo), timeout(timeout)
    { validate(); }
    DpdkRearmStatement(const IR::Expression* timeout) :
    timeout(timeout)
    { validate(); }
    DpdkRearmStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
    DpdkRearmStatement() 
    { validate(); }
    IRNODE_SUBCLASS(DpdkRearmStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkRearmStatement, NodeKind::DpdkRearmStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkRecirculateStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
#line 399 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13578 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkRecirculateStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkRecirculateStatement"_cs; }
    static cstring static_type_name() { return "DpdkRecirculateStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkRecirculateStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkRecirculateStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
    DpdkRecirculateStatement() 
    { validate(); }
    IRNODE_SUBCLASS(DpdkRecirculateStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkRecirculateStatement, NodeKind::DpdkRecirculateStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkLabelStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring label;
#line 405 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13603 "/root/p4c/build/ir/ir-generated.h"
#line 407 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkLabelStatement(cstring l);
#line 13606 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkLabelStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkLabelStatement"_cs; }
    static cstring static_type_name() { return "DpdkLabelStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkLabelStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkLabelStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkLabelStatement, NodeKind::DpdkLabelStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkChecksumAddStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring csum;
    cstring intermediate_value;
    const IR::Expression* field = nullptr;
#line 414 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13630 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkChecksumAddStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkChecksumAddStatement"_cs; }
    static cstring static_type_name() { return "DpdkChecksumAddStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkChecksumAddStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkChecksumAddStatement(Util::SourceInfo srcInfo, cstring csum, cstring intermediate_value, const IR::Expression* field) :
    DpdkAsmStatement(srcInfo), csum(csum), intermediate_value(intermediate_value), field(field)
    { validate(); }
    DpdkChecksumAddStatement(cstring csum, cstring intermediate_value, const IR::Expression* field) :
    csum(csum), intermediate_value(intermediate_value), field(field)
    { validate(); }
    IRNODE_SUBCLASS(DpdkChecksumAddStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkChecksumAddStatement, NodeKind::DpdkChecksumAddStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkChecksumSubStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring csum;
    cstring intermediate_value;
    const IR::Expression* field = nullptr;
#line 422 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13662 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkChecksumSubStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkChecksumSubStatement"_cs; }
    static cstring static_type_name() { return "DpdkChecksumSubStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkChecksumSubStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkChecksumSubStatement(Util::SourceInfo srcInfo, cstring csum, cstring intermediate_value, const IR::Expression* field) :
    DpdkAsmStatement(srcInfo), csum(csum), intermediate_value(intermediate_value), field(field)
    { validate(); }
    DpdkChecksumSubStatement(cstring csum, cstring intermediate_value, const IR::Expression* field) :
    csum(csum), intermediate_value(intermediate_value), field(field)
    { validate(); }
    IRNODE_SUBCLASS(DpdkChecksumSubStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkChecksumSubStatement, NodeKind::DpdkChecksumSubStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkChecksumClearStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring csum;
    cstring intermediate_value;
#line 429 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13693 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkChecksumClearStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkChecksumClearStatement"_cs; }
    static cstring static_type_name() { return "DpdkChecksumClearStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkChecksumClearStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkChecksumClearStatement(Util::SourceInfo srcInfo, cstring csum, cstring intermediate_value) :
    DpdkAsmStatement(srcInfo), csum(csum), intermediate_value(intermediate_value)
    { validate(); }
    DpdkChecksumClearStatement(cstring csum, cstring intermediate_value) :
    csum(csum), intermediate_value(intermediate_value)
    { validate(); }
    IRNODE_SUBCLASS(DpdkChecksumClearStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkChecksumClearStatement, NodeKind::DpdkChecksumClearStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkHashDeclStatement : public DpdkAsmStatement {
 public:
    cstring hash;
#line 435 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13720 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkHashDeclStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkHashDeclStatement"_cs; }
    static cstring static_type_name() { return "DpdkHashDeclStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkHashDeclStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkHashDeclStatement(Util::SourceInfo srcInfo, cstring hash) :
    DpdkAsmStatement(srcInfo), hash(hash)
    { validate(); }
    DpdkHashDeclStatement(cstring hash) :
    hash(hash)
    { validate(); }
    IRNODE_SUBCLASS(DpdkHashDeclStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkHashDeclStatement, NodeKind::DpdkHashDeclStatement, DpdkAsmStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkGetHashStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring instr;
    cstring hash;
    const IR::Expression* fields = nullptr;
    const IR::Expression* dst = nullptr;
#line 445 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13750 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkGetHashStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkGetHashStatement"_cs; }
    static cstring static_type_name() { return "DpdkGetHashStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkGetHashStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkGetHashStatement(Util::SourceInfo srcInfo, cstring instr, cstring hash, const IR::Expression* fields, const IR::Expression* dst) :
    DpdkAsmStatement(srcInfo), instr(instr), hash(hash), fields(fields), dst(dst)
    { validate(); }
    DpdkGetHashStatement(cstring instr, cstring hash, const IR::Expression* fields, const IR::Expression* dst) :
    instr(instr), hash(hash), fields(fields), dst(dst)
    { validate(); }
    IRNODE_SUBCLASS(DpdkGetHashStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkGetHashStatement, NodeKind::DpdkGetHashStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkGetChecksumStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* dst = nullptr;
    cstring checksum;
    cstring intermediate_value;
#line 453 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13782 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkGetChecksumStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkGetChecksumStatement"_cs; }
    static cstring static_type_name() { return "DpdkGetChecksumStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkGetChecksumStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkGetChecksumStatement(Util::SourceInfo srcInfo, const IR::Expression* dst, cstring checksum, cstring intermediate_value) :
    DpdkAsmStatement(srcInfo), dst(dst), checksum(checksum), intermediate_value(intermediate_value)
    { validate(); }
    DpdkGetChecksumStatement(const IR::Expression* dst, cstring checksum, cstring intermediate_value) :
    dst(dst), checksum(checksum), intermediate_value(intermediate_value)
    { validate(); }
    IRNODE_SUBCLASS(DpdkGetChecksumStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkGetChecksumStatement, NodeKind::DpdkGetChecksumStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkCastStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* dst = nullptr;
    const IR::Expression* src = nullptr;
    const IR::Type* type = nullptr;
#line 461 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13814 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkCastStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkCastStatement"_cs; }
    static cstring static_type_name() { return "DpdkCastStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkCastStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkCastStatement(Util::SourceInfo srcInfo, const IR::Expression* dst, const IR::Expression* src, const IR::Type* type) :
    DpdkAsmStatement(srcInfo), dst(dst), src(src), type(type)
    { validate(); }
    DpdkCastStatement(const IR::Expression* dst, const IR::Expression* src, const IR::Type* type) :
    dst(dst), src(src), type(type)
    { validate(); }
    IRNODE_SUBCLASS(DpdkCastStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkCastStatement, NodeKind::DpdkCastStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkVerifyStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* condition = nullptr;
    const IR::Expression* error = nullptr;
#line 468 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13844 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkVerifyStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkVerifyStatement"_cs; }
    static cstring static_type_name() { return "DpdkVerifyStatement"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkVerifyStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkVerifyStatement(Util::SourceInfo srcInfo, const IR::Expression* condition, const IR::Expression* error) :
    DpdkAsmStatement(srcInfo), condition(condition), error(error)
    { validate(); }
    DpdkVerifyStatement(const IR::Expression* condition, const IR::Expression* error) :
    condition(condition), error(error)
    { validate(); }
    IRNODE_SUBCLASS(DpdkVerifyStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkVerifyStatement, NodeKind::DpdkVerifyStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkMeterDeclStatement : public DpdkAsmStatement {
 public:
    cstring meter;
    const IR::Expression* size = nullptr;
#line 475 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13874 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkMeterDeclStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkMeterDeclStatement"_cs; }
    static cstring static_type_name() { return "DpdkMeterDeclStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkMeterDeclStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkMeterDeclStatement(Util::SourceInfo srcInfo, cstring meter, const IR::Expression* size) :
    DpdkAsmStatement(srcInfo), meter(meter), size(size)
    { validate(); }
    DpdkMeterDeclStatement(cstring meter, const IR::Expression* size) :
    meter(meter), size(size)
    { validate(); }
    IRNODE_SUBCLASS(DpdkMeterDeclStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkMeterDeclStatement, NodeKind::DpdkMeterDeclStatement, DpdkAsmStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkMeterExecuteStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring meter;
    const IR::Expression* index = nullptr;
    const IR::Expression* length = nullptr;
    const IR::Expression* color_in = nullptr;
    const IR::Expression* color_out = nullptr;
#line 485 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13908 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkMeterExecuteStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkMeterExecuteStatement"_cs; }
    static cstring static_type_name() { return "DpdkMeterExecuteStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkMeterExecuteStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkMeterExecuteStatement(Util::SourceInfo srcInfo, cstring meter, const IR::Expression* index, const IR::Expression* length, const IR::Expression* color_in, const IR::Expression* color_out) :
    DpdkAsmStatement(srcInfo), meter(meter), index(index), length(length), color_in(color_in), color_out(color_out)
    { validate(); }
    DpdkMeterExecuteStatement(cstring meter, const IR::Expression* index, const IR::Expression* length, const IR::Expression* color_in, const IR::Expression* color_out) :
    meter(meter), index(index), length(length), color_in(color_in), color_out(color_out)
    { validate(); }
    IRNODE_SUBCLASS(DpdkMeterExecuteStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkMeterExecuteStatement, NodeKind::DpdkMeterExecuteStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkGetTableEntryIndex : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* index = nullptr;
#line 491 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13938 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkGetTableEntryIndex const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkGetTableEntryIndex"_cs; }
    static cstring static_type_name() { return "DpdkGetTableEntryIndex"_cs; }
    void toJSON(JSONGenerator & json) const override;
    DpdkGetTableEntryIndex(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkGetTableEntryIndex(Util::SourceInfo srcInfo, const IR::Expression* index) :
    DpdkAsmStatement(srcInfo), index(index)
    { validate(); }
    DpdkGetTableEntryIndex(const IR::Expression* index) :
    index(index)
    { validate(); }
    IRNODE_SUBCLASS(DpdkGetTableEntryIndex)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkGetTableEntryIndex, NodeKind::DpdkGetTableEntryIndex, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkCounterCountStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring counter;
    const IR::Expression* index = nullptr;
    const IR::Expression* incr = nullptr;
#line 499 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 13969 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkCounterCountStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkCounterCountStatement"_cs; }
    static cstring static_type_name() { return "DpdkCounterCountStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkCounterCountStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkCounterCountStatement(Util::SourceInfo srcInfo, cstring counter, const IR::Expression* index, const IR::Expression* incr) :
    DpdkAsmStatement(srcInfo), counter(counter), index(index), incr(incr)
    { validate(); }
    DpdkCounterCountStatement(cstring counter, const IR::Expression* index, const IR::Expression* incr) :
    counter(counter), index(index), incr(incr)
    { validate(); }
    DpdkCounterCountStatement(Util::SourceInfo srcInfo, cstring counter, const IR::Expression* index) :
    DpdkAsmStatement(srcInfo), counter(counter), index(index)
    { validate(); }
    DpdkCounterCountStatement(cstring counter, const IR::Expression* index) :
    counter(counter), index(index)
    { validate(); }
    IRNODE_SUBCLASS(DpdkCounterCountStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkCounterCountStatement, NodeKind::DpdkCounterCountStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkRegisterDeclStatement : public DpdkAsmStatement {
 public:
    cstring reg;
    const IR::Expression* size = nullptr;
    const IR::Expression* init_val = nullptr;
#line 507 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 14007 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkRegisterDeclStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkRegisterDeclStatement"_cs; }
    static cstring static_type_name() { return "DpdkRegisterDeclStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkRegisterDeclStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkRegisterDeclStatement(Util::SourceInfo srcInfo, cstring reg, const IR::Expression* size, const IR::Expression* init_val) :
    DpdkAsmStatement(srcInfo), reg(reg), size(size), init_val(init_val)
    { validate(); }
    DpdkRegisterDeclStatement(cstring reg, const IR::Expression* size, const IR::Expression* init_val) :
    reg(reg), size(size), init_val(init_val)
    { validate(); }
    DpdkRegisterDeclStatement(Util::SourceInfo srcInfo, cstring reg, const IR::Expression* size) :
    DpdkAsmStatement(srcInfo), reg(reg), size(size)
    { validate(); }
    DpdkRegisterDeclStatement(cstring reg, const IR::Expression* size) :
    reg(reg), size(size)
    { validate(); }
    IRNODE_SUBCLASS(DpdkRegisterDeclStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkRegisterDeclStatement, NodeKind::DpdkRegisterDeclStatement, DpdkAsmStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkRegisterReadStatement : public DpdkAssignmentStatement {
 public:
    cstring reg;
    const IR::Expression* index = nullptr;
#line 514 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 14044 "/root/p4c/build/ir/ir-generated.h"
#line 517 "/root/p4c/backends/dpdk/dpdk.def"
    DpdkRegisterReadStatement(const IR::Expression* dst, cstring reg, const IR::Expression* index);
#line 14047 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkRegisterReadStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkRegisterReadStatement"_cs; }
    static cstring static_type_name() { return "DpdkRegisterReadStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkRegisterReadStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAssignmentStatement const & a) const override;
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    IRNODE_SUBCLASS(DpdkRegisterReadStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkRegisterReadStatement, NodeKind::DpdkRegisterReadStatement, DpdkAssignmentStatement);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkRegisterWriteStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring reg;
    const IR::Expression* index = nullptr;
    const IR::Expression* src = nullptr;
#line 525 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 14074 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkRegisterWriteStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkRegisterWriteStatement"_cs; }
    static cstring static_type_name() { return "DpdkRegisterWriteStatement"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkRegisterWriteStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkRegisterWriteStatement(Util::SourceInfo srcInfo, cstring reg, const IR::Expression* index, const IR::Expression* src) :
    DpdkAsmStatement(srcInfo), reg(reg), index(index), src(src)
    { validate(); }
    DpdkRegisterWriteStatement(cstring reg, const IR::Expression* index, const IR::Expression* src) :
    reg(reg), index(index), src(src)
    { validate(); }
    IRNODE_SUBCLASS(DpdkRegisterWriteStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkRegisterWriteStatement, NodeKind::DpdkRegisterWriteStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkValidateStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* header = nullptr;
#line 531 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 14104 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkValidateStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkValidateStatement"_cs; }
    static cstring static_type_name() { return "DpdkValidateStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkValidateStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkValidateStatement(Util::SourceInfo srcInfo, const IR::Expression* header) :
    DpdkAsmStatement(srcInfo), header(header)
    { validate(); }
    DpdkValidateStatement(const IR::Expression* header) :
    header(header)
    { validate(); }
    IRNODE_SUBCLASS(DpdkValidateStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkValidateStatement, NodeKind::DpdkValidateStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkInvalidateStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* header = nullptr;
#line 536 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 14134 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkInvalidateStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkInvalidateStatement"_cs; }
    static cstring static_type_name() { return "DpdkInvalidateStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkInvalidateStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkInvalidateStatement(Util::SourceInfo srcInfo, const IR::Expression* header) :
    DpdkAsmStatement(srcInfo), header(header)
    { validate(); }
    DpdkInvalidateStatement(const IR::Expression* header) :
    header(header)
    { validate(); }
    IRNODE_SUBCLASS(DpdkInvalidateStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkInvalidateStatement, NodeKind::DpdkInvalidateStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR
namespace P4::IR {
class DpdkDropStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
#line 540 "/root/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 14163 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkDropStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkDropStatement"_cs; }
    static cstring static_type_name() { return "DpdkDropStatement"_cs; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkDropStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool operator==(IR::Node const & a) const override;
    DpdkDropStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
    DpdkDropStatement() 
    { validate(); }
    IRNODE_SUBCLASS(DpdkDropStatement)
    DECLARE_TYPEINFO_WITH_TYPEID(DpdkDropStatement, NodeKind::DpdkDropStatement, DpdkAsmStatement, IDPDKNode);
};
}  // namespace P4::IR

#line 18 "/root/p4c/backends/tc/tc.def"
#include "backends/tc/tc_defines.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#line 14188 "/root/p4c/build/ir/ir-generated.h"
namespace P4::IR {
class TCKernelMetadata : public Node {
 public:
    unsigned metaField;
#line 25 "/root/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 14195 "/root/p4c/build/ir/ir-generated.h"
#line 47 "/root/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 14198 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCKernelMetadata const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "TCKernelMetadata"_cs; }
    static cstring static_type_name() { return "TCKernelMetadata"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCKernelMetadata(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    TCKernelMetadata(Util::SourceInfo srcInfo, unsigned metaField) :
    Node(srcInfo), metaField(metaField)
    { validate(); }
    TCKernelMetadata(unsigned metaField) :
    metaField(metaField)
    { validate(); }
    IRNODE_SUBCLASS(TCKernelMetadata)
    DECLARE_TYPEINFO_WITH_TYPEID(TCKernelMetadata, NodeKind::TCKernelMetadata, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class TCActionParam : public Node {
 public:
    cstring paramName;
    unsigned dataType;
    unsigned bitSize;
    unsigned direction;
#line 55 "/root/p4c/backends/tc/tc.def"
    void setParamName(cstring pN);
#line 14227 "/root/p4c/build/ir/ir-generated.h"
#line 58 "/root/p4c/backends/tc/tc.def"
    void setBitSize(unsigned bS);
#line 14230 "/root/p4c/build/ir/ir-generated.h"
#line 61 "/root/p4c/backends/tc/tc.def"
    void setDataType(unsigned d);
#line 14233 "/root/p4c/build/ir/ir-generated.h"
#line 64 "/root/p4c/backends/tc/tc.def"
    void setDirection(unsigned d);
#line 14236 "/root/p4c/build/ir/ir-generated.h"
#line 67 "/root/p4c/backends/tc/tc.def"
    TCActionParam();
#line 14239 "/root/p4c/build/ir/ir-generated.h"
#line 71 "/root/p4c/backends/tc/tc.def"
    cstring getParamName() const;
#line 14242 "/root/p4c/build/ir/ir-generated.h"
#line 74 "/root/p4c/backends/tc/tc.def"
    cstring getName() const;
#line 14245 "/root/p4c/build/ir/ir-generated.h"
#line 77 "/root/p4c/backends/tc/tc.def"
    unsigned getDirection() const;
#line 14248 "/root/p4c/build/ir/ir-generated.h"
#line 80 "/root/p4c/backends/tc/tc.def"
    cstring getParamDecl(cstring placeholderName) const;
#line 14251 "/root/p4c/build/ir/ir-generated.h"
#line 116 "/root/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 14254 "/root/p4c/build/ir/ir-generated.h"
#line 146 "/root/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 14257 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCActionParam const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "TCActionParam"_cs; }
    static cstring static_type_name() { return "TCActionParam"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCActionParam(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    TCActionParam(Util::SourceInfo srcInfo, cstring paramName, unsigned dataType, unsigned bitSize, unsigned direction) :
    Node(srcInfo), paramName(paramName), dataType(dataType), bitSize(bitSize), direction(direction)
    { validate(); }
    TCActionParam(cstring paramName, unsigned dataType, unsigned bitSize, unsigned direction) :
    paramName(paramName), dataType(dataType), bitSize(bitSize), direction(direction)
    { validate(); }
    IRNODE_SUBCLASS(TCActionParam)
    DECLARE_TYPEINFO_WITH_TYPEID(TCActionParam, NodeKind::TCActionParam, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class TCDefaultActionParam : public Node {
 public:
    const IR::TCActionParam* paramDetail = nullptr;
    cstring defaultValue;
#line 152 "/root/p4c/backends/tc/tc.def"
    void setParamDetail(const IR::TCActionParam* pN);
#line 14284 "/root/p4c/build/ir/ir-generated.h"
#line 155 "/root/p4c/backends/tc/tc.def"
    void setDefaultValue(cstring dV);
#line 14287 "/root/p4c/build/ir/ir-generated.h"
#line 158 "/root/p4c/backends/tc/tc.def"
    TCDefaultActionParam();
#line 14290 "/root/p4c/build/ir/ir-generated.h"
#line 162 "/root/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 14293 "/root/p4c/build/ir/ir-generated.h"
#line 168 "/root/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 14296 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCDefaultActionParam const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "TCDefaultActionParam"_cs; }
    static cstring static_type_name() { return "TCDefaultActionParam"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCDefaultActionParam(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    TCDefaultActionParam(Util::SourceInfo srcInfo, const IR::TCActionParam* paramDetail, cstring defaultValue) :
    Node(srcInfo), paramDetail(paramDetail), defaultValue(defaultValue)
    { validate(); }
    TCDefaultActionParam(const IR::TCActionParam* paramDetail, cstring defaultValue) :
    paramDetail(paramDetail), defaultValue(defaultValue)
    { validate(); }
    IRNODE_SUBCLASS(TCDefaultActionParam)
    DECLARE_TYPEINFO_WITH_TYPEID(TCDefaultActionParam, NodeKind::TCDefaultActionParam, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class TCAction : public Node {
 public:
    cstring actionName;
    cstring pipelineName;
    unsigned actId;
    safe_vector<const IR::TCActionParam *> actionParams;
#line 176 "/root/p4c/backends/tc/tc.def"
    cstring getName() const;
#line 14328 "/root/p4c/build/ir/ir-generated.h"
#line 182 "/root/p4c/backends/tc/tc.def"
    cstring getActionName() const;
#line 14331 "/root/p4c/build/ir/ir-generated.h"
#line 185 "/root/p4c/backends/tc/tc.def"
    void setPipelineName(cstring pN);
#line 14334 "/root/p4c/build/ir/ir-generated.h"
#line 188 "/root/p4c/backends/tc/tc.def"
    void addActionParams(const IR::TCActionParam* tca);
#line 14337 "/root/p4c/build/ir/ir-generated.h"
#line 191 "/root/p4c/backends/tc/tc.def"
    void setActionId(unsigned id);
#line 14340 "/root/p4c/build/ir/ir-generated.h"
#line 194 "/root/p4c/backends/tc/tc.def"
    TCAction(cstring aN);
#line 14343 "/root/p4c/build/ir/ir-generated.h"
#line 199 "/root/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 14346 "/root/p4c/build/ir/ir-generated.h"
#line 213 "/root/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 14349 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCAction const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "TCAction"_cs; }
    static cstring static_type_name() { return "TCAction"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCAction(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    TCAction(Util::SourceInfo srcInfo, cstring actionName, cstring pipelineName, unsigned actId, safe_vector<const IR::TCActionParam *> actionParams) :
    Node(srcInfo), actionName(actionName), pipelineName(pipelineName), actId(actId), actionParams(actionParams)
    { validate(); }
    TCAction(cstring actionName, cstring pipelineName, unsigned actId, safe_vector<const IR::TCActionParam *> actionParams) :
    actionName(actionName), pipelineName(pipelineName), actId(actId), actionParams(actionParams)
    { validate(); }
    TCAction(Util::SourceInfo srcInfo, cstring actionName, cstring pipelineName, unsigned actId) :
    Node(srcInfo), actionName(actionName), pipelineName(pipelineName), actId(actId)
    { validate(); }
    TCAction(cstring actionName, cstring pipelineName, unsigned actId) :
    actionName(actionName), pipelineName(pipelineName), actId(actId)
    { validate(); }
    IRNODE_SUBCLASS(TCAction)
    DECLARE_TYPEINFO_WITH_TYPEID(TCAction, NodeKind::TCAction, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class TCEntry : public Node {
 public:
    cstring action;
    ordered_map<cstring, cstring> keys;
#line 219 "/root/p4c/backends/tc/tc.def"
    cstring getActionName() const;
#line 14382 "/root/p4c/build/ir/ir-generated.h"
#line 222 "/root/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 14385 "/root/p4c/build/ir/ir-generated.h"
#line 229 "/root/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 14388 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCEntry const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "TCEntry"_cs; }
    static cstring static_type_name() { return "TCEntry"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCEntry(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    TCEntry(Util::SourceInfo srcInfo, cstring action, ordered_map<cstring, cstring> keys) :
    Node(srcInfo), action(action), keys(keys)
    { validate(); }
    TCEntry(cstring action, ordered_map<cstring, cstring> keys) :
    action(action), keys(keys)
    { validate(); }
    IRNODE_SUBCLASS(TCEntry)
    DECLARE_TYPEINFO_WITH_TYPEID(TCEntry, NodeKind::TCEntry, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class TCTable : public Node {
 public:
    unsigned tableID;
    cstring tableName;
    cstring controlName;
    cstring pipelineName;
    cstring permissions;
    cstring directCounterInstance;
    cstring directMeterInstance;
    unsigned keySize;
    unsigned tableEntriesCount;
    unsigned numMask;
    unsigned matchType;
    unsigned timerProfiles;
    unsigned defaultTimerProfiles = 4;
    const IR::TCAction* defaultHitAction = nullptr;
    bool isDefaultHitConst;
    bool isTcMayOverrideHit;
    safe_vector<const IR::TCDefaultActionParam *> defaultHitActionParams;
    const IR::TCAction* defaultMissAction = nullptr;
    bool isDefaultMissConst;
    bool isTcMayOverrideMiss;
    safe_vector<const IR::TCDefaultActionParam *> defaultMissActionParams;
    bool isTableAddOnMiss;
    bool isTcMayOverride;
    bool isDirectCounter;
    bool isDirectMeter;
    ordered_map<const IR::TCAction *, unsigned> actionList;
    safe_vector<const IR::TCEntry *> const_entries;
#line 261 "/root/p4c/backends/tc/tc.def"
    void setTablePermission(cstring p);
#line 14440 "/root/p4c/build/ir/ir-generated.h"
#line 264 "/root/p4c/backends/tc/tc.def"
    void setDirectCounter(cstring counter);
#line 14443 "/root/p4c/build/ir/ir-generated.h"
#line 268 "/root/p4c/backends/tc/tc.def"
    void setDirectMeter(cstring meter);
#line 14446 "/root/p4c/build/ir/ir-generated.h"
#line 272 "/root/p4c/backends/tc/tc.def"
    void setKeySize(unsigned k);
#line 14449 "/root/p4c/build/ir/ir-generated.h"
#line 275 "/root/p4c/backends/tc/tc.def"
    void setTableEntriesCount(unsigned t);
#line 14452 "/root/p4c/build/ir/ir-generated.h"
#line 278 "/root/p4c/backends/tc/tc.def"
    void setNumMask(unsigned n);
#line 14455 "/root/p4c/build/ir/ir-generated.h"
#line 281 "/root/p4c/backends/tc/tc.def"
    void setMatchType(unsigned m);
#line 14458 "/root/p4c/build/ir/ir-generated.h"
#line 284 "/root/p4c/backends/tc/tc.def"
    void setDefaultHitAction(const IR::TCAction* d);
#line 14461 "/root/p4c/build/ir/ir-generated.h"
#line 287 "/root/p4c/backends/tc/tc.def"
    void setDefaultMissAction(const IR::TCAction* d);
#line 14464 "/root/p4c/build/ir/ir-generated.h"
#line 290 "/root/p4c/backends/tc/tc.def"
    void setDefaultHitConst(bool i);
#line 14467 "/root/p4c/build/ir/ir-generated.h"
#line 293 "/root/p4c/backends/tc/tc.def"
    void setDefaultMissConst(bool i);
#line 14470 "/root/p4c/build/ir/ir-generated.h"
#line 296 "/root/p4c/backends/tc/tc.def"
    void setTcMayOverrideHit();
#line 14473 "/root/p4c/build/ir/ir-generated.h"
#line 299 "/root/p4c/backends/tc/tc.def"
    void setTcMayOverrideMiss();
#line 14476 "/root/p4c/build/ir/ir-generated.h"
#line 302 "/root/p4c/backends/tc/tc.def"
    void setTableAddOnMiss();
#line 14479 "/root/p4c/build/ir/ir-generated.h"
#line 305 "/root/p4c/backends/tc/tc.def"
    void addAction(const IR::TCAction* action, unsigned flag);
#line 14482 "/root/p4c/build/ir/ir-generated.h"
#line 308 "/root/p4c/backends/tc/tc.def"
    void addConstEntries(const IR::TCEntry* entry);
#line 14485 "/root/p4c/build/ir/ir-generated.h"
#line 311 "/root/p4c/backends/tc/tc.def"
    void addTimerProfiles(unsigned tp);
#line 14488 "/root/p4c/build/ir/ir-generated.h"
#line 314 "/root/p4c/backends/tc/tc.def"
    cstring getTableName() const;
#line 14491 "/root/p4c/build/ir/ir-generated.h"
#line 317 "/root/p4c/backends/tc/tc.def"
    cstring printMatchType(unsigned matchType) const;
#line 14494 "/root/p4c/build/ir/ir-generated.h"
#line 332 "/root/p4c/backends/tc/tc.def"
    TCTable(unsigned tId, cstring tN, cstring cN, cstring pN);
#line 14497 "/root/p4c/build/ir/ir-generated.h"
#line 353 "/root/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 14500 "/root/p4c/build/ir/ir-generated.h"
#line 433 "/root/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 14503 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCTable const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "TCTable"_cs; }
    static cstring static_type_name() { return "TCTable"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCTable(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    TCTable(Util::SourceInfo srcInfo, unsigned tableID, cstring tableName, cstring controlName, cstring pipelineName, cstring permissions, cstring directCounterInstance, cstring directMeterInstance, unsigned keySize, unsigned tableEntriesCount, unsigned numMask, unsigned matchType, unsigned timerProfiles, const IR::TCAction* defaultHitAction, bool isDefaultHitConst, bool isTcMayOverrideHit, safe_vector<const IR::TCDefaultActionParam *> defaultHitActionParams, const IR::TCAction* defaultMissAction, bool isDefaultMissConst, bool isTcMayOverrideMiss, safe_vector<const IR::TCDefaultActionParam *> defaultMissActionParams, bool isTableAddOnMiss, bool isTcMayOverride, bool isDirectCounter, bool isDirectMeter, ordered_map<const IR::TCAction *, unsigned> actionList, safe_vector<const IR::TCEntry *> const_entries) :
    Node(srcInfo), tableID(tableID), tableName(tableName), controlName(controlName), pipelineName(pipelineName), permissions(permissions), directCounterInstance(directCounterInstance), directMeterInstance(directMeterInstance), keySize(keySize), tableEntriesCount(tableEntriesCount), numMask(numMask), matchType(matchType), timerProfiles(timerProfiles), defaultHitAction(defaultHitAction), isDefaultHitConst(isDefaultHitConst), isTcMayOverrideHit(isTcMayOverrideHit), defaultHitActionParams(defaultHitActionParams), defaultMissAction(defaultMissAction), isDefaultMissConst(isDefaultMissConst), isTcMayOverrideMiss(isTcMayOverrideMiss), defaultMissActionParams(defaultMissActionParams), isTableAddOnMiss(isTableAddOnMiss), isTcMayOverride(isTcMayOverride), isDirectCounter(isDirectCounter), isDirectMeter(isDirectMeter), actionList(actionList), const_entries(const_entries)
    { validate(); }
    TCTable(unsigned tableID, cstring tableName, cstring controlName, cstring pipelineName, cstring permissions, cstring directCounterInstance, cstring directMeterInstance, unsigned keySize, unsigned tableEntriesCount, unsigned numMask, unsigned matchType, unsigned timerProfiles, const IR::TCAction* defaultHitAction, bool isDefaultHitConst, bool isTcMayOverrideHit, safe_vector<const IR::TCDefaultActionParam *> defaultHitActionParams, const IR::TCAction* defaultMissAction, bool isDefaultMissConst, bool isTcMayOverrideMiss, safe_vector<const IR::TCDefaultActionParam *> defaultMissActionParams, bool isTableAddOnMiss, bool isTcMayOverride, bool isDirectCounter, bool isDirectMeter, ordered_map<const IR::TCAction *, unsigned> actionList, safe_vector<const IR::TCEntry *> const_entries) :
    tableID(tableID), tableName(tableName), controlName(controlName), pipelineName(pipelineName), permissions(permissions), directCounterInstance(directCounterInstance), directMeterInstance(directMeterInstance), keySize(keySize), tableEntriesCount(tableEntriesCount), numMask(numMask), matchType(matchType), timerProfiles(timerProfiles), defaultHitAction(defaultHitAction), isDefaultHitConst(isDefaultHitConst), isTcMayOverrideHit(isTcMayOverrideHit), defaultHitActionParams(defaultHitActionParams), defaultMissAction(defaultMissAction), isDefaultMissConst(isDefaultMissConst), isTcMayOverrideMiss(isTcMayOverrideMiss), defaultMissActionParams(defaultMissActionParams), isTableAddOnMiss(isTableAddOnMiss), isTcMayOverride(isTcMayOverride), isDirectCounter(isDirectCounter), isDirectMeter(isDirectMeter), actionList(actionList), const_entries(const_entries)
    { validate(); }
    TCTable(Util::SourceInfo srcInfo, unsigned tableID, cstring tableName, cstring controlName, cstring pipelineName, cstring permissions, cstring directCounterInstance, cstring directMeterInstance, unsigned keySize, unsigned tableEntriesCount, unsigned numMask, unsigned matchType, unsigned timerProfiles, const IR::TCAction* defaultHitAction, bool isDefaultHitConst, bool isTcMayOverrideHit, const IR::TCAction* defaultMissAction, bool isDefaultMissConst, bool isTcMayOverrideMiss, safe_vector<const IR::TCDefaultActionParam *> defaultMissActionParams, bool isTableAddOnMiss, bool isTcMayOverride, bool isDirectCounter, bool isDirectMeter, ordered_map<const IR::TCAction *, unsigned> actionList, safe_vector<const IR::TCEntry *> const_entries) :
    Node(srcInfo), tableID(tableID), tableName(tableName), controlName(controlName), pipelineName(pipelineName), permissions(permissions), directCounterInstance(directCounterInstance), directMeterInstance(directMeterInstance), keySize(keySize), tableEntriesCount(tableEntriesCount), numMask(numMask), matchType(matchType), timerProfiles(timerProfiles), defaultHitAction(defaultHitAction), isDefaultHitConst(isDefaultHitConst), isTcMayOverrideHit(isTcMayOverrideHit), defaultMissAction(defaultMissAction), isDefaultMissConst(isDefaultMissConst), isTcMayOverrideMiss(isTcMayOverrideMiss), defaultMissActionParams(defaultMissActionParams), isTableAddOnMiss(isTableAddOnMiss), isTcMayOverride(isTcMayOverride), isDirectCounter(isDirectCounter), isDirectMeter(isDirectMeter), actionList(actionList), const_entries(const_entries)
    { validate(); }
    TCTable(unsigned tableID, cstring tableName, cstring controlName, cstring pipelineName, cstring permissions, cstring directCounterInstance, cstring directMeterInstance, unsigned keySize, unsigned tableEntriesCount, unsigned numMask, unsigned matchType, unsigned timerProfiles, const IR::TCAction* defaultHitAction, bool isDefaultHitConst, bool isTcMayOverrideHit, const IR::TCAction* defaultMissAction, bool isDefaultMissConst, bool isTcMayOverrideMiss, safe_vector<const IR::TCDefaultActionParam *> defaultMissActionParams, bool isTableAddOnMiss, bool isTcMayOverride, bool isDirectCounter, bool isDirectMeter, ordered_map<const IR::TCAction *, unsigned> actionList, safe_vector<const IR::TCEntry *> const_entries) :
    tableID(tableID), tableName(tableName), controlName(controlName), pipelineName(pipelineName), permissions(permissions), directCounterInstance(directCounterInstance), directMeterInstance(directMeterInstance), keySize(keySize), tableEntriesCount(tableEntriesCount), numMask(numMask), matchType(matchType), timerProfiles(timerProfiles), defaultHitAction(defaultHitAction), isDefaultHitConst(isDefaultHitConst), isTcMayOverrideHit(isTcMayOverrideHit), defaultMissAction(defaultMissAction), isDefaultMissConst(isDefaultMissConst), isTcMayOverrideMiss(isTcMayOverrideMiss), defaultMissActionParams(defaultMissActionParams), isTableAddOnMiss(isTableAddOnMiss), isTcMayOverride(isTcMayOverride), isDirectCounter(isDirectCounter), isDirectMeter(isDirectMeter), actionList(actionList), const_entries(const_entries)
    { validate(); }
    TCTable(Util::SourceInfo srcInfo, unsigned tableID, cstring tableName, cstring controlName, cstring pipelineName, cstring permissions, cstring directCounterInstance, cstring directMeterInstance, unsigned keySize, unsigned tableEntriesCount, unsigned numMask, unsigned matchType, unsigned timerProfiles, const IR::TCAction* defaultHitAction, bool isDefaultHitConst, bool isTcMayOverrideHit, safe_vector<const IR::TCDefaultActionParam *> defaultHitActionParams, const IR::TCAction* defaultMissAction, bool isDefaultMissConst, bool isTcMayOverrideMiss, bool isTableAddOnMiss, bool isTcMayOverride, bool isDirectCounter, bool isDirectMeter, ordered_map<const IR::TCAction *, unsigned> actionList, safe_vector<const IR::TCEntry *> const_entries) :
    Node(srcInfo), tableID(tableID), tableName(tableName), controlName(controlName), pipelineName(pipelineName), permissions(permissions), directCounterInstance(directCounterInstance), directMeterInstance(directMeterInstance), keySize(keySize), tableEntriesCount(tableEntriesCount), numMask(numMask), matchType(matchType), timerProfiles(timerProfiles), defaultHitAction(defaultHitAction), isDefaultHitConst(isDefaultHitConst), isTcMayOverrideHit(isTcMayOverrideHit), defaultHitActionParams(defaultHitActionParams), defaultMissAction(defaultMissAction), isDefaultMissConst(isDefaultMissConst), isTcMayOverrideMiss(isTcMayOverrideMiss), isTableAddOnMiss(isTableAddOnMiss), isTcMayOverride(isTcMayOverride), isDirectCounter(isDirectCounter), isDirectMeter(isDirectMeter), actionList(actionList), const_entries(const_entries)
    { validate(); }
    TCTable(unsigned tableID, cstring tableName, cstring controlName, cstring pipelineName, cstring permissions, cstring directCounterInstance, cstring directMeterInstance, unsigned keySize, unsigned tableEntriesCount, unsigned numMask, unsigned matchType, unsigned timerProfiles, const IR::TCAction* defaultHitAction, bool isDefaultHitConst, bool isTcMayOverrideHit, safe_vector<const IR::TCDefaultActionParam *> defaultHitActionParams, const IR::TCAction* defaultMissAction, bool isDefaultMissConst, bool isTcMayOverrideMiss, bool isTableAddOnMiss, bool isTcMayOverride, bool isDirectCounter, bool isDirectMeter, ordered_map<const IR::TCAction *, unsigned> actionList, safe_vector<const IR::TCEntry *> const_entries) :
    tableID(tableID), tableName(tableName), controlName(controlName), pipelineName(pipelineName), permissions(permissions), directCounterInstance(directCounterInstance), directMeterInstance(directMeterInstance), keySize(keySize), tableEntriesCount(tableEntriesCount), numMask(numMask), matchType(matchType), timerProfiles(timerProfiles), defaultHitAction(defaultHitAction), isDefaultHitConst(isDefaultHitConst), isTcMayOverrideHit(isTcMayOverrideHit), defaultHitActionParams(defaultHitActionParams), defaultMissAction(defaultMissAction), isDefaultMissConst(isDefaultMissConst), isTcMayOverrideMiss(isTcMayOverrideMiss), isTableAddOnMiss(isTableAddOnMiss), isTcMayOverride(isTcMayOverride), isDirectCounter(isDirectCounter), isDirectMeter(isDirectMeter), actionList(actionList), const_entries(const_entries)
    { validate(); }
    TCTable(Util::SourceInfo srcInfo, unsigned tableID, cstring tableName, cstring controlName, cstring pipelineName, cstring permissions, cstring directCounterInstance, cstring directMeterInstance, unsigned keySize, unsigned tableEntriesCount, unsigned numMask, unsigned matchType, unsigned timerProfiles, const IR::TCAction* defaultHitAction, bool isDefaultHitConst, bool isTcMayOverrideHit, const IR::TCAction* defaultMissAction, bool isDefaultMissConst, bool isTcMayOverrideMiss, bool isTableAddOnMiss, bool isTcMayOverride, bool isDirectCounter, bool isDirectMeter, ordered_map<const IR::TCAction *, unsigned> actionList, safe_vector<const IR::TCEntry *> const_entries) :
    Node(srcInfo), tableID(tableID), tableName(tableName), controlName(controlName), pipelineName(pipelineName), permissions(permissions), directCounterInstance(directCounterInstance), directMeterInstance(directMeterInstance), keySize(keySize), tableEntriesCount(tableEntriesCount), numMask(numMask), matchType(matchType), timerProfiles(timerProfiles), defaultHitAction(defaultHitAction), isDefaultHitConst(isDefaultHitConst), isTcMayOverrideHit(isTcMayOverrideHit), defaultMissAction(defaultMissAction), isDefaultMissConst(isDefaultMissConst), isTcMayOverrideMiss(isTcMayOverrideMiss), isTableAddOnMiss(isTableAddOnMiss), isTcMayOverride(isTcMayOverride), isDirectCounter(isDirectCounter), isDirectMeter(isDirectMeter), actionList(actionList), const_entries(const_entries)
    { validate(); }
    TCTable(unsigned tableID, cstring tableName, cstring controlName, cstring pipelineName, cstring permissions, cstring directCounterInstance, cstring directMeterInstance, unsigned keySize, unsigned tableEntriesCount, unsigned numMask, unsigned matchType, unsigned timerProfiles, const IR::TCAction* defaultHitAction, bool isDefaultHitConst, bool isTcMayOverrideHit, const IR::TCAction* defaultMissAction, bool isDefaultMissConst, bool isTcMayOverrideMiss, bool isTableAddOnMiss, bool isTcMayOverride, bool isDirectCounter, bool isDirectMeter, ordered_map<const IR::TCAction *, unsigned> actionList, safe_vector<const IR::TCEntry *> const_entries) :
    tableID(tableID), tableName(tableName), controlName(controlName), pipelineName(pipelineName), permissions(permissions), directCounterInstance(directCounterInstance), directMeterInstance(directMeterInstance), keySize(keySize), tableEntriesCount(tableEntriesCount), numMask(numMask), matchType(matchType), timerProfiles(timerProfiles), defaultHitAction(defaultHitAction), isDefaultHitConst(isDefaultHitConst), isTcMayOverrideHit(isTcMayOverrideHit), defaultMissAction(defaultMissAction), isDefaultMissConst(isDefaultMissConst), isTcMayOverrideMiss(isTcMayOverrideMiss), isTableAddOnMiss(isTableAddOnMiss), isTcMayOverride(isTcMayOverride), isDirectCounter(isDirectCounter), isDirectMeter(isDirectMeter), actionList(actionList), const_entries(const_entries)
    { validate(); }
    IRNODE_SUBCLASS(TCTable)
    DECLARE_TYPEINFO_WITH_TYPEID(TCTable, NodeKind::TCTable, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class TCKey : public Node {
 public:
    unsigned keyID;
    unsigned bitwidth;
    cstring type;
    cstring keyName;
    cstring keyAttribute;
    bool emitID;
    bool emitValue;
    unsigned value;
#line 445 "/root/p4c/backends/tc/tc.def"
    TCKey(unsigned id, unsigned width, cstring ptype, cstring name, cstring attr, bool isID);
#line 14557 "/root/p4c/build/ir/ir-generated.h"
#line 454 "/root/p4c/backends/tc/tc.def"
    void setValue(unsigned v);
#line 14560 "/root/p4c/build/ir/ir-generated.h"
#line 458 "/root/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 14563 "/root/p4c/build/ir/ir-generated.h"
#line 468 "/root/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 14566 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCKey const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "TCKey"_cs; }
    static cstring static_type_name() { return "TCKey"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCKey(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    TCKey(Util::SourceInfo srcInfo, unsigned keyID, unsigned bitwidth, cstring type, cstring keyName, cstring keyAttribute, bool emitID, bool emitValue, unsigned value) :
    Node(srcInfo), keyID(keyID), bitwidth(bitwidth), type(type), keyName(keyName), keyAttribute(keyAttribute), emitID(emitID), emitValue(emitValue), value(value)
    { validate(); }
    TCKey(unsigned keyID, unsigned bitwidth, cstring type, cstring keyName, cstring keyAttribute, bool emitID, bool emitValue, unsigned value) :
    keyID(keyID), bitwidth(bitwidth), type(type), keyName(keyName), keyAttribute(keyAttribute), emitID(emitID), emitValue(emitValue), value(value)
    { validate(); }
    IRNODE_SUBCLASS(TCKey)
    DECLARE_TYPEINFO_WITH_TYPEID(TCKey, NodeKind::TCKey, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class TCExternInstance : public Node {
 public:
    unsigned instanceID;
    cstring instanceName;
    bool isNumelemns;
    unsigned numelemns;
    bool isControlPath;
    bool isTablBindable;
    bool isInstanceType;
    bool isConstructorKeys;
    cstring instanceType;
    safe_vector<const IR::TCKey *> controlKeys;
    safe_vector<const IR::TCKey *> constructorKeys;
#line 484 "/root/p4c/backends/tc/tc.def"
    TCExternInstance(unsigned id, cstring name, bool isNe, unsigned ne);
#line 14602 "/root/p4c/build/ir/ir-generated.h"
#line 494 "/root/p4c/backends/tc/tc.def"
    void addControlPathKeys(safe_vector<const IR::TCKey *> k);
#line 14605 "/root/p4c/build/ir/ir-generated.h"
#line 500 "/root/p4c/backends/tc/tc.def"
    void addConstructorKeys(safe_vector<const IR::TCKey *> k);
#line 14608 "/root/p4c/build/ir/ir-generated.h"
#line 506 "/root/p4c/backends/tc/tc.def"
    void setExternTypeInstance(cstring type);
#line 14611 "/root/p4c/build/ir/ir-generated.h"
#line 510 "/root/p4c/backends/tc/tc.def"
    void setExternTableBindable(bool flag);
#line 14614 "/root/p4c/build/ir/ir-generated.h"
#line 513 "/root/p4c/backends/tc/tc.def"
    void setNumElements(unsigned ne);
#line 14617 "/root/p4c/build/ir/ir-generated.h"
#line 517 "/root/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 14620 "/root/p4c/build/ir/ir-generated.h"
#line 540 "/root/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 14623 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCExternInstance const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "TCExternInstance"_cs; }
    static cstring static_type_name() { return "TCExternInstance"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCExternInstance(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    TCExternInstance(Util::SourceInfo srcInfo, unsigned instanceID, cstring instanceName, bool isNumelemns, unsigned numelemns, bool isControlPath, bool isTablBindable, bool isInstanceType, bool isConstructorKeys, cstring instanceType, safe_vector<const IR::TCKey *> controlKeys, safe_vector<const IR::TCKey *> constructorKeys) :
    Node(srcInfo), instanceID(instanceID), instanceName(instanceName), isNumelemns(isNumelemns), numelemns(numelemns), isControlPath(isControlPath), isTablBindable(isTablBindable), isInstanceType(isInstanceType), isConstructorKeys(isConstructorKeys), instanceType(instanceType), controlKeys(controlKeys), constructorKeys(constructorKeys)
    { validate(); }
    TCExternInstance(unsigned instanceID, cstring instanceName, bool isNumelemns, unsigned numelemns, bool isControlPath, bool isTablBindable, bool isInstanceType, bool isConstructorKeys, cstring instanceType, safe_vector<const IR::TCKey *> controlKeys, safe_vector<const IR::TCKey *> constructorKeys) :
    instanceID(instanceID), instanceName(instanceName), isNumelemns(isNumelemns), numelemns(numelemns), isControlPath(isControlPath), isTablBindable(isTablBindable), isInstanceType(isInstanceType), isConstructorKeys(isConstructorKeys), instanceType(instanceType), controlKeys(controlKeys), constructorKeys(constructorKeys)
    { validate(); }
    IRNODE_SUBCLASS(TCExternInstance)
    DECLARE_TYPEINFO_WITH_TYPEID(TCExternInstance, NodeKind::TCExternInstance, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class TCExtern : public Node {
 public:
    cstring externName;
    cstring pipelineName;
    cstring acl_permisson;
    cstring externID;
    unsigned numinstances;
    safe_vector<const IR::TCExternInstance *> externInstances;
    bool has_exec_method;
#line 551 "/root/p4c/backends/tc/tc.def"
    TCExtern(cstring eId, cstring eN, cstring pN, unsigned inst, cstring p, bool exec_method);
#line 14655 "/root/p4c/build/ir/ir-generated.h"
#line 559 "/root/p4c/backends/tc/tc.def"
    void addExternInstance(const IR::TCExternInstance* tei);
#line 14658 "/root/p4c/build/ir/ir-generated.h"
#line 562 "/root/p4c/backends/tc/tc.def"
    const IR::TCExternInstance *getExternInstance(cstring inst_name) const;
#line 14661 "/root/p4c/build/ir/ir-generated.h"
#line 570 "/root/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 14664 "/root/p4c/build/ir/ir-generated.h"
#line 584 "/root/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 14667 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCExtern const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "TCExtern"_cs; }
    static cstring static_type_name() { return "TCExtern"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCExtern(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    TCExtern(Util::SourceInfo srcInfo, cstring externName, cstring pipelineName, cstring acl_permisson, cstring externID, unsigned numinstances, safe_vector<const IR::TCExternInstance *> externInstances, bool has_exec_method) :
    Node(srcInfo), externName(externName), pipelineName(pipelineName), acl_permisson(acl_permisson), externID(externID), numinstances(numinstances), externInstances(externInstances), has_exec_method(has_exec_method)
    { validate(); }
    TCExtern(cstring externName, cstring pipelineName, cstring acl_permisson, cstring externID, unsigned numinstances, safe_vector<const IR::TCExternInstance *> externInstances, bool has_exec_method) :
    externName(externName), pipelineName(pipelineName), acl_permisson(acl_permisson), externID(externID), numinstances(numinstances), externInstances(externInstances), has_exec_method(has_exec_method)
    { validate(); }
    IRNODE_SUBCLASS(TCExtern)
    DECLARE_TYPEINFO_WITH_TYPEID(TCExtern, NodeKind::TCExtern, Node);
};
}  // namespace P4::IR
namespace P4::IR {
class TCPipeline : public Node {
 public:
    cstring pipelineName;
    unsigned numTables;
    const IR::TCAction* NoAction = nullptr;
    safe_vector<const IR::TCAction *> actionDefs;
    safe_vector<const IR::TCTable *> tableDefs;
    safe_vector<const IR::TCExtern *> externDefs;
    const IR::TCAction* preaction = nullptr;
    const IR::TCAction* postaction = nullptr;
#line 596 "/root/p4c/backends/tc/tc.def"
    void setPipelineName(cstring pName);
#line 14700 "/root/p4c/build/ir/ir-generated.h"
#line 599 "/root/p4c/backends/tc/tc.def"
    void setNumTables(unsigned n);
#line 14703 "/root/p4c/build/ir/ir-generated.h"
#line 602 "/root/p4c/backends/tc/tc.def"
    void addNoActionDefinition(const IR::TCAction* actionDef);
#line 14706 "/root/p4c/build/ir/ir-generated.h"
#line 605 "/root/p4c/backends/tc/tc.def"
    void addActionDefinition(const IR::TCAction* actionDef);
#line 14709 "/root/p4c/build/ir/ir-generated.h"
#line 608 "/root/p4c/backends/tc/tc.def"
    void addTableDefinition(const IR::TCTable* tableDef);
#line 14712 "/root/p4c/build/ir/ir-generated.h"
#line 611 "/root/p4c/backends/tc/tc.def"
    void setPipelinePreAction(const IR::TCAction* action);
#line 14715 "/root/p4c/build/ir/ir-generated.h"
#line 614 "/root/p4c/backends/tc/tc.def"
    void setPipelinePostAction(const IR::TCAction* action);
#line 14718 "/root/p4c/build/ir/ir-generated.h"
#line 617 "/root/p4c/backends/tc/tc.def"
    void addExternDefinition(const IR::TCExtern* externDef);
#line 14721 "/root/p4c/build/ir/ir-generated.h"
#line 620 "/root/p4c/backends/tc/tc.def"
    const IR::TCExtern *getExternDefinition(cstring eName) const;
#line 14724 "/root/p4c/build/ir/ir-generated.h"
#line 628 "/root/p4c/backends/tc/tc.def"
    TCPipeline();
#line 14727 "/root/p4c/build/ir/ir-generated.h"
#line 633 "/root/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 14730 "/root/p4c/build/ir/ir-generated.h"
#line 666 "/root/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 14733 "/root/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCPipeline const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v, char const * n) override;
    void visit_children(Visitor & v, char const * n) const override;
    void validate() const override;
    cstring node_type_name() const override { return "TCPipeline"_cs; }
    static cstring static_type_name() { return "TCPipeline"_cs; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCPipeline(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override;
    TCPipeline(Util::SourceInfo srcInfo, cstring pipelineName, unsigned numTables, const IR::TCAction* NoAction, safe_vector<const IR::TCAction *> actionDefs, safe_vector<const IR::TCTable *> tableDefs, safe_vector<const IR::TCExtern *> externDefs, const IR::TCAction* preaction, const IR::TCAction* postaction) :
    Node(srcInfo), pipelineName(pipelineName), numTables(numTables), NoAction(NoAction), actionDefs(actionDefs), tableDefs(tableDefs), externDefs(externDefs), preaction(preaction), postaction(postaction)
    { validate(); }
    TCPipeline(cstring pipelineName, unsigned numTables, const IR::TCAction* NoAction, safe_vector<const IR::TCAction *> actionDefs, safe_vector<const IR::TCTable *> tableDefs, safe_vector<const IR::TCExtern *> externDefs, const IR::TCAction* preaction, const IR::TCAction* postaction) :
    pipelineName(pipelineName), numTables(numTables), NoAction(NoAction), actionDefs(actionDefs), tableDefs(tableDefs), externDefs(externDefs), preaction(preaction), postaction(postaction)
    { validate(); }
    IRNODE_SUBCLASS(TCPipeline)
    DECLARE_TYPEINFO_WITH_TYPEID(TCPipeline, NodeKind::TCPipeline, Node);
};
}  // namespace P4::IR
#endif /* IR_GENERATED_H_ */
