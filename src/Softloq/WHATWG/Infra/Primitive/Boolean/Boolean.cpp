/**
 * @file Softloq/WHATWG/Infra/Primitive/Boolean/Boolean.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This implements the Boolean type for the WHATWG Infra library, representing a boolean value in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This implements the Boolean type for the WHATWG Infra library.
 *
 * NOTE: This is a skeleton implementation. All methods are stubs that do not yet
 * produce correct results. Tests are expected to fail at this stage.
 */

#include <Softloq/WHATWG/Infra/API-Library/Precompiled.pch>
#include <Softloq/WHATWG/Infra/Primitive/Boolean/Boolean.hpp>

namespace Softloq::WHATWG::Infra
{

Boolean::Boolean() noexcept = default;
Boolean::Boolean(bool) noexcept {}
Boolean::~Boolean() noexcept = default;

PrimitiveType Boolean::get_type() const noexcept
{
    return PrimitiveType::Invalid;
}

bool Boolean::get_value() const noexcept
{
    return false;
}

void Boolean::set_value(bool) noexcept {}

Boolean::operator bool() const noexcept
{
    return false;
}

Boolean Boolean::operator!() const noexcept
{
    return Boolean{};
}

bool Boolean::operator==(const Boolean&) const noexcept
{
    return false;
}

bool Boolean::operator!=(const Boolean&) const noexcept
{
    return false;
}

} // namespace Softloq::WHATWG::Infra
