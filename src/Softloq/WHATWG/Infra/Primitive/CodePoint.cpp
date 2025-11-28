#include <Softloq/WHATWG/Infra/Primitive/CodePoint.hpp>

namespace Softloq::WHATWG::Infra::Primitive {

// Surrogate detection

bool CodePoint::is_leading_surrogate() const noexcept {
  // Leading surrogate: U+D800 to U+DBFF, inclusive
  return m_value >= 0xD800 && m_value <= 0xDBFF;
}

bool CodePoint::is_trailing_surrogate() const noexcept {
  // Trailing surrogate: U+DC00 to U+DFFF, inclusive
  return m_value >= 0xDC00 && m_value <= 0xDFFF;
}

bool CodePoint::is_surrogate() const noexcept {
  // A surrogate is a leading surrogate or a trailing surrogate
  return is_leading_surrogate() || is_trailing_surrogate();
}

bool CodePoint::is_scalar_value() const noexcept {
  // A scalar value is a code point that is not a surrogate
  return !is_surrogate();
}

bool CodePoint::is_noncharacter() const noexcept {
  // Noncharacter is in range U+FDD0 to U+FDEF, inclusive
  if (m_value >= 0xFDD0 && m_value <= 0xFDEF) {
    return true;
  }
  
  // Or ends with FFFE or FFFF in any plane
  // U+FFFE, U+FFFF, U+1FFFE, U+1FFFF, ..., U+10FFFE, U+10FFFF
  if ((m_value & 0xFFFE) == 0xFFFE) {
    return true;
  }
  
  return false;
}

// ASCII classification

bool CodePoint::is_ascii() const noexcept {
  // ASCII code point: U+0000 NULL to U+007F DELETE, inclusive
  return m_value <= 0x007F;
}

bool CodePoint::is_ascii_tab_or_newline() const noexcept {
  // U+0009 TAB, U+000A LF, or U+000D CR
  return m_value == 0x0009 || m_value == 0x000A || m_value == 0x000D;
}

bool CodePoint::is_ascii_whitespace() const noexcept {
  // U+0009 TAB, U+000A LF, U+000C FF, U+000D CR, or U+0020 SPACE
  return m_value == 0x0009 || m_value == 0x000A || m_value == 0x000C || 
         m_value == 0x000D || m_value == 0x0020;
}

// Control characters

bool CodePoint::is_c0_control() const noexcept {
  // C0 control: U+0000 NULL to U+001F INFORMATION SEPARATOR ONE, inclusive
  return m_value <= 0x001F;
}

bool CodePoint::is_c0_control_or_space() const noexcept {
  // A C0 control or U+0020 SPACE
  return is_c0_control() || m_value == 0x0020;
}

bool CodePoint::is_control() const noexcept {
  // A C0 control or a code point in the range U+007F DELETE to
  // U+009F APPLICATION PROGRAM COMMAND, inclusive
  return is_c0_control() || (m_value >= 0x007F && m_value <= 0x009F);
}

// Digit classification

bool CodePoint::is_ascii_digit() const noexcept {
  // ASCII digit: U+0030 (0) to U+0039 (9), inclusive
  return m_value >= 0x0030 && m_value <= 0x0039;
}

bool CodePoint::is_ascii_upper_hex_digit() const noexcept {
  // ASCII digit or U+0041 (A) to U+0046 (F), inclusive
  return is_ascii_digit() || (m_value >= 0x0041 && m_value <= 0x0046);
}

bool CodePoint::is_ascii_lower_hex_digit() const noexcept {
  // ASCII digit or U+0061 (a) to U+0066 (f), inclusive
  return is_ascii_digit() || (m_value >= 0x0061 && m_value <= 0x0066);
}

bool CodePoint::is_ascii_hex_digit() const noexcept {
  // ASCII upper hex digit or ASCII lower hex digit
  return is_ascii_upper_hex_digit() || is_ascii_lower_hex_digit();
}

// Alpha classification

bool CodePoint::is_ascii_upper_alpha() const noexcept {
  // U+0041 (A) to U+005A (Z), inclusive
  return m_value >= 0x0041 && m_value <= 0x005A;
}

bool CodePoint::is_ascii_lower_alpha() const noexcept {
  // U+0061 (a) to U+007A (z), inclusive
  return m_value >= 0x0061 && m_value <= 0x007A;
}

bool CodePoint::is_ascii_alpha() const noexcept {
  // ASCII upper alpha or ASCII lower alpha
  return is_ascii_upper_alpha() || is_ascii_lower_alpha();
}

bool CodePoint::is_ascii_alphanumeric() const noexcept {
  // ASCII digit or ASCII alpha
  return is_ascii_digit() || is_ascii_alpha();
}

} // namespace Softloq::WHATWG::Infra::Primitive
