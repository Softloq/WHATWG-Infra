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

#include "Softloq/WHATWG/Infra/API-Library/Macro.hpp"
#include "Softloq/WHATWG/Infra/Primitives/Primitive.hpp"

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
    SOFTLOQ_WHATWG_INFRA_API Boolean() noexcept;
    SOFTLOQ_WHATWG_INFRA_API explicit Boolean(bool value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~Boolean() noexcept;

// Primitive interface
public:
    /**
     * @brief Get the type of the primitive.
     *
     * @return The type of the primitive, which is PrimitiveType::Boolean.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API PrimitiveType get_type() const noexcept override;

// Accessors
public:
    /**
     * @brief Get the underlying boolean value.
     *
     * @return The stored boolean value.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool get_value() const noexcept;

    /**
     * @brief Set the underlying boolean value.
     *
     * @param value The new boolean value to store.
     */
    SOFTLOQ_WHATWG_INFRA_API void set_value(bool value) noexcept;

// Conversion
public:
    /**
     * @brief Explicit conversion to bool.
     *
     * @return The stored boolean value.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API explicit operator bool() const noexcept;

// Operators
public:
    /**
     * @brief Logical negation.
     *
     * @return A new Boolean whose value is the logical negation of this instance.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API Boolean operator!() const noexcept;

    /**
     * @brief Equality comparison.
     *
     * @param other The Boolean to compare against.
     * @return true if both instances hold the same value.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool operator==(const Boolean& other) const noexcept;

    /**
     * @brief Inequality comparison.
     *
     * @param other The Boolean to compare against.
     * @return true if the instances hold different values.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool operator!=(const Boolean& other) const noexcept;

private:
    bool m_value{false};
};

} // namespace Softloq::WHATWG::Infra

#include "Softloq/WHATWG/Infra/Primitive/Boolean/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/Boolean/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOLEAN_BOOLEAN_HPP
