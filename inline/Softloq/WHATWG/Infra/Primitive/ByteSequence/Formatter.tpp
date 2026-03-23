/**
 * @file Softloq/WHATWG/Infra/Primitive/ByteSequence/Formatter.tpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Formatter specialization for the ByteSequence primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains the formatter specialization for the ByteSequence primitive type.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTESEQUENCE_FORMATTER_TPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTESEQUENCE_FORMATTER_TPP

#include "Softloq/WHATWG/Infra/Primitive/ByteSequence/ByteSequence.hpp"
#include <format>

/**
 * @brief Formatter specialization for the ByteSequence primitive type.
 *
 * This formatter specialization allows the ByteSequence primitive type to be formatted
 * as a string using std::format.
 */
template <>
struct std::formatter<Softloq::WHATWG::Infra::ByteSequence>
{
    constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

    inline auto format(const Softloq::WHATWG::Infra::ByteSequence& value, std::format_context& ctx) const
    {
        auto out = ctx.out();
        out = std::format_to(out, "[");
        for (std::size_t i = 0; i < value.size(); ++i)
        {
            if (i > 0) out = std::format_to(out, " ");
            out = std::format_to(out, "0x{:02X}", static_cast<unsigned>(value[i].get_value()));
        }
        return std::format_to(out, "]");
    }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTESEQUENCE_FORMATTER_TPP
