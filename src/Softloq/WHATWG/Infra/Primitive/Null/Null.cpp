/**
 * @file Softloq/WHATWG/Infra/Primitive/Null/Null.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This implements the Null type for the WHATWG Infra library, representing a null value in the context of web APIs.
 * 
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This implements the Null type for the WHATWG Infra library.
 */

#include <Softloq/WHATWG/Infra/API-Library/Precompiled.pch>
#include <Softloq/WHATWG/Infra/Primitive/Null/Null.hpp>

namespace Softloq::WHATWG::Infra
{

Null::Null() noexcept = default;
Null::~Null() noexcept = default;

PrimitiveType Null::get_type() const noexcept
{
    return PrimitiveType::Invalid;
}

} // namespace Softloq::WHATWG::Infra