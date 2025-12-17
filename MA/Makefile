CXX ?= g++
ROOT_DIR := $(abspath .)
SRC_DIR := $(ROOT_DIR)/src
INC_DIR := $(ROOT_DIR)/include
BIN_DIR := $(ROOT_DIR)/bin

CXXFLAGS ?= -std=c++17 -Wall -Wextra
CXXFLAGS += -I$(INC_DIR)
LDFLAGS ?=

SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Expect TEST to be provided (absolute or relative to ROOT_DIR).
ifndef TEST
$(error Please invoke with TEST=<path/to/test.cpp>)
endif

TEST_ABS := $(abspath $(TEST))
TEST_BASENAME := $(notdir $(basename $(TEST_ABS)))
TARGET := $(BIN_DIR)/$(TEST_BASENAME)

TEST_DIR := $(dir $(TEST_ABS))
TEST_GEN_DIR := $(TEST_DIR)/generated
TEST_GEN_INC_DIR := $(TEST_GEN_DIR)/include
TEST_GEN_SRC_DIR := $(TEST_GEN_DIR)/src

# Test source (unity build includes generated src via the test file itself).
TEST_SRCS := $(TEST_ABS)
ALL_SRCS := $(SRCS) $(TEST_SRCS)

.PHONY: all clean dirs

all: dirs $(TARGET)

dirs:
	@mkdir -p $(BIN_DIR)

$(TARGET): $(ALL_SRCS) | dirs
	$(CXX) $(CXXFLAGS) -I$(TEST_DIR) -I$(TEST_GEN_INC_DIR) $(ALL_SRCS) -o $@ $(LDFLAGS)

clean:
	rm -rf $(BIN_DIR)

