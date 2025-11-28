#include <Softloq/WHATWG/Infra/Primitives.hpp>
#include <cassert>
#include <iostream>
#include <vector>
#include <format>

using namespace Softloq::WHATWG::Infra::Primitive;

void test_byte() {
  std::cout << "Testing Byte primitives..." << std::endl;
  
  // Construction
  Byte b1(static_cast<uint8_t>(0x41));
  assert(b1.value() == 0x41);
  
  // is_ascii
  assert(Byte(static_cast<uint8_t>(0x00)).is_ascii() == true);
  assert(Byte(static_cast<uint8_t>(0x7F)).is_ascii() == true);
  assert(Byte(static_cast<uint8_t>(0x80)).is_ascii() == false);
  assert(Byte(static_cast<uint8_t>(0xFF)).is_ascii() == false);
  
  // Formatting
  std::string formatted = std::format("{}", Byte(static_cast<uint8_t>(0x41)));
  assert(formatted == "0x41");
  std::cout << "  Byte format: " << formatted << std::endl;
  
  std::cout << "✓ Byte tests passed" << std::endl;
}

void test_byte_sequence() {
  std::cout << "Testing ByteSequence primitives..." << std::endl;
  
  ByteSequence seq1 = {Byte(static_cast<uint8_t>(0x48)), Byte(static_cast<uint8_t>(0x49))}; // "HI"
  ByteSequence seq2 = {Byte(static_cast<uint8_t>(0x68)), Byte(static_cast<uint8_t>(0x69))}; // "hi"
  
  // lowercase
  ByteSequence lower = seq1.lowercase();
  assert(lower.size() == 2);
  assert(lower[0].value() == 0x68);
  assert(lower[1].value() == 0x69);
  
  // uppercase
  ByteSequence upper = seq2.uppercase();
  assert(upper.size() == 2);
  assert(upper[0].value() == 0x48);
  assert(upper[1].value() == 0x49);
  
  // case_insensitive_match
  assert(seq1.case_insensitive_match(seq2) == true);
  assert(seq1.case_insensitive_match({Byte(static_cast<uint8_t>(0x48)), Byte(static_cast<uint8_t>(0x49))}) == true);
  assert(seq1.case_insensitive_match({Byte(static_cast<uint8_t>(0x48)), Byte(static_cast<uint8_t>(0x50))}) == false);
  
  // is_prefix
  ByteSequence prefix = {Byte(static_cast<uint8_t>(0x48))};
  // prefix.is_prefix(seq1) checks if 'prefix' is a prefix of 'seq1'
  assert(prefix.is_prefix(seq1) == true);
  assert(seq1.is_prefix(seq1) == true);
  assert(seq1.is_prefix(prefix) == false);
  
  // less_than
  ByteSequence a = {Byte(static_cast<uint8_t>(0x01)), Byte(static_cast<uint8_t>(0x02))};
  ByteSequence b = {Byte(static_cast<uint8_t>(0x01)), Byte(static_cast<uint8_t>(0x03))};
  assert(a.less_than(b) == true);
  assert(b.less_than(a) == false);
  assert(a.less_than(a) == false);
  
  // isomorphic_decode
  std::u16string decoded = seq1.isomorphic_decode();
  assert(decoded.size() == 2);
  assert(decoded[0] == 0x0048);
  assert(decoded[1] == 0x0049);
  
  // Formatting
  std::string formatted = std::format("{}", seq1);
  assert(formatted == "0x48 0x49");
  std::cout << "  ByteSequence format: " << formatted << std::endl;
  
  std::cout << "✓ ByteSequence tests passed" << std::endl;
}

