/**
 * @file Softloq/WHATWG/Infra/Primitive/Null/Formatter.tpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Formatter specialization for the Null primitive type in the WHATWG Infra library.
 * 
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains the formatter specialization for the Null primitive type.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_FORMATTER_TPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_FORMATTER_TPP

#include "Softloq/WHATWG/Infra/Primitive/Null/Null.hpp"
#include <format>

/**
 * @brief Formatter specialization for the Null primitive type.
 * 
 * This formatter specialization allows the Null primitive type to be formatted as a string using std::format.
 * When formatted, the Null primitive will be represented as the string "null".
 */
template <>
struct std::formatter<Softloq::WHATWG::Infra::Null>
{
    constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

    inline auto format(Softloq::WHATWG::Infra::Null, std::format_context& ctx) const
    {
        return std::format_to(ctx.out(), "null");
    }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_FORMATTER_TPP