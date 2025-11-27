#include <Softloq/WHATWG/Infra/Primitive/String.hpp>

namespace Softloq::WHATWG::Infra::Primitive {

bool string_is_identical(const string& a, const string& b) noexcept {
  // Strings are identical if they consist of the same sequence of code units
  return a == b;
}

bool is_code_unit_prefix(const string& potential_prefix, const string& input) {
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
    
    // Let potentialPrefixCodeUnit be the ith code unit of potentialPrefix
    char16_t potential_prefix_code_unit = potential_prefix[i];
    
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

bool is_code_unit_suffix(const string& potential_suffix, const string& input) {
  // Algorithm from WHATWG Infra specification
  size_t i = 1;
  
  while (true) {
    // Let potentialSuffixIndex be potentialSuffix's length − i
    size_t potential_suffix_index = potential_suffix.size() - i;
    
    // Let inputIndex be input's length − i
    size_t input_index = input.size() - i;
    
    // If potentialSuffixIndex is less than 0, then return true
    if (i > potential_suffix.size()) {
      return true;
    }
    
    // If inputIndex is less than 0, then return false
    if (i > input.size()) {
      return false;
    }
    
    // Let potentialSuffixCodeUnit be the potentialSuffixIndexth code unit of potentialSuffix
    char16_t potential_suffix_code_unit = potential_suffix[potential_suffix_index];
    
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

size_t code_point_length(const string& s) {
  // Count the number of code points, accounting for surrogate pairs
  size_t count = 0;
  size_t i = 0;
  
  while (i < s.size()) {
    char16_t code_unit = s[i];
    
    // Check if this is a leading surrogate
    if (code_unit >= 0xD800 && code_unit <= 0xDBFF) {
      // Check if there's a trailing surrogate following
      if (i + 1 < s.size()) {
        char16_t next_code_unit = s[i + 1];
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

bool is_ascii_string(const string& s) {
  // An ASCII string has all code points in the ASCII range
  for (char16_t code_unit : s) {
    // For ASCII, code units and code points are the same
    if (code_unit > 0x007F) {
      return false;
    }
  }
  return true;
}

bool is_isomorphic_string(const string& s) {
  // An isomorphic string has all code points in range U+0000 to U+00FF
  for (char16_t code_unit : s) {
    // For this range, code units and code points are the same
    if (code_unit > 0x00FF) {
      return false;
    }
  }
  return true;
}

bool is_scalar_value_string(const string& s) {
  // A scalar value string has no surrogates
  for (size_t i = 0; i < s.size(); ++i) {
    char16_t code_unit = s[i];
    
    // Check if this is a leading surrogate
    if (code_unit >= 0xD800 && code_unit <= 0xDBFF) {
      // Check if there's a trailing surrogate following
      if (i + 1 < s.size()) {
        char16_t next_code_unit = s[i + 1];
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

string convert_to_scalar_value_string(const string& s) {
  // Replace any surrogates with U+FFFD (�)
  string result;
  result.reserve(s.size());
  
  for (size_t i = 0; i < s.size(); ++i) {
    char16_t code_unit = s[i];
    
    // Check if this is a leading surrogate
    if (code_unit >= 0xD800 && code_unit <= 0xDBFF) {
      // Check if there's a trailing surrogate following
      if (i + 1 < s.size()) {
        char16_t next_code_unit = s[i + 1];
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
  
  return result;
}

} // namespace Softloq::WHATWG::Infra::Primitive
