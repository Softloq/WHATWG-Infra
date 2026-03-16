cmake_minimum_required(VERSION 3.10...3.16)

project(Softloq-WHATWG-Infra-Tests LANGUAGES CXX)

# Set C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add GoogleTest
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing() # Enables CTest to run tests

# Collect all source files (.cpp) from test directory
file(GLOB_RECURSE SOURCE_FILES 
    "${CMAKE_CURRENT_LIST_DIR}/Test-Units/*.cpp"
)

add_executable(unit_tests ${SOURCE_FILES}) # Define the test executable

# Link to gtest_main, which provides the main() function for the tests
target_link_libraries(unit_tests PRIVATE gtest_main Softloq-WHATWG-Infra) 

# Automatically discover tests in the executable and register them with CTest
include(GoogleTest)
gtest_discover_tests(unit_tests)