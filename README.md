[![Apple-Tests](https://github.com/Softloq/WHATWG-Infra/actions/workflows/Apple-Tests.yml/badge.svg)](https://github.com/Softloq/WHATWG-Infra/actions/workflows/Apple-Tests.yml)
[![Linux-Tests](https://github.com/Softloq/WHATWG-Infra/actions/workflows/Linux-Tests.yml/badge.svg)](https://github.com/Softloq/WHATWG-Infra/actions/workflows/Linux-Tests.yml)
[![Windows-Tests](https://github.com/Softloq/WHATWG-Infra/actions/workflows/Windows-Tests.yml/badge.svg)](https://github.com/Softloq/WHATWG-Infra/actions/workflows/Windows-Tests.yml)

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

#### Boolean

```cpp
#include <Softloq/WHATWG/Infra/Primitive/Boolean/Boolean.hpp>

Softloq::WHATWG::Infra::Boolean bool_value;        // false
Softloq::WHATWG::Infra::Boolean bool_true{true};   // true
```

Get and set the underlying value:

```cpp
bool raw = bool_value.get_value(); // false
bool_value.set_value(true);
bool raw2 = bool_value.get_value(); // true
```

Logical negation and equality:

```cpp
Softloq::WHATWG::Infra::Boolean negated = !bool_true; // false
bool equal = (bool_true == bool_value);               // true (both now true)
bool diff  = (bool_true != negated);                  // true
```

Explicit conversion to `bool`:

```cpp
if (static_cast<bool>(bool_true)) { /* ... */ }
```

Supports `std::format` and `operator<<`:

```cpp
std::string s = std::format("{}", bool_true); // "true"
std::cout << bool_true;                        // "true"
```

#### Byte

```cpp
#include <Softloq/WHATWG/Infra/Primitive/Byte/Byte.hpp>

Softloq::WHATWG::Infra::Byte byte_value;          // 0
Softloq::WHATWG::Infra::Byte byte_max{uint8_t{255}};
```

Get and set the underlying value:

```cpp
std::uint8_t raw = byte_value.get_value(); // 0
byte_value.set_value(std::uint8_t{128});
std::uint8_t raw2 = byte_value.get_value(); // 128
```

Equality and inequality:

```cpp
Softloq::WHATWG::Infra::Byte a{std::uint8_t{10}};
Softloq::WHATWG::Infra::Byte b{std::uint8_t{10}};
bool equal = (a == b); // true
bool diff  = (a != b); // false
```

Explicit conversion to `std::uint8_t`:

```cpp
std::uint8_t val = static_cast<std::uint8_t>(byte_max); // 255
```

Supports `std::format` and `operator<<` (always formats as `0x` followed by two uppercase hex digits):

```cpp
std::string s = std::format("{}", Softloq::WHATWG::Infra::Byte{65});  // "0x41"
std::cout << Softloq::WHATWG::Infra::Byte{255};                        // "0xFF"
std::cout << Softloq::WHATWG::Infra::Byte{0};                          // "0x00"
```

#### Byte Sequence

```cpp
#include <Softloq/WHATWG/Infra/Primitive/ByteSequence/ByteSequence.hpp>

Softloq::WHATWG::Infra::ByteSequence empty;                        // []
Softloq::WHATWG::Infra::ByteSequence seq{0x48u, 0x69u};           // [0x48 0x69]
```

Construct from an initializer list of raw byte values (`std::uint8_t`):

```cpp
Softloq::WHATWG::Infra::ByteSequence hello{0x48u, 0x65u, 0x6Cu, 0x6Cu, 0x6Fu};
```

Container interface — size, emptiness, element access, mutation:

```cpp
std::size_t n = seq.size();    // 2
bool empty    = seq.is_empty(); // false

Softloq::WHATWG::Infra::Byte first = seq[0];          // 0x48
Softloq::WHATWG::Infra::Byte& ref  = seq.at(1);       // 0x69 (throws std::out_of_range if invalid)

seq.push_back(Softloq::WHATWG::Infra::Byte{std::uint8_t{0x21}}); // append 0x21
seq.clear();                                                        // remove all bytes
```

Range-based iteration:

```cpp
for (const auto& b : seq)
    std::cout << b; // prints each byte as 0xXX
```

Equality and inequality:

```cpp
Softloq::WHATWG::Infra::ByteSequence a{0x01u, 0x02u};
Softloq::WHATWG::Infra::ByteSequence b{0x01u, 0x02u};
bool equal = (a == b); // true
bool diff  = (a != b); // false
```

WHATWG Infra operations:

```cpp
Softloq::WHATWG::Infra::ByteSequence s{0x48u, 0x65u, 0x6Cu, 0x6Cu, 0x6Fu}; // "Hello"
s.byte_lowercase(); // [0x68 0x65 0x6C 0x6C 0x6F]  — A–Z → a–z, others unchanged
s.byte_uppercase(); // [0x48 0x45 0x4C 0x4C 0x4F]  — a–z → A–Z, others unchanged

Softloq::WHATWG::Infra::ByteSequence prefix{0x48u, 0x65u};
bool starts = s.starts_with(prefix); // true — s begins with [0x48 0x65]
```

Supports `std::format` and `operator<<` (bytes formatted as `0x` followed by two uppercase hex digits, space-separated, wrapped in `[]`):

```cpp
Softloq::WHATWG::Infra::ByteSequence bs{0x01u, 0xABu, 0xFFu};
std::string s = std::format("{}", bs); // "[0x01 0xAB 0xFF]"
std::cout << bs;                        // "[0x01 0xAB 0xFF]"

std::cout << Softloq::WHATWG::Infra::ByteSequence{}; // "[]"
```

#### Code Point

```cpp
#include <Softloq/WHATWG/Infra/Primitive/CodePoint/CodePoint.hpp>

Softloq::WHATWG::Infra::CodePoint cp;                      // U+0000
Softloq::WHATWG::Infra::CodePoint cp_a{char32_t{0x0041}}; // U+0041 LATIN CAPITAL LETTER A
```

Get and set the underlying value:

```cpp
char32_t raw = cp.get_value(); // U+0000
cp.set_value(char32_t{0x0041});
char32_t raw2 = cp.get_value(); // U+0041
```

Equality and inequality:

```cpp
Softloq::WHATWG::Infra::CodePoint a{char32_t{0x0041}};
Softloq::WHATWG::Infra::CodePoint b{char32_t{0x0041}};
bool equal = (a == b); // true
bool diff  = (a != b); // false
```

Explicit conversion to `char32_t`:

```cpp
char32_t val = static_cast<char32_t>(cp_a); // 0x0041
```

Unicode attribute predicates:

```cpp
using CP = Softloq::WHATWG::Infra::CodePoint;

CP{char32_t{0xD800}}.is_surrogate();          // true  — U+D800..U+DFFF
CP{char32_t{0xD800}}.is_leading_surrogate();  // true  — U+D800..U+DBFF
CP{char32_t{0xDC00}}.is_trailing_surrogate(); // true  — U+DC00..U+DFFF
CP{char32_t{0x0041}}.is_scalar_value();       // true  — not a surrogate
CP{char32_t{0xFFFE}}.is_noncharacter();       // true  — U+FDD0..U+FDEF, U+xFFFE, U+xFFFF

CP{char32_t{0x0041}}.is_ascii();              // true  — U+0000..U+007F
CP{char32_t{0x0009}}.is_ascii_tab_or_newline(); // true — U+0009, U+000A, U+000D
CP{char32_t{0x0020}}.is_ascii_whitespace();   // true  — U+0009, U+000A, U+000C, U+000D, U+0020
CP{char32_t{0x0000}}.is_c0_control();         // true  — U+0000..U+001F
CP{char32_t{0x0020}}.is_c0_control_or_space(); // true — C0 control or U+0020
CP{char32_t{0x007F}}.is_control();            // true  — C0, U+007F, U+0080..U+009F

CP{char32_t{0x0035}}.is_ascii_digit();             // true — U+0030..U+0039
CP{char32_t{0x0046}}.is_ascii_upper_hex_digit();   // true — digit or U+0041..U+0046
CP{char32_t{0x0066}}.is_ascii_lower_hex_digit();   // true — digit or U+0061..U+0066
CP{char32_t{0x0061}}.is_ascii_hex_digit();         // true — upper or lower hex digit
CP{char32_t{0x0041}}.is_ascii_upper_alpha();       // true — U+0041..U+005A
CP{char32_t{0x0061}}.is_ascii_lower_alpha();       // true — U+0061..U+007A
CP{char32_t{0x0041}}.is_ascii_alpha();             // true — upper or lower alpha
CP{char32_t{0x0035}}.is_ascii_alphanumeric();      // true — digit or alpha
```

Supports `std::format` and `operator<<` ("U+" followed by four to six uppercase hex digits):

```cpp
std::string s = std::format("{}", Softloq::WHATWG::Infra::CodePoint{char32_t{0x0041}});   // "U+0041"
std::cout << Softloq::WHATWG::Infra::CodePoint{char32_t{0x0000}};                          // "U+0000"
std::cout << Softloq::WHATWG::Infra::CodePoint{char32_t{0x10FFFF}};                        // "U+10FFFF"
```

#### Number (Integer types)

Eight strongly-typed integer aliases are provided, each wrapping the corresponding `std::intN_t` / `std::uintN_t` type:

| Alias | Underlying type |
|-------|----------------|
| `Int8` | `std::int8_t` |
| `Int16` | `std::int16_t` |
| `Int32` | `std::int32_t` |
| `Int64` | `std::int64_t` |
| `UInt8` | `std::uint8_t` |
| `UInt16` | `std::uint16_t` |
| `UInt32` | `std::uint32_t` |
| `UInt64` | `std::uint64_t` |

```cpp
#include <Softloq/WHATWG/Infra/Primitive/Number/Number.hpp>

Softloq::WHATWG::Infra::Int32  i{-42};   // signed 32-bit
Softloq::WHATWG::Infra::UInt8  u{255};   // unsigned 8-bit
Softloq::WHATWG::Infra::UInt64 big{1'000'000'000'000ULL};
```

Get and set the underlying value:

```cpp
std::int32_t raw = i.get_value(); // -42
i.set_value(0);
```

Arithmetic, compound assignment, and increment/decrement:

```cpp
Softloq::WHATWG::Infra::Int32 a{10}, b{3};
Softloq::WHATWG::Infra::Int32 sum  = a + b;  // 13
Softloq::WHATWG::Infra::Int32 diff = a - b;  // 7
Softloq::WHATWG::Infra::Int32 prod = a * b;  // 30
Softloq::WHATWG::Infra::Int32 quot = a / b;  // 3
Softloq::WHATWG::Infra::Int32 rem  = a % b;  // 1

a += b;  // 13
++a;     // 14
a++;     // 14, then becomes 15
```

Ordering and equality comparisons:

```cpp
bool eq  = (a == b);  // false
bool lt  = (b < a);   // true
bool gte = (a >= b);  // true
```

Explicit conversion to the underlying type:

```cpp
std::int32_t val = static_cast<std::int32_t>(a);
```

Supports `std::format` and `operator<<` (byte-sized types always format as numbers, never as characters):

```cpp
std::string s = std::format("{}", Softloq::WHATWG::Infra::UInt8{65}); // "65", not "A"
std::cout << Softloq::WHATWG::Infra::Int32{-7};                        // "-7"
```

### Convenience Headers

Include all primitives at once:

```cpp
#include <Softloq/WHATWG/Infra/Primitives/Primitives.hpp>
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
