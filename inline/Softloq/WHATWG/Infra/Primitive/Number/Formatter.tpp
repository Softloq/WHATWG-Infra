/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/Formatter.tpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Formatter specialization for the Number primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains the formatter specialization for the Number primitive type.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_FORMATTER_TPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_FORMATTER_TPP

#include "Softloq/WHATWG/Infra/Primitive/Number/Number.hpp"
#include <concepts>
#include <format>

/**
 * @brief Formatter specialization for the Number primitive type.
 *
 * This formatter specialization allows any Number<T> to be formatted as a string
 * using std::format. The value is rendered as its decimal integer representation.
 * To avoid treating uint8_t/int8_t as characters, the stored value is promoted to
 * the widest signed or unsigned integer before formatting.
 *
 * @tparam T An integral type.
 */
template <std::integral T>
struct std::formatter<Softloq::WHATWG::Infra::Number<T>>
{
    constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

    inline auto format(const Softloq::WHATWG::Infra::Number<T>& value, std::format_context& ctx) const
    {
        if constexpr (std::is_signed_v<T>)
            return std::format_to(ctx.out(), "{}", static_cast<long long>(value.get_value()));
        else
            return std::format_to(ctx.out(), "{}", static_cast<unsigned long long>(value.get_value()));
    }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_FORMATTER_TPP
