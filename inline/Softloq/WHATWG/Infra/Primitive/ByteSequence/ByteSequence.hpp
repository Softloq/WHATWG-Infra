/**
 * @file Softloq/WHATWG/Infra/Primitive/ByteSequence/ByteSequence.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the ByteSequence type for the WHATWG Infra library, representing a byte sequence in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the ByteSequence type for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTESEQUENCE_BYTESEQUENCE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTESEQUENCE_BYTESEQUENCE_HPP

#include "Softloq/WHATWG/Infra/Primitive/Primitive.hpp"
#include "Softloq/WHATWG/Infra/Primitive/Byte/Byte.hpp"
#include <cstddef>
#include <initializer_list>
#include <vector>

namespace Softloq::WHATWG::Infra
{

/**
 * @brief The ByteSequence type represents a sequence of bytes in the context of web APIs.
 *
 * The ByteSequence type represents a sequence of zero or more bytes, as defined by the WHATWG
 * Infra specification. It provides construction, element access, mutation, WHATWG Infra operations
 * (byte_lowercase, byte_uppercase, starts_with), and equality comparison. Isomorphic decode is
 * omitted until the String primitive is available.
 */
class ByteSequence final : public Primitive
{
// Constructors and destructor
public:
    constexpr ByteSequence() noexcept = default;

    explicit ByteSequence(std::initializer_list<std::uint8_t> bytes)
    {
        m_bytes.reserve(bytes.size());
        for (auto b : bytes)
            m_bytes.emplace_back(Byte{b});
    }

    constexpr ~ByteSequence() noexcept = default;

// Primitive interface
public:
    /**
     * @brief Get the type of the primitive.
     *
     * @return The type of the primitive, which is PrimitiveType::ByteSequence.
     */
    [[nodiscard]] constexpr PrimitiveType get_type() const noexcept override
    {
        return PrimitiveType::ByteSequence;
    }

// Container interface
public:
    /**
     * @brief Get the number of bytes in the sequence.
     *
     * @return The number of bytes.
     */
    [[nodiscard]] constexpr std::size_t size() const noexcept
    {
        return m_bytes.size();
    }

    /**
     * @brief Returns true if the sequence contains no bytes.
     *
     * @return true if empty.
     */
    [[nodiscard]] constexpr bool is_empty() const noexcept
    {
        return m_bytes.empty();
    }

    /**
     * @brief Access a byte by index without bounds checking.
     *
     * @param index The zero-based index of the byte.
     * @return A reference to the byte at the given index.
     */
    [[nodiscard]] constexpr Byte& operator[](std::size_t index) noexcept
    {
        return m_bytes[index];
    }

    /**
     * @brief Access a byte by index without bounds checking (const).
     *
     * @param index The zero-based index of the byte.
     * @return A const reference to the byte at the given index.
     */
    [[nodiscard]] constexpr const Byte& operator[](std::size_t index) const noexcept
    {
        return m_bytes[index];
    }

    /**
     * @brief Access a byte by index with bounds checking.
     *
     * @param index The zero-based index of the byte.
     * @return A reference to the byte at the given index.
     * @throws std::out_of_range if index is out of bounds.
     */
    [[nodiscard]] Byte& at(std::size_t index)
    {
        return m_bytes.at(index);
    }

    /**
     * @brief Access a byte by index with bounds checking (const).
     *
     * @param index The zero-based index of the byte.
     * @return A const reference to the byte at the given index.
     * @throws std::out_of_range if index is out of bounds.
     */
    [[nodiscard]] const Byte& at(std::size_t index) const
    {
        return m_bytes.at(index);
    }

    /**
     * @brief Append a byte to the end of the sequence.
     *
     * @param byte The byte to append.
     */
    void push_back(Byte byte)
    {
        m_bytes.push_back(byte);
    }

    /**
     * @brief Remove all bytes from the sequence.
     */
    constexpr void clear() noexcept
    {
        m_bytes.clear();
    }

