/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/Number.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This file provides explicit instantiations of the Number template for common integer types in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file provides explicit instantiations of the Number template for common integer types,
 * pre-compiling them into the library binary and suppressing redundant per-TU instantiation
 * for consumers that include Number.hpp.
 */

#include <Softloq/WHATWG/Infra/API-Library/Precompiled.pch>
#include <Softloq/WHATWG/Infra/Primitive/Number/Number.hpp>

namespace Softloq::WHATWG::Infra
{

template class Number<std::uint8_t>;
template class Number<std::uint16_t>;
template class Number<std::uint32_t>;
template class Number<std::uint64_t>;
template class Number<std::int8_t>;
template class Number<std::int16_t>;
template class Number<std::int32_t>;
template class Number<std::int64_t>;

} // namespace Softloq::WHATWG::Infra
