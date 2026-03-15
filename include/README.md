This folder represents all of the C++ header files (.hpp, .tpp, .inl) of the library that can be built as a static/shared library with their corresponding implementation files from a separate directory.

> **Rule:** This file tree must be updated upon any changes to the contents of this directory.

## File Tree

```
Softloq/WHATWG/Infra/
├── API-Library/
│   └── Macro.hpp               - This header defines the API export/import macro for building static or shared libraries.
├── Primitive/
└── Primitives/
    └── All.hpp                 - This header includes all primitive type headers for convenience.
```
