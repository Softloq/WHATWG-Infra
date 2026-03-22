/**
 * @file Test-Units/Primitive/CodePoint.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Unit tests for the CodePoint primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains unit tests for the CodePoint primitive type in the WHATWG Infra library.
 */

#include <gtest/gtest.h>
#include <Softloq/WHATWG/Infra/Primitive/CodePoint/CodePoint.hpp>
#include <sstream>

using namespace Softloq::WHATWG::Infra;

// ---------------------------------------------------------------------------
// Type identity
// ---------------------------------------------------------------------------

/**
 * @brief Test that get_type() returns PrimitiveType::CodePoint.
 */
TEST(CodePointPrimitiveTest, CodePointType)
{
    CodePoint cp;
    EXPECT_EQ(cp.get_type(), PrimitiveType::CodePoint);
}

/**
 * @brief Test that get_type() returns PrimitiveType::CodePoint when accessed through the base class pointer.
 */
TEST(CodePointPrimitiveTest, PolymorphicType)
{
    CodePoint cp;
    const Primitive* base = &cp;
    EXPECT_EQ(base->get_type(), PrimitiveType::CodePoint);
}

// ---------------------------------------------------------------------------
// Construction
// ---------------------------------------------------------------------------

/**
 * @brief Test that the default-constructed CodePoint holds U+0000.
 */
TEST(CodePointPrimitiveTest, DefaultConstructorIsNull)
{
    CodePoint cp;
    EXPECT_EQ(cp.get_value(), char32_t{0x0000});
}

/**
 * @brief Test that CodePoint constructed with U+0000 holds U+0000.
 */
TEST(CodePointPrimitiveTest, ValueConstruction_Zero)
{
    CodePoint cp{char32_t{0x0000}};
    EXPECT_EQ(cp.get_value(), char32_t{0x0000});
}

/**
 * @brief Test that CodePoint constructed with a BMP value holds that value.
 */
TEST(CodePointPrimitiveTest, ValueConstruction_BMP)
{
    CodePoint cp{char32_t{0x0041}}; // U+0041 LATIN CAPITAL LETTER A
    EXPECT_EQ(cp.get_value(), char32_t{0x0041});
}

/**
 * @brief Test that CodePoint constructed with a supplementary value holds that value.
 */
TEST(CodePointPrimitiveTest, ValueConstruction_Supplementary)
{
    CodePoint cp{char32_t{0x10000}}; // First supplementary code point
    EXPECT_EQ(cp.get_value(), char32_t{0x10000});
}

/**
 * @brief Test that CodePoint constructed with the maximum value (U+10FFFF) holds it.
 */
TEST(CodePointPrimitiveTest, ValueConstruction_Max)
{
    CodePoint cp{char32_t{0x10FFFF}};
    EXPECT_EQ(cp.get_value(), char32_t{0x10FFFF});
}

/**
 * @brief Test that CodePoint constructed with a surrogate value holds that value.
 */
TEST(CodePointPrimitiveTest, ValueConstruction_Surrogate)
{
    CodePoint cp{char32_t{0xD800}}; // First leading surrogate
    EXPECT_EQ(cp.get_value(), char32_t{0xD800});
}

// ---------------------------------------------------------------------------
// Mutation
// ---------------------------------------------------------------------------

/**
 * @brief Test that set_value stores a new non-zero value.
 */
TEST(CodePointPrimitiveTest, SetValue_NonZero)
{
    CodePoint cp;
    cp.set_value(char32_t{0x0041});
    EXPECT_EQ(cp.get_value(), char32_t{0x0041});
}

/**
 * @brief Test that set_value can store U+0000 after a non-zero construction.
 */
TEST(CodePointPrimitiveTest, SetValue_ToZero)
{
    CodePoint cp{char32_t{0x0041}};
    cp.set_value(char32_t{0x0000});
    EXPECT_EQ(cp.get_value(), char32_t{0x0000});
}

/**
 * @brief Test that set_value can store a supplementary code point.
 */
TEST(CodePointPrimitiveTest, SetValue_Supplementary)
{
    CodePoint cp;
    cp.set_value(char32_t{0x10FFFF});
    EXPECT_EQ(cp.get_value(), char32_t{0x10FFFF});
}

/**
 * @brief Test that set_value can be called multiple times, always reflecting the latest value.
 */
TEST(CodePointPrimitiveTest, SetValue_MultipleTimes)
{
    CodePoint cp;
    cp.set_value(char32_t{0x0041});
    EXPECT_EQ(cp.get_value(), char32_t{0x0041});
    cp.set_value(char32_t{0x10FFFF});
    EXPECT_EQ(cp.get_value(), char32_t{0x10FFFF});
    cp.set_value(char32_t{0x0000});
    EXPECT_EQ(cp.get_value(), char32_t{0x0000});
}

/**
 * @brief Test that set_value reflects the change on get_value immediately.
 */
TEST(CodePointPrimitiveTest, SetValue_ReflectedByGetValue)
{
    CodePoint cp{char32_t{0x0041}};
    cp.set_value(char32_t{0x0042});
    EXPECT_EQ(cp.get_value(), char32_t{0x0042});
    EXPECT_NE(cp.get_value(), char32_t{0x0041});
}

// ---------------------------------------------------------------------------
// Conversion operator
// ---------------------------------------------------------------------------

/**
 * @brief Test that explicit conversion to char32_t returns U+0000 for a default-constructed CodePoint.
 */
