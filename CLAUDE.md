# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

A C++23 implementation of the [WHATWG Infra specification](https://infra.spec.whatwg.org/), providing strongly-typed primitive types. Library name: `Softloq-WHATWG-Infra`.

## Build

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

Build options (to be re-added to CMakeLists.txt as primitives are implemented):
- `SOFTLOQ_WHATWG_INFRA_BUILD_TESTS` – build unit tests (default ON)
- `SOFTLOQ_WHATWG_INFRA_BUILD_EXAMPLES` – build examples (default ON)
- `SOFTLOQ_WHATWG_INFRA_BUILD_SHARED_LIBS` – shared vs. static (default OFF)

## Architecture

### Directory Layout

```
include/Softloq/WHATWG/Infra/   – Public headers (installed with library)
inline/Softloq/WHATWG/Infra/    – Inline/template implementations (#included by headers)
src/Softloq/WHATWG/Infra/       – .cpp translation units
tests/                          – Test programs
examples/                       – Example programs
docs/                           – Documentation (empty)
```

### Key Headers

- [Softloq/WHATWG/Infra/API-Library/Macro.hpp](include/Softloq/WHATWG/Infra/API-Library/Macro.hpp) – This header defines the API export/import macro for building static or dynamic libraries.
- [Softloq/WHATWG/Infra/Primitives/All.hpp](include/Softloq/WHATWG/Infra/Primitives/All.hpp) – This header includes all primitive type headers for convenience.
