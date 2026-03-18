/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/Number.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the Number type for the WHATWG Infra library, representing integer numeric values in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the Number type for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_NUMBER_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_NUMBER_HPP

#include "Softloq/WHATWG/Infra/Primitive/Primitive.hpp"
#include <concepts>
#include <cstdint>

namespace Softloq::WHATWG::Infra
{

/**
 * @brief The Number type represents an integer numeric value in the context of web APIs.
 *
 * The Number type is parameterized over any std::integral type T, covering all signed
 * and unsigned integer widths used by the WHATWG Infra specification. It provides
 * value construction, mutation, arithmetic, compound assignment, increment/decrement,
 * ordering comparison, and conversion to the underlying integral type.
 *
 * @tparam T An integral type (e.g. std::uint8_t, std::int32_t).
 */
template <std::integral T>
class Number final : public Primitive
{
// Constructors and destructor
public:
    constexpr Number() noexcept = default;

    constexpr explicit Number(T value) noexcept
        : m_value{value}
    {
    }

    constexpr ~Number() noexcept = default;

// Primitive interface
public:
    /**
     * @brief Get the type of the primitive.
     *
     * @return The type of the primitive, which is PrimitiveType::Number.
     */
    [[nodiscard]] constexpr PrimitiveType get_type() const noexcept override
    {
        return PrimitiveType::Number;
    }

// Accessors
public:
    /**
     * @brief Get the underlying integer value.
     *
     * @return The stored integer value.
     */
    [[nodiscard]] constexpr T get_value() const noexcept
    {
        return m_value;
    }

    /**
     * @brief Set the underlying integer value.
     *
     * @param value The new integer value to store.
     */
    constexpr void set_value(T value) noexcept
    {
        m_value = value;
    }

// Conversion
public:
    /**
     * @brief Explicit conversion to the underlying integral type T.
     *
     * @return The stored integer value.
     */
    [[nodiscard]] constexpr explicit operator T() const noexcept
    {
        return m_value;
    }

// Arithmetic operators
public:
    /**
     * @brief Addition.
     *
     * @param other The Number to add.
     * @return A new Number holding the sum.
     */
    [[nodiscard]] constexpr Number operator+(const Number& other) const noexcept
    {
        return Number{static_cast<T>(m_value + other.m_value)};
    }

    /**
     * @brief Subtraction.
     *
     * @param other The Number to subtract.
     * @return A new Number holding the difference.
     */
    [[nodiscard]] constexpr Number operator-(const Number& other) const noexcept
    {
        return Number{static_cast<T>(m_value - other.m_value)};
    }

    /**
     * @brief Multiplication.
     *
     * @param other The Number to multiply by.
     * @return A new Number holding the product.
     */
    [[nodiscard]] constexpr Number operator*(const Number& other) const noexcept
    {
        return Number{static_cast<T>(m_value * other.m_value)};
    }

    /**
     * @brief Division.
     *
     * @param other The Number to divide by.
     * @return A new Number holding the quotient.
     */
    [[nodiscard]] constexpr Number operator/(const Number& other) const noexcept
    {
        return Number{static_cast<T>(m_value / other.m_value)};
    }

    /**
     * @brief Modulo.
     *
     * @param other The Number to compute the remainder with.
     * @return A new Number holding the remainder.
     */
    [[nodiscard]] constexpr Number operator%(const Number& other) const noexcept
    {
        return Number{static_cast<T>(m_value % other.m_value)};
    }

// Compound assignment operators
public:
    /**
     * @brief Addition assignment.
     *
     * @param other The Number to add.
     * @return Reference to this instance after addition.
     */
    constexpr Number& operator+=(const Number& other) noexcept
    {
        m_value += other.m_value;
        return *this;
    }

    /**
     * @brief Subtraction assignment.
     *
     * @param other The Number to subtract.
     * @return Reference to this instance after subtraction.
     */
    constexpr Number& operator-=(const Number& other) noexcept
    {
        m_value -= other.m_value;
        return *this;
    }

    /**
     * @brief Multiplication assignment.
     *
     * @param other The Number to multiply by.
     * @return Reference to this instance after multiplication.
     */
    constexpr Number& operator*=(const Number& other) noexcept
    {
        m_value *= other.m_value;
        return *this;
    }