TEST(CodePointPrimitiveTest, OperatorChar32_Zero)
{
    CodePoint cp;
    EXPECT_EQ(static_cast<char32_t>(cp), char32_t{0x0000});
}

/**
 * @brief Test that explicit conversion to char32_t returns the correct BMP value.
 */
TEST(CodePointPrimitiveTest, OperatorChar32_BMP)
{
    CodePoint cp{char32_t{0x0041}};
    EXPECT_EQ(static_cast<char32_t>(cp), char32_t{0x0041});
}

/**
 * @brief Test that explicit conversion to char32_t returns U+10FFFF for the maximum CodePoint.
 */
TEST(CodePointPrimitiveTest, OperatorChar32_Max)
{
    CodePoint cp{char32_t{0x10FFFF}};
    EXPECT_EQ(static_cast<char32_t>(cp), char32_t{0x10FFFF});
}

/**
 * @brief Test that operator char32_t and get_value() are always consistent.
 */
TEST(CodePointPrimitiveTest, OperatorChar32_ConsistencyWithGetValue)
{
    CodePoint cp{char32_t{0x1F600}};
    EXPECT_EQ(static_cast<char32_t>(cp), cp.get_value());
}

// ---------------------------------------------------------------------------
// Equality
// ---------------------------------------------------------------------------

/**
 * @brief Test that a CodePoint instance is equal to itself (reflexive, U+0000).
 */
TEST(CodePointPrimitiveTest, EqualitySelf_Zero)
{
    CodePoint cp{char32_t{0x0000}};
    EXPECT_TRUE(cp == cp);
}

/**
 * @brief Test that a CodePoint instance is equal to itself (reflexive, non-zero value).
 */
TEST(CodePointPrimitiveTest, EqualitySelf_NonZero)
{
    CodePoint cp{char32_t{0x0041}};
    EXPECT_TRUE(cp == cp);
}

/**
 * @brief Test that two CodePoint instances with the same value are equal.
 */
TEST(CodePointPrimitiveTest, EqualitySameValue)
{
    CodePoint a{char32_t{0x0041}};
    CodePoint b{char32_t{0x0041}};
    EXPECT_TRUE(a == b);
}

/**
 * @brief Test that two CodePoint instances with different values are not equal.
 */
TEST(CodePointPrimitiveTest, EqualityDifferentValues)
{
    CodePoint a{char32_t{0x0041}};
    CodePoint b{char32_t{0x0042}};
    EXPECT_FALSE(a == b);
}

/**
 * @brief Test that equality is symmetric: a == b implies b == a.
 */
TEST(CodePointPrimitiveTest, EqualitySymmetry)
{
    CodePoint a{char32_t{0x0041}};
    CodePoint b{char32_t{0x0041}};
    EXPECT_EQ(a == b, b == a);

    CodePoint c{char32_t{0x0041}};
    CodePoint d{char32_t{0x0042}};
    EXPECT_EQ(c == d, d == c);
}

/**
 * @brief Test equality at boundary values (U+0000 and U+10FFFF).
 */
TEST(CodePointPrimitiveTest, EqualityBoundaryValues)
{
    CodePoint lo_a{char32_t{0x0000}};
    CodePoint lo_b{char32_t{0x0000}};
    EXPECT_TRUE(lo_a == lo_b);

    CodePoint hi_a{char32_t{0x10FFFF}};
    CodePoint hi_b{char32_t{0x10FFFF}};
    EXPECT_TRUE(hi_a == hi_b);

    EXPECT_FALSE(lo_a == hi_a);
}

// ---------------------------------------------------------------------------
// Inequality
// ---------------------------------------------------------------------------

/**
 * @brief Test that two CodePoint instances with the same value are not unequal.
 */
TEST(CodePointPrimitiveTest, InequalitySameValue)
{
    CodePoint a{char32_t{0x0041}};
    CodePoint b{char32_t{0x0041}};
    EXPECT_FALSE(a != b);
}

/**
 * @brief Test that two CodePoint instances with different values are unequal.
 */
TEST(CodePointPrimitiveTest, InequalityDifferentValues)
{
    CodePoint a{char32_t{0x0041}};
    CodePoint b{char32_t{0x0042}};
    EXPECT_TRUE(a != b);
}

/**
 * @brief Test that inequality is symmetric: a != b implies b != a.
 */
TEST(CodePointPrimitiveTest, InequalitySymmetry)
{
    CodePoint a{char32_t{0x0041}};
    CodePoint b{char32_t{0x0042}};
    EXPECT_EQ(a != b, b != a);
}

/**
 * @brief Test that equality and inequality are complementary: (a == b) != (a != b).
 */
TEST(CodePointPrimitiveTest, EqualityAndInequalityAreComplementary)
{
    CodePoint a{char32_t{0x0041}};
    CodePoint b{char32_t{0x0042}};
    EXPECT_NE(a == b, a != b);

    CodePoint c{char32_t{0x0041}};
    CodePoint d{char32_t{0x0041}};
    EXPECT_NE(c == d, c != d);
}

/**
 * @brief Test inequality at boundary values (U+0000 and U+10FFFF).
 */
TEST(CodePointPrimitiveTest, InequalityBoundaryValues)
{
    CodePoint lo{char32_t{0x0000}};
    CodePoint hi{char32_t{0x10FFFF}};
    EXPECT_TRUE(lo != hi);
    EXPECT_FALSE(lo != CodePoint{char32_t{0x0000}});
}

// ---------------------------------------------------------------------------
// Formatting
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0000 formats as "U+0000".
 */
