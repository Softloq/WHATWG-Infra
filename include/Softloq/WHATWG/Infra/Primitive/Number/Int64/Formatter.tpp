/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/Int64/Formatter.tpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Formatter specialization for the Int64 primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains the formatter specialization for the Int64 primitive type.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT64_FORMATTER_TPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT64_FORMATTER_TPP

#include "Softloq/WHATWG/Infra/Primitive/Number/Int64/Int64.hpp"
#include <format>

/**
 * @brief Formatter specialization for Int64 (Number<std::int64_t>).
 */
template <>
struct std::formatter<Softloq::WHATWG::Infra::Number<std::int64_t>>
{
    constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

    auto format(const Softloq::WHATWG::Infra::Number<std::int64_t>& value, std::format_context& ctx) const
    {
        return std::format_to(ctx.out(), "{}", value.get_value());
    }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT64_FORMATTER_TPP
