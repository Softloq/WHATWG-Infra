/**
 * @file Softloq/WHATWG/Infra/Primitive/Null/Null.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the Null type for the WHATWG Infra library, representing a null value in the context of web APIs.
 * 
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the Null type for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_NULL_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_NULL_HPP

#include "Softloq/WHATWG/Infra/Primitives/Primitive.hpp"

namespace Softloq::WHATWG::Infra
{

/**
 * @brief The Null type represents a null value in the context of web APIs.
 * 
 * The Null type represents a null value in the context of web APIs.
 * It is used to indicate the absence of a value or a null reference.
 */
class Null final : public Primitive
{
// Constructors and destructor
public:
    constexpr Null() noexcept = default;
    constexpr ~Null() noexcept = default;

public:
    /**
     * @brief Get the type of the primitive.
     * 
     * @return The type of the primitive, which is PrimitiveType::Null.
     */
    [[nodiscard]] constexpr PrimitiveType get_type() const noexcept override
    {
        return PrimitiveType::Null;
    }
};

} // namespace Softloq::WHATWG::Infra

#include "Softloq/WHATWG/Infra/Primitive/Null/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/Null/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_NULL_HPP