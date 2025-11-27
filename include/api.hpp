#ifndef WHATWG_INFRA_API_HPP
#define WHATWG_INFRA_API_HPP

// API export/import macro for building static or dynamic libraries
#if defined(WHATWG_INFRA_DYNAMIC)
// Dynamic library build
#if defined(WHATWG_INFRA_EXPORTS)
// Building the dynamic library - export symbols
#if defined(_WIN32) || defined(_WIN64)
#define WHATWG_INFRA_API __declspec(dllexport)
#elif defined(__GNUC__) || defined(__clang__)
#define WHATWG_INFRA_API __attribute__((visibility("default")))
#else
#define WHATWG_INFRA_API
#endif
#else
// Using the dynamic library - import symbols
#if defined(_WIN32) || defined(_WIN64)
#define WHATWG_INFRA_API __declspec(dllimport)
#elif defined(__GNUC__) || defined(__clang__)
#define WHATWG_INFRA_API __attribute__((visibility("default")))
#else
#define WHATWG_INFRA_API
#endif
#endif
#else
// Static library (default) - no export/import needed
#define WHATWG_INFRA_API
#endif

#endif // WHATWG_INFRA_API_HPP
