# Test CMakeLists.txt
cmake_minimum_required(VERSION 3.20)

# Find or fetch a testing framework (using a simple approach without external dependencies for now)
# You can later integrate Google Test, Catch2, or other frameworks

# Collect all test source files
file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Create test executables
foreach(TEST_SOURCE ${TEST_SOURCES})
    # Get the filename without extension
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    
    # Create executable for this test
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    
    # Link against the library
    target_link_libraries(${TEST_NAME} PRIVATE ${LIBRARY_NAME})
    
    # Add as a test
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
    
    # Set C++23 standard for tests
    set_target_properties(${TEST_NAME} PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
    )
endforeach()
