# Makefile for builtin tests
CXX = g++-10
CXXFLAGS = -std=c++17 -I ../../include -I ../../generated/include

# Test executables
TESTS = test_sizeof

all: $(TESTS)

test_sizeof: test_sizeof.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(TESTS)

run_%: %
	./$<

.PHONY: all clean run_%