/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/UInt32/UInt32.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the UInt32 type for the WHATWG Infra library, representing a 32-bit unsigned integer in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the UInt32 type for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT32_UINT32_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT32_UINT32_HPP

#include "Softloq/WHATWG/Infra/API-Library/Macro.hpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/Number.hpp"
#include <cstdint>

namespace Softloq::WHATWG::Infra
{

extern template class SOFTLOQ_WHATWG_INFRA_API Number<std::uint32_t>;

/**
 * @brief Alias for a 32-bit unsigned integer Number.
 */
using UInt32 = Number<std::uint32_t>;

} // namespace Softloq::WHATWG::Infra

#include "Softloq/WHATWG/Infra/Primitive/Number/UInt32/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/UInt32/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT32_UINT32_HPP
