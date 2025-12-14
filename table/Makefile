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

.PHONY: all clean dirs

all: dirs $(TARGET)

dirs:
	@mkdir -p $(BIN_DIR)

$(TARGET): $(SRCS) $(TEST_ABS) | dirs
	$(CXX) $(CXXFLAGS) $(SRCS) $(TEST_ABS) -o $@ $(LDFLAGS)

clean:
	rm -rf $(BIN_DIR)

