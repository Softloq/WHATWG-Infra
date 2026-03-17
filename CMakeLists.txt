cmake_minimum_required(VERSION 3.10...3.16)

project(Softloq-WHATWG-Infra VERSION 0.1.0 LANGUAGES CXX)

# Set C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options for building tests and examples
option(SOFTLOQ_WHATWG_INFRA_BUILD_TESTS "Build WHATWG Infra unit tests" OFF)
option(SOFTLOQ_WHATWG_INFRA_BUILD_EXAMPLES "Build WHATWG Infra example programs" OFF)
option(SOFTLOQ_WHATWG_INFRA_BUILD_SHARED_LIBS "Build WHATWG Infra shared libraries instead of static" OFF)
option(SOFTLOQ_WHATWG_INFRA_HEADER_ONLY "Build WHATWG Infra as a header-only library" OFF)

# Define the library name
set(LIBRARY_NAME Softloq-WHATWG-Infra)

if(SOFTLOQ_WHATWG_INFRA_HEADER_ONLY)
    # Collect all header files (.hpp, .tpp, and .inl) from inline directory
    file(GLOB_RECURSE HEADER_FILES 
        "${CMAKE_CURRENT_SOURCE_DIR}/inline/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/inline/*.tpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/inline/*.inl"
    )

    add_library(${LIBRARY_NAME} INTERFACE)

    target_include_directories(${LIBRARY_NAME}
        INTERFACE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inline>
            $<INSTALL_INTERFACE:include>
    )

    # Installation rules
    install(TARGETS ${LIBRARY_NAME}
        EXPORT ${LIBRARY_NAME}Targets
        INCLUDES DESTINATION include
    )

    install(DIRECTORY inline/
        DESTINATION include
        FILES_MATCHING PATTERN "*.hpp" PATTERN "*.tpp" PATTERN "*.inl"
    )
else()
    # Collect all header files (.hpp, .tpp, and .inl) from include directory
    file(GLOB_RECURSE HEADER_FILES 
        "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/*.tpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/*.inl"
    )

    # Collect all source files (.cpp) from src directory
    file(GLOB_RECURSE SOURCE_FILES 
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    )

    if(SOFTLOQ_WHATWG_INFRA_BUILD_SHARED_LIBS)
        add_library(${LIBRARY_NAME} SHARED ${SOURCE_FILES})

        target_compile_definitions(${LIBRARY_NAME} 
            PRIVATE SOFTLOQ_WHATWG_INFRA_EXPORTS
            PUBLIC SOFTLOQ_WHATWG_INFRA_SHARED
        )

        set_target_properties(${LIBRARY_NAME} PROPERTIES
            CXX_VISIBILITY_PRESET hidden
            VISIBILITY_INLINES_HIDDEN ON
        )
    else()
        add_library(${LIBRARY_NAME} STATIC ${SOURCE_FILES})
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
        FILES_MATCHING PATTERN "*.hpp" PATTERN "*.tpp" PATTERN "*.inl"
    )

    # Export targets
    install(EXPORT ${LIBRARY_NAME}Targets
        FILE ${LIBRARY_NAME}Targets.cmake
        NAMESPACE ${LIBRARY_NAME}::
        DESTINATION lib/cmake/${LIBRARY_NAME}
    )
endif()

# Add subdirectories for tests and examples
if (SOFTLOQ_WHATWG_INFRA_BUILD_TESTS)
    add_subdirectory(tests)
endif()
if (SOFTLOQ_WHATWG_INFRA_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()