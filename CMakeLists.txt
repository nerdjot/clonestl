cmake_minimum_required(VERSION 3.15)
project(STLClone LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

# Gather all test files (including main.cpp)
file(GLOB TEST_SOURCES test/*.cpp)

# One test binary
add_executable(test_all ${TEST_SOURCES})
