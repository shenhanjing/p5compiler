#include "ir/ir-generated.h"    // IWYU pragma: keep

#include "ir/ir-inline.h"       // IWYU pragma: keep
#include "ir/json_generator.h"  // IWYU pragma: keep
#include "ir/json_loader.h"     // IWYU pragma: keep
#include "ir/visitor.h"         // IWYU pragma: keep
#include "lib/algorithm.h"      // IWYU pragma: keep
#include "lib/log.h"            // IWYU pragma: keep

using namespace P4;

std::map<cstring, NodeFactoryFn> IR::unpacker_table = {
{"Type_Unknown"_cs, NodeFactoryFn(&IR::Type_Unknown::fromJSON)},
{"Path"_cs, NodeFactoryFn(&IR::Path::fromJSON)},
{"NamedExpression"_cs, NodeFactoryFn(&IR::NamedExpression::fromJSON)},
{"AnnotationToken"_cs, NodeFactoryFn(&IR::AnnotationToken::fromJSON)},
{"Annotation"_cs, NodeFactoryFn(&IR::Annotation::fromJSON)},
{"Argument"_cs, NodeFactoryFn(&IR::Argument::fromJSON)},
{"Type_Any"_cs, NodeFactoryFn(&IR::Type_Any::fromJSON)},
{"Type_Fragment"_cs, NodeFactoryFn(&IR::Type_Fragment::fromJSON)},
{"Type_Type"_cs, NodeFactoryFn(&IR::Type_Type::fromJSON)},
{"Type_Boolean"_cs, NodeFactoryFn(&IR::Type_Boolean::fromJSON)},
{"Type_State"_cs, NodeFactoryFn(&IR::Type_State::fromJSON)},
{"Type_Bits"_cs, NodeFactoryFn(&IR::Type_Bits::fromJSON)},
{"Type_Varbits"_cs, NodeFactoryFn(&IR::Type_Varbits::fromJSON)},
{"Parameter"_cs, NodeFactoryFn(&IR::Parameter::fromJSON)},
{"ParameterList"_cs, NodeFactoryFn(&IR::ParameterList::fromJSON)},
{"Type_Var"_cs, NodeFactoryFn(&IR::Type_Var::fromJSON)},
{"Type_InfInt"_cs, NodeFactoryFn(&IR::Type_InfInt::fromJSON)},
{"Type_Dontcare"_cs, NodeFactoryFn(&IR::Type_Dontcare::fromJSON)},
{"Type_Void"_cs, NodeFactoryFn(&IR::Type_Void::fromJSON)},
{"Type_MatchKind"_cs, NodeFactoryFn(&IR::Type_MatchKind::fromJSON)},
{"TypeParameters"_cs, NodeFactoryFn(&IR::TypeParameters::fromJSON)},
{"StructField"_cs, NodeFactoryFn(&IR::StructField::fromJSON)},
{"Type_Struct"_cs, NodeFactoryFn(&IR::Type_Struct::fromJSON)},
{"Type_UnknownStruct"_cs, NodeFactoryFn(&IR::Type_UnknownStruct::fromJSON)},
{"Type_HeaderUnion"_cs, NodeFactoryFn(&IR::Type_HeaderUnion::fromJSON)},
{"Type_Header"_cs, NodeFactoryFn(&IR::Type_Header::fromJSON)},
{"Type_Set"_cs, NodeFactoryFn(&IR::Type_Set::fromJSON)},
{"Type_List"_cs, NodeFactoryFn(&IR::Type_List::fromJSON)},
{"Type_Tuple"_cs, NodeFactoryFn(&IR::Type_Tuple::fromJSON)},
{"Type_P4List"_cs, NodeFactoryFn(&IR::Type_P4List::fromJSON)},
{"Type_Package"_cs, NodeFactoryFn(&IR::Type_Package::fromJSON)},
{"Type_Parser"_cs, NodeFactoryFn(&IR::Type_Parser::fromJSON)},
{"Type_Control"_cs, NodeFactoryFn(&IR::Type_Control::fromJSON)},
{"Type_Name"_cs, NodeFactoryFn(&IR::Type_Name::fromJSON)},
{"Type_Stack"_cs, NodeFactoryFn(&IR::Type_Stack::fromJSON)},
{"Type_Specialized"_cs, NodeFactoryFn(&IR::Type_Specialized::fromJSON)},
{"Type_SpecializedCanonical"_cs, NodeFactoryFn(&IR::Type_SpecializedCanonical::fromJSON)},
{"Declaration_ID"_cs, NodeFactoryFn(&IR::Declaration_ID::fromJSON)},
{"Type_String"_cs, NodeFactoryFn(&IR::Type_String::fromJSON)},
{"Type_Enum"_cs, NodeFactoryFn(&IR::Type_Enum::fromJSON)},
{"SerEnumMember"_cs, NodeFactoryFn(&IR::SerEnumMember::fromJSON)},
{"Type_SerEnum"_cs, NodeFactoryFn(&IR::Type_SerEnum::fromJSON)},
{"Type_Table"_cs, NodeFactoryFn(&IR::Type_Table::fromJSON)},
{"Type_ActionEnum"_cs, NodeFactoryFn(&IR::Type_ActionEnum::fromJSON)},
{"Type_Method"_cs, NodeFactoryFn(&IR::Type_Method::fromJSON)},
{"ArgumentInfo"_cs, NodeFactoryFn(&IR::ArgumentInfo::fromJSON)},
{"Type_MethodCall"_cs, NodeFactoryFn(&IR::Type_MethodCall::fromJSON)},
{"Type_Action"_cs, NodeFactoryFn(&IR::Type_Action::fromJSON)},
{"Method"_cs, NodeFactoryFn(&IR::Method::fromJSON)},
{"Type_Typedef"_cs, NodeFactoryFn(&IR::Type_Typedef::fromJSON)},
{"Type_Newtype"_cs, NodeFactoryFn(&IR::Type_Newtype::fromJSON)},
{"Type_Extern"_cs, NodeFactoryFn(&IR::Type_Extern::fromJSON)},
{"Neg"_cs, NodeFactoryFn(&IR::Neg::fromJSON)},
{"UPlus"_cs, NodeFactoryFn(&IR::UPlus::fromJSON)},
{"Cmpl"_cs, NodeFactoryFn(&IR::Cmpl::fromJSON)},
{"LNot"_cs, NodeFactoryFn(&IR::LNot::fromJSON)},
{"Mul"_cs, NodeFactoryFn(&IR::Mul::fromJSON)},
{"MulAssign"_cs, NodeFactoryFn(&IR::MulAssign::fromJSON)},
{"Div"_cs, NodeFactoryFn(&IR::Div::fromJSON)},
{"DivAssign"_cs, NodeFactoryFn(&IR::DivAssign::fromJSON)},
{"Mod"_cs, NodeFactoryFn(&IR::Mod::fromJSON)},
{"ModAssign"_cs, NodeFactoryFn(&IR::ModAssign::fromJSON)},
{"Add"_cs, NodeFactoryFn(&IR::Add::fromJSON)},
{"AddAssign"_cs, NodeFactoryFn(&IR::AddAssign::fromJSON)},
{"Sub"_cs, NodeFactoryFn(&IR::Sub::fromJSON)},
{"SubAssign"_cs, NodeFactoryFn(&IR::SubAssign::fromJSON)},
{"AddSat"_cs, NodeFactoryFn(&IR::AddSat::fromJSON)},
{"AddSatAssign"_cs, NodeFactoryFn(&IR::AddSatAssign::fromJSON)},
{"SubSat"_cs, NodeFactoryFn(&IR::SubSat::fromJSON)},
{"SubSatAssign"_cs, NodeFactoryFn(&IR::SubSatAssign::fromJSON)},
{"Shl"_cs, NodeFactoryFn(&IR::Shl::fromJSON)},
{"ShlAssign"_cs, NodeFactoryFn(&IR::ShlAssign::fromJSON)},
{"Shr"_cs, NodeFactoryFn(&IR::Shr::fromJSON)},
{"ShrAssign"_cs, NodeFactoryFn(&IR::ShrAssign::fromJSON)},
{"Equ"_cs, NodeFactoryFn(&IR::Equ::fromJSON)},
{"Neq"_cs, NodeFactoryFn(&IR::Neq::fromJSON)},
{"Lss"_cs, NodeFactoryFn(&IR::Lss::fromJSON)},
{"Leq"_cs, NodeFactoryFn(&IR::Leq::fromJSON)},
{"Grt"_cs, NodeFactoryFn(&IR::Grt::fromJSON)},
{"Geq"_cs, NodeFactoryFn(&IR::Geq::fromJSON)},
{"BAnd"_cs, NodeFactoryFn(&IR::BAnd::fromJSON)},
{"BAndAssign"_cs, NodeFactoryFn(&IR::BAndAssign::fromJSON)},
{"BOr"_cs, NodeFactoryFn(&IR::BOr::fromJSON)},
{"BOrAssign"_cs, NodeFactoryFn(&IR::BOrAssign::fromJSON)},
{"BXor"_cs, NodeFactoryFn(&IR::BXor::fromJSON)},
{"BXorAssign"_cs, NodeFactoryFn(&IR::BXorAssign::fromJSON)},
{"LAnd"_cs, NodeFactoryFn(&IR::LAnd::fromJSON)},
{"LOr"_cs, NodeFactoryFn(&IR::LOr::fromJSON)},
{"Dots"_cs, NodeFactoryFn(&IR::Dots::fromJSON)},
{"NamedDots"_cs, NodeFactoryFn(&IR::NamedDots::fromJSON)},
{"Constant"_cs, NodeFactoryFn(&IR::Constant::fromJSON)},
{"BoolLiteral"_cs, NodeFactoryFn(&IR::BoolLiteral::fromJSON)},
{"StringLiteral"_cs, NodeFactoryFn(&IR::StringLiteral::fromJSON)},
{"PathExpression"_cs, NodeFactoryFn(&IR::PathExpression::fromJSON)},
{"TypeNameExpression"_cs, NodeFactoryFn(&IR::TypeNameExpression::fromJSON)},
{"Slice"_cs, NodeFactoryFn(&IR::Slice::fromJSON)},
{"PlusSlice"_cs, NodeFactoryFn(&IR::PlusSlice::fromJSON)},
{"Member"_cs, NodeFactoryFn(&IR::Member::fromJSON)},
{"Concat"_cs, NodeFactoryFn(&IR::Concat::fromJSON)},
{"ArrayIndex"_cs, NodeFactoryFn(&IR::ArrayIndex::fromJSON)},
{"Range"_cs, NodeFactoryFn(&IR::Range::fromJSON)},
{"Mask"_cs, NodeFactoryFn(&IR::Mask::fromJSON)},
{"Mux"_cs, NodeFactoryFn(&IR::Mux::fromJSON)},
{"DefaultExpression"_cs, NodeFactoryFn(&IR::DefaultExpression::fromJSON)},
{"This"_cs, NodeFactoryFn(&IR::This::fromJSON)},
{"Cast"_cs, NodeFactoryFn(&IR::Cast::fromJSON)},
{"SelectCase"_cs, NodeFactoryFn(&IR::SelectCase::fromJSON)},
{"SelectExpression"_cs, NodeFactoryFn(&IR::SelectExpression::fromJSON)},
{"MethodCallExpression"_cs, NodeFactoryFn(&IR::MethodCallExpression::fromJSON)},
{"ConstructorCallExpression"_cs, NodeFactoryFn(&IR::ConstructorCallExpression::fromJSON)},
{"BaseListExpression"_cs, NodeFactoryFn(&IR::BaseListExpression::fromJSON)},
{"ListExpression"_cs, NodeFactoryFn(&IR::ListExpression::fromJSON)},
{"P4ListExpression"_cs, NodeFactoryFn(&IR::P4ListExpression::fromJSON)},
{"StructExpression"_cs, NodeFactoryFn(&IR::StructExpression::fromJSON)},
{"Invalid"_cs, NodeFactoryFn(&IR::Invalid::fromJSON)},
{"InvalidHeader"_cs, NodeFactoryFn(&IR::InvalidHeader::fromJSON)},
{"InvalidHeaderUnion"_cs, NodeFactoryFn(&IR::InvalidHeaderUnion::fromJSON)},
{"HeaderStackExpression"_cs, NodeFactoryFn(&IR::HeaderStackExpression::fromJSON)},
{"ListCompileTimeValue"_cs, NodeFactoryFn(&IR::ListCompileTimeValue::fromJSON)},
{"P4ListCompileTimeValue"_cs, NodeFactoryFn(&IR::P4ListCompileTimeValue::fromJSON)},
{"StructCompileTimeValue"_cs, NodeFactoryFn(&IR::StructCompileTimeValue::fromJSON)},
{"CompileTimeMethodCall"_cs, NodeFactoryFn(&IR::CompileTimeMethodCall::fromJSON)},
{"SymbolicVariable"_cs, NodeFactoryFn(&IR::SymbolicVariable::fromJSON)},
{"ParserState"_cs, NodeFactoryFn(&IR::ParserState::fromJSON)},
{"P4Parser"_cs, NodeFactoryFn(&IR::P4Parser::fromJSON)},
{"P4Control"_cs, NodeFactoryFn(&IR::P4Control::fromJSON)},
{"P4Action"_cs, NodeFactoryFn(&IR::P4Action::fromJSON)},
{"Type_Error"_cs, NodeFactoryFn(&IR::Type_Error::fromJSON)},
{"Declaration_MatchKind"_cs, NodeFactoryFn(&IR::Declaration_MatchKind::fromJSON)},
{"ExpressionValue"_cs, NodeFactoryFn(&IR::ExpressionValue::fromJSON)},
{"ExpressionListValue"_cs, NodeFactoryFn(&IR::ExpressionListValue::fromJSON)},
{"ActionListElement"_cs, NodeFactoryFn(&IR::ActionListElement::fromJSON)},
{"ActionList"_cs, NodeFactoryFn(&IR::ActionList::fromJSON)},
{"KeyElement"_cs, NodeFactoryFn(&IR::KeyElement::fromJSON)},
{"Key"_cs, NodeFactoryFn(&IR::Key::fromJSON)},
{"Entry"_cs, NodeFactoryFn(&IR::Entry::fromJSON)},
{"EntriesList"_cs, NodeFactoryFn(&IR::EntriesList::fromJSON)},
{"Property"_cs, NodeFactoryFn(&IR::Property::fromJSON)},
{"TableProperties"_cs, NodeFactoryFn(&IR::TableProperties::fromJSON)},
{"P4Table"_cs, NodeFactoryFn(&IR::P4Table::fromJSON)},
{"P4ValueSet"_cs, NodeFactoryFn(&IR::P4ValueSet::fromJSON)},
{"Declaration_Variable"_cs, NodeFactoryFn(&IR::Declaration_Variable::fromJSON)},
{"Declaration_Constant"_cs, NodeFactoryFn(&IR::Declaration_Constant::fromJSON)},
{"Declaration_Instance"_cs, NodeFactoryFn(&IR::Declaration_Instance::fromJSON)},
{"P4Program"_cs, NodeFactoryFn(&IR::P4Program::fromJSON)},
{"ExitStatement"_cs, NodeFactoryFn(&IR::ExitStatement::fromJSON)},
{"ReturnStatement"_cs, NodeFactoryFn(&IR::ReturnStatement::fromJSON)},
{"EmptyStatement"_cs, NodeFactoryFn(&IR::EmptyStatement::fromJSON)},
{"AssignmentStatement"_cs, NodeFactoryFn(&IR::AssignmentStatement::fromJSON)},
{"IfStatement"_cs, NodeFactoryFn(&IR::IfStatement::fromJSON)},
{"BreakStatement"_cs, NodeFactoryFn(&IR::BreakStatement::fromJSON)},
{"ContinueStatement"_cs, NodeFactoryFn(&IR::ContinueStatement::fromJSON)},
{"BlockStatement"_cs, NodeFactoryFn(&IR::BlockStatement::fromJSON)},
{"MethodCallStatement"_cs, NodeFactoryFn(&IR::MethodCallStatement::fromJSON)},
{"SwitchCase"_cs, NodeFactoryFn(&IR::SwitchCase::fromJSON)},
{"SwitchStatement"_cs, NodeFactoryFn(&IR::SwitchStatement::fromJSON)},
{"ForStatement"_cs, NodeFactoryFn(&IR::ForStatement::fromJSON)},
{"ForInStatement"_cs, NodeFactoryFn(&IR::ForInStatement::fromJSON)},
{"Function"_cs, NodeFactoryFn(&IR::Function::fromJSON)},
{"TableBlock"_cs, NodeFactoryFn(&IR::TableBlock::fromJSON)},
{"ParserBlock"_cs, NodeFactoryFn(&IR::ParserBlock::fromJSON)},
{"ControlBlock"_cs, NodeFactoryFn(&IR::ControlBlock::fromJSON)},
{"PackageBlock"_cs, NodeFactoryFn(&IR::PackageBlock::fromJSON)},
{"ExternBlock"_cs, NodeFactoryFn(&IR::ExternBlock::fromJSON)},
{"ToplevelBlock"_cs, NodeFactoryFn(&IR::ToplevelBlock::fromJSON)},
{"Type_Block"_cs, NodeFactoryFn(&IR::Type_Block::fromJSON)},
{"Type_Counter"_cs, NodeFactoryFn(&IR::Type_Counter::fromJSON)},
{"Type_Expression"_cs, NodeFactoryFn(&IR::Type_Expression::fromJSON)},
{"Type_FieldListCalculation"_cs, NodeFactoryFn(&IR::Type_FieldListCalculation::fromJSON)},
{"Type_Meter"_cs, NodeFactoryFn(&IR::Type_Meter::fromJSON)},
{"Type_Register"_cs, NodeFactoryFn(&IR::Type_Register::fromJSON)},
{"Type_AnyTable"_cs, NodeFactoryFn(&IR::Type_AnyTable::fromJSON)},
{"Header"_cs, NodeFactoryFn(&IR::Header::fromJSON)},
{"HeaderStack"_cs, NodeFactoryFn(&IR::HeaderStack::fromJSON)},
{"v1HeaderType"_cs, NodeFactoryFn(&IR::v1HeaderType::fromJSON)},
{"Metadata"_cs, NodeFactoryFn(&IR::Metadata::fromJSON)},
{"ConcreteHeaderRef"_cs, NodeFactoryFn(&IR::ConcreteHeaderRef::fromJSON)},
{"HeaderStackItemRef"_cs, NodeFactoryFn(&IR::HeaderStackItemRef::fromJSON)},
{"If"_cs, NodeFactoryFn(&IR::If::fromJSON)},
{"NamedCond"_cs, NodeFactoryFn(&IR::NamedCond::fromJSON)},
{"Apply"_cs, NodeFactoryFn(&IR::Apply::fromJSON)},
{"Primitive"_cs, NodeFactoryFn(&IR::Primitive::fromJSON)},
{"FieldList"_cs, NodeFactoryFn(&IR::FieldList::fromJSON)},
{"FieldListCalculation"_cs, NodeFactoryFn(&IR::FieldListCalculation::fromJSON)},
{"CalculatedField"_cs, NodeFactoryFn(&IR::CalculatedField::fromJSON)},
{"ParserValueSet"_cs, NodeFactoryFn(&IR::ParserValueSet::fromJSON)},
{"CaseEntry"_cs, NodeFactoryFn(&IR::CaseEntry::fromJSON)},
{"V1Parser"_cs, NodeFactoryFn(&IR::V1Parser::fromJSON)},
{"ParserException"_cs, NodeFactoryFn(&IR::ParserException::fromJSON)},
{"Counter"_cs, NodeFactoryFn(&IR::Counter::fromJSON)},
{"Meter"_cs, NodeFactoryFn(&IR::Meter::fromJSON)},
{"Register"_cs, NodeFactoryFn(&IR::Register::fromJSON)},
{"PrimitiveAction"_cs, NodeFactoryFn(&IR::PrimitiveAction::fromJSON)},
{"NameList"_cs, NodeFactoryFn(&IR::NameList::fromJSON)},
{"ActionArg"_cs, NodeFactoryFn(&IR::ActionArg::fromJSON)},
{"ActionFunction"_cs, NodeFactoryFn(&IR::ActionFunction::fromJSON)},
{"ActionProfile"_cs, NodeFactoryFn(&IR::ActionProfile::fromJSON)},
{"ActionSelector"_cs, NodeFactoryFn(&IR::ActionSelector::fromJSON)},
{"V1Table"_cs, NodeFactoryFn(&IR::V1Table::fromJSON)},
{"V1Control"_cs, NodeFactoryFn(&IR::V1Control::fromJSON)},
{"AttribLocal"_cs, NodeFactoryFn(&IR::AttribLocal::fromJSON)},
{"AttribLocals"_cs, NodeFactoryFn(&IR::AttribLocals::fromJSON)},
{"Attribute"_cs, NodeFactoryFn(&IR::Attribute::fromJSON)},
{"GlobalRef"_cs, NodeFactoryFn(&IR::GlobalRef::fromJSON)},
{"AttributeRef"_cs, NodeFactoryFn(&IR::AttributeRef::fromJSON)},
{"V1Program"_cs, NodeFactoryFn(&IR::V1Program::fromJSON)},
{"P5Table"_cs, NodeFactoryFn(&IR::P5Table::fromJSON)},
{"P5KeyElement"_cs, NodeFactoryFn(&IR::P5KeyElement::fromJSON)},
{"P5KeyCase"_cs, NodeFactoryFn(&IR::P5KeyCase::fromJSON)},
{"P5KeySwitch"_cs, NodeFactoryFn(&IR::P5KeySwitch::fromJSON)},
{"P5Key"_cs, NodeFactoryFn(&IR::P5Key::fromJSON)},
{"P5DesignatedInitializer"_cs, NodeFactoryFn(&IR::P5DesignatedInitializer::fromJSON)},
{"P5PostIncrement"_cs, NodeFactoryFn(&IR::P5PostIncrement::fromJSON)},
{"IntMod"_cs, NodeFactoryFn(&IR::IntMod::fromJSON)},
{"DpdkDeclaration"_cs, NodeFactoryFn(&IR::DpdkDeclaration::fromJSON)},
{"DpdkExternDeclaration"_cs, NodeFactoryFn(&IR::DpdkExternDeclaration::fromJSON)},
{"DpdkHeaderType"_cs, NodeFactoryFn(&IR::DpdkHeaderType::fromJSON)},
{"DpdkHeaderInstance"_cs, NodeFactoryFn(&IR::DpdkHeaderInstance::fromJSON)},
{"DpdkStructType"_cs, NodeFactoryFn(&IR::DpdkStructType::fromJSON)},
{"DpdkAction"_cs, NodeFactoryFn(&IR::DpdkAction::fromJSON)},
{"DpdkTable"_cs, NodeFactoryFn(&IR::DpdkTable::fromJSON)},
{"DpdkSelector"_cs, NodeFactoryFn(&IR::DpdkSelector::fromJSON)},
{"DpdkLearner"_cs, NodeFactoryFn(&IR::DpdkLearner::fromJSON)},
{"DpdkAsmProgram"_cs, NodeFactoryFn(&IR::DpdkAsmProgram::fromJSON)},
{"DpdkListStatement"_cs, NodeFactoryFn(&IR::DpdkListStatement::fromJSON)},
{"DpdkApplyStatement"_cs, NodeFactoryFn(&IR::DpdkApplyStatement::fromJSON)},
{"DpdkLearnStatement"_cs, NodeFactoryFn(&IR::DpdkLearnStatement::fromJSON)},
{"DpdkMirrorStatement"_cs, NodeFactoryFn(&IR::DpdkMirrorStatement::fromJSON)},
{"DpdkEmitStatement"_cs, NodeFactoryFn(&IR::DpdkEmitStatement::fromJSON)},
{"DpdkExtractStatement"_cs, NodeFactoryFn(&IR::DpdkExtractStatement::fromJSON)},
{"DpdkLookaheadStatement"_cs, NodeFactoryFn(&IR::DpdkLookaheadStatement::fromJSON)},
{"DpdkJmpLabelStatement"_cs, NodeFactoryFn(&IR::DpdkJmpLabelStatement::fromJSON)},
{"DpdkJmpHitStatement"_cs, NodeFactoryFn(&IR::DpdkJmpHitStatement::fromJSON)},
{"DpdkJmpMissStatement"_cs, NodeFactoryFn(&IR::DpdkJmpMissStatement::fromJSON)},
{"DpdkJmpIfActionRunStatement"_cs, NodeFactoryFn(&IR::DpdkJmpIfActionRunStatement::fromJSON)},
{"DpdkJmpIfActionNotRunStatement"_cs, NodeFactoryFn(&IR::DpdkJmpIfActionNotRunStatement::fromJSON)},
{"DpdkJmpIfInvalidStatement"_cs, NodeFactoryFn(&IR::DpdkJmpIfInvalidStatement::fromJSON)},
{"DpdkJmpIfValidStatement"_cs, NodeFactoryFn(&IR::DpdkJmpIfValidStatement::fromJSON)},
{"DpdkJmpEqualStatement"_cs, NodeFactoryFn(&IR::DpdkJmpEqualStatement::fromJSON)},
{"DpdkJmpNotEqualStatement"_cs, NodeFactoryFn(&IR::DpdkJmpNotEqualStatement::fromJSON)},
{"DpdkJmpGreaterEqualStatement"_cs, NodeFactoryFn(&IR::DpdkJmpGreaterEqualStatement::fromJSON)},
{"DpdkJmpGreaterStatement"_cs, NodeFactoryFn(&IR::DpdkJmpGreaterStatement::fromJSON)},
{"DpdkJmpLessOrEqualStatement"_cs, NodeFactoryFn(&IR::DpdkJmpLessOrEqualStatement::fromJSON)},
{"DpdkJmpLessStatement"_cs, NodeFactoryFn(&IR::DpdkJmpLessStatement::fromJSON)},
{"DpdkRxStatement"_cs, NodeFactoryFn(&IR::DpdkRxStatement::fromJSON)},
{"DpdkTxStatement"_cs, NodeFactoryFn(&IR::DpdkTxStatement::fromJSON)},
{"DpdkMovStatement"_cs, NodeFactoryFn(&IR::DpdkMovStatement::fromJSON)},
{"DpdkMovhStatement"_cs, NodeFactoryFn(&IR::DpdkMovhStatement::fromJSON)},
{"DpdkAddStatement"_cs, NodeFactoryFn(&IR::DpdkAddStatement::fromJSON)},
{"DpdkAndStatement"_cs, NodeFactoryFn(&IR::DpdkAndStatement::fromJSON)},
{"DpdkShlStatement"_cs, NodeFactoryFn(&IR::DpdkShlStatement::fromJSON)},
{"DpdkShrStatement"_cs, NodeFactoryFn(&IR::DpdkShrStatement::fromJSON)},
{"DpdkSubStatement"_cs, NodeFactoryFn(&IR::DpdkSubStatement::fromJSON)},
{"DpdkOrStatement"_cs, NodeFactoryFn(&IR::DpdkOrStatement::fromJSON)},
{"DpdkXorStatement"_cs, NodeFactoryFn(&IR::DpdkXorStatement::fromJSON)},
{"DpdkRecircidStatement"_cs, NodeFactoryFn(&IR::DpdkRecircidStatement::fromJSON)},
{"DpdkReturnStatement"_cs, NodeFactoryFn(&IR::DpdkReturnStatement::fromJSON)},
{"DpdkRearmStatement"_cs, NodeFactoryFn(&IR::DpdkRearmStatement::fromJSON)},
{"DpdkRecirculateStatement"_cs, NodeFactoryFn(&IR::DpdkRecirculateStatement::fromJSON)},
{"DpdkLabelStatement"_cs, NodeFactoryFn(&IR::DpdkLabelStatement::fromJSON)},
{"DpdkChecksumAddStatement"_cs, NodeFactoryFn(&IR::DpdkChecksumAddStatement::fromJSON)},
{"DpdkChecksumSubStatement"_cs, NodeFactoryFn(&IR::DpdkChecksumSubStatement::fromJSON)},
{"DpdkChecksumClearStatement"_cs, NodeFactoryFn(&IR::DpdkChecksumClearStatement::fromJSON)},
{"DpdkHashDeclStatement"_cs, NodeFactoryFn(&IR::DpdkHashDeclStatement::fromJSON)},
{"DpdkGetHashStatement"_cs, NodeFactoryFn(&IR::DpdkGetHashStatement::fromJSON)},
{"DpdkGetChecksumStatement"_cs, NodeFactoryFn(&IR::DpdkGetChecksumStatement::fromJSON)},
{"DpdkCastStatement"_cs, NodeFactoryFn(&IR::DpdkCastStatement::fromJSON)},
{"DpdkVerifyStatement"_cs, NodeFactoryFn(&IR::DpdkVerifyStatement::fromJSON)},
{"DpdkMeterDeclStatement"_cs, NodeFactoryFn(&IR::DpdkMeterDeclStatement::fromJSON)},
{"DpdkMeterExecuteStatement"_cs, NodeFactoryFn(&IR::DpdkMeterExecuteStatement::fromJSON)},
{"DpdkGetTableEntryIndex"_cs, NodeFactoryFn(&IR::DpdkGetTableEntryIndex::fromJSON)},
{"DpdkCounterCountStatement"_cs, NodeFactoryFn(&IR::DpdkCounterCountStatement::fromJSON)},
{"DpdkRegisterDeclStatement"_cs, NodeFactoryFn(&IR::DpdkRegisterDeclStatement::fromJSON)},
{"DpdkRegisterReadStatement"_cs, NodeFactoryFn(&IR::DpdkRegisterReadStatement::fromJSON)},
{"DpdkRegisterWriteStatement"_cs, NodeFactoryFn(&IR::DpdkRegisterWriteStatement::fromJSON)},
{"DpdkValidateStatement"_cs, NodeFactoryFn(&IR::DpdkValidateStatement::fromJSON)},
{"DpdkInvalidateStatement"_cs, NodeFactoryFn(&IR::DpdkInvalidateStatement::fromJSON)},
{"DpdkDropStatement"_cs, NodeFactoryFn(&IR::DpdkDropStatement::fromJSON)},
{"TCKernelMetadata"_cs, NodeFactoryFn(&IR::TCKernelMetadata::fromJSON)},
{"TCActionParam"_cs, NodeFactoryFn(&IR::TCActionParam::fromJSON)},
{"TCDefaultActionParam"_cs, NodeFactoryFn(&IR::TCDefaultActionParam::fromJSON)},
{"TCAction"_cs, NodeFactoryFn(&IR::TCAction::fromJSON)},
{"TCEntry"_cs, NodeFactoryFn(&IR::TCEntry::fromJSON)},
{"TCTable"_cs, NodeFactoryFn(&IR::TCTable::fromJSON)},
{"TCKey"_cs, NodeFactoryFn(&IR::TCKey::fromJSON)},
{"TCExternInstance"_cs, NodeFactoryFn(&IR::TCExternInstance::fromJSON)},
{"TCExtern"_cs, NodeFactoryFn(&IR::TCExtern::fromJSON)},
{"TCPipeline"_cs, NodeFactoryFn(&IR::TCPipeline::fromJSON)} };

template class IR::Vector<IR::Node>;
template class IR::IndexedVector<IR::Node>;
template class IR::Vector<IR::Type>;
template class IR::Vector<IR::StatOrDecl>;
template class IR::IndexedVector<IR::StatOrDecl>;
template class IR::Vector<IR::Declaration>;
template class IR::IndexedVector<IR::Declaration>;
template class IR::Vector<IR::Expression>;
template class IR::Vector<IR::NamedExpression>;
template class IR::IndexedVector<IR::NamedExpression>;
template class IR::Vector<IR::AnnotationToken>;
template class IR::Vector<IR::Annotation>;
template class IR::Vector<IR::Argument>;
template class IR::Vector<IR::Parameter>;
template class IR::IndexedVector<IR::Parameter>;
template class IR::Vector<IR::Type_Var>;
template class IR::IndexedVector<IR::Type_Var>;
template class IR::Vector<IR::StructField>;
template class IR::IndexedVector<IR::StructField>;
template class IR::Vector<IR::Declaration_ID>;
template class IR::IndexedVector<IR::Declaration_ID>;
template class IR::Vector<IR::SerEnumMember>;
template class IR::IndexedVector<IR::SerEnumMember>;
template class IR::Vector<IR::ArgumentInfo>;
template class IR::Vector<IR::Method>;
template class IR::Vector<IR::SelectCase>;
template class IR::Vector<IR::ParserState>;
template class IR::IndexedVector<IR::ParserState>;
template class IR::Vector<IR::ActionListElement>;
template class IR::IndexedVector<IR::ActionListElement>;
template class IR::Vector<IR::KeyElement>;
template class IR::Vector<IR::Entry>;
template class IR::Vector<IR::Property>;
template class IR::IndexedVector<IR::Property>;
template class IR::Vector<IR::SwitchCase>;
template class IR::Vector<IR::Primitive>;
template class IR::Vector<IR::CaseEntry>;
template class IR::Vector<IR::P5KeyElement>;
template class IR::Vector<IR::P5KeyCase>;
template class IR::Vector<IR::P5KeySwitch>;
template class IR::Vector<IR::DpdkDeclaration>;
template class IR::IndexedVector<IR::DpdkDeclaration>;
template class IR::Vector<IR::DpdkExternDeclaration>;
template class IR::IndexedVector<IR::DpdkExternDeclaration>;
template class IR::Vector<IR::DpdkHeaderType>;
template class IR::IndexedVector<IR::DpdkHeaderType>;
template class IR::Vector<IR::DpdkHeaderInstance>;
template class IR::IndexedVector<IR::DpdkHeaderInstance>;
template class IR::Vector<IR::DpdkStructType>;
template class IR::IndexedVector<IR::DpdkStructType>;
template class IR::Vector<IR::DpdkAsmStatement>;
template class IR::IndexedVector<IR::DpdkAsmStatement>;
template class IR::Vector<IR::DpdkAction>;
template class IR::IndexedVector<IR::DpdkAction>;
template class IR::Vector<IR::DpdkTable>;
template class IR::IndexedVector<IR::DpdkTable>;
template class IR::Vector<IR::DpdkSelector>;
template class IR::IndexedVector<IR::DpdkSelector>;
template class IR::Vector<IR::DpdkLearner>;
template class IR::IndexedVector<IR::DpdkLearner>;

#line 22 "/root/p4c/ir/base.def"
bool IR::CompileTimeValue::equiv(IR::CompileTimeValue const & other) const {
        return this->getNode()->equiv(*other.getNode());
    }
#line 368 "/root/p4c/build/ir/ir-generated.cpp"
/// Well-defined only for types with fixed width
#line 42 "/root/p4c/ir/base.def"
int IR::Type::width_bits() const { BUG("width_bits() on type with unknown size: %1%", this); }
#line 372 "/root/p4c/build/ir/ir-generated.cpp"
/// When possible returns the corresponding type that can be inserted
/// in a P4 program; may return a Type_Name
bool IR::Type::operator==(IR::Type const & a) const {
        return this->typeId() == a.typeId();
    }
bool IR::Type::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        return true;
    }
void IR::Type::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::Type::Type(JSONLoader & json) : Node(json) {
}
bool IR::Type::operator==(IR::Node const & a) const { return a == *this; }
/// Allows the retrieval of type parameters
/// @returns the type signature of the apply method
/// prints an error if it finds duplicate names
#line 80 "/root/p4c/ir/base.def"
void IR::IGeneralNamespace::validate() const { checkDuplicateDeclarations(); }
#line 394 "/root/p4c/build/ir/ir-generated.cpp"
/// The parameters of the functional object
/// Returns true if the parameters can be matched with the
/// supplied arguments.
/// The type of the constructor as a method

#line 114 "/root/p4c/ir/base.def"
const IR::ParameterList *IR::IContainer::getParameters() const { return getConstructorParameters(); }
#line 402 "/root/p4c/build/ir/ir-generated.cpp"
#line 120 "/root/p4c/ir/base.def"
IR::Type const * IR::Type_Base::getP4Type() const { return this; }
#line 405 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Base::operator==(IR::Type_Base const & a) const {
        return Type::operator==(static_cast<const Type &>(a));
    }
bool IR::Type_Base::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        return true;
    }
void IR::Type_Base::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
}
IR::Type_Base::Type_Base(JSONLoader & json) : Type(json) {
}
bool IR::Type_Base::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Base::operator==(IR::Node const & a) const { return a == *this; }
#line 128 "/root/p4c/ir/base.def"
cstring IR::Type_Unknown::toString() const { return "Unknown type"_cs; }
#line 423 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Unknown::operator==(IR::Type_Unknown const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Unknown::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Unknown::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Unknown::Type_Unknown(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Unknown::fromJSON(JSONLoader & json) { return new Type_Unknown(json); }
bool IR::Type_Unknown::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_Unknown::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Unknown::operator==(IR::Node const & a) const { return a == *this; }
bool IR::StatOrDecl::operator==(IR::StatOrDecl const & a) const {
        return this->typeId() == a.typeId();
    }
bool IR::StatOrDecl::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        return true;
    }
void IR::StatOrDecl::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::StatOrDecl::StatOrDecl(JSONLoader & json) : Node(json) {
}
bool IR::StatOrDecl::operator==(IR::Node const & a) const { return a == *this; }
#line 139 "/root/p4c/ir/base.def"
IR::ID IR::Declaration::getName() const { return name; }
#line 457 "/root/p4c/build/ir/ir-generated.cpp"
#line 140 "/root/p4c/ir/base.def"
bool IR::Declaration::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!StatOrDecl::equiv(a_)) return false;
        auto &a = static_cast<const Declaration &>(a_);

#line 140 "/root/p4c/ir/base.def"
{ return name == a.name; /* ignore declid */ }    }
#line 466 "/root/p4c/build/ir/ir-generated.cpp"
#line 144 "/root/p4c/ir/base.def"
cstring IR::Declaration::toString() const { return externalName(); }
#line 469 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Declaration::operator==(IR::Declaration const & a) const {
        return StatOrDecl::operator==(static_cast<const StatOrDecl &>(a))
        && name == a.name
        && declid == a.declid;
    }
void IR::Declaration::dump_fields(std::ostream & out) const {
    StatOrDecl::dump_fields(out);
        out << " name=" << name;
        out << " declid=" << declid;
}
void IR::Declaration::toJSON(JSONGenerator & json) const {
    StatOrDecl::toJSON(json);
    json.emit("name", name);
    json.emit("declid", declid);
}
IR::Declaration::Declaration(JSONLoader & json) : StatOrDecl(json) {
    json.load("name", name);
    json.load("declid", declid);
}
bool IR::Declaration::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::Declaration::operator==(IR::Node const & a) const { return a == *this; }
#line 155 "/root/p4c/ir/base.def"
IR::ID IR::Type_Declaration::getName() const { return name; }
#line 493 "/root/p4c/build/ir/ir-generated.cpp"
#line 156 "/root/p4c/ir/base.def"
bool IR::Type_Declaration::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Declaration &>(a_);

#line 156 "/root/p4c/ir/base.def"
{ return name == a.name; /* ignore declid */ }    }
#line 502 "/root/p4c/build/ir/ir-generated.cpp"
#line 160 "/root/p4c/ir/base.def"
cstring IR::Type_Declaration::toString() const { return externalName(); }
#line 505 "/root/p4c/build/ir/ir-generated.cpp"
#line 161 "/root/p4c/ir/base.def"
IR::Type const * IR::Type_Declaration::getP4Type() const { return new Type_Name(name); }
#line 508 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Declaration::operator==(IR::Type_Declaration const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && name == a.name
        && declid == a.declid;
    }
void IR::Type_Declaration::dump_fields(std::ostream & out) const {
    Type::dump_fields(out);
        out << " name=" << name;
        out << " declid=" << declid;
}
void IR::Type_Declaration::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("name", name);
    json.emit("declid", declid);
}
IR::Type_Declaration::Type_Declaration(JSONLoader & json) : Type(json) {
    json.load("name", name);
    json.load("declid", declid);
}
bool IR::Type_Declaration::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Declaration::operator==(IR::Node const & a) const { return a == *this; }
/// Note that the type field is not visited.
/// Most P4_16 passes don't use this field.
/// It is a used to hold the result of TypeInferencing for the expression.
/// It is used by the P4_14 front-end and by some back-ends.
/// It is not visited by the visitors by default (can be visited explicitly in preorder)
#line 172 "/root/p4c/ir/base.def"
void IR::Expression::visit_children(Visitor & v, char const * n) { (void)v; (void)n; }
#line 172 "/root/p4c/ir/base.def"
void IR::Expression::visit_children(Visitor & v, char const * n) const { (void)v; (void)n; }
#line 539 "/root/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(Expression, , )
bool IR::Expression::operator==(IR::Expression const & a) const {
        return this->typeId() == a.typeId()
        && type == a.type;
    }
bool IR::Expression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const Expression &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::Expression::validate() const {
#line 552 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type); }
void IR::Expression::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("type", type);
}
IR::Expression::Expression(JSONLoader & json) : Node(json) {
    json.load("type", type);
}
bool IR::Expression::operator==(IR::Node const & a) const { return a == *this; }
#line 184 "/root/p4c/ir/base.def"
cstring IR::Operation::toString() const { return getStringOp(); }
#line 565 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Operation::operator==(IR::Operation const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::Operation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::Operation::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::Operation::Operation(JSONLoader & json) : Expression(json) {
}
bool IR::Operation::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Operation::operator==(IR::Node const & a) const { return a == *this; }
#line 195 "/root/p4c/ir/base.def"
cstring IR::Path::toString() const {
        // This is the ORIGINAL name the user used
        return absl::StrCat(absolute ? "." : "", name.toString());
    }
#line 586 "/root/p4c/build/ir/ir-generated.cpp"
#line 203 "/root/p4c/ir/base.def"
void IR::Path::dbprint(std::ostream & out) const { out << name; }
#line 589 "/root/p4c/build/ir/ir-generated.cpp"
#line 204 "/root/p4c/ir/base.def"
void IR::Path::validate() const {
#line 592 "/root/p4c/build/ir/ir-generated.cpp"

#line 204 "/root/p4c/ir/base.def"
{ BUG_CHECK(!name.name.isNullOrEmpty(), "Empty path"); } }
#line 596 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Path::operator==(IR::Path const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && absolute == a.absolute;
    }
bool IR::Path::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const Path &>(a_);
        return name == a.name
        && absolute == a.absolute;
    }
void IR::Path::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " absolute=" << absolute;
}
void IR::Path::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    json.emit("absolute", absolute);
}
IR::Path::Path(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("absolute", absolute);
}
IR::Node * IR::Path::fromJSON(JSONLoader & json) { return new Path(json); }
bool IR::Path::operator==(IR::Node const & a) const { return a == *this; }
bool IR::NamedExpression::operator==(IR::NamedExpression const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && expression == a.expression;
    }
bool IR::NamedExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const NamedExpression &>(a_);
        return (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::NamedExpression::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    v.visit(expression, "expression");
}
void IR::NamedExpression::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    v.visit(expression, "expression");
}
void IR::NamedExpression::validate() const {
#line 646 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(expression); }
void IR::NamedExpression::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("expression", expression);
}
IR::NamedExpression::NamedExpression(JSONLoader & json) : Declaration(json) {
    json.load("expression", expression);
}
IR::Node * IR::NamedExpression::fromJSON(JSONLoader & json) { return new NamedExpression(json); }
bool IR::NamedExpression::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::NamedExpression::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::NamedExpression::operator==(IR::Node const & a) const { return a == *this; }

#line 219 "/root/p4c/ir/base.def"
void IR::AnnotationToken::dbprint(std::ostream & out) const { out << text; }
#line 663 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::AnnotationToken::operator==(IR::AnnotationToken const & a) const {
        return this->typeId() == a.typeId()
        && token_type == a.token_type
        && text == a.text
        && constInfo == a.constInfo;
    }
bool IR::AnnotationToken::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const AnnotationToken &>(a_);
        return token_type == a.token_type
        && text == a.text
        && constInfo == a.constInfo;
    }
void IR::AnnotationToken::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " token_type=" << token_type;
        out << " text=" << text;
        out << " constInfo=" << constInfo;
}
void IR::AnnotationToken::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("token_type", token_type);
    json.emit("text", text);
    if (constInfo != nullptr) json.emit("constInfo", constInfo);
}
IR::AnnotationToken::AnnotationToken(JSONLoader & json) : Node(json) {
    json.load("token_type", token_type);
    json.load("text", text);
    json.load("constInfo", constInfo);
}
IR::Node * IR::AnnotationToken::fromJSON(JSONLoader & json) { return new AnnotationToken(json); }
bool IR::AnnotationToken::operator==(IR::Node const & a) const { return a == *this; }
/// For annotations parsed from P4-16 source.


#line 263 "/root/p4c/ir/base.def"
IR::Annotation::Annotation(IR::ID n, intmax_t v, bool structured) : name(n), structured(structured) {
        body.emplace<ExpressionAnnotation>(new Constant(v));
    }
#line 704 "/root/p4c/build/ir/ir-generated.cpp"


#line 269 "/root/p4c/ir/base.def"
IR::Annotation::Annotation(IR::ID n, cstring v, bool structured) : name(n), structured(structured) {
        body.emplace<ExpressionAnnotation>(new StringLiteral(v));
    }
#line 711 "/root/p4c/build/ir/ir-generated.cpp"

/// Indicates the control-plane name.
/// Action cannot be a default_action.
/// action can only be a default_action.
/// Code should be executed atomically.
/// Object should not be exposed to the control-plane.
/// P4-14 annotation for varbit fields.
/// P4-14 annotation for varbit fields.
/// Optional parameter annotation
/// Package documentation annotation.
/// Deprecation annotation.
/// Synchronous annotation.
/// extern function/method annotation.
/// extern function/method annotation.
/// noWarn annotation.
/// Match annotation (for value sets).
/// Used for recirculate, etc.
/// Used by compiler implementer to limit debug log to the annotated IR context.
/// annotation to disable certain optimization
/// annotation to mark block of inlined function
/// annotation for likely taken blocks/branchs
/// annotation for likely not taken blocks/branchs
#line 296 "/root/p4c/ir/base.def"
cstring IR::Annotation::toString() const { return absl::StrCat("@", name); }
#line 736 "/root/p4c/build/ir/ir-generated.cpp"
#line 297 "/root/p4c/ir/base.def"
void IR::Annotation::validate() const {
#line 739 "/root/p4c/build/ir/ir-generated.cpp"
    std::visit([&](auto &&variant) {
        using T = std::decay_t<decltype(variant)>;
        if constexpr (std::is_same_v<T, IR::Vector<IR::AnnotationToken>>) { variant.validate(); }
        else if constexpr (std::is_same_v<T,IR::Vector<IR::Expression>>) { variant.validate(); }
        else if constexpr (std::is_same_v<T,IR::IndexedVector<IR::NamedExpression>>) { variant.validate(); }
        else { BUG("Unexpected variant field"); } }, body);

#line 297 "/root/p4c/ir/base.def"
{
        BUG_CHECK(!name.name.isNullOrEmpty(), "empty annotation name");
    } }
#line 751 "/root/p4c/build/ir/ir-generated.cpp"
/// Extracts name value from a name annotation
/// Extracts a single string argument; error if the argument is not a string
/// Whether the annotation body needs to be parsed.



/// If this is true this is a structured annotation, and there are some
/// constraints on its contents.
bool IR::Annotation::operator==(IR::Annotation const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && body == a.body
        && structured == a.structured;
    }
bool IR::Annotation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const Annotation &>(a_);
        auto body_equivVisitor = [&](auto &&variant) -> bool {
            using T = std::decay_t<decltype(variant)>;
            if constexpr (std::is_same_v<T, Vector<AnnotationToken>>) {return variant.equiv(std::get<IR::Vector<IR::AnnotationToken>>(a.body)); }
            else if constexpr (std::is_same_v<T,Vector<Expression>>) {return variant.equiv(std::get<IR::Vector<IR::Expression>>(a.body)); }
            else if constexpr (std::is_same_v<T,IndexedVector<NamedExpression>>) {return variant.equiv(std::get<IR::IndexedVector<IR::NamedExpression>>(a.body)); }
            else { BUG("Unexpected variant field"); } };
        return name == a.name
        && body.index() == a.body.index() && std::visit(body_equivVisitor, body)
        && structured == a.structured;
    }
void IR::Annotation::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    std::visit([&](auto &&variant) {
        using T = std::decay_t<decltype(variant)>;
        if constexpr (std::is_same_v<T, IR::Vector<IR::AnnotationToken>>) { v.visit(variant, "body::IR::Vector<IR::AnnotationToken>"); }
        else if constexpr (std::is_same_v<T,IR::Vector<IR::Expression>>) { v.visit(variant, "body::IR::Vector<IR::Expression>"); }
        else if constexpr (std::is_same_v<T,IR::IndexedVector<IR::NamedExpression>>) { v.visit(variant, "body::IR::IndexedVector<IR::NamedExpression>"); }
        else { BUG("Unexpected variant field"); } }, body);
}
void IR::Annotation::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    std::visit([&](auto &&variant) {
        using T = std::decay_t<decltype(variant)>;
        if constexpr (std::is_same_v<T, IR::Vector<IR::AnnotationToken>>) { v.visit(variant, "body::IR::Vector<IR::AnnotationToken>"); }
        else if constexpr (std::is_same_v<T,IR::Vector<IR::Expression>>) { v.visit(variant, "body::IR::Vector<IR::Expression>"); }
        else if constexpr (std::is_same_v<T,IR::IndexedVector<IR::NamedExpression>>) { v.visit(variant, "body::IR::IndexedVector<IR::NamedExpression>"); }
        else { BUG("Unexpected variant field"); } }, body);
}
void IR::Annotation::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
    std::visit([&](auto &&variant) {
        using T = std::decay_t<decltype(variant)>;
        if constexpr (std::is_same_v<T, IR::Vector<IR::AnnotationToken>>) {
}         else if constexpr (std::is_same_v<T,IR::Vector<IR::Expression>>) {
}         else if constexpr (std::is_same_v<T,IR::IndexedVector<IR::NamedExpression>>) {
}         else { BUG("Unexpected variant field"); } }, body);
        out << " structured=" << structured;
}
void IR::Annotation::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    json.emit("body", body);
    json.emit("structured", structured);
}
IR::Annotation::Annotation(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("body", body);
    json.load("structured", structured);
}
IR::Node * IR::Annotation::fromJSON(JSONLoader & json) { return new Annotation(json); }
bool IR::Annotation::operator==(IR::Node const & a) const { return a == *this; }
/// Checks if there is annotation @name
/// Checks if there is annotation @name and it is the only annotation on the
/// node
/// Check if there are any annotations
/// Add annotation if another annotation with the same name is not
/// already present.
/// If annotations with the same name are already present, remove them;
/// add this annotation.
/// If an argument has no name the name.name is nullptr.
#line 462 "/root/p4c/ir/base.def"
void IR::Argument::dbprint(std::ostream & out) const { out << (name.name.isNullOrEmpty() ? "" : name.name + " = ") << expression; }
#line 835 "/root/p4c/build/ir/ir-generated.cpp"
#line 463 "/root/p4c/ir/base.def"
void IR::Argument::validate() const {
#line 838 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(expression);
#line 463 "/root/p4c/ir/base.def"
{ CHECK_NULL(expression); } }
#line 843 "/root/p4c/build/ir/ir-generated.cpp"
#line 464 "/root/p4c/ir/base.def"
cstring IR::Argument::toString() const {
        std::string result = "";
        if (!name.name.isNullOrEmpty())
            absl::StrAppend(&result, name, " = ");
        return absl::StrCat(result, expression);
    }
#line 851 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Argument::operator==(IR::Argument const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && expression == a.expression;
    }
bool IR::Argument::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const Argument &>(a_);
        return name == a.name
        && (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::Argument::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(expression, "expression");
}
void IR::Argument::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(expression, "expression");
}
void IR::Argument::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::Argument::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    json.emit("expression", expression);
}
IR::Argument::Argument(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("expression", expression);
}
IR::Node * IR::Argument::fromJSON(JSONLoader & json) { return new Argument(json); }
bool IR::Argument::operator==(IR::Node const & a) const { return a == *this; }
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
#line 88 "/root/p4c/ir/type.def"
cstring IR::Type_Any::getVarName() const { return absl::StrCat("int_", declid); }
#line 902 "/root/p4c/build/ir/ir-generated.cpp"
#line 89 "/root/p4c/ir/type.def"
int IR::Type_Any::getDeclId() const { return declid; }
#line 905 "/root/p4c/build/ir/ir-generated.cpp"
#line 90 "/root/p4c/ir/type.def"
void IR::Type_Any::dbprint(std::ostream & out) const { out << "ANYTYPE/" << declid; }
#line 908 "/root/p4c/build/ir/ir-generated.cpp"
#line 91 "/root/p4c/ir/type.def"
cstring IR::Type_Any::toString() const { return "ANYTYPE"_cs; }
#line 911 "/root/p4c/build/ir/ir-generated.cpp"
#line 92 "/root/p4c/ir/type.def"
bool IR::Type_Any::operator==(IR::Type_Any const & a) const { return declid == a.declid; }
#line 914 "/root/p4c/build/ir/ir-generated.cpp"
#line 95 "/root/p4c/ir/type.def"
IR::Type const * IR::Type_Any::getP4Type() const { return nullptr; }
#line 917 "/root/p4c/build/ir/ir-generated.cpp"
#line 96 "/root/p4c/ir/type.def"
bool IR::Type_Any::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Any &>(a_);

#line 96 "/root/p4c/ir/type.def"
{
        (void)a;  // silence unused warning
        return true; /* ignore declid */
    }    }
#line 929 "/root/p4c/build/ir/ir-generated.cpp"
void IR::Type_Any::dump_fields(std::ostream & out) const {
    Type::dump_fields(out);
        out << " declid=" << declid;
}
void IR::Type_Any::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("declid", declid);
}
IR::Type_Any::Type_Any(JSONLoader & json) : Type(json) {
    json.load("declid", declid);
}
IR::Node * IR::Type_Any::fromJSON(JSONLoader & json) { return new Type_Any(json); }
bool IR::Type_Any::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Any::operator==(IR::Node const & a) const { return a == *this; }
#line 115 "/root/p4c/ir/type.def"
void IR::Type_Fragment::dbprint(std::ostream & out) const { out << "FRAGMENT(" << type << ")"; }
#line 946 "/root/p4c/build/ir/ir-generated.cpp"
#line 116 "/root/p4c/ir/type.def"
cstring IR::Type_Fragment::toString() const { return absl::StrCat("FRAGMENT(", type, ")"); }
#line 949 "/root/p4c/build/ir/ir-generated.cpp"
#line 117 "/root/p4c/ir/type.def"
IR::Type const * IR::Type_Fragment::getP4Type() const { return nullptr; }
#line 952 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Fragment::operator==(IR::Type_Fragment const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && type == a.type;
    }
bool IR::Type_Fragment::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Fragment &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::Type_Fragment::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type::visit_children(v, n);
    v.visit(type, "type");
}
void IR::Type_Fragment::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type::visit_children(v, n);
    v.visit(type, "type");
}
void IR::Type_Fragment::validate() const {
#line 974 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type); }
void IR::Type_Fragment::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("type", type);
}
IR::Type_Fragment::Type_Fragment(JSONLoader & json) : Type(json) {
    json.load("type", type);
}
IR::Node * IR::Type_Fragment::fromJSON(JSONLoader & json) { return new Type_Fragment(json); }
bool IR::Type_Fragment::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Fragment::operator==(IR::Node const & a) const { return a == *this; }
#line 129 "/root/p4c/ir/type.def"
cstring IR::Type_Type::toString() const { return absl::StrCat("Type(", type, ")"); }
#line 989 "/root/p4c/build/ir/ir-generated.cpp"
#line 130 "/root/p4c/ir/type.def"
void IR::Type_Type::dbprint(std::ostream & out) const { out << "Type(" << type << ")"; }
#line 992 "/root/p4c/build/ir/ir-generated.cpp"
#line 131 "/root/p4c/ir/type.def"
IR::Type const * IR::Type_Type::getP4Type() const { return type; }
#line 995 "/root/p4c/build/ir/ir-generated.cpp"
#line 132 "/root/p4c/ir/type.def"
void IR::Type_Type::validate() const {
#line 998 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
#line 132 "/root/p4c/ir/type.def"
{ BUG_CHECK(!type->is<IR::Type_Type>(), "%1%: nested Type_Type", type); } }
#line 1003 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Type::operator==(IR::Type_Type const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && type == a.type;
    }
bool IR::Type_Type::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Type &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::Type_Type::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type::visit_children(v, n);
    v.visit(type, "type");
}
void IR::Type_Type::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type::visit_children(v, n);
    v.visit(type, "type");
}
void IR::Type_Type::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("type", type);
}
IR::Type_Type::Type_Type(JSONLoader & json) : Type(json) {
    json.load("type", type);
}
IR::Node * IR::Type_Type::fromJSON(JSONLoader & json) { return new Type_Type(json); }
bool IR::Type_Type::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Type::operator==(IR::Node const & a) const { return a == *this; }
#line 149 "/root/p4c/ir/type.def"
int IR::Type_Boolean::width_bits() const { return 1; }
#line 1036 "/root/p4c/build/ir/ir-generated.cpp"
#line 150 "/root/p4c/ir/type.def"
cstring IR::Type_Boolean::toString() const { return "bool"_cs; }
#line 1039 "/root/p4c/build/ir/ir-generated.cpp"
#line 151 "/root/p4c/ir/type.def"
void IR::Type_Boolean::dbprint(std::ostream & out) const { out << "bool"; }
#line 1042 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Boolean::operator==(IR::Type_Boolean const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Boolean::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Boolean::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Boolean::Type_Boolean(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Boolean::fromJSON(JSONLoader & json) { return new Type_Boolean(json); }
bool IR::Type_Boolean::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_Boolean::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Boolean::operator==(IR::Node const & a) const { return a == *this; }
#line 169 "/root/p4c/ir/type.def"
cstring IR::Type_State::toString() const { return "state"_cs; }
#line 1062 "/root/p4c/build/ir/ir-generated.cpp"
#line 170 "/root/p4c/ir/type.def"
void IR::Type_State::dbprint(std::ostream & out) const { out << "state"; }
#line 1065 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_State::operator==(IR::Type_State const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_State::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_State::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_State::Type_State(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_State::fromJSON(JSONLoader & json) { return new Type_State(json); }
bool IR::Type_State::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_State::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_State::operator==(IR::Node const & a) const { return a == *this; }


#line 193 "/root/p4c/ir/type.def"
int IR::Type_Bits::width_bits() const { return size; }
#line 1087 "/root/p4c/build/ir/ir-generated.cpp"
#line 195 "/root/p4c/ir/type.def"
cstring IR::Type_Bits::toString() const { return absl::StrCat(baseName(), "<", size, ">"); }
#line 1090 "/root/p4c/build/ir/ir-generated.cpp"
#line 196 "/root/p4c/ir/type.def"
void IR::Type_Bits::dbprint(std::ostream & out) const { out << toString(); }
#line 1093 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Bits::operator==(IR::Type_Bits const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a))
        && size == a.size
        && expression == a.expression
        && isSigned == a.isSigned;
    }
bool IR::Type_Bits::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        auto &a = static_cast<const Type_Bits &>(a_);
        return size == a.size
        && (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr)
        && isSigned == a.isSigned;
    }
void IR::Type_Bits::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_Base::visit_children(v, n);
    v.visit(expression, "expression");
}
void IR::Type_Bits::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_Base::visit_children(v, n);
    v.visit(expression, "expression");
}
void IR::Type_Bits::dump_fields(std::ostream & out) const {
    Type_Base::dump_fields(out);
        out << " size=" << size;
        out << " isSigned=" << isSigned;
}
void IR::Type_Bits::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
    json.emit("size", size);
    if (expression != nullptr) json.emit("expression", expression);
    json.emit("isSigned", isSigned);
}
IR::Type_Bits::Type_Bits(JSONLoader & json) : Type_Base(json) {
    json.load("size", size);
    json.load("expression", expression);
    json.load("isSigned", isSigned);
}
IR::Node * IR::Type_Bits::fromJSON(JSONLoader & json) { return new Type_Bits(json); }
bool IR::Type_Bits::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_Bits::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Bits::operator==(IR::Node const & a) const { return a == *this; }


#line 217 "/root/p4c/ir/type.def"
cstring IR::Type_Varbits::toString() const { return absl::StrCat("varbit<", size, ">"); }
#line 1142 "/root/p4c/build/ir/ir-generated.cpp"
#line 218 "/root/p4c/ir/type.def"
void IR::Type_Varbits::dbprint(std::ostream & out) const { out << "varbit<" << size << ">"; }
#line 1145 "/root/p4c/build/ir/ir-generated.cpp"
#line 219 "/root/p4c/ir/type.def"
int IR::Type_Varbits::width_bits() const { return size; }
#line 1148 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Varbits::operator==(IR::Type_Varbits const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a))
        && size == a.size
        && expression == a.expression;
    }
bool IR::Type_Varbits::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        auto &a = static_cast<const Type_Varbits &>(a_);
        return size == a.size
        && (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::Type_Varbits::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_Base::visit_children(v, n);
    v.visit(expression, "expression");
}
void IR::Type_Varbits::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_Base::visit_children(v, n);
    v.visit(expression, "expression");
}
void IR::Type_Varbits::dump_fields(std::ostream & out) const {
    Type_Base::dump_fields(out);
        out << " size=" << size;
}
void IR::Type_Varbits::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
    json.emit("size", size);
    if (expression != nullptr) json.emit("expression", expression);
}
IR::Type_Varbits::Type_Varbits(JSONLoader & json) : Type_Base(json) {
    json.load("size", size);
    json.load("expression", expression);
}
IR::Node * IR::Type_Varbits::fromJSON(JSONLoader & json) { return new Type_Varbits(json); }
bool IR::Type_Varbits::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_Varbits::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Varbits::operator==(IR::Node const & a) const { return a == *this; }
#line 227 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> const & IR::Parameter::getAnnotations() const { return annotations; }
#line 1190 "/root/p4c/build/ir/ir-generated.cpp"
#line 228 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> & IR::Parameter::getAnnotations() { return annotations; }
#line 1193 "/root/p4c/build/ir/ir-generated.cpp"
#line 233 "/root/p4c/ir/type.def"
void IR::Parameter::dbprint(std::ostream & out) const { out << annotations << direction << (direction != IR::Direction::None ? " " : "")
                  << type << ' ' << name; }
#line 1197 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Parameter::operator==(IR::Parameter const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && direction == a.direction
        && type == a.type
        && defaultValue == a.defaultValue;
    }
bool IR::Parameter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Parameter &>(a_);
        return annotations.equiv(a.annotations)
        && direction == a.direction
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (defaultValue ? a.defaultValue ? defaultValue->equiv(*a.defaultValue) : false : a.defaultValue == nullptr);
    }
void IR::Parameter::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
    v.visit(defaultValue, "defaultValue");
}
void IR::Parameter::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
    v.visit(defaultValue, "defaultValue");
}
void IR::Parameter::validate() const {
#line 1229 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(type); }
void IR::Parameter::dump_fields(std::ostream & out) const {
    Declaration::dump_fields(out);
        out << " direction=" << direction;
}
void IR::Parameter::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("direction", direction);
    json.emit("type", type);
    if (defaultValue != nullptr) json.emit("defaultValue", defaultValue);
}
IR::Parameter::Parameter(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("direction", direction);
    json.load("type", type);
    json.load("defaultValue", defaultValue);
}
IR::Node * IR::Parameter::fromJSON(JSONLoader & json) { return new Parameter(json); }
bool IR::Parameter::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::Parameter::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::Parameter::operator==(IR::Node const & a) const { return a == *this; }
#line 239 "/root/p4c/ir/type.def"
void IR::ParameterList::validate() const {
#line 1256 "/root/p4c/build/ir/ir-generated.cpp"

        parameters.validate();
#line 239 "/root/p4c/ir/type.def"
{ parameters.check_null(); } }
#line 1261 "/root/p4c/build/ir/ir-generated.cpp"
#line 242 "/root/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::ParameterList::getDeclarations() const {
        return parameters.getDeclarations(); }
#line 1265 "/root/p4c/build/ir/ir-generated.cpp"
#line 254 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::ParameterList::getDeclByName(cstring name) const { return getParameter(name); }
#line 1268 "/root/p4c/build/ir/ir-generated.cpp"
#line 255 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::ParameterList::getDeclByName(std::string_view name) const { return getParameter(name); }
#line 1271 "/root/p4c/build/ir/ir-generated.cpp"
#line 257 "/root/p4c/ir/type.def"
cstring IR::ParameterList::toString() const {
        return absl::StrJoin(parameters, ", ",
                             [](std::string *out, const auto *p) {
                                 absl::StrAppend(out, p);
                             });
    }
#line 1279 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ParameterList::operator==(IR::ParameterList const & a) const {
        return this->typeId() == a.typeId()
        && parameters == a.parameters;
    }
bool IR::ParameterList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const ParameterList &>(a_);
        return parameters.equiv(a.parameters);
    }
void IR::ParameterList::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    parameters.visit_children(v, "parameters");
}
void IR::ParameterList::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    parameters.visit_children(v, "parameters");
}
void IR::ParameterList::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("parameters", parameters);
}
IR::ParameterList::ParameterList(JSONLoader & json) : Node(json) {
    json.load("parameters", parameters);
}
IR::Node * IR::ParameterList::fromJSON(JSONLoader & json) { return new ParameterList(json); }
bool IR::ParameterList::operator==(IR::Node const & a) const { return a == *this; }
#line 271 "/root/p4c/ir/type.def"
cstring IR::Type_Var::getVarName() const { return getName(); }
#line 1311 "/root/p4c/build/ir/ir-generated.cpp"
#line 272 "/root/p4c/ir/type.def"
int IR::Type_Var::getDeclId() const { return declid; }
#line 1314 "/root/p4c/build/ir/ir-generated.cpp"
#line 273 "/root/p4c/ir/type.def"
void IR::Type_Var::dbprint(std::ostream & out) const { out << name << "/" << getDeclId(); }
#line 1317 "/root/p4c/build/ir/ir-generated.cpp"
#line 274 "/root/p4c/ir/type.def"
cstring IR::Type_Var::toString() const { return getName().toString(); }
#line 1320 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Var::operator==(IR::Type_Var const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a));
    }
bool IR::Type_Var::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        return true;
    }
void IR::Type_Var::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
}
IR::Type_Var::Type_Var(JSONLoader & json) : Type_Declaration(json) {
}
IR::Node * IR::Type_Var::fromJSON(JSONLoader & json) { return new Type_Var(json); }
bool IR::Type_Var::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_Var::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Var::operator==(IR::Node const & a) const { return a == *this; }
#line 296 "/root/p4c/ir/type.def"
cstring IR::Type_InfInt::getVarName() const { return absl::StrCat("int_", declid); }
#line 1340 "/root/p4c/build/ir/ir-generated.cpp"
#line 297 "/root/p4c/ir/type.def"
int IR::Type_InfInt::getDeclId() const { return declid; }
#line 1343 "/root/p4c/build/ir/ir-generated.cpp"
#line 298 "/root/p4c/ir/type.def"
void IR::Type_InfInt::dbprint(std::ostream & out) const { out << "int/" << declid; }
#line 1346 "/root/p4c/build/ir/ir-generated.cpp"
#line 299 "/root/p4c/ir/type.def"
cstring IR::Type_InfInt::toString() const { return "int"_cs; }
#line 1349 "/root/p4c/build/ir/ir-generated.cpp"
#line 300 "/root/p4c/ir/type.def"
bool IR::Type_InfInt::operator==(IR::Type_InfInt const & a) const { return declid == a.declid; }
#line 1352 "/root/p4c/build/ir/ir-generated.cpp"
#line 303 "/root/p4c/ir/type.def"
bool IR::Type_InfInt::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_InfInt &>(a_);

#line 303 "/root/p4c/ir/type.def"
{
        (void)a;  // silence unused warning
        return true; /* ignore declid */
    }    }
#line 1364 "/root/p4c/build/ir/ir-generated.cpp"
#line 307 "/root/p4c/ir/type.def"
IR::Type const * IR::Type_InfInt::getP4Type() const { return this; }
#line 1367 "/root/p4c/build/ir/ir-generated.cpp"
#line 308 "/root/p4c/ir/type.def"
int IR::Type_InfInt::width_bits() const { return 0; }
#line 1370 "/root/p4c/build/ir/ir-generated.cpp"
void IR::Type_InfInt::dump_fields(std::ostream & out) const {
    Type::dump_fields(out);
        out << " declid=" << declid;
}
void IR::Type_InfInt::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("declid", declid);
}
IR::Type_InfInt::Type_InfInt(JSONLoader & json) : Type(json) {
    json.load("declid", declid);
}
IR::Node * IR::Type_InfInt::fromJSON(JSONLoader & json) { return new Type_InfInt(json); }
bool IR::Type_InfInt::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_InfInt::operator==(IR::Node const & a) const { return a == *this; }
#line 323 "/root/p4c/ir/type.def"
cstring IR::Type_Dontcare::toString() const { return "_"_cs; }
#line 1387 "/root/p4c/build/ir/ir-generated.cpp"
#line 326 "/root/p4c/ir/type.def"
void IR::Type_Dontcare::dbprint(std::ostream & out) const { out << "_"; }
#line 1390 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Dontcare::operator==(IR::Type_Dontcare const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Dontcare::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Dontcare::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Dontcare::Type_Dontcare(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Dontcare::fromJSON(JSONLoader & json) { return new Type_Dontcare(json); }
bool IR::Type_Dontcare::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_Dontcare::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Dontcare::operator==(IR::Node const & a) const { return a == *this; }
#line 341 "/root/p4c/ir/type.def"
cstring IR::Type_Void::toString() const { return "void"_cs; }
#line 1410 "/root/p4c/build/ir/ir-generated.cpp"
#line 344 "/root/p4c/ir/type.def"
void IR::Type_Void::dbprint(std::ostream & out) const { out << "void"; }
#line 1413 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Void::operator==(IR::Type_Void const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Void::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Void::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Void::Type_Void(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Void::fromJSON(JSONLoader & json) { return new Type_Void(json); }
bool IR::Type_Void::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_Void::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Void::operator==(IR::Node const & a) const { return a == *this; }
#line 359 "/root/p4c/ir/type.def"
cstring IR::Type_MatchKind::toString() const { return "match_kind"_cs; }
#line 1433 "/root/p4c/build/ir/ir-generated.cpp"
#line 362 "/root/p4c/ir/type.def"
void IR::Type_MatchKind::dbprint(std::ostream & out) const { out << "match_kind"; }
#line 1436 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_MatchKind::operator==(IR::Type_MatchKind const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_MatchKind::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_MatchKind::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_MatchKind::Type_MatchKind(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_MatchKind::fromJSON(JSONLoader & json) { return new Type_MatchKind(json); }
bool IR::Type_MatchKind::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_MatchKind::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_MatchKind::operator==(IR::Node const & a) const { return a == *this; }
#line 367 "/root/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::TypeParameters::getDeclarations() const {
        return parameters.getDeclarations(); }
#line 1457 "/root/p4c/build/ir/ir-generated.cpp"
#line 371 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::TypeParameters::getDeclByName(cstring name) const {
        return parameters.getDeclaration(name); }
#line 1461 "/root/p4c/build/ir/ir-generated.cpp"
#line 373 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::TypeParameters::getDeclByName(std::string_view name) const {
        return parameters.getDeclaration(name); }
#line 1465 "/root/p4c/build/ir/ir-generated.cpp"
#line 376 "/root/p4c/ir/type.def"
void IR::TypeParameters::validate() const {
#line 1468 "/root/p4c/build/ir/ir-generated.cpp"

        parameters.validate();
#line 376 "/root/p4c/ir/type.def"
{ parameters.check_null(); } }
#line 1473 "/root/p4c/build/ir/ir-generated.cpp"
#line 377 "/root/p4c/ir/type.def"
cstring IR::TypeParameters::toString() const {
        if (parameters.size() == 0)
            return cstring::empty;
        return absl::StrCat("<",
                            absl::StrJoin(parameters, ", ",
                                          [](std::string *out, const auto *p) {
                                              absl::StrAppend(out, p);
                                          }),
                            ">");
    }
#line 1485 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::TypeParameters::operator==(IR::TypeParameters const & a) const {
        return this->typeId() == a.typeId()
        && parameters == a.parameters;
    }
bool IR::TypeParameters::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const TypeParameters &>(a_);
        return parameters.equiv(a.parameters);
    }
void IR::TypeParameters::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    parameters.visit_children(v, "parameters");
}
void IR::TypeParameters::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    parameters.visit_children(v, "parameters");
}
void IR::TypeParameters::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("parameters", parameters);
}
IR::TypeParameters::TypeParameters(JSONLoader & json) : Node(json) {
    json.load("parameters", parameters);
}
IR::Node * IR::TypeParameters::fromJSON(JSONLoader & json) { return new TypeParameters(json); }
bool IR::TypeParameters::operator==(IR::Node const & a) const { return a == *this; }
#line 392 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> const & IR::StructField::getAnnotations() const { return annotations; }
#line 1517 "/root/p4c/build/ir/ir-generated.cpp"
#line 393 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> & IR::StructField::getAnnotations() { return annotations; }
#line 1520 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::StructField::operator==(IR::StructField const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && type == a.type;
    }
bool IR::StructField::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const StructField &>(a_);
        return annotations.equiv(a.annotations)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::StructField::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
}
void IR::StructField::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
}
void IR::StructField::validate() const {
#line 1546 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(type); }
void IR::StructField::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("type", type);
}
IR::StructField::StructField(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
}
IR::Node * IR::StructField::fromJSON(JSONLoader & json) { return new StructField(json); }
bool IR::StructField::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::StructField::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::StructField::operator==(IR::Node const & a) const { return a == *this; }
#line 400 "/root/p4c/ir/type.def"
const IR::TypeParameters *IR::Type_StructLike::getTypeParameters() const { return typeParameters; }
#line 1565 "/root/p4c/build/ir/ir-generated.cpp"
#line 401 "/root/p4c/ir/type.def"
std::vector<const IR::INamespace *> IR::Type_StructLike::getNestedNamespaces() const { return { typeParameters }; }
#line 1568 "/root/p4c/build/ir/ir-generated.cpp"
#line 402 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> const & IR::Type_StructLike::getAnnotations() const { return annotations; }
#line 1571 "/root/p4c/build/ir/ir-generated.cpp"
#line 403 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> & IR::Type_StructLike::getAnnotations() { return annotations; }
#line 1574 "/root/p4c/build/ir/ir-generated.cpp"
#line 404 "/root/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_StructLike::getDeclarations() const {
        return fields.getDeclarations(); }
#line 1578 "/root/p4c/build/ir/ir-generated.cpp"
/// This function returns start offset of the given field name in bits.
/// If the given name is not a valid field name, -1 is returned.
/// The given offset may not be correct if varbit field(s) present in between.
/// Offset for all fields will be correct if:
///  - the type has only fixed width fields
///  - the type has fixed width fields with only one varbit field as a last member.
#line 433 "/root/p4c/ir/type.def"
int IR::Type_StructLike::width_bits() const {
        int rv = 0;
        for (auto f : fields) {
            rv += f->type->width_bits();
        }
        return rv; }
#line 1592 "/root/p4c/build/ir/ir-generated.cpp"
#line 439 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_StructLike::getDeclByName(cstring name) const {
        return fields.getDeclaration(name); }
#line 1596 "/root/p4c/build/ir/ir-generated.cpp"
#line 441 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_StructLike::getDeclByName(std::string_view name) const {
        return fields.getDeclaration(name); }
#line 1600 "/root/p4c/build/ir/ir-generated.cpp"
#line 443 "/root/p4c/ir/type.def"
void IR::Type_StructLike::validate() const {
#line 1603 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(typeParameters);
        fields.validate();
#line 443 "/root/p4c/ir/type.def"
{ fields.check_null(); } }
#line 1610 "/root/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(Type_StructLike, , )
bool IR::Type_StructLike::operator==(IR::Type_StructLike const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && typeParameters == a.typeParameters
        && fields == a.fields;
    }
bool IR::Type_StructLike::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_StructLike &>(a_);
        return annotations.equiv(a.annotations)
        && (typeParameters ? a.typeParameters ? typeParameters->equiv(*a.typeParameters) : false : a.typeParameters == nullptr)
        && fields.equiv(a.fields);
    }
void IR::Type_StructLike::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(typeParameters, "typeParameters");
    fields.visit_children(v, "fields");
}
void IR::Type_StructLike::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(typeParameters, "typeParameters");
    fields.visit_children(v, "fields");
}
void IR::Type_StructLike::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("typeParameters", typeParameters);
    json.emit("fields", fields);
}
IR::Type_StructLike::Type_StructLike(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("typeParameters", typeParameters);
    json.load("fields", fields);
}
bool IR::Type_StructLike::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_StructLike::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_StructLike::operator==(IR::Node const & a) const { return a == *this; }
#line 450 "/root/p4c/ir/type.def"
cstring IR::Type_Struct::toString() const { return "struct "_cs + externalName(); }
#line 1656 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Struct::operator==(IR::Type_Struct const & a) const {
        return Type_StructLike::operator==(static_cast<const Type_StructLike &>(a));
    }
bool IR::Type_Struct::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_StructLike::equiv(a_)) return false;
        return true;
    }
void IR::Type_Struct::toJSON(JSONGenerator & json) const {
    Type_StructLike::toJSON(json);
}
IR::Type_Struct::Type_Struct(JSONLoader & json) : Type_StructLike(json) {
}
IR::Node * IR::Type_Struct::fromJSON(JSONLoader & json) { return new Type_Struct(json); }
bool IR::Type_Struct::operator==(IR::Type_StructLike const & a) const { return a == *this; }
bool IR::Type_Struct::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_Struct::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Struct::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Type_UnknownStruct::operator==(IR::Type_UnknownStruct const & a) const {
        return Type_StructLike::operator==(static_cast<const Type_StructLike &>(a));
    }
bool IR::Type_UnknownStruct::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_StructLike::equiv(a_)) return false;
        return true;
    }
void IR::Type_UnknownStruct::toJSON(JSONGenerator & json) const {
    Type_StructLike::toJSON(json);
}
IR::Type_UnknownStruct::Type_UnknownStruct(JSONLoader & json) : Type_StructLike(json) {
}
IR::Node * IR::Type_UnknownStruct::fromJSON(JSONLoader & json) { return new Type_UnknownStruct(json); }
bool IR::Type_UnknownStruct::operator==(IR::Type_StructLike const & a) const { return a == *this; }
bool IR::Type_UnknownStruct::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_UnknownStruct::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_UnknownStruct::operator==(IR::Node const & a) const { return a == *this; }
#line 462 "/root/p4c/ir/type.def"
cstring IR::Type_HeaderUnion::toString() const { return "header_union "_cs + externalName(); }
#line 1695 "/root/p4c/build/ir/ir-generated.cpp"

#line 464 "/root/p4c/ir/type.def"
int IR::Type_HeaderUnion::width_bits() const {
        int rv = 0;
        for (auto f : fields)
            rv = std::max(rv, f->type->width_bits());
        return rv; }
#line 1703 "/root/p4c/build/ir/ir-generated.cpp"
/// start offset of any field in a union is 0
bool IR::Type_HeaderUnion::operator==(IR::Type_HeaderUnion const & a) const {
        return Type_StructLike::operator==(static_cast<const Type_StructLike &>(a));
    }
bool IR::Type_HeaderUnion::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_StructLike::equiv(a_)) return false;
        return true;
    }
void IR::Type_HeaderUnion::toJSON(JSONGenerator & json) const {
    Type_StructLike::toJSON(json);
}
IR::Type_HeaderUnion::Type_HeaderUnion(JSONLoader & json) : Type_StructLike(json) {
}
IR::Node * IR::Type_HeaderUnion::fromJSON(JSONLoader & json) { return new Type_HeaderUnion(json); }
bool IR::Type_HeaderUnion::operator==(IR::Type_StructLike const & a) const { return a == *this; }
bool IR::Type_HeaderUnion::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_HeaderUnion::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_HeaderUnion::operator==(IR::Node const & a) const { return a == *this; }
#line 484 "/root/p4c/ir/type.def"
cstring IR::Type_Header::toString() const { return "header "_cs + externalName(); }
#line 1725 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Header::operator==(IR::Type_Header const & a) const {
        return Type_StructLike::operator==(static_cast<const Type_StructLike &>(a));
    }
bool IR::Type_Header::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_StructLike::equiv(a_)) return false;
        return true;
    }
void IR::Type_Header::toJSON(JSONGenerator & json) const {
    Type_StructLike::toJSON(json);
}
IR::Type_Header::Type_Header(JSONLoader & json) : Type_StructLike(json) {
}
IR::Node * IR::Type_Header::fromJSON(JSONLoader & json) { return new Type_Header(json); }
bool IR::Type_Header::operator==(IR::Type_StructLike const & a) const { return a == *this; }
bool IR::Type_Header::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_Header::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Header::operator==(IR::Node const & a) const { return a == *this; }
#line 489 "/root/p4c/ir/type.def"
void IR::Type_Set::dbprint(std::ostream & out) const { Node::dbprint(out); out << "<" << elementType << ">"; }
#line 1746 "/root/p4c/build/ir/ir-generated.cpp"
#line 490 "/root/p4c/ir/type.def"
cstring IR::Type_Set::toString() const { return absl::StrCat("set<", elementType, ">"); }
#line 1749 "/root/p4c/build/ir/ir-generated.cpp"
#line 491 "/root/p4c/ir/type.def"
IR::Type const * IR::Type_Set::getP4Type() const { return nullptr; }
#line 1752 "/root/p4c/build/ir/ir-generated.cpp"
#line 492 "/root/p4c/ir/type.def"
int IR::Type_Set::width_bits() const {
        /// returning the width of the set elements, not the set itself, which doesn't
        /// really have a sensible size
        return elementType->width_bits(); }
#line 1758 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Set::operator==(IR::Type_Set const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && elementType == a.elementType;
    }
bool IR::Type_Set::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Set &>(a_);
        return (elementType ? a.elementType ? elementType->equiv(*a.elementType) : false : a.elementType == nullptr);
    }
void IR::Type_Set::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type::visit_children(v, n);
    v.visit(elementType, "elementType");
}
void IR::Type_Set::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type::visit_children(v, n);
    v.visit(elementType, "elementType");
}
void IR::Type_Set::validate() const {
#line 1780 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(elementType); }
void IR::Type_Set::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("elementType", elementType);
}
IR::Type_Set::Type_Set(JSONLoader & json) : Type(json) {
    json.load("elementType", elementType);
}
IR::Node * IR::Type_Set::fromJSON(JSONLoader & json) { return new Type_Set(json); }
bool IR::Type_Set::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Set::operator==(IR::Node const & a) const { return a == *this; }


#line 508 "/root/p4c/ir/type.def"
void IR::Type_BaseList::validate() const {
#line 1797 "/root/p4c/build/ir/ir-generated.cpp"

        components.validate();
#line 508 "/root/p4c/ir/type.def"
{ components.check_null(); } }
#line 1802 "/root/p4c/build/ir/ir-generated.cpp"
#line 509 "/root/p4c/ir/type.def"
size_t IR::Type_BaseList::getSize() const { return components.size(); }
#line 1805 "/root/p4c/build/ir/ir-generated.cpp"
#line 510 "/root/p4c/ir/type.def"
const IR::Type *IR::Type_BaseList::at(size_t index) const { return components.at(index); }
#line 1808 "/root/p4c/build/ir/ir-generated.cpp"
#line 511 "/root/p4c/ir/type.def"
int IR::Type_BaseList::width_bits() const {
        /// returning sum of the width of the elements
        int rv = 0;
        for (auto f : components) {
            rv += f->width_bits();
        }
        return rv; }
#line 1817 "/root/p4c/build/ir/ir-generated.cpp"
#line 518 "/root/p4c/ir/type.def"
cstring IR::Type_BaseList::asString(char const * name) const {
        return
            absl::StrCat(name,
                         "<",
                         absl::StrJoin(components, ", ",
                                       [](std::string *out, const auto *t) {
                                           absl::StrAppend(out, t);
                                       }),
                         ">");
    }
#line 1829 "/root/p4c/build/ir/ir-generated.cpp"
#line 528 "/root/p4c/ir/type.def"
cstring IR::Type_BaseList::toString() const {
        return asString("baselist");
    }
#line 1834 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_BaseList::operator==(IR::Type_BaseList const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && components == a.components;
    }
bool IR::Type_BaseList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_BaseList &>(a_);
        return components.equiv(a.components);
    }
void IR::Type_BaseList::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type::visit_children(v, n);
    components.visit_children(v, "components");
}
void IR::Type_BaseList::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type::visit_children(v, n);
    components.visit_children(v, "components");
}
void IR::Type_BaseList::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("components", components);
}
IR::Type_BaseList::Type_BaseList(JSONLoader & json) : Type(json) {
    json.load("components", components);
}
bool IR::Type_BaseList::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_BaseList::operator==(IR::Node const & a) const { return a == *this; }

#line 537 "/root/p4c/ir/type.def"
cstring IR::Type_List::toString() const {
        return asString("tuple");
    }
#line 1869 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_List::operator==(IR::Type_List const & a) const {
        return Type_BaseList::operator==(static_cast<const Type_BaseList &>(a));
    }
bool IR::Type_List::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_BaseList::equiv(a_)) return false;
        return true;
    }
void IR::Type_List::toJSON(JSONGenerator & json) const {
    Type_BaseList::toJSON(json);
}
IR::Type_List::Type_List(JSONLoader & json) : Type_BaseList(json) {
}
IR::Node * IR::Type_List::fromJSON(JSONLoader & json) { return new Type_List(json); }
bool IR::Type_List::operator==(IR::Type_BaseList const & a) const { return a == *this; }
bool IR::Type_List::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_List::operator==(IR::Node const & a) const { return a == *this; }
#line 545 "/root/p4c/ir/type.def"
cstring IR::Type_Tuple::toString() const {
        return asString("tuple");
    }
#line 1891 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Tuple::operator==(IR::Type_Tuple const & a) const {
        return Type_BaseList::operator==(static_cast<const Type_BaseList &>(a));
    }
bool IR::Type_Tuple::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_BaseList::equiv(a_)) return false;
        return true;
    }
void IR::Type_Tuple::toJSON(JSONGenerator & json) const {
    Type_BaseList::toJSON(json);
}
IR::Type_Tuple::Type_Tuple(JSONLoader & json) : Type_BaseList(json) {
}
IR::Node * IR::Type_Tuple::fromJSON(JSONLoader & json) { return new Type_Tuple(json); }
bool IR::Type_Tuple::operator==(IR::Type_BaseList const & a) const { return a == *this; }
bool IR::Type_Tuple::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Tuple::operator==(IR::Node const & a) const { return a == *this; }
#line 554 "/root/p4c/ir/type.def"
cstring IR::Type_P4List::toString() const {
        return absl::StrCat("list<", elementType, ">");
    }
#line 1913 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_P4List::operator==(IR::Type_P4List const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && elementType == a.elementType;
    }
bool IR::Type_P4List::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_P4List &>(a_);
        return (elementType ? a.elementType ? elementType->equiv(*a.elementType) : false : a.elementType == nullptr);
    }
void IR::Type_P4List::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type::visit_children(v, n);
    v.visit(elementType, "elementType");
}
void IR::Type_P4List::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type::visit_children(v, n);
    v.visit(elementType, "elementType");
}
void IR::Type_P4List::validate() const {
#line 1935 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(elementType); }
void IR::Type_P4List::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("elementType", elementType);
}
IR::Type_P4List::Type_P4List(JSONLoader & json) : Type(json) {
    json.load("elementType", elementType);
}
IR::Node * IR::Type_P4List::fromJSON(JSONLoader & json) { return new Type_P4List(json); }
bool IR::Type_P4List::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_P4List::operator==(IR::Node const & a) const { return a == *this; }
#line 564 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> const & IR::Type_ArchBlock::getAnnotations() const { return annotations; }
#line 1950 "/root/p4c/build/ir/ir-generated.cpp"
#line 565 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> & IR::Type_ArchBlock::getAnnotations() { return annotations; }
#line 1953 "/root/p4c/build/ir/ir-generated.cpp"
#line 566 "/root/p4c/ir/type.def"
const IR::TypeParameters *IR::Type_ArchBlock::getTypeParameters() const { return typeParameters; }
#line 1956 "/root/p4c/build/ir/ir-generated.cpp"
#line 567 "/root/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_ArchBlock::getDeclarations() const {
        return typeParameters->getDeclarations(); }
#line 1960 "/root/p4c/build/ir/ir-generated.cpp"
#line 569 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_ArchBlock::getDeclByName(cstring name) const {
        return typeParameters->getDeclByName(name); }
#line 1964 "/root/p4c/build/ir/ir-generated.cpp"
#line 571 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_ArchBlock::getDeclByName(std::string_view name) const {
        return typeParameters->getDeclByName(name); }
#line 1968 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_ArchBlock::operator==(IR::Type_ArchBlock const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && typeParameters == a.typeParameters;
    }
bool IR::Type_ArchBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_ArchBlock &>(a_);
        return annotations.equiv(a.annotations)
        && (typeParameters ? a.typeParameters ? typeParameters->equiv(*a.typeParameters) : false : a.typeParameters == nullptr);
    }
void IR::Type_ArchBlock::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(typeParameters, "typeParameters");
}
void IR::Type_ArchBlock::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(typeParameters, "typeParameters");
}
void IR::Type_ArchBlock::validate() const {
#line 1994 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(typeParameters); }
void IR::Type_ArchBlock::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("typeParameters", typeParameters);
}
IR::Type_ArchBlock::Type_ArchBlock(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("typeParameters", typeParameters);
}
bool IR::Type_ArchBlock::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_ArchBlock::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_ArchBlock::operator==(IR::Node const & a) const { return a == *this; }
#line 576 "/root/p4c/ir/type.def"
const IR::Type *IR::Type_Package::getType() const { return this; }
#line 2012 "/root/p4c/build/ir/ir-generated.cpp"
#line 579 "/root/p4c/ir/type.def"
const IR::ParameterList *IR::Type_Package::getConstructorParameters() const { return constructorParams; }
#line 2015 "/root/p4c/build/ir/ir-generated.cpp"
#line 580 "/root/p4c/ir/type.def"
cstring IR::Type_Package::toString() const { return "package "_cs + externalName(); }
#line 2018 "/root/p4c/build/ir/ir-generated.cpp"
#line 581 "/root/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_Package::getDeclarations() const {
        return typeParameters->getDeclarations()->concat(constructorParams->getDeclarations()); }
#line 2022 "/root/p4c/build/ir/ir-generated.cpp"
#line 583 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_Package::getDeclByName(cstring name) const {
        auto decl = constructorParams->getDeclByName(name);
        if (!decl) decl = typeParameters->getDeclByName(name);
        return decl; }
#line 2028 "/root/p4c/build/ir/ir-generated.cpp"
#line 587 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_Package::getDeclByName(std::string_view name) const {
        auto decl = constructorParams->getDeclByName(name);
        if (!decl) decl = typeParameters->getDeclByName(name);
        return decl; }
#line 2034 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Package::operator==(IR::Type_Package const & a) const {
        return Type_ArchBlock::operator==(static_cast<const Type_ArchBlock &>(a))
        && constructorParams == a.constructorParams;
    }
bool IR::Type_Package::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_ArchBlock::equiv(a_)) return false;
        auto &a = static_cast<const Type_Package &>(a_);
        return (constructorParams ? a.constructorParams ? constructorParams->equiv(*a.constructorParams) : false : a.constructorParams == nullptr);
    }
void IR::Type_Package::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_ArchBlock::visit_children(v, n);
    v.visit(constructorParams, "constructorParams");
}
void IR::Type_Package::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_ArchBlock::visit_children(v, n);
    v.visit(constructorParams, "constructorParams");
}
void IR::Type_Package::validate() const {
#line 2056 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(constructorParams); }
void IR::Type_Package::toJSON(JSONGenerator & json) const {
    Type_ArchBlock::toJSON(json);
    json.emit("constructorParams", constructorParams);
}
IR::Type_Package::Type_Package(JSONLoader & json) : Type_ArchBlock(json) {
    json.load("constructorParams", constructorParams);
}
IR::Node * IR::Type_Package::fromJSON(JSONLoader & json) { return new Type_Package(json); }
bool IR::Type_Package::operator==(IR::Type_ArchBlock const & a) const { return a == *this; }
bool IR::Type_Package::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_Package::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Package::operator==(IR::Node const & a) const { return a == *this; }
#line 596 "/root/p4c/ir/type.def"
const IR::ParameterList *IR::Type_Parser::getApplyParameters() const { return applyParams; }
#line 2073 "/root/p4c/build/ir/ir-generated.cpp"
#line 597 "/root/p4c/ir/type.def"
cstring IR::Type_Parser::toString() const { return "parser "_cs + externalName(); }
#line 2076 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Parser::operator==(IR::Type_Parser const & a) const {
        return Type_ArchBlock::operator==(static_cast<const Type_ArchBlock &>(a))
        && applyParams == a.applyParams;
    }
bool IR::Type_Parser::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_ArchBlock::equiv(a_)) return false;
        auto &a = static_cast<const Type_Parser &>(a_);
        return (applyParams ? a.applyParams ? applyParams->equiv(*a.applyParams) : false : a.applyParams == nullptr);
    }
void IR::Type_Parser::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_ArchBlock::visit_children(v, n);
    v.visit(applyParams, "applyParams");
}
void IR::Type_Parser::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_ArchBlock::visit_children(v, n);
    v.visit(applyParams, "applyParams");
}
void IR::Type_Parser::validate() const {
#line 2098 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(applyParams); }
void IR::Type_Parser::toJSON(JSONGenerator & json) const {
    Type_ArchBlock::toJSON(json);
    json.emit("applyParams", applyParams);
}
IR::Type_Parser::Type_Parser(JSONLoader & json) : Type_ArchBlock(json) {
    json.load("applyParams", applyParams);
}
IR::Node * IR::Type_Parser::fromJSON(JSONLoader & json) { return new Type_Parser(json); }
bool IR::Type_Parser::operator==(IR::Type_ArchBlock const & a) const { return a == *this; }
bool IR::Type_Parser::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_Parser::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Parser::operator==(IR::Node const & a) const { return a == *this; }
#line 603 "/root/p4c/ir/type.def"
const IR::ParameterList *IR::Type_Control::getApplyParameters() const { return applyParams; }
#line 2115 "/root/p4c/build/ir/ir-generated.cpp"
#line 604 "/root/p4c/ir/type.def"
cstring IR::Type_Control::toString() const { return "control "_cs + externalName(); }
#line 2118 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Control::operator==(IR::Type_Control const & a) const {
        return Type_ArchBlock::operator==(static_cast<const Type_ArchBlock &>(a))
        && applyParams == a.applyParams;
    }
bool IR::Type_Control::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_ArchBlock::equiv(a_)) return false;
        auto &a = static_cast<const Type_Control &>(a_);
        return (applyParams ? a.applyParams ? applyParams->equiv(*a.applyParams) : false : a.applyParams == nullptr);
    }
void IR::Type_Control::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_ArchBlock::visit_children(v, n);
    v.visit(applyParams, "applyParams");
}
void IR::Type_Control::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_ArchBlock::visit_children(v, n);
    v.visit(applyParams, "applyParams");
}
void IR::Type_Control::validate() const {
#line 2140 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(applyParams); }
void IR::Type_Control::toJSON(JSONGenerator & json) const {
    Type_ArchBlock::toJSON(json);
    json.emit("applyParams", applyParams);
}
IR::Type_Control::Type_Control(JSONLoader & json) : Type_ArchBlock(json) {
    json.load("applyParams", applyParams);
}
IR::Node * IR::Type_Control::fromJSON(JSONLoader & json) { return new Type_Control(json); }
bool IR::Type_Control::operator==(IR::Type_ArchBlock const & a) const { return a == *this; }
bool IR::Type_Control::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_Control::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Control::operator==(IR::Node const & a) const { return a == *this; }
#line 610 "/root/p4c/ir/type.def"
IR::Type_Name::Type_Name(IR::ID id) : Type(id.srcInfo), path(new IR::Path(id)) {}
#line 2157 "/root/p4c/build/ir/ir-generated.cpp"
#line 611 "/root/p4c/ir/type.def"
cstring IR::Type_Name::toString() const { return path->name; }
#line 2160 "/root/p4c/build/ir/ir-generated.cpp"
#line 612 "/root/p4c/ir/type.def"
void IR::Type_Name::dbprint(std::ostream & out) const { out << path->toString(); }
#line 2163 "/root/p4c/build/ir/ir-generated.cpp"
#line 613 "/root/p4c/ir/type.def"
IR::Type const * IR::Type_Name::getP4Type() const { return this; }
#line 2166 "/root/p4c/build/ir/ir-generated.cpp"
#line 614 "/root/p4c/ir/type.def"
int IR::Type_Name::width_bits() const {
        BUG("Type_Name is not a canonical type, use getTypeType()?");
        return 0;
    }
#line 2172 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Name::operator==(IR::Type_Name const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && path == a.path;
    }
bool IR::Type_Name::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Name &>(a_);
        return (path ? a.path ? path->equiv(*a.path) : false : a.path == nullptr);
    }
void IR::Type_Name::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type::visit_children(v, n);
    v.visit(path, "path");
}
void IR::Type_Name::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type::visit_children(v, n);
    v.visit(path, "path");
}
void IR::Type_Name::validate() const {
#line 2194 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(path); }
void IR::Type_Name::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("path", path);
}
IR::Type_Name::Type_Name(JSONLoader & json) : Type(json) {
    json.load("path", path);
}
IR::Node * IR::Type_Name::fromJSON(JSONLoader & json) { return new Type_Name(json); }
bool IR::Type_Name::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Name::operator==(IR::Node const & a) const { return a == *this; }
#line 623 "/root/p4c/ir/type.def"
cstring IR::Type_Stack::toString() const {
        return
            absl::StrCat(elementType,
                         "[",
                         sizeKnown() ? size->toString() : "?"_cs,
                         "]"); }
#line 2214 "/root/p4c/build/ir/ir-generated.cpp"
#line 629 "/root/p4c/ir/type.def"
void IR::Type_Stack::dbprint(std::ostream & out) const { out << elementType << "[" << size << "]"; }
#line 2217 "/root/p4c/build/ir/ir-generated.cpp"
#line 639 "/root/p4c/ir/type.def"
IR::Type const * IR::Type_Stack::getP4Type() const { return new IR::Type_Stack(srcInfo, elementType->getP4Type(), size); }
#line 2220 "/root/p4c/build/ir/ir-generated.cpp"
#line 641 "/root/p4c/ir/type.def"
int IR::Type_Stack::width_bits() const { return getSize() * elementType->width_bits(); }
#line 2223 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Stack::operator==(IR::Type_Stack const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && elementType == a.elementType
        && size == a.size;
    }
bool IR::Type_Stack::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Stack &>(a_);
        return (elementType ? a.elementType ? elementType->equiv(*a.elementType) : false : a.elementType == nullptr)
        && (size ? a.size ? size->equiv(*a.size) : false : a.size == nullptr);
    }
void IR::Type_Stack::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type::visit_children(v, n);
    v.visit(elementType, "elementType");
    v.visit(size, "size");
}
void IR::Type_Stack::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type::visit_children(v, n);
    v.visit(elementType, "elementType");
    v.visit(size, "size");
}
void IR::Type_Stack::validate() const {
#line 2249 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(elementType);
        CHECK_NULL(size); }
void IR::Type_Stack::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("elementType", elementType);
    json.emit("size", size);
}
IR::Type_Stack::Type_Stack(JSONLoader & json) : Type(json) {
    json.load("elementType", elementType);
    json.load("size", size);
}
IR::Node * IR::Type_Stack::fromJSON(JSONLoader & json) { return new Type_Stack(json); }
bool IR::Type_Stack::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Stack::operator==(IR::Node const & a) const { return a == *this; }
#line 652 "/root/p4c/ir/type.def"
void IR::Type_Specialized::validate() const {
#line 2267 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(baseType);
        CHECK_NULL(arguments);
#line 652 "/root/p4c/ir/type.def"
{ arguments->check_null(); } }
#line 2273 "/root/p4c/build/ir/ir-generated.cpp"
#line 654 "/root/p4c/ir/type.def"
cstring IR::Type_Specialized::toString() const {
        return
            absl::StrCat(baseType,
                         "<",
                         absl::StrJoin(*arguments, ", ",
                                       [](std::string *out, const auto *t) {
                                           absl::StrAppend(out, t);
                                       }),
                         ">");
    }
#line 2285 "/root/p4c/build/ir/ir-generated.cpp"
#line 664 "/root/p4c/ir/type.def"
IR::Type_Specialized::Type_Specialized(cstring bt, std::initializer_list<const IR::Type *> args) : baseType(new Type_Name(bt)), arguments(new Vector<Type>(args)) {}
#line 2288 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Specialized::operator==(IR::Type_Specialized const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && baseType == a.baseType
        && arguments == a.arguments;
    }
bool IR::Type_Specialized::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Specialized &>(a_);
        return (baseType ? a.baseType ? baseType->equiv(*a.baseType) : false : a.baseType == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr);
    }
void IR::Type_Specialized::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type::visit_children(v, n);
    v.visit(baseType, "baseType");
    v.visit(arguments, "arguments");
}
void IR::Type_Specialized::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type::visit_children(v, n);
    v.visit(baseType, "baseType");
    v.visit(arguments, "arguments");
}
void IR::Type_Specialized::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("baseType", baseType);
    json.emit("arguments", arguments);
}
IR::Type_Specialized::Type_Specialized(JSONLoader & json) : Type(json) {
    json.load("baseType", baseType);
    json.load("arguments", arguments);
}
IR::Node * IR::Type_Specialized::fromJSON(JSONLoader & json) { return new Type_Specialized(json); }
bool IR::Type_Specialized::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Specialized::operator==(IR::Node const & a) const { return a == *this; }
/// canonical baseType; always IMayBeGenericType
/// canonical type arguments
/// 'substituted' is baseType with all type
/// variables substituted with the arguments.

#line 677 "/root/p4c/ir/type.def"
void IR::Type_SpecializedCanonical::validate() const {
#line 2332 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(baseType);
        CHECK_NULL(arguments);
        CHECK_NULL(substituted);
#line 677 "/root/p4c/ir/type.def"
{
        arguments->check_null();
        BUG_CHECK(baseType->is<IMayBeGenericType>(), "base type %1% is not generic", baseType);
        BUG_CHECK(substituted->is<IMayBeGenericType>(), "substituted %1% is not generic", substituted);
    } }
#line 2343 "/root/p4c/build/ir/ir-generated.cpp"
#line 683 "/root/p4c/ir/type.def"
cstring IR::Type_SpecializedCanonical::toString() const { return baseType->toString() + "<...>"_cs; }
#line 2346 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_SpecializedCanonical::operator==(IR::Type_SpecializedCanonical const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && baseType == a.baseType
        && arguments == a.arguments
        && substituted == a.substituted;
    }
bool IR::Type_SpecializedCanonical::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_SpecializedCanonical &>(a_);
        return (baseType ? a.baseType ? baseType->equiv(*a.baseType) : false : a.baseType == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr)
        && (substituted ? a.substituted ? substituted->equiv(*a.substituted) : false : a.substituted == nullptr);
    }
void IR::Type_SpecializedCanonical::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type::visit_children(v, n);
    v.visit(baseType, "baseType");
    v.visit(arguments, "arguments");
    v.visit(substituted, "substituted");
}
void IR::Type_SpecializedCanonical::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type::visit_children(v, n);
    v.visit(baseType, "baseType");
    v.visit(arguments, "arguments");
    v.visit(substituted, "substituted");
}
void IR::Type_SpecializedCanonical::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("baseType", baseType);
    json.emit("arguments", arguments);
    json.emit("substituted", substituted);
}
IR::Type_SpecializedCanonical::Type_SpecializedCanonical(JSONLoader & json) : Type(json) {
    json.load("baseType", baseType);
    json.load("arguments", arguments);
    json.load("substituted", substituted);
}
IR::Node * IR::Type_SpecializedCanonical::fromJSON(JSONLoader & json) { return new Type_SpecializedCanonical(json); }
bool IR::Type_SpecializedCanonical::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_SpecializedCanonical::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Declaration_ID::operator==(IR::Declaration_ID const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a));
    }
bool IR::Declaration_ID::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        return true;
    }
void IR::Declaration_ID::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
}
IR::Declaration_ID::Declaration_ID(JSONLoader & json) : Declaration(json) {
}
IR::Node * IR::Declaration_ID::fromJSON(JSONLoader & json) { return new Declaration_ID(json); }
bool IR::Declaration_ID::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::Declaration_ID::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::Declaration_ID::operator==(IR::Node const & a) const { return a == *this; }
#line 707 "/root/p4c/ir/type.def"
cstring IR::Type_String::toString() const { return "string"_cs; }
#line 2408 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_String::operator==(IR::Type_String const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_String::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_String::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_String::Type_String(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_String::fromJSON(JSONLoader & json) { return new Type_String(json); }
bool IR::Type_String::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_String::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_String::operator==(IR::Node const & a) const { return a == *this; }
#line 713 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> const & IR::Type_Enum::getAnnotations() const { return annotations; }
#line 2428 "/root/p4c/build/ir/ir-generated.cpp"
#line 714 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> & IR::Type_Enum::getAnnotations() { return annotations; }
#line 2431 "/root/p4c/build/ir/ir-generated.cpp"
#line 715 "/root/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_Enum::getDeclarations() const {
        return members.getDeclarations(); }
#line 2435 "/root/p4c/build/ir/ir-generated.cpp"
#line 717 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_Enum::getDeclByName(cstring name) const {
        return members.getDeclaration(name); }
#line 2439 "/root/p4c/build/ir/ir-generated.cpp"
#line 719 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_Enum::getDeclByName(std::string_view name) const {
        return members.getDeclaration(name); }
#line 2443 "/root/p4c/build/ir/ir-generated.cpp"
#line 722 "/root/p4c/ir/type.def"
void IR::Type_Enum::validate() const {
#line 2446 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        members.validate();
#line 722 "/root/p4c/ir/type.def"
{ members.check_null(); } }
#line 2452 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Enum::operator==(IR::Type_Enum const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && members == a.members;
    }
bool IR::Type_Enum::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Enum &>(a_);
        return annotations.equiv(a.annotations)
        && members.equiv(a.members);
    }
void IR::Type_Enum::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    members.visit_children(v, "members");
}
void IR::Type_Enum::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    members.visit_children(v, "members");
}
void IR::Type_Enum::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("members", members);
}
IR::Type_Enum::Type_Enum(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("members", members);
}
IR::Node * IR::Type_Enum::fromJSON(JSONLoader & json) { return new Type_Enum(json); }
bool IR::Type_Enum::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_Enum::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Enum::operator==(IR::Node const & a) const { return a == *this; }
#line 728 "/root/p4c/ir/type.def"
void IR::SerEnumMember::validate() const {
#line 2492 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(value);
#line 728 "/root/p4c/ir/type.def"
{ CHECK_NULL(value); } }
#line 2497 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::SerEnumMember::operator==(IR::SerEnumMember const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && value == a.value;
    }
bool IR::SerEnumMember::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const SerEnumMember &>(a_);
        return (value ? a.value ? value->equiv(*a.value) : false : a.value == nullptr);
    }
void IR::SerEnumMember::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    v.visit(value, "value");
}
void IR::SerEnumMember::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    v.visit(value, "value");
}
void IR::SerEnumMember::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("value", value);
}
IR::SerEnumMember::SerEnumMember(JSONLoader & json) : Declaration(json) {
    json.load("value", value);
}
IR::Node * IR::SerEnumMember::fromJSON(JSONLoader & json) { return new SerEnumMember(json); }
bool IR::SerEnumMember::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::SerEnumMember::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::SerEnumMember::operator==(IR::Node const & a) const { return a == *this; }
#line 737 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> const & IR::Type_SerEnum::getAnnotations() const { return annotations; }
#line 2531 "/root/p4c/build/ir/ir-generated.cpp"
#line 738 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> & IR::Type_SerEnum::getAnnotations() { return annotations; }
#line 2534 "/root/p4c/build/ir/ir-generated.cpp"
#line 739 "/root/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_SerEnum::getDeclarations() const {
        return members.getDeclarations(); }
#line 2538 "/root/p4c/build/ir/ir-generated.cpp"
#line 741 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_SerEnum::getDeclByName(cstring name) const {
        return members.getDeclaration(name); }
#line 2542 "/root/p4c/build/ir/ir-generated.cpp"
#line 743 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_SerEnum::getDeclByName(std::string_view name) const {
        return members.getDeclaration(name); }
#line 2546 "/root/p4c/build/ir/ir-generated.cpp"
#line 746 "/root/p4c/ir/type.def"
void IR::Type_SerEnum::validate() const {
#line 2549 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(type);
        members.validate();
#line 746 "/root/p4c/ir/type.def"
{ members.check_null(); } }
#line 2556 "/root/p4c/build/ir/ir-generated.cpp"
#line 747 "/root/p4c/ir/type.def"
int IR::Type_SerEnum::width_bits() const { return type->width_bits(); }
#line 2559 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_SerEnum::operator==(IR::Type_SerEnum const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && type == a.type
        && members == a.members;
    }
bool IR::Type_SerEnum::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_SerEnum &>(a_);
        return annotations.equiv(a.annotations)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && members.equiv(a.members);
    }
void IR::Type_SerEnum::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
    members.visit_children(v, "members");
}
void IR::Type_SerEnum::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
    members.visit_children(v, "members");
}
void IR::Type_SerEnum::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("type", type);
    json.emit("members", members);
}
IR::Type_SerEnum::Type_SerEnum(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
    json.load("members", members);
}
IR::Node * IR::Type_SerEnum::fromJSON(JSONLoader & json) { return new Type_SerEnum(json); }
bool IR::Type_SerEnum::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_SerEnum::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_SerEnum::operator==(IR::Node const & a) const { return a == *this; }
#line 753 "/root/p4c/ir/type.def"
const IR::ParameterList *IR::Type_Table::getApplyParameters() const { return new ParameterList(); }
#line 2605 "/root/p4c/build/ir/ir-generated.cpp"
/// names for the fields of the struct returned
/// by applying a table
#line 759 "/root/p4c/ir/type.def"
IR::Type const * IR::Type_Table::getP4Type() const { return nullptr; }
#line 2610 "/root/p4c/build/ir/ir-generated.cpp"
#line 760 "/root/p4c/ir/type.def"
void IR::Type_Table::dbprint(std::ostream & out) const { out << table->name; }
#line 2613 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Table::operator==(IR::Type_Table const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && table == a.table;
    }
bool IR::Type_Table::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Table &>(a_);
        return (table ? a.table ? table->equiv(*a.table) : false : a.table == nullptr);
    }
void IR::Type_Table::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type::visit_children(v, n);
    v.visit(table, "table");
}
void IR::Type_Table::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type::visit_children(v, n);
    v.visit(table, "table");
}
void IR::Type_Table::validate() const {
#line 2635 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(table); }
void IR::Type_Table::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("table", table);
}
IR::Type_Table::Type_Table(JSONLoader & json) : Type(json) {
    json.load("table", table);
}
IR::Node * IR::Type_Table::fromJSON(JSONLoader & json) { return new Type_Table(json); }
bool IR::Type_Table::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Table::operator==(IR::Node const & a) const { return a == *this; }
#line 769 "/root/p4c/ir/type.def"
IR::Type const * IR::Type_ActionEnum::getP4Type() const { return nullptr; }
#line 2650 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_ActionEnum::operator==(IR::Type_ActionEnum const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && actionList == a.actionList;
    }
bool IR::Type_ActionEnum::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_ActionEnum &>(a_);
        return (actionList ? a.actionList ? actionList->equiv(*a.actionList) : false : a.actionList == nullptr);
    }
void IR::Type_ActionEnum::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type::visit_children(v, n);
    v.visit(actionList, "actionList");
}
void IR::Type_ActionEnum::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type::visit_children(v, n);
    v.visit(actionList, "actionList");
}
void IR::Type_ActionEnum::validate() const {
#line 2672 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(actionList); }
void IR::Type_ActionEnum::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("actionList", actionList);
}
IR::Type_ActionEnum::Type_ActionEnum(JSONLoader & json) : Type(json) {
    json.load("actionList", actionList);
}
IR::Node * IR::Type_ActionEnum::fromJSON(JSONLoader & json) { return new Type_ActionEnum(json); }
bool IR::Type_ActionEnum::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_ActionEnum::operator==(IR::Node const & a) const { return a == *this; }


#line 786 "/root/p4c/ir/type.def"
const IR::TypeParameters *IR::Type_MethodBase::getTypeParameters() const { return typeParameters; }
#line 2689 "/root/p4c/build/ir/ir-generated.cpp"
#line 788 "/root/p4c/ir/type.def"
cstring IR::Type_MethodBase::toString() const { return "<Method>"_cs; }
#line 2692 "/root/p4c/build/ir/ir-generated.cpp"
#line 789 "/root/p4c/ir/type.def"
IR::Type const * IR::Type_MethodBase::getP4Type() const { return nullptr; }
#line 2695 "/root/p4c/build/ir/ir-generated.cpp"
#line 790 "/root/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_MethodBase::getDeclarations() const {
        return typeParameters->getDeclarations()->concat(parameters->getDeclarations()); }
#line 2699 "/root/p4c/build/ir/ir-generated.cpp"
#line 792 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_MethodBase::getDeclByName(cstring name) const {
        auto decl = parameters->getDeclByName(name);
        if (!decl) decl = typeParameters->getDeclByName(name);
        return decl; }
#line 2705 "/root/p4c/build/ir/ir-generated.cpp"
#line 796 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_MethodBase::getDeclByName(std::string_view name) const {
        auto decl = parameters->getDeclByName(name);
        if (!decl) decl = typeParameters->getDeclByName(name);
        return decl; }
#line 2711 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_MethodBase::operator==(IR::Type_MethodBase const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && typeParameters == a.typeParameters
        && returnType == a.returnType
        && parameters == a.parameters;
    }
bool IR::Type_MethodBase::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_MethodBase &>(a_);
        return (typeParameters ? a.typeParameters ? typeParameters->equiv(*a.typeParameters) : false : a.typeParameters == nullptr)
        && (returnType ? a.returnType ? returnType->equiv(*a.returnType) : false : a.returnType == nullptr)
        && (parameters ? a.parameters ? parameters->equiv(*a.parameters) : false : a.parameters == nullptr);
    }
void IR::Type_MethodBase::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type::visit_children(v, n);
    v.visit(typeParameters, "typeParameters");
    v.visit(returnType, "returnType");
    v.visit(parameters, "parameters");
}
void IR::Type_MethodBase::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type::visit_children(v, n);
    v.visit(typeParameters, "typeParameters");
    v.visit(returnType, "returnType");
    v.visit(parameters, "parameters");
}
void IR::Type_MethodBase::validate() const {
#line 2741 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(typeParameters);
        CHECK_NULL(parameters); }
void IR::Type_MethodBase::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("typeParameters", typeParameters);
    if (returnType != nullptr) json.emit("returnType", returnType);
    json.emit("parameters", parameters);
}
IR::Type_MethodBase::Type_MethodBase(JSONLoader & json) : Type(json) {
    json.load("typeParameters", typeParameters);
    json.load("returnType", returnType);
    json.load("parameters", parameters);
}
bool IR::Type_MethodBase::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_MethodBase::operator==(IR::Node const & a) const { return a == *this; }

#line 807 "/root/p4c/ir/type.def"
cstring IR::Type_Method::toString() const { return name; }
#line 2761 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Method::operator==(IR::Type_Method const & a) const {
        return Type_MethodBase::operator==(static_cast<const Type_MethodBase &>(a))
        && name == a.name;
    }
bool IR::Type_Method::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_MethodBase::equiv(a_)) return false;
        auto &a = static_cast<const Type_Method &>(a_);
        return name == a.name;
    }
void IR::Type_Method::dump_fields(std::ostream & out) const {
    Type_MethodBase::dump_fields(out);
        out << " name=" << name;
}
void IR::Type_Method::toJSON(JSONGenerator & json) const {
    Type_MethodBase::toJSON(json);
    json.emit("name", name);
}
IR::Type_Method::Type_Method(JSONLoader & json) : Type_MethodBase(json) {
    json.load("name", name);
}
IR::Node * IR::Type_Method::fromJSON(JSONLoader & json) { return new Type_Method(json); }
bool IR::Type_Method::operator==(IR::Type_MethodBase const & a) const { return a == *this; }
bool IR::Type_Method::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Method::operator==(IR::Node const & a) const { return a == *this; }
#line 817 "/root/p4c/ir/type.def"
cstring IR::ArgumentInfo::toString() const { return argument->toString(); }
#line 2789 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ArgumentInfo::operator==(IR::ArgumentInfo const & a) const {
        return this->typeId() == a.typeId()
        && leftValue == a.leftValue
        && compileTimeConstant == a.compileTimeConstant
        && type == a.type
        && argument == a.argument;
    }
bool IR::ArgumentInfo::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const ArgumentInfo &>(a_);
        return leftValue == a.leftValue
        && compileTimeConstant == a.compileTimeConstant
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (argument ? a.argument ? argument->equiv(*a.argument) : false : a.argument == nullptr);
    }
void IR::ArgumentInfo::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(type, "type");
    v.visit(argument, "argument");
}
void IR::ArgumentInfo::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(type, "type");
    v.visit(argument, "argument");
}
void IR::ArgumentInfo::validate() const {
#line 2819 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(argument); }
void IR::ArgumentInfo::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " leftValue=" << leftValue;
        out << " compileTimeConstant=" << compileTimeConstant;
}
void IR::ArgumentInfo::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("leftValue", leftValue);
    json.emit("compileTimeConstant", compileTimeConstant);
    json.emit("type", type);
    json.emit("argument", argument);
}
IR::ArgumentInfo::ArgumentInfo(JSONLoader & json) : Node(json) {
    json.load("leftValue", leftValue);
    json.load("compileTimeConstant", compileTimeConstant);
    json.load("type", type);
    json.load("argument", argument);
}
IR::Node * IR::ArgumentInfo::fromJSON(JSONLoader & json) { return new ArgumentInfo(json); }
bool IR::ArgumentInfo::operator==(IR::Node const & a) const { return a == *this; }
#line 828 "/root/p4c/ir/type.def"
void IR::Type_MethodCall::validate() const {
#line 2845 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(typeArguments);
        CHECK_NULL(returnType);
        CHECK_NULL(arguments);
#line 828 "/root/p4c/ir/type.def"
{ typeArguments->check_null(); arguments->check_null(); } }
#line 2852 "/root/p4c/build/ir/ir-generated.cpp"
#line 829 "/root/p4c/ir/type.def"
IR::Type const * IR::Type_MethodCall::getP4Type() const { return nullptr; }
#line 2855 "/root/p4c/build/ir/ir-generated.cpp"
#line 830 "/root/p4c/ir/type.def"
cstring IR::Type_MethodCall::toString() const { return "<Method call>"_cs; }
#line 2858 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_MethodCall::operator==(IR::Type_MethodCall const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && typeArguments == a.typeArguments
        && returnType == a.returnType
        && arguments == a.arguments;
    }
bool IR::Type_MethodCall::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_MethodCall &>(a_);
        return (typeArguments ? a.typeArguments ? typeArguments->equiv(*a.typeArguments) : false : a.typeArguments == nullptr)
        && (returnType ? a.returnType ? returnType->equiv(*a.returnType) : false : a.returnType == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr);
    }
void IR::Type_MethodCall::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type::visit_children(v, n);
    v.visit(typeArguments, "typeArguments");
    v.visit(returnType, "returnType");
    v.visit(arguments, "arguments");
}
void IR::Type_MethodCall::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type::visit_children(v, n);
    v.visit(typeArguments, "typeArguments");
    v.visit(returnType, "returnType");
    v.visit(arguments, "arguments");
}
void IR::Type_MethodCall::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json.emit("typeArguments", typeArguments);
    json.emit("returnType", returnType);
    json.emit("arguments", arguments);
}
IR::Type_MethodCall::Type_MethodCall(JSONLoader & json) : Type(json) {
    json.load("typeArguments", typeArguments);
    json.load("returnType", returnType);
    json.load("arguments", arguments);
}
IR::Node * IR::Type_MethodCall::fromJSON(JSONLoader & json) { return new Type_MethodCall(json); }
bool IR::Type_MethodCall::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_MethodCall::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Type_Action::operator==(IR::Type_Action const & a) const {
        return Type_MethodBase::operator==(static_cast<const Type_MethodBase &>(a));
    }
bool IR::Type_Action::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_MethodBase::equiv(a_)) return false;
        return true;
    }
void IR::Type_Action::toJSON(JSONGenerator & json) const {
    Type_MethodBase::toJSON(json);
}
IR::Type_Action::Type_Action(JSONLoader & json) : Type_MethodBase(json) {
}
IR::Node * IR::Type_Action::fromJSON(JSONLoader & json) { return new Type_Action(json); }
bool IR::Type_Action::operator==(IR::Type_MethodBase const & a) const { return a == *this; }
bool IR::Type_Action::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Action::operator==(IR::Node const & a) const { return a == *this; }
#line 847 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> const & IR::Method::getAnnotations() const { return annotations; }
#line 2920 "/root/p4c/build/ir/ir-generated.cpp"
#line 848 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> & IR::Method::getAnnotations() { return annotations; }
#line 2923 "/root/p4c/build/ir/ir-generated.cpp"
#line 849 "/root/p4c/ir/type.def"
const IR::ParameterList *IR::Method::getParameters() const { return type->parameters; }
#line 2926 "/root/p4c/build/ir/ir-generated.cpp"

#line 851 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::Method::getDeclByName(cstring name) const {
        return type->parameters->getDeclByName(name); }
#line 2931 "/root/p4c/build/ir/ir-generated.cpp"
#line 853 "/root/p4c/ir/type.def"
const IR::IDeclaration *IR::Method::getDeclByName(std::string_view name) const {
        return type->parameters->getDeclByName(name); }
#line 2935 "/root/p4c/build/ir/ir-generated.cpp"
#line 855 "/root/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Method::getDeclarations() const {
        return type->parameters->getDeclarations(); }
#line 2939 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Method::operator==(IR::Method const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && type == a.type
        && isAbstract == a.isAbstract
        && annotations == a.annotations;
    }
bool IR::Method::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Method &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && isAbstract == a.isAbstract
        && annotations.equiv(a.annotations);
    }
void IR::Method::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    v.visit(type, "type");
    annotations.visit_children(v, "annotations");
}
void IR::Method::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    v.visit(type, "type");
    annotations.visit_children(v, "annotations");
}
void IR::Method::validate() const {
#line 2967 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        annotations.validate(); }
void IR::Method::dump_fields(std::ostream & out) const {
    Declaration::dump_fields(out);
        out << " isAbstract=" << isAbstract;
}
void IR::Method::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("type", type);
    json.emit("isAbstract", isAbstract);
    json.emit("annotations", annotations);
}
IR::Method::Method(JSONLoader & json) : Declaration(json) {
    json.load("type", type);
    json.load("isAbstract", isAbstract);
    json.load("annotations", annotations);
}
IR::Node * IR::Method::fromJSON(JSONLoader & json) { return new Method(json); }
bool IR::Method::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::Method::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::Method::operator==(IR::Node const & a) const { return a == *this; }
#line 862 "/root/p4c/ir/type.def"
int IR::Type_Typedef::width_bits() const { return type->width_bits(); }
#line 2992 "/root/p4c/build/ir/ir-generated.cpp"
#line 863 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> const & IR::Type_Typedef::getAnnotations() const { return annotations; }
#line 2995 "/root/p4c/build/ir/ir-generated.cpp"
#line 864 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> & IR::Type_Typedef::getAnnotations() { return annotations; }
#line 2998 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Typedef::operator==(IR::Type_Typedef const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && type == a.type;
    }
bool IR::Type_Typedef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Typedef &>(a_);
        return annotations.equiv(a.annotations)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::Type_Typedef::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
}
void IR::Type_Typedef::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
}
void IR::Type_Typedef::validate() const {
#line 3024 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(type); }
void IR::Type_Typedef::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("type", type);
}
IR::Type_Typedef::Type_Typedef(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
}
IR::Node * IR::Type_Typedef::fromJSON(JSONLoader & json) { return new Type_Typedef(json); }
bool IR::Type_Typedef::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_Typedef::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Typedef::operator==(IR::Node const & a) const { return a == *this; }
#line 876 "/root/p4c/ir/type.def"
int IR::Type_Newtype::width_bits() const { return type->width_bits(); }
#line 3043 "/root/p4c/build/ir/ir-generated.cpp"
#line 877 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> const & IR::Type_Newtype::getAnnotations() const { return annotations; }
#line 3046 "/root/p4c/build/ir/ir-generated.cpp"
#line 878 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> & IR::Type_Newtype::getAnnotations() { return annotations; }
#line 3049 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Newtype::operator==(IR::Type_Newtype const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && type == a.type;
    }
bool IR::Type_Newtype::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Newtype &>(a_);
        return annotations.equiv(a.annotations)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::Type_Newtype::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
}
void IR::Type_Newtype::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
}
void IR::Type_Newtype::validate() const {
#line 3075 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(type); }
void IR::Type_Newtype::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("type", type);
}
IR::Type_Newtype::Type_Newtype(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
}
IR::Node * IR::Type_Newtype::fromJSON(JSONLoader & json) { return new Type_Newtype(json); }
bool IR::Type_Newtype::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_Newtype::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Newtype::operator==(IR::Node const & a) const { return a == *this; }


#line 890 "/root/p4c/ir/type.def"
std::vector<const IR::INamespace *> IR::Type_Extern::getNestedNamespaces() const { return { typeParameters }; }
#line 3096 "/root/p4c/build/ir/ir-generated.cpp"
#line 891 "/root/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_Extern::getDeclarations() const {
        return attributes.valueEnumerator()->as<const IDeclaration*>()
            ->concat(methods.getEnumerator()->as<const IDeclaration*>()); }
#line 3101 "/root/p4c/build/ir/ir-generated.cpp"
#line 894 "/root/p4c/ir/type.def"
const IR::TypeParameters *IR::Type_Extern::getTypeParameters() const { return typeParameters; }
#line 3104 "/root/p4c/build/ir/ir-generated.cpp"
#line 895 "/root/p4c/ir/type.def"
void IR::Type_Extern::validate() const {
#line 3107 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(typeParameters);
        methods.validate();
        attributes.validate();
        annotations.validate();
#line 895 "/root/p4c/ir/type.def"
{ methods.check_null(); } }
#line 3115 "/root/p4c/build/ir/ir-generated.cpp"
#line 896 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> const & IR::Type_Extern::getAnnotations() const { return annotations; }
#line 3118 "/root/p4c/build/ir/ir-generated.cpp"
#line 897 "/root/p4c/ir/type.def"
IR::Vector<IR::Annotation> & IR::Type_Extern::getAnnotations() { return annotations; }
#line 3121 "/root/p4c/build/ir/ir-generated.cpp"
/// Returns the method that matches the specified arguments.
/// Returns nullptr if no method or more than one method match.
/// In the latter case it also reports an error.
/// Returns the constructor that matches the specified arguments.
/// Returns nullptr if no constructor or more than one constructor matches.
/// In the latter case it also reports an error.
#line 905 "/root/p4c/ir/type.def"
const IR::Method *IR::Type_Extern::lookupConstructor(const IR::Vector<IR::Argument>* arguments) const { return lookupMethod(name, arguments); }
#line 3130 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Extern::operator==(IR::Type_Extern const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && typeParameters == a.typeParameters
        && methods == a.methods
        && attributes == a.attributes
        && annotations == a.annotations;
    }
bool IR::Type_Extern::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Extern &>(a_);
        return (typeParameters ? a.typeParameters ? typeParameters->equiv(*a.typeParameters) : false : a.typeParameters == nullptr)
        && methods.equiv(a.methods)
        && attributes.equiv(a.attributes)
        && annotations.equiv(a.annotations);
    }
void IR::Type_Extern::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_Declaration::visit_children(v, n);
    v.visit(typeParameters, "typeParameters");
    methods.visit_children(v, "methods");
    attributes.visit_children(v, "attributes");
    annotations.visit_children(v, "annotations");
}
void IR::Type_Extern::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_Declaration::visit_children(v, n);
    v.visit(typeParameters, "typeParameters");
    methods.visit_children(v, "methods");
    attributes.visit_children(v, "attributes");
    annotations.visit_children(v, "annotations");
}
void IR::Type_Extern::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json.emit("typeParameters", typeParameters);
    json.emit("methods", methods);
    json.emit("attributes", attributes);
    json.emit("annotations", annotations);
}
IR::Type_Extern::Type_Extern(JSONLoader & json) : Type_Declaration(json) {
    json.load("typeParameters", typeParameters);
    json.load("methods", methods);
    json.load("attributes", attributes);
    json.load("annotations", annotations);
}
IR::Node * IR::Type_Extern::fromJSON(JSONLoader & json) { return new Type_Extern(json); }
bool IR::Type_Extern::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_Extern::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Extern::operator==(IR::Node const & a) const { return a == *this; }
#line 15 "/root/p4c/ir/expression.def"
cstring IR::Operation_Unary::toString() const { return getStringOp() + expr->toString(); }
#line 3182 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Operation_Unary::operator==(IR::Operation_Unary const & a) const {
        return Operation::operator==(static_cast<const Operation &>(a))
        && expr == a.expr;
    }
bool IR::Operation_Unary::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation::equiv(a_)) return false;
        auto &a = static_cast<const Operation_Unary &>(a_);
        return (expr ? a.expr ? expr->equiv(*a.expr) : false : a.expr == nullptr);
    }
void IR::Operation_Unary::visit_children(Visitor & v, char const * n) {
    (void)n;
    Operation::visit_children(v, n);
    v.visit(expr, "expr");
}
void IR::Operation_Unary::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Operation::visit_children(v, n);
    v.visit(expr, "expr");
}
void IR::Operation_Unary::validate() const {
#line 3204 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(expr); }
void IR::Operation_Unary::toJSON(JSONGenerator & json) const {
    Operation::toJSON(json);
    json.emit("expr", expr);
}
IR::Operation_Unary::Operation_Unary(JSONLoader & json) : Operation(json) {
    json.load("expr", expr);
}
bool IR::Operation_Unary::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Operation_Unary::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Operation_Unary::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Neg::operator==(IR::Neg const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a));
    }
bool IR::Neg::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        return true;
    }
void IR::Neg::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
}
IR::Neg::Neg(JSONLoader & json) : Operation_Unary(json) {
}
IR::Node * IR::Neg::fromJSON(JSONLoader & json) { return new Neg(json); }
bool IR::Neg::operator==(IR::Operation_Unary const & a) const { return a == *this; }
bool IR::Neg::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Neg::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Neg::operator==(IR::Node const & a) const { return a == *this; }
bool IR::UPlus::operator==(IR::UPlus const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a));
    }
bool IR::UPlus::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        return true;
    }
void IR::UPlus::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
}
IR::UPlus::UPlus(JSONLoader & json) : Operation_Unary(json) {
}
IR::Node * IR::UPlus::fromJSON(JSONLoader & json) { return new UPlus(json); }
bool IR::UPlus::operator==(IR::Operation_Unary const & a) const { return a == *this; }
bool IR::UPlus::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::UPlus::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::UPlus::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Cmpl::operator==(IR::Cmpl const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a));
    }
bool IR::Cmpl::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        return true;
    }
void IR::Cmpl::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
}
IR::Cmpl::Cmpl(JSONLoader & json) : Operation_Unary(json) {
}
IR::Node * IR::Cmpl::fromJSON(JSONLoader & json) { return new Cmpl(json); }
bool IR::Cmpl::operator==(IR::Operation_Unary const & a) const { return a == *this; }
bool IR::Cmpl::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Cmpl::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Cmpl::operator==(IR::Node const & a) const { return a == *this; }
bool IR::LNot::operator==(IR::LNot const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a));
    }
bool IR::LNot::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        return true;
    }
void IR::LNot::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
}
IR::LNot::LNot(JSONLoader & json) : Operation_Unary(json) {
}
IR::Node * IR::LNot::fromJSON(JSONLoader & json) { return new LNot(json); }
bool IR::LNot::operator==(IR::Operation_Unary const & a) const { return a == *this; }
bool IR::LNot::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::LNot::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::LNot::operator==(IR::Node const & a) const { return a == *this; }
#line 47 "/root/p4c/ir/expression.def"
cstring IR::Operation_Binary::toString() const {
        // FIXME: Do not use debug printing to render user-side strings
        std::stringstream tmp;
        tmp << DBPrint::Prec_Low;
        dbprint(tmp);
        return tmp.str();
    }
#line 3297 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Operation_Binary::operator==(IR::Operation_Binary const & a) const {
        return Operation::operator==(static_cast<const Operation &>(a))
        && left == a.left
        && right == a.right;
    }
bool IR::Operation_Binary::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation::equiv(a_)) return false;
        auto &a = static_cast<const Operation_Binary &>(a_);
        return (left ? a.left ? left->equiv(*a.left) : false : a.left == nullptr)
        && (right ? a.right ? right->equiv(*a.right) : false : a.right == nullptr);
    }
void IR::Operation_Binary::visit_children(Visitor & v, char const * n) {
    (void)n;
    Operation::visit_children(v, n);
    v.visit(left, "left");
    v.visit(right, "right");
}
void IR::Operation_Binary::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Operation::visit_children(v, n);
    v.visit(left, "left");
    v.visit(right, "right");
}
void IR::Operation_Binary::validate() const {
#line 3323 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(left);
        CHECK_NULL(right); }
void IR::Operation_Binary::toJSON(JSONGenerator & json) const {
    Operation::toJSON(json);
    json.emit("left", left);
    json.emit("right", right);
}
IR::Operation_Binary::Operation_Binary(JSONLoader & json) : Operation(json) {
    json.load("left", left);
    json.load("right", right);
}
bool IR::Operation_Binary::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Operation_Binary::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Operation_Binary::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Operation_Ternary::operator==(IR::Operation_Ternary const & a) const {
        return Operation::operator==(static_cast<const Operation &>(a))
        && e0 == a.e0
        && e1 == a.e1
        && e2 == a.e2;
    }
bool IR::Operation_Ternary::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation::equiv(a_)) return false;
        auto &a = static_cast<const Operation_Ternary &>(a_);
        return (e0 ? a.e0 ? e0->equiv(*a.e0) : false : a.e0 == nullptr)
        && (e1 ? a.e1 ? e1->equiv(*a.e1) : false : a.e1 == nullptr)
        && (e2 ? a.e2 ? e2->equiv(*a.e2) : false : a.e2 == nullptr);
    }
void IR::Operation_Ternary::visit_children(Visitor & v, char const * n) {
    (void)n;
    Operation::visit_children(v, n);
    v.visit(e0, "e0");
    v.visit(e1, "e1");
    v.visit(e2, "e2");
}
void IR::Operation_Ternary::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Operation::visit_children(v, n);
    v.visit(e0, "e0");
    v.visit(e1, "e1");
    v.visit(e2, "e2");
}
void IR::Operation_Ternary::validate() const {
#line 3368 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(e0);
        CHECK_NULL(e1);
        CHECK_NULL(e2); }
void IR::Operation_Ternary::toJSON(JSONGenerator & json) const {
    Operation::toJSON(json);
    json.emit("e0", e0);
    json.emit("e1", e1);
    json.emit("e2", e2);
}
IR::Operation_Ternary::Operation_Ternary(JSONLoader & json) : Operation(json) {
    json.load("e0", e0);
    json.load("e1", e1);
    json.load("e2", e2);
}
bool IR::Operation_Ternary::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Operation_Ternary::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Operation_Ternary::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Operation_Relation::operator==(IR::Operation_Relation const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Operation_Relation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Operation_Relation::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Operation_Relation::Operation_Relation(JSONLoader & json) : Operation_Binary(json) {
}
bool IR::Operation_Relation::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Operation_Relation::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Operation_Relation::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Operation_Relation::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Mul::operator==(IR::Mul const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Mul::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Mul::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Mul::Mul(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Mul::fromJSON(JSONLoader & json) { return new Mul(json); }
bool IR::Mul::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Mul::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Mul::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Mul::operator==(IR::Node const & a) const { return a == *this; }
IRNODE_DEFINE_APPLY_OVERLOAD(Statement, , )
bool IR::Statement::operator==(IR::Statement const & a) const {
        return StatOrDecl::operator==(static_cast<const StatOrDecl &>(a));
    }
bool IR::Statement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!StatOrDecl::equiv(a_)) return false;
        return true;
    }
void IR::Statement::toJSON(JSONGenerator & json) const {
    StatOrDecl::toJSON(json);
}
IR::Statement::Statement(JSONLoader & json) : StatOrDecl(json) {
}
bool IR::Statement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::Statement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::BaseAssignmentStatement::operator==(IR::BaseAssignmentStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && left == a.left
        && right == a.right;
    }
bool IR::BaseAssignmentStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const BaseAssignmentStatement &>(a_);
        return (left ? a.left ? left->equiv(*a.left) : false : a.left == nullptr)
        && (right ? a.right ? right->equiv(*a.right) : false : a.right == nullptr);
    }
void IR::BaseAssignmentStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    Statement::visit_children(v, n);
    v.visit(left, "left");
    v.visit(right, "right");
}
void IR::BaseAssignmentStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Statement::visit_children(v, n);
    v.visit(left, "left");
    v.visit(right, "right");
}
void IR::BaseAssignmentStatement::validate() const {
#line 3463 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(left);
        CHECK_NULL(right); }
void IR::BaseAssignmentStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json.emit("left", left);
    json.emit("right", right);
}
IR::BaseAssignmentStatement::BaseAssignmentStatement(JSONLoader & json) : Statement(json) {
    json.load("left", left);
    json.load("right", right);
}
bool IR::BaseAssignmentStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::BaseAssignmentStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::BaseAssignmentStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 482 "/root/p4c/ir/ir.def"
cstring IR::OpAssignmentStatement::toString() const { return absl::StrCat(left, " ", getStringOp(), "= ", right); }
#line 3481 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::OpAssignmentStatement::operator==(IR::OpAssignmentStatement const & a) const {
        return BaseAssignmentStatement::operator==(static_cast<const BaseAssignmentStatement &>(a));
    }
bool IR::OpAssignmentStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!BaseAssignmentStatement::equiv(a_)) return false;
        return true;
    }
void IR::OpAssignmentStatement::toJSON(JSONGenerator & json) const {
    BaseAssignmentStatement::toJSON(json);
}
IR::OpAssignmentStatement::OpAssignmentStatement(JSONLoader & json) : BaseAssignmentStatement(json) {
}
bool IR::OpAssignmentStatement::operator==(IR::BaseAssignmentStatement const & a) const { return a == *this; }
bool IR::OpAssignmentStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::OpAssignmentStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::OpAssignmentStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::MulAssign::operator==(IR::MulAssign const & a) const {
        return OpAssignmentStatement::operator==(static_cast<const OpAssignmentStatement &>(a));
    }
bool IR::MulAssign::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!OpAssignmentStatement::equiv(a_)) return false;
        return true;
    }
void IR::MulAssign::toJSON(JSONGenerator & json) const {
    OpAssignmentStatement::toJSON(json);
}
IR::MulAssign::MulAssign(JSONLoader & json) : OpAssignmentStatement(json) {
}
IR::Node * IR::MulAssign::fromJSON(JSONLoader & json) { return new MulAssign(json); }
bool IR::MulAssign::operator==(IR::OpAssignmentStatement const & a) const { return a == *this; }
bool IR::MulAssign::operator==(IR::BaseAssignmentStatement const & a) const { return a == *this; }
bool IR::MulAssign::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::MulAssign::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::MulAssign::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Div::operator==(IR::Div const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Div::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Div::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Div::Div(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Div::fromJSON(JSONLoader & json) { return new Div(json); }
bool IR::Div::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Div::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Div::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Div::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DivAssign::operator==(IR::DivAssign const & a) const {
        return OpAssignmentStatement::operator==(static_cast<const OpAssignmentStatement &>(a));
    }
bool IR::DivAssign::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!OpAssignmentStatement::equiv(a_)) return false;
        return true;
    }
void IR::DivAssign::toJSON(JSONGenerator & json) const {
    OpAssignmentStatement::toJSON(json);
}
IR::DivAssign::DivAssign(JSONLoader & json) : OpAssignmentStatement(json) {
}
IR::Node * IR::DivAssign::fromJSON(JSONLoader & json) { return new DivAssign(json); }
bool IR::DivAssign::operator==(IR::OpAssignmentStatement const & a) const { return a == *this; }
bool IR::DivAssign::operator==(IR::BaseAssignmentStatement const & a) const { return a == *this; }
bool IR::DivAssign::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::DivAssign::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::DivAssign::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Mod::operator==(IR::Mod const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Mod::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Mod::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Mod::Mod(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Mod::fromJSON(JSONLoader & json) { return new Mod(json); }
bool IR::Mod::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Mod::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Mod::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Mod::operator==(IR::Node const & a) const { return a == *this; }
bool IR::ModAssign::operator==(IR::ModAssign const & a) const {
        return OpAssignmentStatement::operator==(static_cast<const OpAssignmentStatement &>(a));
    }
bool IR::ModAssign::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!OpAssignmentStatement::equiv(a_)) return false;
        return true;
    }
void IR::ModAssign::toJSON(JSONGenerator & json) const {
    OpAssignmentStatement::toJSON(json);
}
IR::ModAssign::ModAssign(JSONLoader & json) : OpAssignmentStatement(json) {
}
IR::Node * IR::ModAssign::fromJSON(JSONLoader & json) { return new ModAssign(json); }
bool IR::ModAssign::operator==(IR::OpAssignmentStatement const & a) const { return a == *this; }
bool IR::ModAssign::operator==(IR::BaseAssignmentStatement const & a) const { return a == *this; }
bool IR::ModAssign::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::ModAssign::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::ModAssign::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Add::operator==(IR::Add const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Add::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Add::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Add::Add(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Add::fromJSON(JSONLoader & json) { return new Add(json); }
bool IR::Add::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Add::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Add::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Add::operator==(IR::Node const & a) const { return a == *this; }
bool IR::AddAssign::operator==(IR::AddAssign const & a) const {
        return OpAssignmentStatement::operator==(static_cast<const OpAssignmentStatement &>(a));
    }
bool IR::AddAssign::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!OpAssignmentStatement::equiv(a_)) return false;
        return true;
    }
void IR::AddAssign::toJSON(JSONGenerator & json) const {
    OpAssignmentStatement::toJSON(json);
}
IR::AddAssign::AddAssign(JSONLoader & json) : OpAssignmentStatement(json) {
}
IR::Node * IR::AddAssign::fromJSON(JSONLoader & json) { return new AddAssign(json); }
bool IR::AddAssign::operator==(IR::OpAssignmentStatement const & a) const { return a == *this; }
bool IR::AddAssign::operator==(IR::BaseAssignmentStatement const & a) const { return a == *this; }
bool IR::AddAssign::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::AddAssign::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::AddAssign::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Sub::operator==(IR::Sub const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Sub::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Sub::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Sub::Sub(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Sub::fromJSON(JSONLoader & json) { return new Sub(json); }
bool IR::Sub::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Sub::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Sub::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Sub::operator==(IR::Node const & a) const { return a == *this; }
bool IR::SubAssign::operator==(IR::SubAssign const & a) const {
        return OpAssignmentStatement::operator==(static_cast<const OpAssignmentStatement &>(a));
    }
bool IR::SubAssign::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!OpAssignmentStatement::equiv(a_)) return false;
        return true;
    }
void IR::SubAssign::toJSON(JSONGenerator & json) const {
    OpAssignmentStatement::toJSON(json);
}
IR::SubAssign::SubAssign(JSONLoader & json) : OpAssignmentStatement(json) {
}
IR::Node * IR::SubAssign::fromJSON(JSONLoader & json) { return new SubAssign(json); }
bool IR::SubAssign::operator==(IR::OpAssignmentStatement const & a) const { return a == *this; }
bool IR::SubAssign::operator==(IR::BaseAssignmentStatement const & a) const { return a == *this; }
bool IR::SubAssign::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::SubAssign::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::SubAssign::operator==(IR::Node const & a) const { return a == *this; }
bool IR::AddSat::operator==(IR::AddSat const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::AddSat::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::AddSat::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::AddSat::AddSat(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::AddSat::fromJSON(JSONLoader & json) { return new AddSat(json); }
bool IR::AddSat::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::AddSat::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::AddSat::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::AddSat::operator==(IR::Node const & a) const { return a == *this; }
bool IR::AddSatAssign::operator==(IR::AddSatAssign const & a) const {
        return OpAssignmentStatement::operator==(static_cast<const OpAssignmentStatement &>(a));
    }
bool IR::AddSatAssign::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!OpAssignmentStatement::equiv(a_)) return false;
        return true;
    }
void IR::AddSatAssign::toJSON(JSONGenerator & json) const {
    OpAssignmentStatement::toJSON(json);
}
IR::AddSatAssign::AddSatAssign(JSONLoader & json) : OpAssignmentStatement(json) {
}
IR::Node * IR::AddSatAssign::fromJSON(JSONLoader & json) { return new AddSatAssign(json); }
bool IR::AddSatAssign::operator==(IR::OpAssignmentStatement const & a) const { return a == *this; }
bool IR::AddSatAssign::operator==(IR::BaseAssignmentStatement const & a) const { return a == *this; }
bool IR::AddSatAssign::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::AddSatAssign::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::AddSatAssign::operator==(IR::Node const & a) const { return a == *this; }
bool IR::SubSat::operator==(IR::SubSat const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::SubSat::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::SubSat::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::SubSat::SubSat(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::SubSat::fromJSON(JSONLoader & json) { return new SubSat(json); }
bool IR::SubSat::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::SubSat::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::SubSat::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::SubSat::operator==(IR::Node const & a) const { return a == *this; }
bool IR::SubSatAssign::operator==(IR::SubSatAssign const & a) const {
        return OpAssignmentStatement::operator==(static_cast<const OpAssignmentStatement &>(a));
    }
bool IR::SubSatAssign::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!OpAssignmentStatement::equiv(a_)) return false;
        return true;
    }
void IR::SubSatAssign::toJSON(JSONGenerator & json) const {
    OpAssignmentStatement::toJSON(json);
}
IR::SubSatAssign::SubSatAssign(JSONLoader & json) : OpAssignmentStatement(json) {
}
IR::Node * IR::SubSatAssign::fromJSON(JSONLoader & json) { return new SubSatAssign(json); }
bool IR::SubSatAssign::operator==(IR::OpAssignmentStatement const & a) const { return a == *this; }
bool IR::SubSatAssign::operator==(IR::BaseAssignmentStatement const & a) const { return a == *this; }
bool IR::SubSatAssign::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::SubSatAssign::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::SubSatAssign::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Shl::operator==(IR::Shl const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Shl::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Shl::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Shl::Shl(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Shl::fromJSON(JSONLoader & json) { return new Shl(json); }
bool IR::Shl::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Shl::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Shl::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Shl::operator==(IR::Node const & a) const { return a == *this; }
bool IR::ShlAssign::operator==(IR::ShlAssign const & a) const {
        return OpAssignmentStatement::operator==(static_cast<const OpAssignmentStatement &>(a));
    }
bool IR::ShlAssign::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!OpAssignmentStatement::equiv(a_)) return false;
        return true;
    }
void IR::ShlAssign::toJSON(JSONGenerator & json) const {
    OpAssignmentStatement::toJSON(json);
}
IR::ShlAssign::ShlAssign(JSONLoader & json) : OpAssignmentStatement(json) {
}
IR::Node * IR::ShlAssign::fromJSON(JSONLoader & json) { return new ShlAssign(json); }
bool IR::ShlAssign::operator==(IR::OpAssignmentStatement const & a) const { return a == *this; }
bool IR::ShlAssign::operator==(IR::BaseAssignmentStatement const & a) const { return a == *this; }
bool IR::ShlAssign::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::ShlAssign::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::ShlAssign::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Shr::operator==(IR::Shr const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Shr::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Shr::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Shr::Shr(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Shr::fromJSON(JSONLoader & json) { return new Shr(json); }
bool IR::Shr::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Shr::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Shr::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Shr::operator==(IR::Node const & a) const { return a == *this; }
bool IR::ShrAssign::operator==(IR::ShrAssign const & a) const {
        return OpAssignmentStatement::operator==(static_cast<const OpAssignmentStatement &>(a));
    }
bool IR::ShrAssign::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!OpAssignmentStatement::equiv(a_)) return false;
        return true;
    }
void IR::ShrAssign::toJSON(JSONGenerator & json) const {
    OpAssignmentStatement::toJSON(json);
}
IR::ShrAssign::ShrAssign(JSONLoader & json) : OpAssignmentStatement(json) {
}
IR::Node * IR::ShrAssign::fromJSON(JSONLoader & json) { return new ShrAssign(json); }
bool IR::ShrAssign::operator==(IR::OpAssignmentStatement const & a) const { return a == *this; }
bool IR::ShrAssign::operator==(IR::BaseAssignmentStatement const & a) const { return a == *this; }
bool IR::ShrAssign::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::ShrAssign::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::ShrAssign::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Equ::operator==(IR::Equ const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Equ::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Equ::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Equ::Equ(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Equ::fromJSON(JSONLoader & json) { return new Equ(json); }
bool IR::Equ::operator==(IR::Operation_Relation const & a) const { return a == *this; }
bool IR::Equ::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Equ::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Equ::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Equ::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Neq::operator==(IR::Neq const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Neq::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Neq::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Neq::Neq(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Neq::fromJSON(JSONLoader & json) { return new Neq(json); }
bool IR::Neq::operator==(IR::Operation_Relation const & a) const { return a == *this; }
bool IR::Neq::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Neq::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Neq::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Neq::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Lss::operator==(IR::Lss const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Lss::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Lss::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Lss::Lss(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Lss::fromJSON(JSONLoader & json) { return new Lss(json); }
bool IR::Lss::operator==(IR::Operation_Relation const & a) const { return a == *this; }
bool IR::Lss::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Lss::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Lss::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Lss::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Leq::operator==(IR::Leq const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Leq::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Leq::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Leq::Leq(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Leq::fromJSON(JSONLoader & json) { return new Leq(json); }
bool IR::Leq::operator==(IR::Operation_Relation const & a) const { return a == *this; }
bool IR::Leq::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Leq::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Leq::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Leq::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Grt::operator==(IR::Grt const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Grt::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Grt::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Grt::Grt(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Grt::fromJSON(JSONLoader & json) { return new Grt(json); }
bool IR::Grt::operator==(IR::Operation_Relation const & a) const { return a == *this; }
bool IR::Grt::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Grt::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Grt::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Grt::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Geq::operator==(IR::Geq const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Geq::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Geq::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Geq::Geq(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Geq::fromJSON(JSONLoader & json) { return new Geq(json); }
bool IR::Geq::operator==(IR::Operation_Relation const & a) const { return a == *this; }
bool IR::Geq::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Geq::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Geq::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Geq::operator==(IR::Node const & a) const { return a == *this; }
bool IR::BAnd::operator==(IR::BAnd const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::BAnd::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::BAnd::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::BAnd::BAnd(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::BAnd::fromJSON(JSONLoader & json) { return new BAnd(json); }
bool IR::BAnd::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::BAnd::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::BAnd::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::BAnd::operator==(IR::Node const & a) const { return a == *this; }
bool IR::BAndAssign::operator==(IR::BAndAssign const & a) const {
        return OpAssignmentStatement::operator==(static_cast<const OpAssignmentStatement &>(a));
    }
bool IR::BAndAssign::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!OpAssignmentStatement::equiv(a_)) return false;
        return true;
    }
void IR::BAndAssign::toJSON(JSONGenerator & json) const {
    OpAssignmentStatement::toJSON(json);
}
IR::BAndAssign::BAndAssign(JSONLoader & json) : OpAssignmentStatement(json) {
}
IR::Node * IR::BAndAssign::fromJSON(JSONLoader & json) { return new BAndAssign(json); }
bool IR::BAndAssign::operator==(IR::OpAssignmentStatement const & a) const { return a == *this; }
bool IR::BAndAssign::operator==(IR::BaseAssignmentStatement const & a) const { return a == *this; }
bool IR::BAndAssign::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::BAndAssign::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::BAndAssign::operator==(IR::Node const & a) const { return a == *this; }
bool IR::BOr::operator==(IR::BOr const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::BOr::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::BOr::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::BOr::BOr(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::BOr::fromJSON(JSONLoader & json) { return new BOr(json); }
bool IR::BOr::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::BOr::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::BOr::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::BOr::operator==(IR::Node const & a) const { return a == *this; }
bool IR::BOrAssign::operator==(IR::BOrAssign const & a) const {
        return OpAssignmentStatement::operator==(static_cast<const OpAssignmentStatement &>(a));
    }
bool IR::BOrAssign::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!OpAssignmentStatement::equiv(a_)) return false;
        return true;
    }
void IR::BOrAssign::toJSON(JSONGenerator & json) const {
    OpAssignmentStatement::toJSON(json);
}
IR::BOrAssign::BOrAssign(JSONLoader & json) : OpAssignmentStatement(json) {
}
IR::Node * IR::BOrAssign::fromJSON(JSONLoader & json) { return new BOrAssign(json); }
bool IR::BOrAssign::operator==(IR::OpAssignmentStatement const & a) const { return a == *this; }
bool IR::BOrAssign::operator==(IR::BaseAssignmentStatement const & a) const { return a == *this; }
bool IR::BOrAssign::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::BOrAssign::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::BOrAssign::operator==(IR::Node const & a) const { return a == *this; }
bool IR::BXor::operator==(IR::BXor const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::BXor::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::BXor::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::BXor::BXor(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::BXor::fromJSON(JSONLoader & json) { return new BXor(json); }
bool IR::BXor::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::BXor::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::BXor::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::BXor::operator==(IR::Node const & a) const { return a == *this; }
bool IR::BXorAssign::operator==(IR::BXorAssign const & a) const {
        return OpAssignmentStatement::operator==(static_cast<const OpAssignmentStatement &>(a));
    }
bool IR::BXorAssign::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!OpAssignmentStatement::equiv(a_)) return false;
        return true;
    }
void IR::BXorAssign::toJSON(JSONGenerator & json) const {
    OpAssignmentStatement::toJSON(json);
}
IR::BXorAssign::BXorAssign(JSONLoader & json) : OpAssignmentStatement(json) {
}
IR::Node * IR::BXorAssign::fromJSON(JSONLoader & json) { return new BXorAssign(json); }
bool IR::BXorAssign::operator==(IR::OpAssignmentStatement const & a) const { return a == *this; }
bool IR::BXorAssign::operator==(IR::BaseAssignmentStatement const & a) const { return a == *this; }
bool IR::BXorAssign::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::BXorAssign::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::BXorAssign::operator==(IR::Node const & a) const { return a == *this; }
bool IR::LAnd::operator==(IR::LAnd const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::LAnd::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::LAnd::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::LAnd::LAnd(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::LAnd::fromJSON(JSONLoader & json) { return new LAnd(json); }
bool IR::LAnd::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::LAnd::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::LAnd::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::LAnd::operator==(IR::Node const & a) const { return a == *this; }
bool IR::LOr::operator==(IR::LOr const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::LOr::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::LOr::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::LOr::LOr(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::LOr::fromJSON(JSONLoader & json) { return new LOr(json); }
bool IR::LOr::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::LOr::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::LOr::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::LOr::operator==(IR::Node const & a) const { return a == *this; }
#line 253 "/root/p4c/ir/expression.def"
void IR::Dots::dbprint(std::ostream & out) const { out << "..."; }
#line 4077 "/root/p4c/build/ir/ir-generated.cpp"
#line 254 "/root/p4c/ir/expression.def"
cstring IR::Dots::toString() const { return "..."_cs; }
#line 4080 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Dots::operator==(IR::Dots const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::Dots::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::Dots::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::Dots::Dots(JSONLoader & json) : Expression(json) {
}
IR::Node * IR::Dots::fromJSON(JSONLoader & json) { return new Dots(json); }
bool IR::Dots::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Dots::operator==(IR::Node const & a) const { return a == *this; }
#line 263 "/root/p4c/ir/expression.def"
void IR::NamedDots::dbprint(std::ostream & out) const { out << "..."; }
#line 4099 "/root/p4c/build/ir/ir-generated.cpp"
#line 264 "/root/p4c/ir/expression.def"
cstring IR::NamedDots::toString() const { return "..."_cs; }
#line 4102 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::NamedDots::operator==(IR::NamedDots const & a) const {
        return NamedExpression::operator==(static_cast<const NamedExpression &>(a));
    }
bool IR::NamedDots::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!NamedExpression::equiv(a_)) return false;
        return true;
    }
void IR::NamedDots::toJSON(JSONGenerator & json) const {
    NamedExpression::toJSON(json);
}
IR::NamedDots::NamedDots(JSONLoader & json) : NamedExpression(json) {
}
IR::Node * IR::NamedDots::fromJSON(JSONLoader & json) { return new NamedDots(json); }
bool IR::NamedDots::operator==(IR::NamedExpression const & a) const { return a == *this; }
bool IR::NamedDots::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::NamedDots::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::NamedDots::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Literal::operator==(IR::Literal const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::Literal::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::Literal::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::Literal::Literal(JSONLoader & json) : Expression(json) {
}
bool IR::Literal::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Literal::operator==(IR::Node const & a) const { return a == *this; }
/// base used when reading/writing
/// if noWarning is true, no warning is emitted



/// @return a constant. Any constant returned here is interned. Base is always 10.



#line 354 "/root/p4c/ir/expression.def"
cstring IR::Constant::toString() const {
        unsigned width;
        bool sign;
        if (const IR::Type_Bits* tb = type->to<IR::Type_Bits>()) {
            width = tb->size;
            sign = tb->isSigned;
        } else {
            width = 0;
            sign = false;
        }
        return Util::toString(value, width, sign, base);
    }
#line 4158 "/root/p4c/build/ir/ir-generated.cpp"
#line 366 "/root/p4c/ir/expression.def"
void IR::Constant::visit_children(Visitor & v, char const * n) { (void)n; v.visit(type, "type"); }
#line 366 "/root/p4c/ir/expression.def"
void IR::Constant::visit_children(Visitor & v, char const * n) const { (void)n; v.visit(type, "type"); }
#line 4163 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Constant::operator==(IR::Constant const & a) const {
        return Literal::operator==(static_cast<const Literal &>(a))
        && value == a.value
        && base == a.base;
    }
bool IR::Constant::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Literal::equiv(a_)) return false;
        auto &a = static_cast<const Constant &>(a_);
        return value == a.value
        && base == a.base;
    }
void IR::Constant::dump_fields(std::ostream & out) const {
    Literal::dump_fields(out);
        out << " value=" << value;
        out << " base=" << base;
}
void IR::Constant::toJSON(JSONGenerator & json) const {
    Literal::toJSON(json);
    json.emit("value", value);
    json.emit("base", base);
}
IR::Constant::Constant(JSONLoader & json) : Literal(json) {
    json.load("value", value);
    json.load("base", base);
}
IR::Node * IR::Constant::fromJSON(JSONLoader & json) { return new Constant(json); }
bool IR::Constant::operator==(IR::Literal const & a) const { return a == *this; }
bool IR::Constant::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Constant::operator==(IR::Node const & a) const { return a == *this; }
#line 371 "/root/p4c/ir/expression.def"
cstring IR::BoolLiteral::toString() const { return value ? "true"_cs : "false"_cs; }
#line 4196 "/root/p4c/build/ir/ir-generated.cpp"
/// @return a bool literal. Both booleans are interned.
bool IR::BoolLiteral::operator==(IR::BoolLiteral const & a) const {
        return Literal::operator==(static_cast<const Literal &>(a))
        && value == a.value;
    }
bool IR::BoolLiteral::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Literal::equiv(a_)) return false;
        auto &a = static_cast<const BoolLiteral &>(a_);
        return value == a.value;
    }
void IR::BoolLiteral::dump_fields(std::ostream & out) const {
    Literal::dump_fields(out);
        out << " value=" << value;
}
void IR::BoolLiteral::toJSON(JSONGenerator & json) const {
    Literal::toJSON(json);
    json.emit("value", value);
}
IR::BoolLiteral::BoolLiteral(JSONLoader & json) : Literal(json) {
    json.load("value", value);
}
IR::Node * IR::BoolLiteral::fromJSON(JSONLoader & json) { return new BoolLiteral(json); }
bool IR::BoolLiteral::operator==(IR::Literal const & a) const { return a == *this; }
bool IR::BoolLiteral::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::BoolLiteral::operator==(IR::Node const & a) const { return a == *this; }
#line 379 "/root/p4c/ir/expression.def"
void IR::StringLiteral::validate() const {
#line 4225 "/root/p4c/build/ir/ir-generated.cpp"

#line 379 "/root/p4c/ir/expression.def"
{ if (value.isNull()) BUG("null StringLiteral"); } }
#line 4229 "/root/p4c/build/ir/ir-generated.cpp"
#line 380 "/root/p4c/ir/expression.def"
cstring IR::StringLiteral::toString() const { return absl::StrCat("\"", value.escapeJson(), "\""); }
#line 4232 "/root/p4c/build/ir/ir-generated.cpp"
/// @returns a string literal. The value is cached.
bool IR::StringLiteral::operator==(IR::StringLiteral const & a) const {
        return Literal::operator==(static_cast<const Literal &>(a))
        && value == a.value;
    }
bool IR::StringLiteral::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Literal::equiv(a_)) return false;
        auto &a = static_cast<const StringLiteral &>(a_);
        return value == a.value;
    }
void IR::StringLiteral::dump_fields(std::ostream & out) const {
    Literal::dump_fields(out);
        out << " value=" << value;
}
void IR::StringLiteral::toJSON(JSONGenerator & json) const {
    Literal::toJSON(json);
    json.emit("value", value);
}
IR::StringLiteral::StringLiteral(JSONLoader & json) : Literal(json) {
    json.load("value", value);
}
IR::Node * IR::StringLiteral::fromJSON(JSONLoader & json) { return new StringLiteral(json); }
bool IR::StringLiteral::operator==(IR::Literal const & a) const { return a == *this; }
bool IR::StringLiteral::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::StringLiteral::operator==(IR::Node const & a) const { return a == *this; }
#line 395 "/root/p4c/ir/expression.def"
cstring IR::PathExpression::toString() const { return path->toString(); }
#line 4261 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::PathExpression::operator==(IR::PathExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && path == a.path;
    }
bool IR::PathExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const PathExpression &>(a_);
        return (path ? a.path ? path->equiv(*a.path) : false : a.path == nullptr);
    }
void IR::PathExpression::visit_children(Visitor & v, char const * n) {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(path, "path");
}
void IR::PathExpression::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(path, "path");
}
void IR::PathExpression::validate() const {
#line 4283 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(path); }
void IR::PathExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("path", path);
}
IR::PathExpression::PathExpression(JSONLoader & json) : Expression(json) {
    json.load("path", path);
}
IR::Node * IR::PathExpression::fromJSON(JSONLoader & json) { return new PathExpression(json); }
bool IR::PathExpression::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::PathExpression::operator==(IR::Node const & a) const { return a == *this; }
#line 406 "/root/p4c/ir/expression.def"
void IR::TypeNameExpression::dbprint(std::ostream & out) const { out << typeName; }
#line 4298 "/root/p4c/build/ir/ir-generated.cpp"
#line 407 "/root/p4c/ir/expression.def"
cstring IR::TypeNameExpression::toString() const { return typeName->toString(); }
#line 4301 "/root/p4c/build/ir/ir-generated.cpp"
#line 408 "/root/p4c/ir/expression.def"
void IR::TypeNameExpression::validate() const {
#line 4304 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(typeName);
#line 408 "/root/p4c/ir/expression.def"
{ BUG_CHECK(typeName->is<Type_Name>() || typeName->is<Type_Specialized>(),
                         "%1% unexpected type in TypeNameExpression", typeName); } }
#line 4310 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::TypeNameExpression::operator==(IR::TypeNameExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && typeName == a.typeName;
    }
bool IR::TypeNameExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const TypeNameExpression &>(a_);
        return (typeName ? a.typeName ? typeName->equiv(*a.typeName) : false : a.typeName == nullptr);
    }
void IR::TypeNameExpression::visit_children(Visitor & v, char const * n) {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(typeName, "typeName");
}
void IR::TypeNameExpression::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(typeName, "typeName");
}
void IR::TypeNameExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("typeName", typeName);
}
IR::TypeNameExpression::TypeNameExpression(JSONLoader & json) : Expression(json) {
    json.load("typeName", typeName);
}
IR::Node * IR::TypeNameExpression::fromJSON(JSONLoader & json) { return new TypeNameExpression(json); }
bool IR::TypeNameExpression::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::TypeNameExpression::operator==(IR::Node const & a) const { return a == *this; }
bool IR::AbstractSlice::operator==(IR::AbstractSlice const & a) const {
        return Operation_Ternary::operator==(static_cast<const Operation_Ternary &>(a));
    }
bool IR::AbstractSlice::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Ternary::equiv(a_)) return false;
        return true;
    }
void IR::AbstractSlice::toJSON(JSONGenerator & json) const {
    Operation_Ternary::toJSON(json);
}
IR::AbstractSlice::AbstractSlice(JSONLoader & json) : Operation_Ternary(json) {
}
bool IR::AbstractSlice::operator==(IR::Operation_Ternary const & a) const { return a == *this; }
bool IR::AbstractSlice::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::AbstractSlice::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::AbstractSlice::operator==(IR::Node const & a) const { return a == *this; }
#line 420 "/root/p4c/ir/expression.def"
cstring IR::Slice::toString() const { return absl::StrCat(e0, "[", e1, ":", e2, "]"); }
#line 4360 "/root/p4c/build/ir/ir-generated.cpp"

#line 422 "/root/p4c/ir/expression.def"
unsigned IR::Slice::getH() const { return e1->checkedTo<IR::Constant>()->asUnsigned(); }
#line 4364 "/root/p4c/build/ir/ir-generated.cpp"
#line 423 "/root/p4c/ir/expression.def"
unsigned IR::Slice::getL() const { return e2->checkedTo<IR::Constant>()->asUnsigned(); }
#line 4367 "/root/p4c/build/ir/ir-generated.cpp"

bool IR::Slice::operator==(IR::Slice const & a) const {
        return AbstractSlice::operator==(static_cast<const AbstractSlice &>(a));
    }
bool IR::Slice::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!AbstractSlice::equiv(a_)) return false;
        return true;
    }
void IR::Slice::toJSON(JSONGenerator & json) const {
    AbstractSlice::toJSON(json);
}
IR::Slice::Slice(JSONLoader & json) : AbstractSlice(json) {
}
IR::Node * IR::Slice::fromJSON(JSONLoader & json) { return new Slice(json); }
bool IR::Slice::operator==(IR::AbstractSlice const & a) const { return a == *this; }
bool IR::Slice::operator==(IR::Operation_Ternary const & a) const { return a == *this; }
bool IR::Slice::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Slice::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Slice::operator==(IR::Node const & a) const { return a == *this; }
#line 438 "/root/p4c/ir/expression.def"
cstring IR::PlusSlice::toString() const { return absl::StrCat(e0, "[", e1, "+:", e2, "]"); }
#line 4390 "/root/p4c/build/ir/ir-generated.cpp"
#line 439 "/root/p4c/ir/expression.def"
unsigned IR::PlusSlice::getH() const {
        BUG_CHECK(e1->is<IR::Constant>(), "non-const PlusSlice not handled");
        return e1->to<IR::Constant>()->asUnsigned() + e2->checkedTo<IR::Constant>()->asUnsigned() - 1; }
#line 4395 "/root/p4c/build/ir/ir-generated.cpp"
#line 442 "/root/p4c/ir/expression.def"
unsigned IR::PlusSlice::getL() const {
        BUG_CHECK(e1->is<IR::Constant>(), "non-const PlusSlice not handled");
        return e1->to<IR::Constant>()->asUnsigned(); }
#line 4400 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::PlusSlice::operator==(IR::PlusSlice const & a) const {
        return AbstractSlice::operator==(static_cast<const AbstractSlice &>(a));
    }
bool IR::PlusSlice::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!AbstractSlice::equiv(a_)) return false;
        return true;
    }
void IR::PlusSlice::toJSON(JSONGenerator & json) const {
    AbstractSlice::toJSON(json);
}
IR::PlusSlice::PlusSlice(JSONLoader & json) : AbstractSlice(json) {
}
IR::Node * IR::PlusSlice::fromJSON(JSONLoader & json) { return new PlusSlice(json); }
bool IR::PlusSlice::operator==(IR::AbstractSlice const & a) const { return a == *this; }
bool IR::PlusSlice::operator==(IR::Operation_Ternary const & a) const { return a == *this; }
bool IR::PlusSlice::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::PlusSlice::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::PlusSlice::operator==(IR::Node const & a) const { return a == *this; }
#line 459 "/root/p4c/ir/expression.def"
cstring IR::Member::toString() const { return absl::StrCat(expr, ".", member); }
#line 4422 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Member::operator==(IR::Member const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a))
        && member == a.member;
    }
bool IR::Member::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        auto &a = static_cast<const Member &>(a_);
        return member == a.member;
    }
void IR::Member::dump_fields(std::ostream & out) const {
    Operation_Unary::dump_fields(out);
        out << " member=" << member;
}
void IR::Member::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
    json.emit("member", member);
}
IR::Member::Member(JSONLoader & json) : Operation_Unary(json) {
    json.load("member", member);
}
IR::Node * IR::Member::fromJSON(JSONLoader & json) { return new Member(json); }
bool IR::Member::operator==(IR::Operation_Unary const & a) const { return a == *this; }
bool IR::Member::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Member::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Member::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Concat::operator==(IR::Concat const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Concat::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Concat::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Concat::Concat(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Concat::fromJSON(JSONLoader & json) { return new Concat(json); }
bool IR::Concat::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Concat::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Concat::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Concat::operator==(IR::Node const & a) const { return a == *this; }
#line 479 "/root/p4c/ir/expression.def"
cstring IR::ArrayIndex::toString() const { return absl::StrCat(left, "[", right, "]"); }
#line 4469 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ArrayIndex::operator==(IR::ArrayIndex const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::ArrayIndex::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::ArrayIndex::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::ArrayIndex::ArrayIndex(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::ArrayIndex::fromJSON(JSONLoader & json) { return new ArrayIndex(json); }
bool IR::ArrayIndex::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::ArrayIndex::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::ArrayIndex::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::ArrayIndex::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Range::operator==(IR::Range const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Range::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Range::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Range::Range(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Range::fromJSON(JSONLoader & json) { return new Range(json); }
bool IR::Range::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Range::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Range::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Range::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Mask::operator==(IR::Mask const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Mask::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Mask::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Mask::Mask(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Mask::fromJSON(JSONLoader & json) { return new Mask(json); }
bool IR::Mask::operator==(IR::Operation_Binary const & a) const { return a == *this; }
bool IR::Mask::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Mask::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Mask::operator==(IR::Node const & a) const { return a == *this; }
#line 499 "/root/p4c/ir/expression.def"
void IR::Mux::visit_children(Visitor & v, char const * n) {
        (void)n;
        v.visit(e0, "e0");
        SplitFlowVisit<Expression>(v, e1, e2).run_visit(); }
#line 499 "/root/p4c/ir/expression.def"
void IR::Mux::visit_children(Visitor & v, char const * n) const {
        (void)n;
        v.visit(e0, "e0");
        SplitFlowVisit<Expression>(v, e1, e2).run_visit(); }
#line 4534 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Mux::operator==(IR::Mux const & a) const {
        return Operation_Ternary::operator==(static_cast<const Operation_Ternary &>(a));
    }
bool IR::Mux::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Ternary::equiv(a_)) return false;
        return true;
    }
void IR::Mux::toJSON(JSONGenerator & json) const {
    Operation_Ternary::toJSON(json);
}
IR::Mux::Mux(JSONLoader & json) : Operation_Ternary(json) {
}
IR::Node * IR::Mux::fromJSON(JSONLoader & json) { return new Mux(json); }
bool IR::Mux::operator==(IR::Operation_Ternary const & a) const { return a == *this; }
bool IR::Mux::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Mux::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Mux::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DefaultExpression::operator==(IR::DefaultExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::DefaultExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::DefaultExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::DefaultExpression::DefaultExpression(JSONLoader & json) : Expression(json) {
}
IR::Node * IR::DefaultExpression::fromJSON(JSONLoader & json) { return new DefaultExpression(json); }
bool IR::DefaultExpression::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::DefaultExpression::operator==(IR::Node const & a) const { return a == *this; }
#line 512 "/root/p4c/ir/expression.def"
cstring IR::This::toString() const { return "this"_cs; }
#line 4571 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::This::operator==(IR::This const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && id == a.id;
    }
bool IR::This::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const This &>(a_);
        return id == a.id;
    }
void IR::This::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " id=" << id;
}
void IR::This::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("id", id);
}
IR::This::This(JSONLoader & json) : Expression(json) {
    json.load("id", id);
}
IR::Node * IR::This::fromJSON(JSONLoader & json) { return new This(json); }
bool IR::This::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::This::operator==(IR::Node const & a) const { return a == *this; }
/// These will generally always be the same, except when a cast to a type argument of
/// a generic occurs.  Then at some point, the 'destType' will be specialized to a concrete
/// type, and 'type' will only be updated later when type inferencing occurs
#line 524 "/root/p4c/ir/expression.def"
cstring IR::Cast::toString() const { return absl::StrCat("(", destType, ")", expr); }
#line 4601 "/root/p4c/build/ir/ir-generated.cpp"
#line 525 "/root/p4c/ir/expression.def"
void IR::Cast::validate() const {
#line 4604 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(destType);
#line 525 "/root/p4c/ir/expression.def"
{ BUG_CHECK(!destType->is<Type_Unknown>(), "%1%: Cannot cast to unknown type", this); } }
#line 4609 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Cast::operator==(IR::Cast const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a))
        && destType == a.destType;
    }
bool IR::Cast::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        auto &a = static_cast<const Cast &>(a_);
        return (destType ? a.destType ? destType->equiv(*a.destType) : false : a.destType == nullptr);
    }
void IR::Cast::visit_children(Visitor & v, char const * n) {
    (void)n;
    Operation_Unary::visit_children(v, n);
    v.visit(destType, "destType");
}
void IR::Cast::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Operation_Unary::visit_children(v, n);
    v.visit(destType, "destType");
}
void IR::Cast::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
    json.emit("destType", destType);
}
IR::Cast::Cast(JSONLoader & json) : Operation_Unary(json) {
    json.load("destType", destType);
}
IR::Node * IR::Cast::fromJSON(JSONLoader & json) { return new Cast(json); }
bool IR::Cast::operator==(IR::Operation_Unary const & a) const { return a == *this; }
bool IR::Cast::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Cast::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Cast::operator==(IR::Node const & a) const { return a == *this; }
#line 531 "/root/p4c/ir/expression.def"
void IR::SelectCase::dbprint(std::ostream & out) const { out << keyset << ": " << state; }
#line 4644 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::SelectCase::operator==(IR::SelectCase const & a) const {
        return this->typeId() == a.typeId()
        && keyset == a.keyset
        && state == a.state;
    }
bool IR::SelectCase::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const SelectCase &>(a_);
        return (keyset ? a.keyset ? keyset->equiv(*a.keyset) : false : a.keyset == nullptr)
        && (state ? a.state ? state->equiv(*a.state) : false : a.state == nullptr);
    }
void IR::SelectCase::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(keyset, "keyset");
    v.visit(state, "state");
}
void IR::SelectCase::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(keyset, "keyset");
    v.visit(state, "state");
}
void IR::SelectCase::validate() const {
#line 4670 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(keyset);
        CHECK_NULL(state); }
void IR::SelectCase::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("keyset", keyset);
    json.emit("state", state);
}
IR::SelectCase::SelectCase(JSONLoader & json) : Node(json) {
    json.load("keyset", keyset);
    json.load("state", state);
}
IR::Node * IR::SelectCase::fromJSON(JSONLoader & json) { return new SelectCase(json); }
bool IR::SelectCase::operator==(IR::Node const & a) const { return a == *this; }
#line 537 "/root/p4c/ir/expression.def"
void IR::SelectExpression::visit_children(Visitor & v, char const * n) {
        (void)n;
        v.visit(select, "select");
        SplitFlowVisitVector<SelectCase>(v, selectCases).run_visit(); }
#line 537 "/root/p4c/ir/expression.def"
void IR::SelectExpression::visit_children(Visitor & v, char const * n) const {
        (void)n;
        v.visit(select, "select");
        SplitFlowVisitVector<SelectCase>(v, selectCases).run_visit(); }
#line 4695 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::SelectExpression::operator==(IR::SelectExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && select == a.select
        && selectCases == a.selectCases;
    }
bool IR::SelectExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const SelectExpression &>(a_);
        return (select ? a.select ? select->equiv(*a.select) : false : a.select == nullptr)
        && selectCases.equiv(a.selectCases);
    }
void IR::SelectExpression::validate() const {
#line 4709 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(select);
        selectCases.validate(); }
void IR::SelectExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("select", select);
    json.emit("selectCases", selectCases);
}
IR::SelectExpression::SelectExpression(JSONLoader & json) : Expression(json) {
    json.load("select", select);
    json.load("selectCases", selectCases);
}
IR::Node * IR::SelectExpression::fromJSON(JSONLoader & json) { return new SelectExpression(json); }
bool IR::SelectExpression::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::SelectExpression::operator==(IR::Node const & a) const { return a == *this; }
#line 547 "/root/p4c/ir/expression.def"
cstring IR::MethodCallExpression::toString() const {
        return
            absl::StrCat(method, "(",
                         absl::StrJoin(*arguments, ", ",
                                       [](std::string *out, const Argument *arg) {
                                           absl::StrAppend(out, arg);
                                       }),
                         ")");
    }
#line 4735 "/root/p4c/build/ir/ir-generated.cpp"
#line 556 "/root/p4c/ir/expression.def"
void IR::MethodCallExpression::validate() const {
#line 4738 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(method);
        CHECK_NULL(typeArguments);
        CHECK_NULL(arguments);
#line 556 "/root/p4c/ir/expression.def"
{ typeArguments->check_null(); arguments->check_null(); } }
#line 4745 "/root/p4c/build/ir/ir-generated.cpp"
#line 562 "/root/p4c/ir/expression.def"
IR::MethodCallExpression::MethodCallExpression(const IR::Expression* m, std::initializer_list<IR::Expression const *> const & a) : method(m), arguments(nullptr)  {
        auto arguments = new Vector<Argument>;
        for (auto arg : a) arguments->push_back(new Argument(arg));
        this->arguments = arguments; }
#line 4751 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::MethodCallExpression::operator==(IR::MethodCallExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && method == a.method
        && typeArguments == a.typeArguments
        && arguments == a.arguments;
    }
bool IR::MethodCallExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const MethodCallExpression &>(a_);
        return (method ? a.method ? method->equiv(*a.method) : false : a.method == nullptr)
        && (typeArguments ? a.typeArguments ? typeArguments->equiv(*a.typeArguments) : false : a.typeArguments == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr);
    }
void IR::MethodCallExpression::visit_children(Visitor & v, char const * n) {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(method, "method");
    v.visit(typeArguments, "typeArguments");
    v.visit(arguments, "arguments");
}
void IR::MethodCallExpression::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(method, "method");
    v.visit(typeArguments, "typeArguments");
    v.visit(arguments, "arguments");
}
void IR::MethodCallExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("method", method);
    json.emit("typeArguments", typeArguments);
    json.emit("arguments", arguments);
}
IR::MethodCallExpression::MethodCallExpression(JSONLoader & json) : Expression(json) {
    json.load("method", method);
    json.load("typeArguments", typeArguments);
    json.load("arguments", arguments);
}
IR::Node * IR::MethodCallExpression::fromJSON(JSONLoader & json) { return new MethodCallExpression(json); }
bool IR::MethodCallExpression::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::MethodCallExpression::operator==(IR::Node const & a) const { return a == *this; }

#line 572 "/root/p4c/ir/expression.def"
cstring IR::ConstructorCallExpression::toString() const { return constructedType->toString(); }
#line 4797 "/root/p4c/build/ir/ir-generated.cpp"
#line 573 "/root/p4c/ir/expression.def"
void IR::ConstructorCallExpression::validate() const {
#line 4800 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(constructedType);
        CHECK_NULL(arguments);
#line 573 "/root/p4c/ir/expression.def"
{ BUG_CHECK(constructedType->is<Type_Name>() ||
                        constructedType->is<Type_Specialized>(),
                        "%1%: unexpected type", constructedType);
        arguments->check_null(); } }
#line 4809 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ConstructorCallExpression::operator==(IR::ConstructorCallExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && constructedType == a.constructedType
        && arguments == a.arguments;
    }
bool IR::ConstructorCallExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const ConstructorCallExpression &>(a_);
        return (constructedType ? a.constructedType ? constructedType->equiv(*a.constructedType) : false : a.constructedType == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr);
    }
void IR::ConstructorCallExpression::visit_children(Visitor & v, char const * n) {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(constructedType, "constructedType");
    v.visit(arguments, "arguments");
}
void IR::ConstructorCallExpression::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(constructedType, "constructedType");
    v.visit(arguments, "arguments");
}
void IR::ConstructorCallExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("constructedType", constructedType);
    json.emit("arguments", arguments);
}
IR::ConstructorCallExpression::ConstructorCallExpression(JSONLoader & json) : Expression(json) {
    json.load("constructedType", constructedType);
    json.load("arguments", arguments);
}
IR::Node * IR::ConstructorCallExpression::fromJSON(JSONLoader & json) { return new ConstructorCallExpression(json); }
bool IR::ConstructorCallExpression::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::ConstructorCallExpression::operator==(IR::Node const & a) const { return a == *this; }
#line 581 "/root/p4c/ir/expression.def"
void IR::BaseListExpression::validate() const {
#line 4848 "/root/p4c/build/ir/ir-generated.cpp"

        components.validate();
#line 581 "/root/p4c/ir/expression.def"
{ components.check_null(); } }
#line 4853 "/root/p4c/build/ir/ir-generated.cpp"
#line 590 "/root/p4c/ir/expression.def"
cstring IR::BaseListExpression::toString() const {
        return components.empty() ? "{}" :
            absl::StrCat("{ ",
                         absl::StrJoin(components, ", ",
                                       [](std::string *out, const Expression *comp)  {
                                           absl::StrAppend(out, comp);
                                       }),
                         " }");
    }
#line 4864 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::BaseListExpression::operator==(IR::BaseListExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && components == a.components;
    }
bool IR::BaseListExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const BaseListExpression &>(a_);
        return components.equiv(a.components);
    }
void IR::BaseListExpression::visit_children(Visitor & v, char const * n) {
    (void)n;
    Expression::visit_children(v, n);
    components.visit_children(v, "components");
}
void IR::BaseListExpression::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Expression::visit_children(v, n);
    components.visit_children(v, "components");
}
void IR::BaseListExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("components", components);
}
IR::BaseListExpression::BaseListExpression(JSONLoader & json) : Expression(json) {
    json.load("components", components);
}
IR::Node * IR::BaseListExpression::fromJSON(JSONLoader & json) { return new BaseListExpression(json); }
bool IR::BaseListExpression::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::BaseListExpression::operator==(IR::Node const & a) const { return a == *this; }
bool IR::ListExpression::operator==(IR::ListExpression const & a) const {
        return BaseListExpression::operator==(static_cast<const BaseListExpression &>(a));
    }
bool IR::ListExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!BaseListExpression::equiv(a_)) return false;
        return true;
    }
void IR::ListExpression::toJSON(JSONGenerator & json) const {
    BaseListExpression::toJSON(json);
}
IR::ListExpression::ListExpression(JSONLoader & json) : BaseListExpression(json) {
}
IR::Node * IR::ListExpression::fromJSON(JSONLoader & json) { return new ListExpression(json); }
bool IR::ListExpression::operator==(IR::BaseListExpression const & a) const { return a == *this; }
bool IR::ListExpression::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::ListExpression::operator==(IR::Node const & a) const { return a == *this; }
bool IR::P4ListExpression::operator==(IR::P4ListExpression const & a) const {
        return BaseListExpression::operator==(static_cast<const BaseListExpression &>(a))
        && elementType == a.elementType;
    }
bool IR::P4ListExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!BaseListExpression::equiv(a_)) return false;
        auto &a = static_cast<const P4ListExpression &>(a_);
        return (elementType ? a.elementType ? elementType->equiv(*a.elementType) : false : a.elementType == nullptr);
    }
void IR::P4ListExpression::visit_children(Visitor & v, char const * n) {
    (void)n;
    BaseListExpression::visit_children(v, n);
    v.visit(elementType, "elementType");
}
void IR::P4ListExpression::visit_children(Visitor & v, char const * n) const {
    (void)n;
    BaseListExpression::visit_children(v, n);
    v.visit(elementType, "elementType");
}
void IR::P4ListExpression::validate() const {
#line 4933 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(elementType); }
void IR::P4ListExpression::toJSON(JSONGenerator & json) const {
    BaseListExpression::toJSON(json);
    json.emit("elementType", elementType);
}
IR::P4ListExpression::P4ListExpression(JSONLoader & json) : BaseListExpression(json) {
    json.load("elementType", elementType);
}
IR::Node * IR::P4ListExpression::fromJSON(JSONLoader & json) { return new P4ListExpression(json); }
bool IR::P4ListExpression::operator==(IR::BaseListExpression const & a) const { return a == *this; }
bool IR::P4ListExpression::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::P4ListExpression::operator==(IR::Node const & a) const { return a == *this; }
/// The struct or header type that is being intialized.
/// May only be known after type checking; so it can be nullptr.
#line 629 "/root/p4c/ir/expression.def"
void IR::StructExpression::validate() const {
#line 4951 "/root/p4c/build/ir/ir-generated.cpp"

        components.validate();
#line 629 "/root/p4c/ir/expression.def"
{
        components.check_null(); components.validate();
        BUG_CHECK(structType == nullptr || structType->is<IR::Type_Name>() ||
                  structType->is<IR::Type_Specialized>(),
                  "%1%: unexpected struct type", this);
    } }
#line 4961 "/root/p4c/build/ir/ir-generated.cpp"
#line 644 "/root/p4c/ir/expression.def"
cstring IR::StructExpression::toString() const {
        return components.empty() ? "{}" :
            absl::StrCat("{ ",
                         absl::StrJoin(components, ", ",
                                       [](std::string *out, const NamedExpression *comp)  {
                                           absl::StrAppend(out, comp, " = ", comp->expression);
                                       }),
                         " }");
    }
#line 4972 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::StructExpression::operator==(IR::StructExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && structType == a.structType
        && components == a.components;
    }
bool IR::StructExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const StructExpression &>(a_);
        return (structType ? a.structType ? structType->equiv(*a.structType) : false : a.structType == nullptr)
        && components.equiv(a.components);
    }
void IR::StructExpression::visit_children(Visitor & v, char const * n) {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(structType, "structType");
    components.visit_children(v, "components");
}
void IR::StructExpression::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(structType, "structType");
    components.visit_children(v, "components");
}
void IR::StructExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    if (structType != nullptr) json.emit("structType", structType);
    json.emit("components", components);
}
IR::StructExpression::StructExpression(JSONLoader & json) : Expression(json) {
    json.load("structType", structType);
    json.load("components", components);
}
IR::Node * IR::StructExpression::fromJSON(JSONLoader & json) { return new StructExpression(json); }
bool IR::StructExpression::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::StructExpression::operator==(IR::Node const & a) const { return a == *this; }
bool IR::Invalid::operator==(IR::Invalid const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::Invalid::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::Invalid::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::Invalid::Invalid(JSONLoader & json) : Expression(json) {
}
IR::Node * IR::Invalid::fromJSON(JSONLoader & json) { return new Invalid(json); }
bool IR::Invalid::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Invalid::operator==(IR::Node const & a) const { return a == *this; }
bool IR::InvalidHeader::operator==(IR::InvalidHeader const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && headerType == a.headerType;
    }
bool IR::InvalidHeader::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const InvalidHeader &>(a_);
        return (headerType ? a.headerType ? headerType->equiv(*a.headerType) : false : a.headerType == nullptr);
    }
void IR::InvalidHeader::visit_children(Visitor & v, char const * n) {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(headerType, "headerType");
}
void IR::InvalidHeader::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(headerType, "headerType");
}
void IR::InvalidHeader::validate() const {
#line 5046 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(headerType); }
void IR::InvalidHeader::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("headerType", headerType);
}
IR::InvalidHeader::InvalidHeader(JSONLoader & json) : Expression(json) {
    json.load("headerType", headerType);
}
IR::Node * IR::InvalidHeader::fromJSON(JSONLoader & json) { return new InvalidHeader(json); }
bool IR::InvalidHeader::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::InvalidHeader::operator==(IR::Node const & a) const { return a == *this; }
bool IR::InvalidHeaderUnion::operator==(IR::InvalidHeaderUnion const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && headerUnionType == a.headerUnionType;
    }
bool IR::InvalidHeaderUnion::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const InvalidHeaderUnion &>(a_);
        return (headerUnionType ? a.headerUnionType ? headerUnionType->equiv(*a.headerUnionType) : false : a.headerUnionType == nullptr);
    }
void IR::InvalidHeaderUnion::visit_children(Visitor & v, char const * n) {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(headerUnionType, "headerUnionType");
}
void IR::InvalidHeaderUnion::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(headerUnionType, "headerUnionType");
}
void IR::InvalidHeaderUnion::validate() const {
#line 5080 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(headerUnionType); }
void IR::InvalidHeaderUnion::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("headerUnionType", headerUnionType);
}
IR::InvalidHeaderUnion::InvalidHeaderUnion(JSONLoader & json) : Expression(json) {
    json.load("headerUnionType", headerUnionType);
}
IR::Node * IR::InvalidHeaderUnion::fromJSON(JSONLoader & json) { return new InvalidHeaderUnion(json); }
bool IR::InvalidHeaderUnion::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::InvalidHeaderUnion::operator==(IR::Node const & a) const { return a == *this; }
/// May only be known after type checking; so it can be nullptr.
#line 673 "/root/p4c/ir/expression.def"
void IR::HeaderStackExpression::validate() const {
#line 5096 "/root/p4c/build/ir/ir-generated.cpp"

#line 673 "/root/p4c/ir/expression.def"
{
        components.check_null();
    } }
#line 5102 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::HeaderStackExpression::operator==(IR::HeaderStackExpression const & a) const {
        return BaseListExpression::operator==(static_cast<const BaseListExpression &>(a))
        && headerStackType == a.headerStackType;
    }
bool IR::HeaderStackExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!BaseListExpression::equiv(a_)) return false;
        auto &a = static_cast<const HeaderStackExpression &>(a_);
        return (headerStackType ? a.headerStackType ? headerStackType->equiv(*a.headerStackType) : false : a.headerStackType == nullptr);
    }
void IR::HeaderStackExpression::visit_children(Visitor & v, char const * n) {
    (void)n;
    BaseListExpression::visit_children(v, n);
    v.visit(headerStackType, "headerStackType");
}
void IR::HeaderStackExpression::visit_children(Visitor & v, char const * n) const {
    (void)n;
    BaseListExpression::visit_children(v, n);
    v.visit(headerStackType, "headerStackType");
}
void IR::HeaderStackExpression::toJSON(JSONGenerator & json) const {
    BaseListExpression::toJSON(json);
    if (headerStackType != nullptr) json.emit("headerStackType", headerStackType);
}
IR::HeaderStackExpression::HeaderStackExpression(JSONLoader & json) : BaseListExpression(json) {
    json.load("headerStackType", headerStackType);
}
IR::Node * IR::HeaderStackExpression::fromJSON(JSONLoader & json) { return new HeaderStackExpression(json); }
bool IR::HeaderStackExpression::operator==(IR::BaseListExpression const & a) const { return a == *this; }
bool IR::HeaderStackExpression::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::HeaderStackExpression::operator==(IR::Node const & a) const { return a == *this; }
#line 682 "/root/p4c/ir/expression.def"
void IR::ListCompileTimeValue::validate() const {
#line 5136 "/root/p4c/build/ir/ir-generated.cpp"

        components.validate();
#line 682 "/root/p4c/ir/expression.def"
{
        for (auto v : components)
            BUG_CHECK(v->is<CompileTimeValue>(), "%1%: not a compile-time value", v); } }
#line 5143 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ListCompileTimeValue::operator==(IR::ListCompileTimeValue const & a) const {
        return this->typeId() == a.typeId()
        && components == a.components;
    }
bool IR::ListCompileTimeValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const ListCompileTimeValue &>(a_);
        return components.equiv(a.components);
    }
void IR::ListCompileTimeValue::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    components.visit_children(v, "components");
}
void IR::ListCompileTimeValue::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    components.visit_children(v, "components");
}
void IR::ListCompileTimeValue::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("components", components);
}
IR::ListCompileTimeValue::ListCompileTimeValue(JSONLoader & json) : Node(json) {
    json.load("components", components);
}
IR::Node * IR::ListCompileTimeValue::fromJSON(JSONLoader & json) { return new ListCompileTimeValue(json); }
bool IR::ListCompileTimeValue::operator==(IR::Node const & a) const { return a == *this; }
#line 692 "/root/p4c/ir/expression.def"
void IR::P4ListCompileTimeValue::validate() const {
#line 5175 "/root/p4c/build/ir/ir-generated.cpp"

        components.validate();
#line 692 "/root/p4c/ir/expression.def"
{
        for (auto v : components)
            BUG_CHECK(v->is<CompileTimeValue>(), "%1%: not a compile-time value", v); } }
#line 5182 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::P4ListCompileTimeValue::operator==(IR::P4ListCompileTimeValue const & a) const {
        return this->typeId() == a.typeId()
        && components == a.components;
    }
bool IR::P4ListCompileTimeValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const P4ListCompileTimeValue &>(a_);
        return components.equiv(a.components);
    }
void IR::P4ListCompileTimeValue::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    components.visit_children(v, "components");
}
void IR::P4ListCompileTimeValue::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    components.visit_children(v, "components");
}
void IR::P4ListCompileTimeValue::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("components", components);
}
IR::P4ListCompileTimeValue::P4ListCompileTimeValue(JSONLoader & json) : Node(json) {
    json.load("components", components);
}
IR::Node * IR::P4ListCompileTimeValue::fromJSON(JSONLoader & json) { return new P4ListCompileTimeValue(json); }
bool IR::P4ListCompileTimeValue::operator==(IR::Node const & a) const { return a == *this; }
#line 702 "/root/p4c/ir/expression.def"
void IR::StructCompileTimeValue::validate() const {
#line 5214 "/root/p4c/build/ir/ir-generated.cpp"

        components.validate();
#line 702 "/root/p4c/ir/expression.def"
{
        for (auto v : components)
            BUG_CHECK(v->is<CompileTimeValue>(), "%1%: not a compile-time value", v); } }
#line 5221 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::StructCompileTimeValue::operator==(IR::StructCompileTimeValue const & a) const {
        return this->typeId() == a.typeId()
        && components == a.components;
    }
bool IR::StructCompileTimeValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const StructCompileTimeValue &>(a_);
        return components.equiv(a.components);
    }
void IR::StructCompileTimeValue::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    components.visit_children(v, "components");
}
void IR::StructCompileTimeValue::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    components.visit_children(v, "components");
}
void IR::StructCompileTimeValue::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("components", components);
}
IR::StructCompileTimeValue::StructCompileTimeValue(JSONLoader & json) : Node(json) {
    json.load("components", components);
}
IR::Node * IR::StructCompileTimeValue::fromJSON(JSONLoader & json) { return new StructCompileTimeValue(json); }
bool IR::StructCompileTimeValue::operator==(IR::Node const & a) const { return a == *this; }
#line 712 "/root/p4c/ir/expression.def"
void IR::CompileTimeMethodCall::validate() const {
#line 5253 "/root/p4c/build/ir/ir-generated.cpp"

#line 712 "/root/p4c/ir/expression.def"
{
        for (auto v : *arguments)
            BUG_CHECK(v->is<CompileTimeValue>(), "%1%: not a compile-time value", v); } }
#line 5259 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::CompileTimeMethodCall::operator==(IR::CompileTimeMethodCall const & a) const {
        return MethodCallExpression::operator==(static_cast<const MethodCallExpression &>(a));
    }
bool IR::CompileTimeMethodCall::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!MethodCallExpression::equiv(a_)) return false;
        return true;
    }
void IR::CompileTimeMethodCall::toJSON(JSONGenerator & json) const {
    MethodCallExpression::toJSON(json);
}
IR::CompileTimeMethodCall::CompileTimeMethodCall(JSONLoader & json) : MethodCallExpression(json) {
}
IR::Node * IR::CompileTimeMethodCall::fromJSON(JSONLoader & json) { return new CompileTimeMethodCall(json); }
bool IR::CompileTimeMethodCall::operator==(IR::MethodCallExpression const & a) const { return a == *this; }
bool IR::CompileTimeMethodCall::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::CompileTimeMethodCall::operator==(IR::Node const & a) const { return a == *this; }
/// The label of the symbolic variable.
/// A symbolic variable always has a type and no source info.
/// Implements comparisons so that SymbolicVariables can be used as map keys.
#line 734 "/root/p4c/ir/expression.def"
cstring IR::SymbolicVariable::toString() const { return absl::StrCat("|", label, "(", type, ")|"); }
#line 5282 "/root/p4c/build/ir/ir-generated.cpp"
#line 736 "/root/p4c/ir/expression.def"
void IR::SymbolicVariable::dbprint(std::ostream & out) const { out << "|" + label +"(" << type << ")|"; }
#line 5285 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::SymbolicVariable::operator==(IR::SymbolicVariable const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && label == a.label;
    }
bool IR::SymbolicVariable::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const SymbolicVariable &>(a_);
        return label == a.label;
    }
void IR::SymbolicVariable::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " label=" << label;
}
void IR::SymbolicVariable::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("label", label);
}
IR::SymbolicVariable::SymbolicVariable(JSONLoader & json) : Expression(json) {
    json.load("label", label);
}
IR::Node * IR::SymbolicVariable::fromJSON(JSONLoader & json) { return new SymbolicVariable(json); }
bool IR::SymbolicVariable::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::SymbolicVariable::operator==(IR::Node const & a) const { return a == *this; }

#line 63 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::ParserState::getAnnotations() const { return annotations; }
#line 5313 "/root/p4c/build/ir/ir-generated.cpp"
#line 64 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::ParserState::getAnnotations() { return annotations; }
#line 5316 "/root/p4c/build/ir/ir-generated.cpp"
#line 65 "/root/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::ParserState::getDeclarations() const {
        return components.getDeclarations(); }
#line 5320 "/root/p4c/build/ir/ir-generated.cpp"
#line 67 "/root/p4c/ir/ir.def"
IR::IDeclaration const * IR::ParserState::getDeclByName(cstring name) const {
        return components.getDeclaration(name); }
#line 5324 "/root/p4c/build/ir/ir-generated.cpp"
#line 69 "/root/p4c/ir/ir.def"
IR::IDeclaration const * IR::ParserState::getDeclByName(std::string_view name) const {
        return components.getDeclaration(name); }
#line 5328 "/root/p4c/build/ir/ir-generated.cpp"
#line 77 "/root/p4c/ir/ir.def"
void IR::ParserState::validate() const {
#line 5331 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        components.validate();
#line 77 "/root/p4c/ir/ir.def"
{
        if (selectExpression != nullptr)
            BUG_CHECK(selectExpression->is<IR::PathExpression>() ||
                      selectExpression->is<IR::SelectExpression>(),
                      "%1%: unexpected select expression", selectExpression);
    } }
#line 5342 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ParserState::operator==(IR::ParserState const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && components == a.components
        && selectExpression == a.selectExpression;
    }
bool IR::ParserState::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const ParserState &>(a_);
        return annotations.equiv(a.annotations)
        && components.equiv(a.components)
        && (selectExpression ? a.selectExpression ? selectExpression->equiv(*a.selectExpression) : false : a.selectExpression == nullptr);
    }
void IR::ParserState::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    components.visit_children(v, "components");
    v.visit(selectExpression, "selectExpression");
}
void IR::ParserState::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    components.visit_children(v, "components");
    v.visit(selectExpression, "selectExpression");
}
void IR::ParserState::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("components", components);
    if (selectExpression != nullptr) json.emit("selectExpression", selectExpression);
}
IR::ParserState::ParserState(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("components", components);
    json.load("selectExpression", selectExpression);
}
IR::Node * IR::ParserState::fromJSON(JSONLoader & json) { return new ParserState(json); }
bool IR::ParserState::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::ParserState::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::ParserState::operator==(IR::Node const & a) const { return a == *this; }
#line 92 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::P4Parser::getAnnotations() const { return type->getAnnotations(); }
#line 5388 "/root/p4c/build/ir/ir-generated.cpp"
#line 93 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::P4Parser::getAnnotations() { BUG("cannot modify annotations"); return *new Vector<Annotation>(); }
#line 5391 "/root/p4c/build/ir/ir-generated.cpp"
#line 94 "/root/p4c/ir/ir.def"
const IR::TypeParameters *IR::P4Parser::getTypeParameters() const { return type->getTypeParameters(); }
#line 5394 "/root/p4c/build/ir/ir-generated.cpp"
#line 95 "/root/p4c/ir/ir.def"
std::vector<const IR::INamespace *> IR::P4Parser::getNestedNamespaces() const {
        return { type->typeParameters, type->applyParams, constructorParams }; }
#line 5398 "/root/p4c/build/ir/ir-generated.cpp"
#line 97 "/root/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::P4Parser::getDeclarations() const {
        return parserLocals.getDeclarations()->concat(states.getDeclarations()); }
#line 5402 "/root/p4c/build/ir/ir-generated.cpp"
#line 99 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::P4Parser::getDeclByName(cstring name) const {
        auto decl = parserLocals.getDeclaration(name);
        if (!decl) decl = states.getDeclaration(name);
        return decl; }
#line 5408 "/root/p4c/build/ir/ir-generated.cpp"
#line 103 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::P4Parser::getDeclByName(std::string_view name) const {
        auto decl = parserLocals.getDeclaration(name);
        if (!decl) decl = states.getDeclaration(name);
        return decl; }
#line 5414 "/root/p4c/build/ir/ir-generated.cpp"
#line 108 "/root/p4c/ir/ir.def"
const IR::Type_Method *IR::P4Parser::getApplyMethodType() const { return type->getApplyMethodType(); }
#line 5417 "/root/p4c/build/ir/ir-generated.cpp"
#line 109 "/root/p4c/ir/ir.def"
const IR::ParameterList *IR::P4Parser::getApplyParameters() const { return type->getApplyParameters(); }
#line 5420 "/root/p4c/build/ir/ir-generated.cpp"
#line 111 "/root/p4c/ir/ir.def"
const IR::ParameterList *IR::P4Parser::getConstructorParameters() const { return constructorParams; }
#line 5423 "/root/p4c/build/ir/ir-generated.cpp"
#line 113 "/root/p4c/ir/ir.def"
const IR::Type *IR::P4Parser::getType() const { return this->type; }
#line 5426 "/root/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(P4Parser, , )
#line 115 "/root/p4c/ir/ir.def"
void IR::P4Parser::validate() const {
#line 5430 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(constructorParams);
        parserLocals.validate();
        states.validate();
#line 115 "/root/p4c/ir/ir.def"
{
        if (!(name == type->name))
            BUG("Name mismatch for %1%: %2% != %3%", this, name, type->name);
        parserLocals.check_null();
        states.check_null();
        checkDuplicates();
        for (auto d : parserLocals)
            BUG_CHECK(!d->is<ParserState>(), "%1%: state in locals", d);
    } }
#line 5446 "/root/p4c/build/ir/ir-generated.cpp"
#line 124 "/root/p4c/ir/ir.def"
cstring IR::P4Parser::toString() const { return "parser "_cs + externalName(); }
#line 5449 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::P4Parser::operator==(IR::P4Parser const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && type == a.type
        && constructorParams == a.constructorParams
        && parserLocals == a.parserLocals
        && states == a.states;
    }
bool IR::P4Parser::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4Parser &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (constructorParams ? a.constructorParams ? constructorParams->equiv(*a.constructorParams) : false : a.constructorParams == nullptr)
        && parserLocals.equiv(a.parserLocals)
        && states.equiv(a.states);
    }
void IR::P4Parser::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_Declaration::visit_children(v, n);
    v.visit(type, "type");
    v.visit(constructorParams, "constructorParams");
    parserLocals.visit_children(v, "parserLocals");
    states.visit_children(v, "states");
}
void IR::P4Parser::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_Declaration::visit_children(v, n);
    v.visit(type, "type");
    v.visit(constructorParams, "constructorParams");
    parserLocals.visit_children(v, "parserLocals");
    states.visit_children(v, "states");
}
void IR::P4Parser::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json.emit("type", type);
    json.emit("constructorParams", constructorParams);
    json.emit("parserLocals", parserLocals);
    json.emit("states", states);
}
IR::P4Parser::P4Parser(JSONLoader & json) : Type_Declaration(json) {
    json.load("type", type);
    json.load("constructorParams", constructorParams);
    json.load("parserLocals", parserLocals);
    json.load("states", states);
}
IR::Node * IR::P4Parser::fromJSON(JSONLoader & json) { return new P4Parser(json); }
bool IR::P4Parser::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::P4Parser::operator==(IR::Type const & a) const { return a == *this; }
bool IR::P4Parser::operator==(IR::Node const & a) const { return a == *this; }
#line 133 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::P4Control::getAnnotations() const { return type->getAnnotations(); }
#line 5501 "/root/p4c/build/ir/ir-generated.cpp"
#line 134 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::P4Control::getAnnotations() { BUG("cannot modify annotations"); return *new Vector<Annotation>(); }
#line 5504 "/root/p4c/build/ir/ir-generated.cpp"
#line 135 "/root/p4c/ir/ir.def"
const IR::TypeParameters *IR::P4Control::getTypeParameters() const { return type->getTypeParameters(); }
#line 5507 "/root/p4c/build/ir/ir-generated.cpp"
#line 136 "/root/p4c/ir/ir.def"
std::vector<const IR::INamespace *> IR::P4Control::getNestedNamespaces() const {
        return { type->typeParameters, type->applyParams, constructorParams }; }
#line 5511 "/root/p4c/build/ir/ir-generated.cpp"
#line 138 "/root/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::P4Control::getDeclarations() const {
        return controlLocals.getDeclarations(); }
#line 5515 "/root/p4c/build/ir/ir-generated.cpp"
#line 140 "/root/p4c/ir/ir.def"
const IR::Type_Method *IR::P4Control::getApplyMethodType() const { return type->getApplyMethodType(); }
#line 5518 "/root/p4c/build/ir/ir-generated.cpp"
#line 141 "/root/p4c/ir/ir.def"
const IR::ParameterList *IR::P4Control::getApplyParameters() const { return type->getApplyParameters(); }
#line 5521 "/root/p4c/build/ir/ir-generated.cpp"
#line 143 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::P4Control::getDeclByName(cstring name) const {
        return controlLocals.getDeclaration(name); }
#line 5525 "/root/p4c/build/ir/ir-generated.cpp"
#line 145 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::P4Control::getDeclByName(std::string_view name) const {
        return controlLocals.getDeclaration(name); }
#line 5529 "/root/p4c/build/ir/ir-generated.cpp"
#line 147 "/root/p4c/ir/ir.def"
const IR::ParameterList *IR::P4Control::getConstructorParameters() const { return constructorParams; }
#line 5532 "/root/p4c/build/ir/ir-generated.cpp"
#line 148 "/root/p4c/ir/ir.def"
const IR::Type *IR::P4Control::getType() const { return this->type; }
#line 5535 "/root/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(P4Control, , )
#line 150 "/root/p4c/ir/ir.def"
void IR::P4Control::validate() const {
#line 5539 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(constructorParams);
        controlLocals.validate();
        CHECK_NULL(body);
#line 150 "/root/p4c/ir/ir.def"
{
        if (!(name == type->name))
            BUG("Name mismatch for %1%: %2% != %3%", this, name, type->name);
        controlLocals.check_null();
    } }
#line 5551 "/root/p4c/build/ir/ir-generated.cpp"
#line 155 "/root/p4c/ir/ir.def"
cstring IR::P4Control::toString() const { return "control "_cs + externalName(); }
#line 5554 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::P4Control::operator==(IR::P4Control const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && type == a.type
        && constructorParams == a.constructorParams
        && controlLocals == a.controlLocals
        && body == a.body;
    }
bool IR::P4Control::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4Control &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (constructorParams ? a.constructorParams ? constructorParams->equiv(*a.constructorParams) : false : a.constructorParams == nullptr)
        && controlLocals.equiv(a.controlLocals)
        && (body ? a.body ? body->equiv(*a.body) : false : a.body == nullptr);
    }
void IR::P4Control::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_Declaration::visit_children(v, n);
    v.visit(type, "type");
    v.visit(constructorParams, "constructorParams");
    controlLocals.visit_children(v, "controlLocals");
    v.visit(body, "body");
}
void IR::P4Control::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_Declaration::visit_children(v, n);
    v.visit(type, "type");
    v.visit(constructorParams, "constructorParams");
    controlLocals.visit_children(v, "controlLocals");
    v.visit(body, "body");
}
void IR::P4Control::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json.emit("type", type);
    json.emit("constructorParams", constructorParams);
    json.emit("controlLocals", controlLocals);
    json.emit("body", body);
}
IR::P4Control::P4Control(JSONLoader & json) : Type_Declaration(json) {
    json.load("type", type);
    json.load("constructorParams", constructorParams);
    json.load("controlLocals", controlLocals);
    json.load("body", body);
}
IR::Node * IR::P4Control::fromJSON(JSONLoader & json) { return new P4Control(json); }
bool IR::P4Control::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::P4Control::operator==(IR::Type const & a) const { return a == *this; }
bool IR::P4Control::operator==(IR::Node const & a) const { return a == *this; }
#line 163 "/root/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::P4Action::getDeclarations() const {
        return parameters->getDeclarations(); }
#line 5607 "/root/p4c/build/ir/ir-generated.cpp"
#line 165 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::P4Action::getDeclByName(cstring name) const {
        return parameters->getDeclByName(name); }
#line 5611 "/root/p4c/build/ir/ir-generated.cpp"
#line 167 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::P4Action::getDeclByName(std::string_view name) const {
        return parameters->getDeclByName(name); }
#line 5615 "/root/p4c/build/ir/ir-generated.cpp"
#line 169 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::P4Action::getAnnotations() const { return annotations; }
#line 5618 "/root/p4c/build/ir/ir-generated.cpp"
#line 170 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::P4Action::getAnnotations() { return annotations; }
#line 5621 "/root/p4c/build/ir/ir-generated.cpp"
#line 171 "/root/p4c/ir/ir.def"
const IR::ParameterList *IR::P4Action::getParameters() const { return parameters; }
#line 5624 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::P4Action::operator==(IR::P4Action const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && parameters == a.parameters
        && body == a.body;
    }
bool IR::P4Action::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4Action &>(a_);
        return annotations.equiv(a.annotations)
        && (parameters ? a.parameters ? parameters->equiv(*a.parameters) : false : a.parameters == nullptr)
        && (body ? a.body ? body->equiv(*a.body) : false : a.body == nullptr);
    }
void IR::P4Action::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(parameters, "parameters");
    v.visit(body, "body");
}
void IR::P4Action::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(parameters, "parameters");
    v.visit(body, "body");
}
void IR::P4Action::validate() const {
#line 5654 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(parameters);
        CHECK_NULL(body); }
void IR::P4Action::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("parameters", parameters);
    json.emit("body", body);
}
IR::P4Action::P4Action(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("parameters", parameters);
    json.load("body", body);
}
IR::Node * IR::P4Action::fromJSON(JSONLoader & json) { return new P4Action(json); }
bool IR::P4Action::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::P4Action::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::P4Action::operator==(IR::Node const & a) const { return a == *this; }
#line 177 "/root/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_Error::getDeclarations() const {
        return members.getDeclarations(); }
#line 5677 "/root/p4c/build/ir/ir-generated.cpp"
#line 179 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::Type_Error::getDeclByName(cstring name) const {
        return members.getDeclaration(name); }
#line 5681 "/root/p4c/build/ir/ir-generated.cpp"
#line 181 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::Type_Error::getDeclByName(std::string_view name) const {
        return members.getDeclaration(name); }
#line 5685 "/root/p4c/build/ir/ir-generated.cpp"
#line 183 "/root/p4c/ir/ir.def"
void IR::Type_Error::validate() const {
#line 5688 "/root/p4c/build/ir/ir-generated.cpp"

        members.validate();
#line 183 "/root/p4c/ir/ir.def"
{ members.check_null(); } }
#line 5693 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Error::operator==(IR::Type_Error const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && members == a.members;
    }
bool IR::Type_Error::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Error &>(a_);
        return members.equiv(a.members);
    }
void IR::Type_Error::visit_children(Visitor & v, char const * n) {
    (void)n;
    Type_Declaration::visit_children(v, n);
    members.visit_children(v, "members");
}
void IR::Type_Error::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Type_Declaration::visit_children(v, n);
    members.visit_children(v, "members");
}
void IR::Type_Error::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json.emit("members", members);
}
IR::Type_Error::Type_Error(JSONLoader & json) : Type_Declaration(json) {
    json.load("members", members);
}
IR::Node * IR::Type_Error::fromJSON(JSONLoader & json) { return new Type_Error(json); }
bool IR::Type_Error::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::Type_Error::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Error::operator==(IR::Node const & a) const { return a == *this; }
#line 189 "/root/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Declaration_MatchKind::getDeclarations() const {
        return members.getDeclarations(); }
#line 5728 "/root/p4c/build/ir/ir-generated.cpp"
#line 191 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::Declaration_MatchKind::getDeclByName(cstring name) const {
        return members.getDeclaration(name); }
#line 5732 "/root/p4c/build/ir/ir-generated.cpp"
#line 193 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::Declaration_MatchKind::getDeclByName(std::string_view name) const {
        return members.getDeclaration(name); }
#line 5736 "/root/p4c/build/ir/ir-generated.cpp"
#line 195 "/root/p4c/ir/ir.def"
void IR::Declaration_MatchKind::validate() const {
#line 5739 "/root/p4c/build/ir/ir-generated.cpp"

        members.validate();
#line 195 "/root/p4c/ir/ir.def"
{ members.check_null(); } }
#line 5744 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Declaration_MatchKind::operator==(IR::Declaration_MatchKind const & a) const {
        return this->typeId() == a.typeId()
        && members == a.members;
    }
bool IR::Declaration_MatchKind::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const Declaration_MatchKind &>(a_);
        return members.equiv(a.members);
    }
void IR::Declaration_MatchKind::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    members.visit_children(v, "members");
}
void IR::Declaration_MatchKind::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    members.visit_children(v, "members");
}
void IR::Declaration_MatchKind::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("members", members);
}
IR::Declaration_MatchKind::Declaration_MatchKind(JSONLoader & json) : Node(json) {
    json.load("members", members);
}
IR::Node * IR::Declaration_MatchKind::fromJSON(JSONLoader & json) { return new Declaration_MatchKind(json); }
bool IR::Declaration_MatchKind::operator==(IR::Node const & a) const { return a == *this; }
bool IR::PropertyValue::operator==(IR::PropertyValue const & a) const {
        return this->typeId() == a.typeId();
    }
bool IR::PropertyValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        return true;
    }
void IR::PropertyValue::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::PropertyValue::PropertyValue(JSONLoader & json) : Node(json) {
}
bool IR::PropertyValue::operator==(IR::Node const & a) const { return a == *this; }
#line 204 "/root/p4c/ir/ir.def"
void IR::ExpressionValue::dbprint(std::ostream & out) const { out << expression; }
#line 5790 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ExpressionValue::operator==(IR::ExpressionValue const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && expression == a.expression;
    }
bool IR::ExpressionValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const ExpressionValue &>(a_);
        return (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::ExpressionValue::visit_children(Visitor & v, char const * n) {
    (void)n;
    PropertyValue::visit_children(v, n);
    v.visit(expression, "expression");
}
void IR::ExpressionValue::visit_children(Visitor & v, char const * n) const {
    (void)n;
    PropertyValue::visit_children(v, n);
    v.visit(expression, "expression");
}
void IR::ExpressionValue::validate() const {
#line 5812 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(expression); }
void IR::ExpressionValue::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json.emit("expression", expression);
}
IR::ExpressionValue::ExpressionValue(JSONLoader & json) : PropertyValue(json) {
    json.load("expression", expression);
}
IR::Node * IR::ExpressionValue::fromJSON(JSONLoader & json) { return new ExpressionValue(json); }
bool IR::ExpressionValue::operator==(IR::PropertyValue const & a) const { return a == *this; }
bool IR::ExpressionValue::operator==(IR::Node const & a) const { return a == *this; }
#line 209 "/root/p4c/ir/ir.def"
void IR::ExpressionListValue::dbprint(std::ostream & out) const { out << expressions; }
#line 5827 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ExpressionListValue::operator==(IR::ExpressionListValue const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && expressions == a.expressions;
    }
bool IR::ExpressionListValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const ExpressionListValue &>(a_);
        return expressions.equiv(a.expressions);
    }
void IR::ExpressionListValue::visit_children(Visitor & v, char const * n) {
    (void)n;
    PropertyValue::visit_children(v, n);
    expressions.visit_children(v, "expressions");
}
void IR::ExpressionListValue::visit_children(Visitor & v, char const * n) const {
    (void)n;
    PropertyValue::visit_children(v, n);
    expressions.visit_children(v, "expressions");
}
void IR::ExpressionListValue::validate() const {
#line 5849 "/root/p4c/build/ir/ir-generated.cpp"

        expressions.validate(); }
void IR::ExpressionListValue::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json.emit("expressions", expressions);
}
IR::ExpressionListValue::ExpressionListValue(JSONLoader & json) : PropertyValue(json) {
    json.load("expressions", expressions);
}
IR::Node * IR::ExpressionListValue::fromJSON(JSONLoader & json) { return new ExpressionListValue(json); }
bool IR::ExpressionListValue::operator==(IR::PropertyValue const & a) const { return a == *this; }
bool IR::ExpressionListValue::operator==(IR::Node const & a) const { return a == *this; }

#line 216 "/root/p4c/ir/ir.def"
void IR::ActionListElement::dbprint(std::ostream & out) const { out << annotations << expression; }
#line 5865 "/root/p4c/build/ir/ir-generated.cpp"
#line 217 "/root/p4c/ir/ir.def"
IR::ID IR::ActionListElement::getName() const { return getPath()->name; }
#line 5868 "/root/p4c/build/ir/ir-generated.cpp"
#line 219 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::ActionListElement::getAnnotations() const { return annotations; }
#line 5871 "/root/p4c/build/ir/ir-generated.cpp"
#line 220 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::ActionListElement::getAnnotations() { return annotations; }
#line 5874 "/root/p4c/build/ir/ir-generated.cpp"
#line 221 "/root/p4c/ir/ir.def"
void IR::ActionListElement::validate() const {
#line 5877 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(expression);
#line 221 "/root/p4c/ir/ir.def"
{
        BUG_CHECK(expression->is<IR::PathExpression>() ||
                  expression->is<IR::MethodCallExpression>(),
                  "%1%: unexpected expression", expression);
    } }
#line 5887 "/root/p4c/build/ir/ir-generated.cpp"
#line 226 "/root/p4c/ir/ir.def"
cstring IR::ActionListElement::toString() const { return getName().toString(); }
#line 5890 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ActionListElement::operator==(IR::ActionListElement const & a) const {
        return this->typeId() == a.typeId()
        && annotations == a.annotations
        && expression == a.expression;
    }
bool IR::ActionListElement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const ActionListElement &>(a_);
        return annotations.equiv(a.annotations)
        && (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::ActionListElement::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(expression, "expression");
}
void IR::ActionListElement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(expression, "expression");
}
void IR::ActionListElement::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("expression", expression);
}
IR::ActionListElement::ActionListElement(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
    json.load("expression", expression);
}
IR::Node * IR::ActionListElement::fromJSON(JSONLoader & json) { return new ActionListElement(json); }
bool IR::ActionListElement::operator==(IR::Node const & a) const { return a == *this; }
#line 232 "/root/p4c/ir/ir.def"
void IR::ActionList::validate() const {
#line 5928 "/root/p4c/build/ir/ir-generated.cpp"

        actionList.validate();
#line 232 "/root/p4c/ir/ir.def"
{ actionList.check_null(); } }
#line 5933 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ActionList::operator==(IR::ActionList const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && actionList == a.actionList;
    }
bool IR::ActionList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const ActionList &>(a_);
        return actionList.equiv(a.actionList);
    }
void IR::ActionList::visit_children(Visitor & v, char const * n) {
    (void)n;
    PropertyValue::visit_children(v, n);
    actionList.visit_children(v, "actionList");
}
void IR::ActionList::visit_children(Visitor & v, char const * n) const {
    (void)n;
    PropertyValue::visit_children(v, n);
    actionList.visit_children(v, "actionList");
}
void IR::ActionList::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json.emit("actionList", actionList);
}
IR::ActionList::ActionList(JSONLoader & json) : PropertyValue(json) {
    json.load("actionList", actionList);
}
IR::Node * IR::ActionList::fromJSON(JSONLoader & json) { return new ActionList(json); }
bool IR::ActionList::operator==(IR::PropertyValue const & a) const { return a == *this; }
bool IR::ActionList::operator==(IR::Node const & a) const { return a == *this; }
#line 244 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::KeyElement::getAnnotations() const { return annotations; }
#line 5966 "/root/p4c/build/ir/ir-generated.cpp"
#line 245 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::KeyElement::getAnnotations() { return annotations; }
#line 5969 "/root/p4c/build/ir/ir-generated.cpp"
#line 246 "/root/p4c/ir/ir.def"
IR::Node const * IR::KeyElement::transform_visit(Transform & v) {
        // call this from Transform::preorder(KeyElement) if the transform might split
        // the expression into a Vector<Expression>
        v.visit(annotations, "annotations");
        auto exp = v.apply_visitor(expression, "expression");
        v.visit(matchType, "matchType");
        v.prune();
        if (exp == expression) {
        } else if (auto vec = exp->to<Vector<Expression>>()) {
            auto *rv = new Vector<KeyElement>();
            for (auto el : *vec) {
                auto *kel = clone();
                kel->expression = el;
                rv->push_back(kel); }
            return rv;
        } else {
            expression = exp->to<IR::Expression>(); }
        return this; }
#line 5989 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::KeyElement::operator==(IR::KeyElement const & a) const {
        return this->typeId() == a.typeId()
        && expression == a.expression
        && matchType == a.matchType
        && annotations == a.annotations;
    }
bool IR::KeyElement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const KeyElement &>(a_);
        return (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr)
        && (matchType ? a.matchType ? matchType->equiv(*a.matchType) : false : a.matchType == nullptr)
        && annotations.equiv(a.annotations);
    }
void IR::KeyElement::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(expression, "expression");
    v.visit(matchType, "matchType");
    annotations.visit_children(v, "annotations");
}
void IR::KeyElement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(expression, "expression");
    v.visit(matchType, "matchType");
    annotations.visit_children(v, "annotations");
}
void IR::KeyElement::validate() const {
#line 6019 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(expression);
        CHECK_NULL(matchType);
        annotations.validate(); }
void IR::KeyElement::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("expression", expression);
    json.emit("matchType", matchType);
    json.emit("annotations", annotations);
}
IR::KeyElement::KeyElement(JSONLoader & json) : Node(json) {
    json.load("expression", expression);
    json.load("matchType", matchType);
    json.load("annotations", annotations);
}
IR::Node * IR::KeyElement::fromJSON(JSONLoader & json) { return new KeyElement(json); }
bool IR::KeyElement::operator==(IR::Node const & a) const { return a == *this; }
#line 269 "/root/p4c/ir/ir.def"
void IR::Key::validate() const {
#line 6039 "/root/p4c/build/ir/ir-generated.cpp"

        keyElements.validate();
#line 269 "/root/p4c/ir/ir.def"
{ keyElements.check_null(); } }
#line 6044 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Key::operator==(IR::Key const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && keyElements == a.keyElements;
    }
bool IR::Key::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const Key &>(a_);
        return keyElements.equiv(a.keyElements);
    }
void IR::Key::visit_children(Visitor & v, char const * n) {
    (void)n;
    PropertyValue::visit_children(v, n);
    keyElements.visit_children(v, "keyElements");
}
void IR::Key::visit_children(Visitor & v, char const * n) const {
    (void)n;
    PropertyValue::visit_children(v, n);
    keyElements.visit_children(v, "keyElements");
}
void IR::Key::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json.emit("keyElements", keyElements);
}
IR::Key::Key(JSONLoader & json) : PropertyValue(json) {
    json.load("keyElements", keyElements);
}
IR::Node * IR::Key::fromJSON(JSONLoader & json) { return new Key(json); }
bool IR::Key::operator==(IR::PropertyValue const & a) const { return a == *this; }
bool IR::Key::operator==(IR::Node const & a) const { return a == *this; }
/// annotations are optional (supported annotations: @priority(value))
/// optional const annotation
/// optional entry priority
/// must be a tuple expression
/// typically a MethodCallExpression.
/// The action must be defined in action list
/// True if the entry is not a list.
#line 284 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::Entry::getAnnotations() const { return annotations; }
#line 6084 "/root/p4c/build/ir/ir-generated.cpp"
#line 285 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::Entry::getAnnotations() { return annotations; }
#line 6087 "/root/p4c/build/ir/ir-generated.cpp"
#line 288 "/root/p4c/ir/ir.def"
void IR::Entry::dbprint(std::ostream & out) const { out << annotations << keys << action; }
#line 6090 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Entry::operator==(IR::Entry const & a) const {
        return this->typeId() == a.typeId()
        && annotations == a.annotations
        && isConst == a.isConst
        && priority == a.priority
        && keys == a.keys
        && action == a.action
        && singleton == a.singleton;
    }
bool IR::Entry::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const Entry &>(a_);
        return annotations.equiv(a.annotations)
        && isConst == a.isConst
        && (priority ? a.priority ? priority->equiv(*a.priority) : false : a.priority == nullptr)
        && (keys ? a.keys ? keys->equiv(*a.keys) : false : a.keys == nullptr)
        && (action ? a.action ? action->equiv(*a.action) : false : a.action == nullptr)
        && singleton == a.singleton;
    }
void IR::Entry::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(priority, "priority");
    v.visit(keys, "keys");
    v.visit(action, "action");
}
void IR::Entry::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(priority, "priority");
    v.visit(keys, "keys");
    v.visit(action, "action");
}
void IR::Entry::validate() const {
#line 6128 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(keys);
        CHECK_NULL(action); }
void IR::Entry::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " isConst=" << isConst;
        out << " singleton=" << singleton;
}
void IR::Entry::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("isConst", isConst);
    if (priority != nullptr) json.emit("priority", priority);
    json.emit("keys", keys);
    json.emit("action", action);
    json.emit("singleton", singleton);
}
IR::Entry::Entry(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
    json.load("isConst", isConst);
    json.load("priority", priority);
    json.load("keys", keys);
    json.load("action", action);
    json.load("singleton", singleton);
}
IR::Node * IR::Entry::fromJSON(JSONLoader & json) { return new Entry(json); }
bool IR::Entry::operator==(IR::Node const & a) const { return a == *this; }
#line 295 "/root/p4c/ir/ir.def"
void IR::EntriesList::dbprint(std::ostream & out) const { out << "{ " << entries << "}"; }
#line 6159 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::EntriesList::operator==(IR::EntriesList const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && entries == a.entries;
    }
bool IR::EntriesList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const EntriesList &>(a_);
        return entries.equiv(a.entries);
    }
void IR::EntriesList::visit_children(Visitor & v, char const * n) {
    (void)n;
    PropertyValue::visit_children(v, n);
    entries.visit_children(v, "entries");
}
void IR::EntriesList::visit_children(Visitor & v, char const * n) const {
    (void)n;
    PropertyValue::visit_children(v, n);
    entries.visit_children(v, "entries");
}
void IR::EntriesList::validate() const {
#line 6181 "/root/p4c/build/ir/ir-generated.cpp"

        entries.validate(); }
void IR::EntriesList::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json.emit("entries", entries);
}
IR::EntriesList::EntriesList(JSONLoader & json) : PropertyValue(json) {
    json.load("entries", entries);
}
IR::Node * IR::EntriesList::fromJSON(JSONLoader & json) { return new EntriesList(json); }
bool IR::EntriesList::operator==(IR::PropertyValue const & a) const { return a == *this; }
bool IR::EntriesList::operator==(IR::Node const & a) const { return a == *this; }
#line 302 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::Property::getAnnotations() const { return annotations; }
#line 6196 "/root/p4c/build/ir/ir-generated.cpp"
#line 303 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::Property::getAnnotations() { return annotations; }
#line 6199 "/root/p4c/build/ir/ir-generated.cpp"
#line 304 "/root/p4c/ir/ir.def"
void IR::Property::dbprint(std::ostream & out) const { out << annotations << (isConstant ? "const " : "") << name << " = " << value; }
#line 6202 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Property::operator==(IR::Property const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && value == a.value
        && isConstant == a.isConstant;
    }
bool IR::Property::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Property &>(a_);
        return annotations.equiv(a.annotations)
        && (value ? a.value ? value->equiv(*a.value) : false : a.value == nullptr)
        && isConstant == a.isConstant;
    }
void IR::Property::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(value, "value");
}
void IR::Property::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(value, "value");
}
void IR::Property::validate() const {
#line 6230 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(value); }
void IR::Property::dump_fields(std::ostream & out) const {
    Declaration::dump_fields(out);
        out << " isConstant=" << isConstant;
}
void IR::Property::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("value", value);
    json.emit("isConstant", isConstant);
}
IR::Property::Property(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("value", value);
    json.load("isConstant", isConstant);
}
IR::Node * IR::Property::fromJSON(JSONLoader & json) { return new Property(json); }
bool IR::Property::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::Property::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::Property::operator==(IR::Node const & a) const { return a == *this; }
#line 309 "/root/p4c/ir/ir.def"
cstring IR::TableProperties::toString() const { return absl::StrCat("TableProperties(", properties.size(), ")"); }
#line 6255 "/root/p4c/build/ir/ir-generated.cpp"
#line 310 "/root/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::TableProperties::getDeclarations() const {
        return properties.getDeclarations(); }
#line 6259 "/root/p4c/build/ir/ir-generated.cpp"
#line 314 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::TableProperties::getDeclByName(cstring name) const {
        return properties.getDeclaration(name); }
#line 6263 "/root/p4c/build/ir/ir-generated.cpp"
#line 318 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::TableProperties::getDeclByName(std::string_view name) const {
        return properties.getDeclaration(name); }
#line 6267 "/root/p4c/build/ir/ir-generated.cpp"
#line 328 "/root/p4c/ir/ir.def"
void IR::TableProperties::validate() const {
#line 6270 "/root/p4c/build/ir/ir-generated.cpp"

        properties.validate();
#line 328 "/root/p4c/ir/ir.def"
{ properties.check_null(); properties.validate(); } }
#line 6275 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::TableProperties::operator==(IR::TableProperties const & a) const {
        return this->typeId() == a.typeId()
        && properties == a.properties;
    }
bool IR::TableProperties::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const TableProperties &>(a_);
        return properties.equiv(a.properties);
    }
void IR::TableProperties::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    properties.visit_children(v, "properties");
}
void IR::TableProperties::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    properties.visit_children(v, "properties");
}
void IR::TableProperties::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("properties", properties);
}
IR::TableProperties::TableProperties(JSONLoader & json) : Node(json) {
    json.load("properties", properties);
}
IR::Node * IR::TableProperties::fromJSON(JSONLoader & json) { return new TableProperties(json); }
bool IR::TableProperties::operator==(IR::Node const & a) const { return a == *this; }
#line 335 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::P4Table::getAnnotations() const { return annotations; }
#line 6307 "/root/p4c/build/ir/ir-generated.cpp"
#line 336 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::P4Table::getAnnotations() { return annotations; }
#line 6310 "/root/p4c/build/ir/ir-generated.cpp"
#line 338 "/root/p4c/ir/ir.def"
const IR::ParameterList *IR::P4Table::getApplyParameters() const { return new ParameterList(); }
#line 6313 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::P4Table::operator==(IR::P4Table const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && properties == a.properties;
    }
bool IR::P4Table::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4Table &>(a_);
        return annotations.equiv(a.annotations)
        && (properties ? a.properties ? properties->equiv(*a.properties) : false : a.properties == nullptr);
    }
void IR::P4Table::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(properties, "properties");
}
void IR::P4Table::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(properties, "properties");
}
void IR::P4Table::validate() const {
#line 6339 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(properties); }
void IR::P4Table::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("properties", properties);
}
IR::P4Table::P4Table(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("properties", properties);
}
IR::Node * IR::P4Table::fromJSON(JSONLoader & json) { return new P4Table(json); }
bool IR::P4Table::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::P4Table::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::P4Table::operator==(IR::Node const & a) const { return a == *this; }

#line 390 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::P4ValueSet::getAnnotations() const { return annotations; }
#line 6359 "/root/p4c/build/ir/ir-generated.cpp"
#line 391 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::P4ValueSet::getAnnotations() { return annotations; }
#line 6362 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::P4ValueSet::operator==(IR::P4ValueSet const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && elementType == a.elementType
        && size == a.size;
    }
bool IR::P4ValueSet::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4ValueSet &>(a_);
        return annotations.equiv(a.annotations)
        && (elementType ? a.elementType ? elementType->equiv(*a.elementType) : false : a.elementType == nullptr)
        && (size ? a.size ? size->equiv(*a.size) : false : a.size == nullptr);
    }
void IR::P4ValueSet::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(elementType, "elementType");
    v.visit(size, "size");
}
void IR::P4ValueSet::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(elementType, "elementType");
    v.visit(size, "size");
}
void IR::P4ValueSet::validate() const {
#line 6392 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(elementType);
        CHECK_NULL(size); }
void IR::P4ValueSet::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("elementType", elementType);
    json.emit("size", size);
}
IR::P4ValueSet::P4ValueSet(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("elementType", elementType);
    json.load("size", size);
}
IR::Node * IR::P4ValueSet::fromJSON(JSONLoader & json) { return new P4ValueSet(json); }
bool IR::P4ValueSet::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::P4ValueSet::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::P4ValueSet::operator==(IR::Node const & a) const { return a == *this; }
#line 399 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::Declaration_Variable::getAnnotations() const { return annotations; }
#line 6414 "/root/p4c/build/ir/ir-generated.cpp"
#line 400 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::Declaration_Variable::getAnnotations() { return annotations; }
#line 6417 "/root/p4c/build/ir/ir-generated.cpp"
#line 401 "/root/p4c/ir/ir.def"
void IR::Declaration_Variable::dbprint(std::ostream & out) const {
        out << annotations << type << ' ' << name;
        if (initializer) out << " = " << *initializer; }
#line 6422 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Declaration_Variable::operator==(IR::Declaration_Variable const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && type == a.type
        && initializer == a.initializer;
    }
bool IR::Declaration_Variable::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Declaration_Variable &>(a_);
        return annotations.equiv(a.annotations)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (initializer ? a.initializer ? initializer->equiv(*a.initializer) : false : a.initializer == nullptr);
    }
void IR::Declaration_Variable::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
    v.visit(initializer, "initializer");
}
void IR::Declaration_Variable::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
    v.visit(initializer, "initializer");
}
void IR::Declaration_Variable::validate() const {
#line 6452 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(type); }
void IR::Declaration_Variable::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("type", type);
    if (initializer != nullptr) json.emit("initializer", initializer);
}
IR::Declaration_Variable::Declaration_Variable(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
    json.load("initializer", initializer);
}
IR::Node * IR::Declaration_Variable::fromJSON(JSONLoader & json) { return new Declaration_Variable(json); }
bool IR::Declaration_Variable::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::Declaration_Variable::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::Declaration_Variable::operator==(IR::Node const & a) const { return a == *this; }
#line 411 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::Declaration_Constant::getAnnotations() const { return annotations; }
#line 6473 "/root/p4c/build/ir/ir-generated.cpp"
#line 412 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::Declaration_Constant::getAnnotations() { return annotations; }
#line 6476 "/root/p4c/build/ir/ir-generated.cpp"
#line 413 "/root/p4c/ir/ir.def"
cstring IR::Declaration_Constant::toString() const { return Declaration::toString(); }
#line 6479 "/root/p4c/build/ir/ir-generated.cpp"
#line 414 "/root/p4c/ir/ir.def"
void IR::Declaration_Constant::dbprint(std::ostream & out) const { out << annotations << type << ' ' << name << " = " << *initializer; }
#line 6482 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Declaration_Constant::operator==(IR::Declaration_Constant const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && type == a.type
        && initializer == a.initializer;
    }
bool IR::Declaration_Constant::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Declaration_Constant &>(a_);
        return annotations.equiv(a.annotations)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (initializer ? a.initializer ? initializer->equiv(*a.initializer) : false : a.initializer == nullptr);
    }
void IR::Declaration_Constant::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
    v.visit(initializer, "initializer");
}
void IR::Declaration_Constant::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
    v.visit(initializer, "initializer");
}
void IR::Declaration_Constant::validate() const {
#line 6512 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(type);
        CHECK_NULL(initializer); }
void IR::Declaration_Constant::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("type", type);
    json.emit("initializer", initializer);
}
IR::Declaration_Constant::Declaration_Constant(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
    json.load("initializer", initializer);
}
IR::Node * IR::Declaration_Constant::fromJSON(JSONLoader & json) { return new Declaration_Constant(json); }
bool IR::Declaration_Constant::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::Declaration_Constant::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::Declaration_Constant::operator==(IR::Node const & a) const { return a == *this; }



#line 429 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::Declaration_Instance::getAnnotations() const { return annotations; }
#line 6537 "/root/p4c/build/ir/ir-generated.cpp"
#line 430 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::Declaration_Instance::getAnnotations() { return annotations; }
#line 6540 "/root/p4c/build/ir/ir-generated.cpp"
#line 431 "/root/p4c/ir/ir.def"
const IR::Type *IR::Declaration_Instance::getType() const { return type; }
#line 6543 "/root/p4c/build/ir/ir-generated.cpp"
#line 432 "/root/p4c/ir/ir.def"
IR::ID IR::Declaration_Instance::Name() const { return name; }
#line 6546 "/root/p4c/build/ir/ir-generated.cpp"
#line 433 "/root/p4c/ir/ir.def"
void IR::Declaration_Instance::validate() const {
#line 6549 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(type);
        CHECK_NULL(arguments);
        properties.validate();
#line 433 "/root/p4c/ir/ir.def"
{ arguments->check_null(); } }
#line 6557 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Declaration_Instance::operator==(IR::Declaration_Instance const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && type == a.type
        && arguments == a.arguments
        && properties == a.properties
        && initializer == a.initializer;
    }
bool IR::Declaration_Instance::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Declaration_Instance &>(a_);
        return annotations.equiv(a.annotations)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr)
        && properties.equiv(a.properties)
        && (initializer ? a.initializer ? initializer->equiv(*a.initializer) : false : a.initializer == nullptr);
    }
void IR::Declaration_Instance::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
    v.visit(arguments, "arguments");
    properties.visit_children(v, "properties");
    v.visit(initializer, "initializer");
}
void IR::Declaration_Instance::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
    v.visit(arguments, "arguments");
    properties.visit_children(v, "properties");
    v.visit(initializer, "initializer");
}
void IR::Declaration_Instance::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("type", type);
    json.emit("arguments", arguments);
    json.emit("properties", properties);
    if (initializer != nullptr) json.emit("initializer", initializer);
}
IR::Declaration_Instance::Declaration_Instance(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
    json.load("arguments", arguments);
    json.load("properties", properties);
    json.load("initializer", initializer);
}
IR::Node * IR::Declaration_Instance::fromJSON(JSONLoader & json) { return new Declaration_Instance(json); }
bool IR::Declaration_Instance::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::Declaration_Instance::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::Declaration_Instance::operator==(IR::Node const & a) const { return a == *this; }
/// Top-level program objects.
/// This is not an IndexedVector because:
/// - we allow overloaded function-like objects.
/// - not all objects in a P4Program are declarations (e.g., match_kind is not).
#line 444 "/root/p4c/ir/ir.def"
void IR::P4Program::validate() const {
#line 6619 "/root/p4c/build/ir/ir-generated.cpp"

        objects.validate();
#line 444 "/root/p4c/ir/ir.def"
{ objects.check_null(); } }
#line 6624 "/root/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(P4Program, , )
bool IR::P4Program::operator==(IR::P4Program const & a) const {
        return this->typeId() == a.typeId()
        && objects == a.objects;
    }
bool IR::P4Program::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const P4Program &>(a_);
        return objects.equiv(a.objects);
    }
void IR::P4Program::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    objects.visit_children(v, "objects");
}
void IR::P4Program::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    objects.visit_children(v, "objects");
}
void IR::P4Program::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("objects", objects);
}
IR::P4Program::P4Program(JSONLoader & json) : Node(json) {
    json.load("objects", objects);
}
IR::Node * IR::P4Program::fromJSON(JSONLoader & json) { return new P4Program(json); }
bool IR::P4Program::operator==(IR::Node const & a) const { return a == *this; }
#line 456 "/root/p4c/ir/ir.def"
cstring IR::ExitStatement::toString() const { return "exit"_cs; }
#line 6657 "/root/p4c/build/ir/ir-generated.cpp"
#line 457 "/root/p4c/ir/ir.def"
void IR::ExitStatement::dbprint(std::ostream & out) const { out << "exit"; }
#line 6660 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ExitStatement::operator==(IR::ExitStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a));
    }
bool IR::ExitStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        return true;
    }
void IR::ExitStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
}
IR::ExitStatement::ExitStatement(JSONLoader & json) : Statement(json) {
}
IR::Node * IR::ExitStatement::fromJSON(JSONLoader & json) { return new ExitStatement(json); }
bool IR::ExitStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::ExitStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::ExitStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 462 "/root/p4c/ir/ir.def"
cstring IR::ReturnStatement::toString() const { return absl::StrCat("return ",
                                  (expression ?
                                   expression->toString() : ""_cs)); }
#line 6682 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ReturnStatement::operator==(IR::ReturnStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && expression == a.expression;
    }
bool IR::ReturnStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const ReturnStatement &>(a_);
        return (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::ReturnStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    Statement::visit_children(v, n);
    v.visit(expression, "expression");
}
void IR::ReturnStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Statement::visit_children(v, n);
    v.visit(expression, "expression");
}
void IR::ReturnStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    if (expression != nullptr) json.emit("expression", expression);
}
IR::ReturnStatement::ReturnStatement(JSONLoader & json) : Statement(json) {
    json.load("expression", expression);
}
IR::Node * IR::ReturnStatement::fromJSON(JSONLoader & json) { return new ReturnStatement(json); }
bool IR::ReturnStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::ReturnStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::ReturnStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 468 "/root/p4c/ir/ir.def"
void IR::EmptyStatement::dbprint(std::ostream & out) const { out << ""; }
#line 6716 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::EmptyStatement::operator==(IR::EmptyStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a));
    }
bool IR::EmptyStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        return true;
    }
void IR::EmptyStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
}
IR::EmptyStatement::EmptyStatement(JSONLoader & json) : Statement(json) {
}
IR::Node * IR::EmptyStatement::fromJSON(JSONLoader & json) { return new EmptyStatement(json); }
bool IR::EmptyStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::EmptyStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::EmptyStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 477 "/root/p4c/ir/ir.def"
cstring IR::AssignmentStatement::toString() const { return absl::StrCat(left, " = ", right); }
#line 6736 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::AssignmentStatement::operator==(IR::AssignmentStatement const & a) const {
        return BaseAssignmentStatement::operator==(static_cast<const BaseAssignmentStatement &>(a));
    }
bool IR::AssignmentStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!BaseAssignmentStatement::equiv(a_)) return false;
        return true;
    }
void IR::AssignmentStatement::toJSON(JSONGenerator & json) const {
    BaseAssignmentStatement::toJSON(json);
}
IR::AssignmentStatement::AssignmentStatement(JSONLoader & json) : BaseAssignmentStatement(json) {
}
IR::Node * IR::AssignmentStatement::fromJSON(JSONLoader & json) { return new AssignmentStatement(json); }
bool IR::AssignmentStatement::operator==(IR::BaseAssignmentStatement const & a) const { return a == *this; }
bool IR::AssignmentStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::AssignmentStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::AssignmentStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 490 "/root/p4c/ir/ir.def"
void IR::IfStatement::visit_children(Visitor & v, char const * n) {
        (void)n;
        v.visit(condition, "condition");
        SplitFlowVisit<Statement>(v, ifTrue, ifFalse).run_visit(); }
#line 490 "/root/p4c/ir/ir.def"
void IR::IfStatement::visit_children(Visitor & v, char const * n) const {
        (void)n;
        v.visit(condition, "condition");
        SplitFlowVisit<Statement>(v, ifTrue, ifFalse).run_visit(); }
#line 6765 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::IfStatement::operator==(IR::IfStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && condition == a.condition
        && ifTrue == a.ifTrue
        && ifFalse == a.ifFalse;
    }
bool IR::IfStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const IfStatement &>(a_);
        return (condition ? a.condition ? condition->equiv(*a.condition) : false : a.condition == nullptr)
        && (ifTrue ? a.ifTrue ? ifTrue->equiv(*a.ifTrue) : false : a.ifTrue == nullptr)
        && (ifFalse ? a.ifFalse ? ifFalse->equiv(*a.ifFalse) : false : a.ifFalse == nullptr);
    }
void IR::IfStatement::validate() const {
#line 6781 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(condition);
        CHECK_NULL(ifTrue); }
void IR::IfStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json.emit("condition", condition);
    json.emit("ifTrue", ifTrue);
    if (ifFalse != nullptr) json.emit("ifFalse", ifFalse);
}
IR::IfStatement::IfStatement(JSONLoader & json) : Statement(json) {
    json.load("condition", condition);
    json.load("ifTrue", ifTrue);
    json.load("ifFalse", ifFalse);
}
IR::Node * IR::IfStatement::fromJSON(JSONLoader & json) { return new IfStatement(json); }
bool IR::IfStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::IfStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::IfStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 497 "/root/p4c/ir/ir.def"
cstring IR::BreakStatement::toString() const { return "break"_cs; }
#line 6802 "/root/p4c/build/ir/ir-generated.cpp"
#line 498 "/root/p4c/ir/ir.def"
void IR::BreakStatement::dbprint(std::ostream & out) const { out << "break"; }
#line 6805 "/root/p4c/build/ir/ir-generated.cpp"

bool IR::BreakStatement::operator==(IR::BreakStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a));
    }
bool IR::BreakStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        return true;
    }
void IR::BreakStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
}
IR::BreakStatement::BreakStatement(JSONLoader & json) : Statement(json) {
}
IR::Node * IR::BreakStatement::fromJSON(JSONLoader & json) { return new BreakStatement(json); }
bool IR::BreakStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::BreakStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::BreakStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 503 "/root/p4c/ir/ir.def"
cstring IR::ContinueStatement::toString() const { return "continue"_cs; }
#line 6826 "/root/p4c/build/ir/ir-generated.cpp"
#line 504 "/root/p4c/ir/ir.def"
void IR::ContinueStatement::dbprint(std::ostream & out) const { out << "continue"; }
#line 6829 "/root/p4c/build/ir/ir-generated.cpp"

bool IR::ContinueStatement::operator==(IR::ContinueStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a));
    }
bool IR::ContinueStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        return true;
    }
void IR::ContinueStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
}
IR::ContinueStatement::ContinueStatement(JSONLoader & json) : Statement(json) {
}
IR::Node * IR::ContinueStatement::fromJSON(JSONLoader & json) { return new ContinueStatement(json); }
bool IR::ContinueStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::ContinueStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::ContinueStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 511 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::BlockStatement::getDeclByName(cstring name) const {
        return components.getDeclaration(name); }
#line 6851 "/root/p4c/build/ir/ir-generated.cpp"
#line 513 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::BlockStatement::getDeclByName(std::string_view name) const {
        return components.getDeclaration(name); }
#line 6855 "/root/p4c/build/ir/ir-generated.cpp"
#line 515 "/root/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::BlockStatement::getDeclarations() const {
        return components.getDeclarations(); }
#line 6859 "/root/p4c/build/ir/ir-generated.cpp"
#line 517 "/root/p4c/ir/ir.def"
void IR::BlockStatement::push_back(const IR::StatOrDecl* st) { components.push_back(st); }
#line 6862 "/root/p4c/build/ir/ir-generated.cpp"
#line 518 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::BlockStatement::getAnnotations() const { return annotations; }
#line 6865 "/root/p4c/build/ir/ir-generated.cpp"
#line 519 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::BlockStatement::getAnnotations() { return annotations; }
#line 6868 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::BlockStatement::operator==(IR::BlockStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && annotations == a.annotations
        && components == a.components;
    }
bool IR::BlockStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const BlockStatement &>(a_);
        return annotations.equiv(a.annotations)
        && components.equiv(a.components);
    }
void IR::BlockStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    Statement::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    components.visit_children(v, "components");
}
void IR::BlockStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Statement::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    components.visit_children(v, "components");
}
void IR::BlockStatement::validate() const {
#line 6894 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        components.validate(); }
void IR::BlockStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("components", components);
}
IR::BlockStatement::BlockStatement(JSONLoader & json) : Statement(json) {
    json.load("annotations", annotations);
    json.load("components", components);
}
IR::Node * IR::BlockStatement::fromJSON(JSONLoader & json) { return new BlockStatement(json); }
bool IR::BlockStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::BlockStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::BlockStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 533 "/root/p4c/ir/ir.def"
cstring IR::MethodCallStatement::toString() const { return methodCall->toString(); }
#line 6913 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::MethodCallStatement::operator==(IR::MethodCallStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && methodCall == a.methodCall;
    }
bool IR::MethodCallStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const MethodCallStatement &>(a_);
        return (methodCall ? a.methodCall ? methodCall->equiv(*a.methodCall) : false : a.methodCall == nullptr);
    }
void IR::MethodCallStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    Statement::visit_children(v, n);
    v.visit(methodCall, "methodCall");
}
void IR::MethodCallStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Statement::visit_children(v, n);
    v.visit(methodCall, "methodCall");
}
void IR::MethodCallStatement::validate() const {
#line 6935 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(methodCall); }
void IR::MethodCallStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json.emit("methodCall", methodCall);
}
IR::MethodCallStatement::MethodCallStatement(JSONLoader & json) : Statement(json) {
    json.load("methodCall", methodCall);
}
IR::Node * IR::MethodCallStatement::fromJSON(JSONLoader & json) { return new MethodCallStatement(json); }
bool IR::MethodCallStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::MethodCallStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::MethodCallStatement::operator==(IR::Node const & a) const { return a == *this; }

#line 540 "/root/p4c/ir/ir.def"
void IR::SwitchCase::validate() const {
#line 6952 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(label);
#line 540 "/root/p4c/ir/ir.def"
{
        BUG_CHECK(statement == nullptr || statement->is<IR::BlockStatement>(),
                  "%1%: Expected a block statement",
                  statement);
    } }
#line 6961 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::SwitchCase::operator==(IR::SwitchCase const & a) const {
        return this->typeId() == a.typeId()
        && label == a.label
        && statement == a.statement;
    }
bool IR::SwitchCase::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const SwitchCase &>(a_);
        return (label ? a.label ? label->equiv(*a.label) : false : a.label == nullptr)
        && (statement ? a.statement ? statement->equiv(*a.statement) : false : a.statement == nullptr);
    }
void IR::SwitchCase::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(label, "label");
    v.visit(statement, "statement");
}
void IR::SwitchCase::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(label, "label");
    v.visit(statement, "statement");
}
void IR::SwitchCase::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("label", label);
    if (statement != nullptr) json.emit("statement", statement);
}
IR::SwitchCase::SwitchCase(JSONLoader & json) : Node(json) {
    json.load("label", label);
    json.load("statement", statement);
}
IR::Node * IR::SwitchCase::fromJSON(JSONLoader & json) { return new SwitchCase(json); }
bool IR::SwitchCase::operator==(IR::Node const & a) const { return a == *this; }
#line 552 "/root/p4c/ir/ir.def"
void IR::SwitchStatement::visit_children(Visitor & v, char const * n) {
        (void)n;
        v.visit(expression, "expression");
        SplitFlowVisit<SwitchCase> split(v);
        for (auto &c : cases) split.addNode(c);
        split.run_visit(); }
#line 552 "/root/p4c/ir/ir.def"
void IR::SwitchStatement::visit_children(Visitor & v, char const * n) const {
        (void)n;
        v.visit(expression, "expression");
        SplitFlowVisit<SwitchCase> split(v);
        for (auto &c : cases) split.addNode(c);
        split.run_visit(); }
#line 7011 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::SwitchStatement::operator==(IR::SwitchStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && expression == a.expression
        && cases == a.cases;
    }
bool IR::SwitchStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const SwitchStatement &>(a_);
        return (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr)
        && cases.equiv(a.cases);
    }
void IR::SwitchStatement::validate() const {
#line 7025 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(expression);
        cases.validate(); }
void IR::SwitchStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json.emit("expression", expression);
    json.emit("cases", cases);
}
IR::SwitchStatement::SwitchStatement(JSONLoader & json) : Statement(json) {
    json.load("expression", expression);
    json.load("cases", cases);
}
IR::Node * IR::SwitchStatement::fromJSON(JSONLoader & json) { return new SwitchStatement(json); }
bool IR::SwitchStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::SwitchStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::SwitchStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 563 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::LoopStatement::getAnnotations() const { return annotations; }
#line 7044 "/root/p4c/build/ir/ir-generated.cpp"
#line 564 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::LoopStatement::getAnnotations() { return annotations; }
#line 7047 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::LoopStatement::operator==(IR::LoopStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && annotations == a.annotations;
    }
bool IR::LoopStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const LoopStatement &>(a_);
        return annotations.equiv(a.annotations);
    }
void IR::LoopStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    Statement::visit_children(v, n);
    annotations.visit_children(v, "annotations");
}
void IR::LoopStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Statement::visit_children(v, n);
    annotations.visit_children(v, "annotations");
}
void IR::LoopStatement::validate() const {
#line 7069 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate(); }
void IR::LoopStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json.emit("annotations", annotations);
}
IR::LoopStatement::LoopStatement(JSONLoader & json) : Statement(json) {
    json.load("annotations", annotations);
}
bool IR::LoopStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::LoopStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::LoopStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 572 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::ForStatement::getDeclByName(cstring name) const {
        return init.getDeclaration(name); }
#line 7085 "/root/p4c/build/ir/ir-generated.cpp"
#line 574 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::ForStatement::getDeclByName(std::string_view name) const {
        return init.getDeclaration(name); }
#line 7089 "/root/p4c/build/ir/ir-generated.cpp"
#line 576 "/root/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::ForStatement::getDeclarations() const {
        return init.getDeclarations(); }
#line 7093 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ForStatement::operator==(IR::ForStatement const & a) const {
        return LoopStatement::operator==(static_cast<const LoopStatement &>(a))
        && init == a.init
        && condition == a.condition
        && updates == a.updates
        && body == a.body;
    }
bool IR::ForStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!LoopStatement::equiv(a_)) return false;
        auto &a = static_cast<const ForStatement &>(a_);
        return init.equiv(a.init)
        && (condition ? a.condition ? condition->equiv(*a.condition) : false : a.condition == nullptr)
        && updates.equiv(a.updates)
        && (body ? a.body ? body->equiv(*a.body) : false : a.body == nullptr);
    }
void IR::ForStatement::validate() const {
#line 7111 "/root/p4c/build/ir/ir-generated.cpp"

        init.validate();
        CHECK_NULL(condition);
        updates.validate();
        CHECK_NULL(body); }
void IR::ForStatement::toJSON(JSONGenerator & json) const {
    LoopStatement::toJSON(json);
    json.emit("init", init);
    json.emit("condition", condition);
    json.emit("updates", updates);
    json.emit("body", body);
}
IR::ForStatement::ForStatement(JSONLoader & json) : LoopStatement(json) {
    json.load("init", init);
    json.load("condition", condition);
    json.load("updates", updates);
    json.load("body", body);
}
IR::Node * IR::ForStatement::fromJSON(JSONLoader & json) { return new ForStatement(json); }
bool IR::ForStatement::operator==(IR::LoopStatement const & a) const { return a == *this; }
bool IR::ForStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::ForStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::ForStatement::operator==(IR::Node const & a) const { return a == *this; }


#line 594 "/root/p4c/ir/ir.def"
IR::ForInStatement::ForInStatement(Util::SourceInfo si, const IR::Vector<IR::Annotation>* a, const IR::PathExpression* pe, const IR::Expression* c, const IR::Statement* b) : LoopStatement(si, *a), decl(nullptr), ref(pe), collection(c), body(b) {}
#line 7139 "/root/p4c/build/ir/ir-generated.cpp"
#line 596 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::ForInStatement::getDeclByName(cstring name) const {
        return decl && decl->name == name ? decl : nullptr; }
#line 7143 "/root/p4c/build/ir/ir-generated.cpp"
#line 598 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::ForInStatement::getDeclByName(std::string_view name) const {
        return decl && decl->name.name == name ? decl : nullptr; }
#line 7147 "/root/p4c/build/ir/ir-generated.cpp"
#line 600 "/root/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::ForInStatement::getDeclarations() const {
        if (decl) return new Util::SingleEnumerator<const IDeclaration *>(decl);
        return new Util::EmptyEnumerator<const IDeclaration *>(); }
#line 7152 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ForInStatement::operator==(IR::ForInStatement const & a) const {
        return LoopStatement::operator==(static_cast<const LoopStatement &>(a))
        && decl == a.decl
        && ref == a.ref
        && collection == a.collection
        && body == a.body;
    }
bool IR::ForInStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!LoopStatement::equiv(a_)) return false;
        auto &a = static_cast<const ForInStatement &>(a_);
        return (decl ? a.decl ? decl->equiv(*a.decl) : false : a.decl == nullptr)
        && (ref ? a.ref ? ref->equiv(*a.ref) : false : a.ref == nullptr)
        && (collection ? a.collection ? collection->equiv(*a.collection) : false : a.collection == nullptr)
        && (body ? a.body ? body->equiv(*a.body) : false : a.body == nullptr);
    }
void IR::ForInStatement::validate() const {
#line 7170 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(ref);
        CHECK_NULL(collection);
        CHECK_NULL(body); }
void IR::ForInStatement::toJSON(JSONGenerator & json) const {
    LoopStatement::toJSON(json);
    if (decl != nullptr) json.emit("decl", decl);
    json.emit("ref", ref);
    json.emit("collection", collection);
    json.emit("body", body);
}
IR::ForInStatement::ForInStatement(JSONLoader & json) : LoopStatement(json) {
    json.load("decl", decl);
    json.load("ref", ref);
    json.load("collection", collection);
    json.load("body", body);
}
IR::Node * IR::ForInStatement::fromJSON(JSONLoader & json) { return new ForInStatement(json); }
bool IR::ForInStatement::operator==(IR::LoopStatement const & a) const { return a == *this; }
bool IR::ForInStatement::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::ForInStatement::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::ForInStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 616 "/root/p4c/ir/ir.def"
const IR::ParameterList *IR::Function::getParameters() const {
        return type->parameters;
    }
#line 7197 "/root/p4c/build/ir/ir-generated.cpp"
#line 619 "/root/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Function::getDeclarations() const {
        return type->parameters->getDeclarations(); }
#line 7201 "/root/p4c/build/ir/ir-generated.cpp"
#line 621 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::Function::getDeclByName(cstring name) const {
        return type->parameters->getDeclByName(name); }
#line 7205 "/root/p4c/build/ir/ir-generated.cpp"
#line 623 "/root/p4c/ir/ir.def"
const IR::IDeclaration *IR::Function::getDeclByName(std::string_view name) const {
        return type->parameters->getDeclByName(name); }
#line 7209 "/root/p4c/build/ir/ir-generated.cpp"
#line 625 "/root/p4c/ir/ir.def"
std::vector<const IR::INamespace *> IR::Function::getNestedNamespaces() const {
        return { type->typeParameters }; }
#line 7213 "/root/p4c/build/ir/ir-generated.cpp"
#line 627 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> const & IR::Function::getAnnotations() const { return annotations; }
#line 7216 "/root/p4c/build/ir/ir-generated.cpp"
#line 628 "/root/p4c/ir/ir.def"
IR::Vector<IR::Annotation> & IR::Function::getAnnotations() { return annotations; }
#line 7219 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Function::operator==(IR::Function const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && type == a.type
        && body == a.body;
    }
bool IR::Function::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Function &>(a_);
        return annotations.equiv(a.annotations)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (body ? a.body ? body->equiv(*a.body) : false : a.body == nullptr);
    }
void IR::Function::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
    v.visit(body, "body");
}
void IR::Function::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
    v.visit(body, "body");
}
void IR::Function::validate() const {
#line 7249 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(type);
        CHECK_NULL(body); }
void IR::Function::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("type", type);
    json.emit("body", body);
}
IR::Function::Function(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
    json.load("body", body);
}
IR::Node * IR::Function::fromJSON(JSONLoader & json) { return new Function(json); }
bool IR::Function::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::Function::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::Function::operator==(IR::Node const & a) const { return a == *this; }
/// Node that evaluates to this block.
/// This is either a Declaration_Instance or a ConstructorCallExpression.
/// One value for each Node inside that evaluates to a compile-time constant.
/// This includes all constructor parameters, and all inner nested blocks.
/// value can be null for parameters which are optional
#line 660 "/root/p4c/ir/ir.def"
void IR::Block::visit_children(Visitor & v, char const * n) { (void)v; (void)n; }
#line 660 "/root/p4c/ir/ir.def"
void IR::Block::visit_children(Visitor & v, char const * n) const { (void)v; (void)n; }
#line 7278 "/root/p4c/build/ir/ir-generated.cpp"
#line 661 "/root/p4c/ir/ir.def"
IR::IDeclaration const * IR::Block::getContainer() const { return nullptr; }
#line 7281 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Block::operator==(IR::Block const & a) const {
        return this->typeId() == a.typeId()
        && node == a.node
        && constantValue == a.constantValue;
    }
bool IR::Block::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const Block &>(a_);
        return (node ? a.node ? node->equiv(*a.node) : false : a.node == nullptr)
        && constantValue == a.constantValue;
    }
void IR::Block::validate() const {
#line 7295 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(node); }
void IR::Block::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("node", node);
    json.emit("constantValue", constantValue);
}
IR::Block::Block(JSONLoader & json) : Node(json) {
    json.load("node", node);
    json.load("constantValue", constantValue);
}
bool IR::Block::operator==(IR::Node const & a) const { return a == *this; }
#line 666 "/root/p4c/ir/ir.def"
IR::IDeclaration const * IR::TableBlock::getContainer() const { return container; }
#line 7310 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::TableBlock::operator==(IR::TableBlock const & a) const {
        return Block::operator==(static_cast<const Block &>(a))
        && container == a.container;
    }
bool IR::TableBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Block::equiv(a_)) return false;
        auto &a = static_cast<const TableBlock &>(a_);
        return (container ? a.container ? container->equiv(*a.container) : false : a.container == nullptr);
    }
void IR::TableBlock::visit_children(Visitor & v, char const * n) {
    (void)n;
    Block::visit_children(v, n);
    v.visit(container, "container");
}
void IR::TableBlock::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Block::visit_children(v, n);
    v.visit(container, "container");
}
void IR::TableBlock::validate() const {
#line 7332 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(container); }
void IR::TableBlock::toJSON(JSONGenerator & json) const {
    Block::toJSON(json);
    json.emit("container", container);
}
IR::TableBlock::TableBlock(JSONLoader & json) : Block(json) {
    json.load("container", container);
}
IR::Node * IR::TableBlock::fromJSON(JSONLoader & json) { return new TableBlock(json); }
bool IR::TableBlock::operator==(IR::Block const & a) const { return a == *this; }
bool IR::TableBlock::operator==(IR::Node const & a) const { return a == *this; }

/// @return the argument that the given parameter was instantiated with.
/// It's a fatal error if no such parameter exists.
/// @return the argument that the given parameter was instantiated with, or
/// null if no such parameter exists.
bool IR::InstantiatedBlock::operator==(IR::InstantiatedBlock const & a) const {
        return Block::operator==(static_cast<const Block &>(a))
        && instanceType == a.instanceType;
    }
bool IR::InstantiatedBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Block::equiv(a_)) return false;
        auto &a = static_cast<const InstantiatedBlock &>(a_);
        return (instanceType ? a.instanceType ? instanceType->equiv(*a.instanceType) : false : a.instanceType == nullptr);
    }
void IR::InstantiatedBlock::visit_children(Visitor & v, char const * n) {
    (void)n;
    Block::visit_children(v, n);
    v.visit(instanceType, "instanceType");
}
void IR::InstantiatedBlock::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Block::visit_children(v, n);
    v.visit(instanceType, "instanceType");
}
void IR::InstantiatedBlock::validate() const {
#line 7371 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(instanceType); }
void IR::InstantiatedBlock::toJSON(JSONGenerator & json) const {
    Block::toJSON(json);
    json.emit("instanceType", instanceType);
}
IR::InstantiatedBlock::InstantiatedBlock(JSONLoader & json) : Block(json) {
    json.load("instanceType", instanceType);
}
bool IR::InstantiatedBlock::operator==(IR::Block const & a) const { return a == *this; }
bool IR::InstantiatedBlock::operator==(IR::Node const & a) const { return a == *this; }
#line 690 "/root/p4c/ir/ir.def"
const IR::ParameterList *IR::ParserBlock::getConstructorParameters() const {
        return container->constructorParams; }
#line 7386 "/root/p4c/build/ir/ir-generated.cpp"
#line 692 "/root/p4c/ir/ir.def"
cstring IR::ParserBlock::toString() const { return container->toString(); }
#line 7389 "/root/p4c/build/ir/ir-generated.cpp"
#line 693 "/root/p4c/ir/ir.def"
IR::ID IR::ParserBlock::getName() const { return container->getName(); }
#line 7392 "/root/p4c/build/ir/ir-generated.cpp"
#line 694 "/root/p4c/ir/ir.def"
IR::IDeclaration const * IR::ParserBlock::getContainer() const { return container; }
#line 7395 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ParserBlock::operator==(IR::ParserBlock const & a) const {
        return InstantiatedBlock::operator==(static_cast<const InstantiatedBlock &>(a))
        && container == a.container;
    }
bool IR::ParserBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!InstantiatedBlock::equiv(a_)) return false;
        auto &a = static_cast<const ParserBlock &>(a_);
        return (container ? a.container ? container->equiv(*a.container) : false : a.container == nullptr);
    }
void IR::ParserBlock::visit_children(Visitor & v, char const * n) {
    (void)n;
    InstantiatedBlock::visit_children(v, n);
    v.visit(container, "container");
}
void IR::ParserBlock::visit_children(Visitor & v, char const * n) const {
    (void)n;
    InstantiatedBlock::visit_children(v, n);
    v.visit(container, "container");
}
void IR::ParserBlock::validate() const {
#line 7417 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(container); }
void IR::ParserBlock::toJSON(JSONGenerator & json) const {
    InstantiatedBlock::toJSON(json);
    json.emit("container", container);
}
IR::ParserBlock::ParserBlock(JSONLoader & json) : InstantiatedBlock(json) {
    json.load("container", container);
}
IR::Node * IR::ParserBlock::fromJSON(JSONLoader & json) { return new ParserBlock(json); }
bool IR::ParserBlock::operator==(IR::InstantiatedBlock const & a) const { return a == *this; }
bool IR::ParserBlock::operator==(IR::Block const & a) const { return a == *this; }
bool IR::ParserBlock::operator==(IR::Node const & a) const { return a == *this; }
#line 700 "/root/p4c/ir/ir.def"
const IR::ParameterList *IR::ControlBlock::getConstructorParameters() const {
        return container->constructorParams; }
#line 7434 "/root/p4c/build/ir/ir-generated.cpp"
#line 702 "/root/p4c/ir/ir.def"
cstring IR::ControlBlock::toString() const { return container->toString(); }
#line 7437 "/root/p4c/build/ir/ir-generated.cpp"
#line 703 "/root/p4c/ir/ir.def"
IR::ID IR::ControlBlock::getName() const { return container->getName(); }
#line 7440 "/root/p4c/build/ir/ir-generated.cpp"
#line 704 "/root/p4c/ir/ir.def"
IR::IDeclaration const * IR::ControlBlock::getContainer() const { return container; }
#line 7443 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ControlBlock::operator==(IR::ControlBlock const & a) const {
        return InstantiatedBlock::operator==(static_cast<const InstantiatedBlock &>(a))
        && container == a.container;
    }
bool IR::ControlBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!InstantiatedBlock::equiv(a_)) return false;
        auto &a = static_cast<const ControlBlock &>(a_);
        return (container ? a.container ? container->equiv(*a.container) : false : a.container == nullptr);
    }
void IR::ControlBlock::visit_children(Visitor & v, char const * n) {
    (void)n;
    InstantiatedBlock::visit_children(v, n);
    v.visit(container, "container");
}
void IR::ControlBlock::visit_children(Visitor & v, char const * n) const {
    (void)n;
    InstantiatedBlock::visit_children(v, n);
    v.visit(container, "container");
}
void IR::ControlBlock::validate() const {
#line 7465 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(container); }
void IR::ControlBlock::toJSON(JSONGenerator & json) const {
    InstantiatedBlock::toJSON(json);
    json.emit("container", container);
}
IR::ControlBlock::ControlBlock(JSONLoader & json) : InstantiatedBlock(json) {
    json.load("container", container);
}
IR::Node * IR::ControlBlock::fromJSON(JSONLoader & json) { return new ControlBlock(json); }
bool IR::ControlBlock::operator==(IR::InstantiatedBlock const & a) const { return a == *this; }
bool IR::ControlBlock::operator==(IR::Block const & a) const { return a == *this; }
bool IR::ControlBlock::operator==(IR::Node const & a) const { return a == *this; }
#line 710 "/root/p4c/ir/ir.def"
const IR::ParameterList *IR::PackageBlock::getConstructorParameters() const { return type->constructorParams; }
#line 7481 "/root/p4c/build/ir/ir-generated.cpp"
#line 711 "/root/p4c/ir/ir.def"
cstring IR::PackageBlock::toString() const { return type->toString(); }
#line 7484 "/root/p4c/build/ir/ir-generated.cpp"
#line 712 "/root/p4c/ir/ir.def"
IR::ID IR::PackageBlock::getName() const { return type->getName(); }
#line 7487 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::PackageBlock::operator==(IR::PackageBlock const & a) const {
        return InstantiatedBlock::operator==(static_cast<const InstantiatedBlock &>(a))
        && type == a.type;
    }
bool IR::PackageBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!InstantiatedBlock::equiv(a_)) return false;
        auto &a = static_cast<const PackageBlock &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::PackageBlock::visit_children(Visitor & v, char const * n) {
    (void)n;
    InstantiatedBlock::visit_children(v, n);
    v.visit(type, "type");
}
void IR::PackageBlock::visit_children(Visitor & v, char const * n) const {
    (void)n;
    InstantiatedBlock::visit_children(v, n);
    v.visit(type, "type");
}
void IR::PackageBlock::validate() const {
#line 7509 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type); }
void IR::PackageBlock::toJSON(JSONGenerator & json) const {
    InstantiatedBlock::toJSON(json);
    json.emit("type", type);
}
IR::PackageBlock::PackageBlock(JSONLoader & json) : InstantiatedBlock(json) {
    json.load("type", type);
}
IR::Node * IR::PackageBlock::fromJSON(JSONLoader & json) { return new PackageBlock(json); }
bool IR::PackageBlock::operator==(IR::InstantiatedBlock const & a) const { return a == *this; }
bool IR::PackageBlock::operator==(IR::Block const & a) const { return a == *this; }
bool IR::PackageBlock::operator==(IR::Node const & a) const { return a == *this; }

#line 719 "/root/p4c/ir/ir.def"
const IR::ParameterList *IR::ExternBlock::getConstructorParameters() const {
        return constructor->type->parameters; }
#line 7527 "/root/p4c/build/ir/ir-generated.cpp"
#line 721 "/root/p4c/ir/ir.def"
cstring IR::ExternBlock::toString() const { return type->toString(); }
#line 7530 "/root/p4c/build/ir/ir-generated.cpp"
#line 722 "/root/p4c/ir/ir.def"
IR::ID IR::ExternBlock::getName() const { return type->getName(); }
#line 7533 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ExternBlock::operator==(IR::ExternBlock const & a) const {
        return InstantiatedBlock::operator==(static_cast<const InstantiatedBlock &>(a))
        && type == a.type
        && constructor == a.constructor;
    }
bool IR::ExternBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!InstantiatedBlock::equiv(a_)) return false;
        auto &a = static_cast<const ExternBlock &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (constructor ? a.constructor ? constructor->equiv(*a.constructor) : false : a.constructor == nullptr);
    }
void IR::ExternBlock::visit_children(Visitor & v, char const * n) {
    (void)n;
    InstantiatedBlock::visit_children(v, n);
    v.visit(type, "type");
    v.visit(constructor, "constructor");
}
void IR::ExternBlock::visit_children(Visitor & v, char const * n) const {
    (void)n;
    InstantiatedBlock::visit_children(v, n);
    v.visit(type, "type");
    v.visit(constructor, "constructor");
}
void IR::ExternBlock::validate() const {
#line 7559 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(constructor); }
void IR::ExternBlock::toJSON(JSONGenerator & json) const {
    InstantiatedBlock::toJSON(json);
    json.emit("type", type);
    json.emit("constructor", constructor);
}
IR::ExternBlock::ExternBlock(JSONLoader & json) : InstantiatedBlock(json) {
    json.load("type", type);
    json.load("constructor", constructor);
}
IR::Node * IR::ExternBlock::fromJSON(JSONLoader & json) { return new ExternBlock(json); }
bool IR::ExternBlock::operator==(IR::InstantiatedBlock const & a) const { return a == *this; }
bool IR::ExternBlock::operator==(IR::Block const & a) const { return a == *this; }
bool IR::ExternBlock::operator==(IR::Node const & a) const { return a == *this; }
#line 728 "/root/p4c/ir/ir.def"
const IR::P4Program *IR::ToplevelBlock::getProgram() const { return node->to<IR::P4Program>(); }
#line 7578 "/root/p4c/build/ir/ir-generated.cpp"
#line 730 "/root/p4c/ir/ir.def"
IR::ID IR::ToplevelBlock::getName() const { return "main"; }
#line 7581 "/root/p4c/build/ir/ir-generated.cpp"
#line 732 "/root/p4c/ir/ir.def"
void IR::ToplevelBlock::validate() const {
#line 7584 "/root/p4c/build/ir/ir-generated.cpp"

#line 732 "/root/p4c/ir/ir.def"
{ BUG_CHECK(node->is<IR::P4Program>(), "%1%: expected a P4Program", node); } }
#line 7588 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ToplevelBlock::operator==(IR::ToplevelBlock const & a) const {
        return Block::operator==(static_cast<const Block &>(a));
    }
bool IR::ToplevelBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Block::equiv(a_)) return false;
        return true;
    }
void IR::ToplevelBlock::toJSON(JSONGenerator & json) const {
    Block::toJSON(json);
}
IR::ToplevelBlock::ToplevelBlock(JSONLoader & json) : Block(json) {
}
IR::Node * IR::ToplevelBlock::fromJSON(JSONLoader & json) { return new ToplevelBlock(json); }
bool IR::ToplevelBlock::operator==(IR::Block const & a) const { return a == *this; }
bool IR::ToplevelBlock::operator==(IR::Node const & a) const { return a == *this; }
/** @} */
/* end group irdefs */
/* -*-C++-*- */
/*
  This file contains IR classes needed just for the P4 v1.0/v1.1 front-end.
*/
/** \addtogroup irdefs
  * @{
  */
#line 51 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::Type_Block::toString() const { return "block"_cs; }
#line 7616 "/root/p4c/build/ir/ir-generated.cpp"
#line 53 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::Type_Block::dbprint(std::ostream & out) const { out << "block"; }
#line 7619 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Block::operator==(IR::Type_Block const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Block::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Block::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Block::Type_Block(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Block::fromJSON(JSONLoader & json) { return new Type_Block(json); }
bool IR::Type_Block::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_Block::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Block::operator==(IR::Node const & a) const { return a == *this; }
#line 56 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::Type_Counter::toString() const { return "counter"_cs; }
#line 7639 "/root/p4c/build/ir/ir-generated.cpp"
#line 58 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::Type_Counter::dbprint(std::ostream & out) const { out << "counter"; }
#line 7642 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Counter::operator==(IR::Type_Counter const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Counter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Counter::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Counter::Type_Counter(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Counter::fromJSON(JSONLoader & json) { return new Type_Counter(json); }
bool IR::Type_Counter::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_Counter::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Counter::operator==(IR::Node const & a) const { return a == *this; }
#line 61 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::Type_Expression::toString() const { return "expression"_cs; }
#line 7662 "/root/p4c/build/ir/ir-generated.cpp"
#line 63 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::Type_Expression::dbprint(std::ostream & out) const { out << "expression"; }
#line 7665 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Expression::operator==(IR::Type_Expression const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Expression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Expression::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Expression::Type_Expression(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Expression::fromJSON(JSONLoader & json) { return new Type_Expression(json); }
bool IR::Type_Expression::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_Expression::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Expression::operator==(IR::Node const & a) const { return a == *this; }
#line 66 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::Type_FieldListCalculation::toString() const { return "field_list_calculation"_cs; }
#line 7685 "/root/p4c/build/ir/ir-generated.cpp"
#line 68 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::Type_FieldListCalculation::dbprint(std::ostream & out) const { out << "field_list_calculation"; }
#line 7688 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_FieldListCalculation::operator==(IR::Type_FieldListCalculation const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_FieldListCalculation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_FieldListCalculation::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_FieldListCalculation::Type_FieldListCalculation(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_FieldListCalculation::fromJSON(JSONLoader & json) { return new Type_FieldListCalculation(json); }
bool IR::Type_FieldListCalculation::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_FieldListCalculation::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_FieldListCalculation::operator==(IR::Node const & a) const { return a == *this; }
#line 71 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::Type_Meter::toString() const { return "meter"_cs; }
#line 7708 "/root/p4c/build/ir/ir-generated.cpp"
#line 73 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::Type_Meter::dbprint(std::ostream & out) const { out << "meter"; }
#line 7711 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Meter::operator==(IR::Type_Meter const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Meter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Meter::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Meter::Type_Meter(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Meter::fromJSON(JSONLoader & json) { return new Type_Meter(json); }
bool IR::Type_Meter::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_Meter::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Meter::operator==(IR::Node const & a) const { return a == *this; }
#line 76 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::Type_Register::toString() const { return "register"_cs; }
#line 7731 "/root/p4c/build/ir/ir-generated.cpp"
#line 78 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::Type_Register::dbprint(std::ostream & out) const { out << "register"; }
#line 7734 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Register::operator==(IR::Type_Register const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Register::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Register::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Register::Type_Register(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Register::fromJSON(JSONLoader & json) { return new Type_Register(json); }
bool IR::Type_Register::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_Register::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_Register::operator==(IR::Node const & a) const { return a == *this; }
#line 81 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::Type_AnyTable::toString() const { return "table"_cs; }
#line 7754 "/root/p4c/build/ir/ir-generated.cpp"
#line 83 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::Type_AnyTable::dbprint(std::ostream & out) const { out << "table"; }
#line 7757 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Type_AnyTable::operator==(IR::Type_AnyTable const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_AnyTable::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_AnyTable::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_AnyTable::Type_AnyTable(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_AnyTable::fromJSON(JSONLoader & json) { return new Type_AnyTable(json); }
bool IR::Type_AnyTable::operator==(IR::Type_Base const & a) const { return a == *this; }
bool IR::Type_AnyTable::operator==(IR::Type const & a) const { return a == *this; }
bool IR::Type_AnyTable::operator==(IR::Node const & a) const { return a == *this; }
#line 92 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> const & IR::HeaderOrMetadata::getAnnotations() const { return annotations; }
#line 7777 "/root/p4c/build/ir/ir-generated.cpp"
#line 93 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> & IR::HeaderOrMetadata::getAnnotations() { return annotations; }
#line 7780 "/root/p4c/build/ir/ir-generated.cpp"
#line 94 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::HeaderOrMetadata::HeaderOrMetadata(IR::ID n, const IR::Type_StructLike* t) : type_name(t->name), name(n), type(t) {}
#line 7783 "/root/p4c/build/ir/ir-generated.cpp"
#line 96 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::HeaderOrMetadata::dbprint(std::ostream & out) const { out << type_name << ' ' << name; }
#line 7786 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::HeaderOrMetadata::operator==(IR::HeaderOrMetadata const & a) const {
        return this->typeId() == a.typeId()
        && type_name == a.type_name
        && name == a.name
        && annotations == a.annotations
        && type == a.type;
    }
bool IR::HeaderOrMetadata::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const HeaderOrMetadata &>(a_);
        return type_name == a.type_name
        && name == a.name
        && annotations.equiv(a.annotations)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::HeaderOrMetadata::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
}
void IR::HeaderOrMetadata::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(type, "type");
}
void IR::HeaderOrMetadata::validate() const {
#line 7816 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate(); }
void IR::HeaderOrMetadata::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " type_name=" << type_name;
        out << " name=" << name;
}
void IR::HeaderOrMetadata::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("type_name", type_name);
    json.emit("name", name);
    json.emit("annotations", annotations);
    if (type != nullptr) json.emit("type", type);
}
IR::HeaderOrMetadata::HeaderOrMetadata(JSONLoader & json) : Node(json) {
    json.load("type_name", type_name);
    json.load("name", name);
    json.load("annotations", annotations);
    json.load("type", type);
}
bool IR::HeaderOrMetadata::operator==(IR::Node const & a) const { return a == *this; }
#line 100 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Header::Header(IR::ID n, const IR::Type_Header* t) : HeaderOrMetadata(n, t) {}
#line 7840 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Header::operator==(IR::Header const & a) const {
        return HeaderOrMetadata::operator==(static_cast<const HeaderOrMetadata &>(a));
    }
bool IR::Header::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderOrMetadata::equiv(a_)) return false;
        return true;
    }
void IR::Header::toJSON(JSONGenerator & json) const {
    HeaderOrMetadata::toJSON(json);
}
IR::Header::Header(JSONLoader & json) : HeaderOrMetadata(json) {
}
IR::Node * IR::Header::fromJSON(JSONLoader & json) { return new Header(json); }
bool IR::Header::operator==(IR::HeaderOrMetadata const & a) const { return a == *this; }
bool IR::Header::operator==(IR::Node const & a) const { return a == *this; }
#line 106 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::HeaderStack::HeaderStack(IR::ID n, const IR::Type_Header* t, int sz) : HeaderOrMetadata(n, t), size(sz) {}
#line 7859 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::HeaderStack::operator==(IR::HeaderStack const & a) const {
        return HeaderOrMetadata::operator==(static_cast<const HeaderOrMetadata &>(a))
        && size == a.size;
    }
bool IR::HeaderStack::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderOrMetadata::equiv(a_)) return false;
        auto &a = static_cast<const HeaderStack &>(a_);
        return size == a.size;
    }
void IR::HeaderStack::dump_fields(std::ostream & out) const {
    HeaderOrMetadata::dump_fields(out);
        out << " size=" << size;
}
void IR::HeaderStack::toJSON(JSONGenerator & json) const {
    HeaderOrMetadata::toJSON(json);
    json.emit("size", size);
}
IR::HeaderStack::HeaderStack(JSONLoader & json) : HeaderOrMetadata(json) {
    json.load("size", size);
}
IR::Node * IR::HeaderStack::fromJSON(JSONLoader & json) { return new HeaderStack(json); }
bool IR::HeaderStack::operator==(IR::HeaderOrMetadata const & a) const { return a == *this; }
bool IR::HeaderStack::operator==(IR::Node const & a) const { return a == *this; }
#line 115 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::v1HeaderType::v1HeaderType(IR::Type_Struct const * m, IR::Type_Header const * h) : v1HeaderType(Util::SourceInfo(), m->name, m, h) {}
#line 7886 "/root/p4c/build/ir/ir-generated.cpp"
#line 117 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::v1HeaderType::dbprint(std::ostream & out) const { out << "header " << name; }
#line 7889 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::v1HeaderType::operator==(IR::v1HeaderType const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && as_metadata == a.as_metadata
        && as_header == a.as_header;
    }
bool IR::v1HeaderType::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const v1HeaderType &>(a_);
        return name == a.name
        && (as_metadata ? a.as_metadata ? as_metadata->equiv(*a.as_metadata) : false : a.as_metadata == nullptr)
        && (as_header ? a.as_header ? as_header->equiv(*a.as_header) : false : a.as_header == nullptr);
    }
void IR::v1HeaderType::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(as_metadata, "as_metadata");
    v.visit(as_header, "as_header");
}
void IR::v1HeaderType::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(as_metadata, "as_metadata");
    v.visit(as_header, "as_header");
}
void IR::v1HeaderType::validate() const {
#line 7917 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(as_metadata); }
void IR::v1HeaderType::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::v1HeaderType::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    json.emit("as_metadata", as_metadata);
    if (as_header != nullptr) json.emit("as_header", as_header);
}
IR::v1HeaderType::v1HeaderType(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("as_metadata", as_metadata);
    json.load("as_header", as_header);
}
IR::Node * IR::v1HeaderType::fromJSON(JSONLoader & json) { return new v1HeaderType(json); }
bool IR::v1HeaderType::operator==(IR::Node const & a) const { return a == *this; }
#line 121 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Metadata::Metadata(IR::ID n, const IR::Type_StructLike* t) : HeaderOrMetadata(n, t) {}
#line 7939 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Metadata::operator==(IR::Metadata const & a) const {
        return HeaderOrMetadata::operator==(static_cast<const HeaderOrMetadata &>(a));
    }
bool IR::Metadata::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderOrMetadata::equiv(a_)) return false;
        return true;
    }
void IR::Metadata::toJSON(JSONGenerator & json) const {
    HeaderOrMetadata::toJSON(json);
}
IR::Metadata::Metadata(JSONLoader & json) : HeaderOrMetadata(json) {
}
IR::Node * IR::Metadata::fromJSON(JSONLoader & json) { return new Metadata(json); }
bool IR::Metadata::operator==(IR::HeaderOrMetadata const & a) const { return a == *this; }
bool IR::Metadata::operator==(IR::Node const & a) const { return a == *this; }
bool IR::HeaderRef::operator==(IR::HeaderRef const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::HeaderRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::HeaderRef::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::HeaderRef::HeaderRef(JSONLoader & json) : Expression(json) {
}
bool IR::HeaderRef::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::HeaderRef::operator==(IR::Node const & a) const { return a == *this; }
#line 132 "/root/p4c/frontends/p4-14/ir-v1.def"
const IR::HeaderOrMetadata *IR::ConcreteHeaderRef::baseRef() const { return ref; }
#line 7973 "/root/p4c/build/ir/ir-generated.cpp"
#line 133 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::ConcreteHeaderRef::toString() const { return ref->name; }
#line 7976 "/root/p4c/build/ir/ir-generated.cpp"
#line 134 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::ConcreteHeaderRef::dbprint(std::ostream & out) const { out << ref->name; }
#line 7979 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ConcreteHeaderRef::operator==(IR::ConcreteHeaderRef const & a) const {
        return HeaderRef::operator==(static_cast<const HeaderRef &>(a))
        && ref == a.ref;
    }
bool IR::ConcreteHeaderRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderRef::equiv(a_)) return false;
        auto &a = static_cast<const ConcreteHeaderRef &>(a_);
        return (ref ? a.ref ? ref->equiv(*a.ref) : false : a.ref == nullptr);
    }
void IR::ConcreteHeaderRef::visit_children(Visitor & v, char const * n) {
    (void)n;
    HeaderRef::visit_children(v, n);
    v.visit(ref, "ref");
}
void IR::ConcreteHeaderRef::visit_children(Visitor & v, char const * n) const {
    (void)n;
    HeaderRef::visit_children(v, n);
    v.visit(ref, "ref");
}
void IR::ConcreteHeaderRef::validate() const {
#line 8001 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(ref); }
void IR::ConcreteHeaderRef::toJSON(JSONGenerator & json) const {
    HeaderRef::toJSON(json);
    json.emit("ref", ref);
}
IR::ConcreteHeaderRef::ConcreteHeaderRef(JSONLoader & json) : HeaderRef(json) {
    json.load("ref", ref);
}
IR::Node * IR::ConcreteHeaderRef::fromJSON(JSONLoader & json) { return new ConcreteHeaderRef(json); }
bool IR::ConcreteHeaderRef::operator==(IR::HeaderRef const & a) const { return a == *this; }
bool IR::ConcreteHeaderRef::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::ConcreteHeaderRef::operator==(IR::Node const & a) const { return a == *this; }
#line 144 "/root/p4c/frontends/p4-14/ir-v1.def"
const IR::Expression *IR::HeaderStackItemRef::base() const { return base_; }
#line 8017 "/root/p4c/build/ir/ir-generated.cpp"
/// Returns `nullptr` if the base is not `HeaderOrMetadata` (e.g. when this
/// is stack ref of an expression such as `lookahead`).
#line 147 "/root/p4c/frontends/p4-14/ir-v1.def"
const IR::HeaderOrMetadata *IR::HeaderStackItemRef::baseRef() const {
        auto hdrRef = base_->to<HeaderRef>();
        return hdrRef ? hdrRef->baseRef() : nullptr;
    }
#line 8025 "/root/p4c/build/ir/ir-generated.cpp"
#line 151 "/root/p4c/frontends/p4-14/ir-v1.def"
const IR::Expression *IR::HeaderStackItemRef::index() const { return index_; }
#line 8028 "/root/p4c/build/ir/ir-generated.cpp"
#line 152 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::HeaderStackItemRef::set_base(const IR::Expression* b) { base_ = b; }
#line 8031 "/root/p4c/build/ir/ir-generated.cpp"
#line 153 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::HeaderStackItemRef::toString() const { return base_->toString() + "[" + index_->toString() + "]"; }
#line 8034 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::HeaderStackItemRef::operator==(IR::HeaderStackItemRef const & a) const {
        return HeaderRef::operator==(static_cast<const HeaderRef &>(a))
        && base_ == a.base_
        && index_ == a.index_;
    }
bool IR::HeaderStackItemRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderRef::equiv(a_)) return false;
        auto &a = static_cast<const HeaderStackItemRef &>(a_);
        return (base_ ? a.base_ ? base_->equiv(*a.base_) : false : a.base_ == nullptr)
        && (index_ ? a.index_ ? index_->equiv(*a.index_) : false : a.index_ == nullptr);
    }
void IR::HeaderStackItemRef::visit_children(Visitor & v, char const * n) {
    (void)n;
    HeaderRef::visit_children(v, n);
    v.visit(base_, "base_");
    v.visit(index_, "index_");
}
void IR::HeaderStackItemRef::visit_children(Visitor & v, char const * n) const {
    (void)n;
    HeaderRef::visit_children(v, n);
    v.visit(base_, "base_");
    v.visit(index_, "index_");
}
void IR::HeaderStackItemRef::validate() const {
#line 8060 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(base_);
        CHECK_NULL(index_); }
void IR::HeaderStackItemRef::toJSON(JSONGenerator & json) const {
    HeaderRef::toJSON(json);
    json.emit("base_", base_);
    json.emit("index_", index_);
}
IR::HeaderStackItemRef::HeaderStackItemRef(JSONLoader & json) : HeaderRef(json) {
    json.load("base_", base_);
    json.load("index_", index_);
}
IR::Node * IR::HeaderStackItemRef::fromJSON(JSONLoader & json) { return new HeaderStackItemRef(json); }
bool IR::HeaderStackItemRef::operator==(IR::HeaderRef const & a) const { return a == *this; }
bool IR::HeaderStackItemRef::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::HeaderStackItemRef::operator==(IR::Node const & a) const { return a == *this; }
#line 160 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::If::visit_children(Visitor & v, char const * n) {
        v.visit(pred, "pred");
        SplitFlowVisit<Vector<Expression>>(v, ifTrue, ifFalse).run_visit();
        Expression::visit_children(v, n);
    }
#line 160 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::If::visit_children(Visitor & v, char const * n) const {
        v.visit(pred, "pred");
        SplitFlowVisit<Vector<Expression>>(v, ifTrue, ifFalse).run_visit();
        Expression::visit_children(v, n);
    }
#line 8089 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::If::operator==(IR::If const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && pred == a.pred
        && ifTrue == a.ifTrue
        && ifFalse == a.ifFalse;
    }
bool IR::If::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const If &>(a_);
        return (pred ? a.pred ? pred->equiv(*a.pred) : false : a.pred == nullptr)
        && (ifTrue ? a.ifTrue ? ifTrue->equiv(*a.ifTrue) : false : a.ifTrue == nullptr)
        && (ifFalse ? a.ifFalse ? ifFalse->equiv(*a.ifFalse) : false : a.ifFalse == nullptr);
    }
void IR::If::validate() const {
#line 8105 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(pred); }
void IR::If::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("pred", pred);
    if (ifTrue != nullptr) json.emit("ifTrue", ifTrue);
    if (ifFalse != nullptr) json.emit("ifFalse", ifFalse);
}
IR::If::If(JSONLoader & json) : Expression(json) {
    json.load("pred", pred);
    json.load("ifTrue", ifTrue);
    json.load("ifFalse", ifFalse);
}
IR::Node * IR::If::fromJSON(JSONLoader & json) { return new If(json); }
bool IR::If::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::If::operator==(IR::Node const & a) const { return a == *this; }
#line 172 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::NamedCond::NamedCond(IR::If const & i) : If(i), name(unique_name()) {}
#line 8124 "/root/p4c/build/ir/ir-generated.cpp"
#line 173 "/root/p4c/frontends/p4-14/ir-v1.def"
bool IR::NamedCond::operator==(IR::NamedCond const & a) const { return If::operator==(static_cast<const If &>(a)); }
#line 8127 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::NamedCond::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!If::equiv(a_)) return false;
        auto &a = static_cast<const NamedCond &>(a_);
        return name == a.name;
    }
void IR::NamedCond::dump_fields(std::ostream & out) const {
    If::dump_fields(out);
        out << " name=" << name;
}
void IR::NamedCond::toJSON(JSONGenerator & json) const {
    If::toJSON(json);
    json.emit("name", name);
}
IR::NamedCond::NamedCond(JSONLoader & json) : If(json) {
    json.load("name", name);
}
IR::Node * IR::NamedCond::fromJSON(JSONLoader & json) { return new NamedCond(json); }
bool IR::NamedCond::operator==(IR::If const & a) const { return a == *this; }
bool IR::NamedCond::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::NamedCond::operator==(IR::Node const & a) const { return a == *this; }


bool IR::Apply::operator==(IR::Apply const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && name == a.name
        && actions == a.actions
        && position == a.position;
    }
bool IR::Apply::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const Apply &>(a_);
        return name == a.name
        && actions.equiv(a.actions)
        && position.equiv(a.position);
    }
void IR::Apply::visit_children(Visitor & v, char const * n) {
    (void)n;
    Expression::visit_children(v, n);
    actions.visit_children(v, "actions");
    position.visit_children(v, "position");
}
void IR::Apply::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Expression::visit_children(v, n);
    actions.visit_children(v, "actions");
    position.visit_children(v, "position");
}
void IR::Apply::validate() const {
#line 8178 "/root/p4c/build/ir/ir-generated.cpp"

        actions.validate();
        position.validate(); }
void IR::Apply::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " name=" << name;
}
void IR::Apply::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("name", name);
    json.emit("actions", actions);
    json.emit("position", position);
}
IR::Apply::Apply(JSONLoader & json) : Expression(json) {
    json.load("name", name);
    json.load("actions", actions);
    json.load("position", position);
}
IR::Node * IR::Apply::fromJSON(JSONLoader & json) { return new Apply(json); }
bool IR::Apply::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Apply::operator==(IR::Node const & a) const { return a == *this; }
#line 190 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Primitive::Primitive(cstring n, const IR::Vector<IR::Expression>* l) : name(n) {
        if (l) for (auto e : *l) operands.push_back(e); }
#line 8203 "/root/p4c/build/ir/ir-generated.cpp"
#line 192 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Vector<IR::Expression>* l) : Operation(si), name(n) {
        if (l) for (auto e : *l) operands.push_back(e); }
#line 8207 "/root/p4c/build/ir/ir-generated.cpp"
#line 194 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Primitive::Primitive(cstring n, const IR::Expression* a1) : name(n) {
        operands.push_back(a1); }
#line 8211 "/root/p4c/build/ir/ir-generated.cpp"
#line 196 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1) : Operation(si), name(n) {
        operands.push_back(a1); }
#line 8215 "/root/p4c/build/ir/ir-generated.cpp"
#line 198 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Primitive::Primitive(cstring n, const IR::Expression* a1, const IR::Expression* a2) : name(n) {
        operands.push_back(a1); operands.push_back(a2); }
#line 8219 "/root/p4c/build/ir/ir-generated.cpp"
#line 200 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Expression* a2) : Operation(si), name(n) {
        operands.push_back(a1); operands.push_back(a2); }
#line 8223 "/root/p4c/build/ir/ir-generated.cpp"
#line 203 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Primitive::Primitive(cstring n, const IR::Expression* a1, const IR::Vector<IR::Expression>* a2) : name(n) {
        operands.push_back(a1);
        if (a2) for (auto e : *a2) operands.push_back(e); }
#line 8228 "/root/p4c/build/ir/ir-generated.cpp"
#line 206 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Vector<IR::Expression>* a2) : Operation(si), name(n) {
        operands.push_back(a1);
        if (a2) for (auto e : *a2) operands.push_back(e); }
#line 8233 "/root/p4c/build/ir/ir-generated.cpp"
#line 210 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Primitive::Primitive(cstring n, const IR::Expression* a1, const IR::Expression* a2, const IR::Expression* a3) : name(n) {
        operands.push_back(a1); operands.push_back(a2); operands.push_back(a3); }
#line 8237 "/root/p4c/build/ir/ir-generated.cpp"
#line 212 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Expression* a2, const IR::Expression* a3) : Operation(si), name(n) {
        operands.push_back(a1); operands.push_back(a2); operands.push_back(a3); }
#line 8241 "/root/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(Primitive, , )
bool IR::Primitive::operator==(IR::Primitive const & a) const {
        return Operation::operator==(static_cast<const Operation &>(a))
        && name == a.name
        && operands == a.operands;
    }
bool IR::Primitive::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation::equiv(a_)) return false;
        auto &a = static_cast<const Primitive &>(a_);
        return name == a.name
        && operands.equiv(a.operands);
    }
void IR::Primitive::visit_children(Visitor & v, char const * n) {
    (void)n;
    Operation::visit_children(v, n);
    operands.visit_children(v, "operands");
}
void IR::Primitive::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Operation::visit_children(v, n);
    operands.visit_children(v, "operands");
}
void IR::Primitive::validate() const {
#line 8266 "/root/p4c/build/ir/ir-generated.cpp"

        operands.validate(); }
void IR::Primitive::dump_fields(std::ostream & out) const {
    Operation::dump_fields(out);
        out << " name=" << name;
}
void IR::Primitive::toJSON(JSONGenerator & json) const {
    Operation::toJSON(json);
    json.emit("name", name);
    json.emit("operands", operands);
}
IR::Primitive::Primitive(JSONLoader & json) : Operation(json) {
    json.load("name", name);
    json.load("operands", operands);
}
IR::Node * IR::Primitive::fromJSON(JSONLoader & json) { return new Primitive(json); }
bool IR::Primitive::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::Primitive::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::Primitive::operator==(IR::Node const & a) const { return a == *this; }
#line 229 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> const & IR::FieldList::getAnnotations() const { return annotations; }
#line 8288 "/root/p4c/build/ir/ir-generated.cpp"
#line 230 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> & IR::FieldList::getAnnotations() { return annotations; }
#line 8291 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::FieldList::operator==(IR::FieldList const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && payload == a.payload
        && annotations == a.annotations
        && fields == a.fields;
    }
bool IR::FieldList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const FieldList &>(a_);
        return name == a.name
        && payload == a.payload
        && annotations.equiv(a.annotations)
        && fields.equiv(a.fields);
    }
void IR::FieldList::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    fields.visit_children(v, "fields");
}
void IR::FieldList::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    fields.visit_children(v, "fields");
}
void IR::FieldList::validate() const {
#line 8321 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        fields.validate(); }
void IR::FieldList::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " payload=" << payload;
}
void IR::FieldList::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    json.emit("payload", payload);
    json.emit("annotations", annotations);
    json.emit("fields", fields);
}
IR::FieldList::FieldList(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("payload", payload);
    json.load("annotations", annotations);
    json.load("fields", fields);
}
IR::Node * IR::FieldList::fromJSON(JSONLoader & json) { return new FieldList(json); }
bool IR::FieldList::operator==(IR::Node const & a) const { return a == *this; }
#line 240 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> const & IR::FieldListCalculation::getAnnotations() const { return annotations; }
#line 8347 "/root/p4c/build/ir/ir-generated.cpp"
#line 241 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> & IR::FieldListCalculation::getAnnotations() { return annotations; }
#line 8350 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::FieldListCalculation::operator==(IR::FieldListCalculation const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && input == a.input
        && input_fields == a.input_fields
        && algorithm == a.algorithm
        && output_width == a.output_width
        && annotations == a.annotations;
    }
bool IR::FieldListCalculation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const FieldListCalculation &>(a_);
        return name == a.name
        && (input ? a.input ? input->equiv(*a.input) : false : a.input == nullptr)
        && (input_fields ? a.input_fields ? input_fields->equiv(*a.input_fields) : false : a.input_fields == nullptr)
        && (algorithm ? a.algorithm ? algorithm->equiv(*a.algorithm) : false : a.algorithm == nullptr)
        && output_width == a.output_width
        && annotations.equiv(a.annotations);
    }
void IR::FieldListCalculation::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(input, "input");
    v.visit(input_fields, "input_fields");
    v.visit(algorithm, "algorithm");
    annotations.visit_children(v, "annotations");
}
void IR::FieldListCalculation::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(input, "input");
    v.visit(input_fields, "input_fields");
    v.visit(algorithm, "algorithm");
    annotations.visit_children(v, "annotations");
}
void IR::FieldListCalculation::validate() const {
#line 8388 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate(); }
void IR::FieldListCalculation::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " output_width=" << output_width;
}
void IR::FieldListCalculation::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    if (input != nullptr) json.emit("input", input);
    if (input_fields != nullptr) json.emit("input_fields", input_fields);
    if (algorithm != nullptr) json.emit("algorithm", algorithm);
    json.emit("output_width", output_width);
    json.emit("annotations", annotations);
}
IR::FieldListCalculation::FieldListCalculation(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("input", input);
    json.load("input_fields", input_fields);
    json.load("algorithm", algorithm);
    json.load("output_width", output_width);
    json.load("annotations", annotations);
}
IR::Node * IR::FieldListCalculation::fromJSON(JSONLoader & json) { return new FieldListCalculation(json); }
bool IR::FieldListCalculation::operator==(IR::Node const & a) const { return a == *this; }
#line 251 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::CalculatedField::update_or_verify::update_or_verify() { }
#line 8417 "/root/p4c/build/ir/ir-generated.cpp"

bool IR::CalculatedField::update_or_verify::operator==(IR::CalculatedField::update_or_verify const & a) const {
        return update == a.update
        && name == a.name
        && cond == a.cond;
    }
void IR::CalculatedField::update_or_verify::toJSON(JSONGenerator & json) const {
    json.emit("update", update);
    json.emit("name", name);
    json.emit("cond", cond);
}
IR::CalculatedField::update_or_verify::update_or_verify(JSONLoader & json)  {
    json.load("update", update);
    json.load("name", name);
    json.load("cond", cond);
}
IR::CalculatedField::update_or_verify * IR::CalculatedField::update_or_verify::fromJSON(JSONLoader & json) { return new update_or_verify(json); }
#line 255 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> const & IR::CalculatedField::getAnnotations() const { return annotations; }
#line 8437 "/root/p4c/build/ir/ir-generated.cpp"
#line 256 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> & IR::CalculatedField::getAnnotations() { return annotations; }
#line 8440 "/root/p4c/build/ir/ir-generated.cpp"
#line 257 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::CalculatedField::visit_children(Visitor & v, char const * n) {
        (void)n;
        v.visit(field, "field");
        for (auto &s : specs) v.visit(s.cond, s.name.name.c_str());
        v.visit(annotations, "annotations"); }
#line 257 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::CalculatedField::visit_children(Visitor & v, char const * n) const {
        (void)n;
        v.visit(field, "field");
        for (auto &s : specs) v.visit(s.cond, s.name.name.c_str());
        v.visit(annotations, "annotations"); }
#line 8453 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::CalculatedField::operator==(IR::CalculatedField const & a) const {
        return this->typeId() == a.typeId()
        && field == a.field
        && specs == a.specs
        && annotations == a.annotations;
    }
bool IR::CalculatedField::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const CalculatedField &>(a_);
        return (field ? a.field ? field->equiv(*a.field) : false : a.field == nullptr)
        && specs == a.specs
        && annotations.equiv(a.annotations);
    }
void IR::CalculatedField::validate() const {
#line 8469 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate(); }
void IR::CalculatedField::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    if (field != nullptr) json.emit("field", field);
    json.emit("specs", specs);
    json.emit("annotations", annotations);
}
IR::CalculatedField::CalculatedField(JSONLoader & json) : Node(json) {
    json.load("field", field);
    json.load("specs", specs);
    json.load("annotations", annotations);
}
IR::Node * IR::CalculatedField::fromJSON(JSONLoader & json) { return new CalculatedField(json); }
bool IR::CalculatedField::operator==(IR::Node const & a) const { return a == *this; }
#line 267 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> const & IR::ParserValueSet::getAnnotations() const { return annotations; }
#line 8487 "/root/p4c/build/ir/ir-generated.cpp"
#line 268 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> & IR::ParserValueSet::getAnnotations() { return annotations; }
#line 8490 "/root/p4c/build/ir/ir-generated.cpp"
#line 269 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::ParserValueSet::dbprint(std::ostream & out) const { out << node_type_name() << " " << name; }
#line 8493 "/root/p4c/build/ir/ir-generated.cpp"
#line 270 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::ParserValueSet::toString() const { return node_type_name() + " " + name; }
#line 8496 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ParserValueSet::operator==(IR::ParserValueSet const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && annotations == a.annotations;
    }
bool IR::ParserValueSet::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const ParserValueSet &>(a_);
        return name == a.name
        && annotations.equiv(a.annotations);
    }
void IR::ParserValueSet::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
}
void IR::ParserValueSet::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
}
void IR::ParserValueSet::validate() const {
#line 8520 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate(); }
void IR::ParserValueSet::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::ParserValueSet::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    json.emit("annotations", annotations);
}
IR::ParserValueSet::ParserValueSet(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("annotations", annotations);
}
IR::Node * IR::ParserValueSet::fromJSON(JSONLoader & json) { return new ParserValueSet(json); }
bool IR::ParserValueSet::operator==(IR::Node const & a) const { return a == *this; }
bool IR::CaseEntry::operator==(IR::CaseEntry const & a) const {
        return this->typeId() == a.typeId()
        && values == a.values
        && action == a.action;
    }
bool IR::CaseEntry::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const CaseEntry &>(a_);
        return values == a.values
        && action == a.action;
    }
void IR::CaseEntry::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " action=" << action;
}
void IR::CaseEntry::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("values", values);
    json.emit("action", action);
}
IR::CaseEntry::CaseEntry(JSONLoader & json) : Node(json) {
    json.load("values", values);
    json.load("action", action);
}
IR::Node * IR::CaseEntry::fromJSON(JSONLoader & json) { return new CaseEntry(json); }
bool IR::CaseEntry::operator==(IR::Node const & a) const { return a == *this; }
#line 287 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> const & IR::V1Parser::getAnnotations() const { return annotations; }
#line 8567 "/root/p4c/build/ir/ir-generated.cpp"
#line 288 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> & IR::V1Parser::getAnnotations() { return annotations; }
#line 8570 "/root/p4c/build/ir/ir-generated.cpp"
#line 289 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::V1Parser::toString() const { return node_type_name() + " " + name; }
#line 8573 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::V1Parser::operator==(IR::V1Parser const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && stmts == a.stmts
        && select == a.select
        && cases == a.cases
        && default_return == a.default_return
        && parse_error == a.parse_error
        && drop == a.drop
        && annotations == a.annotations;
    }
bool IR::V1Parser::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const V1Parser &>(a_);
        return name == a.name
        && stmts.equiv(a.stmts)
        && (select ? a.select ? select->equiv(*a.select) : false : a.select == nullptr)
        && (cases ? a.cases ? cases->equiv(*a.cases) : false : a.cases == nullptr)
        && default_return == a.default_return
        && parse_error == a.parse_error
        && drop == a.drop
        && annotations.equiv(a.annotations);
    }
void IR::V1Parser::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    stmts.visit_children(v, "stmts");
    v.visit(select, "select");
    v.visit(cases, "cases");
    annotations.visit_children(v, "annotations");
}
void IR::V1Parser::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    stmts.visit_children(v, "stmts");
    v.visit(select, "select");
    v.visit(cases, "cases");
    annotations.visit_children(v, "annotations");
}
void IR::V1Parser::validate() const {
#line 8615 "/root/p4c/build/ir/ir-generated.cpp"

        stmts.validate();
        annotations.validate(); }
void IR::V1Parser::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " default_return=" << default_return;
        out << " parse_error=" << parse_error;
        out << " drop=" << drop;
}
void IR::V1Parser::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    json.emit("stmts", stmts);
    if (select != nullptr) json.emit("select", select);
    if (cases != nullptr) json.emit("cases", cases);
    json.emit("default_return", default_return);
    json.emit("parse_error", parse_error);
    json.emit("drop", drop);
    json.emit("annotations", annotations);
}
IR::V1Parser::V1Parser(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("stmts", stmts);
    json.load("select", select);
    json.load("cases", cases);
    json.load("default_return", default_return);
    json.load("parse_error", parse_error);
    json.load("drop", drop);
    json.load("annotations", annotations);
}
IR::Node * IR::V1Parser::fromJSON(JSONLoader & json) { return new V1Parser(json); }
bool IR::V1Parser::operator==(IR::Node const & a) const { return a == *this; }
bool IR::ParserException::operator==(IR::ParserException const & a) const {
        return this->typeId() == a.typeId();
    }
bool IR::ParserException::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        return true;
    }
void IR::ParserException::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::ParserException::ParserException(JSONLoader & json) : Node(json) {
}
IR::Node * IR::ParserException::fromJSON(JSONLoader & json) { return new ParserException(json); }
bool IR::ParserException::operator==(IR::Node const & a) const { return a == *this; }
#line 297 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::ID IR::Attached::Name() const { return name; }
#line 8666 "/root/p4c/build/ir/ir-generated.cpp"
#line 299 "/root/p4c/frontends/p4-14/ir-v1.def"
const IR::Type *IR::Attached::getType() const { return Type_Unknown::get(); }
#line 8669 "/root/p4c/build/ir/ir-generated.cpp"
#line 300 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> const & IR::Attached::getAnnotations() const { return annotations; }
#line 8672 "/root/p4c/build/ir/ir-generated.cpp"
#line 301 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> & IR::Attached::getAnnotations() { return annotations; }
#line 8675 "/root/p4c/build/ir/ir-generated.cpp"
#line 302 "/root/p4c/frontends/p4-14/ir-v1.def"
bool IR::Attached::indexed() const { return false; }
#line 8678 "/root/p4c/build/ir/ir-generated.cpp"
#line 303 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Attached * IR::Attached::clone_rename(char const * ext) const {
        Attached *rv = clone();
        rv->name = ID(Util::SourceInfo(), rv->name.name + ext);
        return rv; }
#line 8684 "/root/p4c/build/ir/ir-generated.cpp"
#line 307 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::Attached::dbprint(std::ostream & out) const { out << node_type_name() << " " << name; }
#line 8687 "/root/p4c/build/ir/ir-generated.cpp"
#line 308 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::Attached::toString() const { return node_type_name() + " " + name; }
#line 8690 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Attached::operator==(IR::Attached const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && annotations == a.annotations;
    }
bool IR::Attached::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const Attached &>(a_);
        return name == a.name
        && annotations.equiv(a.annotations);
    }
void IR::Attached::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
}
void IR::Attached::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
}
void IR::Attached::validate() const {
#line 8714 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate(); }
void IR::Attached::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::Attached::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    json.emit("annotations", annotations);
}
IR::Attached::Attached(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("annotations", annotations);
}
bool IR::Attached::operator==(IR::Node const & a) const { return a == *this; }
#line 316 "/root/p4c/frontends/p4-14/ir-v1.def"
bool IR::Stateful::indexed() const { return !direct; }
#line 8733 "/root/p4c/build/ir/ir-generated.cpp"

bool IR::Stateful::operator==(IR::Stateful const & a) const {
        return Attached::operator==(static_cast<const Attached &>(a))
        && table == a.table
        && direct == a.direct
        && saturating == a.saturating
        && instance_count == a.instance_count;
    }
bool IR::Stateful::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Attached::equiv(a_)) return false;
        auto &a = static_cast<const Stateful &>(a_);
        return table == a.table
        && direct == a.direct
        && saturating == a.saturating
        && instance_count == a.instance_count;
    }
void IR::Stateful::dump_fields(std::ostream & out) const {
    Attached::dump_fields(out);
        out << " table=" << table;
        out << " direct=" << direct;
        out << " saturating=" << saturating;
        out << " instance_count=" << instance_count;
}
void IR::Stateful::toJSON(JSONGenerator & json) const {
    Attached::toJSON(json);
    json.emit("table", table);
    json.emit("direct", direct);
    json.emit("saturating", saturating);
    json.emit("instance_count", instance_count);
}
IR::Stateful::Stateful(JSONLoader & json) : Attached(json) {
    json.load("table", table);
    json.load("direct", direct);
    json.load("saturating", saturating);
    json.load("instance_count", instance_count);
}
bool IR::Stateful::operator==(IR::Attached const & a) const { return a == *this; }
bool IR::Stateful::operator==(IR::Node const & a) const { return a == *this; }
#line 322 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::CounterOrMeter::settype(cstring t) {
        if (strcasecmp(t.c_str(), "packets") == 0) type = CounterType::PACKETS;
        else if (strcasecmp(t.c_str(), "bytes") == 0) type = CounterType::BYTES;
        else if (strcasecmp(t.c_str(), "packets_and_bytes") == 0 ||
                 strcasecmp(t.c_str(), "PacketAndBytes") == 0) type = CounterType::BOTH;
        else error(ErrorType::ERR_UNKNOWN, "%s: Unknown type %s", srcInfo, t); }
#line 8780 "/root/p4c/build/ir/ir-generated.cpp"

bool IR::CounterOrMeter::operator==(IR::CounterOrMeter const & a) const {
        return Stateful::operator==(static_cast<const Stateful &>(a))
        && type == a.type;
    }
bool IR::CounterOrMeter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Stateful::equiv(a_)) return false;
        auto &a = static_cast<const CounterOrMeter &>(a_);
        return type == a.type;
    }
void IR::CounterOrMeter::dump_fields(std::ostream & out) const {
    Stateful::dump_fields(out);
        out << " type=" << type;
}
void IR::CounterOrMeter::toJSON(JSONGenerator & json) const {
    Stateful::toJSON(json);
    json.emit("type", type);
}
IR::CounterOrMeter::CounterOrMeter(JSONLoader & json) : Stateful(json) {
    json.load("type", type);
}
bool IR::CounterOrMeter::operator==(IR::Stateful const & a) const { return a == *this; }
bool IR::CounterOrMeter::operator==(IR::Attached const & a) const { return a == *this; }
bool IR::CounterOrMeter::operator==(IR::Node const & a) const { return a == *this; }
#line 333 "/root/p4c/frontends/p4-14/ir-v1.def"
char const * IR::Counter::kind() const { return "stats"; }
#line 8808 "/root/p4c/build/ir/ir-generated.cpp"
#line 334 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Type const * IR::Counter::getType() const { return Type_Counter::get(); }
#line 8811 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Counter::operator==(IR::Counter const & a) const {
        return CounterOrMeter::operator==(static_cast<const CounterOrMeter &>(a))
        && max_width == a.max_width
        && min_width == a.min_width;
    }
bool IR::Counter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!CounterOrMeter::equiv(a_)) return false;
        auto &a = static_cast<const Counter &>(a_);
        return max_width == a.max_width
        && min_width == a.min_width;
    }
void IR::Counter::dump_fields(std::ostream & out) const {
    CounterOrMeter::dump_fields(out);
        out << " max_width=" << max_width;
        out << " min_width=" << min_width;
}
void IR::Counter::toJSON(JSONGenerator & json) const {
    CounterOrMeter::toJSON(json);
    json.emit("max_width", max_width);
    json.emit("min_width", min_width);
}
IR::Counter::Counter(JSONLoader & json) : CounterOrMeter(json) {
    json.load("max_width", max_width);
    json.load("min_width", min_width);
}
IR::Node * IR::Counter::fromJSON(JSONLoader & json) { return new Counter(json); }
bool IR::Counter::operator==(IR::CounterOrMeter const & a) const { return a == *this; }
bool IR::Counter::operator==(IR::Stateful const & a) const { return a == *this; }
bool IR::Counter::operator==(IR::Attached const & a) const { return a == *this; }
bool IR::Counter::operator==(IR::Node const & a) const { return a == *this; }
#line 341 "/root/p4c/frontends/p4-14/ir-v1.def"
char const * IR::Meter::kind() const { return "meter"; }
#line 8845 "/root/p4c/build/ir/ir-generated.cpp"
#line 342 "/root/p4c/frontends/p4-14/ir-v1.def"
const IR::Type *IR::Meter::getType() const { return Type_Meter::get(); }
#line 8848 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Meter::operator==(IR::Meter const & a) const {
        return CounterOrMeter::operator==(static_cast<const CounterOrMeter &>(a))
        && result == a.result
        && pre_color == a.pre_color
        && implementation == a.implementation;
    }
bool IR::Meter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!CounterOrMeter::equiv(a_)) return false;
        auto &a = static_cast<const Meter &>(a_);
        return (result ? a.result ? result->equiv(*a.result) : false : a.result == nullptr)
        && (pre_color ? a.pre_color ? pre_color->equiv(*a.pre_color) : false : a.pre_color == nullptr)
        && implementation == a.implementation;
    }
void IR::Meter::visit_children(Visitor & v, char const * n) {
    (void)n;
    CounterOrMeter::visit_children(v, n);
    v.visit(result, "result");
    v.visit(pre_color, "pre_color");
}
void IR::Meter::visit_children(Visitor & v, char const * n) const {
    (void)n;
    CounterOrMeter::visit_children(v, n);
    v.visit(result, "result");
    v.visit(pre_color, "pre_color");
}
void IR::Meter::dump_fields(std::ostream & out) const {
    CounterOrMeter::dump_fields(out);
        out << " implementation=" << implementation;
}
void IR::Meter::toJSON(JSONGenerator & json) const {
    CounterOrMeter::toJSON(json);
    if (result != nullptr) json.emit("result", result);
    if (pre_color != nullptr) json.emit("pre_color", pre_color);
    json.emit("implementation", implementation);
}
IR::Meter::Meter(JSONLoader & json) : CounterOrMeter(json) {
    json.load("result", result);
    json.load("pre_color", pre_color);
    json.load("implementation", implementation);
}
IR::Node * IR::Meter::fromJSON(JSONLoader & json) { return new Meter(json); }
bool IR::Meter::operator==(IR::CounterOrMeter const & a) const { return a == *this; }
bool IR::Meter::operator==(IR::Stateful const & a) const { return a == *this; }
bool IR::Meter::operator==(IR::Attached const & a) const { return a == *this; }
bool IR::Meter::operator==(IR::Node const & a) const { return a == *this; }

#line 350 "/root/p4c/frontends/p4-14/ir-v1.def"
char const * IR::Register::kind() const { return "register"; }
#line 8898 "/root/p4c/build/ir/ir-generated.cpp"
#line 351 "/root/p4c/frontends/p4-14/ir-v1.def"
const IR::Type *IR::Register::getType() const { return Type_Register::get(); }
#line 8901 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Register::operator==(IR::Register const & a) const {
        return Stateful::operator==(static_cast<const Stateful &>(a))
        && layout == a.layout
        && width == a.width
        && signed_ == a.signed_;
    }
bool IR::Register::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Stateful::equiv(a_)) return false;
        auto &a = static_cast<const Register &>(a_);
        return layout == a.layout
        && width == a.width
        && signed_ == a.signed_;
    }
void IR::Register::dump_fields(std::ostream & out) const {
    Stateful::dump_fields(out);
        out << " layout=" << layout;
        out << " width=" << width;
        out << " signed_=" << signed_;
}
void IR::Register::toJSON(JSONGenerator & json) const {
    Stateful::toJSON(json);
    json.emit("layout", layout);
    json.emit("width", width);
    json.emit("signed_", signed_);
}
IR::Register::Register(JSONLoader & json) : Stateful(json) {
    json.load("layout", layout);
    json.load("width", width);
    json.load("signed_", signed_);
}
IR::Node * IR::Register::fromJSON(JSONLoader & json) { return new Register(json); }
bool IR::Register::operator==(IR::Stateful const & a) const { return a == *this; }
bool IR::Register::operator==(IR::Attached const & a) const { return a == *this; }
bool IR::Register::operator==(IR::Node const & a) const { return a == *this; }
bool IR::PrimitiveAction::operator==(IR::PrimitiveAction const & a) const {
        return this->typeId() == a.typeId();
    }
bool IR::PrimitiveAction::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        return true;
    }
void IR::PrimitiveAction::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::PrimitiveAction::PrimitiveAction(JSONLoader & json) : Node(json) {
}
IR::Node * IR::PrimitiveAction::fromJSON(JSONLoader & json) { return new PrimitiveAction(json); }
bool IR::PrimitiveAction::operator==(IR::Node const & a) const { return a == *this; }
#line 358 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::NameList::NameList(Util::SourceInfo si, cstring n) { names.emplace_back(si, n); }
#line 8954 "/root/p4c/build/ir/ir-generated.cpp"
#line 359 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::NameList::NameList(Util::SourceInfo si, IR::ID n) { names.emplace_back(si, n); }
#line 8957 "/root/p4c/build/ir/ir-generated.cpp"
#line 360 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::NameList::dump_fields(std::ostream & out) const { out << "names=" << names; }
#line 8960 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::NameList::operator==(IR::NameList const & a) const {
        return this->typeId() == a.typeId()
        && names == a.names;
    }
bool IR::NameList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const NameList &>(a_);
        return names == a.names;
    }
void IR::NameList::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("names", names);
}
IR::NameList::NameList(JSONLoader & json) : Node(json) {
    json.load("names", names);
}
IR::Node * IR::NameList::fromJSON(JSONLoader & json) { return new NameList(json); }
bool IR::NameList::operator==(IR::Node const & a) const { return a == *this; }
#line 369 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::ActionArg::dbprint(std::ostream & out) const { out << action_name << ':' << name; }
#line 8982 "/root/p4c/build/ir/ir-generated.cpp"
#line 370 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::ActionArg::toString() const { return name.name; }
#line 8985 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ActionArg::operator==(IR::ActionArg const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && action_name == a.action_name
        && name == a.name
        && read == a.read
        && write == a.write;
    }
bool IR::ActionArg::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const ActionArg &>(a_);
        return action_name == a.action_name
        && name == a.name
        && read == a.read
        && write == a.write;
    }
void IR::ActionArg::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " action_name=" << action_name;
        out << " name=" << name;
        out << " read=" << read;
        out << " write=" << write;
}
void IR::ActionArg::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("action_name", action_name);
    json.emit("name", name);
    json.emit("read", read);
    json.emit("write", write);
}
IR::ActionArg::ActionArg(JSONLoader & json) : Expression(json) {
    json.load("action_name", action_name);
    json.load("name", name);
    json.load("read", read);
    json.load("write", write);
}
IR::Node * IR::ActionArg::fromJSON(JSONLoader & json) { return new ActionArg(json); }
bool IR::ActionArg::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::ActionArg::operator==(IR::Node const & a) const { return a == *this; }
#line 380 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> const & IR::ActionFunction::getAnnotations() const { return annotations; }
#line 9027 "/root/p4c/build/ir/ir-generated.cpp"
#line 381 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> & IR::ActionFunction::getAnnotations() { return annotations; }
#line 9030 "/root/p4c/build/ir/ir-generated.cpp"
#line 382 "/root/p4c/frontends/p4-14/ir-v1.def"
const IR::ActionArg *IR::ActionFunction::arg(cstring n) const {
        for (auto a : args)
            if (a->name == n)
                return a;
        return nullptr; }
#line 9037 "/root/p4c/build/ir/ir-generated.cpp"
#line 387 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::ActionFunction::visit_children(Visitor & v, char const * n) {
        (void)n;
        v.visit(action, "action");
        // DANGER -- visiting action first so type inferencing will push types to
        // DANGER -- action args based on use.  This is immoral.
        for (auto &a : args) v.visit(a, "arg");
        v.visit(annotations, "annotations");
    }
#line 387 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::ActionFunction::visit_children(Visitor & v, char const * n) const {
        (void)n;
        v.visit(action, "action");
        // DANGER -- visiting action first so type inferencing will push types to
        // DANGER -- action args based on use.  This is immoral.
        for (auto &a : args) v.visit(a, "arg");
        v.visit(annotations, "annotations");
    }
#line 9056 "/root/p4c/build/ir/ir-generated.cpp"
#line 395 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::ActionFunction::toString() const {
        return "action "_cs + name + " {\n"_cs +
                 cstring::join(action.begin(), action.end(), ";\n") +
                 " }"_cs; }
#line 9062 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ActionFunction::operator==(IR::ActionFunction const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && action == a.action
        && args == a.args
        && annotations == a.annotations;
    }
bool IR::ActionFunction::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const ActionFunction &>(a_);
        return name == a.name
        && action.equiv(a.action)
        && args == a.args
        && annotations.equiv(a.annotations);
    }
void IR::ActionFunction::validate() const {
#line 9080 "/root/p4c/build/ir/ir-generated.cpp"

        action.validate();
        annotations.validate(); }
void IR::ActionFunction::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::ActionFunction::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    json.emit("action", action);
    json.emit("args", args);
    json.emit("annotations", annotations);
}
IR::ActionFunction::ActionFunction(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("action", action);
    json.load("args", args);
    json.load("annotations", annotations);
}
IR::Node * IR::ActionFunction::fromJSON(JSONLoader & json) { return new ActionFunction(json); }
bool IR::ActionFunction::operator==(IR::Node const & a) const { return a == *this; }
#line 405 "/root/p4c/frontends/p4-14/ir-v1.def"
char const * IR::ActionProfile::kind() const { return "action_profile"; }
#line 9105 "/root/p4c/build/ir/ir-generated.cpp"
#line 406 "/root/p4c/frontends/p4-14/ir-v1.def"
bool IR::ActionProfile::indexed() const { return true; }
#line 9108 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ActionProfile::operator==(IR::ActionProfile const & a) const {
        return Attached::operator==(static_cast<const Attached &>(a))
        && selector == a.selector
        && actions == a.actions
        && size == a.size;
    }
bool IR::ActionProfile::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Attached::equiv(a_)) return false;
        auto &a = static_cast<const ActionProfile &>(a_);
        return selector == a.selector
        && actions == a.actions
        && size == a.size;
    }
void IR::ActionProfile::dump_fields(std::ostream & out) const {
    Attached::dump_fields(out);
        out << " selector=" << selector;
        out << " size=" << size;
}
void IR::ActionProfile::toJSON(JSONGenerator & json) const {
    Attached::toJSON(json);
    json.emit("selector", selector);
    json.emit("actions", actions);
    json.emit("size", size);
}
IR::ActionProfile::ActionProfile(JSONLoader & json) : Attached(json) {
    json.load("selector", selector);
    json.load("actions", actions);
    json.load("size", size);
}
IR::Node * IR::ActionProfile::fromJSON(JSONLoader & json) { return new ActionProfile(json); }
bool IR::ActionProfile::operator==(IR::Attached const & a) const { return a == *this; }
bool IR::ActionProfile::operator==(IR::Node const & a) const { return a == *this; }
#line 414 "/root/p4c/frontends/p4-14/ir-v1.def"
char const * IR::ActionSelector::kind() const { return "action_selector"; }
#line 9144 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::ActionSelector::operator==(IR::ActionSelector const & a) const {
        return Attached::operator==(static_cast<const Attached &>(a))
        && key == a.key
        && key_fields == a.key_fields
        && mode == a.mode
        && type == a.type;
    }
bool IR::ActionSelector::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Attached::equiv(a_)) return false;
        auto &a = static_cast<const ActionSelector &>(a_);
        return key == a.key
        && (key_fields ? a.key_fields ? key_fields->equiv(*a.key_fields) : false : a.key_fields == nullptr)
        && mode == a.mode
        && type == a.type;
    }
void IR::ActionSelector::visit_children(Visitor & v, char const * n) {
    (void)n;
    Attached::visit_children(v, n);
    v.visit(key_fields, "key_fields");
}
void IR::ActionSelector::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Attached::visit_children(v, n);
    v.visit(key_fields, "key_fields");
}
void IR::ActionSelector::dump_fields(std::ostream & out) const {
    Attached::dump_fields(out);
        out << " key=" << key;
        out << " mode=" << mode;
        out << " type=" << type;
}
void IR::ActionSelector::toJSON(JSONGenerator & json) const {
    Attached::toJSON(json);
    json.emit("key", key);
    if (key_fields != nullptr) json.emit("key_fields", key_fields);
    json.emit("mode", mode);
    json.emit("type", type);
}
IR::ActionSelector::ActionSelector(JSONLoader & json) : Attached(json) {
    json.load("key", key);
    json.load("key_fields", key_fields);
    json.load("mode", mode);
    json.load("type", type);
}
IR::Node * IR::ActionSelector::fromJSON(JSONLoader & json) { return new ActionSelector(json); }
bool IR::ActionSelector::operator==(IR::Attached const & a) const { return a == *this; }
bool IR::ActionSelector::operator==(IR::Node const & a) const { return a == *this; }

#line 432 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::V1Table::addProperty(const IR::Property* prop) { properties.push_back(prop); }
#line 9196 "/root/p4c/build/ir/ir-generated.cpp"
#line 433 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> const & IR::V1Table::getAnnotations() const { return annotations; }
#line 9199 "/root/p4c/build/ir/ir-generated.cpp"
#line 434 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> & IR::V1Table::getAnnotations() { return annotations; }
#line 9202 "/root/p4c/build/ir/ir-generated.cpp"
#line 435 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::V1Table::toString() const { return node_type_name() + " " + name; }
#line 9205 "/root/p4c/build/ir/ir-generated.cpp"
#line 436 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::ID IR::V1Table::Name() const { return name; }
#line 9208 "/root/p4c/build/ir/ir-generated.cpp"
#line 437 "/root/p4c/frontends/p4-14/ir-v1.def"
const IR::Type *IR::V1Table::getType() const { return Type_AnyTable::get(); }
#line 9211 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::V1Table::operator==(IR::V1Table const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && reads == a.reads
        && reads_types == a.reads_types
        && min_size == a.min_size
        && max_size == a.max_size
        && size == a.size
        && action_profile == a.action_profile
        && actions == a.actions
        && default_action == a.default_action
        && default_action_is_const == a.default_action_is_const
        && default_action_args == a.default_action_args
        && properties == a.properties
        && annotations == a.annotations;
    }
bool IR::V1Table::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const V1Table &>(a_);
        return name == a.name
        && (reads ? a.reads ? reads->equiv(*a.reads) : false : a.reads == nullptr)
        && reads_types == a.reads_types
        && min_size == a.min_size
        && max_size == a.max_size
        && size == a.size
        && action_profile == a.action_profile
        && actions == a.actions
        && default_action == a.default_action
        && default_action_is_const == a.default_action_is_const
        && (default_action_args ? a.default_action_args ? default_action_args->equiv(*a.default_action_args) : false : a.default_action_args == nullptr)
        && properties.equiv(a.properties)
        && annotations.equiv(a.annotations);
    }
void IR::V1Table::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(reads, "reads");
    v.visit(default_action_args, "default_action_args");
    properties.visit_children(v, "properties");
    annotations.visit_children(v, "annotations");
}
void IR::V1Table::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(reads, "reads");
    v.visit(default_action_args, "default_action_args");
    properties.visit_children(v, "properties");
    annotations.visit_children(v, "annotations");
}
void IR::V1Table::validate() const {
#line 9263 "/root/p4c/build/ir/ir-generated.cpp"

        properties.validate();
        annotations.validate(); }
void IR::V1Table::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " min_size=" << min_size;
        out << " max_size=" << max_size;
        out << " size=" << size;
        out << " action_profile=" << action_profile;
        out << " default_action=" << default_action;
        out << " default_action_is_const=" << default_action_is_const;
}
void IR::V1Table::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    if (reads != nullptr) json.emit("reads", reads);
    json.emit("reads_types", reads_types);
    json.emit("min_size", min_size);
    json.emit("max_size", max_size);
    json.emit("size", size);
    json.emit("action_profile", action_profile);
    json.emit("actions", actions);
    json.emit("default_action", default_action);
    json.emit("default_action_is_const", default_action_is_const);
    if (default_action_args != nullptr) json.emit("default_action_args", default_action_args);
    json.emit("properties", properties);
    json.emit("annotations", annotations);
}
IR::V1Table::V1Table(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("reads", reads);
    json.load("reads_types", reads_types);
    json.load("min_size", min_size);
    json.load("max_size", max_size);
    json.load("size", size);
    json.load("action_profile", action_profile);
    json.load("actions", actions);
    json.load("default_action", default_action);
    json.load("default_action_is_const", default_action_is_const);
    json.load("default_action_args", default_action_args);
    json.load("properties", properties);
    json.load("annotations", annotations);
}
IR::Node * IR::V1Table::fromJSON(JSONLoader & json) { return new V1Table(json); }
bool IR::V1Table::operator==(IR::Node const & a) const { return a == *this; }
#line 445 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::V1Control::V1Control(IR::ID n) : name(n), code(new Vector<Expression>()) {}
#line 9312 "/root/p4c/build/ir/ir-generated.cpp"
#line 446 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::V1Control::V1Control(Util::SourceInfo si, IR::ID n) : Node(si), name(n), code(new Vector<Expression>()) {}
#line 9315 "/root/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(V1Control, , )
#line 448 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> const & IR::V1Control::getAnnotations() const { return annotations; }
#line 9319 "/root/p4c/build/ir/ir-generated.cpp"
#line 449 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::Vector<IR::Annotation> & IR::V1Control::getAnnotations() { return annotations; }
#line 9322 "/root/p4c/build/ir/ir-generated.cpp"
#line 450 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::V1Control::toString() const { return node_type_name() + " " + name; }
#line 9325 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::V1Control::operator==(IR::V1Control const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && code == a.code
        && annotations == a.annotations;
    }
bool IR::V1Control::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const V1Control &>(a_);
        return name == a.name
        && (code ? a.code ? code->equiv(*a.code) : false : a.code == nullptr)
        && annotations.equiv(a.annotations);
    }
void IR::V1Control::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(code, "code");
    annotations.visit_children(v, "annotations");
}
void IR::V1Control::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(code, "code");
    annotations.visit_children(v, "annotations");
}
void IR::V1Control::validate() const {
#line 9353 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(code);
        annotations.validate(); }
void IR::V1Control::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::V1Control::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    json.emit("code", code);
    json.emit("annotations", annotations);
}
IR::V1Control::V1Control(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("code", code);
    json.load("annotations", annotations);
}
IR::Node * IR::V1Control::fromJSON(JSONLoader & json) { return new V1Control(json); }
bool IR::V1Control::operator==(IR::Node const & a) const { return a == *this; }
#line 455 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::ID IR::AttribLocal::getName() const { return name; }
#line 9376 "/root/p4c/build/ir/ir-generated.cpp"
#line 456 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::AttribLocal::dbprint(std::ostream & out) const { out << name; }
#line 9379 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::AttribLocal::operator==(IR::AttribLocal const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && name == a.name;
    }
bool IR::AttribLocal::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const AttribLocal &>(a_);
        return name == a.name;
    }
void IR::AttribLocal::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " name=" << name;
}
void IR::AttribLocal::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("name", name);
}
IR::AttribLocal::AttribLocal(JSONLoader & json) : Expression(json) {
    json.load("name", name);
}
IR::Node * IR::AttribLocal::fromJSON(JSONLoader & json) { return new AttribLocal(json); }
bool IR::AttribLocal::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::AttribLocal::operator==(IR::Node const & a) const { return a == *this; }
#line 462 "/root/p4c/frontends/p4-14/ir-v1.def"
Util::Enumerator<const IR::IDeclaration *> * IR::AttribLocals::getDeclarations() const {
        return locals.valueEnumerator()->as<const IDeclaration *>(); }
#line 9407 "/root/p4c/build/ir/ir-generated.cpp"
#line 464 "/root/p4c/frontends/p4-14/ir-v1.def"
const IR::IDeclaration *IR::AttribLocals::getDeclByName(cstring name) const { return locals[name]; }
#line 9410 "/root/p4c/build/ir/ir-generated.cpp"
#line 465 "/root/p4c/frontends/p4-14/ir-v1.def"
const IR::IDeclaration *IR::AttribLocals::getDeclByName(std::string_view name) const { return locals[cstring(name)]; }
#line 9413 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::AttribLocals::operator==(IR::AttribLocals const & a) const {
        return this->typeId() == a.typeId()
        && locals == a.locals;
    }
bool IR::AttribLocals::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const AttribLocals &>(a_);
        return locals.equiv(a.locals);
    }
void IR::AttribLocals::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    locals.visit_children(v, "locals");
}
void IR::AttribLocals::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    locals.visit_children(v, "locals");
}
void IR::AttribLocals::validate() const {
#line 9435 "/root/p4c/build/ir/ir-generated.cpp"

        locals.validate(); }
void IR::AttribLocals::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("locals", locals);
}
IR::AttribLocals::AttribLocals(JSONLoader & json) : Node(json) {
    json.load("locals", locals);
}
IR::Node * IR::AttribLocals::fromJSON(JSONLoader & json) { return new AttribLocals(json); }
bool IR::AttribLocals::operator==(IR::Node const & a) const { return a == *this; }
#line 472 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::Attribute::dbprint(std::ostream & out) const { if (type) out << type << ' '; out << name; }
#line 9449 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::Attribute::operator==(IR::Attribute const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && type == a.type
        && locals == a.locals
        && optional == a.optional;
    }
bool IR::Attribute::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Attribute &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (locals ? a.locals ? locals->equiv(*a.locals) : false : a.locals == nullptr)
        && optional == a.optional;
    }
void IR::Attribute::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    v.visit(type, "type");
    v.visit(locals, "locals");
}
void IR::Attribute::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    v.visit(type, "type");
    v.visit(locals, "locals");
}
void IR::Attribute::dump_fields(std::ostream & out) const {
    Declaration::dump_fields(out);
        out << " optional=" << optional;
}
void IR::Attribute::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    if (type != nullptr) json.emit("type", type);
    if (locals != nullptr) json.emit("locals", locals);
    json.emit("optional", optional);
}
IR::Attribute::Attribute(JSONLoader & json) : Declaration(json) {
    json.load("type", type);
    json.load("locals", locals);
    json.load("optional", optional);
}
IR::Node * IR::Attribute::fromJSON(JSONLoader & json) { return new Attribute(json); }
bool IR::Attribute::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::Attribute::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::Attribute::operator==(IR::Node const & a) const { return a == *this; }


#line 479 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::GlobalRef::validate() const {
#line 9499 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(obj);
#line 479 "/root/p4c/frontends/p4-14/ir-v1.def"
{ BUG_CHECK(obj->is<IInstance>(), "Invalid object %1%", obj); } }
#line 9504 "/root/p4c/build/ir/ir-generated.cpp"
#line 480 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::GlobalRef::toString() const { return obj->to<IInstance>()->toString(); }
#line 9507 "/root/p4c/build/ir/ir-generated.cpp"
#line 481 "/root/p4c/frontends/p4-14/ir-v1.def"
IR::ID IR::GlobalRef::Name() const { return obj->to<IInstance>()->Name(); }
#line 9510 "/root/p4c/build/ir/ir-generated.cpp"
#line 482 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::GlobalRef::dbprint(std::ostream & out) const { out << obj->to<IInstance>()->Name(); }
#line 9513 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::GlobalRef::operator==(IR::GlobalRef const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && obj == a.obj;
    }
bool IR::GlobalRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const GlobalRef &>(a_);
        return (obj ? a.obj ? obj->equiv(*a.obj) : false : a.obj == nullptr);
    }
void IR::GlobalRef::visit_children(Visitor & v, char const * n) {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(obj, "obj");
}
void IR::GlobalRef::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(obj, "obj");
}
void IR::GlobalRef::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("obj", obj);
}
IR::GlobalRef::GlobalRef(JSONLoader & json) : Expression(json) {
    json.load("obj", obj);
}
IR::Node * IR::GlobalRef::fromJSON(JSONLoader & json) { return new GlobalRef(json); }
bool IR::GlobalRef::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::GlobalRef::operator==(IR::Node const & a) const { return a == *this; }
#line 490 "/root/p4c/frontends/p4-14/ir-v1.def"
cstring IR::AttributeRef::toString() const { return attrib->name; }
#line 9546 "/root/p4c/build/ir/ir-generated.cpp"
#line 491 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::AttributeRef::dbprint(std::ostream & out) const { out << attrib->name; }
#line 9549 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::AttributeRef::operator==(IR::AttributeRef const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && extern_name == a.extern_name
        && extern_type == a.extern_type
        && attrib == a.attrib;
    }
bool IR::AttributeRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const AttributeRef &>(a_);
        return extern_name == a.extern_name
        && (extern_type ? a.extern_type ? extern_type->equiv(*a.extern_type) : false : a.extern_type == nullptr)
        && (attrib ? a.attrib ? attrib->equiv(*a.attrib) : false : a.attrib == nullptr);
    }
void IR::AttributeRef::visit_children(Visitor & v, char const * n) {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(extern_type, "extern_type");
    v.visit(attrib, "attrib");
}
void IR::AttributeRef::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(extern_type, "extern_type");
    v.visit(attrib, "attrib");
}
void IR::AttributeRef::validate() const {
#line 9577 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(extern_type);
        CHECK_NULL(attrib); }
void IR::AttributeRef::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " extern_name=" << extern_name;
}
void IR::AttributeRef::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("extern_name", extern_name);
    json.emit("extern_type", extern_type);
    json.emit("attrib", attrib);
}
IR::AttributeRef::AttributeRef(JSONLoader & json) : Expression(json) {
    json.load("extern_name", extern_name);
    json.load("extern_type", extern_type);
    json.load("attrib", attrib);
}
IR::Node * IR::AttributeRef::fromJSON(JSONLoader & json) { return new AttributeRef(json); }
bool IR::AttributeRef::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::AttributeRef::operator==(IR::Node const & a) const { return a == *this; }
#line 502 "/root/p4c/frontends/p4-14/ir-v1.def"
void IR::V1Program::add(cstring name, IR::Node const * n) { scope.add(name, n); }
#line 9601 "/root/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(V1Program, , )
bool IR::V1Program::operator==(IR::V1Program const & a) const {
        return this->typeId() == a.typeId()
        && scope == a.scope;
    }
bool IR::V1Program::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const V1Program &>(a_);
        return scope.equiv(a.scope);
    }
void IR::V1Program::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    scope.visit_children(v, "scope");
}
void IR::V1Program::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    scope.visit_children(v, "scope");
}
void IR::V1Program::validate() const {
#line 9624 "/root/p4c/build/ir/ir-generated.cpp"

        scope.validate(); }
void IR::V1Program::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("scope", scope);
}
IR::V1Program::V1Program(JSONLoader & json) : Node(json) {
    json.load("scope", scope);
}
IR::Node * IR::V1Program::fromJSON(JSONLoader & json) { return new V1Program(json); }
bool IR::V1Program::operator==(IR::Node const & a) const { return a == *this; }
#line 6 "/root/p4c/frontends/p5/ir-p5.def"
IR::Vector<IR::Annotation> const & IR::P5Table::getAnnotations() const { return annotations; }
#line 9638 "/root/p4c/build/ir/ir-generated.cpp"
#line 7 "/root/p4c/frontends/p5/ir-p5.def"
IR::Vector<IR::Annotation> & IR::P5Table::getAnnotations() { return annotations; }
#line 9641 "/root/p4c/build/ir/ir-generated.cpp"
#line 9 "/root/p4c/frontends/p5/ir-p5.def"
Util::Enumerator<const IR::IDeclaration *> * IR::P5Table::getDeclarations() const {
        return parameters->getDeclarations(); }
#line 9645 "/root/p4c/build/ir/ir-generated.cpp"
#line 11 "/root/p4c/frontends/p5/ir-p5.def"
const IR::IDeclaration *IR::P5Table::getDeclByName(cstring name) const {
        return parameters->getDeclByName(name); }
#line 9649 "/root/p4c/build/ir/ir-generated.cpp"
#line 13 "/root/p4c/frontends/p5/ir-p5.def"
const IR::IDeclaration *IR::P5Table::getDeclByName(std::string_view name) const {
        return parameters->getDeclByName(name); }
#line 9653 "/root/p4c/build/ir/ir-generated.cpp"
#line 16 "/root/p4c/frontends/p5/ir-p5.def"
void IR::P5Table::dbprint(std::ostream & out) const { out << "P5Table " << name; }
#line 9656 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::P5Table::operator==(IR::P5Table const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && parameters == a.parameters
        && body == a.body;
    }
bool IR::P5Table::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P5Table &>(a_);
        return annotations.equiv(a.annotations)
        && (parameters ? a.parameters ? parameters->equiv(*a.parameters) : false : a.parameters == nullptr)
        && (body ? a.body ? body->equiv(*a.body) : false : a.body == nullptr);
    }
void IR::P5Table::visit_children(Visitor & v, char const * n) {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(parameters, "parameters");
    v.visit(body, "body");
}
void IR::P5Table::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Declaration::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(parameters, "parameters");
    v.visit(body, "body");
}
void IR::P5Table::validate() const {
#line 9686 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(parameters);
        CHECK_NULL(body); }
void IR::P5Table::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("parameters", parameters);
    json.emit("body", body);
}
IR::P5Table::P5Table(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("parameters", parameters);
    json.load("body", body);
}
IR::Node * IR::P5Table::fromJSON(JSONLoader & json) { return new P5Table(json); }
bool IR::P5Table::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::P5Table::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::P5Table::operator==(IR::Node const & a) const { return a == *this; }
#line 24 "/root/p4c/frontends/p5/ir-p5.def"
void IR::P5KeyElement::dbprint(std::ostream & out) const { out << "P5KeyElement"; }
#line 9708 "/root/p4c/build/ir/ir-generated.cpp"
#line 26 "/root/p4c/frontends/p5/ir-p5.def"
IR::Vector<IR::Annotation> const & IR::P5KeyElement::getAnnotations() const { return annotations; }
#line 9711 "/root/p4c/build/ir/ir-generated.cpp"
#line 27 "/root/p4c/frontends/p5/ir-p5.def"
IR::Vector<IR::Annotation> & IR::P5KeyElement::getAnnotations() { return annotations; }
#line 9714 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::P5KeyElement::operator==(IR::P5KeyElement const & a) const {
        return this->typeId() == a.typeId()
        && annotations == a.annotations
        && expr == a.expr
        && matchType == a.matchType
        && control == a.control;
    }
bool IR::P5KeyElement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const P5KeyElement &>(a_);
        return annotations.equiv(a.annotations)
        && (expr ? a.expr ? expr->equiv(*a.expr) : false : a.expr == nullptr)
        && matchType == a.matchType
        && control.equiv(a.control);
    }
void IR::P5KeyElement::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(expr, "expr");
    control.visit_children(v, "control");
}
void IR::P5KeyElement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(expr, "expr");
    control.visit_children(v, "control");
}
void IR::P5KeyElement::validate() const {
#line 9746 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        control.validate(); }
void IR::P5KeyElement::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " matchType=" << matchType;
}
void IR::P5KeyElement::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("annotations", annotations);
    if (expr != nullptr) json.emit("expr", expr);
    if (matchType != nullptr) json.emit("matchType", matchType);
    json.emit("control", control);
}
IR::P5KeyElement::P5KeyElement(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
    json.load("expr", expr);
    json.load("matchType", matchType);
    json.load("control", control);
}
IR::Node * IR::P5KeyElement::fromJSON(JSONLoader & json) { return new P5KeyElement(json); }
bool IR::P5KeyElement::operator==(IR::Node const & a) const { return a == *this; }


#line 37 "/root/p4c/frontends/p5/ir-p5.def"
void IR::P5KeyCase::dbprint(std::ostream & out) const { out << "P5KeyCase"; }
#line 9773 "/root/p4c/build/ir/ir-generated.cpp"
#line 39 "/root/p4c/frontends/p5/ir-p5.def"
IR::Vector<IR::Annotation> const & IR::P5KeyCase::getAnnotations() const { return annotations; }
#line 9776 "/root/p4c/build/ir/ir-generated.cpp"
#line 40 "/root/p4c/frontends/p5/ir-p5.def"
IR::Vector<IR::Annotation> & IR::P5KeyCase::getAnnotations() { return annotations; }
#line 9779 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::P5KeyCase::operator==(IR::P5KeyCase const & a) const {
        return this->typeId() == a.typeId()
        && annotations == a.annotations
        && label == a.label
        && elements == a.elements
        && fallthrough == a.fallthrough;
    }
bool IR::P5KeyCase::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const P5KeyCase &>(a_);
        return annotations.equiv(a.annotations)
        && (label ? a.label ? label->equiv(*a.label) : false : a.label == nullptr)
        && elements.equiv(a.elements)
        && fallthrough == a.fallthrough;
    }
void IR::P5KeyCase::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(label, "label");
    elements.visit_children(v, "elements");
}
void IR::P5KeyCase::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(label, "label");
    elements.visit_children(v, "elements");
}
void IR::P5KeyCase::validate() const {
#line 9811 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        elements.validate(); }
void IR::P5KeyCase::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " fallthrough=" << fallthrough;
}
void IR::P5KeyCase::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("annotations", annotations);
    if (label != nullptr) json.emit("label", label);
    json.emit("elements", elements);
    json.emit("fallthrough", fallthrough);
}
IR::P5KeyCase::P5KeyCase(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
    json.load("label", label);
    json.load("elements", elements);
    json.load("fallthrough", fallthrough);
}
IR::Node * IR::P5KeyCase::fromJSON(JSONLoader & json) { return new P5KeyCase(json); }
bool IR::P5KeyCase::operator==(IR::Node const & a) const { return a == *this; }
#line 47 "/root/p4c/frontends/p5/ir-p5.def"
void IR::P5KeySwitch::dbprint(std::ostream & out) const { out << "P5KeySwitch"; }
#line 9836 "/root/p4c/build/ir/ir-generated.cpp"
#line 49 "/root/p4c/frontends/p5/ir-p5.def"
IR::Vector<IR::Annotation> const & IR::P5KeySwitch::getAnnotations() const { return annotations; }
#line 9839 "/root/p4c/build/ir/ir-generated.cpp"
#line 50 "/root/p4c/frontends/p5/ir-p5.def"
IR::Vector<IR::Annotation> & IR::P5KeySwitch::getAnnotations() { return annotations; }
#line 9842 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::P5KeySwitch::operator==(IR::P5KeySwitch const & a) const {
        return this->typeId() == a.typeId()
        && annotations == a.annotations
        && select == a.select
        && cases == a.cases;
    }
bool IR::P5KeySwitch::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const P5KeySwitch &>(a_);
        return annotations.equiv(a.annotations)
        && (select ? a.select ? select->equiv(*a.select) : false : a.select == nullptr)
        && cases.equiv(a.cases);
    }
void IR::P5KeySwitch::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(select, "select");
    cases.visit_children(v, "cases");
}
void IR::P5KeySwitch::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    v.visit(select, "select");
    cases.visit_children(v, "cases");
}
void IR::P5KeySwitch::validate() const {
#line 9872 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        CHECK_NULL(select);
        cases.validate(); }
void IR::P5KeySwitch::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("select", select);
    json.emit("cases", cases);
}
IR::P5KeySwitch::P5KeySwitch(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
    json.load("select", select);
    json.load("cases", cases);
}
IR::Node * IR::P5KeySwitch::fromJSON(JSONLoader & json) { return new P5KeySwitch(json); }
bool IR::P5KeySwitch::operator==(IR::Node const & a) const { return a == *this; }


#line 57 "/root/p4c/frontends/p5/ir-p5.def"
void IR::P5Key::dbprint(std::ostream & out) const { out << "P5Key"; }
#line 9894 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::P5Key::operator==(IR::P5Key const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && elements == a.elements
        && switches == a.switches;
    }
bool IR::P5Key::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const P5Key &>(a_);
        return elements.equiv(a.elements)
        && switches.equiv(a.switches);
    }
void IR::P5Key::visit_children(Visitor & v, char const * n) {
    (void)n;
    Statement::visit_children(v, n);
    elements.visit_children(v, "elements");
    switches.visit_children(v, "switches");
}
void IR::P5Key::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Statement::visit_children(v, n);
    elements.visit_children(v, "elements");
    switches.visit_children(v, "switches");
}
void IR::P5Key::validate() const {
#line 9920 "/root/p4c/build/ir/ir-generated.cpp"

        elements.validate();
        switches.validate(); }
void IR::P5Key::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json.emit("elements", elements);
    json.emit("switches", switches);
}
IR::P5Key::P5Key(JSONLoader & json) : Statement(json) {
    json.load("elements", elements);
    json.load("switches", switches);
}
IR::Node * IR::P5Key::fromJSON(JSONLoader & json) { return new P5Key(json); }
bool IR::P5Key::operator==(IR::Statement const & a) const { return a == *this; }
bool IR::P5Key::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::P5Key::operator==(IR::Node const & a) const { return a == *this; }


#line 67 "/root/p4c/frontends/p5/ir-p5.def"
void IR::P5DesignatedInitializer::dbprint(std::ostream & out) const { out << "P5DesignatedInitializer"; }
#line 9941 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::P5DesignatedInitializer::operator==(IR::P5DesignatedInitializer const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && isMember == a.isMember
        && designator == a.designator
        && value == a.value;
    }
bool IR::P5DesignatedInitializer::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const P5DesignatedInitializer &>(a_);
        return isMember == a.isMember
        && (designator ? a.designator ? designator->equiv(*a.designator) : false : a.designator == nullptr)
        && (value ? a.value ? value->equiv(*a.value) : false : a.value == nullptr);
    }
void IR::P5DesignatedInitializer::visit_children(Visitor & v, char const * n) {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(designator, "designator");
    v.visit(value, "value");
}
void IR::P5DesignatedInitializer::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(designator, "designator");
    v.visit(value, "value");
}
void IR::P5DesignatedInitializer::validate() const {
#line 9969 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(designator);
        CHECK_NULL(value); }
void IR::P5DesignatedInitializer::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " isMember=" << isMember;
}
void IR::P5DesignatedInitializer::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("isMember", isMember);
    json.emit("designator", designator);
    json.emit("value", value);
}
IR::P5DesignatedInitializer::P5DesignatedInitializer(JSONLoader & json) : Expression(json) {
    json.load("isMember", isMember);
    json.load("designator", designator);
    json.load("value", value);
}
IR::Node * IR::P5DesignatedInitializer::fromJSON(JSONLoader & json) { return new P5DesignatedInitializer(json); }
bool IR::P5DesignatedInitializer::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::P5DesignatedInitializer::operator==(IR::Node const & a) const { return a == *this; }
#line 74 "/root/p4c/frontends/p5/ir-p5.def"
void IR::P5PostIncrement::dbprint(std::ostream & out) const { out << "P5PostIncrement"; }
#line 9993 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::P5PostIncrement::operator==(IR::P5PostIncrement const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && expr == a.expr;
    }
bool IR::P5PostIncrement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const P5PostIncrement &>(a_);
        return (expr ? a.expr ? expr->equiv(*a.expr) : false : a.expr == nullptr);
    }
void IR::P5PostIncrement::visit_children(Visitor & v, char const * n) {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(expr, "expr");
}
void IR::P5PostIncrement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Expression::visit_children(v, n);
    v.visit(expr, "expr");
}
void IR::P5PostIncrement::validate() const {
#line 10015 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(expr); }
void IR::P5PostIncrement::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json.emit("expr", expr);
}
IR::P5PostIncrement::P5PostIncrement(JSONLoader & json) : Expression(json) {
    json.load("expr", expr);
}
IR::Node * IR::P5PostIncrement::fromJSON(JSONLoader & json) { return new P5PostIncrement(json); }
bool IR::P5PostIncrement::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::P5PostIncrement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::IntMod::operator==(IR::IntMod const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a))
        && width == a.width;
    }
bool IR::IntMod::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        auto &a = static_cast<const IntMod &>(a_);
        return width == a.width;
    }
void IR::IntMod::dump_fields(std::ostream & out) const {
    Operation_Unary::dump_fields(out);
        out << " width=" << width;
}
void IR::IntMod::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
    json.emit("width", width);
}
IR::IntMod::IntMod(JSONLoader & json) : Operation_Unary(json) {
    json.load("width", width);
}
IR::Node * IR::IntMod::fromJSON(JSONLoader & json) { return new IntMod(json); }
bool IR::IntMod::operator==(IR::Operation_Unary const & a) const { return a == *this; }
bool IR::IntMod::operator==(IR::Operation const & a) const { return a == *this; }
bool IR::IntMod::operator==(IR::Expression const & a) const { return a == *this; }
bool IR::IntMod::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkDeclaration::operator==(IR::DpdkDeclaration const & a) const {
        return this->typeId() == a.typeId()
        && global == a.global;
    }
bool IR::DpdkDeclaration::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const DpdkDeclaration &>(a_);
        return (global ? a.global ? global->equiv(*a.global) : false : a.global == nullptr);
    }
void IR::DpdkDeclaration::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(global, "global");
}
void IR::DpdkDeclaration::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(global, "global");
}
void IR::DpdkDeclaration::validate() const {
#line 10075 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(global); }
void IR::DpdkDeclaration::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("global", global);
}
IR::DpdkDeclaration::DpdkDeclaration(JSONLoader & json) : Node(json) {
    json.load("global", global);
}
IR::Node * IR::DpdkDeclaration::fromJSON(JSONLoader & json) { return new DpdkDeclaration(json); }
bool IR::DpdkDeclaration::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkExternDeclaration::operator==(IR::DpdkExternDeclaration const & a) const {
        return Declaration_Instance::operator==(static_cast<const Declaration_Instance &>(a));
    }
bool IR::DpdkExternDeclaration::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration_Instance::equiv(a_)) return false;
        return true;
    }
void IR::DpdkExternDeclaration::toJSON(JSONGenerator & json) const {
    Declaration_Instance::toJSON(json);
}
IR::DpdkExternDeclaration::DpdkExternDeclaration(JSONLoader & json) : Declaration_Instance(json) {
}
IR::Node * IR::DpdkExternDeclaration::fromJSON(JSONLoader & json) { return new DpdkExternDeclaration(json); }
bool IR::DpdkExternDeclaration::operator==(IR::Declaration_Instance const & a) const { return a == *this; }
bool IR::DpdkExternDeclaration::operator==(IR::Declaration const & a) const { return a == *this; }
bool IR::DpdkExternDeclaration::operator==(IR::StatOrDecl const & a) const { return a == *this; }
bool IR::DpdkExternDeclaration::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkHeaderType::operator==(IR::DpdkHeaderType const & a) const {
        return Type_Header::operator==(static_cast<const Type_Header &>(a));
    }
bool IR::DpdkHeaderType::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Header::equiv(a_)) return false;
        return true;
    }
void IR::DpdkHeaderType::toJSON(JSONGenerator & json) const {
    Type_Header::toJSON(json);
}
IR::DpdkHeaderType::DpdkHeaderType(JSONLoader & json) : Type_Header(json) {
}
IR::Node * IR::DpdkHeaderType::fromJSON(JSONLoader & json) { return new DpdkHeaderType(json); }
bool IR::DpdkHeaderType::operator==(IR::Type_Header const & a) const { return a == *this; }
bool IR::DpdkHeaderType::operator==(IR::Type_StructLike const & a) const { return a == *this; }
bool IR::DpdkHeaderType::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::DpdkHeaderType::operator==(IR::Type const & a) const { return a == *this; }
bool IR::DpdkHeaderType::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkHeaderInstance::operator==(IR::DpdkHeaderInstance const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && headerType == a.headerType;
    }
bool IR::DpdkHeaderInstance::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const DpdkHeaderInstance &>(a_);
        return (name ? a.name ? name->equiv(*a.name) : false : a.name == nullptr)
        && (headerType ? a.headerType ? headerType->equiv(*a.headerType) : false : a.headerType == nullptr);
    }
void IR::DpdkHeaderInstance::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(name, "name");
    v.visit(headerType, "headerType");
}
void IR::DpdkHeaderInstance::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(name, "name");
    v.visit(headerType, "headerType");
}
void IR::DpdkHeaderInstance::validate() const {
#line 10149 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(name);
        CHECK_NULL(headerType); }
void IR::DpdkHeaderInstance::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    json.emit("headerType", headerType);
}
IR::DpdkHeaderInstance::DpdkHeaderInstance(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("headerType", headerType);
}
IR::Node * IR::DpdkHeaderInstance::fromJSON(JSONLoader & json) { return new DpdkHeaderInstance(json); }
bool IR::DpdkHeaderInstance::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkStructType::operator==(IR::DpdkStructType const & a) const {
        return Type_Struct::operator==(static_cast<const Type_Struct &>(a));
    }
bool IR::DpdkStructType::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Struct::equiv(a_)) return false;
        return true;
    }
void IR::DpdkStructType::toJSON(JSONGenerator & json) const {
    Type_Struct::toJSON(json);
}
IR::DpdkStructType::DpdkStructType(JSONLoader & json) : Type_Struct(json) {
}
IR::Node * IR::DpdkStructType::fromJSON(JSONLoader & json) { return new DpdkStructType(json); }
bool IR::DpdkStructType::operator==(IR::Type_Struct const & a) const { return a == *this; }
bool IR::DpdkStructType::operator==(IR::Type_StructLike const & a) const { return a == *this; }
bool IR::DpdkStructType::operator==(IR::Type_Declaration const & a) const { return a == *this; }
bool IR::DpdkStructType::operator==(IR::Type const & a) const { return a == *this; }
bool IR::DpdkStructType::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkAsmStatement::operator==(IR::DpdkAsmStatement const & a) const {
        return this->typeId() == a.typeId();
    }
bool IR::DpdkAsmStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        return true;
    }
void IR::DpdkAsmStatement::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::DpdkAsmStatement::DpdkAsmStatement(JSONLoader & json) : Node(json) {
}
bool IR::DpdkAsmStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 43 "/root/p4c/backends/dpdk/dpdk.def"
IR::Vector<IR::Annotation> const & IR::DpdkAction::getAnnotations() const { return annotations; }
#line 10199 "/root/p4c/build/ir/ir-generated.cpp"
#line 44 "/root/p4c/backends/dpdk/dpdk.def"
IR::Vector<IR::Annotation> & IR::DpdkAction::getAnnotations() { return annotations; }
#line 10202 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkAction::operator==(IR::DpdkAction const & a) const {
        return this->typeId() == a.typeId()
        && annotations == a.annotations
        && statements == a.statements
        && name == a.name
        && para == a.para;
    }
bool IR::DpdkAction::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const DpdkAction &>(a_);
        return annotations.equiv(a.annotations)
        && statements.equiv(a.statements)
        && name == a.name
        && para.equiv(a.para);
    }
void IR::DpdkAction::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    statements.visit_children(v, "statements");
    para.visit_children(v, "para");
}
void IR::DpdkAction::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    annotations.visit_children(v, "annotations");
    statements.visit_children(v, "statements");
    para.visit_children(v, "para");
}
void IR::DpdkAction::validate() const {
#line 10234 "/root/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
        statements.validate();
        para.validate(); }
void IR::DpdkAction::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::DpdkAction::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("annotations", annotations);
    json.emit("statements", statements);
    json.emit("name", name);
    json.emit("para", para);
}
IR::DpdkAction::DpdkAction(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
    json.load("statements", statements);
    json.load("name", name);
    json.load("para", para);
}
IR::Node * IR::DpdkAction::fromJSON(JSONLoader & json) { return new DpdkAction(json); }
bool IR::DpdkAction::operator==(IR::Node const & a) const { return a == *this; }
#line 55 "/root/p4c/backends/dpdk/dpdk.def"
const IR::Key *IR::DpdkTable::getKey() const {
        auto kp = properties->getProperty(TableProperties::keyPropertyName);
        if (kp == nullptr)
            return nullptr;
        if (!kp->value->is<IR::Key>()) {
            ::P4::error(ErrorType::ERR_INVALID, "%1%: must be a key", kp);
            return nullptr; }
        return kp->value->to<IR::Key>(); }
#line 10267 "/root/p4c/build/ir/ir-generated.cpp"
#line 63 "/root/p4c/backends/dpdk/dpdk.def"
const IR::EntriesList *IR::DpdkTable::getEntries() const {
        auto ep = properties->getProperty(TableProperties::entriesPropertyName);
        if (ep == nullptr)
            return nullptr;
        if (!ep->value->is<IR::EntriesList>()) {
            ::P4::error(ErrorType::ERR_INVALID, "%1%: must be a list of entries", ep);
            return nullptr;
        }
        return ep->value->to<IR::EntriesList>();
    }
#line 10279 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkTable::operator==(IR::DpdkTable const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && match_keys == a.match_keys
        && actions == a.actions
        && default_action == a.default_action
        && properties == a.properties
        && default_action_paraList == a.default_action_paraList;
    }
bool IR::DpdkTable::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const DpdkTable &>(a_);
        return name == a.name
        && (match_keys ? a.match_keys ? match_keys->equiv(*a.match_keys) : false : a.match_keys == nullptr)
        && (actions ? a.actions ? actions->equiv(*a.actions) : false : a.actions == nullptr)
        && (default_action ? a.default_action ? default_action->equiv(*a.default_action) : false : a.default_action == nullptr)
        && (properties ? a.properties ? properties->equiv(*a.properties) : false : a.properties == nullptr)
        && default_action_paraList.equiv(a.default_action_paraList);
    }
void IR::DpdkTable::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(match_keys, "match_keys");
    v.visit(actions, "actions");
    v.visit(default_action, "default_action");
    v.visit(properties, "properties");
    default_action_paraList.visit_children(v, "default_action_paraList");
}
void IR::DpdkTable::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(match_keys, "match_keys");
    v.visit(actions, "actions");
    v.visit(default_action, "default_action");
    v.visit(properties, "properties");
    default_action_paraList.visit_children(v, "default_action_paraList");
}
void IR::DpdkTable::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::DpdkTable::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    json.emit("match_keys", match_keys);
    json.emit("actions", actions);
    json.emit("default_action", default_action);
    json.emit("properties", properties);
    json.emit("default_action_paraList", default_action_paraList);
}
IR::DpdkTable::DpdkTable(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("match_keys", match_keys);
    json.load("actions", actions);
    json.load("default_action", default_action);
    json.load("properties", properties);
    json.load("default_action_paraList", default_action_paraList);
}
IR::Node * IR::DpdkTable::fromJSON(JSONLoader & json) { return new DpdkTable(json); }
bool IR::DpdkTable::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkSelector::operator==(IR::DpdkSelector const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && group_id == a.group_id
        && member_id == a.member_id
        && selectors == a.selectors
        && n_groups_max == a.n_groups_max
        && n_members_per_group_max == a.n_members_per_group_max;
    }
bool IR::DpdkSelector::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const DpdkSelector &>(a_);
        return name == a.name
        && (group_id ? a.group_id ? group_id->equiv(*a.group_id) : false : a.group_id == nullptr)
        && (member_id ? a.member_id ? member_id->equiv(*a.member_id) : false : a.member_id == nullptr)
        && (selectors ? a.selectors ? selectors->equiv(*a.selectors) : false : a.selectors == nullptr)
        && n_groups_max == a.n_groups_max
        && n_members_per_group_max == a.n_members_per_group_max;
    }
void IR::DpdkSelector::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(group_id, "group_id");
    v.visit(member_id, "member_id");
    v.visit(selectors, "selectors");
}
void IR::DpdkSelector::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(group_id, "group_id");
    v.visit(member_id, "member_id");
    v.visit(selectors, "selectors");
}
void IR::DpdkSelector::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " n_groups_max=" << n_groups_max;
        out << " n_members_per_group_max=" << n_members_per_group_max;
}
void IR::DpdkSelector::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    json.emit("group_id", group_id);
    json.emit("member_id", member_id);
    json.emit("selectors", selectors);
    json.emit("n_groups_max", n_groups_max);
    json.emit("n_members_per_group_max", n_members_per_group_max);
}
IR::DpdkSelector::DpdkSelector(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("group_id", group_id);
    json.load("member_id", member_id);
    json.load("selectors", selectors);
    json.load("n_groups_max", n_groups_max);
    json.load("n_members_per_group_max", n_members_per_group_max);
}
IR::Node * IR::DpdkSelector::fromJSON(JSONLoader & json) { return new DpdkSelector(json); }
bool IR::DpdkSelector::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkLearner::operator==(IR::DpdkLearner const & a) const {
        return this->typeId() == a.typeId()
        && name == a.name
        && match_keys == a.match_keys
        && actions == a.actions
        && default_action == a.default_action
        && properties == a.properties;
    }
bool IR::DpdkLearner::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const DpdkLearner &>(a_);
        return name == a.name
        && (match_keys ? a.match_keys ? match_keys->equiv(*a.match_keys) : false : a.match_keys == nullptr)
        && (actions ? a.actions ? actions->equiv(*a.actions) : false : a.actions == nullptr)
        && (default_action ? a.default_action ? default_action->equiv(*a.default_action) : false : a.default_action == nullptr)
        && (properties ? a.properties ? properties->equiv(*a.properties) : false : a.properties == nullptr);
    }
void IR::DpdkLearner::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(match_keys, "match_keys");
    v.visit(actions, "actions");
    v.visit(default_action, "default_action");
    v.visit(properties, "properties");
}
void IR::DpdkLearner::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(match_keys, "match_keys");
    v.visit(actions, "actions");
    v.visit(default_action, "default_action");
    v.visit(properties, "properties");
}
void IR::DpdkLearner::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::DpdkLearner::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("name", name);
    json.emit("match_keys", match_keys);
    json.emit("actions", actions);
    json.emit("default_action", default_action);
    json.emit("properties", properties);
}
IR::DpdkLearner::DpdkLearner(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("match_keys", match_keys);
    json.load("actions", actions);
    json.load("default_action", default_action);
    json.load("properties", properties);
}
IR::Node * IR::DpdkLearner::fromJSON(JSONLoader & json) { return new DpdkLearner(json); }
bool IR::DpdkLearner::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkAsmProgram::operator==(IR::DpdkAsmProgram const & a) const {
        return this->typeId() == a.typeId()
        && headerType == a.headerType
        && structType == a.structType
        && headerInstance == a.headerInstance
        && externDeclarations == a.externDeclarations
        && actions == a.actions
        && tables == a.tables
        && selectors == a.selectors
        && learners == a.learners
        && statements == a.statements
        && globals == a.globals;
    }
bool IR::DpdkAsmProgram::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const DpdkAsmProgram &>(a_);
        return headerType.equiv(a.headerType)
        && structType.equiv(a.structType)
        && headerInstance.equiv(a.headerInstance)
        && externDeclarations.equiv(a.externDeclarations)
        && actions.equiv(a.actions)
        && tables.equiv(a.tables)
        && selectors.equiv(a.selectors)
        && learners.equiv(a.learners)
        && statements.equiv(a.statements)
        && globals.equiv(a.globals);
    }
void IR::DpdkAsmProgram::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    headerType.visit_children(v, "headerType");
    structType.visit_children(v, "structType");
    headerInstance.visit_children(v, "headerInstance");
    externDeclarations.visit_children(v, "externDeclarations");
    actions.visit_children(v, "actions");
    tables.visit_children(v, "tables");
    selectors.visit_children(v, "selectors");
    learners.visit_children(v, "learners");
    statements.visit_children(v, "statements");
    globals.visit_children(v, "globals");
}
void IR::DpdkAsmProgram::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    headerType.visit_children(v, "headerType");
    structType.visit_children(v, "structType");
    headerInstance.visit_children(v, "headerInstance");
    externDeclarations.visit_children(v, "externDeclarations");
    actions.visit_children(v, "actions");
    tables.visit_children(v, "tables");
    selectors.visit_children(v, "selectors");
    learners.visit_children(v, "learners");
    statements.visit_children(v, "statements");
    globals.visit_children(v, "globals");
}
void IR::DpdkAsmProgram::validate() const {
#line 10512 "/root/p4c/build/ir/ir-generated.cpp"

        headerType.validate();
        structType.validate();
        headerInstance.validate();
        externDeclarations.validate();
        actions.validate();
        tables.validate();
        selectors.validate();
        learners.validate();
        statements.validate();
        globals.validate(); }
void IR::DpdkAsmProgram::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("headerType", headerType);
    json.emit("structType", structType);
    json.emit("headerInstance", headerInstance);
    json.emit("externDeclarations", externDeclarations);
    json.emit("actions", actions);
    json.emit("tables", tables);
    json.emit("selectors", selectors);
    json.emit("learners", learners);
    json.emit("statements", statements);
    json.emit("globals", globals);
}
IR::DpdkAsmProgram::DpdkAsmProgram(JSONLoader & json) : Node(json) {
    json.load("headerType", headerType);
    json.load("structType", structType);
    json.load("headerInstance", headerInstance);
    json.load("externDeclarations", externDeclarations);
    json.load("actions", actions);
    json.load("tables", tables);
    json.load("selectors", selectors);
    json.load("learners", learners);
    json.load("statements", statements);
    json.load("globals", globals);
}
IR::Node * IR::DpdkAsmProgram::fromJSON(JSONLoader & json) { return new DpdkAsmProgram(json); }
bool IR::DpdkAsmProgram::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkListStatement::operator==(IR::DpdkListStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && statements == a.statements;
    }
bool IR::DpdkListStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkListStatement &>(a_);
        return statements.equiv(a.statements);
    }
void IR::DpdkListStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    statements.visit_children(v, "statements");
}
void IR::DpdkListStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    statements.visit_children(v, "statements");
}
void IR::DpdkListStatement::validate() const {
#line 10572 "/root/p4c/build/ir/ir-generated.cpp"

        statements.validate(); }
void IR::DpdkListStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("statements", statements);
}
IR::DpdkListStatement::DpdkListStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("statements", statements);
}
IR::Node * IR::DpdkListStatement::fromJSON(JSONLoader & json) { return new DpdkListStatement(json); }
bool IR::DpdkListStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkListStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkApplyStatement::operator==(IR::DpdkApplyStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && table == a.table;
    }
bool IR::DpdkApplyStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkApplyStatement &>(a_);
        return table == a.table;
    }
void IR::DpdkApplyStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " table=" << table;
}
void IR::DpdkApplyStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("table", table);
}
IR::DpdkApplyStatement::DpdkApplyStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("table", table);
}
IR::Node * IR::DpdkApplyStatement::fromJSON(JSONLoader & json) { return new DpdkApplyStatement(json); }
bool IR::DpdkApplyStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkApplyStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkLearnStatement::operator==(IR::DpdkLearnStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && action == a.action
        && timeout == a.timeout
        && argument == a.argument;
    }
bool IR::DpdkLearnStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkLearnStatement &>(a_);
        return action == a.action
        && (timeout ? a.timeout ? timeout->equiv(*a.timeout) : false : a.timeout == nullptr)
        && (argument ? a.argument ? argument->equiv(*a.argument) : false : a.argument == nullptr);
    }
void IR::DpdkLearnStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(timeout, "timeout");
    v.visit(argument, "argument");
}
void IR::DpdkLearnStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(timeout, "timeout");
    v.visit(argument, "argument");
}
void IR::DpdkLearnStatement::validate() const {
#line 10636 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(timeout); }
void IR::DpdkLearnStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " action=" << action;
}
void IR::DpdkLearnStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("action", action);
    json.emit("timeout", timeout);
    if (argument != nullptr) json.emit("argument", argument);
}
IR::DpdkLearnStatement::DpdkLearnStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("action", action);
    json.load("timeout", timeout);
    json.load("argument", argument);
}
IR::Node * IR::DpdkLearnStatement::fromJSON(JSONLoader & json) { return new DpdkLearnStatement(json); }
bool IR::DpdkLearnStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkLearnStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkMirrorStatement::operator==(IR::DpdkMirrorStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && slotId == a.slotId
        && sessionId == a.sessionId;
    }
bool IR::DpdkMirrorStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkMirrorStatement &>(a_);
        return (slotId ? a.slotId ? slotId->equiv(*a.slotId) : false : a.slotId == nullptr)
        && (sessionId ? a.sessionId ? sessionId->equiv(*a.sessionId) : false : a.sessionId == nullptr);
    }
void IR::DpdkMirrorStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(slotId, "slotId");
    v.visit(sessionId, "sessionId");
}
void IR::DpdkMirrorStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(slotId, "slotId");
    v.visit(sessionId, "sessionId");
}
void IR::DpdkMirrorStatement::validate() const {
#line 10682 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(slotId);
        CHECK_NULL(sessionId); }
void IR::DpdkMirrorStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("slotId", slotId);
    json.emit("sessionId", sessionId);
}
IR::DpdkMirrorStatement::DpdkMirrorStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("slotId", slotId);
    json.load("sessionId", sessionId);
}
IR::Node * IR::DpdkMirrorStatement::fromJSON(JSONLoader & json) { return new DpdkMirrorStatement(json); }
bool IR::DpdkMirrorStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkMirrorStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkEmitStatement::operator==(IR::DpdkEmitStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && header == a.header;
    }
bool IR::DpdkEmitStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkEmitStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr);
    }
void IR::DpdkEmitStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(header, "header");
}
void IR::DpdkEmitStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(header, "header");
}
void IR::DpdkEmitStatement::validate() const {
#line 10719 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkEmitStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("header", header);
}
IR::DpdkEmitStatement::DpdkEmitStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("header", header);
}
IR::Node * IR::DpdkEmitStatement::fromJSON(JSONLoader & json) { return new DpdkEmitStatement(json); }
bool IR::DpdkEmitStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkEmitStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkExtractStatement::operator==(IR::DpdkExtractStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && header == a.header
        && length == a.length;
    }
bool IR::DpdkExtractStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkExtractStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr)
        && (length ? a.length ? length->equiv(*a.length) : false : a.length == nullptr);
    }
void IR::DpdkExtractStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(header, "header");
    v.visit(length, "length");
}
void IR::DpdkExtractStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(header, "header");
    v.visit(length, "length");
}
void IR::DpdkExtractStatement::validate() const {
#line 10757 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkExtractStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("header", header);
    if (length != nullptr) json.emit("length", length);
}
IR::DpdkExtractStatement::DpdkExtractStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("header", header);
    json.load("length", length);
}
IR::Node * IR::DpdkExtractStatement::fromJSON(JSONLoader & json) { return new DpdkExtractStatement(json); }
bool IR::DpdkExtractStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkExtractStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkLookaheadStatement::operator==(IR::DpdkLookaheadStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && header == a.header;
    }
bool IR::DpdkLookaheadStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkLookaheadStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr);
    }
void IR::DpdkLookaheadStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(header, "header");
}
void IR::DpdkLookaheadStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(header, "header");
}
void IR::DpdkLookaheadStatement::validate() const {
#line 10793 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkLookaheadStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("header", header);
}
IR::DpdkLookaheadStatement::DpdkLookaheadStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("header", header);
}
IR::Node * IR::DpdkLookaheadStatement::fromJSON(JSONLoader & json) { return new DpdkLookaheadStatement(json); }
bool IR::DpdkLookaheadStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkLookaheadStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 166 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpStatement::DpdkJmpStatement(cstring instruction, cstring l) :
        instruction(instruction), label(l.toUpper()) { }
#line 10809 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpStatement::operator==(IR::DpdkJmpStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && instruction == a.instruction
        && label == a.label;
    }
bool IR::DpdkJmpStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkJmpStatement &>(a_);
        return instruction == a.instruction
        && label == a.label;
    }
void IR::DpdkJmpStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " instruction=" << instruction;
        out << " label=" << label;
}
void IR::DpdkJmpStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("instruction", instruction);
    json.emit("label", label);
}
IR::DpdkJmpStatement::DpdkJmpStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("instruction", instruction);
    json.load("label", label);
}
bool IR::DpdkJmpStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 172 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpLabelStatement::DpdkJmpLabelStatement(cstring label) :
        DpdkJmpStatement("jmp"_cs, label) { }
#line 10841 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpLabelStatement::operator==(IR::DpdkJmpLabelStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a));
    }
bool IR::DpdkJmpLabelStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpLabelStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
}
IR::DpdkJmpLabelStatement::DpdkJmpLabelStatement(JSONLoader & json) : DpdkJmpStatement(json) {
}
IR::Node * IR::DpdkJmpLabelStatement::fromJSON(JSONLoader & json) { return new DpdkJmpLabelStatement(json); }
bool IR::DpdkJmpLabelStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpLabelStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpLabelStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 179 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpHitStatement::DpdkJmpHitStatement(cstring label) :
        DpdkJmpStatement("jmph"_cs, label) { }
#line 10862 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpHitStatement::operator==(IR::DpdkJmpHitStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a));
    }
bool IR::DpdkJmpHitStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpHitStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
}
IR::DpdkJmpHitStatement::DpdkJmpHitStatement(JSONLoader & json) : DpdkJmpStatement(json) {
}
IR::Node * IR::DpdkJmpHitStatement::fromJSON(JSONLoader & json) { return new DpdkJmpHitStatement(json); }
bool IR::DpdkJmpHitStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpHitStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpHitStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 186 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpMissStatement::DpdkJmpMissStatement(cstring label) :
        DpdkJmpStatement("jmpnh"_cs, label) { }
#line 10883 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpMissStatement::operator==(IR::DpdkJmpMissStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a));
    }
bool IR::DpdkJmpMissStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpMissStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
}
IR::DpdkJmpMissStatement::DpdkJmpMissStatement(JSONLoader & json) : DpdkJmpStatement(json) {
}
IR::Node * IR::DpdkJmpMissStatement::fromJSON(JSONLoader & json) { return new DpdkJmpMissStatement(json); }
bool IR::DpdkJmpMissStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpMissStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpMissStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 195 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpActionStatement::DpdkJmpActionStatement(cstring instruction, cstring label, IR::ID action) :
        DpdkJmpStatement(instruction, label), action(action) { }
#line 10904 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpActionStatement::operator==(IR::DpdkJmpActionStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a))
        && action == a.action;
    }
bool IR::DpdkJmpActionStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkJmpActionStatement &>(a_);
        return action == a.action;
    }
void IR::DpdkJmpActionStatement::dump_fields(std::ostream & out) const {
    DpdkJmpStatement::dump_fields(out);
        out << " action=" << action;
}
void IR::DpdkJmpActionStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
    json.emit("action", action);
}
IR::DpdkJmpActionStatement::DpdkJmpActionStatement(JSONLoader & json) : DpdkJmpStatement(json) {
    json.load("action", action);
}
bool IR::DpdkJmpActionStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpActionStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpActionStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 202 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpIfActionRunStatement::DpdkJmpIfActionRunStatement(cstring label, cstring act) :
        DpdkJmpActionStatement("jmpa"_cs, label, act) { }
#line 10932 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpIfActionRunStatement::operator==(IR::DpdkJmpIfActionRunStatement const & a) const {
        return DpdkJmpActionStatement::operator==(static_cast<const DpdkJmpActionStatement &>(a));
    }
bool IR::DpdkJmpIfActionRunStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpActionStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpIfActionRunStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpActionStatement::toJSON(json);
}
IR::DpdkJmpIfActionRunStatement::DpdkJmpIfActionRunStatement(JSONLoader & json) : DpdkJmpActionStatement(json) {
}
IR::Node * IR::DpdkJmpIfActionRunStatement::fromJSON(JSONLoader & json) { return new DpdkJmpIfActionRunStatement(json); }
bool IR::DpdkJmpIfActionRunStatement::operator==(IR::DpdkJmpActionStatement const & a) const { return a == *this; }
bool IR::DpdkJmpIfActionRunStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpIfActionRunStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpIfActionRunStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 209 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpIfActionNotRunStatement::DpdkJmpIfActionNotRunStatement(cstring label, cstring act) :
        DpdkJmpActionStatement("jmpna"_cs, label, act) { }
#line 10954 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpIfActionNotRunStatement::operator==(IR::DpdkJmpIfActionNotRunStatement const & a) const {
        return DpdkJmpActionStatement::operator==(static_cast<const DpdkJmpActionStatement &>(a));
    }
bool IR::DpdkJmpIfActionNotRunStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpActionStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpIfActionNotRunStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpActionStatement::toJSON(json);
}
IR::DpdkJmpIfActionNotRunStatement::DpdkJmpIfActionNotRunStatement(JSONLoader & json) : DpdkJmpActionStatement(json) {
}
IR::Node * IR::DpdkJmpIfActionNotRunStatement::fromJSON(JSONLoader & json) { return new DpdkJmpIfActionNotRunStatement(json); }
bool IR::DpdkJmpIfActionNotRunStatement::operator==(IR::DpdkJmpActionStatement const & a) const { return a == *this; }
bool IR::DpdkJmpIfActionNotRunStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpIfActionNotRunStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpIfActionNotRunStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 217 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpHeaderStatement::DpdkJmpHeaderStatement(cstring instruction, cstring label, const IR::Expression* hdr) :
        DpdkJmpStatement(instruction, label), header(hdr) { }
#line 10976 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpHeaderStatement::operator==(IR::DpdkJmpHeaderStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a))
        && header == a.header;
    }
bool IR::DpdkJmpHeaderStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkJmpHeaderStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr);
    }
void IR::DpdkJmpHeaderStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkJmpStatement::visit_children(v, n);
    v.visit(header, "header");
}
void IR::DpdkJmpHeaderStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkJmpStatement::visit_children(v, n);
    v.visit(header, "header");
}
void IR::DpdkJmpHeaderStatement::validate() const {
#line 10998 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkJmpHeaderStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
    json.emit("header", header);
}
IR::DpdkJmpHeaderStatement::DpdkJmpHeaderStatement(JSONLoader & json) : DpdkJmpStatement(json) {
    json.load("header", header);
}
bool IR::DpdkJmpHeaderStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpHeaderStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpHeaderStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 223 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpIfInvalidStatement::DpdkJmpIfInvalidStatement(cstring label, const IR::Expression* hdr) :
        DpdkJmpHeaderStatement("jmpnv"_cs, label, hdr) { }
#line 11014 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpIfInvalidStatement::operator==(IR::DpdkJmpIfInvalidStatement const & a) const {
        return DpdkJmpHeaderStatement::operator==(static_cast<const DpdkJmpHeaderStatement &>(a));
    }
bool IR::DpdkJmpIfInvalidStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpHeaderStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpIfInvalidStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpHeaderStatement::toJSON(json);
}
IR::DpdkJmpIfInvalidStatement::DpdkJmpIfInvalidStatement(JSONLoader & json) : DpdkJmpHeaderStatement(json) {
}
IR::Node * IR::DpdkJmpIfInvalidStatement::fromJSON(JSONLoader & json) { return new DpdkJmpIfInvalidStatement(json); }
bool IR::DpdkJmpIfInvalidStatement::operator==(IR::DpdkJmpHeaderStatement const & a) const { return a == *this; }
bool IR::DpdkJmpIfInvalidStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpIfInvalidStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpIfInvalidStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 230 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpIfValidStatement::DpdkJmpIfValidStatement(cstring label, const IR::Expression* hdr) :
        DpdkJmpHeaderStatement("jmpv"_cs, label, hdr) { }
#line 11036 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpIfValidStatement::operator==(IR::DpdkJmpIfValidStatement const & a) const {
        return DpdkJmpHeaderStatement::operator==(static_cast<const DpdkJmpHeaderStatement &>(a));
    }
bool IR::DpdkJmpIfValidStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpHeaderStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpIfValidStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpHeaderStatement::toJSON(json);
}
IR::DpdkJmpIfValidStatement::DpdkJmpIfValidStatement(JSONLoader & json) : DpdkJmpHeaderStatement(json) {
}
IR::Node * IR::DpdkJmpIfValidStatement::fromJSON(JSONLoader & json) { return new DpdkJmpIfValidStatement(json); }
bool IR::DpdkJmpIfValidStatement::operator==(IR::DpdkJmpHeaderStatement const & a) const { return a == *this; }
bool IR::DpdkJmpIfValidStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpIfValidStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpIfValidStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 239 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpCondStatement::DpdkJmpCondStatement(cstring instruction, cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpStatement(instruction, label), src1(src1), src2(src2) { }
#line 11058 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpCondStatement::operator==(IR::DpdkJmpCondStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a))
        && src1 == a.src1
        && src2 == a.src2;
    }
bool IR::DpdkJmpCondStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkJmpCondStatement &>(a_);
        return (src1 ? a.src1 ? src1->equiv(*a.src1) : false : a.src1 == nullptr)
        && (src2 ? a.src2 ? src2->equiv(*a.src2) : false : a.src2 == nullptr);
    }
void IR::DpdkJmpCondStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkJmpStatement::visit_children(v, n);
    v.visit(src1, "src1");
    v.visit(src2, "src2");
}
void IR::DpdkJmpCondStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkJmpStatement::visit_children(v, n);
    v.visit(src1, "src1");
    v.visit(src2, "src2");
}
void IR::DpdkJmpCondStatement::validate() const {
#line 11084 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(src1);
        CHECK_NULL(src2); }
void IR::DpdkJmpCondStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
    json.emit("src1", src1);
    json.emit("src2", src2);
}
IR::DpdkJmpCondStatement::DpdkJmpCondStatement(JSONLoader & json) : DpdkJmpStatement(json) {
    json.load("src1", src1);
    json.load("src2", src2);
}
bool IR::DpdkJmpCondStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpCondStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpCondStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 244 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpEqualStatement::DpdkJmpEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmpeq"_cs, label, src1, src2) { }
#line 11103 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpEqualStatement::operator==(IR::DpdkJmpEqualStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpEqualStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpEqualStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpEqualStatement::DpdkJmpEqualStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpEqualStatement::fromJSON(JSONLoader & json) { return new DpdkJmpEqualStatement(json); }
bool IR::DpdkJmpEqualStatement::operator==(IR::DpdkJmpCondStatement const & a) const { return a == *this; }
bool IR::DpdkJmpEqualStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpEqualStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpEqualStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 251 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpNotEqualStatement::DpdkJmpNotEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmpneq"_cs, label, src1, src2) { }
#line 11125 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpNotEqualStatement::operator==(IR::DpdkJmpNotEqualStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpNotEqualStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpNotEqualStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpNotEqualStatement::DpdkJmpNotEqualStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpNotEqualStatement::fromJSON(JSONLoader & json) { return new DpdkJmpNotEqualStatement(json); }
bool IR::DpdkJmpNotEqualStatement::operator==(IR::DpdkJmpCondStatement const & a) const { return a == *this; }
bool IR::DpdkJmpNotEqualStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpNotEqualStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpNotEqualStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 258 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpGreaterEqualStatement::DpdkJmpGreaterEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmpge"_cs, label, src1, src2) { }
#line 11147 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpGreaterEqualStatement::operator==(IR::DpdkJmpGreaterEqualStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpGreaterEqualStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpGreaterEqualStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpGreaterEqualStatement::DpdkJmpGreaterEqualStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpGreaterEqualStatement::fromJSON(JSONLoader & json) { return new DpdkJmpGreaterEqualStatement(json); }
bool IR::DpdkJmpGreaterEqualStatement::operator==(IR::DpdkJmpCondStatement const & a) const { return a == *this; }
bool IR::DpdkJmpGreaterEqualStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpGreaterEqualStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpGreaterEqualStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 265 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpGreaterStatement::DpdkJmpGreaterStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmpgt"_cs, label, src1, src2) { }
#line 11169 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpGreaterStatement::operator==(IR::DpdkJmpGreaterStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpGreaterStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpGreaterStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpGreaterStatement::DpdkJmpGreaterStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpGreaterStatement::fromJSON(JSONLoader & json) { return new DpdkJmpGreaterStatement(json); }
bool IR::DpdkJmpGreaterStatement::operator==(IR::DpdkJmpCondStatement const & a) const { return a == *this; }
bool IR::DpdkJmpGreaterStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpGreaterStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpGreaterStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 272 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpLessOrEqualStatement::DpdkJmpLessOrEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmple"_cs, label, src1, src2) { }
#line 11191 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpLessOrEqualStatement::operator==(IR::DpdkJmpLessOrEqualStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpLessOrEqualStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpLessOrEqualStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpLessOrEqualStatement::DpdkJmpLessOrEqualStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpLessOrEqualStatement::fromJSON(JSONLoader & json) { return new DpdkJmpLessOrEqualStatement(json); }
bool IR::DpdkJmpLessOrEqualStatement::operator==(IR::DpdkJmpCondStatement const & a) const { return a == *this; }
bool IR::DpdkJmpLessOrEqualStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpLessOrEqualStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpLessOrEqualStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 279 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpLessStatement::DpdkJmpLessStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmplt"_cs, label, src1, src2) { }
#line 11213 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpLessStatement::operator==(IR::DpdkJmpLessStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpLessStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpLessStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpLessStatement::DpdkJmpLessStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpLessStatement::fromJSON(JSONLoader & json) { return new DpdkJmpLessStatement(json); }
bool IR::DpdkJmpLessStatement::operator==(IR::DpdkJmpCondStatement const & a) const { return a == *this; }
bool IR::DpdkJmpLessStatement::operator==(IR::DpdkJmpStatement const & a) const { return a == *this; }
bool IR::DpdkJmpLessStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkJmpLessStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkRxStatement::operator==(IR::DpdkRxStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && port == a.port;
    }
bool IR::DpdkRxStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkRxStatement &>(a_);
        return (port ? a.port ? port->equiv(*a.port) : false : a.port == nullptr);
    }
void IR::DpdkRxStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(port, "port");
}
void IR::DpdkRxStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(port, "port");
}
void IR::DpdkRxStatement::validate() const {
#line 11253 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(port); }
void IR::DpdkRxStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("port", port);
}
IR::DpdkRxStatement::DpdkRxStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("port", port);
}
IR::Node * IR::DpdkRxStatement::fromJSON(JSONLoader & json) { return new DpdkRxStatement(json); }
bool IR::DpdkRxStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkRxStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkTxStatement::operator==(IR::DpdkTxStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && port == a.port;
    }
bool IR::DpdkTxStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkTxStatement &>(a_);
        return (port ? a.port ? port->equiv(*a.port) : false : a.port == nullptr);
    }
void IR::DpdkTxStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(port, "port");
}
void IR::DpdkTxStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(port, "port");
}
void IR::DpdkTxStatement::validate() const {
#line 11287 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(port); }
void IR::DpdkTxStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("port", port);
}
IR::DpdkTxStatement::DpdkTxStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("port", port);
}
IR::Node * IR::DpdkTxStatement::fromJSON(JSONLoader & json) { return new DpdkTxStatement(json); }
bool IR::DpdkTxStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkTxStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 299 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkAssignmentStatement::DpdkAssignmentStatement(cstring instruction, const IR::Expression* dst) :
        instruction(instruction), dst(dst) { }
#line 11303 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkAssignmentStatement::operator==(IR::DpdkAssignmentStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && instruction == a.instruction
        && dst == a.dst;
    }
bool IR::DpdkAssignmentStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkAssignmentStatement &>(a_);
        return instruction == a.instruction
        && (dst ? a.dst ? dst->equiv(*a.dst) : false : a.dst == nullptr);
    }
void IR::DpdkAssignmentStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(dst, "dst");
}
void IR::DpdkAssignmentStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(dst, "dst");
}
void IR::DpdkAssignmentStatement::validate() const {
#line 11327 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(dst); }
void IR::DpdkAssignmentStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " instruction=" << instruction;
}
void IR::DpdkAssignmentStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("instruction", instruction);
    json.emit("dst", dst);
}
IR::DpdkAssignmentStatement::DpdkAssignmentStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("instruction", instruction);
    json.load("dst", dst);
}
bool IR::DpdkAssignmentStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkAssignmentStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 307 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkUnaryStatement::DpdkUnaryStatement(cstring instruction, const IR::Expression* dst, const IR::Expression* src) :
        DpdkAssignmentStatement(instruction, dst), src(src) { }
#line 11348 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkUnaryStatement::operator==(IR::DpdkUnaryStatement const & a) const {
        return DpdkAssignmentStatement::operator==(static_cast<const DpdkAssignmentStatement &>(a))
        && src == a.src;
    }
bool IR::DpdkUnaryStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAssignmentStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkUnaryStatement &>(a_);
        return (src ? a.src ? src->equiv(*a.src) : false : a.src == nullptr);
    }
void IR::DpdkUnaryStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAssignmentStatement::visit_children(v, n);
    v.visit(src, "src");
}
void IR::DpdkUnaryStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAssignmentStatement::visit_children(v, n);
    v.visit(src, "src");
}
void IR::DpdkUnaryStatement::validate() const {
#line 11370 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(src); }
void IR::DpdkUnaryStatement::toJSON(JSONGenerator & json) const {
    DpdkAssignmentStatement::toJSON(json);
    json.emit("src", src);
}
IR::DpdkUnaryStatement::DpdkUnaryStatement(JSONLoader & json) : DpdkAssignmentStatement(json) {
    json.load("src", src);
}
bool IR::DpdkUnaryStatement::operator==(IR::DpdkAssignmentStatement const & a) const { return a == *this; }
bool IR::DpdkUnaryStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkUnaryStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 312 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkMovStatement::DpdkMovStatement(const IR::Expression* dst, const IR::Expression* src) :
        DpdkUnaryStatement("mov"_cs, dst, src) { }
#line 11386 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkMovStatement::operator==(IR::DpdkMovStatement const & a) const {
        return DpdkUnaryStatement::operator==(static_cast<const DpdkUnaryStatement &>(a));
    }
bool IR::DpdkMovStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkUnaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkMovStatement::toJSON(JSONGenerator & json) const {
    DpdkUnaryStatement::toJSON(json);
}
IR::DpdkMovStatement::DpdkMovStatement(JSONLoader & json) : DpdkUnaryStatement(json) {
}
IR::Node * IR::DpdkMovStatement::fromJSON(JSONLoader & json) { return new DpdkMovStatement(json); }
bool IR::DpdkMovStatement::operator==(IR::DpdkUnaryStatement const & a) const { return a == *this; }
bool IR::DpdkMovStatement::operator==(IR::DpdkAssignmentStatement const & a) const { return a == *this; }
bool IR::DpdkMovStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkMovStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 318 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkMovhStatement::DpdkMovhStatement(const IR::Expression* dst, const IR::Expression* src) :
        DpdkUnaryStatement("movh"_cs, dst, src) { }
#line 11408 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkMovhStatement::operator==(IR::DpdkMovhStatement const & a) const {
        return DpdkUnaryStatement::operator==(static_cast<const DpdkUnaryStatement &>(a));
    }
bool IR::DpdkMovhStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkUnaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkMovhStatement::toJSON(JSONGenerator & json) const {
    DpdkUnaryStatement::toJSON(json);
}
IR::DpdkMovhStatement::DpdkMovhStatement(JSONLoader & json) : DpdkUnaryStatement(json) {
}
IR::Node * IR::DpdkMovhStatement::fromJSON(JSONLoader & json) { return new DpdkMovhStatement(json); }
bool IR::DpdkMovhStatement::operator==(IR::DpdkUnaryStatement const & a) const { return a == *this; }
bool IR::DpdkMovhStatement::operator==(IR::DpdkAssignmentStatement const & a) const { return a == *this; }
bool IR::DpdkMovhStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkMovhStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 328 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkBinaryStatement::DpdkBinaryStatement(cstring instruction, const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkAssignmentStatement(instruction, dst), src1(src1), src2(src2) { }
#line 11430 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkBinaryStatement::operator==(IR::DpdkBinaryStatement const & a) const {
        return DpdkAssignmentStatement::operator==(static_cast<const DpdkAssignmentStatement &>(a))
        && src1 == a.src1
        && src2 == a.src2;
    }
bool IR::DpdkBinaryStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAssignmentStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkBinaryStatement &>(a_);
        return (src1 ? a.src1 ? src1->equiv(*a.src1) : false : a.src1 == nullptr)
        && (src2 ? a.src2 ? src2->equiv(*a.src2) : false : a.src2 == nullptr);
    }
void IR::DpdkBinaryStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAssignmentStatement::visit_children(v, n);
    v.visit(src1, "src1");
    v.visit(src2, "src2");
}
void IR::DpdkBinaryStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAssignmentStatement::visit_children(v, n);
    v.visit(src1, "src1");
    v.visit(src2, "src2");
}
void IR::DpdkBinaryStatement::validate() const {
#line 11456 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(src1);
        CHECK_NULL(src2); }
void IR::DpdkBinaryStatement::toJSON(JSONGenerator & json) const {
    DpdkAssignmentStatement::toJSON(json);
    json.emit("src1", src1);
    json.emit("src2", src2);
}
IR::DpdkBinaryStatement::DpdkBinaryStatement(JSONLoader & json) : DpdkAssignmentStatement(json) {
    json.load("src1", src1);
    json.load("src2", src2);
}
bool IR::DpdkBinaryStatement::operator==(IR::DpdkAssignmentStatement const & a) const { return a == *this; }
bool IR::DpdkBinaryStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkBinaryStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 335 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkAddStatement::DpdkAddStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("add"_cs, dst, src1, src2) { }
#line 11475 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkAddStatement::operator==(IR::DpdkAddStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkAddStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkAddStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkAddStatement::DpdkAddStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkAddStatement::fromJSON(JSONLoader & json) { return new DpdkAddStatement(json); }
bool IR::DpdkAddStatement::operator==(IR::DpdkBinaryStatement const & a) const { return a == *this; }
bool IR::DpdkAddStatement::operator==(IR::DpdkAssignmentStatement const & a) const { return a == *this; }
bool IR::DpdkAddStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkAddStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 342 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkAndStatement::DpdkAndStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("and"_cs, dst, src1, src2) { }
#line 11497 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkAndStatement::operator==(IR::DpdkAndStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkAndStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkAndStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkAndStatement::DpdkAndStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkAndStatement::fromJSON(JSONLoader & json) { return new DpdkAndStatement(json); }
bool IR::DpdkAndStatement::operator==(IR::DpdkBinaryStatement const & a) const { return a == *this; }
bool IR::DpdkAndStatement::operator==(IR::DpdkAssignmentStatement const & a) const { return a == *this; }
bool IR::DpdkAndStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkAndStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 349 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkShlStatement::DpdkShlStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("shl"_cs, dst, src1, src2) { }
#line 11519 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkShlStatement::operator==(IR::DpdkShlStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkShlStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkShlStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkShlStatement::DpdkShlStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkShlStatement::fromJSON(JSONLoader & json) { return new DpdkShlStatement(json); }
bool IR::DpdkShlStatement::operator==(IR::DpdkBinaryStatement const & a) const { return a == *this; }
bool IR::DpdkShlStatement::operator==(IR::DpdkAssignmentStatement const & a) const { return a == *this; }
bool IR::DpdkShlStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkShlStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 356 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkShrStatement::DpdkShrStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("shr"_cs, dst, src1, src2) { }
#line 11541 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkShrStatement::operator==(IR::DpdkShrStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkShrStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkShrStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkShrStatement::DpdkShrStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkShrStatement::fromJSON(JSONLoader & json) { return new DpdkShrStatement(json); }
bool IR::DpdkShrStatement::operator==(IR::DpdkBinaryStatement const & a) const { return a == *this; }
bool IR::DpdkShrStatement::operator==(IR::DpdkAssignmentStatement const & a) const { return a == *this; }
bool IR::DpdkShrStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkShrStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 363 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkSubStatement::DpdkSubStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("sub"_cs, dst, src1, src2) { }
#line 11563 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkSubStatement::operator==(IR::DpdkSubStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkSubStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkSubStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkSubStatement::DpdkSubStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkSubStatement::fromJSON(JSONLoader & json) { return new DpdkSubStatement(json); }
bool IR::DpdkSubStatement::operator==(IR::DpdkBinaryStatement const & a) const { return a == *this; }
bool IR::DpdkSubStatement::operator==(IR::DpdkAssignmentStatement const & a) const { return a == *this; }
bool IR::DpdkSubStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkSubStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 370 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkOrStatement::DpdkOrStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("or"_cs, dst, src1, src2) { }
#line 11585 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkOrStatement::operator==(IR::DpdkOrStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkOrStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkOrStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkOrStatement::DpdkOrStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkOrStatement::fromJSON(JSONLoader & json) { return new DpdkOrStatement(json); }
bool IR::DpdkOrStatement::operator==(IR::DpdkBinaryStatement const & a) const { return a == *this; }
bool IR::DpdkOrStatement::operator==(IR::DpdkAssignmentStatement const & a) const { return a == *this; }
bool IR::DpdkOrStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkOrStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 377 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkXorStatement::DpdkXorStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("xor"_cs, dst, src1, src2) { }
#line 11607 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkXorStatement::operator==(IR::DpdkXorStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkXorStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkXorStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkXorStatement::DpdkXorStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkXorStatement::fromJSON(JSONLoader & json) { return new DpdkXorStatement(json); }
bool IR::DpdkXorStatement::operator==(IR::DpdkBinaryStatement const & a) const { return a == *this; }
bool IR::DpdkXorStatement::operator==(IR::DpdkAssignmentStatement const & a) const { return a == *this; }
bool IR::DpdkXorStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkXorStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkRecircidStatement::operator==(IR::DpdkRecircidStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && pass == a.pass;
    }
bool IR::DpdkRecircidStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkRecircidStatement &>(a_);
        return (pass ? a.pass ? pass->equiv(*a.pass) : false : a.pass == nullptr);
    }
void IR::DpdkRecircidStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(pass, "pass");
}
void IR::DpdkRecircidStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(pass, "pass");
}
void IR::DpdkRecircidStatement::validate() const {
#line 11647 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(pass); }
void IR::DpdkRecircidStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("pass", pass);
}
IR::DpdkRecircidStatement::DpdkRecircidStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("pass", pass);
}
IR::Node * IR::DpdkRecircidStatement::fromJSON(JSONLoader & json) { return new DpdkRecircidStatement(json); }
bool IR::DpdkRecircidStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkRecircidStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkReturnStatement::operator==(IR::DpdkReturnStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a));
    }
bool IR::DpdkReturnStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkReturnStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
}
IR::DpdkReturnStatement::DpdkReturnStatement(JSONLoader & json) : DpdkAsmStatement(json) {
}
IR::Node * IR::DpdkReturnStatement::fromJSON(JSONLoader & json) { return new DpdkReturnStatement(json); }
bool IR::DpdkReturnStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkReturnStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkRearmStatement::operator==(IR::DpdkRearmStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && timeout == a.timeout;
    }
bool IR::DpdkRearmStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkRearmStatement &>(a_);
        return (timeout ? a.timeout ? timeout->equiv(*a.timeout) : false : a.timeout == nullptr);
    }
void IR::DpdkRearmStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(timeout, "timeout");
}
void IR::DpdkRearmStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(timeout, "timeout");
}
void IR::DpdkRearmStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    if (timeout != nullptr) json.emit("timeout", timeout);
}
IR::DpdkRearmStatement::DpdkRearmStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("timeout", timeout);
}
IR::Node * IR::DpdkRearmStatement::fromJSON(JSONLoader & json) { return new DpdkRearmStatement(json); }
bool IR::DpdkRearmStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkRearmStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkRecirculateStatement::operator==(IR::DpdkRecirculateStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a));
    }
bool IR::DpdkRecirculateStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkRecirculateStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
}
IR::DpdkRecirculateStatement::DpdkRecirculateStatement(JSONLoader & json) : DpdkAsmStatement(json) {
}
IR::Node * IR::DpdkRecirculateStatement::fromJSON(JSONLoader & json) { return new DpdkRecirculateStatement(json); }
bool IR::DpdkRecirculateStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkRecirculateStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 407 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkLabelStatement::DpdkLabelStatement(cstring l) : label(l.toUpper()) { }
#line 11724 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkLabelStatement::operator==(IR::DpdkLabelStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && label == a.label;
    }
bool IR::DpdkLabelStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkLabelStatement &>(a_);
        return label == a.label;
    }
void IR::DpdkLabelStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " label=" << label;
}
void IR::DpdkLabelStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("label", label);
}
IR::DpdkLabelStatement::DpdkLabelStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("label", label);
}
IR::Node * IR::DpdkLabelStatement::fromJSON(JSONLoader & json) { return new DpdkLabelStatement(json); }
bool IR::DpdkLabelStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkLabelStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkChecksumAddStatement::operator==(IR::DpdkChecksumAddStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && csum == a.csum
        && intermediate_value == a.intermediate_value
        && field == a.field;
    }
bool IR::DpdkChecksumAddStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkChecksumAddStatement &>(a_);
        return csum == a.csum
        && intermediate_value == a.intermediate_value
        && (field ? a.field ? field->equiv(*a.field) : false : a.field == nullptr);
    }
void IR::DpdkChecksumAddStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(field, "field");
}
void IR::DpdkChecksumAddStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(field, "field");
}
void IR::DpdkChecksumAddStatement::validate() const {
#line 11774 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(field); }
void IR::DpdkChecksumAddStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " csum=" << csum;
        out << " intermediate_value=" << intermediate_value;
}
void IR::DpdkChecksumAddStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("csum", csum);
    json.emit("intermediate_value", intermediate_value);
    json.emit("field", field);
}
IR::DpdkChecksumAddStatement::DpdkChecksumAddStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("csum", csum);
    json.load("intermediate_value", intermediate_value);
    json.load("field", field);
}
IR::Node * IR::DpdkChecksumAddStatement::fromJSON(JSONLoader & json) { return new DpdkChecksumAddStatement(json); }
bool IR::DpdkChecksumAddStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkChecksumAddStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkChecksumSubStatement::operator==(IR::DpdkChecksumSubStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && csum == a.csum
        && intermediate_value == a.intermediate_value
        && field == a.field;
    }
bool IR::DpdkChecksumSubStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkChecksumSubStatement &>(a_);
        return csum == a.csum
        && intermediate_value == a.intermediate_value
        && (field ? a.field ? field->equiv(*a.field) : false : a.field == nullptr);
    }
void IR::DpdkChecksumSubStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(field, "field");
}
void IR::DpdkChecksumSubStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(field, "field");
}
void IR::DpdkChecksumSubStatement::validate() const {
#line 11821 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(field); }
void IR::DpdkChecksumSubStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " csum=" << csum;
        out << " intermediate_value=" << intermediate_value;
}
void IR::DpdkChecksumSubStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("csum", csum);
    json.emit("intermediate_value", intermediate_value);
    json.emit("field", field);
}
IR::DpdkChecksumSubStatement::DpdkChecksumSubStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("csum", csum);
    json.load("intermediate_value", intermediate_value);
    json.load("field", field);
}
IR::Node * IR::DpdkChecksumSubStatement::fromJSON(JSONLoader & json) { return new DpdkChecksumSubStatement(json); }
bool IR::DpdkChecksumSubStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkChecksumSubStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkChecksumClearStatement::operator==(IR::DpdkChecksumClearStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && csum == a.csum
        && intermediate_value == a.intermediate_value;
    }
bool IR::DpdkChecksumClearStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkChecksumClearStatement &>(a_);
        return csum == a.csum
        && intermediate_value == a.intermediate_value;
    }
void IR::DpdkChecksumClearStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " csum=" << csum;
        out << " intermediate_value=" << intermediate_value;
}
void IR::DpdkChecksumClearStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("csum", csum);
    json.emit("intermediate_value", intermediate_value);
}
IR::DpdkChecksumClearStatement::DpdkChecksumClearStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("csum", csum);
    json.load("intermediate_value", intermediate_value);
}
IR::Node * IR::DpdkChecksumClearStatement::fromJSON(JSONLoader & json) { return new DpdkChecksumClearStatement(json); }
bool IR::DpdkChecksumClearStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkChecksumClearStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkHashDeclStatement::operator==(IR::DpdkHashDeclStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && hash == a.hash;
    }
bool IR::DpdkHashDeclStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkHashDeclStatement &>(a_);
        return hash == a.hash;
    }
void IR::DpdkHashDeclStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " hash=" << hash;
}
void IR::DpdkHashDeclStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("hash", hash);
}
IR::DpdkHashDeclStatement::DpdkHashDeclStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("hash", hash);
}
IR::Node * IR::DpdkHashDeclStatement::fromJSON(JSONLoader & json) { return new DpdkHashDeclStatement(json); }
bool IR::DpdkHashDeclStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkHashDeclStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkGetHashStatement::operator==(IR::DpdkGetHashStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && instr == a.instr
        && hash == a.hash
        && fields == a.fields
        && dst == a.dst;
    }
bool IR::DpdkGetHashStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkGetHashStatement &>(a_);
        return instr == a.instr
        && hash == a.hash
        && (fields ? a.fields ? fields->equiv(*a.fields) : false : a.fields == nullptr)
        && (dst ? a.dst ? dst->equiv(*a.dst) : false : a.dst == nullptr);
    }
void IR::DpdkGetHashStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(fields, "fields");
    v.visit(dst, "dst");
}
void IR::DpdkGetHashStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(fields, "fields");
    v.visit(dst, "dst");
}
void IR::DpdkGetHashStatement::validate() const {
#line 11925 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(fields);
        CHECK_NULL(dst); }
void IR::DpdkGetHashStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " instr=" << instr;
        out << " hash=" << hash;
}
void IR::DpdkGetHashStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("instr", instr);
    json.emit("hash", hash);
    json.emit("fields", fields);
    json.emit("dst", dst);
}
IR::DpdkGetHashStatement::DpdkGetHashStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("instr", instr);
    json.load("hash", hash);
    json.load("fields", fields);
    json.load("dst", dst);
}
IR::Node * IR::DpdkGetHashStatement::fromJSON(JSONLoader & json) { return new DpdkGetHashStatement(json); }
bool IR::DpdkGetHashStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkGetHashStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkGetChecksumStatement::operator==(IR::DpdkGetChecksumStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && dst == a.dst
        && checksum == a.checksum
        && intermediate_value == a.intermediate_value;
    }
bool IR::DpdkGetChecksumStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkGetChecksumStatement &>(a_);
        return (dst ? a.dst ? dst->equiv(*a.dst) : false : a.dst == nullptr)
        && checksum == a.checksum
        && intermediate_value == a.intermediate_value;
    }
void IR::DpdkGetChecksumStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(dst, "dst");
}
void IR::DpdkGetChecksumStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(dst, "dst");
}
void IR::DpdkGetChecksumStatement::validate() const {
#line 11975 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(dst); }
void IR::DpdkGetChecksumStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " checksum=" << checksum;
        out << " intermediate_value=" << intermediate_value;
}
void IR::DpdkGetChecksumStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("dst", dst);
    json.emit("checksum", checksum);
    json.emit("intermediate_value", intermediate_value);
}
IR::DpdkGetChecksumStatement::DpdkGetChecksumStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("dst", dst);
    json.load("checksum", checksum);
    json.load("intermediate_value", intermediate_value);
}
IR::Node * IR::DpdkGetChecksumStatement::fromJSON(JSONLoader & json) { return new DpdkGetChecksumStatement(json); }
bool IR::DpdkGetChecksumStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkGetChecksumStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkCastStatement::operator==(IR::DpdkCastStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && dst == a.dst
        && src == a.src
        && type == a.type;
    }
bool IR::DpdkCastStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkCastStatement &>(a_);
        return (dst ? a.dst ? dst->equiv(*a.dst) : false : a.dst == nullptr)
        && (src ? a.src ? src->equiv(*a.src) : false : a.src == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::DpdkCastStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(dst, "dst");
    v.visit(src, "src");
    v.visit(type, "type");
}
void IR::DpdkCastStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(dst, "dst");
    v.visit(src, "src");
    v.visit(type, "type");
}
void IR::DpdkCastStatement::validate() const {
#line 12026 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(dst);
        CHECK_NULL(src);
        CHECK_NULL(type); }
void IR::DpdkCastStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("dst", dst);
    json.emit("src", src);
    json.emit("type", type);
}
IR::DpdkCastStatement::DpdkCastStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("dst", dst);
    json.load("src", src);
    json.load("type", type);
}
IR::Node * IR::DpdkCastStatement::fromJSON(JSONLoader & json) { return new DpdkCastStatement(json); }
bool IR::DpdkCastStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkCastStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkVerifyStatement::operator==(IR::DpdkVerifyStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && condition == a.condition
        && error == a.error;
    }
bool IR::DpdkVerifyStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkVerifyStatement &>(a_);
        return (condition ? a.condition ? condition->equiv(*a.condition) : false : a.condition == nullptr)
        && (error ? a.error ? error->equiv(*a.error) : false : a.error == nullptr);
    }
void IR::DpdkVerifyStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(condition, "condition");
    v.visit(error, "error");
}
void IR::DpdkVerifyStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(condition, "condition");
    v.visit(error, "error");
}
void IR::DpdkVerifyStatement::validate() const {
#line 12070 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(condition);
        CHECK_NULL(error); }
void IR::DpdkVerifyStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("condition", condition);
    json.emit("error", error);
}
IR::DpdkVerifyStatement::DpdkVerifyStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("condition", condition);
    json.load("error", error);
}
IR::Node * IR::DpdkVerifyStatement::fromJSON(JSONLoader & json) { return new DpdkVerifyStatement(json); }
bool IR::DpdkVerifyStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkVerifyStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkMeterDeclStatement::operator==(IR::DpdkMeterDeclStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && meter == a.meter
        && size == a.size;
    }
bool IR::DpdkMeterDeclStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkMeterDeclStatement &>(a_);
        return meter == a.meter
        && (size ? a.size ? size->equiv(*a.size) : false : a.size == nullptr);
    }
void IR::DpdkMeterDeclStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(size, "size");
}
void IR::DpdkMeterDeclStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(size, "size");
}
void IR::DpdkMeterDeclStatement::validate() const {
#line 12109 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(size); }
void IR::DpdkMeterDeclStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " meter=" << meter;
}
void IR::DpdkMeterDeclStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("meter", meter);
    json.emit("size", size);
}
IR::DpdkMeterDeclStatement::DpdkMeterDeclStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("meter", meter);
    json.load("size", size);
}
IR::Node * IR::DpdkMeterDeclStatement::fromJSON(JSONLoader & json) { return new DpdkMeterDeclStatement(json); }
bool IR::DpdkMeterDeclStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkMeterDeclStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkMeterExecuteStatement::operator==(IR::DpdkMeterExecuteStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && meter == a.meter
        && index == a.index
        && length == a.length
        && color_in == a.color_in
        && color_out == a.color_out;
    }
bool IR::DpdkMeterExecuteStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkMeterExecuteStatement &>(a_);
        return meter == a.meter
        && (index ? a.index ? index->equiv(*a.index) : false : a.index == nullptr)
        && (length ? a.length ? length->equiv(*a.length) : false : a.length == nullptr)
        && (color_in ? a.color_in ? color_in->equiv(*a.color_in) : false : a.color_in == nullptr)
        && (color_out ? a.color_out ? color_out->equiv(*a.color_out) : false : a.color_out == nullptr);
    }
void IR::DpdkMeterExecuteStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(index, "index");
    v.visit(length, "length");
    v.visit(color_in, "color_in");
    v.visit(color_out, "color_out");
}
void IR::DpdkMeterExecuteStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(index, "index");
    v.visit(length, "length");
    v.visit(color_in, "color_in");
    v.visit(color_out, "color_out");
}
void IR::DpdkMeterExecuteStatement::validate() const {
#line 12163 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(index);
        CHECK_NULL(color_in);
        CHECK_NULL(color_out); }
void IR::DpdkMeterExecuteStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " meter=" << meter;
}
void IR::DpdkMeterExecuteStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("meter", meter);
    json.emit("index", index);
    if (length != nullptr) json.emit("length", length);
    json.emit("color_in", color_in);
    json.emit("color_out", color_out);
}
IR::DpdkMeterExecuteStatement::DpdkMeterExecuteStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("meter", meter);
    json.load("index", index);
    json.load("length", length);
    json.load("color_in", color_in);
    json.load("color_out", color_out);
}
IR::Node * IR::DpdkMeterExecuteStatement::fromJSON(JSONLoader & json) { return new DpdkMeterExecuteStatement(json); }
bool IR::DpdkMeterExecuteStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkMeterExecuteStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkGetTableEntryIndex::operator==(IR::DpdkGetTableEntryIndex const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && index == a.index;
    }
bool IR::DpdkGetTableEntryIndex::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkGetTableEntryIndex &>(a_);
        return (index ? a.index ? index->equiv(*a.index) : false : a.index == nullptr);
    }
void IR::DpdkGetTableEntryIndex::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(index, "index");
}
void IR::DpdkGetTableEntryIndex::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(index, "index");
}
void IR::DpdkGetTableEntryIndex::validate() const {
#line 12211 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(index); }
void IR::DpdkGetTableEntryIndex::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("index", index);
}
IR::DpdkGetTableEntryIndex::DpdkGetTableEntryIndex(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("index", index);
}
IR::Node * IR::DpdkGetTableEntryIndex::fromJSON(JSONLoader & json) { return new DpdkGetTableEntryIndex(json); }
bool IR::DpdkGetTableEntryIndex::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkGetTableEntryIndex::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkCounterCountStatement::operator==(IR::DpdkCounterCountStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && counter == a.counter
        && index == a.index
        && incr == a.incr;
    }
bool IR::DpdkCounterCountStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkCounterCountStatement &>(a_);
        return counter == a.counter
        && (index ? a.index ? index->equiv(*a.index) : false : a.index == nullptr)
        && (incr ? a.incr ? incr->equiv(*a.incr) : false : a.incr == nullptr);
    }
void IR::DpdkCounterCountStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(index, "index");
    v.visit(incr, "incr");
}
void IR::DpdkCounterCountStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(index, "index");
    v.visit(incr, "incr");
}
void IR::DpdkCounterCountStatement::validate() const {
#line 12251 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(index); }
void IR::DpdkCounterCountStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " counter=" << counter;
}
void IR::DpdkCounterCountStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("counter", counter);
    json.emit("index", index);
    if (incr != nullptr) json.emit("incr", incr);
}
IR::DpdkCounterCountStatement::DpdkCounterCountStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("counter", counter);
    json.load("index", index);
    json.load("incr", incr);
}
IR::Node * IR::DpdkCounterCountStatement::fromJSON(JSONLoader & json) { return new DpdkCounterCountStatement(json); }
bool IR::DpdkCounterCountStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkCounterCountStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkRegisterDeclStatement::operator==(IR::DpdkRegisterDeclStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && reg == a.reg
        && size == a.size
        && init_val == a.init_val;
    }
bool IR::DpdkRegisterDeclStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkRegisterDeclStatement &>(a_);
        return reg == a.reg
        && (size ? a.size ? size->equiv(*a.size) : false : a.size == nullptr)
        && (init_val ? a.init_val ? init_val->equiv(*a.init_val) : false : a.init_val == nullptr);
    }
void IR::DpdkRegisterDeclStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(size, "size");
    v.visit(init_val, "init_val");
}
void IR::DpdkRegisterDeclStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(size, "size");
    v.visit(init_val, "init_val");
}
void IR::DpdkRegisterDeclStatement::validate() const {
#line 12299 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(size); }
void IR::DpdkRegisterDeclStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " reg=" << reg;
}
void IR::DpdkRegisterDeclStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("reg", reg);
    json.emit("size", size);
    if (init_val != nullptr) json.emit("init_val", init_val);
}
IR::DpdkRegisterDeclStatement::DpdkRegisterDeclStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("reg", reg);
    json.load("size", size);
    json.load("init_val", init_val);
}
IR::Node * IR::DpdkRegisterDeclStatement::fromJSON(JSONLoader & json) { return new DpdkRegisterDeclStatement(json); }
bool IR::DpdkRegisterDeclStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkRegisterDeclStatement::operator==(IR::Node const & a) const { return a == *this; }
#line 517 "/root/p4c/backends/dpdk/dpdk.def"
IR::DpdkRegisterReadStatement::DpdkRegisterReadStatement(const IR::Expression* dst, cstring reg, const IR::Expression* index) :
        DpdkAssignmentStatement("read"_cs, dst), reg(reg), index(index) { }
#line 12323 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkRegisterReadStatement::operator==(IR::DpdkRegisterReadStatement const & a) const {
        return DpdkAssignmentStatement::operator==(static_cast<const DpdkAssignmentStatement &>(a))
        && reg == a.reg
        && index == a.index;
    }
bool IR::DpdkRegisterReadStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAssignmentStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkRegisterReadStatement &>(a_);
        return reg == a.reg
        && (index ? a.index ? index->equiv(*a.index) : false : a.index == nullptr);
    }
void IR::DpdkRegisterReadStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAssignmentStatement::visit_children(v, n);
    v.visit(index, "index");
}
void IR::DpdkRegisterReadStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAssignmentStatement::visit_children(v, n);
    v.visit(index, "index");
}
void IR::DpdkRegisterReadStatement::validate() const {
#line 12347 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(index); }
void IR::DpdkRegisterReadStatement::dump_fields(std::ostream & out) const {
    DpdkAssignmentStatement::dump_fields(out);
        out << " reg=" << reg;
}
void IR::DpdkRegisterReadStatement::toJSON(JSONGenerator & json) const {
    DpdkAssignmentStatement::toJSON(json);
    json.emit("reg", reg);
    json.emit("index", index);
}
IR::DpdkRegisterReadStatement::DpdkRegisterReadStatement(JSONLoader & json) : DpdkAssignmentStatement(json) {
    json.load("reg", reg);
    json.load("index", index);
}
IR::Node * IR::DpdkRegisterReadStatement::fromJSON(JSONLoader & json) { return new DpdkRegisterReadStatement(json); }
bool IR::DpdkRegisterReadStatement::operator==(IR::DpdkAssignmentStatement const & a) const { return a == *this; }
bool IR::DpdkRegisterReadStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkRegisterReadStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkRegisterWriteStatement::operator==(IR::DpdkRegisterWriteStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && reg == a.reg
        && index == a.index
        && src == a.src;
    }
bool IR::DpdkRegisterWriteStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkRegisterWriteStatement &>(a_);
        return reg == a.reg
        && (index ? a.index ? index->equiv(*a.index) : false : a.index == nullptr)
        && (src ? a.src ? src->equiv(*a.src) : false : a.src == nullptr);
    }
void IR::DpdkRegisterWriteStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(index, "index");
    v.visit(src, "src");
}
void IR::DpdkRegisterWriteStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(index, "index");
    v.visit(src, "src");
}
void IR::DpdkRegisterWriteStatement::validate() const {
#line 12394 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(index);
        CHECK_NULL(src); }
void IR::DpdkRegisterWriteStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " reg=" << reg;
}
void IR::DpdkRegisterWriteStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("reg", reg);
    json.emit("index", index);
    json.emit("src", src);
}
IR::DpdkRegisterWriteStatement::DpdkRegisterWriteStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("reg", reg);
    json.load("index", index);
    json.load("src", src);
}
IR::Node * IR::DpdkRegisterWriteStatement::fromJSON(JSONLoader & json) { return new DpdkRegisterWriteStatement(json); }
bool IR::DpdkRegisterWriteStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkRegisterWriteStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkValidateStatement::operator==(IR::DpdkValidateStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && header == a.header;
    }
bool IR::DpdkValidateStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkValidateStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr);
    }
void IR::DpdkValidateStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(header, "header");
}
void IR::DpdkValidateStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(header, "header");
}
void IR::DpdkValidateStatement::validate() const {
#line 12437 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkValidateStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("header", header);
}
IR::DpdkValidateStatement::DpdkValidateStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("header", header);
}
IR::Node * IR::DpdkValidateStatement::fromJSON(JSONLoader & json) { return new DpdkValidateStatement(json); }
bool IR::DpdkValidateStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkValidateStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkInvalidateStatement::operator==(IR::DpdkInvalidateStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && header == a.header;
    }
bool IR::DpdkInvalidateStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkInvalidateStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr);
    }
void IR::DpdkInvalidateStatement::visit_children(Visitor & v, char const * n) {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(header, "header");
}
void IR::DpdkInvalidateStatement::visit_children(Visitor & v, char const * n) const {
    (void)n;
    DpdkAsmStatement::visit_children(v, n);
    v.visit(header, "header");
}
void IR::DpdkInvalidateStatement::validate() const {
#line 12471 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkInvalidateStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json.emit("header", header);
}
IR::DpdkInvalidateStatement::DpdkInvalidateStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("header", header);
}
IR::Node * IR::DpdkInvalidateStatement::fromJSON(JSONLoader & json) { return new DpdkInvalidateStatement(json); }
bool IR::DpdkInvalidateStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkInvalidateStatement::operator==(IR::Node const & a) const { return a == *this; }
bool IR::DpdkDropStatement::operator==(IR::DpdkDropStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a));
    }
bool IR::DpdkDropStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkDropStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
}
IR::DpdkDropStatement::DpdkDropStatement(JSONLoader & json) : DpdkAsmStatement(json) {
}
IR::Node * IR::DpdkDropStatement::fromJSON(JSONLoader & json) { return new DpdkDropStatement(json); }
bool IR::DpdkDropStatement::operator==(IR::DpdkAsmStatement const & a) const { return a == *this; }
bool IR::DpdkDropStatement::operator==(IR::Node const & a) const { return a == *this; }

#line 25 "/root/p4c/backends/tc/tc.def"
cstring IR::TCKernelMetadata::toString() const {
        std::string metaName = "kernel.";
        switch (metaField) {
            case TC::SKBREDIR: {
                absl::StrAppend(&metaName, "skbredir");
                break;
            }
            case TC::SKBIIF: {
                absl::StrAppend(&metaName, "skbiif");
                break;
            }
            case TC::SKBTSTAMP: {
                absl::StrAppend(&metaName, "skbtstamp");
                break;
            }
            case TC::SKBPRIO: {
                absl::StrAppend(&metaName, "skbprio");
                break;
            }
        }
        return metaName;
    }
#line 12524 "/root/p4c/build/ir/ir-generated.cpp"
#line 47 "/root/p4c/backends/tc/tc.def"
void IR::TCKernelMetadata::dbprint(std::ostream & out) const { out << toString(); }
#line 12527 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::TCKernelMetadata::operator==(IR::TCKernelMetadata const & a) const {
        return this->typeId() == a.typeId()
        && metaField == a.metaField;
    }
bool IR::TCKernelMetadata::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const TCKernelMetadata &>(a_);
        return metaField == a.metaField;
    }
void IR::TCKernelMetadata::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " metaField=" << metaField;
}
void IR::TCKernelMetadata::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("metaField", metaField);
}
IR::TCKernelMetadata::TCKernelMetadata(JSONLoader & json) : Node(json) {
    json.load("metaField", metaField);
}
IR::Node * IR::TCKernelMetadata::fromJSON(JSONLoader & json) { return new TCKernelMetadata(json); }
bool IR::TCKernelMetadata::operator==(IR::Node const & a) const { return a == *this; }
#line 55 "/root/p4c/backends/tc/tc.def"
void IR::TCActionParam::setParamName(cstring pN) {
        paramName = pN;
    }
#line 12555 "/root/p4c/build/ir/ir-generated.cpp"
#line 58 "/root/p4c/backends/tc/tc.def"
void IR::TCActionParam::setBitSize(unsigned bS) {
        bitSize = bS;
    }
#line 12560 "/root/p4c/build/ir/ir-generated.cpp"
#line 61 "/root/p4c/backends/tc/tc.def"
void IR::TCActionParam::setDataType(unsigned d) {
        dataType = d;
    }
#line 12565 "/root/p4c/build/ir/ir-generated.cpp"
#line 64 "/root/p4c/backends/tc/tc.def"
void IR::TCActionParam::setDirection(unsigned d) {
        direction = d;
    }
#line 12570 "/root/p4c/build/ir/ir-generated.cpp"
#line 67 "/root/p4c/backends/tc/tc.def"
IR::TCActionParam::TCActionParam() {
        paramName = nullptr;
        bitSize = 0;
    }
#line 12576 "/root/p4c/build/ir/ir-generated.cpp"
#line 71 "/root/p4c/backends/tc/tc.def"
cstring IR::TCActionParam::getParamName() const {
        return paramName;
    }
#line 12581 "/root/p4c/build/ir/ir-generated.cpp"
#line 74 "/root/p4c/backends/tc/tc.def"
cstring IR::TCActionParam::getName() const {
        return "param." + paramName;
    }
#line 12586 "/root/p4c/build/ir/ir-generated.cpp"
#line 77 "/root/p4c/backends/tc/tc.def"
unsigned IR::TCActionParam::getDirection() const {
        return direction;
    }
#line 12591 "/root/p4c/build/ir/ir-generated.cpp"
#line 80 "/root/p4c/backends/tc/tc.def"
cstring IR::TCActionParam::getParamDecl(cstring placeholderName) const {
        std::string paramDecl = "";
        switch(dataType) {
            case TC::BIT_TYPE :
                if (bitSize == 8 || bitSize == 16 || bitSize == 32 || bitSize == 64) {
                    paramDecl = absl::StrCat("__u", bitSize, " ", placeholderName);
                } else {
                    unsigned byteSize = bitSize / 8 + (bitSize % 8 != 0);

                    paramDecl = absl::StrCat("__u8 ", placeholderName, "[", byteSize, "]");
                }
                break;
            case TC::DEV_TYPE :
                paramDecl = absl::StrCat("__u32 ", placeholderName);
                break;
            case TC::MACADDR_TYPE :
                paramDecl = absl::StrCat("__u8 ", placeholderName, "[6]");
                break;
            case TC::IPV4_TYPE :
                paramDecl = absl::StrCat("__u32 ", placeholderName);
                break;
            case TC::IPV6_TYPE :
                paramDecl = absl::StrCat("__u8 ", placeholderName, "[16]");
                break;
            case TC::BE16_TYPE :
                paramDecl = absl::StrCat("__be16 ", placeholderName);
                break;
            case TC::BE32_TYPE :
                paramDecl = absl::StrCat("__be32 ", placeholderName);
                break;
            case TC::BE64_TYPE :
                paramDecl = absl::StrCat("__be64 ", placeholderName);
                break;
        }
        return paramDecl;
    }
#line 12629 "/root/p4c/build/ir/ir-generated.cpp"
#line 116 "/root/p4c/backends/tc/tc.def"
cstring IR::TCActionParam::toString() const {
        std::string tcActionParam = absl::StrCat("\n\tparam ", paramName, " type ");
        switch(dataType) {
            case TC::BIT_TYPE :
                absl::StrAppend(&tcActionParam, "bit", bitSize);
                break;
            case TC::DEV_TYPE :
                absl::StrAppend(&tcActionParam, "dev");
                break;
            case TC::MACADDR_TYPE :
                absl::StrAppend(&tcActionParam, "macaddr");
                break;
            case TC::IPV4_TYPE :
                absl::StrAppend(&tcActionParam, "ipv4");
                break;
            case TC::IPV6_TYPE :
                absl::StrAppend(&tcActionParam, "ipv6");
                break;
            case TC::BE16_TYPE :
                absl::StrAppend(&tcActionParam, "be16");
                break;
            case TC::BE32_TYPE :
                absl::StrAppend(&tcActionParam, "be32");
                break;
            case TC::BE64_TYPE :
                absl::StrAppend(&tcActionParam, "be64");
                break;
        }
        return tcActionParam;
    }
#line 12661 "/root/p4c/build/ir/ir-generated.cpp"
#line 146 "/root/p4c/backends/tc/tc.def"
void IR::TCActionParam::dbprint(std::ostream & out) const { out << toString(); }
#line 12664 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::TCActionParam::operator==(IR::TCActionParam const & a) const {
        return this->typeId() == a.typeId()
        && paramName == a.paramName
        && dataType == a.dataType
        && bitSize == a.bitSize
        && direction == a.direction;
    }
bool IR::TCActionParam::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const TCActionParam &>(a_);
        return paramName == a.paramName
        && dataType == a.dataType
        && bitSize == a.bitSize
        && direction == a.direction;
    }
void IR::TCActionParam::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " paramName=" << paramName;
        out << " dataType=" << dataType;
        out << " bitSize=" << bitSize;
        out << " direction=" << direction;
}
void IR::TCActionParam::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("paramName", paramName);
    json.emit("dataType", dataType);
    json.emit("bitSize", bitSize);
    json.emit("direction", direction);
}
IR::TCActionParam::TCActionParam(JSONLoader & json) : Node(json) {
    json.load("paramName", paramName);
    json.load("dataType", dataType);
    json.load("bitSize", bitSize);
    json.load("direction", direction);
}
IR::Node * IR::TCActionParam::fromJSON(JSONLoader & json) { return new TCActionParam(json); }
bool IR::TCActionParam::operator==(IR::Node const & a) const { return a == *this; }
#line 152 "/root/p4c/backends/tc/tc.def"
void IR::TCDefaultActionParam::setParamDetail(const IR::TCActionParam* pN) {
        paramDetail = pN;
    }
#line 12707 "/root/p4c/build/ir/ir-generated.cpp"
#line 155 "/root/p4c/backends/tc/tc.def"
void IR::TCDefaultActionParam::setDefaultValue(cstring dV) {
        defaultValue = dV;
    }
#line 12712 "/root/p4c/build/ir/ir-generated.cpp"
#line 158 "/root/p4c/backends/tc/tc.def"
IR::TCDefaultActionParam::TCDefaultActionParam() {
        paramDetail = nullptr;
        defaultValue = nullptr;
    }
#line 12718 "/root/p4c/build/ir/ir-generated.cpp"
#line 162 "/root/p4c/backends/tc/tc.def"
cstring IR::TCDefaultActionParam::toString() const {
        std::string tcActionParam = absl::StrCat(" ", paramDetail->paramName);
        if (defaultValue != nullptr)
            absl::StrAppend(&tcActionParam, " ", defaultValue);
        return tcActionParam;
    }
#line 12726 "/root/p4c/build/ir/ir-generated.cpp"
#line 168 "/root/p4c/backends/tc/tc.def"
void IR::TCDefaultActionParam::dbprint(std::ostream & out) const { out << toString(); }
#line 12729 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::TCDefaultActionParam::operator==(IR::TCDefaultActionParam const & a) const {
        return this->typeId() == a.typeId()
        && paramDetail == a.paramDetail
        && defaultValue == a.defaultValue;
    }
bool IR::TCDefaultActionParam::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const TCDefaultActionParam &>(a_);
        return (paramDetail ? a.paramDetail ? paramDetail->equiv(*a.paramDetail) : false : a.paramDetail == nullptr)
        && defaultValue == a.defaultValue;
    }
void IR::TCDefaultActionParam::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(paramDetail, "paramDetail");
}
void IR::TCDefaultActionParam::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(paramDetail, "paramDetail");
}
void IR::TCDefaultActionParam::validate() const {
#line 12753 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(paramDetail); }
void IR::TCDefaultActionParam::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " defaultValue=" << defaultValue;
}
void IR::TCDefaultActionParam::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("paramDetail", paramDetail);
    json.emit("defaultValue", defaultValue);
}
IR::TCDefaultActionParam::TCDefaultActionParam(JSONLoader & json) : Node(json) {
    json.load("paramDetail", paramDetail);
    json.load("defaultValue", defaultValue);
}
IR::Node * IR::TCDefaultActionParam::fromJSON(JSONLoader & json) { return new TCDefaultActionParam(json); }
bool IR::TCDefaultActionParam::operator==(IR::Node const & a) const { return a == *this; }
#line 176 "/root/p4c/backends/tc/tc.def"
cstring IR::TCAction::getName() const {
        if (actionName == "NoAction") {
            return actionName;
        }
        return absl::StrCat(pipelineName, "/", actionName);
    }
#line 12778 "/root/p4c/build/ir/ir-generated.cpp"
#line 182 "/root/p4c/backends/tc/tc.def"
cstring IR::TCAction::getActionName() const {
        return actionName;
    }
#line 12783 "/root/p4c/build/ir/ir-generated.cpp"
#line 185 "/root/p4c/backends/tc/tc.def"
void IR::TCAction::setPipelineName(cstring pN) {
        pipelineName = pN;
    }
#line 12788 "/root/p4c/build/ir/ir-generated.cpp"
#line 188 "/root/p4c/backends/tc/tc.def"
void IR::TCAction::addActionParams(const IR::TCActionParam* tca) {
        actionParams.push_back(tca);
    }
#line 12793 "/root/p4c/build/ir/ir-generated.cpp"
#line 191 "/root/p4c/backends/tc/tc.def"
void IR::TCAction::setActionId(unsigned id) {
        actId = id;
    }
#line 12798 "/root/p4c/build/ir/ir-generated.cpp"
#line 194 "/root/p4c/backends/tc/tc.def"
IR::TCAction::TCAction(cstring aN) {
        actionName = aN;
        pipelineName = nullptr;
        actId = 0;
    }
#line 12805 "/root/p4c/build/ir/ir-generated.cpp"
#line 199 "/root/p4c/backends/tc/tc.def"
cstring IR::TCAction::toString() const {
        std::string tcAction = absl::StrCat("\n$TC p4template create action/", pipelineName, "/", actionName);
        if (actId != 0) {
            absl::StrAppend(&tcAction, " actid ", actId);
        }
        if (!actionParams.empty()) {
            for (auto actParam : actionParams) {
                absl::StrAppend(&tcAction, " \\", actParam);
            }
        }
        absl::StrAppend(&tcAction, "\n$TC p4template update action/", pipelineName, "/", actionName, " state active");

        return tcAction;
    }
#line 12821 "/root/p4c/build/ir/ir-generated.cpp"
#line 213 "/root/p4c/backends/tc/tc.def"
void IR::TCAction::dbprint(std::ostream & out) const { out << toString(); }
#line 12824 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::TCAction::operator==(IR::TCAction const & a) const {
        return this->typeId() == a.typeId()
        && actionName == a.actionName
        && pipelineName == a.pipelineName
        && actId == a.actId
        && actionParams == a.actionParams;
    }
bool IR::TCAction::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const TCAction &>(a_);
        return actionName == a.actionName
        && pipelineName == a.pipelineName
        && actId == a.actId
        && actionParams == a.actionParams;
    }
void IR::TCAction::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " actionName=" << actionName;
        out << " pipelineName=" << pipelineName;
        out << " actId=" << actId;
}
void IR::TCAction::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("actionName", actionName);
    json.emit("pipelineName", pipelineName);
    json.emit("actId", actId);
    json.emit("actionParams", actionParams);
}
IR::TCAction::TCAction(JSONLoader & json) : Node(json) {
    json.load("actionName", actionName);
    json.load("pipelineName", pipelineName);
    json.load("actId", actId);
    json.load("actionParams", actionParams);
}
IR::Node * IR::TCAction::fromJSON(JSONLoader & json) { return new TCAction(json); }
bool IR::TCAction::operator==(IR::Node const & a) const { return a == *this; }
#line 219 "/root/p4c/backends/tc/tc.def"
cstring IR::TCEntry::getActionName() const {
        return action;
    }
#line 12866 "/root/p4c/build/ir/ir-generated.cpp"
#line 222 "/root/p4c/backends/tc/tc.def"
cstring IR::TCEntry::toString() const {
        std::string tcEntry = "";
        for (auto k : keys) {
            tcEntry = absl::StrJoin({tcEntry, k.first.string(), k.second.string()}, " ");
        }
        return tcEntry;
    }
#line 12875 "/root/p4c/build/ir/ir-generated.cpp"
#line 229 "/root/p4c/backends/tc/tc.def"
void IR::TCEntry::dbprint(std::ostream & out) const { out << toString(); }
#line 12878 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::TCEntry::operator==(IR::TCEntry const & a) const {
        return this->typeId() == a.typeId()
        && action == a.action
        && keys == a.keys;
    }
bool IR::TCEntry::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const TCEntry &>(a_);
        return action == a.action
        && keys == a.keys;
    }
void IR::TCEntry::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " action=" << action;
}
void IR::TCEntry::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("action", action);
    json.emit("keys", keys);
}
IR::TCEntry::TCEntry(JSONLoader & json) : Node(json) {
    json.load("action", action);
    json.load("keys", keys);
}
IR::Node * IR::TCEntry::fromJSON(JSONLoader & json) { return new TCEntry(json); }
bool IR::TCEntry::operator==(IR::Node const & a) const { return a == *this; }
#line 261 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::setTablePermission(cstring p) {
        permissions = p;
    }
#line 12910 "/root/p4c/build/ir/ir-generated.cpp"
#line 264 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::setDirectCounter(cstring counter) {
        isDirectCounter = true;
        directCounterInstance = counter;
    }
#line 12916 "/root/p4c/build/ir/ir-generated.cpp"
#line 268 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::setDirectMeter(cstring meter) {
        isDirectMeter = true;
        directMeterInstance = meter;
    }
#line 12922 "/root/p4c/build/ir/ir-generated.cpp"
#line 272 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::setKeySize(unsigned k) {
        keySize = k;
    }
#line 12927 "/root/p4c/build/ir/ir-generated.cpp"
#line 275 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::setTableEntriesCount(unsigned t) {
        tableEntriesCount = t;
    }
#line 12932 "/root/p4c/build/ir/ir-generated.cpp"
#line 278 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::setNumMask(unsigned n) {
        numMask = n;
    }
#line 12937 "/root/p4c/build/ir/ir-generated.cpp"
#line 281 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::setMatchType(unsigned m) {
        matchType = m;
    }
#line 12942 "/root/p4c/build/ir/ir-generated.cpp"
#line 284 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::setDefaultHitAction(const IR::TCAction* d) {
        defaultHitAction = d;
    }
#line 12947 "/root/p4c/build/ir/ir-generated.cpp"
#line 287 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::setDefaultMissAction(const IR::TCAction* d) {
        defaultMissAction = d;
    }
#line 12952 "/root/p4c/build/ir/ir-generated.cpp"
#line 290 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::setDefaultHitConst(bool i) {
        isDefaultHitConst = i;
    }
#line 12957 "/root/p4c/build/ir/ir-generated.cpp"
#line 293 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::setDefaultMissConst(bool i) {
        isDefaultMissConst = i;
    }
#line 12962 "/root/p4c/build/ir/ir-generated.cpp"
#line 296 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::setTcMayOverrideHit() {
        isTcMayOverrideHit = true;
    }
#line 12967 "/root/p4c/build/ir/ir-generated.cpp"
#line 299 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::setTcMayOverrideMiss() {
        isTcMayOverrideMiss = true;
    }
#line 12972 "/root/p4c/build/ir/ir-generated.cpp"
#line 302 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::setTableAddOnMiss() {
        isTableAddOnMiss = true;
    }
#line 12977 "/root/p4c/build/ir/ir-generated.cpp"
#line 305 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::addAction(const IR::TCAction* action, unsigned flag) {
        actionList.emplace(action, flag);
    }
#line 12982 "/root/p4c/build/ir/ir-generated.cpp"
#line 308 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::addConstEntries(const IR::TCEntry* entry) {
        const_entries.push_back(entry);
    }
#line 12987 "/root/p4c/build/ir/ir-generated.cpp"
#line 311 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::addTimerProfiles(unsigned tp) {
        timerProfiles = tp;
    }
#line 12992 "/root/p4c/build/ir/ir-generated.cpp"
#line 314 "/root/p4c/backends/tc/tc.def"
cstring IR::TCTable::getTableName() const {
        return tableName;
    }
#line 12997 "/root/p4c/build/ir/ir-generated.cpp"
#line 317 "/root/p4c/backends/tc/tc.def"
cstring IR::TCTable::printMatchType(unsigned matchType) const {
        cstring matchTypeString = cstring::empty;
        switch(matchType) {
                case TC::EXACT_TYPE :
                    matchTypeString = "exact"_cs;
                    break;
                case TC::LPM_TYPE :
                    matchTypeString = "lpm"_cs;
                    break;
                case TC::TERNARY_TYPE :
                    matchTypeString = "ternary"_cs;
                    break;
        }
        return matchTypeString;
    }
#line 13014 "/root/p4c/build/ir/ir-generated.cpp"
#line 332 "/root/p4c/backends/tc/tc.def"
IR::TCTable::TCTable(unsigned tId, cstring tN, cstring cN, cstring pN) {
        tableID = tId;
        tableName = tN;
        controlName = cN;
        pipelineName = pN;
        keySize = 0;
        timerProfiles = 0;
        tableEntriesCount = TC::DEFAULT_TABLE_ENTRIES;
        numMask = TC::DEFAULT_KEY_MASK;
        matchType = TC::EXACT_TYPE;
        defaultHitAction = nullptr;
        defaultMissAction = nullptr;
        isDefaultHitConst = false;
        isDefaultMissConst = false;
        isTcMayOverrideHit = false;
        isTcMayOverrideMiss = false;
        isTableAddOnMiss = false;
        isTcMayOverride = false;
        isDirectCounter = false;
        isDirectMeter = false;
    }
#line 13037 "/root/p4c/build/ir/ir-generated.cpp"
#line 353 "/root/p4c/backends/tc/tc.def"
cstring IR::TCTable::toString() const {
        std::string tcTable = absl::StrCat("\n$TC p4template create table/",
                        pipelineName, "/", controlName, "/", tableName, " \\",
                        "\n\ttblid ", tableID, " \\",
                        "\n\ttype ", printMatchType(matchType), " \\",
                        "\n\tkeysz ", keySize,
                        " permissions ", permissions,
                        " tentries ", tableEntriesCount);
        if (matchType == TC::EXACT_TYPE) {
            absl::StrAppend(&tcTable, " nummasks ", TC::DEFAULT_KEY_MASK_EXACT);
        } else {
            absl::StrAppend(&tcTable, " nummasks ", TC::DEFAULT_KEY_MASK);
        }

        if (isTableAddOnMiss && timerProfiles > defaultTimerProfiles) {
            absl::StrAppend(&tcTable, " num_timer_profiles ", timerProfiles);
        }
        if (isDirectCounter) {
            absl::StrAppend(&tcTable, " \\\n\tpna_direct_counter DirectCounter/", directCounterInstance);
        }
        if (isDirectMeter) {
            absl::StrAppend(&tcTable, " \\\n\tpna_direct_meter DirectMeter/", directMeterInstance);
        }

        if (!actionList.empty()) {
            absl::StrAppend(&tcTable, " \\", "\n\ttable_acts ");
            for (auto iter = actionList.begin(); iter != actionList.end(); iter++) {
                absl::StrAppend(&tcTable, "act name ", iter->first->getName());
                if (iter->second == TC::TABLEONLY) {
                    absl::StrAppend(&tcTable, " flags tableonly");
                } else if (iter->second == TC::DEFAULTONLY) {
                    absl::StrAppend(&tcTable, " flags defaultonly");
                }
                if (std::next(iter) != actionList.end()) {
                    absl::StrAppend(&tcTable, " \\", "\n\t");
                }
            }
        }
        if (defaultHitAction != nullptr) {
            absl::StrAppend(&tcTable, "\n$TC p4template update table/", pipelineName,
                      "/", controlName, "/", tableName,
                      " default_hit_action");
            if (isDefaultHitConst) {
                absl::StrAppend(&tcTable, " permissions 0x1024");
            }
            absl::StrAppend(&tcTable, " action ", defaultHitAction->getName());
            if (!defaultHitActionParams.empty())
                absl::StrAppend(&tcTable, " param");
            for (auto param : defaultHitActionParams)
                absl::StrAppend(&tcTable, param);
            if (isTcMayOverrideHit)
                absl::StrAppend(&tcTable, " flags runtime");
        }
        if (defaultMissAction != nullptr) {
            absl::StrAppend(&tcTable, "\n$TC p4template update table/", pipelineName,
                      "/", controlName, "/", tableName,
                      " default_miss_action");
            if (isDefaultMissConst) {
                absl::StrAppend(&tcTable, " permissions 0x1024");
            }
            absl::StrAppend(&tcTable, " action ", defaultMissAction->getName());
            if (!defaultMissActionParams.empty())
                absl::StrAppend(&tcTable, " param");
            for (auto param : defaultMissActionParams)
                absl::StrAppend(&tcTable, param);
            if (isTcMayOverrideMiss)
                absl::StrAppend(&tcTable, " flags runtime");
        }
        if (const_entries.size() != 0) {
            for (auto entry : const_entries) {
                absl::StrAppend(&tcTable, "\n$TC p4template create table/", pipelineName,
                                "/", controlName, "/", tableName,
                                " entry", entry,
                                " permissions 0x1024",
                                " action ", pipelineName,
                                "/", controlName, "/", entry->getActionName());
            }
        }
        return tcTable;
    }
#line 13119 "/root/p4c/build/ir/ir-generated.cpp"
#line 433 "/root/p4c/backends/tc/tc.def"
void IR::TCTable::dbprint(std::ostream & out) const { out << toString(); }
#line 13122 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::TCTable::operator==(IR::TCTable const & a) const {
        return this->typeId() == a.typeId()
        && tableID == a.tableID
        && tableName == a.tableName
        && controlName == a.controlName
        && pipelineName == a.pipelineName
        && permissions == a.permissions
        && directCounterInstance == a.directCounterInstance
        && directMeterInstance == a.directMeterInstance
        && keySize == a.keySize
        && tableEntriesCount == a.tableEntriesCount
        && numMask == a.numMask
        && matchType == a.matchType
        && timerProfiles == a.timerProfiles
        && defaultTimerProfiles == a.defaultTimerProfiles
        && defaultHitAction == a.defaultHitAction
        && isDefaultHitConst == a.isDefaultHitConst
        && isTcMayOverrideHit == a.isTcMayOverrideHit
        && defaultHitActionParams == a.defaultHitActionParams
        && defaultMissAction == a.defaultMissAction
        && isDefaultMissConst == a.isDefaultMissConst
        && isTcMayOverrideMiss == a.isTcMayOverrideMiss
        && defaultMissActionParams == a.defaultMissActionParams
        && isTableAddOnMiss == a.isTableAddOnMiss
        && isTcMayOverride == a.isTcMayOverride
        && isDirectCounter == a.isDirectCounter
        && isDirectMeter == a.isDirectMeter
        && actionList == a.actionList
        && const_entries == a.const_entries;
    }
bool IR::TCTable::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const TCTable &>(a_);
        return tableID == a.tableID
        && tableName == a.tableName
        && controlName == a.controlName
        && pipelineName == a.pipelineName
        && permissions == a.permissions
        && directCounterInstance == a.directCounterInstance
        && directMeterInstance == a.directMeterInstance
        && keySize == a.keySize
        && tableEntriesCount == a.tableEntriesCount
        && numMask == a.numMask
        && matchType == a.matchType
        && timerProfiles == a.timerProfiles
        && defaultTimerProfiles == a.defaultTimerProfiles
        && (defaultHitAction ? a.defaultHitAction ? defaultHitAction->equiv(*a.defaultHitAction) : false : a.defaultHitAction == nullptr)
        && isDefaultHitConst == a.isDefaultHitConst
        && isTcMayOverrideHit == a.isTcMayOverrideHit
        && defaultHitActionParams == a.defaultHitActionParams
        && (defaultMissAction ? a.defaultMissAction ? defaultMissAction->equiv(*a.defaultMissAction) : false : a.defaultMissAction == nullptr)
        && isDefaultMissConst == a.isDefaultMissConst
        && isTcMayOverrideMiss == a.isTcMayOverrideMiss
        && defaultMissActionParams == a.defaultMissActionParams
        && isTableAddOnMiss == a.isTableAddOnMiss
        && isTcMayOverride == a.isTcMayOverride
        && isDirectCounter == a.isDirectCounter
        && isDirectMeter == a.isDirectMeter
        && actionList == a.actionList
        && const_entries == a.const_entries;
    }
void IR::TCTable::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(defaultHitAction, "defaultHitAction");
    v.visit(defaultMissAction, "defaultMissAction");
}
void IR::TCTable::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(defaultHitAction, "defaultHitAction");
    v.visit(defaultMissAction, "defaultMissAction");
}
void IR::TCTable::validate() const {
#line 13198 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(defaultHitAction);
        CHECK_NULL(defaultMissAction); }
void IR::TCTable::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " tableID=" << tableID;
        out << " tableName=" << tableName;
        out << " controlName=" << controlName;
        out << " pipelineName=" << pipelineName;
        out << " permissions=" << permissions;
        out << " directCounterInstance=" << directCounterInstance;
        out << " directMeterInstance=" << directMeterInstance;
        out << " keySize=" << keySize;
        out << " tableEntriesCount=" << tableEntriesCount;
        out << " numMask=" << numMask;
        out << " matchType=" << matchType;
        out << " timerProfiles=" << timerProfiles;
        out << " defaultTimerProfiles=" << defaultTimerProfiles;
        out << " isDefaultHitConst=" << isDefaultHitConst;
        out << " isTcMayOverrideHit=" << isTcMayOverrideHit;
        out << " isDefaultMissConst=" << isDefaultMissConst;
        out << " isTcMayOverrideMiss=" << isTcMayOverrideMiss;
        out << " isTableAddOnMiss=" << isTableAddOnMiss;
        out << " isTcMayOverride=" << isTcMayOverride;
        out << " isDirectCounter=" << isDirectCounter;
        out << " isDirectMeter=" << isDirectMeter;
}
void IR::TCTable::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("tableID", tableID);
    json.emit("tableName", tableName);
    json.emit("controlName", controlName);
    json.emit("pipelineName", pipelineName);
    json.emit("permissions", permissions);
    json.emit("directCounterInstance", directCounterInstance);
    json.emit("directMeterInstance", directMeterInstance);
    json.emit("keySize", keySize);
    json.emit("tableEntriesCount", tableEntriesCount);
    json.emit("numMask", numMask);
    json.emit("matchType", matchType);
    json.emit("timerProfiles", timerProfiles);
    json.emit("defaultTimerProfiles", defaultTimerProfiles);
    json.emit("defaultHitAction", defaultHitAction);
    json.emit("isDefaultHitConst", isDefaultHitConst);
    json.emit("isTcMayOverrideHit", isTcMayOverrideHit);
    json.emit("defaultHitActionParams", defaultHitActionParams);
    json.emit("defaultMissAction", defaultMissAction);
    json.emit("isDefaultMissConst", isDefaultMissConst);
    json.emit("isTcMayOverrideMiss", isTcMayOverrideMiss);
    json.emit("defaultMissActionParams", defaultMissActionParams);
    json.emit("isTableAddOnMiss", isTableAddOnMiss);
    json.emit("isTcMayOverride", isTcMayOverride);
    json.emit("isDirectCounter", isDirectCounter);
    json.emit("isDirectMeter", isDirectMeter);
    json.emit("actionList", actionList);
    json.emit("const_entries", const_entries);
}
IR::TCTable::TCTable(JSONLoader & json) : Node(json) {
    json.load("tableID", tableID);
    json.load("tableName", tableName);
    json.load("controlName", controlName);
    json.load("pipelineName", pipelineName);
    json.load("permissions", permissions);
    json.load("directCounterInstance", directCounterInstance);
    json.load("directMeterInstance", directMeterInstance);
    json.load("keySize", keySize);
    json.load("tableEntriesCount", tableEntriesCount);
    json.load("numMask", numMask);
    json.load("matchType", matchType);
    json.load("timerProfiles", timerProfiles);
    json.load("defaultTimerProfiles", defaultTimerProfiles);
    json.load("defaultHitAction", defaultHitAction);
    json.load("isDefaultHitConst", isDefaultHitConst);
    json.load("isTcMayOverrideHit", isTcMayOverrideHit);
    json.load("defaultHitActionParams", defaultHitActionParams);
    json.load("defaultMissAction", defaultMissAction);
    json.load("isDefaultMissConst", isDefaultMissConst);
    json.load("isTcMayOverrideMiss", isTcMayOverrideMiss);
    json.load("defaultMissActionParams", defaultMissActionParams);
    json.load("isTableAddOnMiss", isTableAddOnMiss);
    json.load("isTcMayOverride", isTcMayOverride);
    json.load("isDirectCounter", isDirectCounter);
    json.load("isDirectMeter", isDirectMeter);
    json.load("actionList", actionList);
    json.load("const_entries", const_entries);
}
IR::Node * IR::TCTable::fromJSON(JSONLoader & json) { return new TCTable(json); }
bool IR::TCTable::operator==(IR::Node const & a) const { return a == *this; }
#line 445 "/root/p4c/backends/tc/tc.def"
IR::TCKey::TCKey(unsigned id, unsigned width, cstring ptype, cstring name, cstring attr, bool isID) {
        keyID = id;
        bitwidth = width;
        type = ptype;
        keyName = name;
        keyAttribute = attr;
        emitID = isID;
        emitValue = false;
    }
#line 13297 "/root/p4c/build/ir/ir-generated.cpp"
#line 454 "/root/p4c/backends/tc/tc.def"
void IR::TCKey::setValue(unsigned v) {
        value = v;
        emitValue = true;
    }
#line 13303 "/root/p4c/build/ir/ir-generated.cpp"
#line 458 "/root/p4c/backends/tc/tc.def"
cstring IR::TCKey::toString() const {
        std::string tckeyInstance = absl::StrCat(" ", keyAttribute, " ", keyName, " ptype ", type);
        if (emitID) {
            absl::StrAppend(&tckeyInstance, " id ", keyID);
        }
        if (emitValue) {
            absl::StrAppend(&tckeyInstance, " ", value);
        }
        return tckeyInstance;
    }
#line 13315 "/root/p4c/build/ir/ir-generated.cpp"
#line 468 "/root/p4c/backends/tc/tc.def"
void IR::TCKey::dbprint(std::ostream & out) const { out << toString(); }
#line 13318 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::TCKey::operator==(IR::TCKey const & a) const {
        return this->typeId() == a.typeId()
        && keyID == a.keyID
        && bitwidth == a.bitwidth
        && type == a.type
        && keyName == a.keyName
        && keyAttribute == a.keyAttribute
        && emitID == a.emitID
        && emitValue == a.emitValue
        && value == a.value;
    }
bool IR::TCKey::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const TCKey &>(a_);
        return keyID == a.keyID
        && bitwidth == a.bitwidth
        && type == a.type
        && keyName == a.keyName
        && keyAttribute == a.keyAttribute
        && emitID == a.emitID
        && emitValue == a.emitValue
        && value == a.value;
    }
void IR::TCKey::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " keyID=" << keyID;
        out << " bitwidth=" << bitwidth;
        out << " type=" << type;
        out << " keyName=" << keyName;
        out << " keyAttribute=" << keyAttribute;
        out << " emitID=" << emitID;
        out << " emitValue=" << emitValue;
        out << " value=" << value;
}
void IR::TCKey::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("keyID", keyID);
    json.emit("bitwidth", bitwidth);
    json.emit("type", type);
    json.emit("keyName", keyName);
    json.emit("keyAttribute", keyAttribute);
    json.emit("emitID", emitID);
    json.emit("emitValue", emitValue);
    json.emit("value", value);
}
IR::TCKey::TCKey(JSONLoader & json) : Node(json) {
    json.load("keyID", keyID);
    json.load("bitwidth", bitwidth);
    json.load("type", type);
    json.load("keyName", keyName);
    json.load("keyAttribute", keyAttribute);
    json.load("emitID", emitID);
    json.load("emitValue", emitValue);
    json.load("value", value);
}
IR::Node * IR::TCKey::fromJSON(JSONLoader & json) { return new TCKey(json); }
bool IR::TCKey::operator==(IR::Node const & a) const { return a == *this; }
#line 484 "/root/p4c/backends/tc/tc.def"
IR::TCExternInstance::TCExternInstance(unsigned id, cstring name, bool isNe, unsigned ne) {
        instanceID = id;
        instanceName = name;
        isNumelemns = isNe;
        numelemns = ne;
        isControlPath = false;
        isTablBindable = false;
        isInstanceType = false;
        isConstructorKeys = false;
    }
#line 13388 "/root/p4c/build/ir/ir-generated.cpp"
#line 494 "/root/p4c/backends/tc/tc.def"
void IR::TCExternInstance::addControlPathKeys(safe_vector<const IR::TCKey *> k) {
        if (k.size() > 0) {
            isControlPath = true;
            controlKeys = k;
        }
    }
#line 13396 "/root/p4c/build/ir/ir-generated.cpp"
#line 500 "/root/p4c/backends/tc/tc.def"
void IR::TCExternInstance::addConstructorKeys(safe_vector<const IR::TCKey *> k) {
        if (k.size() > 0) {
            isConstructorKeys = true;
            constructorKeys = k;
        }
    }
#line 13404 "/root/p4c/build/ir/ir-generated.cpp"
#line 506 "/root/p4c/backends/tc/tc.def"
void IR::TCExternInstance::setExternTypeInstance(cstring type) {
        isInstanceType = true;
        instanceType = type;
    }
#line 13410 "/root/p4c/build/ir/ir-generated.cpp"
#line 510 "/root/p4c/backends/tc/tc.def"
void IR::TCExternInstance::setExternTableBindable(bool flag) {
        isTablBindable = flag;
    }
#line 13415 "/root/p4c/build/ir/ir-generated.cpp"
#line 513 "/root/p4c/backends/tc/tc.def"
void IR::TCExternInstance::setNumElements(unsigned ne) {
        isNumelemns = true;
        numelemns = ne;
    }
#line 13421 "/root/p4c/build/ir/ir-generated.cpp"
#line 517 "/root/p4c/backends/tc/tc.def"
cstring IR::TCExternInstance::toString() const {
        std::string tcExternInstance = absl::StrCat(instanceName, " instid ", instanceID, " \\");
        if (isNumelemns) {
            absl::StrAppend(&tcExternInstance, "\ntc_numel ", numelemns, " \\");
        }
        if (isTablBindable) {
            absl::StrAppend(&tcExternInstance, "\ntbl_bindable", " \\");
        }
        if (isConstructorKeys) {
            absl::StrAppend(&tcExternInstance, "\nconstructor");
            for (auto field : constructorKeys) {
                absl::StrAppend(&tcExternInstance, field);
            }
            absl::StrAppend(&tcExternInstance, " \\");
        }
        if (isControlPath) {
            absl::StrAppend(&tcExternInstance, "\ncontrol_path");
            for (auto field : controlKeys) {
                absl::StrAppend(&tcExternInstance, field);
            }
        }
        return tcExternInstance;
    }
#line 13446 "/root/p4c/build/ir/ir-generated.cpp"
#line 540 "/root/p4c/backends/tc/tc.def"
void IR::TCExternInstance::dbprint(std::ostream & out) const { out << toString(); }
#line 13449 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::TCExternInstance::operator==(IR::TCExternInstance const & a) const {
        return this->typeId() == a.typeId()
        && instanceID == a.instanceID
        && instanceName == a.instanceName
        && isNumelemns == a.isNumelemns
        && numelemns == a.numelemns
        && isControlPath == a.isControlPath
        && isTablBindable == a.isTablBindable
        && isInstanceType == a.isInstanceType
        && isConstructorKeys == a.isConstructorKeys
        && instanceType == a.instanceType
        && controlKeys == a.controlKeys
        && constructorKeys == a.constructorKeys;
    }
bool IR::TCExternInstance::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const TCExternInstance &>(a_);
        return instanceID == a.instanceID
        && instanceName == a.instanceName
        && isNumelemns == a.isNumelemns
        && numelemns == a.numelemns
        && isControlPath == a.isControlPath
        && isTablBindable == a.isTablBindable
        && isInstanceType == a.isInstanceType
        && isConstructorKeys == a.isConstructorKeys
        && instanceType == a.instanceType
        && controlKeys == a.controlKeys
        && constructorKeys == a.constructorKeys;
    }
void IR::TCExternInstance::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " instanceID=" << instanceID;
        out << " instanceName=" << instanceName;
        out << " isNumelemns=" << isNumelemns;
        out << " numelemns=" << numelemns;
        out << " isControlPath=" << isControlPath;
        out << " isTablBindable=" << isTablBindable;
        out << " isInstanceType=" << isInstanceType;
        out << " isConstructorKeys=" << isConstructorKeys;
        out << " instanceType=" << instanceType;
}
void IR::TCExternInstance::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("instanceID", instanceID);
    json.emit("instanceName", instanceName);
    json.emit("isNumelemns", isNumelemns);
    json.emit("numelemns", numelemns);
    json.emit("isControlPath", isControlPath);
    json.emit("isTablBindable", isTablBindable);
    json.emit("isInstanceType", isInstanceType);
    json.emit("isConstructorKeys", isConstructorKeys);
    json.emit("instanceType", instanceType);
    json.emit("controlKeys", controlKeys);
    json.emit("constructorKeys", constructorKeys);
}
IR::TCExternInstance::TCExternInstance(JSONLoader & json) : Node(json) {
    json.load("instanceID", instanceID);
    json.load("instanceName", instanceName);
    json.load("isNumelemns", isNumelemns);
    json.load("numelemns", numelemns);
    json.load("isControlPath", isControlPath);
    json.load("isTablBindable", isTablBindable);
    json.load("isInstanceType", isInstanceType);
    json.load("isConstructorKeys", isConstructorKeys);
    json.load("instanceType", instanceType);
    json.load("controlKeys", controlKeys);
    json.load("constructorKeys", constructorKeys);
}
IR::Node * IR::TCExternInstance::fromJSON(JSONLoader & json) { return new TCExternInstance(json); }
bool IR::TCExternInstance::operator==(IR::Node const & a) const { return a == *this; }
#line 551 "/root/p4c/backends/tc/tc.def"
IR::TCExtern::TCExtern(cstring eId, cstring eN, cstring pN, unsigned inst, cstring p, bool exec_method) {
        externID = eId;
        externName = eN;
        pipelineName = pN;
        numinstances = inst;
        acl_permisson = p;
        has_exec_method = exec_method;
    }
#line 13530 "/root/p4c/build/ir/ir-generated.cpp"
#line 559 "/root/p4c/backends/tc/tc.def"
void IR::TCExtern::addExternInstance(const IR::TCExternInstance* tei) {
        externInstances.push_back(tei);
    }
#line 13535 "/root/p4c/build/ir/ir-generated.cpp"
#line 562 "/root/p4c/backends/tc/tc.def"
const IR::TCExternInstance *IR::TCExtern::getExternInstance(cstring inst_name) const {
        for (auto extnInstDef : externInstances) {
            if(extnInstDef->instanceName == inst_name) {
                return extnInstDef;
            }
        }
        return nullptr;
    }
#line 13545 "/root/p4c/build/ir/ir-generated.cpp"
#line 570 "/root/p4c/backends/tc/tc.def"
cstring IR::TCExtern::toString() const {
        std::string tcExtern = absl::StrCat("\n$TC p4template create extern/", "root/", externName,
                                            " extid ", externID, " numinstances ", numinstances, " tc_acl " + acl_permisson);
        if (has_exec_method) {
             absl::StrAppend(&tcExtern, " has_exec_method");
        }
        for (unsigned iter = 0; iter < numinstances; iter++) {
            absl::StrAppend(&tcExtern, "\n\n$TC p4template create extern_inst/", pipelineName,
                      "/", externName, "/");
            if (externInstances.size() > iter)
                absl::StrAppend(&tcExtern, externInstances[iter]->toString());
        }
        return tcExtern;
    }
#line 13561 "/root/p4c/build/ir/ir-generated.cpp"
#line 584 "/root/p4c/backends/tc/tc.def"
void IR::TCExtern::dbprint(std::ostream & out) const { out << toString(); }
#line 13564 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::TCExtern::operator==(IR::TCExtern const & a) const {
        return this->typeId() == a.typeId()
        && externName == a.externName
        && pipelineName == a.pipelineName
        && acl_permisson == a.acl_permisson
        && externID == a.externID
        && numinstances == a.numinstances
        && externInstances == a.externInstances
        && has_exec_method == a.has_exec_method;
    }
bool IR::TCExtern::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const TCExtern &>(a_);
        return externName == a.externName
        && pipelineName == a.pipelineName
        && acl_permisson == a.acl_permisson
        && externID == a.externID
        && numinstances == a.numinstances
        && externInstances == a.externInstances
        && has_exec_method == a.has_exec_method;
    }
void IR::TCExtern::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " externName=" << externName;
        out << " pipelineName=" << pipelineName;
        out << " acl_permisson=" << acl_permisson;
        out << " externID=" << externID;
        out << " numinstances=" << numinstances;
        out << " has_exec_method=" << has_exec_method;
}
void IR::TCExtern::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("externName", externName);
    json.emit("pipelineName", pipelineName);
    json.emit("acl_permisson", acl_permisson);
    json.emit("externID", externID);
    json.emit("numinstances", numinstances);
    json.emit("externInstances", externInstances);
    json.emit("has_exec_method", has_exec_method);
}
IR::TCExtern::TCExtern(JSONLoader & json) : Node(json) {
    json.load("externName", externName);
    json.load("pipelineName", pipelineName);
    json.load("acl_permisson", acl_permisson);
    json.load("externID", externID);
    json.load("numinstances", numinstances);
    json.load("externInstances", externInstances);
    json.load("has_exec_method", has_exec_method);
}
IR::Node * IR::TCExtern::fromJSON(JSONLoader & json) { return new TCExtern(json); }
bool IR::TCExtern::operator==(IR::Node const & a) const { return a == *this; }
#line 596 "/root/p4c/backends/tc/tc.def"
void IR::TCPipeline::setPipelineName(cstring pName) {
        pipelineName = pName;
    }
#line 13621 "/root/p4c/build/ir/ir-generated.cpp"
#line 599 "/root/p4c/backends/tc/tc.def"
void IR::TCPipeline::setNumTables(unsigned n) {
        numTables = n;
    }
#line 13626 "/root/p4c/build/ir/ir-generated.cpp"
#line 602 "/root/p4c/backends/tc/tc.def"
void IR::TCPipeline::addNoActionDefinition(const IR::TCAction* actionDef) {
        NoAction = actionDef;
    }
#line 13631 "/root/p4c/build/ir/ir-generated.cpp"
#line 605 "/root/p4c/backends/tc/tc.def"
void IR::TCPipeline::addActionDefinition(const IR::TCAction* actionDef) {
        actionDefs.push_back(actionDef);
    }
#line 13636 "/root/p4c/build/ir/ir-generated.cpp"
#line 608 "/root/p4c/backends/tc/tc.def"
void IR::TCPipeline::addTableDefinition(const IR::TCTable* tableDef) {
        tableDefs.push_back(tableDef);
    }
#line 13641 "/root/p4c/build/ir/ir-generated.cpp"
#line 611 "/root/p4c/backends/tc/tc.def"
void IR::TCPipeline::setPipelinePreAction(const IR::TCAction* action) {
        preaction = action;
    }
#line 13646 "/root/p4c/build/ir/ir-generated.cpp"
#line 614 "/root/p4c/backends/tc/tc.def"
void IR::TCPipeline::setPipelinePostAction(const IR::TCAction* action) {
        postaction = action;
    }
#line 13651 "/root/p4c/build/ir/ir-generated.cpp"
#line 617 "/root/p4c/backends/tc/tc.def"
void IR::TCPipeline::addExternDefinition(const IR::TCExtern* externDef) {
        externDefs.push_back(externDef);
    }
#line 13656 "/root/p4c/build/ir/ir-generated.cpp"
#line 620 "/root/p4c/backends/tc/tc.def"
const IR::TCExtern *IR::TCPipeline::getExternDefinition(cstring eName) const {
        for (auto externDef : externDefs) {
            if(externDef->externName == eName) {
                return externDef;
            }
        }
        return nullptr;
    }
#line 13666 "/root/p4c/build/ir/ir-generated.cpp"
#line 628 "/root/p4c/backends/tc/tc.def"
IR::TCPipeline::TCPipeline() {
        Util::SourceInfo* srcinfo = new Util::SourceInfo();
        Node::srcInfo = *srcinfo;
        pipelineName = nullptr;
    }
#line 13673 "/root/p4c/build/ir/ir-generated.cpp"
#line 633 "/root/p4c/backends/tc/tc.def"
cstring IR::TCPipeline::toString() const {
        std::string tcCode = absl::StrCat("#!/bin/bash -x\n",
                                        "\nset -e\n", "\n: \"${TC:=\"tc\"}\"",
                                        "\n$TC p4template create pipeline/", pipelineName,
                                        " numtables ", numTables);
        if (!actionDefs.empty()) {
            for (auto a : actionDefs) {
                absl::StrAppend(&tcCode, "\n", a);
            }
        }
        if (!externDefs.empty()) {
            for (auto e : externDefs) {
                absl::StrAppend(&tcCode, "\n", e);
            }
        }
        if (!tableDefs.empty()) {
            for (auto t : tableDefs) {
                absl::StrAppend(&tcCode, "\n", t);
            }
        }
        if (preaction != nullptr) {
            absl::StrAppend(&tcCode, "\n", preaction,
                            "\n$TC p4template update pipeline/", pipelineName,
                            " preactions action ", pipelineName, "/preaction");
        }
        if (postaction != nullptr) {
            absl::StrAppend(&tcCode, "\n", postaction,
                            "\n$TC p4template update pipeline/", pipelineName,
                            " postactions action ", pipelineName, "/postaction");
        }
        absl::StrAppend(&tcCode, "\n$TC p4template update pipeline/", pipelineName, " state ready");
        return tcCode;
    }
#line 13708 "/root/p4c/build/ir/ir-generated.cpp"
#line 666 "/root/p4c/backends/tc/tc.def"
void IR::TCPipeline::dbprint(std::ostream & out) const { out << toString(); }
#line 13711 "/root/p4c/build/ir/ir-generated.cpp"
bool IR::TCPipeline::operator==(IR::TCPipeline const & a) const {
        return this->typeId() == a.typeId()
        && pipelineName == a.pipelineName
        && numTables == a.numTables
        && NoAction == a.NoAction
        && actionDefs == a.actionDefs
        && tableDefs == a.tableDefs
        && externDefs == a.externDefs
        && preaction == a.preaction
        && postaction == a.postaction;
    }
bool IR::TCPipeline::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (this->typeId() != a_.typeId()) return false;
        auto &a = static_cast<const TCPipeline &>(a_);
        return pipelineName == a.pipelineName
        && numTables == a.numTables
        && (NoAction ? a.NoAction ? NoAction->equiv(*a.NoAction) : false : a.NoAction == nullptr)
        && actionDefs == a.actionDefs
        && tableDefs == a.tableDefs
        && externDefs == a.externDefs
        && (preaction ? a.preaction ? preaction->equiv(*a.preaction) : false : a.preaction == nullptr)
        && (postaction ? a.postaction ? postaction->equiv(*a.postaction) : false : a.postaction == nullptr);
    }
void IR::TCPipeline::visit_children(Visitor & v, char const * n) {
    (void)n;
    Node::visit_children(v, n);
    v.visit(NoAction, "NoAction");
    v.visit(preaction, "preaction");
    v.visit(postaction, "postaction");
}
void IR::TCPipeline::visit_children(Visitor & v, char const * n) const {
    (void)n;
    Node::visit_children(v, n);
    v.visit(NoAction, "NoAction");
    v.visit(preaction, "preaction");
    v.visit(postaction, "postaction");
}
void IR::TCPipeline::validate() const {
#line 13751 "/root/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(NoAction);
        CHECK_NULL(preaction);
        CHECK_NULL(postaction); }
void IR::TCPipeline::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " pipelineName=" << pipelineName;
        out << " numTables=" << numTables;
}
void IR::TCPipeline::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json.emit("pipelineName", pipelineName);
    json.emit("numTables", numTables);
    json.emit("NoAction", NoAction);
    json.emit("actionDefs", actionDefs);
    json.emit("tableDefs", tableDefs);
    json.emit("externDefs", externDefs);
    json.emit("preaction", preaction);
    json.emit("postaction", postaction);
}
IR::TCPipeline::TCPipeline(JSONLoader & json) : Node(json) {
    json.load("pipelineName", pipelineName);
    json.load("numTables", numTables);
    json.load("NoAction", NoAction);
    json.load("actionDefs", actionDefs);
    json.load("tableDefs", tableDefs);
    json.load("externDefs", externDefs);
    json.load("preaction", preaction);
    json.load("postaction", postaction);
}
IR::Node * IR::TCPipeline::fromJSON(JSONLoader & json) { return new TCPipeline(json); }
bool IR::TCPipeline::operator==(IR::Node const & a) const { return a == *this; }