TEST(CodePointPrimitiveTest, Formatting_Zero)
{
    CodePoint cp{char32_t{0x0000}};
    EXPECT_EQ(std::format("{}", cp), "U+0000");
}

/**
 * @brief Test that U+0041 formats as "U+0041" (four uppercase hex digits).
 */
TEST(CodePointPrimitiveTest, Formatting_FourDigits)
{
    CodePoint cp{char32_t{0x0041}};
    EXPECT_EQ(std::format("{}", cp), "U+0041");
}

/**
 * @brief Test that a BMP code point with all four hex digits set formats correctly.
 */
TEST(CodePointPrimitiveTest, Formatting_FFFF)
{
    CodePoint cp{char32_t{0xFFFF}};
    EXPECT_EQ(std::format("{}", cp), "U+FFFF");
}

/**
 * @brief Test that a five-digit supplementary code point formats with five digits.
 */
TEST(CodePointPrimitiveTest, Formatting_FiveDigits)
{
    CodePoint cp{char32_t{0x10000}};
    EXPECT_EQ(std::format("{}", cp), "U+10000");
}

/**
 * @brief Test that U+10FFFF (maximum) formats as "U+10FFFF" (six uppercase hex digits).
 */
TEST(CodePointPrimitiveTest, Formatting_Max)
{
    CodePoint cp{char32_t{0x10FFFF}};
    EXPECT_EQ(std::format("{}", cp), "U+10FFFF");
}

/**
 * @brief Test that lowercase letters in the value are formatted as uppercase.
 */
TEST(CodePointPrimitiveTest, Formatting_UppercaseHex)
{
    CodePoint cp{char32_t{0x00AB}};
    EXPECT_EQ(std::format("{}", cp), "U+00AB");
}

/**
 * @brief Test that formatting reflects the value after a set_value call.
 */
TEST(CodePointPrimitiveTest, Formatting_AfterSetValue)
{
    CodePoint cp;
    cp.set_value(char32_t{0x0041});
    EXPECT_EQ(std::format("{}", cp), "U+0041");
    cp.set_value(char32_t{0x10FFFF});
    EXPECT_EQ(std::format("{}", cp), "U+10FFFF");
}

// ---------------------------------------------------------------------------
// Output stream
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0000 streams as "U+0000".
 */
TEST(CodePointPrimitiveTest, OutputStream_Zero)
{
    CodePoint cp{char32_t{0x0000}};
    std::ostringstream oss;
    oss << cp;
    EXPECT_EQ(oss.str(), "U+0000");
}

/**
 * @brief Test that U+0041 streams as "U+0041".
 */
TEST(CodePointPrimitiveTest, OutputStream_BMP)
{
    CodePoint cp{char32_t{0x0041}};
    std::ostringstream oss;
    oss << cp;
    EXPECT_EQ(oss.str(), "U+0041");
}

/**
 * @brief Test that U+10FFFF streams as "U+10FFFF".
 */
TEST(CodePointPrimitiveTest, OutputStream_Max)
{
    CodePoint cp{char32_t{0x10FFFF}};
    std::ostringstream oss;
    oss << cp;
    EXPECT_EQ(oss.str(), "U+10FFFF");
}

/**
 * @brief Test that the output stream reflects the value after a set_value call.
 */
TEST(CodePointPrimitiveTest, OutputStream_AfterSetValue)
{
    CodePoint cp;
    cp.set_value(char32_t{0x0041});
    std::ostringstream oss;
    oss << cp;
    EXPECT_EQ(oss.str(), "U+0041");
}

// ---------------------------------------------------------------------------
// is_surrogate — U+D800 to U+DFFF
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+D800 (first leading surrogate) is a surrogate.
 */
TEST(CodePointPrimitiveTest, IsSurrogate_FirstLeading)
{
    EXPECT_TRUE(CodePoint{char32_t{0xD800}}.is_surrogate());
}

/**
 * @brief Test that U+DBFF (last leading surrogate) is a surrogate.
 */
TEST(CodePointPrimitiveTest, IsSurrogate_LastLeading)
{
    EXPECT_TRUE(CodePoint{char32_t{0xDBFF}}.is_surrogate());
}

/**
 * @brief Test that U+DC00 (first trailing surrogate) is a surrogate.
 */
TEST(CodePointPrimitiveTest, IsSurrogate_FirstTrailing)
{
    EXPECT_TRUE(CodePoint{char32_t{0xDC00}}.is_surrogate());
}

/**
 * @brief Test that U+DFFF (last trailing surrogate) is a surrogate.
 */
TEST(CodePointPrimitiveTest, IsSurrogate_LastTrailing)
{
    EXPECT_TRUE(CodePoint{char32_t{0xDFFF}}.is_surrogate());
}

/**
 * @brief Test that U+D7FF (just before surrogate range) is not a surrogate.
 */
TEST(CodePointPrimitiveTest, IsSurrogate_JustBefore)
{
    EXPECT_FALSE(CodePoint{char32_t{0xD7FF}}.is_surrogate());
}

/**
 * @brief Test that U+E000 (just after surrogate range) is not a surrogate.
 */
TEST(CodePointPrimitiveTest, IsSurrogate_JustAfter)
{
    EXPECT_FALSE(CodePoint{char32_t{0xE000}}.is_surrogate());
}

/**
 * @brief Test that U+0041 is not a surrogate.
 */
TEST(CodePointPrimitiveTest, IsSurrogate_ASCII)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0041}}.is_surrogate());
}

