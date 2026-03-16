/**
 * @file include/Softloq/WHATWG/Infra/Primitive/Null/OStream.inl
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This file defines the output stream operator for the Null primitive type in the WHATWG Infra library.
 * 
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file defines the output stream operator for the Null primitive type, allowing it to be printed to output streams.
 * When the Null primitive is printed, it will be represented as the string "null".
 */

#include "Softloq/WHATWG/Infra/Primitive/Null/Null.hpp"
#include <ostream>

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_OSTREAM_INL
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_OSTREAM_INL

inline std::ostream& operator<<(std::ostream& os, const Softloq::WHATWG::Infra::Null&) { return os << "null"; }

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_OSTREAM_INL