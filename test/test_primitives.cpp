#include <Softloq/WHATWG/Infra/Primitives.hpp>
#include <cassert>
#include <iostream>
#include <vector>

using namespace Softloq::WHATWG::Infra::Primitive;

void test_byte() {
  std::cout << "Testing Byte primitives..." << std::endl;
  
  // is_ascii_byte
  assert(is_ascii_byte(0x00) == true);
  assert(is_ascii_byte(0x7F) == true);
  assert(is_ascii_byte(0x80) == false);
  assert(is_ascii_byte(0xFF) == false);
  
  std::cout << "✓ Byte tests passed" << std::endl;
}

void test_byte_sequence() {
  std::cout << "Testing ByteSequence primitives..." << std::endl;
  
  byte_sequence seq1 = {0x48, 0x49}; // "HI"
  byte_sequence seq2 = {0x68, 0x69}; // "hi"
  
  // byte_lowercase
  byte_sequence lower = byte_lowercase(seq1);
  assert(lower.size() == 2);
  assert(lower[0] == 0x68);
  assert(lower[1] == 0x69);
  
  // byte_uppercase
  byte_sequence upper = byte_uppercase(seq2);
  assert(upper.size() == 2);
  assert(upper[0] == 0x48);
  assert(upper[1] == 0x49);
  
  // byte_case_insensitive_match
  assert(byte_case_insensitive_match(seq1, seq2) == true);
  assert(byte_case_insensitive_match(seq1, {0x48, 0x49}) == true);
  assert(byte_case_insensitive_match(seq1, {0x48, 0x50}) == false);
  
  // is_prefix
  byte_sequence prefix = {0x48};
  assert(is_prefix(prefix, seq1) == true);
  assert(is_prefix(seq1, seq1) == true);
  assert(is_prefix(seq1, prefix) == false);
  
  // byte_less_than
  byte_sequence a = {0x01, 0x02};
  byte_sequence b = {0x01, 0x03};
  assert(byte_less_than(a, b) == true);
  assert(byte_less_than(b, a) == false);
  assert(byte_less_than(a, a) == false);
  
  // isomorphic_decode
  std::u16string decoded = isomorphic_decode(seq1);
  assert(decoded.size() == 2);
  assert(decoded[0] == 0x0048);
  assert(decoded[1] == 0x0049);
  
  std::cout << "✓ ByteSequence tests passed" << std::endl;
}