// ---------------------------------------------------------------------------
// is_leading_surrogate — U+D800 to U+DBFF
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+D800 is a leading surrogate.
 */
TEST(CodePointPrimitiveTest, IsLeadingSurrogate_First)
{
    EXPECT_TRUE(CodePoint{char32_t{0xD800}}.is_leading_surrogate());
}

/**
 * @brief Test that U+DBFF is a leading surrogate.
 */
TEST(CodePointPrimitiveTest, IsLeadingSurrogate_Last)
{
    EXPECT_TRUE(CodePoint{char32_t{0xDBFF}}.is_leading_surrogate());
}

/**
 * @brief Test that U+DC00 (trailing surrogate) is not a leading surrogate.
 */
TEST(CodePointPrimitiveTest, IsLeadingSurrogate_TrailingIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0xDC00}}.is_leading_surrogate());
}

/**
 * @brief Test that U+D7FF (just before leading surrogate range) is not a leading surrogate.
 */
TEST(CodePointPrimitiveTest, IsLeadingSurrogate_JustBefore)
{
    EXPECT_FALSE(CodePoint{char32_t{0xD7FF}}.is_leading_surrogate());
}

/**
 * @brief Test that U+DC00 (just after leading surrogate range) is not a leading surrogate.
 */
TEST(CodePointPrimitiveTest, IsLeadingSurrogate_JustAfter)
{
    EXPECT_FALSE(CodePoint{char32_t{0xDC00}}.is_leading_surrogate());
}

// ---------------------------------------------------------------------------
// is_trailing_surrogate — U+DC00 to U+DFFF
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+DC00 is a trailing surrogate.
 */
TEST(CodePointPrimitiveTest, IsTrailingSurrogate_First)
{
    EXPECT_TRUE(CodePoint{char32_t{0xDC00}}.is_trailing_surrogate());
}

/**
 * @brief Test that U+DFFF is a trailing surrogate.
 */
TEST(CodePointPrimitiveTest, IsTrailingSurrogate_Last)
{
    EXPECT_TRUE(CodePoint{char32_t{0xDFFF}}.is_trailing_surrogate());
}

/**
 * @brief Test that U+DBFF (leading surrogate) is not a trailing surrogate.
 */
TEST(CodePointPrimitiveTest, IsTrailingSurrogate_LeadingIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0xDBFF}}.is_trailing_surrogate());
}

/**
 * @brief Test that U+DBFF (just before trailing surrogate range) is not a trailing surrogate.
 */
TEST(CodePointPrimitiveTest, IsTrailingSurrogate_JustBefore)
{
    EXPECT_FALSE(CodePoint{char32_t{0xDBFF}}.is_trailing_surrogate());
}

/**
 * @brief Test that U+E000 (just after trailing surrogate range) is not a trailing surrogate.
 */
TEST(CodePointPrimitiveTest, IsTrailingSurrogate_JustAfter)
{
    EXPECT_FALSE(CodePoint{char32_t{0xE000}}.is_trailing_surrogate());
}

// ---------------------------------------------------------------------------
// is_scalar_value — not a surrogate (U+0000..U+D7FF, U+E000..U+10FFFF)
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0000 is a scalar value.
 */
TEST(CodePointPrimitiveTest, IsScalarValue_Zero)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0000}}.is_scalar_value());
}

/**
 * @brief Test that U+D7FF (just before surrogates) is a scalar value.
 */
TEST(CodePointPrimitiveTest, IsScalarValue_JustBeforeSurrogates)
{
    EXPECT_TRUE(CodePoint{char32_t{0xD7FF}}.is_scalar_value());
}

/**
 * @brief Test that U+D800 (leading surrogate) is not a scalar value.
 */
TEST(CodePointPrimitiveTest, IsScalarValue_LeadingSurrogateIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0xD800}}.is_scalar_value());
}

/**
 * @brief Test that U+DFFF (trailing surrogate) is not a scalar value.
 */
TEST(CodePointPrimitiveTest, IsScalarValue_TrailingSurrogateIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0xDFFF}}.is_scalar_value());
}

/**
 * @brief Test that U+E000 (just after surrogates) is a scalar value.
 */
TEST(CodePointPrimitiveTest, IsScalarValue_JustAfterSurrogates)
{
    EXPECT_TRUE(CodePoint{char32_t{0xE000}}.is_scalar_value());
}

/**
 * @brief Test that U+10FFFF (maximum code point) is a scalar value.
 */
TEST(CodePointPrimitiveTest, IsScalarValue_Max)
{
    EXPECT_TRUE(CodePoint{char32_t{0x10FFFF}}.is_scalar_value());
}

// ---------------------------------------------------------------------------
// is_noncharacter — U+FDD0..U+FDEF, U+xFFFE, U+xFFFF for x in 0x0..0x10
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+FDD0 (first of FDD0..FDEF range) is a noncharacter.
 */
TEST(CodePointPrimitiveTest, IsNoncharacter_FDD0)
{
    EXPECT_TRUE(CodePoint{char32_t{0xFDD0}}.is_noncharacter());
}

/**
 * @brief Test that U+FDEF (last of FDD0..FDEF range) is a noncharacter.
 */
TEST(CodePointPrimitiveTest, IsNoncharacter_FDEF)
{
    EXPECT_TRUE(CodePoint{char32_t{0xFDEF}}.is_noncharacter());
}

/**
 * @brief Test that U+FDCF (just before FDD0..FDEF range) is not a noncharacter.
 */
