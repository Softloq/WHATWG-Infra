#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_SEQUENCE_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_SEQUENCE_HPP

#include <Softloq/API.Softloq.WHATWG.Infra.hpp>
#include <Softloq/WHATWG/Infra/Primitive/Byte.hpp>
#include <string>
#include <vector>

namespace Softloq::WHATWG::Infra::Primitive {

/**
 * @brief A byte sequence is a sequence of bytes.
 * 
 * As per WHATWG Infra specification, a byte sequence is represented as a
 * space-separated sequence of bytes.
 */
using byte_sequence = std::vector<byte>;

/**
 * @brief Convert a byte sequence to lowercase.
 * 
 * To byte-lowercase a byte sequence, increase each byte it contains,
 * in the range 0x41 (A) to 0x5A (Z), inclusive, by 0x20.
 * 
 * @param input The byte sequence to convert
 * @return A new byte sequence with uppercase ASCII letters converted to lowercase
 */
SOFTLOQ_WHATWG_INFRA_API byte_sequence byte_lowercase(const byte_sequence& input);

/**
 * @brief Convert a byte sequence to uppercase.
 * 
 * To byte-uppercase a byte sequence, subtract each byte it contains,
 * in the range 0x61 (a) to 0x7A (z), inclusive, by 0x20.
 * 
 * @param input The byte sequence to convert
 * @return A new byte sequence with lowercase ASCII letters converted to uppercase
 */
SOFTLOQ_WHATWG_INFRA_API byte_sequence byte_uppercase(const byte_sequence& input);

/**
 * @brief Check if two byte sequences are a byte-case-insensitive match.
 * 
 * A byte sequence A is a byte-case-insensitive match for a byte sequence B,
 * if the byte-lowercase of A is the byte-lowercase of B.
 * 
 * @param a First byte sequence
 * @param b Second byte sequence
 * @return true if the sequences match case-insensitively, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool byte_case_insensitive_match(
    const byte_sequence& a, const byte_sequence& b);

/**
 * @brief Check if a byte sequence is a prefix of another.
 * 
 * A byte sequence potentialPrefix is a prefix of a byte sequence input
 * if the algorithm defined in the WHATWG Infra specification returns true.
 * 
 * @param potential_prefix The potential prefix sequence
 * @param input The input sequence to check
 * @return true if potential_prefix is a prefix of input, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_prefix(
    const byte_sequence& potential_prefix, const byte_sequence& input);

/**
 * @brief Check if one byte sequence is byte less than another.
 * 
 * A byte sequence a is byte less than a byte sequence b if the algorithm
 * defined in the WHATWG Infra specification returns true.
 * 
 * @param a First byte sequence
 * @param b Second byte sequence
 * @return true if a is byte less than b, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool byte_less_than(
    const byte_sequence& a, const byte_sequence& b);

/**
 * @brief Isomorphic decode a byte sequence.
 * 
 * To isomorphic decode a byte sequence input, return a string whose
 * code point length is equal to input's length and whose code points
 * have the same values as the values of input's bytes, in the same order.
 * 
 * @param input The byte sequence to decode
 * @return A string with code points corresponding to the byte values
 */
SOFTLOQ_WHATWG_INFRA_API std::u16string isomorphic_decode(const byte_sequence& input);

} // namespace Softloq::WHATWG::Infra::Primitive

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_BYTE_SEQUENCE_HPP
