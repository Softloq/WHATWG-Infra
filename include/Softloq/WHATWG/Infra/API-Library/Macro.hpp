/**
 * @file Softloq/WHATWG/Infra/API-Library/Macro.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the API export/import macro for building static or shared libraries.
 * 
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the API export/import macro for building static or shared libraries.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_API_LIBRARY_MACRO_HPP
#define SOFTLOQ_WHATWG_INFRA_API_LIBRARY_MACRO_HPP

// Define API export/import macro for building static or shared libraries
#if defined(SOFTLOQ_WHATWG_INFRA_SHARED)
    // Shared library build
    #if defined(SOFTLOQ_WHATWG_INFRA_EXPORTS)
        // Building the shared library - export symbols
        #if defined(_WIN32) || defined(_WIN64)
            // Windows platform
            #define SOFTLOQ_WHATWG_INFRA_API __declspec(dllexport)
        #elif defined(__GNUC__) || defined(__clang__)
            // GCC or Clang
            #define SOFTLOQ_WHATWG_INFRA_API __attribute__((visibility("default")))
        #else
            // Other platforms
            #define SOFTLOQ_WHATWG_INFRA_API
        #endif
    #else
        // Using the shared library - import symbols
        #if defined(_WIN32) || defined(_WIN64)
            // Windows platform
            #define SOFTLOQ_WHATWG_INFRA_API __declspec(dllimport)
        #elif defined(__GNUC__) || defined(__clang__)
            // GCC or Clang
            #define SOFTLOQ_WHATWG_INFRA_API __attribute__((visibility("default")))
        #else
            // Other platforms
            #define SOFTLOQ_WHATWG_INFRA_API
        #endif
    #endif
#else
    // Static library (default) - no export/import needed
    #define SOFTLOQ_WHATWG_INFRA_API
#endif

#endif // SOFTLOQ_WHATWG_INFRA_API_LIBRARY_MACRO_HPP