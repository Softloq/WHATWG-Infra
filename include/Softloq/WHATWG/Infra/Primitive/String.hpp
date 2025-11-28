#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_STRING_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_STRING_HPP

#include <Softloq/API.Softloq.WHATWG.Infra.hpp>
#include <Softloq/WHATWG/Infra/Primitive/CodePoint.hpp>
#include <string>
#include <format>
#include <compare>
#include <iostream>

namespace Softloq::WHATWG::Infra::Primitive {

/**
 * @brief A string is a sequence of 16-bit unsigned integers (code units).
 * 
 * As per WHATWG Infra specification, a string is also known as a JavaScript string.
 * This is different from how Unicode defines "code unit" - it refers exclusively to
 * how Unicode defines it for Unicode 16-bit strings.
 * 
 * Note: We use std::u16string which is a sequence of char16_t (16-bit code units).
 */
class SOFTLOQ_WHATWG_INFRA_API String {
public:
  using value_type = std::u16string;

  String() = default;
  String(const char16_t* str) : m_value(str) {}
  String(const std::u16string& str) : m_value(str) {}
  String(std::u16string&& str) : m_value(std::move(str)) {}
  
  // Allow construction from u"" literals easily
  template <size_t N>
  String(const char16_t (&str)[N]) : m_value(str) {}

  const value_type& value() const noexcept { return m_value; }
  value_type& value() noexcept { return m_value; }

  // String-like interface
  auto begin() const noexcept { return m_value.begin(); }
  auto end() const noexcept { return m_value.end(); }
  auto begin() noexcept { return m_value.begin(); }
  auto end() noexcept { return m_value.end(); }
  auto size() const noexcept { return m_value.size(); }
  auto length() const noexcept { return m_value.length(); }
  bool empty() const noexcept { return m_value.empty(); }
  const char16_t& operator[](size_t index) const { return m_value[index]; }
  char16_t& operator[](size_t index) { return m_value[index]; }
  void push_back(char16_t c) { m_value.push_back(c); }
  
  String operator+(const String& other) const {
    return String(m_value + other.m_value);
  }

  bool operator==(const String& other) const = default;

  /**
   * @brief Check if this string is identical to another.
   */
  bool is_identical_to(const String& other) const noexcept;

  /**
   * @brief Check if this string is a code unit prefix of another.
   */
  bool is_code_unit_prefix(const String& input) const;

  /**
   * @brief Check if this string is a code unit suffix of another.
   */
  bool is_code_unit_suffix(const String& input) const;

  /**
   * @brief Get the code point length of the string.
   */
  size_t code_point_length() const;

  /**
   * @brief Check if the string is an ASCII string.
   */
  bool is_ascii_string() const;

  /**
   * @brief Check if the string is an isomorphic string.
   */
  bool is_isomorphic_string() const;

  /**
   * @brief Check if the string is a scalar value string.
   */
  bool is_scalar_value_string() const;

  /**
   * @brief Convert the string into a scalar value string.
   */
  String convert_to_scalar_value_string() const;

private:
  value_type m_value;
};

} // namespace Softloq::WHATWG::Infra::Primitive

// std::formatter specialization for String
template <>
struct std::formatter<Softloq::WHATWG::Infra::Primitive::String> {
  constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }

  auto format(const Softloq::WHATWG::Infra::Primitive::String& s, format_context& ctx) const {
    // Format as "..." (double quoted)
    // Note: std::format doesn't natively support char16_t string formatting to char output easily
    // We'll do a basic conversion for display purposes, replacing non-ASCII with ? or similar
    // or just printing code units if needed.
    // For now, let's try to convert to UTF-8 for display if possible, or just print ASCII chars
    
    auto out = ctx.out();
    out = std::format_to(out, "\"");
    
    for (char16_t c : s.value()) {
      if (c >= 0x20 && c <= 0x7E) {
        out = std::format_to(out, "{}", static_cast<char>(c));
      } else {
        // Escape non-printable/non-ASCII
        out = std::format_to(out, "\\u{:04X}", static_cast<uint16_t>(c));
      }
    }
    
    return std::format_to(out, "\"");
  }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_STRING_HPP
