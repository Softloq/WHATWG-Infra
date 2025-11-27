cmake_minimum_required(VERSION 3.20)

project(WHATWGInfra VERSION 1.0.0 LANGUAGES CXX)

# Set C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options for building tests and examples
option(BUILD_TESTS "Build unit tests" ON)
option(BUILD_EXAMPLES "Build example programs" ON)
option(BUILD_SHARED_LIBS "Build shared libraries instead of static" OFF)

# Define the library name
set(LIBRARY_NAME whatwg_infra)

# Collect all header files (.hpp and .tpp) from include directory
file(GLOB_RECURSE HEADER_FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.tpp"
)

# Collect all source files (.cpp) from src directory
file(GLOB_RECURSE SOURCE_FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Create the library (type determined by BUILD_SHARED_LIBS)
add_library(${LIBRARY_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# Set compile definitions based on library type
if(BUILD_SHARED_LIBS)
    # Building a shared/dynamic library
    target_compile_definitions(${LIBRARY_NAME} 
        PRIVATE WHATWG_INFRA_EXPORTS
        PUBLIC WHATWG_INFRA_DYNAMIC
    )
endif()

# Specify include directories
target_include_directories(${LIBRARY_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Set compiler warnings
if(MSVC)
    target_compile_options(${LIBRARY_NAME} PRIVATE /W4)
else()
    target_compile_options(${LIBRARY_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Set visibility for shared libraries
if(BUILD_SHARED_LIBS)
    set_target_properties(${LIBRARY_NAME} PROPERTIES
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN ON
    )
endif()

# Installation rules
install(TARGETS ${LIBRARY_NAME}
    EXPORT ${LIBRARY_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.hpp" PATTERN "*.tpp"
)

# Export targets
install(EXPORT ${LIBRARY_NAME}Targets
    FILE ${LIBRARY_NAME}Targets.cmake
    NAMESPACE ${LIBRARY_NAME}::
    DESTINATION lib/cmake/${LIBRARY_NAME}
)

# Enable testing
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

# Build examples
if(BUILD_EXAMPLES)
    add_subdirectory(example)
endif()
