cmake_minimum_required(VERSION 3.20)
project(p5compiler LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Build Abseil from vendored source (copied from p4c build/_deps).
add_subdirectory(third_party/abseil-src)

file(GLOB P5C_LIB_SRCS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/p5c_src/lib/*.cpp")
file(GLOB P5C_IR_SRCS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/p5c_src/ir/*.cpp")

# Drop IR utilities that pull in large frontend dependencies not needed for
# parsing + P5-to-C codegen.
list(FILTER P5C_IR_SRCS EXCLUDE REGEX ".*/splitter\\.cpp$")
list(FILTER P5C_IR_SRCS EXCLUDE REGEX ".*/json_parser\\.cpp$")

add_executable(p5c
  p5c_src/p5c_main.cpp

  # P5 parser / lexer (generated outputs copied from p4c build).
  p5c_src/frontends/parsers/parserDriver.cpp
  p5c_src/frontends/parsers/p5/p5lexer.cc
  p5c_src/frontends/parsers/p5/p5parser.cpp

  # Minimal frontend helpers used by lexer/parser actions.
  p5c_src/frontends/common/p5c_context_stub.cpp
  p5c_src/frontends/common/constantFolding.cpp
  p5c_src/frontends/common/constantParsing.cpp
  p5c_src/frontends/common/resolveReferences/resolveReferences.cpp
  p5c_src/frontends/common/resolveReferences/referenceMap.cpp
  p5c_src/frontends/p4/symbol_table.cpp
  p5c_src/frontends/p4/typeMap.cpp
  p5c_src/frontends/p4/enumInstance.cpp
  p5c_src/frontends/p4/typeChecking/typeSubstitution.cpp
  p5c_src/frontends/p4/typeChecking/typeSubstitutionVisitor.cpp
  p5c_src/frontends/p4/reservedWords.cpp
  # Provides implementations for some IR helpers declared from P4-14 IR defs
  # (e.g., IR::Type_Counter::get(), IR::NamedCond::unique_name(), IR::Primitive).
  p5c_src/frontends/p4-14/v1.cpp

  # P5 -> C++ codegen pass.
  p5c_src/frontends/p5/passes/p5_to_c.cpp

  # DPDK backend provides implementations for some virtual methods on DPDK IR nodes
  # which are referenced by the pre-generated ir-generated.cpp.
  p5c_src/backends/dpdk/dbprint-dpdk.cpp
  p5c_src/backends/dpdk/spec_stubs.cpp

  ${P5C_IR_SRCS}
  ${P5C_LIB_SRCS}
)

target_include_directories(p5c PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/p5c_src
  ${CMAKE_CURRENT_SOURCE_DIR}/p5c_src/include
  # Vendored Flex header for the pre-generated C++ lexer.
  ${CMAKE_CURRENT_SOURCE_DIR}/third_party/flex
)

target_compile_definitions(p5c PRIVATE
  # Ensure vendored config.h is found first.
  )

target_link_libraries(p5c PRIVATE
  # Abseil building blocks used widely by vendored p4c code.
  absl::strings
  absl::str_format
  absl::base
  absl::debugging
  absl::time
  absl::hash
  absl::raw_hash_set
  absl::flat_hash_map
  absl::flat_hash_set
  absl::stacktrace
  absl::symbolize
  absl::examine_stack
)

if(UNIX)
  target_link_libraries(p5c PRIVATE pthread dl)
endif()


