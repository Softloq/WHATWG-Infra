/**
 * @file include/Softloq/WHATWG/Infra/Primitive/CodeUnit/OStream.inl
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This file defines the output stream operator for the CodeUnit primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file defines the output stream operator for the CodeUnit primitive type, allowing it to be
 * printed to output streams. When the CodeUnit primitive is printed, it will be represented as
 * "0x" followed by four uppercase hex digits (e.g., 0x0000, 0x00FF, 0xD800, 0xFFFF).
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEUNIT_OSTREAM_INL
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEUNIT_OSTREAM_INL

#include "Softloq/WHATWG/Infra/Primitive/CodeUnit/CodeUnit.hpp"
#include <format>
#include <ostream>

inline std::ostream& operator<<(std::ostream& os, const Softloq::WHATWG::Infra::CodeUnit& value)
{
    return os << std::format("{}", value);
}

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEUNIT_OSTREAM_INL
