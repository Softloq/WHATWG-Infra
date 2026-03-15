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

See [examples/README.md](examples/README.md) for instructions on building examples.

---

## Testing

See [tests/README.md](tests/README.md) for instructions on running tests.

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

See [docs/README.md](docs/README.md) for instructions on generating documentation.

---

## License

Copyright (c) 2025–2026 Softloq. Released under the [MIT License](LICENSE).
