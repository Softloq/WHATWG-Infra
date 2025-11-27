#include <Softloq/WHATWG/Infra/Primitive/ByteSequence.hpp>

namespace Softloq::WHATWG::Infra::Primitive {

byte_sequence byte_lowercase(const byte_sequence& input) {
  byte_sequence result = input;
  for (auto& b : result) {
    // Convert bytes in range 0x41 (A) to 0x5A (Z) by adding 0x20
    if (b >= 0x41 && b <= 0x5A) {
      b += 0x20;
    }
  }
  return result;
}

byte_sequence byte_uppercase(const byte_sequence& input) {
  byte_sequence result = input;
  for (auto& b : result) {
    // Convert bytes in range 0x61 (a) to 0x7A (z) by subtracting 0x20
    if (b >= 0x61 && b <= 0x7A) {
      b -= 0x20;
    }
  }
  return result;
}

bool byte_case_insensitive_match(const byte_sequence& a, const byte_sequence& b) {
  // A is a byte-case-insensitive match for B if byte-lowercase of A
  // is the byte-lowercase of B
  return byte_lowercase(a) == byte_lowercase(b);
}

bool is_prefix(const byte_sequence& potential_prefix, const byte_sequence& input) {
  // Algorithm from WHATWG Infra specification
  size_t i = 0;
  
  while (true) {
    // If i is greater than or equal to potentialPrefix's length, return true
    if (i >= potential_prefix.size()) {
      return true;
    }
    
    // If i is greater than or equal to input's length, return false
    if (i >= input.size()) {
      return false;
    }
    
    // Let potentialPrefixByte be the ith byte of potentialPrefix
    byte potential_prefix_byte = potential_prefix[i];
    
    // Let inputByte be the ith byte of input
    byte input_byte = input[i];
    
    // Return false if potentialPrefixByte is not inputByte
    if (potential_prefix_byte != input_byte) {
      return false;
    }
    
    // Set i to i + 1
    ++i;
  }
}

bool byte_less_than(const byte_sequence& a, const byte_sequence& b) {
  // Algorithm from WHATWG Infra specification
  
  // If b is a prefix of a, then return false
  if (is_prefix(b, a)) {
    return false;
  }
  
  // If a is a prefix of b, then return true
  if (is_prefix(a, b)) {
    return true;
  }
  
  // Let n be the smallest index such that the nth byte of a is different
  // from the nth byte of b
  size_t n = 0;
  while (n < a.size() && n < b.size() && a[n] == b[n]) {
    ++n;
  }
  
  // If the nth byte of a is less than the nth byte of b, then return true
  if (n < a.size() && n < b.size() && a[n] < b[n]) {
    return true;
  }
  
  // Return false
  return false;
}

std::u16string isomorphic_decode(const byte_sequence& input) {
  // Return a string whose code point length is equal to input's length
  // and whose code points have the same values as the values of input's bytes
  std::u16string result;
  result.reserve(input.size());
  
  for (byte b : input) {
    // Each byte value becomes a code point with the same value
    result.push_back(static_cast<char16_t>(b));
  }
  
  return result;
}

} // namespace Softloq::WHATWG::Infra::Primitive
