#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOLEAN_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOLEAN_HPP

#include <Softloq/API.Softloq.WHATWG.Infra.hpp>
#include <format>
#include <compare>

namespace Softloq::WHATWG::Infra::Primitive {

/**
 * @brief The boolean primitive.
 */
class SOFTLOQ_WHATWG_INFRA_API Boolean {
public:
  using value_type = bool;

  constexpr Boolean() noexcept : m_value(false) {}
  constexpr Boolean(bool value) noexcept : m_value(value) {}

  constexpr value_type value() const noexcept { return m_value; }
  constexpr operator bool() const noexcept { return m_value; }

  constexpr auto operator<=>(const Boolean&) const = default;

private:
  value_type m_value;
};

} // namespace Softloq::WHATWG::Infra::Primitive

template <>
struct std::formatter<Softloq::WHATWG::Infra::Primitive::Boolean> : std::formatter<bool> {
  auto format(Softloq::WHATWG::Infra::Primitive::Boolean b, std::format_context& ctx) const {
    return std::formatter<bool>::format(b.value(), ctx);
  }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BOOLEAN_HPP
