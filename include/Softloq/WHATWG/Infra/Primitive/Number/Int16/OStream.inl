/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/Int16/OStream.inl
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Output stream operator for the Int16 primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file defines the output stream operator for the Int16 primitive type.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT16_OSTREAM_INL
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT16_OSTREAM_INL

#include "Softloq/WHATWG/Infra/Primitive/Number/Number.hpp"
#include <ostream>

inline std::ostream& operator<<(std::ostream& os, const Softloq::WHATWG::Infra::Number<std::int16_t>& value)
{
    return os << value.get_value();
}

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INT16_OSTREAM_INL
