This folder represents all of the C++ header-only files (.hpp) of the library that does not require compilation into a library to be used.

> **Rule:** This file tree must be updated upon any changes to the contents of this directory.

> **Rule:** Add any C++ header files (.hpp, .tpp, .inl) in this directory that is missing from File Tree to the Tree. Set their description to the @brief statement in their file.

> **Rule:** Do not include Formatter specialization (.tpp) and Output stream operator (.inl) files in the File Tree.

## File Tree

```
Softloq/WHATWG/Infra/
├── Primitive/
│   ├── Boolean/
│   │   └── Boolean.hpp         - This header defines the Boolean type for the WHATWG Infra library, representing a boolean value in the context of web APIs.
│   ├── Byte/
│   │   └── Byte.hpp            - This header defines the Byte type for the WHATWG Infra library, representing a byte value in the context of web APIs.
│   ├── Number/
│   │   ├── Number.hpp          - This header defines the Number type for the WHATWG Infra library, representing integer numeric values in the context of web APIs.
│   │   ├── UInt8/
│   │   │   └── UInt8.hpp       - This header defines the UInt8 type for the WHATWG Infra library, representing an 8-bit unsigned integer in the context of web APIs.
│   │   ├── UInt16/
│   │   │   └── UInt16.hpp      - This header defines the UInt16 type for the WHATWG Infra library, representing a 16-bit unsigned integer in the context of web APIs.
│   │   ├── UInt32/
│   │   │   └── UInt32.hpp      - This header defines the UInt32 type for the WHATWG Infra library, representing a 32-bit unsigned integer in the context of web APIs.
│   │   ├── UInt64/
│   │   │   └── UInt64.hpp      - This header defines the UInt64 type for the WHATWG Infra library, representing a 64-bit unsigned integer in the context of web APIs.
│   │   ├── Int8/
│   │   │   └── Int8.hpp        - This header defines the Int8 type for the WHATWG Infra library, representing an 8-bit signed integer in the context of web APIs.
│   │   ├── Int16/
│   │   │   └── Int16.hpp       - This header defines the Int16 type for the WHATWG Infra library, representing a 16-bit signed integer in the context of web APIs.
│   │   ├── Int32/
│   │   │   └── Int32.hpp       - This header defines the Int32 type for the WHATWG Infra library, representing a 32-bit signed integer in the context of web APIs.
│   │   └── Int64/
│   │       └── Int64.hpp       - This header defines the Int64 type for the WHATWG Infra library, representing a 64-bit signed integer in the context of web APIs.
│   ├── Null/
│   │   └── Null.hpp            - This header defines the Null type for the WHATWG Infra library, representing a null value in the context of web APIs.
│   ├── Numbers/
│   │   └── Numbers.hpp         - This header includes all number primitive type headers for convenience.
│   ├── Primitive.hpp           - This header defines the primitive abstract class for the WHATWG Infra library.
│   └── PrimitiveType.hpp       - This header defines the primitive types for the WHATWG Infra library.
└── Primitives/
    └── Primitives.hpp          - This header includes all primitive type headers for convenience.
```
