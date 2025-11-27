#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_POINT_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_POINT_HPP

#include <Softloq/API.Softloq.WHATWG.Infra.hpp>
#include <cstdint>

namespace Softloq::WHATWG::Infra::Primitive {

/**
 * @brief A code point is a Unicode code point.
 * 
 * As per WHATWG Infra specification, a code point is represented as "U+" followed
 * by four-to-six ASCII upper hex digits, in the range U+0000 to U+10FFFF, inclusive.
 * A code point's value is its underlying number.
 */
using code_point = char32_t;

// Surrogate detection

/**
 * @brief Check if a code point is a leading surrogate.
 * 
 * A leading surrogate is a code point in the range U+D800 to U+DBFF, inclusive.
 * 
 * @param cp The code point to check
 * @return true if the code point is a leading surrogate, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_leading_surrogate(code_point cp) noexcept;

/**
 * @brief Check if a code point is a trailing surrogate.
 * 
 * A trailing surrogate is a code point in the range U+DC00 to U+DFFF, inclusive.
 * 
 * @param cp The code point to check
 * @return true if the code point is a trailing surrogate, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_trailing_surrogate(code_point cp) noexcept;

/**
 * @brief Check if a code point is a surrogate.
 * 
 * A surrogate is a leading surrogate or a trailing surrogate.
 * 
 * @param cp The code point to check
 * @return true if the code point is a surrogate, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_surrogate(code_point cp) noexcept;

/**
 * @brief Check if a code point is a scalar value.
 * 
 * A scalar value is a code point that is not a surrogate.
 * 
 * @param cp The code point to check
 * @return true if the code point is a scalar value, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_scalar_value(code_point cp) noexcept;

/**
 * @brief Check if a code point is a noncharacter.
 * 
 * A noncharacter is a code point that is in the range U+FDD0 to U+FDEF, inclusive,
 * or U+FFFE, U+FFFF, U+1FFFE, U+1FFFF, U+2FFFE, U+2FFFF, U+3FFFE, U+3FFFF,
 * U+4FFFE, U+4FFFF, U+5FFFE, U+5FFFF, U+6FFFE, U+6FFFF, U+7FFFE, U+7FFFF,
 * U+8FFFE, U+8FFFF, U+9FFFE, U+9FFFF, U+AFFFE, U+AFFFF, U+BFFFE, U+BFFFF,
 * U+CFFFE, U+CFFFF, U+DFFFE, U+DFFFF, U+EFFFE, U+EFFFF, U+FFFFE, U+FFFFF,
 * U+10FFFE, or U+10FFFF.
 * 
 * @param cp The code point to check
 * @return true if the code point is a noncharacter, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_noncharacter(code_point cp) noexcept;

// ASCII classification

/**
 * @brief Check if a code point is an ASCII code point.
 * 
 * An ASCII code point is a code point in the range U+0000 NULL to U+007F DELETE, inclusive.
 * 
 * @param cp The code point to check
 * @return true if the code point is ASCII, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_ascii_code_point(code_point cp) noexcept;

/**
 * @brief Check if a code point is an ASCII tab or newline.
 * 
 * An ASCII tab or newline is U+0009 TAB, U+000A LF, or U+000D CR.
 * 
 * @param cp The code point to check
 * @return true if the code point is tab or newline, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_ascii_tab_or_newline(code_point cp) noexcept;

/**
 * @brief Check if a code point is ASCII whitespace.
 * 
 * ASCII whitespace is U+0009 TAB, U+000A LF, U+000C FF, U+000D CR, or U+0020 SPACE.
 * 
 * @param cp The code point to check
 * @return true if the code point is ASCII whitespace, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_ascii_whitespace(code_point cp) noexcept;

// Control characters

/**
 * @brief Check if a code point is a C0 control.
 * 
 * A C0 control is a code point in the range U+0000 NULL to U+001F INFORMATION SEPARATOR ONE, inclusive.
 * 
 * @param cp The code point to check
 * @return true if the code point is a C0 control, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_c0_control(code_point cp) noexcept;

/**
 * @brief Check if a code point is a C0 control or space.
 * 
 * A C0 control or space is a C0 control or U+0020 SPACE.
 * 
 * @param cp The code point to check
 * @return true if the code point is a C0 control or space, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_c0_control_or_space(code_point cp) noexcept;

/**
 * @brief Check if a code point is a control.
 * 
 * A control is a C0 control or a code point in the range U+007F DELETE to
 * U+009F APPLICATION PROGRAM COMMAND, inclusive.
 * 
 * @param cp The code point to check
 * @return true if the code point is a control, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_control(code_point cp) noexcept;

// Digit classification

/**
 * @brief Check if a code point is an ASCII digit.
 * 
 * An ASCII digit is a code point in the range U+0030 (0) to U+0039 (9), inclusive.
 * 
 * @param cp The code point to check
 * @return true if the code point is an ASCII digit, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_ascii_digit(code_point cp) noexcept;

/**
 * @brief Check if a code point is an ASCII upper hex digit.
 * 
 * An ASCII upper hex digit is an ASCII digit or a code point in the range
 * U+0041 (A) to U+0046 (F), inclusive.
 * 
 * @param cp The code point to check
 * @return true if the code point is an ASCII upper hex digit, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_ascii_upper_hex_digit(code_point cp) noexcept;

/**
 * @brief Check if a code point is an ASCII lower hex digit.
 * 
 * An ASCII lower hex digit is an ASCII digit or a code point in the range
 * U+0061 (a) to U+0066 (f), inclusive.
 * 
 * @param cp The code point to check
 * @return true if the code point is an ASCII lower hex digit, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_ascii_lower_hex_digit(code_point cp) noexcept;

/**
 * @brief Check if a code point is an ASCII hex digit.
 * 
 * An ASCII hex digit is an ASCII upper hex digit or ASCII lower hex digit.
 * 
 * @param cp The code point to check
 * @return true if the code point is an ASCII hex digit, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_ascii_hex_digit(code_point cp) noexcept;

// Alpha classification

/**
 * @brief Check if a code point is an ASCII upper alpha.
 * 
 * An ASCII upper alpha is a code point in the range U+0041 (A) to U+005A (Z), inclusive.
 * 
 * @param cp The code point to check
 * @return true if the code point is an ASCII upper alpha, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_ascii_upper_alpha(code_point cp) noexcept;

/**
 * @brief Check if a code point is an ASCII lower alpha.
 * 
 * An ASCII lower alpha is a code point in the range U+0061 (a) to U+007A (z), inclusive.
 * 
 * @param cp The code point to check
 * @return true if the code point is an ASCII lower alpha, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_ascii_lower_alpha(code_point cp) noexcept;

/**
 * @brief Check if a code point is an ASCII alpha.
 * 
 * An ASCII alpha is an ASCII upper alpha or ASCII lower alpha.
 * 
 * @param cp The code point to check
 * @return true if the code point is an ASCII alpha, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_ascii_alpha(code_point cp) noexcept;

/**
 * @brief Check if a code point is an ASCII alphanumeric.
 * 
 * An ASCII alphanumeric is an ASCII digit or ASCII alpha.
 * 
 * @param cp The code point to check
 * @return true if the code point is an ASCII alphanumeric, false otherwise
 */
SOFTLOQ_WHATWG_INFRA_API bool is_ascii_alphanumeric(code_point cp) noexcept;

} // namespace Softloq::WHATWG::Infra::Primitive

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODE_POINT_HPP
