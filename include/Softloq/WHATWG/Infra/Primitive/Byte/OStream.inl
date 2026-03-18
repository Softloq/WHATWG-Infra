/**
 * @file include/Softloq/WHATWG/Infra/Primitive/Byte/OStream.inl
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This file defines the output stream operator for the Byte primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file defines the output stream operator for the Byte primitive type, allowing it to be
 * printed to output streams. When the Byte primitive is printed, it will be represented as
 * a decimal integer in the range [0, 255].
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_OSTREAM_INL
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_OSTREAM_INL

#include "Softloq/WHATWG/Infra/Primitive/Byte/Byte.hpp"
#include <ostream>

inline std::ostream& operator<<(std::ostream& os, const Softloq::WHATWG::Infra::Byte& value)
{
    return os << static_cast<unsigned>(value.get_value());
}

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_OSTREAM_INL
