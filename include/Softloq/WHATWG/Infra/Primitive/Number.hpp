#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_HPP

#include <Softloq/API.Softloq.WHATWG.Infra.hpp>
#include <cstdint>
#include <format>
#include <compare>
#include <limits>
#include <iostream> // For ostream operators if needed, but we use std::format

namespace Softloq::WHATWG::Infra::Primitive {

// Helper macro to define integer wrappers
#define DEFINE_INTEGER_WRAPPER(ClassName, NativeType) \
class SOFTLOQ_WHATWG_INFRA_API ClassName { \
public: \
  using value_type = NativeType; \
  constexpr ClassName() noexcept : m_value(0) {} \
  constexpr ClassName(value_type value) noexcept : m_value(value) {} \
  constexpr value_type value() const noexcept { return m_value; } \
  constexpr operator value_type() const noexcept { return m_value; } \
  constexpr auto operator<=>(const ClassName&) const = default; \
private: \
  value_type m_value; \
};

// Unsigned Integers
DEFINE_INTEGER_WRAPPER(UInteger8, std::uint8_t)
DEFINE_INTEGER_WRAPPER(UInteger16, std::uint16_t)
DEFINE_INTEGER_WRAPPER(UInteger32, std::uint32_t)
DEFINE_INTEGER_WRAPPER(UInteger64, std::uint64_t)

// Signed Integers
DEFINE_INTEGER_WRAPPER(Integer8, std::int8_t)
DEFINE_INTEGER_WRAPPER(Integer16, std::int16_t)
DEFINE_INTEGER_WRAPPER(Integer32, std::int32_t)
DEFINE_INTEGER_WRAPPER(Integer64, std::int64_t)

#undef DEFINE_INTEGER_WRAPPER

// 128-bit Unsigned Integer
// Since standard C++ doesn't mandate __int128, and MSVC doesn't support it,
// we'll implement a basic struct.
class SOFTLOQ_WHATWG_INFRA_API UInteger128 {
public:
  constexpr UInteger128() noexcept : m_high(0), m_low(0) {}
  constexpr UInteger128(std::uint64_t low) noexcept : m_high(0), m_low(low) {}
  constexpr UInteger128(std::uint64_t high, std::uint64_t low) noexcept : m_high(high), m_low(low) {}

  constexpr std::uint64_t high() const noexcept { return m_high; }
  constexpr std::uint64_t low() const noexcept { return m_low; }

  friend constexpr bool operator==(const UInteger128& lhs, const UInteger128& rhs) noexcept {
    return lhs.m_high == rhs.m_high && lhs.m_low == rhs.m_low;
  }

  friend constexpr std::strong_ordering operator<=>(const UInteger128& lhs, const UInteger128& rhs) noexcept {
    if (auto cmp = lhs.m_high <=> rhs.m_high; cmp != 0) return cmp;
    return lhs.m_low <=> rhs.m_low;
  }

private:
  std::uint64_t m_high;
  std::uint64_t m_low;
};

} // namespace Softloq::WHATWG::Infra::Primitive

// Formatters
template <typename T>
struct std::formatter<T, std::enable_if_t<
  std::is_same_v<T, Softloq::WHATWG::Infra::Primitive::UInteger8> ||
  std::is_same_v<T, Softloq::WHATWG::Infra::Primitive::UInteger16> ||
  std::is_same_v<T, Softloq::WHATWG::Infra::Primitive::UInteger32> ||
  std::is_same_v<T, Softloq::WHATWG::Infra::Primitive::UInteger64> ||
  std::is_same_v<T, Softloq::WHATWG::Infra::Primitive::Integer8> ||
  std::is_same_v<T, Softloq::WHATWG::Infra::Primitive::Integer16> ||
  std::is_same_v<T, Softloq::WHATWG::Infra::Primitive::Integer32> ||
  std::is_same_v<T, Softloq::WHATWG::Infra::Primitive::Integer64>, char>> 
  : std::formatter<typename T::value_type> {
  
  auto format(const T& val, std::format_context& ctx) const {
    return std::formatter<typename T::value_type>::format(val.value(), ctx);
  }
};

template <>
struct std::formatter<Softloq::WHATWG::Infra::Primitive::UInteger128> {
  constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

  auto format(const Softloq::WHATWG::Infra::Primitive::UInteger128& val, std::format_context& ctx) const {
    // Simple hex formatting for 128-bit for now as decimal conversion is complex without a library
    // Or we can try to do decimal if needed, but hex is safer for a basic implementation.
    // Let's do Hex: 0xHIGH_LOW
    return std::format_to(ctx.out(), "0x{:016X}{:016X}", val.high(), val.low());
  }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_HPP
