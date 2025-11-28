#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_SEQUENCE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_SEQUENCE_HPP

#include <Softloq/API.Softloq.WHATWG.Infra.hpp>
#include <Softloq/WHATWG/Infra/Primitive/Byte.hpp>
#include <string>
#include <vector>
#include <format>
#include <compare>
#include <initializer_list>

namespace Softloq::WHATWG::Infra::Primitive {

class String; // Forward declaration

/**
 * @brief A byte sequence is a sequence of bytes.
 * 
 * As per WHATWG Infra specification, a byte sequence is represented as a
 * space-separated sequence of bytes.
 */
class SOFTLOQ_WHATWG_INFRA_API ByteSequence {
public:
  using value_type = std::vector<Byte>;

  ByteSequence() = default;
  ByteSequence(std::initializer_list<Byte> init) : m_value(init) {}
  explicit ByteSequence(const value_type& value) : m_value(value) {}
  explicit ByteSequence(value_type&& value) : m_value(std::move(value)) {}

  const value_type& value() const noexcept { return m_value; }
  value_type& value() noexcept { return m_value; }

  // Vector-like interface
  auto begin() const noexcept { return m_value.begin(); }
  auto end() const noexcept { return m_value.end(); }
  auto begin() noexcept { return m_value.begin(); }
  auto end() noexcept { return m_value.end(); }
  auto size() const noexcept { return m_value.size(); }
  bool empty() const noexcept { return m_value.empty(); }
  const Byte& operator[](size_t index) const { return m_value[index]; }
  Byte& operator[](size_t index) { return m_value[index]; }
  void push_back(Byte b) { m_value.push_back(b); }

  bool operator==(const ByteSequence& other) const = default;

  /**
   * @brief Convert a byte sequence to lowercase.
   * 
   * To byte-lowercase a byte sequence, increase each byte it contains,
   * in the range 0x41 (A) to 0x5A (Z), inclusive, by 0x20.
   */
  ByteSequence lowercase() const;

  /**
   * @brief Convert a byte sequence to uppercase.
   * 
   * To byte-uppercase a byte sequence, subtract each byte it contains,
   * in the range 0x61 (a) to 0x7A (z), inclusive, by 0x20.
   */
  ByteSequence uppercase() const;

  /**
   * @brief Check if this byte sequence is a byte-case-insensitive match for another.
   */
  bool case_insensitive_match(const ByteSequence& other) const;

  /**
   * @brief Check if this byte sequence is a prefix of another.
   */
  bool is_prefix(const ByteSequence& input) const;

  /**
   * @brief Check if this byte sequence is byte less than another.
   */
  bool less_than(const ByteSequence& other) const;

  /**
   * @brief Isomorphic decode a byte sequence.
   */
  std::u16string isomorphic_decode() const;

private:
  value_type m_value;
};

} // namespace Softloq::WHATWG::Infra::Primitive

// std::formatter specialization for ByteSequence
template <>
struct std::formatter<Softloq::WHATWG::Infra::Primitive::ByteSequence> {
  constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }

  auto format(const Softloq::WHATWG::Infra::Primitive::ByteSequence& bs, format_context& ctx) const {
    auto out = ctx.out();
    bool first = true;
    for (const auto& b : bs) {
      if (!first) {
        out = std::format_to(out, " ");
      }
      out = std::format_to(out, "{}", b);
      first = false;
    }
    return out;
  }
};

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_SEQUENCE_HPP
