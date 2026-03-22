/**
 * @file Softloq/WHATWG/Infra/Primitive/CodeUnit/CodeUnit.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This implements the CodeUnit type for the WHATWG Infra library, representing a UTF-16 code unit in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file provides the implementation of the CodeUnit primitive type.
 */

#include <Softloq/WHATWG/Infra/API-Library/Precompiled.pch>
#include <Softloq/WHATWG/Infra/Primitive/CodeUnit/CodeUnit.hpp>

namespace Softloq::WHATWG::Infra
{

CodeUnit::CodeUnit() noexcept = default;

CodeUnit::CodeUnit(std::uint16_t value) noexcept
    : m_value{value}
{
}

CodeUnit::~CodeUnit() noexcept = default;

PrimitiveType CodeUnit::get_type() const noexcept { return PrimitiveType::CodeUnit; }

std::uint16_t CodeUnit::get_value() const noexcept { return m_value; }

void CodeUnit::set_value(std::uint16_t value) noexcept { m_value = value; }

CodeUnit::operator std::uint16_t() const noexcept { return m_value; }

bool CodeUnit::operator==(const CodeUnit& other) const noexcept { return m_value == other.m_value; }

bool CodeUnit::operator!=(const CodeUnit& other) const noexcept { return m_value != other.m_value; }

bool CodeUnit::is_surrogate() const noexcept
{
    return m_value >= 0xD800 && m_value <= 0xDFFF;
}

bool CodeUnit::is_leading_surrogate() const noexcept
{
    return m_value >= 0xD800 && m_value <= 0xDBFF;
}

bool CodeUnit::is_trailing_surrogate() const noexcept
{
    return m_value >= 0xDC00 && m_value <= 0xDFFF;
}

bool CodeUnit::is_ascii() const noexcept
{
    return m_value <= 0x007F;
}

bool CodeUnit::is_ascii_tab_or_newline() const noexcept
{
    return m_value == 0x0009 || m_value == 0x000A || m_value == 0x000D;
}

bool CodeUnit::is_ascii_whitespace() const noexcept
{
    return m_value == 0x0009 || m_value == 0x000A
        || m_value == 0x000C || m_value == 0x000D
        || m_value == 0x0020;
}

bool CodeUnit::is_c0_control() const noexcept
{
    return m_value <= 0x001F;
}

bool CodeUnit::is_c0_control_or_space() const noexcept
{
    return m_value <= 0x001F || m_value == 0x0020;
}

bool CodeUnit::is_control() const noexcept
{
    return m_value <= 0x001F || m_value == 0x007F
        || (m_value >= 0x0080 && m_value <= 0x009F);
}

bool CodeUnit::is_ascii_digit() const noexcept
{
    return m_value >= 0x0030 && m_value <= 0x0039;
}

bool CodeUnit::is_ascii_upper_hex_digit() const noexcept
{
    return is_ascii_digit()
        || (m_value >= 0x0041 && m_value <= 0x0046);
}

bool CodeUnit::is_ascii_lower_hex_digit() const noexcept
{
    return is_ascii_digit()
        || (m_value >= 0x0061 && m_value <= 0x0066);
}

bool CodeUnit::is_ascii_hex_digit() const noexcept
{
    return is_ascii_upper_hex_digit() || is_ascii_lower_hex_digit();
}

bool CodeUnit::is_ascii_upper_alpha() const noexcept
{
    return m_value >= 0x0041 && m_value <= 0x005A;
}

bool CodeUnit::is_ascii_lower_alpha() const noexcept
{
    return m_value >= 0x0061 && m_value <= 0x007A;
}

bool CodeUnit::is_ascii_alpha() const noexcept
{
    return is_ascii_upper_alpha() || is_ascii_lower_alpha();
}

bool CodeUnit::is_ascii_alphanumeric() const noexcept
{
    return is_ascii_digit() || is_ascii_alpha();
}

} // namespace Softloq::WHATWG::Infra
