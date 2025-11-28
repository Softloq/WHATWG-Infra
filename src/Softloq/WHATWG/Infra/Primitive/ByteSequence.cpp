#include <Softloq/WHATWG/Infra/Primitive/ByteSequence.hpp>

namespace Softloq::WHATWG::Infra::Primitive {

ByteSequence ByteSequence::lowercase() const {
  ByteSequence result;
  result.m_value.reserve(m_value.size());
  
  for (const auto& b : m_value) {
    auto val = b.value();
    // Convert bytes in range 0x41 (A) to 0x5A (Z) by adding 0x20
    if (val >= 0x41 && val <= 0x5A) {
      result.push_back(Byte(static_cast<uint8_t>(val + 0x20)));
    } else {
      result.push_back(b);
    }
  }
  return result;
}

ByteSequence ByteSequence::uppercase() const {
  ByteSequence result;
  result.m_value.reserve(m_value.size());
  
  for (const auto& b : m_value) {
    auto val = b.value();
    // Convert bytes in range 0x61 (a) to 0x7A (z) by subtracting 0x20
    if (val >= 0x61 && val <= 0x7A) {
      result.push_back(Byte(static_cast<uint8_t>(val - 0x20)));
    } else {
      result.push_back(b);
    }
  }
  return result;
}

bool ByteSequence::case_insensitive_match(const ByteSequence& other) const {
  // A is a byte-case-insensitive match for B if byte-lowercase of A
  // is the byte-lowercase of B
  return this->lowercase() == other.lowercase();
}

bool ByteSequence::is_prefix(const ByteSequence& input) const {
  // Algorithm from WHATWG Infra specification
  // Note: 'this' is potentialPrefix
  
  size_t i = 0;
  
  while (true) {
    // If i is greater than or equal to potentialPrefix's length, return true
    if (i >= this->size()) {
      return true;
    }
    
    // If i is greater than or equal to input's length, return false
    if (i >= input.size()) {
      return false;
    }
    
    // Let potentialPrefixByte be the ith byte of potentialPrefix
    Byte potential_prefix_byte = (*this)[i];
    
    // Let inputByte be the ith byte of input
    Byte input_byte = input[i];
    
    // Return false if potentialPrefixByte is not inputByte
    if (potential_prefix_byte != input_byte) {
      return false;
    }
    
    // Set i to i + 1
    ++i;
  }
}

bool ByteSequence::less_than(const ByteSequence& other) const {
  // Algorithm from WHATWG Infra specification
  // Note: 'this' is 'a', 'other' is 'b'
  
  // If b is a prefix of a, then return false
  if (other.is_prefix(*this)) {
    return false;
  }
  
  // If a is a prefix of b, then return true
  if (this->is_prefix(other)) {
    return true;
  }
  
  // Let n be the smallest index such that the nth byte of a is different
  // from the nth byte of b
  size_t n = 0;
  while (n < this->size() && n < other.size() && (*this)[n] == other[n]) {
    ++n;
  }
  
  // If the nth byte of a is less than the nth byte of b, then return true
  if (n < this->size() && n < other.size() && (*this)[n] < other[n]) {
    return true;
  }
  
  // Return false
  return false;
}

std::u16string ByteSequence::isomorphic_decode() const {
  // Return a string whose code point length is equal to input's length
  // and whose code points have the same values as the values of input's bytes
  std::u16string result;
  result.reserve(m_value.size());
  
  for (const auto& b : m_value) {
    // Each byte value becomes a code point with the same value
    result.push_back(static_cast<char16_t>(b.value()));
  }
  
  return result;
}

} // namespace Softloq::WHATWG::Infra::Primitive
