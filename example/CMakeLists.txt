# Example CMakeLists.txt
cmake_minimum_required(VERSION 3.20)

# Collect all example source files
file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Create example executables
foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    # Get the filename without extension
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    
    # Create executable for this example
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    
    # Link against the library
    target_link_libraries(${EXAMPLE_NAME} PRIVATE ${LIBRARY_NAME})
    
    # Set C++23 standard for examples
    set_target_properties(${EXAMPLE_NAME} PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
    )
endforeach()
