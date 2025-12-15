# Makefile for test_parser compilation
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra -O2
INCLUDES = -I. -Isources/common

# Directories
SRC_DIR = sources/common
OBJ_DIR = .

# Source files
TEST_SRC = test_parser.cpp
PARSER_SRC = $(SRC_DIR)/parser.cpp
PARSER_INTERFACE_SRC = $(SRC_DIR)/parser_interface.cpp

# Object files
TEST_OBJ = $(OBJ_DIR)/test_parser.o
PARSER_OBJ = $(OBJ_DIR)/parser.o
PARSER_INTERFACE_OBJ = $(OBJ_DIR)/parser_interface.o

# Executable
TARGET = test_parser

# All object files
OBJS = $(TEST_OBJ) $(PARSER_OBJ) $(PARSER_INTERFACE_OBJ)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)
	@echo "Build complete: $(TARGET)"

# Compile test_parser.cpp
$(TEST_OBJ): $(TEST_SRC) model_intf_1027.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(TEST_SRC) -o $(TEST_OBJ)

# Compile parser.cpp
$(PARSER_OBJ): $(PARSER_SRC) $(SRC_DIR)/parser.hpp $(SRC_DIR)/parser_base.hpp \
               $(SRC_DIR)/headers.hpp model_intf_1027.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(PARSER_SRC) -o $(PARSER_OBJ)

# Compile parser_interface.cpp
$(PARSER_INTERFACE_OBJ): $(PARSER_INTERFACE_SRC) $(SRC_DIR)/parser.hpp model_intf_1027.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(PARSER_INTERFACE_SRC) -o $(PARSER_INTERFACE_OBJ)

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Clean complete"

# Rebuild everything
rebuild: clean all

# Phony targets
.PHONY: all clean rebuild
