/**
 * @file inline/Softloq/WHATWG/Infra/Primitive/CodePoint/OStream.inl
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This file defines the output stream operator for the CodePoint primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file defines the output stream operator for the CodePoint primitive type, allowing it to be
 * printed to output streams. When the CodePoint primitive is printed, it will be represented as
 * "U+" followed by four to six uppercase hex digits (e.g., U+0041, U+10FFFF).
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEPOINT_OSTREAM_INL
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEPOINT_OSTREAM_INL

#include "Softloq/WHATWG/Infra/Primitive/CodePoint/CodePoint.hpp"
#include <format>
#include <ostream>

inline std::ostream& operator<<(std::ostream& os, const Softloq::WHATWG::Infra::CodePoint& value)
{
    return os << std::format("U+{:04X}", static_cast<unsigned>(value.get_value()));
}

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEPOINT_OSTREAM_INL
