/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/Int32/Int32.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the Int32 type for the WHATWG Infra library, representing a 32-bit signed integer in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the Int32 type for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT32_INT32_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT32_INT32_HPP

#include "Softloq/WHATWG/Infra/Primitive/Number/Number.hpp"
#include <cstdint>

namespace Softloq::WHATWG::Infra
{

/**
 * @brief Alias for a 32-bit signed integer Number.
 */
using Int32 = Number<std::int32_t>;

} // namespace Softloq::WHATWG::Infra

#include "Softloq/WHATWG/Infra/Primitive/Number/Int32/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/Int32/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT32_INT32_HPP