TEST(CodePointPrimitiveTest, IsNoncharacter_JustBeforeFDD0)
{
    EXPECT_FALSE(CodePoint{char32_t{0xFDCF}}.is_noncharacter());
}

/**
 * @brief Test that U+FDF0 (just after FDD0..FDEF range) is not a noncharacter.
 */
TEST(CodePointPrimitiveTest, IsNoncharacter_JustAfterFDEF)
{
    EXPECT_FALSE(CodePoint{char32_t{0xFDF0}}.is_noncharacter());
}

/**
 * @brief Test that U+FFFE is a noncharacter.
 */
TEST(CodePointPrimitiveTest, IsNoncharacter_FFFE)
{
    EXPECT_TRUE(CodePoint{char32_t{0xFFFE}}.is_noncharacter());
}

/**
 * @brief Test that U+FFFF is a noncharacter.
 */
TEST(CodePointPrimitiveTest, IsNoncharacter_FFFF)
{
    EXPECT_TRUE(CodePoint{char32_t{0xFFFF}}.is_noncharacter());
}

/**
 * @brief Test that U+1FFFE is a noncharacter.
 */
TEST(CodePointPrimitiveTest, IsNoncharacter_1FFFE)
{
    EXPECT_TRUE(CodePoint{char32_t{0x1FFFE}}.is_noncharacter());
}

/**
 * @brief Test that U+1FFFF is a noncharacter.
 */
TEST(CodePointPrimitiveTest, IsNoncharacter_1FFFF)
{
    EXPECT_TRUE(CodePoint{char32_t{0x1FFFF}}.is_noncharacter());
}

/**
 * @brief Test that U+10FFFE is a noncharacter.
 */
TEST(CodePointPrimitiveTest, IsNoncharacter_10FFFE)
{
    EXPECT_TRUE(CodePoint{char32_t{0x10FFFE}}.is_noncharacter());
}

/**
 * @brief Test that U+10FFFF is a noncharacter.
 */
TEST(CodePointPrimitiveTest, IsNoncharacter_10FFFF)
{
    EXPECT_TRUE(CodePoint{char32_t{0x10FFFF}}.is_noncharacter());
}

/**
 * @brief Test that U+10000 (first supplementary, not a noncharacter plane-end) is not a noncharacter.
 */
TEST(CodePointPrimitiveTest, IsNoncharacter_10000IsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x10000}}.is_noncharacter());
}

/**
 * @brief Test that U+0041 is not a noncharacter.
 */
TEST(CodePointPrimitiveTest, IsNoncharacter_ASCIIIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0041}}.is_noncharacter());
}

// ---------------------------------------------------------------------------
// is_ascii — U+0000 to U+007F
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0000 is an ASCII code point.
 */
TEST(CodePointPrimitiveTest, IsASCII_Zero)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0000}}.is_ascii());
}

/**
 * @brief Test that U+007F (DEL) is an ASCII code point.
 */
TEST(CodePointPrimitiveTest, IsASCII_DEL)
{
    EXPECT_TRUE(CodePoint{char32_t{0x007F}}.is_ascii());
}

/**
 * @brief Test that U+0041 (LATIN CAPITAL LETTER A) is an ASCII code point.
 */
TEST(CodePointPrimitiveTest, IsASCII_LetterA)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0041}}.is_ascii());
}

/**
 * @brief Test that U+0080 (first non-ASCII) is not an ASCII code point.
 */
TEST(CodePointPrimitiveTest, IsASCII_0080IsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0080}}.is_ascii());
}

/**
 * @brief Test that U+00FF is not an ASCII code point.
 */
TEST(CodePointPrimitiveTest, IsASCII_00FFIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x00FF}}.is_ascii());
}

/**
 * @brief Test that a supplementary code point is not an ASCII code point.
 */
TEST(CodePointPrimitiveTest, IsASCII_SupplementaryIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x10000}}.is_ascii());
}

// ---------------------------------------------------------------------------
// is_ascii_tab_or_newline — U+0009, U+000A, U+000D
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0009 (TAB) is an ASCII tab or newline.
 */
TEST(CodePointPrimitiveTest, IsASCIITabOrNewline_Tab)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0009}}.is_ascii_tab_or_newline());
}

/**
 * @brief Test that U+000A (LF) is an ASCII tab or newline.
 */
TEST(CodePointPrimitiveTest, IsASCIITabOrNewline_LF)
{
    EXPECT_TRUE(CodePoint{char32_t{0x000A}}.is_ascii_tab_or_newline());
}

/**
 * @brief Test that U+000D (CR) is an ASCII tab or newline.
 */
TEST(CodePointPrimitiveTest, IsASCIITabOrNewline_CR)
{
    EXPECT_TRUE(CodePoint{char32_t{0x000D}}.is_ascii_tab_or_newline());
}

/**
 * @brief Test that U+000C (FF) is not an ASCII tab or newline.
 */
TEST(CodePointPrimitiveTest, IsASCIITabOrNewline_FFIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x000C}}.is_ascii_tab_or_newline());
}

/**
 * @brief Test that U+0020 (SPACE) is not an ASCII tab or newline.
 */
TEST(CodePointPrimitiveTest, IsASCIITabOrNewline_SpaceIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0020}}.is_ascii_tab_or_newline());
}

/**
 * @brief Test that U+0041 is not an ASCII tab or newline.
 */
TEST(CodePointPrimitiveTest, IsASCIITabOrNewline_LetterIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0041}}.is_ascii_tab_or_newline());
}

