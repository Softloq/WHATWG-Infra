This folder represents all of the C++ implementation files (.cpp) of the library that can be built as a static/shared library with their corresponding header files from a separate directory.

> **Rule:** This file tree must be updated upon any changes to the contents of this directory.

> **Rule:** Add any C++ implementation files (.cpp) in this directory that is missing from File Tree to the Tree. Set their description to the @brief statement in their file.

> **Rule:** Do not include Formatter specialization (.tpp) and Output stream operator (.inl) files in the File Tree.

## File Tree

```
Softloq/WHATWG/Infra/
├── Primitive/
│   ├── Boolean/
│   │   └── Boolean.cpp         - This implements the Boolean type for the WHATWG Infra library, representing a boolean value in the context of web APIs.
│   ├── Byte/
│   │   └── Byte.cpp            - This implements the Byte type for the WHATWG Infra library, representing a byte value in the context of web APIs.
│   ├── ByteSequence/
│   │   └── ByteSequence.cpp    - This implements the ByteSequence type for the WHATWG Infra library, representing a byte sequence in the context of web APIs.
│   ├── CodePoint/
│   │   └── CodePoint.cpp       - This implements the CodePoint type for the WHATWG Infra library, representing a Unicode code point in the context of web APIs.
│   ├── CodeUnit/
│   │   └── CodeUnit.cpp        - This implements the CodeUnit type for the WHATWG Infra library, representing a UTF-16 code unit in the context of web APIs.
│   ├── Number/
│   │   ├── UInt8/
│   │   │   └── UInt8.cpp       - This file provides the explicit instantiation of Number<std::uint8_t> for the WHATWG Infra library.
│   │   ├── UInt16/
│   │   │   └── UInt16.cpp      - This file provides the explicit instantiation of Number<std::uint16_t> for the WHATWG Infra library.
│   │   ├── UInt32/
│   │   │   └── UInt32.cpp      - This file provides the explicit instantiation of Number<std::uint32_t> for the WHATWG Infra library.
│   │   ├── UInt64/
│   │   │   └── UInt64.cpp      - This file provides the explicit instantiation of Number<std::uint64_t> for the WHATWG Infra library.
│   │   ├── Int8/
│   │   │   └── Int8.cpp        - This file provides the explicit instantiation of Number<std::int8_t> for the WHATWG Infra library.
│   │   ├── Int16/
│   │   │   └── Int16.cpp       - This file provides the explicit instantiation of Number<std::int16_t> for the WHATWG Infra library.
│   │   ├── Int32/
│   │   │   └── Int32.cpp       - This file provides the explicit instantiation of Number<std::int32_t> for the WHATWG Infra library.
│   │   └── Int64/
│   │       └── Int64.cpp       - This file provides the explicit instantiation of Number<std::int64_t> for the WHATWG Infra library.
│   ├── Null/
│   │   └── Null.cpp            - This implements the Null type for the WHATWG Infra library, representing a null value in the context of web APIs.
│   └── Primitive.cpp           - This implements the primitive abstract class for the WHATWG Infra library.
```
