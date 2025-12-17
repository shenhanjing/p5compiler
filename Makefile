# Unified Makefile for P5toC Runtime Library
# Supports building Parser tests, Table tests, and all components

CXX ?= g++
ROOT_DIR := $(abspath .)
SRC_DIR := $(ROOT_DIR)/src
INC_DIR := $(ROOT_DIR)/include
BUILD_DIR := $(ROOT_DIR)/build
OBJ_DIR := $(BUILD_DIR)/obj
TEST_DIR := $(ROOT_DIR)/test

# Compiler flags
CXXFLAGS ?= -std=c++17 -Wall -Wextra
CXXFLAGS += -I$(INC_DIR)/common -I$(INC_DIR)/generated -I$(INC_DIR)
LDFLAGS ?=

# Runtime library source files (from MA project)
RUNTIME_SRCS := $(SRC_DIR)/common/key.cpp $(SRC_DIR)/common/SE.cpp $(SRC_DIR)/common/table.cpp

# Parser source files (parser.cpp is in generated, not common)
PARSER_SRCS := $(SRC_DIR)/generated/parser.cpp $(SRC_DIR)/common/parser_interface.cpp

# All library sources
LIB_SRCS := $(RUNTIME_SRCS) $(PARSER_SRCS)

.PHONY: all parser table clean dirs help

help:
	@echo "P5toC Build System"
	@echo "=================="
	@echo "Available targets:"
	@echo "  all     - Build all components (Parser and Table tests)"
	@echo "  parser  - Build Parser test only"
	@echo "  table   - Build Table test only"
	@echo "  clean   - Remove all build artifacts"
	@echo ""
	@echo "Examples:"
	@echo "  make parser"
	@echo "  make table"
	@echo "  make all"

# Default target: build all
all: dirs parser table

dirs:
	@mkdir -p $(BUILD_DIR) $(OBJ_DIR)/common $(OBJ_DIR)/generated $(OBJ_DIR)/test

# ========== Parser Test Build ==========
PARSER_TEST_SRC := $(TEST_DIR)/test_parser.cpp
PARSER_TEST_TARGET := $(BUILD_DIR)/test_parser
PARSER_TEST_OBJ := $(OBJ_DIR)/test/test_parser.o

# Object files for parser test (parser.o is in generated directory)
PARSER_OBJS := $(OBJ_DIR)/generated/parser.o $(OBJ_DIR)/common/parser_interface.o
RUNTIME_OBJS := $(OBJ_DIR)/common/key.o $(OBJ_DIR)/common/SE.o $(OBJ_DIR)/common/table.o
PARSER_TEST_OBJS := $(PARSER_OBJS) $(RUNTIME_OBJS) $(PARSER_TEST_OBJ)

parser: dirs $(PARSER_TEST_TARGET)

$(PARSER_TEST_TARGET): $(PARSER_TEST_OBJS)
	@echo "Linking Parser test..."
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "Parser test built: $@"

# Compile parser source files (parser.cpp is in generated directory)
$(OBJ_DIR)/generated/parser.o: $(SRC_DIR)/generated/parser.cpp $(INC_DIR)/generated/parser.hpp $(INC_DIR)/common/parser_base.hpp \
                     $(INC_DIR)/common/headers.hpp $(INC_DIR)/common/serializer.hpp $(INC_DIR)/common/fv_structs.hpp
	@echo "Compiling parser.cpp..."
	@mkdir -p $(OBJ_DIR)/generated
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/common/parser_interface.o: $(SRC_DIR)/common/parser_interface.cpp $(INC_DIR)/generated/parser.hpp
	@echo "Compiling parser_interface.cpp..."
	@mkdir -p $(OBJ_DIR)/common
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/test/test_parser.o: $(PARSER_TEST_SRC) $(INC_DIR)/common/model_intf_1027.h
	@echo "Compiling test_parser.cpp..."
	@mkdir -p $(OBJ_DIR)/test
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile runtime library source files (shared)
$(OBJ_DIR)/common/key.o: $(SRC_DIR)/common/key.cpp $(INC_DIR)/common/key.hpp $(INC_DIR)/common/p5_types.hpp
	@echo "Compiling key.cpp..."
	@mkdir -p $(OBJ_DIR)/common
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/common/SE.o: $(SRC_DIR)/common/SE.cpp $(INC_DIR)/common/SE.hpp $(INC_DIR)/common/p5_types.hpp
	@echo "Compiling SE.cpp..."
	@mkdir -p $(OBJ_DIR)/common
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/common/table.o: $(SRC_DIR)/common/table.cpp $(INC_DIR)/common/table.hpp
	@echo "Compiling table.cpp..."
	@mkdir -p $(OBJ_DIR)/common
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ========== Table Test Build ==========
# Table test uses generated code and unity build pattern (includes generated_MA.cpp directly)
TABLE_TEST_SRC := $(TEST_DIR)/test_ma.cpp
TABLE_TEST_TARGET := $(BUILD_DIR)/test_ma
TABLE_TEST_OBJ := $(OBJ_DIR)/test/test_ma.o

# Table test object files (unity build, so no separate generated object needed)
TABLE_TEST_OBJS := $(PARSER_OBJS) $(RUNTIME_OBJS) $(TABLE_TEST_OBJ)

table: dirs $(TABLE_TEST_TARGET)

$(TABLE_TEST_TARGET): $(TABLE_TEST_OBJS)
	@echo "Linking Table test..."
	$(CXX) $(CXXFLAGS) -I$(TEST_DIR) -I$(SRC_DIR)/generated $^ -o $@ $(LDFLAGS)
	@echo "Table test built: $@"

# Compile table test (unity build includes generated_MA.cpp directly)
# Note: test_ma.cpp includes "src/generated/generated_MA.cpp" via Unity Build
$(OBJ_DIR)/test/test_ma.o: $(TABLE_TEST_SRC) $(INC_DIR)/generated/generated_MA.hpp
	@echo "Compiling test_ma.cpp (Unity Build)..."
	@mkdir -p $(OBJ_DIR)/test
	$(CXX) $(CXXFLAGS) -I$(TEST_DIR) -I$(ROOT_DIR) -c $< -o $@

# ========== Clean ==========
clean:
	@echo "Cleaning build artifacts..."
	rm -rf $(BUILD_DIR)
	@echo "Clean complete"