void test_code_point() {
  std::cout << "Testing CodePoint primitives..." << std::endl;
  
  // Surrogates
  assert(is_leading_surrogate(0xD800) == true);
  assert(is_leading_surrogate(0xDBFF) == true);
  assert(is_leading_surrogate(0xD7FF) == false);
  assert(is_leading_surrogate(0xDC00) == false);
  
  assert(is_trailing_surrogate(0xDC00) == true);
  assert(is_trailing_surrogate(0xDFFF) == true);
  assert(is_trailing_surrogate(0xDBFF) == false);
  assert(is_trailing_surrogate(0xE000) == false);
  
  assert(is_surrogate(0xD800) == true);
  assert(is_surrogate(0xDFFF) == true);
  assert(is_surrogate(0x0041) == false);
  
  assert(is_scalar_value(0x0041) == true);
  assert(is_scalar_value(0xD800) == false);
  
  // Noncharacters
  assert(is_noncharacter(0xFDD0) == true);
  assert(is_noncharacter(0xFDEF) == true);
  assert(is_noncharacter(0xFFFE) == true);
  assert(is_noncharacter(0xFFFF) == true);
  assert(is_noncharacter(0x10FFFF) == true);
  assert(is_noncharacter(0x0041) == false);
  
  // ASCII classification
  assert(is_ascii_code_point(0x0000) == true);
  assert(is_ascii_code_point(0x007F) == true);
  assert(is_ascii_code_point(0x0080) == false);
  
  assert(is_ascii_tab_or_newline(0x0009) == true); // TAB
  assert(is_ascii_tab_or_newline(0x000A) == true); // LF
  assert(is_ascii_tab_or_newline(0x000D) == true); // CR
  assert(is_ascii_tab_or_newline(0x0020) == false); // SPACE
  
  assert(is_ascii_whitespace(0x0020) == true);
  assert(is_ascii_whitespace(0x000C) == true); // FF
  assert(is_ascii_whitespace(0x0041) == false);
  
  // Control characters
  assert(is_c0_control(0x0000) == true);
  assert(is_c0_control(0x001F) == true);
  assert(is_c0_control(0x0020) == false);
  
  assert(is_c0_control_or_space(0x0020) == true);
  
  assert(is_control(0x007F) == true); // DEL
  assert(is_control(0x009F) == true);
  assert(is_control(0x0041) == false);
  
  // Digits and hex
  assert(is_ascii_digit(0x0030) == true); // 0
  assert(is_ascii_digit(0x0039) == true); // 9
  assert(is_ascii_digit(0x002F) == false);
  
  assert(is_ascii_upper_hex_digit(0x0041) == true); // A
  assert(is_ascii_upper_hex_digit(0x0046) == true); // F
  assert(is_ascii_upper_hex_digit(0x0061) == false); // a
  
  assert(is_ascii_lower_hex_digit(0x0061) == true); // a
  assert(is_ascii_lower_hex_digit(0x0066) == true); // f
  assert(is_ascii_lower_hex_digit(0x0041) == false); // A
  
  assert(is_ascii_hex_digit(0x0041) == true);
  assert(is_ascii_hex_digit(0x0061) == true);
  assert(is_ascii_hex_digit(0x0030) == true);
  assert(is_ascii_hex_digit(0x0047) == false); // G
  
  // Alpha
  assert(is_ascii_upper_alpha(0x0041) == true);
  assert(is_ascii_upper_alpha(0x005A) == true);
  assert(is_ascii_lower_alpha(0x0061) == true);
  assert(is_ascii_lower_alpha(0x007A) == true);
  
  assert(is_ascii_alpha(0x0041) == true);
  assert(is_ascii_alpha(0x0061) == true);
  assert(is_ascii_alpha(0x0030) == false);
  
  assert(is_ascii_alphanumeric(0x0041) == true);
  assert(is_ascii_alphanumeric(0x0030) == true);
  assert(is_ascii_alphanumeric(0x0020) == false);
  
  std::cout << "✓ CodePoint tests passed" << std::endl;
}

void test_string() {
  std::cout << "Testing String primitives..." << std::endl;
  
  string s1 = u"Hello";
  string s2 = u"Hello";
  string s3 = u"World";
  
  // string_is_identical
  assert(string_is_identical(s1, s2) == true);
  assert(string_is_identical(s1, s3) == false);
  
  // Prefix/Suffix
  string prefix = u"He";
  string suffix = u"lo";
  assert(is_code_unit_prefix(prefix, s1) == true);
  assert(is_code_unit_prefix(suffix, s1) == false);
  
  assert(is_code_unit_suffix(suffix, s1) == true);
  assert(is_code_unit_suffix(prefix, s1) == false);
  
  // code_point_length
  string surrogate_pair = {0xD83D, 0xDCA9}; // 💩 U+1F4A9
  assert(code_point_length(surrogate_pair) == 1);
  assert(surrogate_pair.length() == 2); // 2 code units
  
  string mixed = u"A" + surrogate_pair + u"B";
  assert(code_point_length(mixed) == 3);
  
  // String type validation
  assert(is_ascii_string(u"Hello") == true);
  assert(is_ascii_string(u"Hellö") == false); // ö is U+00F6
  
  assert(is_isomorphic_string(u"Hellö") == true);
  assert(is_isomorphic_string(u"Hello\u0100") == false);
  
  assert(is_scalar_value_string(u"Hello") == true);
  assert(is_scalar_value_string(surrogate_pair) == true); // Paired surrogates are scalar values
  
  string unpaired_lead = {0xD800};
  assert(is_scalar_value_string(unpaired_lead) == false);
  
  // convert_to_scalar_value_string
  string bad_string = {0x0041, 0xD800, 0x0042}; // A, unpaired lead, B
  string fixed = convert_to_scalar_value_string(bad_string);
  assert(fixed.size() == 3);
  assert(fixed[0] == 0x0041);
  assert(fixed[1] == 0xFFFD); // Replaced
  assert(fixed[2] == 0x0042);
  
  std::cout << "✓ String tests passed" << std::endl;
}

int main() {
  std::cout << "Running primitives tests..." << std::endl;
  
  test_byte();
  test_byte_sequence();
  test_code_point();
  test_string();
  
  std::cout << "\nAll primitives tests passed!" << std::endl;
  return 0;
}
