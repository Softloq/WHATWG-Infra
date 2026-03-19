/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/UInt8/OStream.inl
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Output stream operator for the UInt8 primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file defines the output stream operator for the UInt8 primitive type, printing it as
 * its decimal integer representation rather than as a character.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT8_OSTREAM_INL
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT8_OSTREAM_INL

#include "Softloq/WHATWG/Infra/Primitive/Number/Number.hpp"
#include <ostream>

inline std::ostream& operator<<(std::ostream& os, const Softloq::WHATWG::Infra::Number<std::uint8_t>& value)
{
    return os << static_cast<unsigned int>(value.get_value());
}

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT8_OSTREAM_INL
