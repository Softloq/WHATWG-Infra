#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_SINGLETON_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_SINGLETON_HPP

#include <Softloq/API.Softloq.WHATWG.Infra.hpp>
#include <format>
#include <compare>

namespace Softloq::WHATWG::Infra::Primitive {

// Helper macro for singletons
#define DEFINE_SINGLETON(ClassName, NameString) \
class SOFTLOQ_WHATWG_INFRA_API ClassName { \
public: \
  constexpr ClassName() noexcept = default; \
  constexpr bool operator==(const ClassName&) const noexcept { return true; } \
  constexpr std::strong_ordering operator<=>(const ClassName&) const noexcept { return std::strong_ordering::equal; } \
};

DEFINE_SINGLETON(Allowed, "allowed")
DEFINE_SINGLETON(Blocked, "blocked")
DEFINE_SINGLETON(Failure, "failure")
DEFINE_SINGLETON(Success, "success")

#undef DEFINE_SINGLETON

} // namespace Softloq::WHATWG::Infra::Primitive

// Formatters
template <> struct std::formatter<Softloq::WHATWG::Infra::Primitive::Allowed> {
  constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }
  auto format(Softloq::WHATWG::Infra::Primitive::Allowed, std::format_context& ctx) const { return std::format_to(ctx.out(), "allowed"); }
};

template <> struct std::formatter<Softloq::WHATWG::Infra::Primitive::Blocked> {
  constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }
  auto format(Softloq::WHATWG::Infra::Primitive::Blocked, std::format_context& ctx) const { return std::format_to(ctx.out(), "blocked"); }
};

template <> struct std::formatter<Softloq::WHATWG::Infra::Primitive::Failure> {
  constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }
  auto format(Softloq::WHATWG::Infra::Primitive::Failure, std::format_context& ctx) const { return std::format_to(ctx.out(), "failure"); }
};

template <> struct std::formatter<Softloq::WHATWG::Infra::Primitive::Success> {
  constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }
  auto format(Softloq::WHATWG::Infra::Primitive::Success, std::format_context& ctx) const { return std::format_to(ctx.out(), "success"); }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_SINGLETON_HPP
