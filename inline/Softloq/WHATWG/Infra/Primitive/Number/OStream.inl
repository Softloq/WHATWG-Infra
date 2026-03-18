/**
 * @file include/Softloq/WHATWG/Infra/Primitive/Number/OStream.inl
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This file defines the output stream operator for the Number primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file defines the output stream operator for the Number primitive type, allowing it to be
 * printed to output streams as its decimal integer representation. To avoid treating
 * uint8_t/int8_t as characters, the value is promoted to the widest integer type before output.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_OSTREAM_INL
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_OSTREAM_INL

#include "Softloq/WHATWG/Infra/Primitive/Number/Number.hpp"
#include <concepts>
#include <ostream>

template <std::integral T>
inline std::ostream& operator<<(std::ostream& os, const Softloq::WHATWG::Infra::Number<T>& value)
{
    if constexpr (std::is_signed_v<T>)
        return os << static_cast<long long>(value.get_value());
    else
        return os << static_cast<unsigned long long>(value.get_value());
}

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_OSTREAM_INL
