/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/UInt16/Formatter.tpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Formatter specialization for the UInt16 primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains the formatter specialization for the UInt16 primitive type.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT16_FORMATTER_TPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT16_FORMATTER_TPP

#include "Softloq/WHATWG/Infra/Primitive/Number/UInt16/UInt16.hpp"
#include <format>

/**
 * @brief Formatter specialization for UInt16 (Number<std::uint16_t>).
 */
template <>
struct std::formatter<Softloq::WHATWG::Infra::Number<std::uint16_t>>
{
    constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

    auto format(const Softloq::WHATWG::Infra::Number<std::uint16_t>& value, std::format_context& ctx) const
    {
        return std::format_to(ctx.out(), "{}", value.get_value());
    }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT16_FORMATTER_TPP
