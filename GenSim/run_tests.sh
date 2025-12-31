#!/bin/bash

# set -e: 遇到任何错误立即停止 (比如编译失败)
set -e

echo "Starting Automated Build and Test Sequence..."
echo "=============================================="

# 1. 先清理一次环境
echo "[Step 1] Cleaning workspace..."
make clean

# 2. 自动查找 test 目录下所有以 "test_" 开头并以 ".cpp" 结尾的文件
# 使用 sort 确保执行顺序是字母顺序
TEST_FILES=$(ls test/test_*.cpp | sort)

if [ -z "$TEST_FILES" ]; then
    echo "No test files found in test/ directory matching 'test_*.cpp'."
    exit 1
fi

# 3. 循环遍历找到的文件
for file in $TEST_FILES; do
    # 提取文件名用于运行二进制文件
    # 例如: test/test_ima.cpp -> test_ima
    bin_name=$(basename "$file" .cpp)
    
    echo "--------------------------------------------------"
    echo "Found Test:   $bin_name"
    echo "Source Path:  $file"
    echo "--------------------------------------------------"
    
    # 编译指定的测试
    # 对应您的指令: make TEST=test/xxx.cpp
    make TEST="$file"
    
    # 运行编译出的二进制文件
    # 对应您的指令: ./bin/xxx
    if [ -f "./bin/$bin_name" ]; then
        ./bin/"$bin_name"
    else
        echo "Error: Binary ./bin/$bin_name not found after compilation."
        exit 1
    fi
done

echo "=================================================="
echo "✅ All discovered tests passed successfully!"
echo "=================================================="