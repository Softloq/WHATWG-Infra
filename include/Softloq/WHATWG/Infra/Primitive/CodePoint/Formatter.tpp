/**
 * @file Softloq/WHATWG/Infra/Primitive/CodePoint/Formatter.tpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Formatter specialization for the CodePoint primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains the formatter specialization for the CodePoint primitive type.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEPOINT_FORMATTER_TPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEPOINT_FORMATTER_TPP

#include "Softloq/WHATWG/Infra/Primitive/CodePoint/CodePoint.hpp"
#include <format>
#include <string>

/**
 * @brief Formatter specialization for the CodePoint primitive type.
 *
 * This formatter specialization allows the CodePoint primitive type to be formatted
 * as a string using std::format. When formatted, the CodePoint will be represented
 * as "U+" followed by four to six uppercase hex digits (e.g., U+0041, U+10FFFF).
 */
template <>
struct std::formatter<Softloq::WHATWG::Infra::CodePoint> : std::formatter<std::string>
{
    inline auto format(const Softloq::WHATWG::Infra::CodePoint& value, format_context& ctx) const
    {
        return formatter<std::string>::format(
            std::format("U+{:04X}", static_cast<unsigned>(value.get_value())), ctx);
    }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEPOINT_FORMATTER_TPP