void test_code_point() {
  std::cout << "Testing CodePoint primitives..." << std::endl;
  
  // Surrogates
  assert(CodePoint(0xD800).is_leading_surrogate() == true);
  assert(CodePoint(0xDBFF).is_leading_surrogate() == true);
  assert(CodePoint(0xD7FF).is_leading_surrogate() == false);
  assert(CodePoint(0xDC00).is_leading_surrogate() == false);
  
  assert(CodePoint(0xDC00).is_trailing_surrogate() == true);
  assert(CodePoint(0xDFFF).is_trailing_surrogate() == true);
  assert(CodePoint(0xDBFF).is_trailing_surrogate() == false);
  assert(CodePoint(0xE000).is_trailing_surrogate() == false);
  
  assert(CodePoint(0xD800).is_surrogate() == true);
  assert(CodePoint(0xDFFF).is_surrogate() == true);
  assert(CodePoint(0x0041).is_surrogate() == false);
  
  assert(CodePoint(0x0041).is_scalar_value() == true);
  assert(CodePoint(0xD800).is_scalar_value() == false);
  
  // Noncharacters
  assert(CodePoint(0xFDD0).is_noncharacter() == true);
  assert(CodePoint(0xFDEF).is_noncharacter() == true);
  assert(CodePoint(0xFFFE).is_noncharacter() == true);
  assert(CodePoint(0xFFFF).is_noncharacter() == true);
  assert(CodePoint(0x10FFFF).is_noncharacter() == true);
  assert(CodePoint(0x0041).is_noncharacter() == false);
  
  // ASCII classification
  assert(CodePoint(0x0000).is_ascii() == true);
  assert(CodePoint(0x007F).is_ascii() == true);
  assert(CodePoint(0x0080).is_ascii() == false);
  
  assert(CodePoint(0x0009).is_ascii_tab_or_newline() == true); // TAB
  assert(CodePoint(0x000A).is_ascii_tab_or_newline() == true); // LF
  assert(CodePoint(0x000D).is_ascii_tab_or_newline() == true); // CR
  assert(CodePoint(0x0020).is_ascii_tab_or_newline() == false); // SPACE
  
  assert(CodePoint(0x0020).is_ascii_whitespace() == true);
  assert(CodePoint(0x000C).is_ascii_whitespace() == true); // FF
  assert(CodePoint(0x0041).is_ascii_whitespace() == false);
  
  // Control characters
  assert(CodePoint(0x0000).is_c0_control() == true);
  assert(CodePoint(0x001F).is_c0_control() == true);
  assert(CodePoint(0x0020).is_c0_control() == false);
  
  assert(CodePoint(0x0020).is_c0_control_or_space() == true);
  
  assert(CodePoint(0x007F).is_control() == true); // DEL
  assert(CodePoint(0x009F).is_control() == true);
  assert(CodePoint(0x0041).is_control() == false);
  
  // Digits and hex
  assert(CodePoint(0x0030).is_ascii_digit() == true); // 0
  assert(CodePoint(0x0039).is_ascii_digit() == true); // 9
  assert(CodePoint(0x002F).is_ascii_digit() == false);
  
  assert(CodePoint(0x0041).is_ascii_upper_hex_digit() == true); // A
  assert(CodePoint(0x0046).is_ascii_upper_hex_digit() == true); // F
  assert(CodePoint(0x0061).is_ascii_upper_hex_digit() == false); // a
  
  assert(CodePoint(0x0061).is_ascii_lower_hex_digit() == true); // a
  assert(CodePoint(0x0066).is_ascii_lower_hex_digit() == true); // f
  assert(CodePoint(0x0041).is_ascii_lower_hex_digit() == false); // A
  
  assert(CodePoint(0x0041).is_ascii_hex_digit() == true);
  assert(CodePoint(0x0061).is_ascii_hex_digit() == true);
  assert(CodePoint(0x0030).is_ascii_hex_digit() == true);
  assert(CodePoint(0x0047).is_ascii_hex_digit() == false); // G
  
  // Alpha
  assert(CodePoint(0x0041).is_ascii_upper_alpha() == true);
  assert(CodePoint(0x005A).is_ascii_upper_alpha() == true);
  assert(CodePoint(0x0061).is_ascii_lower_alpha() == true);
  assert(CodePoint(0x007A).is_ascii_lower_alpha() == true);
  
  assert(CodePoint(0x0041).is_ascii_alpha() == true);
  assert(CodePoint(0x0061).is_ascii_alpha() == true);
  assert(CodePoint(0x0030).is_ascii_alpha() == false);
  
  assert(CodePoint(0x0041).is_ascii_alphanumeric() == true);
  assert(CodePoint(0x0030).is_ascii_alphanumeric() == true);
  assert(CodePoint(0x0020).is_ascii_alphanumeric() == false);
  
  // Formatting
  std::string formatted = std::format("{}", CodePoint(0x1F4A9));
  assert(formatted == "U+1F4A9");
  std::cout << "  CodePoint format: " << formatted << std::endl;
  
  std::cout << "✓ CodePoint tests passed" << std::endl;
}