    /**
     * @brief Division assignment.
     *
     * @param other The Number to divide by.
     * @return Reference to this instance after division.
     */
    constexpr Number& operator/=(const Number& other) noexcept
    {
        m_value /= other.m_value;
        return *this;
    }

    /**
     * @brief Modulo assignment.
     *
     * @param other The Number to compute the remainder with.
     * @return Reference to this instance after modulo.
     */
    constexpr Number& operator%=(const Number& other) noexcept
    {
        m_value %= other.m_value;
        return *this;
    }

// Increment and decrement operators
public:
    /**
     * @brief Prefix increment.
     *
     * @return Reference to this instance after incrementing.
     */
    constexpr Number& operator++() noexcept
    {
        ++m_value;
        return *this;
    }

    /**
     * @brief Postfix increment.
     *
     * @return A copy of this instance before incrementing.
     */
    constexpr Number operator++(int) noexcept
    {
        Number copy{m_value};
        ++m_value;
        return copy;
    }

    /**
     * @brief Prefix decrement.
     *
     * @return Reference to this instance after decrementing.
     */
    constexpr Number& operator--() noexcept
    {
        --m_value;
        return *this;
    }

    /**
     * @brief Postfix decrement.
     *
     * @return A copy of this instance before decrementing.
     */
    constexpr Number operator--(int) noexcept
    {
        Number copy{m_value};
        --m_value;
        return copy;
    }

// Comparison operators
public:
    /**
     * @brief Equality comparison.
     *
     * @param other The Number to compare against.
     * @return true if both instances hold the same value.
     */
    [[nodiscard]] constexpr bool operator==(const Number& other) const noexcept
    {
        return m_value == other.m_value;
    }

    /**
     * @brief Inequality comparison.
     *
     * @param other The Number to compare against.
     * @return true if the instances hold different values.
     */
    [[nodiscard]] constexpr bool operator!=(const Number& other) const noexcept
    {
        return m_value != other.m_value;
    }

    /**
     * @brief Less-than comparison.
     *
     * @param other The Number to compare against.
     * @return true if this instance is less than other.
     */
    [[nodiscard]] constexpr bool operator<(const Number& other) const noexcept
    {
        return m_value < other.m_value;
    }

    /**
     * @brief Less-than-or-equal comparison.
     *
     * @param other The Number to compare against.
     * @return true if this instance is less than or equal to other.
     */
    [[nodiscard]] constexpr bool operator<=(const Number& other) const noexcept
    {
        return m_value <= other.m_value;
    }

    /**
     * @brief Greater-than comparison.
     *
     * @param other The Number to compare against.
     * @return true if this instance is greater than other.
     */
    [[nodiscard]] constexpr bool operator>(const Number& other) const noexcept
    {
        return m_value > other.m_value;
    }

    /**
     * @brief Greater-than-or-equal comparison.
     *
     * @param other The Number to compare against.
     * @return true if this instance is greater than or equal to other.
     */
    [[nodiscard]] constexpr bool operator>=(const Number& other) const noexcept
    {
        return m_value >= other.m_value;
    }

private:
    T m_value{};
};

// ---------------------------------------------------------------------------
// Type aliases for common integer widths
// ---------------------------------------------------------------------------

/**
 * @brief Alias for an 8-bit unsigned integer Number.
 */
using UInt8  = Number<std::uint8_t>;

/**
 * @brief Alias for a 16-bit unsigned integer Number.
 */
using UInt16 = Number<std::uint16_t>;

/**
 * @brief Alias for a 32-bit unsigned integer Number.
 */
using UInt32 = Number<std::uint32_t>;

/**
 * @brief Alias for a 64-bit unsigned integer Number.
 */
using UInt64 = Number<std::uint64_t>;

/**
 * @brief Alias for an 8-bit signed integer Number.
 */
using Int8   = Number<std::int8_t>;

/**
 * @brief Alias for a 16-bit signed integer Number.
 */
using Int16  = Number<std::int16_t>;

/**
 * @brief Alias for a 32-bit signed integer Number.
 */
using Int32  = Number<std::int32_t>;

/**
 * @brief Alias for a 64-bit signed integer Number.
 */
using Int64  = Number<std::int64_t>;

} // namespace Softloq::WHATWG::Infra

#include "Softloq/WHATWG/Infra/Primitive/Number/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_NUMBER_HPP