// ---------------------------------------------------------------------------
// is_ascii_whitespace — U+0009, U+000A, U+000C, U+000D, U+0020
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0009 (TAB) is ASCII whitespace.
 */
TEST(CodePointPrimitiveTest, IsASCIIWhitespace_Tab)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0009}}.is_ascii_whitespace());
}

/**
 * @brief Test that U+000A (LF) is ASCII whitespace.
 */
TEST(CodePointPrimitiveTest, IsASCIIWhitespace_LF)
{
    EXPECT_TRUE(CodePoint{char32_t{0x000A}}.is_ascii_whitespace());
}

/**
 * @brief Test that U+000C (FF) is ASCII whitespace.
 */
TEST(CodePointPrimitiveTest, IsASCIIWhitespace_FF)
{
    EXPECT_TRUE(CodePoint{char32_t{0x000C}}.is_ascii_whitespace());
}

/**
 * @brief Test that U+000D (CR) is ASCII whitespace.
 */
TEST(CodePointPrimitiveTest, IsASCIIWhitespace_CR)
{
    EXPECT_TRUE(CodePoint{char32_t{0x000D}}.is_ascii_whitespace());
}

/**
 * @brief Test that U+0020 (SPACE) is ASCII whitespace.
 */
TEST(CodePointPrimitiveTest, IsASCIIWhitespace_Space)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0020}}.is_ascii_whitespace());
}

/**
 * @brief Test that U+000B (VT) is not ASCII whitespace.
 */
TEST(CodePointPrimitiveTest, IsASCIIWhitespace_VTIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x000B}}.is_ascii_whitespace());
}

/**
 * @brief Test that U+0021 (just after SPACE) is not ASCII whitespace.
 */
TEST(CodePointPrimitiveTest, IsASCIIWhitespace_0021IsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0021}}.is_ascii_whitespace());
}

/**
 * @brief Test that U+00A0 (non-breaking space) is not ASCII whitespace.
 */
TEST(CodePointPrimitiveTest, IsASCIIWhitespace_NBSPIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x00A0}}.is_ascii_whitespace());
}

// ---------------------------------------------------------------------------
// is_c0_control — U+0000 to U+001F
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0000 is a C0 control.
 */
TEST(CodePointPrimitiveTest, IsC0Control_Zero)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0000}}.is_c0_control());
}

/**
 * @brief Test that U+001F (last C0 control) is a C0 control.
 */
TEST(CodePointPrimitiveTest, IsC0Control_Last)
{
    EXPECT_TRUE(CodePoint{char32_t{0x001F}}.is_c0_control());
}

/**
 * @brief Test that U+0009 (TAB) is a C0 control.
 */
TEST(CodePointPrimitiveTest, IsC0Control_Tab)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0009}}.is_c0_control());
}

/**
 * @brief Test that U+0020 (SPACE) is not a C0 control.
 */
TEST(CodePointPrimitiveTest, IsC0Control_SpaceIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0020}}.is_c0_control());
}

/**
 * @brief Test that U+007F (DEL) is not a C0 control.
 */
TEST(CodePointPrimitiveTest, IsC0Control_DELIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x007F}}.is_c0_control());
}

/**
 * @brief Test that U+0041 is not a C0 control.
 */
TEST(CodePointPrimitiveTest, IsC0Control_LetterIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0041}}.is_c0_control());
}

// ---------------------------------------------------------------------------
// is_c0_control_or_space — C0 control or U+0020
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0000 is a C0 control or space.
 */
TEST(CodePointPrimitiveTest, IsC0ControlOrSpace_Zero)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0000}}.is_c0_control_or_space());
}

/**
 * @brief Test that U+001F is a C0 control or space.
 */
TEST(CodePointPrimitiveTest, IsC0ControlOrSpace_LastC0)
{
    EXPECT_TRUE(CodePoint{char32_t{0x001F}}.is_c0_control_or_space());
}

/**
 * @brief Test that U+0020 (SPACE) is a C0 control or space.
 */
TEST(CodePointPrimitiveTest, IsC0ControlOrSpace_Space)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0020}}.is_c0_control_or_space());
}

/**
 * @brief Test that U+0021 (just after SPACE) is not a C0 control or space.
 */
TEST(CodePointPrimitiveTest, IsC0ControlOrSpace_0021IsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0021}}.is_c0_control_or_space());
}

/**
 * @brief Test that U+007F (DEL) is not a C0 control or space.
 */
TEST(CodePointPrimitiveTest, IsC0ControlOrSpace_DELIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x007F}}.is_c0_control_or_space());
}

// ---------------------------------------------------------------------------
// is_control — C0 controls, U+007F DEL, U+0080..U+009F
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0000 (C0 control) is a control.
 */
TEST(CodePointPrimitiveTest, IsControl_C0First)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0000}}.is_control());
}

/**
 * @brief Test that U+001F (last C0 control) is a control.
 */
TEST(CodePointPrimitiveTest, IsControl_C0Last)
{
    EXPECT_TRUE(CodePoint{char32_t{0x001F}}.is_control());
}

/**
 * @brief Test that U+007F (DEL) is a control.
 */
TEST(CodePointPrimitiveTest, IsControl_DEL)
{
    EXPECT_TRUE(CodePoint{char32_t{0x007F}}.is_control());
}

/**
 * @brief Test that U+0080 (first C1 control) is a control.
 */
TEST(CodePointPrimitiveTest, IsControl_C1First)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0080}}.is_control());
}

