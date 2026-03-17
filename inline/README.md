This folder represents all of the C++ header-only files (.hpp) of the library that does not require compilation into a library to be used.

> **Rule:** This file tree must be updated upon any changes to the contents of this directory.

> **Rule:** Add any C++ header files (.hpp, .tpp, .inl) in this directory that is missing from File Tree to the Tree. Set their description to the @brief statement in their file.

## File Tree

```
Softloq/WHATWG/Infra/
├── Primitive/
│   └── Null/
│       ├── Formatter.tpp       - Formatter specialization for the Null primitive type in the WHATWG Infra library.
│       ├── Null.hpp            - This header defines the Null type for the WHATWG Infra library, representing a null value in the context of web APIs.
│       └── OStream.inl         - This file defines the output stream operator for the Null primitive type in the WHATWG Infra library.
└── Primitives/
    ├── All.hpp                 - This header includes all primitive type headers for convenience.
    ├── Primitive.hpp           - This header defines the primitive abstract class for the WHATWG Infra library.
    └── Type.hpp                - This header defines the primitive types for the WHATWG Infra library.
```
