/**
 * @file Softloq/WHATWG/Infra/Primitives/Primitive.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This implements the primitive abstract class for the WHATWG Infra library.
 * 
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This implements the primitive abstract class for the WHATWG Infra library.
 */

#include <Softloq/WHATWG/Infra/API-Library/Precompiled.pch>
#include <Softloq/WHATWG/Infra/Primitives/Primitive.hpp>

namespace Softloq::WHATWG::Infra
{

Primitive::Primitive() = default;
Primitive::~Primitive() = default;

PrimitiveType Primitive::get_type() const
{
    return PrimitiveType::Invalid;
}

} // namespace Softloq::WHATWG::Infra