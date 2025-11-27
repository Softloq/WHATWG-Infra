#include <Softloq/WHATWG/Infra/Primitive/CodePoint.hpp>

namespace Softloq::WHATWG::Infra::Primitive {

// Surrogate detection

bool is_leading_surrogate(code_point cp) noexcept {
  // Leading surrogate: U+D800 to U+DBFF, inclusive
  return cp >= 0xD800 && cp <= 0xDBFF;
}

bool is_trailing_surrogate(code_point cp) noexcept {
  // Trailing surrogate: U+DC00 to U+DFFF, inclusive
  return cp >= 0xDC00 && cp <= 0xDFFF;
}

bool is_surrogate(code_point cp) noexcept {
  // A surrogate is a leading surrogate or a trailing surrogate
  return is_leading_surrogate(cp) || is_trailing_surrogate(cp);
}

bool is_scalar_value(code_point cp) noexcept {
  // A scalar value is a code point that is not a surrogate
  return !is_surrogate(cp);
}

bool is_noncharacter(code_point cp) noexcept {
  // Noncharacter is in range U+FDD0 to U+FDEF, inclusive
  if (cp >= 0xFDD0 && cp <= 0xFDEF) {
    return true;
  }
  
  // Or ends with FFFE or FFFF in any plane
  // U+FFFE, U+FFFF, U+1FFFE, U+1FFFF, ..., U+10FFFE, U+10FFFF
  if ((cp & 0xFFFE) == 0xFFFE) {
    return true;
  }
  
  return false;
}

// ASCII classification

bool is_ascii_code_point(code_point cp) noexcept {
  // ASCII code point: U+0000 NULL to U+007F DELETE, inclusive
  return cp <= 0x007F;
}

bool is_ascii_tab_or_newline(code_point cp) noexcept {
  // U+0009 TAB, U+000A LF, or U+000D CR
  return cp == 0x0009 || cp == 0x000A || cp == 0x000D;
}

bool is_ascii_whitespace(code_point cp) noexcept {
  // U+0009 TAB, U+000A LF, U+000C FF, U+000D CR, or U+0020 SPACE
  return cp == 0x0009 || cp == 0x000A || cp == 0x000C || 
         cp == 0x000D || cp == 0x0020;
}

// Control characters

bool is_c0_control(code_point cp) noexcept {
  // C0 control: U+0000 NULL to U+001F INFORMATION SEPARATOR ONE, inclusive
  return cp <= 0x001F;
}

bool is_c0_control_or_space(code_point cp) noexcept {
  // A C0 control or U+0020 SPACE
  return is_c0_control(cp) || cp == 0x0020;
}

bool is_control(code_point cp) noexcept {
  // A C0 control or a code point in the range U+007F DELETE to
  // U+009F APPLICATION PROGRAM COMMAND, inclusive
  return is_c0_control(cp) || (cp >= 0x007F && cp <= 0x009F);
}

// Digit classification

bool is_ascii_digit(code_point cp) noexcept {
  // ASCII digit: U+0030 (0) to U+0039 (9), inclusive
  return cp >= 0x0030 && cp <= 0x0039;
}

bool is_ascii_upper_hex_digit(code_point cp) noexcept {
  // ASCII digit or U+0041 (A) to U+0046 (F), inclusive
  return is_ascii_digit(cp) || (cp >= 0x0041 && cp <= 0x0046);
}

bool is_ascii_lower_hex_digit(code_point cp) noexcept {
  // ASCII digit or U+0061 (a) to U+0066 (f), inclusive
  return is_ascii_digit(cp) || (cp >= 0x0061 && cp <= 0x0066);
}

bool is_ascii_hex_digit(code_point cp) noexcept {
  // ASCII upper hex digit or ASCII lower hex digit
  return is_ascii_upper_hex_digit(cp) || is_ascii_lower_hex_digit(cp);
}

// Alpha classification

bool is_ascii_upper_alpha(code_point cp) noexcept {
  // U+0041 (A) to U+005A (Z), inclusive
  return cp >= 0x0041 && cp <= 0x005A;
}

bool is_ascii_lower_alpha(code_point cp) noexcept {
  // U+0061 (a) to U+007A (z), inclusive
  return cp >= 0x0061 && cp <= 0x007A;
}

bool is_ascii_alpha(code_point cp) noexcept {
  // ASCII upper alpha or ASCII lower alpha
  return is_ascii_upper_alpha(cp) || is_ascii_lower_alpha(cp);
}

bool is_ascii_alphanumeric(code_point cp) noexcept {
  // ASCII digit or ASCII alpha
  return is_ascii_digit(cp) || is_ascii_alpha(cp);
}

} // namespace Softloq::WHATWG::Infra::Primitive
