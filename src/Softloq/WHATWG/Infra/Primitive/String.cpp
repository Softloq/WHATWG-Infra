#include <Softloq/WHATWG/Infra/Primitive/String.hpp>

namespace Softloq::WHATWG::Infra::Primitive {

bool String::is_identical_to(const String& other) const noexcept {
  // Strings are identical if they consist of the same sequence of code units
  return m_value == other.m_value;
}

bool String::is_code_unit_prefix(const String& input) const {
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
    
    // Let potentialPrefixCodeUnit be the ith code unit of potentialPrefix
    char16_t potential_prefix_code_unit = (*this)[i];
    
    // Let inputCodeUnit be the ith code unit of input
    char16_t input_code_unit = input[i];
    
    // Return false if potentialPrefixCodeUnit is not inputCodeUnit
    if (potential_prefix_code_unit != input_code_unit) {
      return false;
    }
    
    // Set i to i + 1
    ++i;
  }
}

bool String::is_code_unit_suffix(const String& input) const {
  // Algorithm from WHATWG Infra specification
  // Note: 'this' is potentialSuffix
  
  size_t i = 1;
  
  while (true) {
    // Let potentialSuffixIndex be potentialSuffix's length − i
    // Check bounds carefully with size_t (unsigned)
    if (i > this->size()) {
      return true;
    }
    size_t potential_suffix_index = this->size() - i;
    
    // Let inputIndex be input's length − i
    if (i > input.size()) {
      return false;
    }
    size_t input_index = input.size() - i;
    
    // Let potentialSuffixCodeUnit be the potentialSuffixIndexth code unit of potentialSuffix
    char16_t potential_suffix_code_unit = (*this)[potential_suffix_index];
    
    // Let inputCodeUnit be the inputIndexth code unit of input
    char16_t input_code_unit = input[input_index];
    
    // Return false if potentialSuffixCodeUnit is not inputCodeUnit
    if (potential_suffix_code_unit != input_code_unit) {
      return false;
    }
    
    // Set i to i + 1
    ++i;
  }
}

size_t String::code_point_length() const {
  // Count the number of code points, accounting for surrogate pairs
  size_t count = 0;
  size_t i = 0;
  
  while (i < m_value.size()) {
    char16_t code_unit = m_value[i];
    
    // Check if this is a leading surrogate
    if (code_unit >= 0xD800 && code_unit <= 0xDBFF) {
      // Check if there's a trailing surrogate following
      if (i + 1 < m_value.size()) {
        char16_t next_code_unit = m_value[i + 1];
        if (next_code_unit >= 0xDC00 && next_code_unit <= 0xDFFF) {
          // This is a surrogate pair, counts as one code point
          ++count;
          i += 2;
          continue;
        }
      }
    }
    
    // Not a surrogate pair, counts as one code point
    ++count;
    ++i;
  }
  
  return count;
}

bool String::is_ascii_string() const {
  // An ASCII string has all code points in the ASCII range
  for (char16_t code_unit : m_value) {
    // For ASCII, code units and code points are the same
    if (code_unit > 0x007F) {
      return false;
    }
  }
  return true;
}

bool String::is_isomorphic_string() const {
  // An isomorphic string has all code points in range U+0000 to U+00FF
  for (char16_t code_unit : m_value) {
    // For this range, code units and code points are the same
    if (code_unit > 0x00FF) {
      return false;
    }
  }
  return true;
}

bool String::is_scalar_value_string() const {
  // A scalar value string has no surrogates
  for (size_t i = 0; i < m_value.size(); ++i) {
    char16_t code_unit = m_value[i];
    
    // Check if this is a leading surrogate
    if (code_unit >= 0xD800 && code_unit <= 0xDBFF) {
      // Check if there's a trailing surrogate following
      if (i + 1 < m_value.size()) {
        char16_t next_code_unit = m_value[i + 1];
        if (next_code_unit >= 0xDC00 && next_code_unit <= 0xDFFF) {
          // This is a valid surrogate pair, which is a scalar value
          ++i; // Skip the trailing surrogate
          continue;
        }
      }
      // Unpaired leading surrogate
      return false;
    }
    
    // Check if this is a trailing surrogate (unpaired)
    if (code_unit >= 0xDC00 && code_unit <= 0xDFFF) {
      return false;
    }
  }
  
  return true;
}

String String::convert_to_scalar_value_string() const {
  // Replace any surrogates with U+FFFD ()
  std::u16string result;
  result.reserve(m_value.size());
  
  for (size_t i = 0; i < m_value.size(); ++i) {
    char16_t code_unit = m_value[i];
    
    // Check if this is a leading surrogate
    if (code_unit >= 0xD800 && code_unit <= 0xDBFF) {
      // Check if there's a trailing surrogate following
      if (i + 1 < m_value.size()) {
        char16_t next_code_unit = m_value[i + 1];
        if (next_code_unit >= 0xDC00 && next_code_unit <= 0xDFFF) {
          // This is a valid surrogate pair, keep it
          result.push_back(code_unit);
          result.push_back(next_code_unit);
          ++i; // Skip the trailing surrogate
          continue;
        }
      }
      // Unpaired leading surrogate, replace with U+FFFD
      result.push_back(0xFFFD);
      continue;
    }
    
    // Check if this is a trailing surrogate (unpaired)
    if (code_unit >= 0xDC00 && code_unit <= 0xDFFF) {
      // Unpaired trailing surrogate, replace with U+FFFD
      result.push_back(0xFFFD);
      continue;
    }
    
    // Normal code unit, keep it
    result.push_back(code_unit);
  }
  
  return String(result);
}

} // namespace Softloq::WHATWG::Infra::Primitive
