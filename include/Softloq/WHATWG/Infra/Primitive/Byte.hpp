#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_HPP

#include <Softloq/API.Softloq.WHATWG.Infra.hpp>
#include <cstdint>

namespace Softloq::WHATWG::Infra::Primitive {

/**
 * @brief A byte is a sequence of eight bits represented as an 8-bit unsigned integer.
 * 
 * As per WHATWG Infra specification, a byte is in the range 0x00 to 0xFF, inclusive.
 * A byte's value is its underlying number.
 */
using byte = std::uint8_t;

/**
 * @brief Check if a byte is an ASCII byte.
 * 
 * An ASCII byte is a byte in the range 0x00 (NUL) to 0x7F (DEL), inclusive.
 * 
 * @param b The byte to check
 * @return true if the byte is in the ASCII range, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_ascii_byte(byte b) noexcept;

} // namespace Softloq::WHATWG::Infra::Primitive

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_HPP
