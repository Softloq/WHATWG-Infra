/**
 * @file inline/Softloq/WHATWG/Infra/Primitive/ByteSequence/OStream.inl
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This file defines the output stream operator for the ByteSequence primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file defines the output stream operator for the ByteSequence primitive type.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTESEQUENCE_OSTREAM_INL
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTESEQUENCE_OSTREAM_INL

#include "Softloq/WHATWG/Infra/Primitive/ByteSequence/ByteSequence.hpp"
#include <format>
#include <ostream>

inline std::ostream& operator<<(std::ostream& os, const Softloq::WHATWG::Infra::ByteSequence& value)
{
    return os << std::format("{}", value);
}

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTESEQUENCE_OSTREAM_INL