void test_string() {
  std::cout << "Testing String primitives..." << std::endl;
  
  String s1 = u"Hello";
  String s2 = u"Hello";
  String s3 = u"World";
  
  // is_identical_to
  assert(s1.is_identical_to(s2) == true);
  assert(s1.is_identical_to(s3) == false);
  assert(s1 == s2);
  
  // Prefix/Suffix
  String prefix = u"He";
  String suffix = u"lo";
  assert(prefix.is_code_unit_prefix(s1) == true);
  assert(suffix.is_code_unit_prefix(s1) == false);
  
  assert(suffix.is_code_unit_suffix(s1) == true);
  assert(prefix.is_code_unit_suffix(s1) == false);
  
  // code_point_length
  String surrogate_pair = String(std::u16string{static_cast<char16_t>(0xD83D), static_cast<char16_t>(0xDCA9)}); // 💩 U+1F4A9
  assert(surrogate_pair.code_point_length() == 1);
  assert(surrogate_pair.length() == 2); // 2 code units
  
  String mixed = u"A";
  mixed = mixed + surrogate_pair + String(u"B");
  assert(mixed.code_point_length() == 3);
  
  // String type validation
  assert(String(u"Hello").is_ascii_string() == true);
  assert(String(u"Hellö").is_ascii_string() == false); // ö is U+00F6
  
  assert(String(u"Hellö").is_isomorphic_string() == true);
  assert(String(u"Hello\u0100").is_isomorphic_string() == false);
  
  assert(String(u"Hello").is_scalar_value_string() == true);
  assert(surrogate_pair.is_scalar_value_string() == true); // Paired surrogates are scalar values
  
  String unpaired_lead = String(std::u16string{static_cast<char16_t>(0xD800)});
  assert(unpaired_lead.is_scalar_value_string() == false);
  
  // convert_to_scalar_value_string
  String bad_string = String(std::u16string{static_cast<char16_t>(0x0041), static_cast<char16_t>(0xD800), static_cast<char16_t>(0x0042)}); // A, unpaired lead, B
  String fixed = bad_string.convert_to_scalar_value_string();
  assert(fixed.size() == 3);
  assert(fixed[0] == 0x0041);
  assert(fixed[1] == 0xFFFD); // Replaced
  assert(fixed[2] == 0x0042);
  
  // Formatting
  std::string formatted = std::format("{}", String(u"Hello"));
  assert(formatted == "\"Hello\"");
  std::cout << "  String format: " << formatted << std::endl;
  
  std::cout << "✓ String tests passed" << std::endl;
}

int main() {
  std::cout << "Running primitives tests..." << std::endl;
  
  test_byte();
  test_byte_sequence();
  test_code_point();
  test_string();

  // New tests
  std::cout << "Testing Null primitives..." << std::endl;
  assert(Null() == nullptr);
  assert(std::format("{}", Null()) == "null");
  std::cout << "✓ Null tests passed" << std::endl;

  std::cout << "Testing Boolean primitives..." << std::endl;
  assert(Boolean(true).value() == true);
  assert(Boolean(false).value() == false);
  assert(std::format("{}", Boolean(true)) == "true");
  assert(std::format("{}", Boolean(false)) == "false");
  std::cout << "✓ Boolean tests passed" << std::endl;

  std::cout << "Testing Number primitives..." << std::endl;
  assert(UInteger8(255).value() == 255);
  assert(Integer8(-128).value() == -128);
  assert(UInteger128(10).low() == 10);
  assert(UInteger128(1, 0).high() == 1);
  assert(std::format("{}", UInteger8(0xFF)) == "255");
  // assert(std::format("{}", UInteger128(0, 0xFF)) == "0x000000000000000000000000000000FF"); // Check format if needed
  std::cout << "✓ Number tests passed" << std::endl;

  std::cout << "Testing Time primitives..." << std::endl;
  // Just check compilation and basic access for now as time values are dynamic
  Moment m(std::chrono::system_clock::now());
  Duration d(std::chrono::seconds(5));
  assert(d.value().count() == 5.0);
  std::cout << "✓ Time tests passed" << std::endl;

  std::cout << "Testing Singleton primitives..." << std::endl;
  assert(Allowed() == Allowed());
  assert(std::format("{}", Allowed()) == "allowed");
  assert(std::format("{}", Blocked()) == "blocked");
  assert(std::format("{}", Failure()) == "failure");
  assert(std::format("{}", Success()) == "success");
  std::cout << "✓ Singleton tests passed" << std::endl;
  
  std::cout << "\nAll primitives tests passed!" << std::endl;
  return 0;
}
