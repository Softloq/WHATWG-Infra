/**
 * @file Softloq/WHATWG/Infra/Primitives/Primitive.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the primitive abstract class for the WHATWG Infra library.
 * 
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the primitive abstract class for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVES_PRIMITIVE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVES_PRIMITIVE_HPP

#include "Softloq/WHATWG/Infra/API-Library/Macro.hpp"
#include "Softloq/WHATWG/Infra/Primitives/Type.hpp"

namespace Softloq::WHATWG::Infra
{

/**
 * @brief The Primitive class is an abstract base class for all primitive types in the WHATWG Infra library.
 * 
 * The Primitive class is an abstract base class for all primitive types in the WHATWG Infra library.
 * It provides a common interface for all primitive types and allows for polymorphic behavior.
 */
class Primitive
{
// Constructors and destructor
public:
    SOFTLOQ_WHATWG_INFRA_API Primitive();
    SOFTLOQ_WHATWG_INFRA_API virtual ~Primitive();

public:
    /**
     * @brief Get the type of the primitive.
     * 
     * @return The type of the primitive.
     */
    SOFTLOQ_WHATWG_INFRA_API virtual PrimitiveType get_type() const = 0;
};

} // namespace Softloq::WHATWG::Infra

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVES_PRIMITIVE_HPP