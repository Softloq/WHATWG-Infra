/**
 * @file inline/Softloq/WHATWG/Infra/Primitive/Byte/OStream.inl
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This file defines the output stream operator for the Byte primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file defines the output stream operator for the Byte primitive type, allowing it to be
 * printed to output streams. When the Byte primitive is printed, it will be represented as
 * a hexadecimal integer prefixed with "0x" and zero-padded to two uppercase hex digits
 * (e.g., 0x00, 0x0F, 0xFF).
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_OSTREAM_INL
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_OSTREAM_INL

#include "Softloq/WHATWG/Infra/Primitive/Byte/Byte.hpp"
#include <format>
#include <ostream>

inline std::ostream& operator<<(std::ostream& os, const Softloq::WHATWG::Infra::Byte& value)
{
    return os << std::format("0x{:02X}", static_cast<unsigned>(value.get_value()));
}

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_OSTREAM_INL
