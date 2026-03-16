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

#include "Softloq/WHATWG/Infra/API-Library/Macro.hpp"
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
    SOFTLOQ_WHATWG_INFRA_API Null() noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~Null() noexcept;

public:
    /**
     * @brief Get the type of the primitive.
     * 
     * @return The type of the primitive, which is PrimitiveType::Null.
     */
    SOFTLOQ_WHATWG_INFRA_API [[nodiscard]] PrimitiveType get_type() const noexcept override;

// Delete copy and move constructors and assignment operators
public:
    Null(const Null&) = delete;
    Null(Null&&) = delete;
    Null& operator=(const Null&) = delete;
    Null& operator=(Null&&) = delete;
};

} // namespace Softloq::WHATWG::Infra

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_NULL_HPP