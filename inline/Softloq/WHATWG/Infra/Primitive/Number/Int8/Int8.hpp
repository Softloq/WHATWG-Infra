/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/Int8/Int8.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the Int8 type for the WHATWG Infra library, representing an 8-bit signed integer in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the Int8 type for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT8_INT8_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT8_INT8_HPP

#include "Softloq/WHATWG/Infra/Primitive/Number/Number.hpp"
#include <cstdint>

namespace Softloq::WHATWG::Infra
{

/**
 * @brief Alias for an 8-bit signed integer Number.
 */
using Int8 = Number<std::int8_t>;

} // namespace Softloq::WHATWG::Infra

#include "Softloq/WHATWG/Infra/Primitive/Number/Int8/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/Int8/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT8_INT8_HPP
