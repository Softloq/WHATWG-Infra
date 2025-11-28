#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_HPP

#include <Softloq/API.Softloq.WHATWG.Infra.hpp>
#include <cstdint>
#include <format>
#include <compare>

namespace Softloq::WHATWG::Infra::Primitive {

/**
 * @brief A byte is a sequence of eight bits represented as an 8-bit unsigned integer.
 * 
 * As per WHATWG Infra specification, a byte is in the range 0x00 to 0xFF, inclusive.
 * A byte's value is its underlying number.
 */
class SOFTLOQ_WHATWG_INFRA_API Byte {
public:
  using value_type = std::uint8_t;

  constexpr Byte() noexcept : m_value(0) {}
  constexpr Byte(value_type value) noexcept : m_value(value) {}

  constexpr value_type value() const noexcept { return m_value; }
  constexpr operator value_type() const noexcept { return m_value; }

  constexpr auto operator<=>(const Byte&) const = default;

  /**
   * @brief Check if a byte is an ASCII byte.
   * 
   * An ASCII byte is a byte in the range 0x00 (NUL) to 0x7F (DEL), inclusive.
   * 
   * @return true if the byte is in the ASCII range, false otherwise
   */
  constexpr bool is_ascii() const noexcept {
    return m_value <= 0x7F;
  }

private:
  value_type m_value;
};

} // namespace Softloq::WHATWG::Infra::Primitive

// std::formatter specialization for Byte
template <>
struct std::formatter<Softloq::WHATWG::Infra::Primitive::Byte> : std::formatter<std::uint8_t> {
  auto format(Softloq::WHATWG::Infra::Primitive::Byte b, format_context& ctx) const {
    // Format as 0xHH (upper hex)
    return std::format_to(ctx.out(), "0x{:02X}", b.value());
  }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_HPP
