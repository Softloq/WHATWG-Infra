/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/UInt8/UInt8.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the UInt8 type for the WHATWG Infra library, representing an 8-bit unsigned integer in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the UInt8 type for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT8_UINT8_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT8_UINT8_HPP

#include "Softloq/WHATWG/Infra/API-Library/Macro.hpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/Number.hpp"

namespace Softloq::WHATWG::Infra
{

extern template class SOFTLOQ_WHATWG_INFRA_API Number<std::uint8_t>;

/**
 * @brief Alias for an 8-bit unsigned integer Number.
 */
using UInt8 = Number<std::uint8_t>;

} // namespace Softloq::WHATWG::Infra

#include "Softloq/WHATWG/Infra/Primitive/Number/UInt8/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/UInt8/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT8_UINT8_HPP
