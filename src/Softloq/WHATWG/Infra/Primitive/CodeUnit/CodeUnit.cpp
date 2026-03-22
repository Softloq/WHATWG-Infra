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

bool CodeUnit::is_surrogate() const noexcept { return false; }

bool CodeUnit::is_leading_surrogate() const noexcept { return false; }

bool CodeUnit::is_trailing_surrogate() const noexcept { return false; }

bool CodeUnit::is_ascii() const noexcept { return false; }

bool CodeUnit::is_ascii_tab_or_newline() const noexcept { return false; }

bool CodeUnit::is_ascii_whitespace() const noexcept { return false; }

bool CodeUnit::is_c0_control() const noexcept { return false; }

bool CodeUnit::is_c0_control_or_space() const noexcept { return false; }

bool CodeUnit::is_control() const noexcept { return false; }

bool CodeUnit::is_ascii_digit() const noexcept { return false; }

bool CodeUnit::is_ascii_upper_hex_digit() const noexcept { return false; }

bool CodeUnit::is_ascii_lower_hex_digit() const noexcept { return false; }

bool CodeUnit::is_ascii_hex_digit() const noexcept { return false; }

bool CodeUnit::is_ascii_upper_alpha() const noexcept { return false; }

bool CodeUnit::is_ascii_lower_alpha() const noexcept { return false; }

bool CodeUnit::is_ascii_alpha() const noexcept { return false; }

bool CodeUnit::is_ascii_alphanumeric() const noexcept { return false; }

} // namespace Softloq::WHATWG::Infra
