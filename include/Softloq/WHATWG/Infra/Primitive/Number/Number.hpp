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

#include "Softloq/WHATWG/Infra/API-Library/Macro.hpp"
#include "Softloq/WHATWG/Infra/Primitive/Primitive.hpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/Integral.hpp"

namespace Softloq::WHATWG::Infra
{

/**
 * @brief The Number type represents an integral numeric value in the context of web APIs.
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
    Number() noexcept;
    explicit Number(T value) noexcept;
    ~Number() noexcept;

// Primitive interface
public:
    /**
     * @brief Get the type of the primitive.
     *
     * @return The type of the primitive, which is PrimitiveType::Number.
     */
    [[nodiscard]] PrimitiveType get_type() const noexcept override;

// Accessors
public:
    /**
     * @brief Get the underlying integer value.
     *
     * @return The stored integer value.
     */
    [[nodiscard]] T get_value() const noexcept;

    /**
     * @brief Set the underlying integer value.
     *
     * @param value The new integer value to store.
     */
    void set_value(T value) noexcept;

// Conversion
public:
    /**
     * @brief Explicit conversion to the underlying integral type T.
     *
     * @return The stored integer value.
     */
    [[nodiscard]] explicit operator T() const noexcept;

// Arithmetic operators
public:
    /**
     * @brief Addition.
     *
     * @param other The Number to add.
     * @return A new Number holding the sum.
     */
    [[nodiscard]] Number operator+(const Number& other) const noexcept;

    /**
     * @brief Subtraction.
     *
     * @param other The Number to subtract.
     * @return A new Number holding the difference.
     */
    [[nodiscard]] Number operator-(const Number& other) const noexcept;

    /**
     * @brief Multiplication.
     *
     * @param other The Number to multiply by.
     * @return A new Number holding the product.
     */
    [[nodiscard]] Number operator*(const Number& other) const noexcept;

    /**
     * @brief Division.
     *
     * @param other The Number to divide by.
     * @return A new Number holding the quotient.
     */
    [[nodiscard]] Number operator/(const Number& other) const noexcept;

    /**
     * @brief Modulo.
     *
     * @param other The Number to compute the remainder with.
     * @return A new Number holding the remainder.
     */
    [[nodiscard]] Number operator%(const Number& other) const noexcept;

// Compound assignment operators
public:
    /**
     * @brief Addition assignment.
     *
     * @param other The Number to add.
     * @return Reference to this instance after addition.
     */
    Number& operator+=(const Number& other) noexcept;

    /**
     * @brief Subtraction assignment.
     *
     * @param other The Number to subtract.
     * @return Reference to this instance after subtraction.
     */
    Number& operator-=(const Number& other) noexcept;

    /**
     * @brief Multiplication assignment.
     *
     * @param other The Number to multiply by.
     * @return Reference to this instance after multiplication.
     */
    Number& operator*=(const Number& other) noexcept;

    /**
     * @brief Division assignment.
     *
     * @param other The Number to divide by.
     * @return Reference to this instance after division.
     */
    Number& operator/=(const Number& other) noexcept;

    /**
     * @brief Modulo assignment.
     *
     * @param other The Number to compute the remainder with.
     * @return Reference to this instance after modulo.
     */
    Number& operator%=(const Number& other) noexcept;

// Increment and decrement operators
public:
    /**
     * @brief Prefix increment.
     *
     * @return Reference to this instance after incrementing.
     */
    Number& operator++() noexcept;

    /**
     * @brief Postfix increment.
     *
     * @return A copy of this instance before incrementing.
     */
    Number operator++(int) noexcept;

    /**
     * @brief Prefix decrement.
     *
     * @return Reference to this instance after decrementing.
     */
    Number& operator--() noexcept;

    /**
     * @brief Postfix decrement.
     *
     * @return A copy of this instance before decrementing.
     */
    Number operator--(int) noexcept;

// Comparison operators
public:
    /**
     * @brief Equality comparison.
     *
     * @param other The Number to compare against.
     * @return true if both instances hold the same value.
     */
    [[nodiscard]] bool operator==(const Number& other) const noexcept;

    /**
     * @brief Inequality comparison.
     *
     * @param other The Number to compare against.
     * @return true if the instances hold different values.
     */
    [[nodiscard]] bool operator!=(const Number& other) const noexcept;

