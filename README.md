# Softloq-WHATWG-Infra

A C++23 implementation of the [WHATWG Infra specification](https://infra.spec.whatwg.org/), providing strongly-typed primitive types.

**Author:** Brandon Foster (Paradox Gene), Softloq
**License:** [MIT](LICENSE)

---

## Overview

The WHATWG Infra specification defines the foundational primitives used across all WHATWG standards — data types such as bytes, byte sequences, strings, code points, lists, maps, and more. This library implements those primitives in modern C++23 with a focus on type safety and spec conformance.

---

## Requirements

- C++23-capable compiler (GCC 13+, Clang 17+, or MSVC 19.38+)
- CMake 3.10 or higher

---

## Building

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### Build Options

| Option | Default | Description |
|---|---|---|
| `SOFTLOQ_WHATWG_INFRA_BUILD_TESTS` | `ON` | Build unit tests |
| `SOFTLOQ_WHATWG_INFRA_BUILD_EXAMPLES` | `ON` | Build example programs |
| `SOFTLOQ_WHATWG_INFRA_BUILD_SHARED_LIBS` | `OFF` | Build as shared library instead of static |

Example — build as a shared library without tests:

```bash
cmake .. -DSOFTLOQ_WHATWG_INFRA_BUILD_SHARED_LIBS=ON -DSOFTLOQ_WHATWG_INFRA_BUILD_TESTS=OFF
cmake --build .
```

---

## Testing

Tests are built alongside the library when `SOFTLOQ_WHATWG_INFRA_BUILD_TESTS=ON` (the default). After building, run:

```bash
cd build
ctest --output-on-failure
```

Test source files live in [tests/](tests/).

---

## Usage

Include the convenience header to pull in all primitives:

```cpp
#include <Softloq/WHATWG/Infra/Primitives/All.hpp>
```

Or include individual primitive headers as needed.

---

## Project Layout

```
include/Softloq/WHATWG/Infra/   – Public headers (installed with the library)
inline/Softloq/WHATWG/Infra/    – Inline and template implementations
src/Softloq/WHATWG/Infra/       – .cpp translation units
tests/                          – Unit tests
examples/                       – Example programs
docs/                           – Documentation
```

---

## Documentation

Documentation lives in [docs/](docs/). To generate it locally (requires [Doxygen](https://www.doxygen.nl/)):

```bash
doxygen Doxyfile
```

The generated output will be in `docs/html/`. Open `docs/html/index.html` in a browser.

For the upstream specification this library implements, see the [WHATWG Infra standard](https://infra.spec.whatwg.org/).

---

## License

Copyright (c) 2025–2026 Softloq. Released under the [MIT License](LICENSE).
