CXX ?= g++
ROOT_DIR := $(abspath .)
SRC_DIR := $(ROOT_DIR)/src
INC_DIR := $(ROOT_DIR)/include
BIN_DIR := $(ROOT_DIR)/bin

# Use GNU C++17 mode so we can use C++ designated initializers in tests (".field = ...").
# Note: GCC does not support C99-style array designators ("[idx] = ...") in C++ mode here.
CXXFLAGS ?= -std=gnu++17 -Wall -Wextra
CXXFLAGS += -I$(INC_DIR)
LDFLAGS ?=

SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Expect TEST to be provided (absolute or relative to ROOT_DIR) for targets that
# actually build a specific test binary.
# If the user only runs exempt targets (e.g. clean/run_tests/help), don't require TEST.
EXEMPT_GOALS := clean run_tests tests help
REQUIRES_TEST_GOALS := $(filter-out $(EXEMPT_GOALS),$(MAKECMDGOALS))
# Default goal is "all" (requires TEST)
ifeq ($(strip $(MAKECMDGOALS)),)
REQUIRES_TEST_GOALS := all
endif
ifneq ($(strip $(REQUIRES_TEST_GOALS)),)
ifndef TEST
$(error Please invoke with TEST=<path/to/test.cpp>)
endif
endif

TEST_ABS := $(abspath $(TEST))
TEST_BASENAME := $(notdir $(basename $(TEST_ABS)))
TARGET := $(BIN_DIR)/$(TEST_BASENAME)

TEST_DIR := $(dir $(TEST_ABS))
#
# Generated output directory (contains include/ and src/).
# Default is ./generated, but you can override it:
#   - make OUT_DIR=out_dir TEST=test/test_xxx.cpp
# Also accepts lowercase out_dir for convenience.
#
OUT_DIR ?= $(out_dir)
ifeq ($(strip $(OUT_DIR)),)
OUT_DIR := $(ROOT_DIR)/generated
endif

TEST_GEN_DIR := $(abspath $(OUT_DIR))
TEST_GEN_INC_DIR := $(TEST_GEN_DIR)/include
TEST_GEN_SRC_DIR := $(TEST_GEN_DIR)/src

# Test source + generated sources under $(OUT_DIR)/src
TEST_GEN_SRCS := $(wildcard $(TEST_GEN_SRC_DIR)/*.cpp)
TEST_SRCS := $(TEST_ABS) $(TEST_GEN_SRCS)
ALL_SRCS := $(SRCS) $(TEST_SRCS)

.PHONY: all clean dirs run_tests tests help

all: dirs $(TARGET)

dirs:
	@mkdir -p $(BIN_DIR)

$(TARGET): $(ALL_SRCS) | dirs
	$(CXX) $(CXXFLAGS) -I$(TEST_DIR) -I$(TEST_GEN_INC_DIR) $(ALL_SRCS) -o $@ $(LDFLAGS)

clean:
	rm -rf $(BIN_DIR)/*

run_tests:
	@bash $(ROOT_DIR)/run_tests.sh

tests: run_tests

help:
	@echo "Targets:"
	@echo "  make TEST=test/test_xxx.cpp    Build a single test binary into ./bin/"
	@echo "  make OUT_DIR=out_dir TEST=...  Use generated code from OUT_DIR/{include,src}"
	@echo "  make run_tests (or tests)      Build and run all tests via run_tests.sh"
	@echo "  make clean                     Remove ./bin outputs"

