# Softloq-WHATWG-Infra

A C++23 implementation of the [WHATWG Infra specification](https://infra.spec.whatwg.org/), providing strongly-typed primitive types.

**Author:** [Softloq CEO - Brandon Foster (Paradox Gene)](https://github.com/BrandonFoster)
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

### Build Options

| Option | Default | Description |
|---|---|---|
| `SOFTLOQ_WHATWG_INFRA_BUILD_TESTS` | `OFF` | Build unit tests |
| `SOFTLOQ_WHATWG_INFRA_BUILD_EXAMPLES` | `OFF` | Build example programs |
| `SOFTLOQ_WHATWG_INFRA_BUILD_SHARED_LIBS` | `OFF` | Build as shared library instead of static |
| `SOFTLOQ_WHATWG_INFRA_HEADER_ONLY` | `OFF` | Use the header-only version from `inline/` instead of building the library |

See [examples/README.md](examples/README.md) for instructions on building examples.

---

## Testing

See [tests/README.md](tests/README.md) for instructions on running tests.

---

## Usage

### Primitives

#### Null

```cpp
#include <Softloq/WHATWG/Infra/Primitive/Null/Null.hpp>

Softloq::WHATWG::Infra::Null null_value;
```

Supports `std::format` and `operator<<`:

```cpp
std::string s = std::format("{}", null_value); // "null"
std::cout << null_value;                        // "null"
```

### Convenience Headers

Include all primitives at once:

```cpp
#include <Softloq/WHATWG/Infra/Primitives/All.hpp>
```

---

## Project Layout

```
include/Softloq/WHATWG/Infra/   – Headers (.hpp, .tpp, .inl) for the static/shared library
inline/Softloq/WHATWG/Infra/    – Header-only version of the library
src/Softloq/WHATWG/Infra/       – Implementations (.cpp) of the translation units
tests/                          – Unit tests
examples/                       – Example programs
docs/                           – HTML Documentation
roadmap/                        – Development roadmap
```

---

## Roadmap

See [roadmap/README.md](roadmap/README.md) for the development roadmap.

---

## Documentation

See [docs/README.md](docs/README.md) for instructions on generating documentation.

---

## License

Copyright (c) 2025–2026 Softloq. Released under the [MIT License](LICENSE).
