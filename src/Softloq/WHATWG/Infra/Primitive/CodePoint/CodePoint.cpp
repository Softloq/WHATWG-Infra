/**
 * @file Softloq/WHATWG/Infra/Primitive/CodePoint/CodePoint.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This implements the CodePoint type for the WHATWG Infra library, representing a Unicode code point in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file provides the implementation of the CodePoint primitive type.
 */

#include <Softloq/WHATWG/Infra/API-Library/Precompiled.pch>
#include <Softloq/WHATWG/Infra/Primitive/CodePoint/CodePoint.hpp>

namespace Softloq::WHATWG::Infra
{

CodePoint::CodePoint() noexcept = default;

CodePoint::CodePoint(char32_t value) noexcept
    : m_value{value}
{
}

CodePoint::~CodePoint() noexcept = default;

PrimitiveType CodePoint::get_type() const noexcept { return PrimitiveType::CodePoint; }

char32_t CodePoint::get_value() const noexcept { return m_value; }

void CodePoint::set_value(char32_t value) noexcept { m_value = value; }

CodePoint::operator char32_t() const noexcept { return m_value; }

bool CodePoint::operator==(const CodePoint& other) const noexcept { return m_value == other.m_value; }

bool CodePoint::operator!=(const CodePoint& other) const noexcept { return m_value != other.m_value; }

bool CodePoint::is_surrogate() const noexcept
{
    return m_value >= 0xD800 && m_value <= 0xDFFF;
}

bool CodePoint::is_leading_surrogate() const noexcept
{
    return m_value >= 0xD800 && m_value <= 0xDBFF;
}

bool CodePoint::is_trailing_surrogate() const noexcept
{
    return m_value >= 0xDC00 && m_value <= 0xDFFF;
}

bool CodePoint::is_scalar_value() const noexcept
{
    return !is_surrogate();
}

bool CodePoint::is_noncharacter() const noexcept
{
    if (m_value >= 0xFDD0 && m_value <= 0xFDEF) return true;
    return (m_value & 0xFFFF) >= 0xFFFE;
}

bool CodePoint::is_ascii() const noexcept
{
    return m_value <= 0x007F;
}

bool CodePoint::is_ascii_tab_or_newline() const noexcept
{
    return m_value == 0x0009 || m_value == 0x000A || m_value == 0x000D;
}

bool CodePoint::is_ascii_whitespace() const noexcept
{
    return m_value == 0x0009 || m_value == 0x000A
        || m_value == 0x000C || m_value == 0x000D
        || m_value == 0x0020;
}

bool CodePoint::is_c0_control() const noexcept
{
    return m_value <= 0x001F;
}

bool CodePoint::is_c0_control_or_space() const noexcept
{
    return m_value <= 0x001F || m_value == 0x0020;
}

bool CodePoint::is_control() const noexcept
{
    return m_value <= 0x001F || m_value == 0x007F
        || (m_value >= 0x0080 && m_value <= 0x009F);
}

bool CodePoint::is_ascii_digit() const noexcept
{
    return m_value >= 0x0030 && m_value <= 0x0039;
}

bool CodePoint::is_ascii_upper_hex_digit() const noexcept
{
    return is_ascii_digit()
        || (m_value >= 0x0041 && m_value <= 0x0046);
}

bool CodePoint::is_ascii_lower_hex_digit() const noexcept
{
    return is_ascii_digit()
        || (m_value >= 0x0061 && m_value <= 0x0066);
}

bool CodePoint::is_ascii_hex_digit() const noexcept
{
    return is_ascii_upper_hex_digit() || is_ascii_lower_hex_digit();
}

bool CodePoint::is_ascii_upper_alpha() const noexcept
{
    return m_value >= 0x0041 && m_value <= 0x005A;
}

bool CodePoint::is_ascii_lower_alpha() const noexcept
{
    return m_value >= 0x0061 && m_value <= 0x007A;
}

bool CodePoint::is_ascii_alpha() const noexcept
{
    return is_ascii_upper_alpha() || is_ascii_lower_alpha();
}

bool CodePoint::is_ascii_alphanumeric() const noexcept
{
    return is_ascii_digit() || is_ascii_alpha();
}

} // namespace Softloq::WHATWG::Infra
