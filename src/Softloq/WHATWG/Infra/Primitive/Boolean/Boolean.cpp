/**
 * @file Softloq/WHATWG/Infra/Primitive/Boolean/Boolean.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This implements the Boolean type for the WHATWG Infra library, representing a boolean value in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This implements the Boolean type for the WHATWG Infra library.
 */

#include <Softloq/WHATWG/Infra/API-Library/Precompiled.pch>
#include <Softloq/WHATWG/Infra/Primitive/Boolean/Boolean.hpp>

namespace Softloq::WHATWG::Infra
{

Boolean::Boolean() noexcept = default;

Boolean::Boolean(bool value) noexcept
    : m_value{value}
{
}

Boolean::~Boolean() noexcept = default;

PrimitiveType Boolean::get_type() const noexcept
{
    return PrimitiveType::Boolean;
}

bool Boolean::get_value() const noexcept
{
    return m_value;
}

void Boolean::set_value(bool value) noexcept
{
    m_value = value;
}

Boolean::operator bool() const noexcept
{
    return m_value;
}

Boolean Boolean::operator!() const noexcept
{
    return Boolean{!m_value};
}

bool Boolean::operator==(const Boolean& other) const noexcept
{
    return m_value == other.m_value;
}

bool Boolean::operator!=(const Boolean& other) const noexcept
{
    return m_value != other.m_value;
}

} // namespace Softloq::WHATWG::Infra
