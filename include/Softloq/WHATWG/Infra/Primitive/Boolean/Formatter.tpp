/**
 * @file Softloq/WHATWG/Infra/Primitive/Boolean/Formatter.tpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Formatter specialization for the Boolean primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains the formatter specialization for the Boolean primitive type.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOLEAN_FORMATTER_TPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOLEAN_FORMATTER_TPP

#include "Softloq/WHATWG/Infra/Primitive/Boolean/Boolean.hpp"
#include <format>

/**
 * @brief Formatter specialization for the Boolean primitive type.
 *
 * This formatter specialization allows the Boolean primitive type to be formatted
 * as a string using std::format. When formatted, the Boolean primitive will be
 * represented as "true" or "false".
 */
template <>
struct std::formatter<Softloq::WHATWG::Infra::Boolean> : std::formatter<std::string>
{
    inline auto format(const Softloq::WHATWG::Infra::Boolean& value, format_context& ctx) const
    {
        return formatter<std::string>::format(value.get_value() ? "true" : "false", ctx);
    }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOLEAN_FORMATTER_TPP
