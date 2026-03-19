/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/Int64/Int64.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the Int64 type for the WHATWG Infra library, representing a 64-bit signed integer in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the Int64 type for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT64_INT64_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT64_INT64_HPP

#include "Softloq/WHATWG/Infra/API-Library/Macro.hpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/Number.hpp"

namespace Softloq::WHATWG::Infra
{

extern template class SOFTLOQ_WHATWG_INFRA_API Number<std::int64_t>;

/**
 * @brief Alias for a 64-bit signed integer Number.
 */
using Int64 = Number<std::int64_t>;

} // namespace Softloq::WHATWG::Infra

#include "Softloq/WHATWG/Infra/Primitive/Number/Int64/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/Number/Int64/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT64_INT64_HPP