    /**
     * @brief Less-than comparison.
     *
     * @param other The Number to compare against.
     * @return true if this instance is less than other.
     */
    [[nodiscard]] bool operator<(const Number& other) const noexcept;

    /**
     * @brief Less-than-or-equal comparison.
     *
     * @param other The Number to compare against.
     * @return true if this instance is less than or equal to other.
     */
    [[nodiscard]] bool operator<=(const Number& other) const noexcept;

    /**
     * @brief Greater-than comparison.
     *
     * @param other The Number to compare against.
     * @return true if this instance is greater than other.
     */
    [[nodiscard]] bool operator>(const Number& other) const noexcept;

    /**
     * @brief Greater-than-or-equal comparison.
     *
     * @param other The Number to compare against.
     * @return true if this instance is greater than or equal to other.
     */
    [[nodiscard]] bool operator>=(const Number& other) const noexcept;

private:
    T m_value{};
};

// ---------------------------------------------------------------------------
// Implementations
// ---------------------------------------------------------------------------

template <Integral T>
Number<T>::Number() noexcept = default;

template <Integral T>
Number<T>::Number(T value) noexcept
    : m_value{value}
{
}

template <Integral T>
Number<T>::~Number() noexcept = default;

template <Integral T>
PrimitiveType Number<T>::get_type() const noexcept { return PrimitiveType::Number; }

template <Integral T>
T Number<T>::get_value() const noexcept { return m_value; }

template <Integral T>
void Number<T>::set_value(T value) noexcept { m_value = value; }

template <Integral T>
Number<T>::operator T() const noexcept { return m_value; }

template <Integral T>
Number<T> Number<T>::operator+(const Number& other) const noexcept { return Number{static_cast<T>(m_value + other.m_value)}; }

template <Integral T>
Number<T> Number<T>::operator-(const Number& other) const noexcept { return Number{static_cast<T>(m_value - other.m_value)}; }

template <Integral T>
Number<T> Number<T>::operator*(const Number& other) const noexcept { return Number{static_cast<T>(m_value * other.m_value)}; }

template <Integral T>
Number<T> Number<T>::operator/(const Number& other) const noexcept { return Number{static_cast<T>(m_value / other.m_value)}; }

template <Integral T>
Number<T> Number<T>::operator%(const Number& other) const noexcept { return Number{static_cast<T>(m_value % other.m_value)}; }

template <Integral T>
Number<T>& Number<T>::operator+=(const Number& other) noexcept { m_value += other.m_value; return *this; }

template <Integral T>
Number<T>& Number<T>::operator-=(const Number& other) noexcept { m_value -= other.m_value; return *this; }

template <Integral T>
Number<T>& Number<T>::operator*=(const Number& other) noexcept { m_value *= other.m_value; return *this; }

template <Integral T>
Number<T>& Number<T>::operator/=(const Number& other) noexcept { m_value /= other.m_value; return *this; }

template <Integral T>
Number<T>& Number<T>::operator%=(const Number& other) noexcept { m_value %= other.m_value; return *this; }

template <Integral T>
Number<T>& Number<T>::operator++() noexcept { ++m_value; return *this; }

template <Integral T>
Number<T> Number<T>::operator++(int) noexcept { Number copy{m_value}; ++m_value; return copy; }

template <Integral T>
Number<T>& Number<T>::operator--() noexcept { --m_value; return *this; }

template <Integral T>
Number<T> Number<T>::operator--(int) noexcept { Number copy{m_value}; --m_value; return copy; }

template <Integral T>
bool Number<T>::operator==(const Number& other) const noexcept { return m_value == other.m_value; }

template <Integral T>
bool Number<T>::operator!=(const Number& other) const noexcept { return m_value != other.m_value; }

template <Integral T>
bool Number<T>::operator<(const Number& other) const noexcept { return m_value < other.m_value; }

template <Integral T>
bool Number<T>::operator<=(const Number& other) const noexcept { return m_value <= other.m_value; }

template <Integral T>
bool Number<T>::operator>(const Number& other) const noexcept { return m_value > other.m_value; }

template <Integral T>
bool Number<T>::operator>=(const Number& other) const noexcept { return m_value >= other.m_value; }

} // namespace Softloq::WHATWG::Infra

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_NUMBER_HPP
