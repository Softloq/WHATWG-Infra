/**
 * @file Softloq/WHATWG/Infra/Primitive/Byte/Byte.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the Byte type for the WHATWG Infra library, representing a byte value in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the Byte type for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_BYTE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_BYTE_HPP

#include "Softloq/WHATWG/Infra/API-Library/Macro.hpp"
#include "Softloq/WHATWG/Infra/Primitive/Primitive.hpp"
#include <cstdint>

namespace Softloq::WHATWG::Infra
{

/**
 * @brief The Byte type represents a byte value in the context of web APIs.
 *
 * The Byte type represents an integer in the range [0, 255], as defined by the WHATWG Infra
 * specification. It provides value construction, mutation, equality comparison,
 * and explicit conversion to the underlying std::uint8_t type.
 */
class Byte final : public Primitive
{
// Constructors and destructor
public:
    SOFTLOQ_WHATWG_INFRA_API Byte() noexcept;
    SOFTLOQ_WHATWG_INFRA_API explicit Byte(std::uint8_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~Byte() noexcept;

// Primitive interface
public:
    /**
     * @brief Get the type of the primitive.
     *
     * @return The type of the primitive, which is PrimitiveType::Byte.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API PrimitiveType get_type() const noexcept override;

// Accessors
public:
    /**
     * @brief Get the underlying byte value.
     *
     * @return The stored byte value as std::uint8_t.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API std::uint8_t get_value() const noexcept;

    /**
     * @brief Set the underlying byte value.
     *
     * @param value The new byte value to store.
     */
    SOFTLOQ_WHATWG_INFRA_API void set_value(std::uint8_t value) noexcept;

// Conversion
public:
    /**
     * @brief Explicit conversion to std::uint8_t.
     *
     * @return The stored byte value.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API explicit operator std::uint8_t() const noexcept;

// Operators
public:
    /**
     * @brief Equality comparison.
     *
     * @param other The Byte to compare against.
     * @return true if both instances hold the same value.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool operator==(const Byte& other) const noexcept;

    /**
     * @brief Inequality comparison.
     *
     * @param other The Byte to compare against.
     * @return true if the instances hold different values.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool operator!=(const Byte& other) const noexcept;

private:
    std::uint8_t m_value{0};
};

} // namespace Softloq::WHATWG::Infra

#include "Softloq/WHATWG/Infra/Primitive/Byte/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/Byte/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_BYTE_HPP
