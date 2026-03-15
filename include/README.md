This folder represents all of the C++ header files (.hpp, .tpp, .inl) of the library that can be built as a static/shared library with their corresponding implementation files from a separate directory.

>    **Rule:** This file tree must be updated upon any changes to the contents of this directory.
>    **Rule:** Add any C++ header files (.hpp, .tpp, .inl) in this directory that is missing from File Tree to the Tree. Set their description to the @brief statement in their file.

## File Tree

```
Softloq/WHATWG/Infra/
├── API-Library/
│   └── Macro.hpp               - This header defines the API export/import macro for building static or shared libraries.
├── Primitive/
│   └── Null/
│       └── Null.hpp            - This header defines the Null type for the WHATWG Infra library, representing a null value in the context of web APIs.
└── Primitives/
    ├── All.hpp                 - This header includes all primitive type headers for convenience.
    ├── Primitive.hpp           - This header defines the primitive abstract class for the WHATWG Infra library.
    └── Type.hpp                - This header defines the primitive types for the WHATWG Infra library.
```
