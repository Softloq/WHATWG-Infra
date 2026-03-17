This folder represents all of the C++ implementation files (.cpp) of the library that can be built as a static/shared library with their corresponding header files from a separate directory.

> **Rule:** This file tree must be updated upon any changes to the contents of this directory.

> **Rule:** Add any C++ implementation files (.cpp) in this directory that is missing from File Tree to the Tree. Set their description to the @brief statement in their file.

## File Tree

```
Softloq/WHATWG/Infra/
├── Primitive/
│   └── Null/
│       └── Null.cpp            - This implements the Null type for the WHATWG Infra library, representing a null value in the context of web APIs.
└── Primitives/
    └── Primitive.cpp           - This implements the primitive abstract class for the WHATWG Infra library.
```
