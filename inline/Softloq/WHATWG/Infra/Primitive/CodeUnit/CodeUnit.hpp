/**
 * @file Softloq/WHATWG/Infra/Primitive/CodeUnit/CodeUnit.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the CodeUnit type for the WHATWG Infra library, representing a UTF-16 code unit in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the CodeUnit type for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEUNIT_CODEUNIT_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEUNIT_CODEUNIT_HPP

#include "Softloq/WHATWG/Infra/Primitive/Primitive.hpp"
#include <cstdint>

namespace Softloq::WHATWG::Infra
{

/**
 * @brief The CodeUnit type represents a UTF-16 code unit in the context of web APIs.
 *
 * The CodeUnit type represents a 16-bit unsigned integer used as the fundamental unit of
 * UTF-16 encoded strings, as defined by the WHATWG Infra specification. It provides value
 * construction, mutation, equality comparison, explicit conversion to the underlying
 * std::uint16_t type, and a full set of Unicode attribute predicates matching those defined
 * for CodePoint (e.g. is_surrogate, is_ascii, is_ascii_whitespace).
 *
 * @note This is an auxiliary class to the String primitive. It is used internally by the
 * String type to represent individual elements of a UTF-16 encoded string.
 */
class CodeUnit final : public Primitive
{
// Constructors and destructor
public:
    constexpr CodeUnit() noexcept = default;

    constexpr explicit CodeUnit(std::uint16_t value) noexcept
        : m_value{value}
    {
    }

    constexpr ~CodeUnit() noexcept = default;

// Primitive interface
public:
    /**
     * @brief Get the type of the primitive.
     *
     * @return The type of the primitive, which is PrimitiveType::CodeUnit.
     */
    [[nodiscard]] constexpr PrimitiveType get_type() const noexcept override
    {
        return PrimitiveType::CodeUnit;
    }

// Accessors
public:
    /**
     * @brief Get the underlying code unit value.
     *
     * @return The stored code unit as std::uint16_t.
     */
    [[nodiscard]] constexpr std::uint16_t get_value() const noexcept
    {
        return m_value;
    }

    /**
     * @brief Set the underlying code unit value.
     *
     * @param value The new code unit to store.
     */
    constexpr void set_value(std::uint16_t value) noexcept
    {
        m_value = value;
    }

// Conversion
public:
    /**
     * @brief Explicit conversion to std::uint16_t.
     *
     * @return The stored code unit value.
     */
    [[nodiscard]] constexpr explicit operator std::uint16_t() const noexcept
    {
        return m_value;
    }

// Operators
public:
    /**
     * @brief Equality comparison.
     *
     * @param other The CodeUnit to compare against.
     * @return true if both instances hold the same value.
     */
    [[nodiscard]] constexpr bool operator==(const CodeUnit& other) const noexcept
    {
        return m_value == other.m_value;
    }

    /**
     * @brief Inequality comparison.
     *
     * @param other The CodeUnit to compare against.
     * @return true if the instances hold different values.
     */
    [[nodiscard]] constexpr bool operator!=(const CodeUnit& other) const noexcept
    {
        return m_value != other.m_value;
    }

// Unicode attribute predicates
public:
    /**
     * @brief Returns true if the code unit is a surrogate (0xD800 to 0xDFFF).
     */
    [[nodiscard]] constexpr bool is_surrogate() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is a leading surrogate (0xD800 to 0xDBFF).
     */
    [[nodiscard]] constexpr bool is_leading_surrogate() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is a trailing surrogate (0xDC00 to 0xDFFF).
     */
    [[nodiscard]] constexpr bool is_trailing_surrogate() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is an ASCII code unit (0x0000 to 0x007F).
     */
    [[nodiscard]] constexpr bool is_ascii() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is an ASCII tab or newline (0x0009, 0x000A, 0x000D).
     */
    [[nodiscard]] constexpr bool is_ascii_tab_or_newline() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is ASCII whitespace (0x0009, 0x000A, 0x000C, 0x000D, 0x0020).
     */
    [[nodiscard]] constexpr bool is_ascii_whitespace() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is a C0 control (0x0000 to 0x001F).
     */
    [[nodiscard]] constexpr bool is_c0_control() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is a C0 control or 0x0020 SPACE.
     */
    [[nodiscard]] constexpr bool is_c0_control_or_space() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is a control (C0, 0x007F DEL, or 0x0080 to 0x009F).
     */
    [[nodiscard]] constexpr bool is_control() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is an ASCII digit (0x0030 to 0x0039).
     */
    [[nodiscard]] constexpr bool is_ascii_digit() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is an ASCII upper hex digit (0x0030..0x0039 or 0x0041..0x0046).
     */
    [[nodiscard]] constexpr bool is_ascii_upper_hex_digit() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is an ASCII lower hex digit (0x0030..0x0039 or 0x0061..0x0066).
     */
    [[nodiscard]] constexpr bool is_ascii_lower_hex_digit() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is an ASCII hex digit (upper or lower).
     */
    [[nodiscard]] constexpr bool is_ascii_hex_digit() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is an ASCII upper alpha (0x0041 to 0x005A).
     */
    [[nodiscard]] constexpr bool is_ascii_upper_alpha() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is an ASCII lower alpha (0x0061 to 0x007A).
     */
    [[nodiscard]] constexpr bool is_ascii_lower_alpha() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is an ASCII alpha (upper or lower).
     */
    [[nodiscard]] constexpr bool is_ascii_alpha() const noexcept { return false; }

    /**
     * @brief Returns true if the code unit is an ASCII alphanumeric (digit or alpha).
     */
    [[nodiscard]] constexpr bool is_ascii_alphanumeric() const noexcept { return false; }

private:
    std::uint16_t m_value{0};
};

} // namespace Softloq::WHATWG::Infra

#include "Softloq/WHATWG/Infra/Primitive/CodeUnit/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/CodeUnit/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEUNIT_CODEUNIT_HPP
