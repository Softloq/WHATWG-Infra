/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/UInt128/UInt128.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This file provides the explicit instantiation of Number<uint128_t> for the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file provides the explicit instantiation of Number<uint128_t>, pre-compiling it
 * into the library binary and suppressing redundant per-TU instantiation for consumers
 * that include UInt128.hpp.
 */

#include <Softloq/WHATWG/Infra/API-Library/Precompiled.pch>
#include <Softloq/WHATWG/Infra/Primitive/Number/UInt128/UInt128.hpp>

namespace Softloq::WHATWG::Infra
{

template class Number<uint128_t>;

} // namespace Softloq::WHATWG::Infra
