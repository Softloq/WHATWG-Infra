# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

A C++23 implementation of the [WHATWG Infra specification](https://infra.spec.whatwg.org/), providing strongly-typed primitive types. Library name: `Softloq-WHATWG-Infra`.

See [roadmap/README.md](roadmap/README.md) for the development roadmap.

When adding code, follow the contribution guidelines in [CONTRIBUTING.md](CONTRIBUTING.md).

**Rule:** When primitives or data structures are added to `include/`, update the Usage section of [README.md](README.md) to show direct usage of those types first (e.g. including and constructing individual primitive or data structure headers), then list convenience features such as `Primitives/Primitives.hpp` at the end.

## Build

Bash
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

Powershell
```powershell
mkdir build; cd build
cmake ..
cmake --build .
```

Build options (to be re-added to CMakeLists.txt as primitives are implemented):
- `SOFTLOQ_WHATWG_INFRA_BUILD_TESTS` – build unit tests (default OFF)
- `SOFTLOQ_WHATWG_INFRA_BUILD_EXAMPLES` – build examples (default OFF)
- `SOFTLOQ_WHATWG_INFRA_BUILD_SHARED_LIBS` – shared vs. static (default OFF)
- `SOFTLOQ_WHATWG_INFRA_HEADER_ONLY` – use the header-only version from `inline/` instead of building the library (default OFF)

## Architecture

### Directory Layout

```
include/Softloq/WHATWG/Infra/   – Headers (.hpp, .tpp, .inl) for the static/shared library
inline/Softloq/WHATWG/Infra/    – Header-only version of the library
src/Softloq/WHATWG/Infra/       – Implementations (.cpp) of the translation units
tests/                          – Unit tests
examples/                       – Example programs
docs/                           – HTML Documentation
```

### Key Headers

- [Softloq/WHATWG/Infra/API-Library/Macro.hpp](include/Softloq/WHATWG/Infra/API-Library/Macro.hpp) – This header defines the API export/import macro for building static or dynamic libraries.
- [Softloq/WHATWG/Infra/Primitives/Primitives.hpp](include/Softloq/WHATWG/Infra/Primitives/Primitives.hpp) – This header includes all primitive type headers for convenience.
