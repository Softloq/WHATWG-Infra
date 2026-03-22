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

bool CodePoint::is_surrogate() const noexcept { return false; }

bool CodePoint::is_leading_surrogate() const noexcept { return false; }

bool CodePoint::is_trailing_surrogate() const noexcept { return false; }

bool CodePoint::is_scalar_value() const noexcept { return false; }

bool CodePoint::is_noncharacter() const noexcept { return false; }

bool CodePoint::is_ascii() const noexcept { return false; }

bool CodePoint::is_ascii_tab_or_newline() const noexcept { return false; }

bool CodePoint::is_ascii_whitespace() const noexcept { return false; }

bool CodePoint::is_c0_control() const noexcept { return false; }

bool CodePoint::is_c0_control_or_space() const noexcept { return false; }

bool CodePoint::is_control() const noexcept { return false; }

bool CodePoint::is_ascii_digit() const noexcept { return false; }

bool CodePoint::is_ascii_upper_hex_digit() const noexcept { return false; }

bool CodePoint::is_ascii_lower_hex_digit() const noexcept { return false; }

bool CodePoint::is_ascii_hex_digit() const noexcept { return false; }

bool CodePoint::is_ascii_upper_alpha() const noexcept { return false; }

bool CodePoint::is_ascii_lower_alpha() const noexcept { return false; }

bool CodePoint::is_ascii_alpha() const noexcept { return false; }

bool CodePoint::is_ascii_alphanumeric() const noexcept { return false; }

} // namespace Softloq::WHATWG::Infra
