/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/Int8/Formatter.tpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Formatter specialization for the Int8 primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains the formatter specialization for the Int8 primitive type.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT8_FORMATTER_TPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT8_FORMATTER_TPP

#include "Softloq/WHATWG/Infra/Primitive/Number/Number.hpp"
#include <format>

/**
 * @brief Formatter specialization for Int8 (Number<std::int8_t>).
 *
 * Casts to int before formatting to avoid treating the value as a character.
 */
template <>
struct std::formatter<Softloq::WHATWG::Infra::Number<std::int8_t>>
{
    constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

    auto format(const Softloq::WHATWG::Infra::Number<std::int8_t>& value, std::format_context& ctx) const
    {
        return std::format_to(ctx.out(), "{}", static_cast<int>(value.get_value()));
    }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT8_FORMATTER_TPP
