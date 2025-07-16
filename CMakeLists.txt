cmake_minimum_required(VERSION 3.15)
project(STLClone LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include headers from src/
include_directories(src)

# Enable testing
enable_testing()

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Gather all test sources
file(GLOB TEST_SOURCES test/*.cpp)

# One test binary
add_executable(clonestl_test ${TEST_SOURCES})

# Link with GoogleTest
target_link_libraries(clonestl_test gtest_main)

# Register with CTest
add_test(NAME clonestl_test COMMAND clonestl_test)
