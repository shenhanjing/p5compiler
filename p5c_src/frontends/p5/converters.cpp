/*
Copyright 2013-present Barefoot Networks, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "frontends/p5/converters.h"

#include <sstream>

#include "frontends/common/options.h"
#include "frontends/p4-14/fromv1.0/v1model.h"
#include "frontends/p5/parse_annotations.h"
#include "frontends/parsers/p4/p4parser.hpp"
#include "frontends/parsers/parserDriver.h"
#include "lib/log.h"

namespace P4::P5 {

// P4 include 目录路径
static const char *p4includePath = "/usr/local/share/p4c";

// ============================================================================
// P5ProgramStructure 实现
// ============================================================================

P5ProgramStructure::P5ProgramStructure()
    : v1model(P4V1::V1Model::instance), p4lib(P4::P4CoreLibrary::instance()) {
    declarations = new IR::Vector<IR::Node>();
}

void P5ProgramStructure::loadModel() {
    LOG1("Loading v1model for P5");
    // 构造版本参数
    std::stringstream versionArg;
    versionArg << "-DV1MODEL_VERSION=" << P4V1::V1Model::versionCurrent;
    // 包含 v1model.p4
    include(v1model.file.name, versionArg.str());
}

void P5ProgramStructure::include(cstring filename, cstring ppoptions) {
    // 使用环境变量或默认的 p4include 路径
    char *drvP4IncludePath = getenv("P4C_16_INCLUDE_PATH");
    std::filesystem::path path((drvP4IncludePath != nullptr) ? drvP4IncludePath : p4includePath);
    path /= std::string(filename);

    LOG1("Including " << path);

    // 预处理和解析
    CompilerOptions options;
    if (ppoptions != nullptr) {
        options.preprocessor_options += " ";
        options.preprocessor_options += ppoptions;
    }
    options.langVersion = CompilerOptions::FrontendVersion::P4_16;
    options.file = path;

    if (::P4::errorCount() == 0) {
        auto preprocessorResult = options.preprocess();
        if (preprocessorResult.has_value()) {
            const auto *code = P4::P4ParserDriver::parse(preprocessorResult.value().get(),
                                                         options.file.string());
            if (code != nullptr && ::P4::errorCount() == 0) {
                // 将解析得到的声明添加到 declarations 中
                for (const auto *decl : code->objects) {
                    declarations->push_back(decl);
                }
                LOG1("Successfully included " << filename << " with " << code->objects.size()
                                              << " declarations");
            }
        }
    }
}

void P5ProgramStructure::extractComponents(const IR::P4Program *p5Program) {
    CHECK_NULL(p5Program);
    LOG1("Extracting components from P5 program");

    // 遍历 P5 程序的所有声明，提取各个组件
    for (const auto *obj : p5Program->objects) {
        if (const auto *parser = obj->to<IR::P4Parser>()) {
            // 根据名称判断是 parser_i 还是 parser_e
            if (parser->name == "ParserImpl_i" || parser->name == "parser_i") {
                parser_i = parser;
                LOG1("Found ingress parser: " << parser->name);
            } else if (parser->name == "ParserImpl_e" || parser->name == "parser_e") {
                parser_e = parser;
                LOG1("Found egress parser: " << parser->name);
            } else {
                // 如果只有一个未命名的 parser，假设为 ingress parser
                if (parser_i == nullptr) {
                    parser_i = parser;
                    LOG1("Found default parser (assuming ingress): " << parser->name);
                }
            }
            // 将 parser 添加到 declarations
            declarations->push_back(parser);
        } else if (const auto *control = obj->to<IR::P4Control>()) {
            // 根据名称判断是哪个 control
            if (control->name == "verifyChecksum") {
                verifyChecksum = control;
                LOG1("Found verifyChecksum control");
            } else if (control->name == "ingress") {
                ingress = control;
                LOG1("Found ingress control");
            } else if (control->name == "egress") {
                egress = control;
                LOG1("Found egress control");
            } else if (control->name == "computeChecksum") {
                computeChecksum = control;
                LOG1("Found computeChecksum control");
            } else if (control->name == "DeparserImpl" || control->name == "deparser") {
                deparser = control;
                LOG1("Found deparser control");
            }
            // 将 control 添加到 declarations
            declarations->push_back(control);
        } else {
            // 其他声明（类型、常量等）也添加到 declarations
            declarations->push_back(obj);
        }
    }

    // 检查必需组件
    if (ingress == nullptr) {
        ::P4::warning(ErrorType::WARN_MISSING, "P5 program does not define an 'ingress' control");
    }
}

const IR::P4Parser *P5ProgramStructure::createEmptyParser(cstring name) {
    // 创建 parser 的参数列表
    auto paramList = new IR::ParameterList();

    // packet_in parameter
    auto pinpath = new IR::Path(p4lib.packetIn.Id());
    auto pintype = new IR::Type_Name(pinpath);
    auto packetParam = new IR::Parameter(IR::ID("packet"), IR::Direction::None, pintype);
    paramList->push_back(packetParam);

    // headers parameter (out)
    auto headpath = new IR::Path(v1model.headersType.Id());
    auto headtype = new IR::Type_Name(headpath);
    auto headersParam = new IR::Parameter(IR::ID("hdr"), IR::Direction::Out, headtype);
    paramList->push_back(headersParam);

    // metadata parameter (inout)
    auto metapath = new IR::Path(v1model.metadataType.Id());
    auto metatype = new IR::Type_Name(metapath);
    auto metaParam = new IR::Parameter(IR::ID("meta"), IR::Direction::InOut, metatype);
    paramList->push_back(metaParam);

    // standard_metadata parameter (inout)
    auto stdMetaPath = new IR::Path(v1model.standardMetadataType.Id());
    auto stdMetaType = new IR::Type_Name(stdMetaPath);
    auto stdMetaParam = new IR::Parameter(IR::ID("standard_metadata"), IR::Direction::InOut, stdMetaType);
    paramList->push_back(stdMetaParam);

    // 创建 parser 类型
    auto type = new IR::Type_Parser(IR::ID(name), new IR::TypeParameters(), paramList);

    // 创建空的 start state (直接 accept)
    auto startState = new IR::ParserState(IR::ID("start"), IR::IndexedVector<IR::StatOrDecl>(),
                                          new IR::PathExpression(IR::ID("accept")));

    IR::IndexedVector<IR::ParserState> states;
    states.push_back(startState);

    // 创建 parser
    auto parser =
        new IR::P4Parser(IR::ID(name), type, IR::IndexedVector<IR::Declaration>(), states);

    LOG1("Created empty parser: " << name);
    return parser;
}

const IR::P4Control *P5ProgramStructure::createEmptyControl(cstring name) {
    // 创建 control 的参数列表
    auto paramList = new IR::ParameterList();

    // headers parameter (inout)
    auto headpath = new IR::Path(v1model.headersType.Id());
    auto headtype = new IR::Type_Name(headpath);
    auto headersParam = new IR::Parameter(IR::ID("hdr"), IR::Direction::InOut, headtype);
    paramList->push_back(headersParam);

    // metadata parameter (inout)
    auto metapath = new IR::Path(v1model.metadataType.Id());
    auto metatype = new IR::Type_Name(metapath);
    auto metaParam = new IR::Parameter(IR::ID("meta"), IR::Direction::InOut, metatype);
    paramList->push_back(metaParam);

    // standard_metadata parameter (inout)
    auto stdMetaPath = new IR::Path(v1model.standardMetadataType.Id());
    auto stdMetaType = new IR::Type_Name(stdMetaPath);
    auto stdMetaParam = new IR::Parameter(IR::ID("standard_metadata"), IR::Direction::InOut, stdMetaType);
    paramList->push_back(stdMetaParam);

    // 创建 control 类型
    auto type = new IR::Type_Control(IR::ID(name), new IR::TypeParameters(), paramList);

    // 创建空的 body
    auto body = new IR::BlockStatement();

    // 创建 control
    auto control = new IR::P4Control(IR::ID(name), type, new IR::ParameterList(),
                                     IR::IndexedVector<IR::Declaration>(), body);

    LOG1("Created empty control: " << name);
    return control;
}

const IR::P4Control *P5ProgramStructure::createEmptyChecksumControl(cstring name) {
    // Checksum control 的参数列表：只有 hdr 和 meta，没有 standard_metadata
    auto paramList = new IR::ParameterList();

    // headers parameter (inout)
    auto headpath = new IR::Path(v1model.headersType.Id());
    auto headtype = new IR::Type_Name(headpath);
    auto headersParam = new IR::Parameter(IR::ID("hdr"), IR::Direction::InOut, headtype);
    paramList->push_back(headersParam);

    // metadata parameter (inout)
    auto metapath = new IR::Path(v1model.metadataType.Id());
    auto metatype = new IR::Type_Name(metapath);
    auto metaParam = new IR::Parameter(IR::ID("meta"), IR::Direction::InOut, metatype);
    paramList->push_back(metaParam);

    // 创建 control 类型
    auto type = new IR::Type_Control(IR::ID(name), new IR::TypeParameters(), paramList);

    // 创建空的 body
    auto body = new IR::BlockStatement();

    // 创建 control
    auto control = new IR::P4Control(IR::ID(name), type, new IR::ParameterList(),
                                     IR::IndexedVector<IR::Declaration>(), body);

    LOG1("Created empty checksum control: " << name);
    return control;
}

const IR::P4Control *P5ProgramStructure::createEmptyDeparser(cstring name) {
    // Deparser 的参数列表与普通 control 不同
    auto paramList = new IR::ParameterList();

    // packet_out parameter
    auto poutpath = new IR::Path(p4lib.packetOut.Id());
    auto pouttype = new IR::Type_Name(poutpath);
    auto packetParam = new IR::Parameter(IR::ID("packet"), IR::Direction::None, pouttype);
    paramList->push_back(packetParam);

    // headers parameter (in, not inout!)
    auto headpath = new IR::Path(v1model.headersType.Id());
    auto headtype = new IR::Type_Name(headpath);
    auto headersParam = new IR::Parameter(IR::ID("hdr"), IR::Direction::In, headtype);
    paramList->push_back(headersParam);

    // 创建 control 类型
    auto type = new IR::Type_Control(IR::ID(name), new IR::TypeParameters(), paramList);

    // 创建空的 body
    auto body = new IR::BlockStatement();

    // 创建 control
    auto control = new IR::P4Control(IR::ID(name), type, new IR::ParameterList(),
                                     IR::IndexedVector<IR::Declaration>(), body);

    LOG1("Created empty deparser: " << name);
    return control;
}

void P5ProgramStructure::createMain() {
    LOG1("Creating V1Switch main with dual parsers");

    auto name = IR::ID(IR::P4Program::main);
    auto typepath = new IR::Path(v1model.sw.Id());  // "V1Switch"
    auto type = new IR::Type_Name(typepath);
    auto args = new IR::Vector<IR::Argument>();
    auto emptyArgs = new IR::Vector<IR::Argument>();

    // 参数1: parser_i (ingress parser)
    const IR::Expression *parser_i_expr = nullptr;
    if (parser_i != nullptr) {
        auto parser_i_path = new IR::Path(parser_i->name);
        auto parser_i_type = new IR::Type_Name(parser_i_path);
        parser_i_expr = new IR::ConstructorCallExpression(parser_i_type, emptyArgs);
    } else {
        LOG1("No ingress parser found, creating empty ParserImpl_i");
        auto emptyParser = createEmptyParser(cstring("ParserImpl_i"));
        declarations->push_back(emptyParser);
        parser_i = emptyParser;
        auto parser_i_path = new IR::Path(parser_i->name);
        auto parser_i_type = new IR::Type_Name(parser_i_path);
        parser_i_expr = new IR::ConstructorCallExpression(parser_i_type, emptyArgs);
    }
    args->push_back(new IR::Argument(parser_i_expr));

    // 参数2: verifyChecksum（只有 hdr 和 meta 两个参数）
    const IR::Expression *verify_expr = nullptr;
    if (verifyChecksum != nullptr) {
        auto verify_path = new IR::Path(verifyChecksum->name);
        auto verify_type = new IR::Type_Name(verify_path);
        verify_expr = new IR::ConstructorCallExpression(verify_type, emptyArgs);
    } else {
        LOG1("No verifyChecksum control found, creating empty verifyChecksum");
        auto emptyControl = createEmptyChecksumControl(cstring("verifyChecksum"));
        declarations->push_back(emptyControl);
        verifyChecksum = emptyControl;
        auto verify_path = new IR::Path(verifyChecksum->name);
        auto verify_type = new IR::Type_Name(verify_path);
        verify_expr = new IR::ConstructorCallExpression(verify_type, emptyArgs);
    }
    args->push_back(new IR::Argument(verify_expr));

    // 参数3: ingress
    const IR::Expression *ingress_expr = nullptr;
    if (ingress != nullptr) {
        auto ingress_path = new IR::Path(ingress->name);
        auto ingress_type = new IR::Type_Name(ingress_path);
        ingress_expr = new IR::ConstructorCallExpression(ingress_type, emptyArgs);
    } else {
        LOG1("No ingress control found, creating empty ingress");
        auto emptyControl = createEmptyControl(cstring("ingress"));
        declarations->push_back(emptyControl);
        ingress = emptyControl;
        auto ingress_path = new IR::Path(ingress->name);
        auto ingress_type = new IR::Type_Name(ingress_path);
        ingress_expr = new IR::ConstructorCallExpression(ingress_type, emptyArgs);
    }
    args->push_back(new IR::Argument(ingress_expr));

    // 参数4: parser_e (egress parser)
    const IR::Expression *parser_e_expr = nullptr;
    if (parser_e != nullptr) {
        auto parser_e_path = new IR::Path(parser_e->name);
        auto parser_e_type = new IR::Type_Name(parser_e_path);
        parser_e_expr = new IR::ConstructorCallExpression(parser_e_type, emptyArgs);
    } else {
        // 如果没有定义 egress parser，使用 ingress parser
        LOG1("No egress parser found, using ingress parser for both");
        auto parser_i_path = new IR::Path(parser_i->name);
        auto parser_i_type = new IR::Type_Name(parser_i_path);
        parser_e_expr = new IR::ConstructorCallExpression(parser_i_type, emptyArgs);
    }
    args->push_back(new IR::Argument(parser_e_expr));

    // 参数5: egress
    const IR::Expression *egress_expr = nullptr;
    if (egress != nullptr) {
        auto egress_path = new IR::Path(egress->name);
        auto egress_type = new IR::Type_Name(egress_path);
        egress_expr = new IR::ConstructorCallExpression(egress_type, emptyArgs);
    } else {
        LOG1("No egress control found, creating empty egress");
        auto emptyControl = createEmptyControl(cstring("egress"));
        declarations->push_back(emptyControl);
        egress = emptyControl;
        auto egress_path = new IR::Path(egress->name);
        auto egress_type = new IR::Type_Name(egress_path);
        egress_expr = new IR::ConstructorCallExpression(egress_type, emptyArgs);
    }
    args->push_back(new IR::Argument(egress_expr));

    // 参数6: computeChecksum（只有 hdr 和 meta 两个参数）
    const IR::Expression *compute_expr = nullptr;
    if (computeChecksum != nullptr) {
        auto compute_path = new IR::Path(computeChecksum->name);
        auto compute_type = new IR::Type_Name(compute_path);
        compute_expr = new IR::ConstructorCallExpression(compute_type, emptyArgs);
    } else {
        LOG1("No computeChecksum control found, creating empty computeChecksum");
        auto emptyControl = createEmptyChecksumControl(cstring("computeChecksum"));
        declarations->push_back(emptyControl);
        computeChecksum = emptyControl;
        auto compute_path = new IR::Path(computeChecksum->name);
        auto compute_type = new IR::Type_Name(compute_path);
        compute_expr = new IR::ConstructorCallExpression(compute_type, emptyArgs);
    }
    args->push_back(new IR::Argument(compute_expr));

    // 参数7: deparser（注意：deparser 的参数签名不同）
    const IR::Expression *deparser_expr = nullptr;
    if (deparser != nullptr) {
        auto deparser_path = new IR::Path(deparser->name);
        auto deparser_type = new IR::Type_Name(deparser_path);
        deparser_expr = new IR::ConstructorCallExpression(deparser_type, emptyArgs);
    } else {
        LOG1("No deparser control found, creating empty DeparserImpl");
        auto emptyDeparser = createEmptyDeparser(cstring("DeparserImpl"));
        declarations->push_back(emptyDeparser);
        deparser = emptyDeparser;
        auto deparser_path = new IR::Path(deparser->name);
        auto deparser_type = new IR::Type_Name(deparser_path);
        deparser_expr = new IR::ConstructorCallExpression(deparser_type, emptyArgs);
    }
    args->push_back(new IR::Argument(deparser_expr));

    // 创建 main 实例声明
    auto result = new IR::Declaration_Instance(name, type, args, nullptr);
    declarations->push_back(result);

    LOG1("V1Switch main created with " << args->size() << " components");
}

bool P5ProgramStructure::isTypeDefined(cstring typeName) {
    // 检查 declarations 中是否已经定义了指定的类型
    for (const auto *decl : *declarations) {
        if (const auto *typeDecl = decl->to<IR::Type_Declaration>()) {
            if (typeDecl->name == typeName) {
                return true;
            }
        }
    }
    return false;
}

void P5ProgramStructure::ensureRequiredTypes() {
    LOG1("Ensuring required types exist");

    // 检查并创建 headers 类型（如果不存在）
    if (!isTypeDefined(v1model.headersType.Id())) {
        LOG1("Creating empty headers struct");
        auto headersStruct = new IR::Type_Struct(v1model.headersType.Id());
        declarations->push_back(headersStruct);
    }

    // 检查并创建 metadata 类型（如果不存在）
    if (!isTypeDefined(v1model.metadataType.Id())) {
        LOG1("Creating empty metadata struct");
        auto metadataStruct = new IR::Type_Struct(v1model.metadataType.Id());
        declarations->push_back(metadataStruct);
    }
}

const IR::P4Program *P5ProgramStructure::create(Util::SourceInfo info) {
    LOG1("Creating final P4 program from P5");

    // 确保必需的类型定义存在（在创建组件之前）
    ensureRequiredTypes();

    // 生成 V1Switch main（可能会创建引用 headers/metadata 的空组件）
    createMain();

    if (::P4::errorCount() > 0) {
        return nullptr;
    }

    // 创建最终的 P4Program
    auto program = new IR::P4Program(info, *declarations);
    return program;
}

// ============================================================================
// ExtractComponents 实现
// ============================================================================

bool ExtractComponents::preorder(const IR::P4Parser *parser) {
    // 根据名称判断是哪个 parser
    if (parser->name == "ParserImpl_i" || parser->name == "parser_i") {
        structure->parser_i = parser;
        LOG2("ExtractComponents: Found ingress parser: " << parser->name);
    } else if (parser->name == "ParserImpl_e" || parser->name == "parser_e") {
        structure->parser_e = parser;
        LOG2("ExtractComponents: Found egress parser: " << parser->name);
    } else if (structure->parser_i == nullptr) {
        // 第一个未特别命名的 parser 作为 ingress parser
        structure->parser_i = parser;
        LOG2("ExtractComponents: Found default parser (assuming ingress): " << parser->name);
    }
    return false;  // 不需要继续遍历子节点
}

bool ExtractComponents::preorder(const IR::P4Control *control) {
    // 根据名称判断是哪个 control
    if (control->name == "verifyChecksum") {
        structure->verifyChecksum = control;
        LOG2("ExtractComponents: Found verifyChecksum control");
    } else if (control->name == "ingress") {
        structure->ingress = control;
        LOG2("ExtractComponents: Found ingress control");
    } else if (control->name == "egress") {
        structure->egress = control;
        LOG2("ExtractComponents: Found egress control");
    } else if (control->name == "computeChecksum") {
        structure->computeChecksum = control;
        LOG2("ExtractComponents: Found computeChecksum control");
    } else if (control->name == "DeparserImpl" || control->name == "deparser") {
        structure->deparser = control;
        LOG2("ExtractComponents: Found deparser control");
    }
    return false;  // 不需要继续遍历子节点
}

// ============================================================================
// InjectV1Model 实现
// ============================================================================

const IR::Node *InjectV1Model::preorder(IR::P4Program *program) {
    LOG1("InjectV1Model: Processing P4Program");

    // 停止遍历旧的 IR 树
    prune();

    // 1. 先包含 v1model.p4
    structure->loadModel();

    // 2. 从原始 P5 程序中提取组件并添加到 declarations
    structure->extractComponents(program);

    // 3. 生成最终的程序（包括 V1Switch main）
    auto result = structure->create(program->srcInfo);

    LOG1("InjectV1Model: Created new P4Program with " << result->objects.size()
                                                       << " declarations");

    return result;
}

// ============================================================================
// Converter 实现
// ============================================================================

Converter::Converter() {
    setStopOnError(true);
    setName("P5::Converter");

    structure = new P5ProgramStructure();

    // 只需要一个 Pass：注入 v1model 并生成最终程序
    // InjectV1Model 内部会调用 extractComponents，无需单独的提取 Pass
    passes.emplace_back(new InjectV1Model(structure));

    LOG1("P5::Converter initialized with " << passes.size() << " pass");
}

}  // namespace P4::P5