/**
 * @brief Test that U+009F (last C1 control) is a control.
 */
TEST(CodePointPrimitiveTest, IsControl_C1Last)
{
    EXPECT_TRUE(CodePoint{char32_t{0x009F}}.is_control());
}

/**
 * @brief Test that U+0020 (SPACE) is not a control.
 */
TEST(CodePointPrimitiveTest, IsControl_SpaceIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0020}}.is_control());
}

/**
 * @brief Test that U+0041 is not a control.
 */
TEST(CodePointPrimitiveTest, IsControl_LetterIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0041}}.is_control());
}

/**
 * @brief Test that U+00A0 (non-breaking space, just after C1) is not a control.
 */
TEST(CodePointPrimitiveTest, IsControl_00A0IsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x00A0}}.is_control());
}

// ---------------------------------------------------------------------------
// is_ascii_digit — U+0030 to U+0039
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0030 ('0') is an ASCII digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIDigit_Zero)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0030}}.is_ascii_digit());
}

/**
 * @brief Test that U+0039 ('9') is an ASCII digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIDigit_Nine)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0039}}.is_ascii_digit());
}

/**
 * @brief Test that U+0035 ('5') is an ASCII digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIDigit_Five)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0035}}.is_ascii_digit());
}

/**
 * @brief Test that U+002F (just before digit range) is not an ASCII digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIDigit_JustBefore)
{
    EXPECT_FALSE(CodePoint{char32_t{0x002F}}.is_ascii_digit());
}

/**
 * @brief Test that U+003A (just after digit range) is not an ASCII digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIDigit_JustAfter)
{
    EXPECT_FALSE(CodePoint{char32_t{0x003A}}.is_ascii_digit());
}

/**
 * @brief Test that U+0041 ('A') is not an ASCII digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIDigit_LetterIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0041}}.is_ascii_digit());
}

// ---------------------------------------------------------------------------
// is_ascii_upper_hex_digit — U+0030..U+0039 or U+0041..U+0046
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0030 ('0') is an ASCII upper hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIUpperHexDigit_Zero)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0030}}.is_ascii_upper_hex_digit());
}

/**
 * @brief Test that U+0039 ('9') is an ASCII upper hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIUpperHexDigit_Nine)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0039}}.is_ascii_upper_hex_digit());
}

/**
 * @brief Test that U+0041 ('A') is an ASCII upper hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIUpperHexDigit_A)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0041}}.is_ascii_upper_hex_digit());
}

/**
 * @brief Test that U+0046 ('F') is an ASCII upper hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIUpperHexDigit_F)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0046}}.is_ascii_upper_hex_digit());
}

/**
 * @brief Test that U+0047 ('G') is not an ASCII upper hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIUpperHexDigit_GIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0047}}.is_ascii_upper_hex_digit());
}

/**
 * @brief Test that U+0061 ('a') is not an ASCII upper hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIUpperHexDigit_LowercaseIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0061}}.is_ascii_upper_hex_digit());
}

// ---------------------------------------------------------------------------
// is_ascii_lower_hex_digit — U+0030..U+0039 or U+0061..U+0066
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0030 ('0') is an ASCII lower hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIILowerHexDigit_Zero)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0030}}.is_ascii_lower_hex_digit());
}

/**
 * @brief Test that U+0039 ('9') is an ASCII lower hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIILowerHexDigit_Nine)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0039}}.is_ascii_lower_hex_digit());
}

/**
 * @brief Test that U+0061 ('a') is an ASCII lower hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIILowerHexDigit_A)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0061}}.is_ascii_lower_hex_digit());
}

/**
 * @brief Test that U+0066 ('f') is an ASCII lower hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIILowerHexDigit_F)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0066}}.is_ascii_lower_hex_digit());
}

/**
 * @brief Test that U+0067 ('g') is not an ASCII lower hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIILowerHexDigit_GIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0067}}.is_ascii_lower_hex_digit());
}

/**
 * @brief Test that U+0041 ('A') is not an ASCII lower hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIILowerHexDigit_UppercaseIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0041}}.is_ascii_lower_hex_digit());
}

// ---------------------------------------------------------------------------
// is_ascii_hex_digit — upper or lower hex digit
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0030 ('0') is an ASCII hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIHexDigit_Zero)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0030}}.is_ascii_hex_digit());
}

/**
 * @brief Test that U+0041 ('A') is an ASCII hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIHexDigit_UpperA)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0041}}.is_ascii_hex_digit());
}

/**
 * @brief Test that U+0046 ('F') is an ASCII hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIHexDigit_UpperF)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0046}}.is_ascii_hex_digit());
}

/**
 * @brief Test that U+0061 ('a') is an ASCII hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIHexDigit_LowerA)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0061}}.is_ascii_hex_digit());
}

/**
 * @brief Test that U+0066 ('f') is an ASCII hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIHexDigit_LowerF)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0066}}.is_ascii_hex_digit());
}

/**
 * @brief Test that U+0047 ('G') is not an ASCII hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIHexDigit_UpperGIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0047}}.is_ascii_hex_digit());
}

/**
 * @brief Test that U+0067 ('g') is not an ASCII hex digit.
 */
TEST(CodePointPrimitiveTest, IsASCIIHexDigit_LowerGIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0067}}.is_ascii_hex_digit());
}

// ---------------------------------------------------------------------------
// is_ascii_upper_alpha — U+0041 to U+005A
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0041 ('A') is an ASCII upper alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIIUpperAlpha_A)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0041}}.is_ascii_upper_alpha());
}

