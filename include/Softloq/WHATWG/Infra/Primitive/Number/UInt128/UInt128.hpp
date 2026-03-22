/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/UInt128/UInt128.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the UInt128 type for the WHATWG Infra library, representing 128-bit unsigned integer numeric values in the context of web APIs.
 * 
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the UInt128 type for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT128_UINT128_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT128_UINT128_HPP

#include "Softloq/WHATWG/Infra/API-Library/Macro.hpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/UInt128/uint128_t.hpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/Number.hpp"
#include <cstdint>

namespace Softloq::WHATWG::Infra
{

static_assert(IntegralConcept<uint128_t>, "uint128_t must be an integral type"); // Passes
extern template class SOFTLOQ_WHATWG_INFRA_API Number<uint128_t>;

/**
 * @brief Alias for a 128-bit unsigned integer Number.
 */
using UInt128 = Number<uint128_t>;

} // namespace Softloq::WHATWG::Infra

// #include "Softloq/WHATWG/Infra/Primitive/Number/UInt128/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/UInt128/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT128_UINT128_HPP