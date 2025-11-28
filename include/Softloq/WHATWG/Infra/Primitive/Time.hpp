#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_TIME_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_TIME_HPP

#include <Softloq/API.Softloq.WHATWG.Infra.hpp>
#include <chrono>
#include <format>
#include <compare>

namespace Softloq::WHATWG::Infra::Primitive {

/**
 * @brief A moment is a point in time.
 * 
 * Represented as a std::chrono::system_clock::time_point.
 */
class SOFTLOQ_WHATWG_INFRA_API Moment {
public:
  using value_type = std::chrono::system_clock::time_point;

  Moment() = default;
  Moment(value_type value) : m_value(value) {}

  value_type value() const noexcept { return m_value; }
  
  auto operator<=>(const Moment&) const = default;

private:
  value_type m_value;
};

/**
 * @brief A duration is a length of time.
 * 
 * Represented as std::chrono::duration<double> (seconds).
 */
class SOFTLOQ_WHATWG_INFRA_API Duration {
public:
  using value_type = std::chrono::duration<double>;

  Duration() = default;
  Duration(value_type value) : m_value(value) {}
  template <typename Rep, typename Period>
  Duration(std::chrono::duration<Rep, Period> d) : m_value(d) {}

  value_type value() const noexcept { return m_value; }
  
  auto operator<=>(const Duration&) const = default;

private:
  value_type m_value;
};

} // namespace Softloq::WHATWG::Infra::Primitive

template <>
struct std::formatter<Softloq::WHATWG::Infra::Primitive::Moment> {
  constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

  auto format(const Softloq::WHATWG::Infra::Primitive::Moment& m, std::format_context& ctx) const {
    // Format as ISO 8601 if possible, or just a simple representation
    // C++20 has std::chrono::format but support might vary.
    // We'll use a simple fallback if needed, but let's try to use std::format with chrono
    // Note: MSVC C++20 supports chrono formatting.
    return std::format_to(ctx.out(), "{}", m.value());
  }
};

template <>
struct std::formatter<Softloq::WHATWG::Infra::Primitive::Duration> {
  constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

  auto format(const Softloq::WHATWG::Infra::Primitive::Duration& d, std::format_context& ctx) const {
    return std::format_to(ctx.out(), "{}s", d.value().count());
  }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_TIME_HPP
