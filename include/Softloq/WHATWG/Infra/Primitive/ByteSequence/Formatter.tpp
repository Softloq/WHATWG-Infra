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
#include <string>

/**
 * @brief Formatter specialization for the ByteSequence primitive type.
 *
 * This formatter specialization allows the ByteSequence primitive type to be formatted
 * as a string using std::format.
 */
template <>
struct std::formatter<Softloq::WHATWG::Infra::ByteSequence> : std::formatter<std::string>
{
    inline auto format(const Softloq::WHATWG::Infra::ByteSequence& value, format_context& ctx) const
    {
        return formatter<std::string>::format(std::string{}, ctx);
    }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTESEQUENCE_FORMATTER_TPP