/**
 * @brief Test that U+005A ('Z') is an ASCII upper alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIIUpperAlpha_Z)
{
    EXPECT_TRUE(CodePoint{char32_t{0x005A}}.is_ascii_upper_alpha());
}

/**
 * @brief Test that U+0040 (just before 'A') is not an ASCII upper alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIIUpperAlpha_JustBefore)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0040}}.is_ascii_upper_alpha());
}

/**
 * @brief Test that U+005B (just after 'Z') is not an ASCII upper alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIIUpperAlpha_JustAfter)
{
    EXPECT_FALSE(CodePoint{char32_t{0x005B}}.is_ascii_upper_alpha());
}

/**
 * @brief Test that U+0061 ('a', lowercase) is not an ASCII upper alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIIUpperAlpha_LowercaseIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0061}}.is_ascii_upper_alpha());
}

// ---------------------------------------------------------------------------
// is_ascii_lower_alpha — U+0061 to U+007A
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0061 ('a') is an ASCII lower alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIILowerAlpha_A)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0061}}.is_ascii_lower_alpha());
}

/**
 * @brief Test that U+007A ('z') is an ASCII lower alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIILowerAlpha_Z)
{
    EXPECT_TRUE(CodePoint{char32_t{0x007A}}.is_ascii_lower_alpha());
}

/**
 * @brief Test that U+0060 (just before 'a') is not an ASCII lower alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIILowerAlpha_JustBefore)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0060}}.is_ascii_lower_alpha());
}

/**
 * @brief Test that U+007B (just after 'z') is not an ASCII lower alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIILowerAlpha_JustAfter)
{
    EXPECT_FALSE(CodePoint{char32_t{0x007B}}.is_ascii_lower_alpha());
}

/**
 * @brief Test that U+0041 ('A', uppercase) is not an ASCII lower alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIILowerAlpha_UppercaseIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0041}}.is_ascii_lower_alpha());
}

// ---------------------------------------------------------------------------
// is_ascii_alpha — upper or lower alpha
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0041 ('A') is an ASCII alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlpha_UpperA)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0041}}.is_ascii_alpha());
}

/**
 * @brief Test that U+005A ('Z') is an ASCII alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlpha_UpperZ)
{
    EXPECT_TRUE(CodePoint{char32_t{0x005A}}.is_ascii_alpha());
}

/**
 * @brief Test that U+0061 ('a') is an ASCII alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlpha_LowerA)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0061}}.is_ascii_alpha());
}

/**
 * @brief Test that U+007A ('z') is an ASCII alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlpha_LowerZ)
{
    EXPECT_TRUE(CodePoint{char32_t{0x007A}}.is_ascii_alpha());
}

/**
 * @brief Test that U+0030 ('0') is not an ASCII alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlpha_DigitIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0030}}.is_ascii_alpha());
}

/**
 * @brief Test that U+0040 ('@') is not an ASCII alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlpha_AtIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0040}}.is_ascii_alpha());
}

/**
 * @brief Test that U+005B ('[') is not an ASCII alpha.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlpha_BracketIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x005B}}.is_ascii_alpha());
}

// ---------------------------------------------------------------------------
// is_ascii_alphanumeric — digit or alpha
// ---------------------------------------------------------------------------

/**
 * @brief Test that U+0030 ('0') is ASCII alphanumeric.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlphanumeric_Digit)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0030}}.is_ascii_alphanumeric());
}

/**
 * @brief Test that U+0039 ('9') is ASCII alphanumeric.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlphanumeric_DigitNine)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0039}}.is_ascii_alphanumeric());
}

/**
 * @brief Test that U+0041 ('A') is ASCII alphanumeric.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlphanumeric_UpperA)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0041}}.is_ascii_alphanumeric());
}

/**
 * @brief Test that U+005A ('Z') is ASCII alphanumeric.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlphanumeric_UpperZ)
{
    EXPECT_TRUE(CodePoint{char32_t{0x005A}}.is_ascii_alphanumeric());
}

/**
 * @brief Test that U+0061 ('a') is ASCII alphanumeric.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlphanumeric_LowerA)
{
    EXPECT_TRUE(CodePoint{char32_t{0x0061}}.is_ascii_alphanumeric());
}

/**
 * @brief Test that U+007A ('z') is ASCII alphanumeric.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlphanumeric_LowerZ)
{
    EXPECT_TRUE(CodePoint{char32_t{0x007A}}.is_ascii_alphanumeric());
}

/**
 * @brief Test that U+0020 (SPACE) is not ASCII alphanumeric.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlphanumeric_SpaceIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0020}}.is_ascii_alphanumeric());
}

/**
 * @brief Test that U+002F ('/') is not ASCII alphanumeric.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlphanumeric_SlashIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x002F}}.is_ascii_alphanumeric());
}

/**
 * @brief Test that U+003A (':') is not ASCII alphanumeric.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlphanumeric_ColonIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x003A}}.is_ascii_alphanumeric());
}

/**
 * @brief Test that U+0040 ('@') is not ASCII alphanumeric.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlphanumeric_AtIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x0040}}.is_ascii_alphanumeric());
}

/**
 * @brief Test that U+00FF is not ASCII alphanumeric.
 */
TEST(CodePointPrimitiveTest, IsASCIIAlphanumeric_NonASCIIIsNot)
{
    EXPECT_FALSE(CodePoint{char32_t{0x00FF}}.is_ascii_alphanumeric());
}
