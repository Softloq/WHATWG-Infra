/**
 * @file Softloq/WHATWG/Infra/Primitive/Byte/Formatter.tpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Formatter specialization for the Byte primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains the formatter specialization for the Byte primitive type.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_FORMATTER_TPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_FORMATTER_TPP

#include "Softloq/WHATWG/Infra/Primitive/Byte/Byte.hpp"
#include <format>
#include <string>

/**
 * @brief Formatter specialization for the Byte primitive type.
 *
 * This formatter specialization allows the Byte primitive type to be formatted
 * as a string using std::format. When formatted, the Byte primitive will be
 * represented as a decimal integer in the range [0, 255].
 */
template <>
struct std::formatter<Softloq::WHATWG::Infra::Byte> : std::formatter<std::string>
{
    inline auto format(const Softloq::WHATWG::Infra::Byte& value, format_context& ctx) const
    {
        return formatter<std::string>::format(std::to_string(value.get_value()), ctx);
    }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_FORMATTER_TPP
