/**
 * @file Softloq/WHATWG/Infra/Primitive/Boolean/Boolean.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the Boolean type for the WHATWG Infra library, representing a boolean value in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the Boolean type for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOLEAN_BOOLEAN_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOLEAN_BOOLEAN_HPP

#include "Softloq/WHATWG/Infra/Primitive/Primitive.hpp"

namespace Softloq::WHATWG::Infra
{

/**
 * @brief The Boolean type represents a boolean value in the context of web APIs.
 *
 * The Boolean type represents either true or false, as defined by the WHATWG Infra specification.
 * It provides value construction, mutation, logical negation, equality comparison,
 * and implicit conversion to the underlying bool type.
 */
class Boolean final : public Primitive
{
// Constructors and destructor
public:
    constexpr Boolean() noexcept = default;

    constexpr explicit Boolean(bool value) noexcept
        : m_value{value}
    {
    }

    constexpr ~Boolean() noexcept = default;

// Primitive interface
public:
    /**
     * @brief Get the type of the primitive.
     *
     * @return The type of the primitive, which is PrimitiveType::Boolean.
     */
    [[nodiscard]] constexpr PrimitiveType get_type() const noexcept override
    {
        return PrimitiveType::Boolean;
    }

// Accessors
public:
    /**
     * @brief Get the underlying boolean value.
     *
     * @return The stored boolean value.
     */
    [[nodiscard]] constexpr bool get_value() const noexcept
    {
        return m_value;
    }

    /**
     * @brief Set the underlying boolean value.
     *
     * @param value The new boolean value to store.
     */
    constexpr void set_value(bool value) noexcept
    {
        m_value = value;
    }

// Conversion
public:
    /**
     * @brief Explicit conversion to bool.
     *
     * @return The stored boolean value.
     */
    [[nodiscard]] constexpr explicit operator bool() const noexcept
    {
        return m_value;
    }

// Operators
public:
    /**
     * @brief Logical negation.
     *
     * @return A new Boolean whose value is the logical negation of this instance.
     */
    [[nodiscard]] constexpr Boolean operator!() const noexcept
    {
        return Boolean{!m_value};
    }

    /**
     * @brief Equality comparison.
     *
     * @param other The Boolean to compare against.
     * @return true if both instances hold the same value.
     */
    [[nodiscard]] constexpr bool operator==(const Boolean& other) const noexcept
    {
        return m_value == other.m_value;
    }

    /**
     * @brief Inequality comparison.
     *
     * @param other The Boolean to compare against.
     * @return true if the instances hold different values.
     */
    [[nodiscard]] constexpr bool operator!=(const Boolean& other) const noexcept
    {
        return m_value != other.m_value;
    }

private:
    bool m_value{false};
};

} // namespace Softloq::WHATWG::Infra

#include "Softloq/WHATWG/Infra/Primitive/Boolean/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/Boolean/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOLEAN_BOOLEAN_HPP
