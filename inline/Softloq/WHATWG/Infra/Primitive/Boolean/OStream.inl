/**
 * @file include/Softloq/WHATWG/Infra/Primitive/Boolean/OStream.inl
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This file defines the output stream operator for the Boolean primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file defines the output stream operator for the Boolean primitive type, allowing it to be
 * printed to output streams. When the Boolean primitive is printed, it will be represented as
 * "true" or "false".
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOLEAN_OSTREAM_INL
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOLEAN_OSTREAM_INL

#include "Softloq/WHATWG/Infra/Primitive/Boolean/Boolean.hpp"
#include <ostream>

inline std::ostream& operator<<(std::ostream& os, const Softloq::WHATWG::Infra::Boolean& value)
{
    return os << (value.get_value() ? "true" : "false");
}

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOLEAN_OSTREAM_INL
