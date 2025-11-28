#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_HPP

#include <Softloq/API.Softloq.WHATWG.Infra.hpp>
#include <format>
#include <compare>
#include <cstddef>

namespace Softloq::WHATWG::Infra::Primitive {

/**
 * @brief The null primitive.
 */
class SOFTLOQ_WHATWG_INFRA_API Null {
public:
  using value_type = std::nullptr_t;

  constexpr Null() noexcept = default;
  constexpr Null(std::nullptr_t) noexcept {}

  constexpr value_type value() const noexcept { return nullptr; }
  
  constexpr bool operator==(const Null&) const noexcept { return true; }
  constexpr bool operator==(std::nullptr_t) const noexcept { return true; }
  constexpr std::strong_ordering operator<=>(const Null&) const noexcept { return std::strong_ordering::equal; }
};

} // namespace Softloq::WHATWG::Infra::Primitive

template <>
struct std::formatter<Softloq::WHATWG::Infra::Primitive::Null> {
  constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

  auto format(Softloq::WHATWG::Infra::Primitive::Null, std::format_context& ctx) const {
    return std::format_to(ctx.out(), "null");
  }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NULL_HPP
