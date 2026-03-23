/**
 * @file Softloq/WHATWG/Infra/Primitive/ByteSequence/ByteSequence.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This implements the ByteSequence type for the WHATWG Infra library, representing a byte sequence in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file provides the implementation of the ByteSequence primitive type.
 */

#include <Softloq/WHATWG/Infra/API-Library/Precompiled.pch>
#include <Softloq/WHATWG/Infra/Primitive/ByteSequence/ByteSequence.hpp>

namespace Softloq::WHATWG::Infra
{

ByteSequence::ByteSequence() noexcept = default;

ByteSequence::ByteSequence(const ByteSequence& other) noexcept
    : m_bytes{other.m_bytes}
{
}

ByteSequence::ByteSequence(std::initializer_list<std::uint8_t> bytes) noexcept
{
    m_bytes.reserve(bytes.size());
    for (auto b : bytes)
        m_bytes.emplace_back(Byte{b});
}

ByteSequence::~ByteSequence() noexcept = default;

PrimitiveType ByteSequence::get_type() const noexcept { return PrimitiveType::ByteSequence; }

std::size_t ByteSequence::size() const noexcept { return m_bytes.size(); }

bool ByteSequence::is_empty() const noexcept { return m_bytes.empty(); }

Byte& ByteSequence::operator[](std::size_t index) noexcept { return m_bytes[index]; }

const Byte& ByteSequence::operator[](std::size_t index) const noexcept { return m_bytes[index]; }

Byte& ByteSequence::at(std::size_t index) { return m_bytes.at(index); }

const Byte& ByteSequence::at(std::size_t index) const { return m_bytes.at(index); }

void ByteSequence::push_back(Byte byte) { m_bytes.push_back(byte); }

void ByteSequence::clear() noexcept { m_bytes.clear(); }

std::vector<Byte>::iterator ByteSequence::begin() noexcept { return m_bytes.begin(); }

std::vector<Byte>::iterator ByteSequence::end() noexcept { return m_bytes.end(); }

std::vector<Byte>::const_iterator ByteSequence::begin() const noexcept { return m_bytes.begin(); }

std::vector<Byte>::const_iterator ByteSequence::end() const noexcept { return m_bytes.end(); }

std::vector<Byte>::const_iterator ByteSequence::cbegin() const noexcept { return m_bytes.cbegin(); }

std::vector<Byte>::const_iterator ByteSequence::cend() const noexcept { return m_bytes.cend(); }

bool ByteSequence::operator==(const ByteSequence& other) const noexcept
{
    if (m_bytes.size() != other.m_bytes.size()) return false;
    for (std::size_t i = 0; i < m_bytes.size(); ++i)
        if (m_bytes[i] != other.m_bytes[i]) return false;
    return true;
}

bool ByteSequence::operator!=(const ByteSequence& other) const noexcept
{
    return !(*this == other);
}

void ByteSequence::byte_lowercase() noexcept
{
    for (auto& b : m_bytes)
    {
        const auto v = b.get_value();
        if (v >= 0x41 && v <= 0x5A)
            b.set_value(static_cast<std::uint8_t>(v + 0x20));
    }
}

void ByteSequence::byte_uppercase() noexcept
{
    for (auto& b : m_bytes)
    {
        const auto v = b.get_value();
        if (v >= 0x61 && v <= 0x7A)
            b.set_value(static_cast<std::uint8_t>(v - 0x20));
    }
}

bool ByteSequence::starts_with(const ByteSequence& other) const noexcept
{
    if (other.m_bytes.size() > m_bytes.size()) return false;
    for (std::size_t i = 0; i < other.m_bytes.size(); ++i)
        if (m_bytes[i] != other.m_bytes[i]) return false;
    return true;
}

} // namespace Softloq::WHATWG::Infra
