#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_POINT_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_POINT_HPP

#include <Softloq/API.Softloq.WHATWG.Infra.hpp>
#include <cstdint>
#include <format>
#include <compare>

namespace Softloq::WHATWG::Infra::Primitive {

/**
 * @brief A code point is a Unicode code point.
 * 
 * As per WHATWG Infra specification, a code point is represented as "U+" followed
 * by four-to-six ASCII upper hex digits, in the range U+0000 to U+10FFFF, inclusive.
 * A code point's value is its underlying number.
 */
class SOFTLOQ_WHATWG_INFRA_API CodePoint {
public:
  using value_type = char32_t;

  constexpr CodePoint() noexcept : m_value(0) {}
  constexpr CodePoint(value_type value) noexcept : m_value(value) {}

  constexpr value_type value() const noexcept { return m_value; }
  constexpr operator value_type() const noexcept { return m_value; }

  constexpr auto operator<=>(const CodePoint&) const = default;

  // Surrogate detection
  bool is_leading_surrogate() const noexcept;
  bool is_trailing_surrogate() const noexcept;
  bool is_surrogate() const noexcept;
  bool is_scalar_value() const noexcept;

  // Noncharacter detection
  bool is_noncharacter() const noexcept;

  // ASCII classification
  bool is_ascii() const noexcept;
  bool is_ascii_tab_or_newline() const noexcept;
  bool is_ascii_whitespace() const noexcept;

  // Control characters
  bool is_c0_control() const noexcept;
  bool is_c0_control_or_space() const noexcept;
  bool is_control() const noexcept;

  // Digit classification
  bool is_ascii_digit() const noexcept;
  bool is_ascii_upper_hex_digit() const noexcept;
  bool is_ascii_lower_hex_digit() const noexcept;
  bool is_ascii_hex_digit() const noexcept;

  // Alpha classification
  bool is_ascii_upper_alpha() const noexcept;
  bool is_ascii_lower_alpha() const noexcept;
  bool is_ascii_alpha() const noexcept;
  bool is_ascii_alphanumeric() const noexcept;

private:
  value_type m_value;
};

} // namespace Softloq::WHATWG::Infra::Primitive

// std::formatter specialization for CodePoint
template <>
struct std::formatter<Softloq::WHATWG::Infra::Primitive::CodePoint> : std::formatter<std::uint32_t> {
  auto format(Softloq::WHATWG::Infra::Primitive::CodePoint cp, format_context& ctx) const {
    // Format as U+HHHH (or more digits if needed)
    return std::format_to(ctx.out(), "U+{:04X}", static_cast<uint32_t>(cp.value()));
  }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_POINT_HPP
