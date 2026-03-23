/**
 * @file Softloq/WHATWG/Infra/Primitive/Byte/Byte.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This implements the Byte type for the WHATWG Infra library, representing a byte value in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This implements the Byte type for the WHATWG Infra library.
 */

#include <Softloq/WHATWG/Infra/API-Library/Precompiled.pch>
#include <Softloq/WHATWG/Infra/Primitive/Byte/Byte.hpp>

namespace Softloq::WHATWG::Infra
{

Byte::Byte() noexcept = default;

Byte::Byte(const Byte& other) noexcept
    : m_value{other.m_value}
{
}

Byte::Byte(std::uint8_t value) noexcept
    : m_value{value}
{
}

Byte::~Byte() noexcept = default;

PrimitiveType Byte::get_type() const noexcept
{
    return PrimitiveType::Byte;
}

std::uint8_t Byte::get_value() const noexcept
{
    return m_value;
}

void Byte::set_value(std::uint8_t value) noexcept
{
    m_value = value;
}

Byte::operator std::uint8_t() const noexcept
{
    return m_value;
}

bool Byte::operator==(const Byte& other) const noexcept
{
    return m_value == other.m_value;
}

bool Byte::operator!=(const Byte& other) const noexcept
{
    return m_value != other.m_value;
}

} // namespace Softloq::WHATWG::Infra
