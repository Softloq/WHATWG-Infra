#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_STRING_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_STRING_HPP

#include <Softloq/API.Softloq.WHATWG.Infra.hpp>
#include <Softloq/WHATWG/Infra/Primitive/CodePoint.hpp>
#include <string>

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
using string = std::u16string;

// String comparison

/**
 * @brief Check if two strings are identical.
 * 
 * A string a is identical to a string b if it consists of the same sequence of code units.
 * This is a case-sensitive comparison that is also sensitive to normalization form and
 * combining mark order.
 * 
 * @param a First string
 * @param b Second string
 * @return true if the strings are identical, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool string_is_identical(const string& a, const string& b) noexcept;

// Prefix and suffix checking

/**
 * @brief Check if a string is a code unit prefix of another.
 * 
 * A string potentialPrefix is a code unit prefix of a string input if the algorithm
 * defined in the WHATWG Infra specification returns true.
 * 
 * @param potential_prefix The potential prefix string
 * @param input The input string to check
 * @return true if potential_prefix is a code unit prefix of input, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_code_unit_prefix(
    const string& potential_prefix, const string& input);

/**
 * @brief Check if a string is a code unit suffix of another.
 * 
 * A string potentialSuffix is a code unit suffix of a string input if the algorithm
 * defined in the WHATWG Infra specification returns true.
 * 
 * @param potential_suffix The potential suffix string
 * @param input The input string to check
 * @return true if potential_suffix is a code unit suffix of input, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_code_unit_suffix(
    const string& potential_suffix, const string& input);

// String length

/**
 * @brief Get the code point length of a string.
 * 
 * A string's code point length is the number of code points it contains.
 * This accounts for surrogate pairs which represent a single code point.
 * 
 * @param s The string to measure
 * @return The number of code points in the string
 */
SOFTLOQ_WHATWG_INFRA_API size_t code_point_length(const string& s);

// String type validation

/**
 * @brief Check if a string is an ASCII string.
 * 
 * An ASCII string is a string whose code points are all ASCII code points.
 * 
 * @param s The string to check
 * @return true if all code points are ASCII, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_ascii_string(const string& s);

/**
 * @brief Check if a string is an isomorphic string.
 * 
 * An isomorphic string is a string whose code points are all in the range
 * U+0000 NULL to U+00FF (ÿ), inclusive.
 * 
 * @param s The string to check
 * @return true if all code points are in the isomorphic range, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_isomorphic_string(const string& s);

/**
 * @brief Check if a string is a scalar value string.
 * 
 * A scalar value string is a string whose code points are all scalar values
 * (i.e., not surrogates).
 * 
 * @param s The string to check
 * @return true if all code points are scalar values, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_scalar_value_string(const string& s);

/**
 * @brief Convert a string into a scalar value string.
 * 
 * To convert a string into a scalar value string, replace any surrogates with U+FFFD (�).
 * The replaced surrogates are never part of surrogate pairs, since the process of
 * interpreting the string as containing code points will have converted surrogate pairs
 * into scalar values.
 * 
 * @param s The string to convert
 * @return A new string with surrogates replaced by U+FFFD
 */
SOFTLOQ_WHATWG_INFRA_API string convert_to_scalar_value_string(const string& s);

} // namespace Softloq::WHATWG::Infra::Primitive

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_STRING_HPP
