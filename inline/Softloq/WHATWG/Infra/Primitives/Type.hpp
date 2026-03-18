/**
 * @file Softloq/WHATWG/Infra/Primitives/Type.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the primitive types for the WHATWG Infra library.
 * 
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the primitive types for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVES_TYPE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVES_TYPE_HPP

namespace Softloq::WHATWG::Infra
{

/**
 * @brief The PrimitiveType enum represents the different primitive types in the WHATWG Infra library.
 * 
 * The PrimitiveType enum represents the different primitive types in the WHATWG Infra library.
 * Currently, it includes the Null type, which represents a null value in the context of web APIs.
 */
enum class PrimitiveType
{
    Invalid, // Adds testability.
    Null,
    Boolean
};

} // namespace Softloq::WHATWG::Infra

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVES_TYPE_HPP