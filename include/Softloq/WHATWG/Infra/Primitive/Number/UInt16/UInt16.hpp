/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/UInt16/UInt16.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the UInt16 type for the WHATWG Infra library, representing a 16-bit unsigned integer in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the UInt16 type for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT16_UINT16_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT16_UINT16_HPP

#include "Softloq/WHATWG/Infra/API-Library/Macro.hpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/Number.hpp"
#include <cstdint>

namespace Softloq::WHATWG::Infra
{

extern template class SOFTLOQ_WHATWG_INFRA_API Number<std::uint16_t>;

/**
 * @brief Alias for a 16-bit unsigned integer Number.
 */
using UInt16 = Number<std::uint16_t>;

} // namespace Softloq::WHATWG::Infra

#include "Softloq/WHATWG/Infra/Primitive/Number/UInt16/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/UInt16/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT16_UINT16_HPP
