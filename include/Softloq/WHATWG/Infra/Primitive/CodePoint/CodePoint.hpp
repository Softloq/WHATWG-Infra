/**
 * @file Softloq/WHATWG/Infra/Primitive/CodePoint/CodePoint.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the CodePoint type for the WHATWG Infra library, representing a Unicode code point in the context of web APIs.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the CodePoint type for the WHATWG Infra library.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEPOINT_CODEPOINT_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEPOINT_CODEPOINT_HPP

#include "Softloq/WHATWG/Infra/API-Library/Macro.hpp"
#include "Softloq/WHATWG/Infra/Primitive/Primitive.hpp"

namespace Softloq::WHATWG::Infra
{

/**
 * @brief The CodePoint type represents a Unicode code point in the context of web APIs.
 *
 * The CodePoint type represents a Unicode scalar value in the range U+000000 to U+10FFFF,
 * as defined by the WHATWG Infra specification. It provides value construction, mutation,
 * equality comparison, explicit conversion to the underlying char32_t type, and a full set
 * of Unicode attribute predicates (e.g. is_surrogate, is_ascii, is_ascii_whitespace).
 */
class CodePoint final : public Primitive
{
// Constructors and destructor
public:
    SOFTLOQ_WHATWG_INFRA_API CodePoint() noexcept;
    SOFTLOQ_WHATWG_INFRA_API explicit CodePoint(char32_t value) noexcept;
    SOFTLOQ_WHATWG_INFRA_API ~CodePoint() noexcept;

// Primitive interface
public:
    /**
     * @brief Get the type of the primitive.
     *
     * @return The type of the primitive, which is PrimitiveType::CodePoint.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API PrimitiveType get_type() const noexcept override;

// Accessors
public:
    /**
     * @brief Get the underlying code point value.
     *
     * @return The stored code point as char32_t.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API char32_t get_value() const noexcept;

    /**
     * @brief Set the underlying code point value.
     *
     * @param value The new code point to store.
     */
    SOFTLOQ_WHATWG_INFRA_API void set_value(char32_t value) noexcept;

// Conversion
public:
    /**
     * @brief Explicit conversion to char32_t.
     *
     * @return The stored code point value.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API explicit operator char32_t() const noexcept;

// Operators
public:
    /**
     * @brief Equality comparison.
     *
     * @param other The CodePoint to compare against.
     * @return true if both instances hold the same value.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool operator==(const CodePoint& other) const noexcept;

    /**
     * @brief Inequality comparison.
     *
     * @param other The CodePoint to compare against.
     * @return true if the instances hold different values.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool operator!=(const CodePoint& other) const noexcept;

// Unicode attribute predicates
public:
    /**
     * @brief Returns true if the code point is a surrogate (U+D800 to U+DFFF).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_surrogate() const noexcept;

    /**
     * @brief Returns true if the code point is a leading surrogate (U+D800 to U+DBFF).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_leading_surrogate() const noexcept;

    /**
     * @brief Returns true if the code point is a trailing surrogate (U+DC00 to U+DFFF).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_trailing_surrogate() const noexcept;

    /**
     * @brief Returns true if the code point is a scalar value (not a surrogate).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_scalar_value() const noexcept;

    /**
     * @brief Returns true if the code point is a noncharacter.
     *
     * Noncharacters are U+FDD0 to U+FDEF and the last two code points of each plane
     * (U+xFFFE and U+xFFFF, for x in 0x0 to 0x10).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_noncharacter() const noexcept;

    /**
     * @brief Returns true if the code point is an ASCII code point (U+0000 to U+007F).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_ascii() const noexcept;

    /**
     * @brief Returns true if the code point is an ASCII tab or newline (U+0009, U+000A, U+000D).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_ascii_tab_or_newline() const noexcept;

    /**
     * @brief Returns true if the code point is ASCII whitespace (U+0009, U+000A, U+000C, U+000D, U+0020).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_ascii_whitespace() const noexcept;

    /**
     * @brief Returns true if the code point is a C0 control (U+0000 to U+001F).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_c0_control() const noexcept;

    /**
     * @brief Returns true if the code point is a C0 control or U+0020 SPACE.
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_c0_control_or_space() const noexcept;

    /**
     * @brief Returns true if the code point is a control (C0, U+007F DEL, or U+0080 to U+009F).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_control() const noexcept;

    /**
     * @brief Returns true if the code point is an ASCII digit (U+0030 to U+0039).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_ascii_digit() const noexcept;

    /**
     * @brief Returns true if the code point is an ASCII upper hex digit (U+0030..U+0039 or U+0041..U+0046).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_ascii_upper_hex_digit() const noexcept;

    /**
     * @brief Returns true if the code point is an ASCII lower hex digit (U+0030..U+0039 or U+0061..U+0066).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_ascii_lower_hex_digit() const noexcept;

    /**
     * @brief Returns true if the code point is an ASCII hex digit (upper or lower).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_ascii_hex_digit() const noexcept;

    /**
     * @brief Returns true if the code point is an ASCII upper alpha (U+0041 to U+005A).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_ascii_upper_alpha() const noexcept;

    /**
     * @brief Returns true if the code point is an ASCII lower alpha (U+0061 to U+007A).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_ascii_lower_alpha() const noexcept;

    /**
     * @brief Returns true if the code point is an ASCII alpha (upper or lower).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_ascii_alpha() const noexcept;

    /**
     * @brief Returns true if the code point is an ASCII alphanumeric (digit or alpha).
     */
    [[nodiscard]] SOFTLOQ_WHATWG_INFRA_API bool is_ascii_alphanumeric() const noexcept;

private:
    char32_t m_value{U'\0'};
};

} // namespace Softloq::WHATWG::Infra

#include "Softloq/WHATWG/Infra/Primitive/CodePoint/Formatter.tpp"
#include "Softloq/WHATWG/Infra/Primitive/CodePoint/OStream.inl"

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_CODEPOINT_CODEPOINT_HPP
