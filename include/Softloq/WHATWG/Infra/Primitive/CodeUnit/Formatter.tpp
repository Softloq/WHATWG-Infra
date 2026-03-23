/**
 * @file Softloq/WHATWG/Infra/Primitive/CodeUnit/Formatter.tpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Formatter specialization for the CodeUnit primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains the formatter specialization for the CodeUnit primitive type.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEUNIT_FORMATTER_TPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEUNIT_FORMATTER_TPP

#include "Softloq/WHATWG/Infra/Primitive/CodeUnit/CodeUnit.hpp"
#include <format>
#include <string>

/**
 * @brief Formatter specialization for the CodeUnit primitive type.
 *
 * This formatter specialization allows the CodeUnit primitive type to be formatted
 * as a string using std::format. When formatted, the CodeUnit will be represented
 * as a hexadecimal integer prefixed with "0x" and zero-padded to four uppercase
 * hex digits (e.g., 0x0000, 0x00FF, 0xD800, 0xFFFF).
 */
template <>
struct std::formatter<Softloq::WHATWG::Infra::CodeUnit> : std::formatter<std::string>
{
    inline auto format(const Softloq::WHATWG::Infra::CodeUnit& value, format_context& ctx) const
    {
        return formatter<std::string>::format(
            std::format("0x{:04X}", static_cast<unsigned>(value.get_value())), ctx);
    }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEUNIT_FORMATTER_TPP
