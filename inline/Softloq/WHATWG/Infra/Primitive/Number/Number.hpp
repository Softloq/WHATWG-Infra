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
#include "Softloq/WHATWG/Infra/Primitive/Number/Integral.hpp"

namespace Softloq::WHATWG::Infra
{

/**
 * @brief The Number type represents an integer numeric value in the context of web APIs.
 *
 * The Number type is parameterized over any Integral type T, covering all signed
 * and unsigned integer widths used by the WHATWG Infra specification. It provides
 * value construction, mutation, arithmetic, compound assignment, increment/decrement,
 * ordering comparison, and conversion to the underlying integral type.
 *
 * @tparam T An integral type (e.g. std::uint8_t, std::int32_t).
 */
template <Integral T>
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

} // namespace Softloq::WHATWG::Infra

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_NUMBER_HPP
