/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/UInt64/UInt64.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This file provides the explicit instantiation of Number<std::uint64_t> for the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file provides the explicit instantiation of Number<std::uint64_t>, pre-compiling it
 * into the library binary and suppressing redundant per-TU instantiation for consumers
 * that include UInt64.hpp.
 */

#include <Softloq/WHATWG/Infra/API-Library/Precompiled.pch>
#include <Softloq/WHATWG/Infra/Primitive/Number/UInt64/UInt64.hpp>

namespace Softloq::WHATWG::Infra
{

template class Number<std::uint64_t>;

} // namespace Softloq::WHATWG::Infra
