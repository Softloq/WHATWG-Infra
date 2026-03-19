/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/Int64/Int64.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This file provides the explicit instantiation of Number<std::int64_t> for the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file provides the explicit instantiation of Number<std::int64_t>, pre-compiling it
 * into the library binary and suppressing redundant per-TU instantiation for consumers
 * that include Int64.hpp.
 */

#include <Softloq/WHATWG/Infra/API-Library/Precompiled.pch>
#include <Softloq/WHATWG/Infra/Primitive/Number/Int64/Int64.hpp>

namespace Softloq::WHATWG::Infra
{

template class Number<std::int64_t>;

} // namespace Softloq::WHATWG::Infra
