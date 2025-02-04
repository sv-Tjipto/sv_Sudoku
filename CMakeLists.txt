# Specify the minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Sudoku)

# Test
include(CTest)
enable_testing()

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable and its source files
add_executable(Sudoku main.cpp sudoku.cpp)