    /**
     * @brief Returns an iterator to the first byte of the sequence.
     */
    [[nodiscard]] std::vector<Byte>::iterator begin() noexcept
    {
        return m_bytes.begin();
    }

    /**
     * @brief Returns an iterator past the last byte of the sequence.
     */
    [[nodiscard]] std::vector<Byte>::iterator end() noexcept
    {
        return m_bytes.end();
    }

    /**
     * @brief Returns a const iterator to the first byte of the sequence.
     */
    [[nodiscard]] std::vector<Byte>::const_iterator begin() const noexcept
    {
        return m_bytes.begin();
    }

    /**
     * @brief Returns a const iterator past the last byte of the sequence.
     */
    [[nodiscard]] std::vector<Byte>::const_iterator end() const noexcept
    {
        return m_bytes.end();
    }

    /**
     * @brief Returns a const iterator to the first byte of the sequence.
     */
    [[nodiscard]] std::vector<Byte>::const_iterator cbegin() const noexcept
    {
        return m_bytes.cbegin();
    }

    /**
     * @brief Returns a const iterator past the last byte of the sequence.
     */
    [[nodiscard]] std::vector<Byte>::const_iterator cend() const noexcept
    {
        return m_bytes.cend();
    }

// Operators
public:
    /**
     * @brief Equality comparison.
     *
     * @param other The ByteSequence to compare against.
     * @return true if both sequences contain the same bytes in the same order.
     */
    [[nodiscard]] constexpr bool operator==(const ByteSequence& other) const noexcept
    {
        if (m_bytes.size() != other.m_bytes.size()) return false;
        for (std::size_t i = 0; i < m_bytes.size(); ++i)
            if (m_bytes[i] != other.m_bytes[i]) return false;
        return true;
    }

    /**
     * @brief Inequality comparison.
     *
     * @param other The ByteSequence to compare against.
     * @return true if the sequences differ.
     */
    [[nodiscard]] constexpr bool operator!=(const ByteSequence& other) const noexcept
    {
        return !(*this == other);
    }

// WHATWG Infra operations
public:
    /**
     * @brief Byte-lowercase: converts each byte in the range 0x41..0x5A (A–Z) to 0x61..0x7A (a–z) in place.
     *
     * As defined by the WHATWG Infra specification.
     */
    constexpr void byte_lowercase() noexcept
    {
        for (auto& b : m_bytes)
        {
            const auto v = b.get_value();
            if (v >= 0x41 && v <= 0x5A)
                b.set_value(static_cast<std::uint8_t>(v + 0x20));
        }
    }

    /**
     * @brief Byte-uppercase: converts each byte in the range 0x61..0x7A (a–z) to 0x41..0x5A (A–Z) in place.
     *
     * As defined by the WHATWG Infra specification.
     */
    constexpr void byte_uppercase() noexcept
    {
        for (auto& b : m_bytes)
        {
            const auto v = b.get_value();
            if (v >= 0x61 && v <= 0x7A)
                b.set_value(static_cast<std::uint8_t>(v - 0x20));
        }
    }

    /**
     * @brief Returns true if this byte sequence starts with the given byte sequence.
     *
     * A byte sequence a starts with b if a's length is greater than or equal to b's length
     * and the first b's length bytes of a are b, as defined by the WHATWG Infra specification.
     *
     * @param other The byte sequence to check as a prefix.
     * @return true if this sequence starts with other.
     */
    [[nodiscard]] constexpr bool starts_with(const ByteSequence& other) const noexcept
    {
        if (other.m_bytes.size() > m_bytes.size()) return false;
        for (std::size_t i = 0; i < other.m_bytes.size(); ++i)
            if (m_bytes[i] != other.m_bytes[i]) return false;
        return true;
    }

private:
    std::vector<Byte> m_bytes;
};

} // namespace Softloq::WHATWG::Infra

#include "Softloq/WHATWG/Infra/Primitive/ByteSequence/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/ByteSequence/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTESEQUENCE_BYTESEQUENCE_HPP
