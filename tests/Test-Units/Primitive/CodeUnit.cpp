/**
 * @file Test-Units/Primitive/CodeUnit.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Unit tests for the CodeUnit primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains unit tests for the CodeUnit primitive type in the WHATWG Infra library.
 */

#include <gtest/gtest.h>
#include <Softloq/WHATWG/Infra/Primitive/CodeUnit/CodeUnit.hpp>
#include <sstream>

using namespace Softloq::WHATWG::Infra;

// ---------------------------------------------------------------------------
// Type identity
// ---------------------------------------------------------------------------

/**
 * @brief Test that get_type() returns PrimitiveType::CodeUnit.
 */
TEST(CodeUnitPrimitiveTest, CodeUnitType)
{
    CodeUnit cu;
    EXPECT_EQ(cu.get_type(), PrimitiveType::CodeUnit);
}

/**
 * @brief Test that get_type() returns PrimitiveType::CodeUnit when accessed through the base class pointer.
 */
TEST(CodeUnitPrimitiveTest, PolymorphicType)
{
    CodeUnit cu;
    const Primitive* base = &cu;
    EXPECT_EQ(base->get_type(), PrimitiveType::CodeUnit);
}

// ---------------------------------------------------------------------------
// Construction
// ---------------------------------------------------------------------------

/**
 * @brief Test that the default-constructed CodeUnit holds 0x0000.
 */
TEST(CodeUnitPrimitiveTest, DefaultConstructorIsZero)
{
    CodeUnit cu;
    EXPECT_EQ(cu.get_value(), std::uint16_t{0x0000});
}

/**
 * @brief Test that CodeUnit constructed with 0x0000 holds 0x0000.
 */
TEST(CodeUnitPrimitiveTest, ValueConstruction_Zero)
{
    CodeUnit cu{std::uint16_t{0x0000}};
    EXPECT_EQ(cu.get_value(), std::uint16_t{0x0000});
}

/**
 * @brief Test that CodeUnit constructed with an ASCII value holds that value.
 */
TEST(CodeUnitPrimitiveTest, ValueConstruction_ASCII)
{
    CodeUnit cu{std::uint16_t{0x0041}}; // 'A'
    EXPECT_EQ(cu.get_value(), std::uint16_t{0x0041});
}

/**
 * @brief Test that CodeUnit constructed with a leading surrogate value holds that value.
 */
TEST(CodeUnitPrimitiveTest, ValueConstruction_LeadingSurrogate)
{
    CodeUnit cu{std::uint16_t{0xD800}};
    EXPECT_EQ(cu.get_value(), std::uint16_t{0xD800});
}

/**
 * @brief Test that CodeUnit constructed with a trailing surrogate value holds that value.
 */
TEST(CodeUnitPrimitiveTest, ValueConstruction_TrailingSurrogate)
{
    CodeUnit cu{std::uint16_t{0xDFFF}};
    EXPECT_EQ(cu.get_value(), std::uint16_t{0xDFFF});
}

/**
 * @brief Test that CodeUnit constructed with the maximum value (0xFFFF) holds 0xFFFF.
 */
TEST(CodeUnitPrimitiveTest, ValueConstruction_Max)
{
    CodeUnit cu{std::uint16_t{0xFFFF}};
    EXPECT_EQ(cu.get_value(), std::uint16_t{0xFFFF});
}

// ---------------------------------------------------------------------------
// Mutation
// ---------------------------------------------------------------------------

/**
 * @brief Test that set_value stores a new non-zero value.
 */
TEST(CodeUnitPrimitiveTest, SetValue_NonZero)
{
    CodeUnit cu;
    cu.set_value(std::uint16_t{0x0041});
    EXPECT_EQ(cu.get_value(), std::uint16_t{0x0041});
}

/**
 * @brief Test that set_value can store 0x0000 after a non-zero construction.
 */
TEST(CodeUnitPrimitiveTest, SetValue_ToZero)
{
    CodeUnit cu{std::uint16_t{0x0041}};
    cu.set_value(std::uint16_t{0x0000});
    EXPECT_EQ(cu.get_value(), std::uint16_t{0x0000});
}

/**
 * @brief Test that set_value can store the maximum value (0xFFFF).
 */
TEST(CodeUnitPrimitiveTest, SetValue_ToMax)
{
    CodeUnit cu;
    cu.set_value(std::uint16_t{0xFFFF});
    EXPECT_EQ(cu.get_value(), std::uint16_t{0xFFFF});
}

/**
 * @brief Test that set_value can be called multiple times, always reflecting the latest value.
 */
TEST(CodeUnitPrimitiveTest, SetValue_MultipleTimes)
{
    CodeUnit cu;
    cu.set_value(std::uint16_t{0x0041});
    EXPECT_EQ(cu.get_value(), std::uint16_t{0x0041});
    cu.set_value(std::uint16_t{0xD800});
    EXPECT_EQ(cu.get_value(), std::uint16_t{0xD800});
    cu.set_value(std::uint16_t{0x0000});
    EXPECT_EQ(cu.get_value(), std::uint16_t{0x0000});
}

/**
 * @brief Test that set_value reflects the change on get_value immediately.
 */
TEST(CodeUnitPrimitiveTest, SetValue_ReflectedByGetValue)
{
    CodeUnit cu{std::uint16_t{0x0041}};
    cu.set_value(std::uint16_t{0x0042});
    EXPECT_EQ(cu.get_value(), std::uint16_t{0x0042});
    EXPECT_NE(cu.get_value(), std::uint16_t{0x0041});
}

// ---------------------------------------------------------------------------
// Conversion operator
// ---------------------------------------------------------------------------

/**
 * @brief Test that explicit conversion to std::uint16_t returns 0x0000 for a default-constructed CodeUnit.
 */
TEST(CodeUnitPrimitiveTest, OperatorUInt16_Zero)
{
    CodeUnit cu;
    EXPECT_EQ(static_cast<std::uint16_t>(cu), std::uint16_t{0x0000});
}

/**
 * @brief Test that explicit conversion to std::uint16_t returns the correct value.
 */
TEST(CodeUnitPrimitiveTest, OperatorUInt16_Value)
{
    CodeUnit cu{std::uint16_t{0x0041}};
    EXPECT_EQ(static_cast<std::uint16_t>(cu), std::uint16_t{0x0041});
}

/**
 * @brief Test that explicit conversion to std::uint16_t returns 0xFFFF for the maximum CodeUnit.
 */
TEST(CodeUnitPrimitiveTest, OperatorUInt16_Max)
{
    CodeUnit cu{std::uint16_t{0xFFFF}};
    EXPECT_EQ(static_cast<std::uint16_t>(cu), std::uint16_t{0xFFFF});
}

/**
 * @brief Test that operator std::uint16_t and get_value() are always consistent.
 */
TEST(CodeUnitPrimitiveTest, OperatorUInt16_ConsistencyWithGetValue)
{
    CodeUnit cu{std::uint16_t{0xD800}};
    EXPECT_EQ(static_cast<std::uint16_t>(cu), cu.get_value());
}

// ---------------------------------------------------------------------------
// Equality
// ---------------------------------------------------------------------------

/**
 * @brief Test that a CodeUnit instance is equal to itself (reflexive, 0x0000).
 */
TEST(CodeUnitPrimitiveTest, EqualitySelf_Zero)
{
    CodeUnit cu{std::uint16_t{0x0000}};
    EXPECT_TRUE(cu == cu);
}

/**
 * @brief Test that a CodeUnit instance is equal to itself (reflexive, non-zero value).
 */
TEST(CodeUnitPrimitiveTest, EqualitySelf_NonZero)
{
    CodeUnit cu{std::uint16_t{0x0041}};
    EXPECT_TRUE(cu == cu);
}

/**
 * @brief Test that two CodeUnit instances with the same value are equal.
 */
TEST(CodeUnitPrimitiveTest, EqualitySameValue)
{
    CodeUnit a{std::uint16_t{0x0041}};
    CodeUnit b{std::uint16_t{0x0041}};
    EXPECT_TRUE(a == b);
}

/**
 * @brief Test that two CodeUnit instances with different values are not equal.
 */
TEST(CodeUnitPrimitiveTest, EqualityDifferentValues)
{
    CodeUnit a{std::uint16_t{0x0041}};
    CodeUnit b{std::uint16_t{0x0042}};
    EXPECT_FALSE(a == b);
}

/**
 * @brief Test that equality is symmetric: a == b implies b == a.
 */
TEST(CodeUnitPrimitiveTest, EqualitySymmetry)
{
    CodeUnit a{std::uint16_t{0x0041}};
    CodeUnit b{std::uint16_t{0x0041}};
    EXPECT_EQ(a == b, b == a);

    CodeUnit c{std::uint16_t{0x0041}};
    CodeUnit d{std::uint16_t{0x0042}};
    EXPECT_EQ(c == d, d == c);
}

/**
 * @brief Test equality at boundary values (0x0000 and 0xFFFF).
 */
TEST(CodeUnitPrimitiveTest, EqualityBoundaryValues)
{
    CodeUnit lo_a{std::uint16_t{0x0000}};
    CodeUnit lo_b{std::uint16_t{0x0000}};
    EXPECT_TRUE(lo_a == lo_b);

    CodeUnit hi_a{std::uint16_t{0xFFFF}};
    CodeUnit hi_b{std::uint16_t{0xFFFF}};
    EXPECT_TRUE(hi_a == hi_b);

    EXPECT_FALSE(lo_a == hi_a);
}

// ---------------------------------------------------------------------------
// Inequality
// ---------------------------------------------------------------------------

/**
 * @brief Test that two CodeUnit instances with the same value are not unequal.
 */
TEST(CodeUnitPrimitiveTest, InequalitySameValue)
{
    CodeUnit a{std::uint16_t{0x0041}};
    CodeUnit b{std::uint16_t{0x0041}};
    EXPECT_FALSE(a != b);
}

/**
 * @brief Test that two CodeUnit instances with different values are unequal.
 */
TEST(CodeUnitPrimitiveTest, InequalityDifferentValues)
{
    CodeUnit a{std::uint16_t{0x0041}};
    CodeUnit b{std::uint16_t{0x0042}};
    EXPECT_TRUE(a != b);
}

/**
 * @brief Test that inequality is symmetric: a != b implies b != a.
 */
TEST(CodeUnitPrimitiveTest, InequalitySymmetry)
{
    CodeUnit a{std::uint16_t{0x0041}};
    CodeUnit b{std::uint16_t{0x0042}};
    EXPECT_EQ(a != b, b != a);
}

/**
 * @brief Test that equality and inequality are complementary: (a == b) != (a != b).
 */
TEST(CodeUnitPrimitiveTest, EqualityAndInequalityAreComplementary)
{
    CodeUnit a{std::uint16_t{0x0041}};
    CodeUnit b{std::uint16_t{0x0042}};
    EXPECT_NE(a == b, a != b);

    CodeUnit c{std::uint16_t{0x0041}};
    CodeUnit d{std::uint16_t{0x0041}};
    EXPECT_NE(c == d, c != d);
}

/**
 * @brief Test inequality at boundary values (0x0000 and 0xFFFF).
 */
TEST(CodeUnitPrimitiveTest, InequalityBoundaryValues)
{
    CodeUnit lo{std::uint16_t{0x0000}};
    CodeUnit hi{std::uint16_t{0xFFFF}};
    EXPECT_TRUE(lo != hi);
    EXPECT_FALSE(lo != CodeUnit{std::uint16_t{0x0000}});
}

// ---------------------------------------------------------------------------
// Formatting
// ---------------------------------------------------------------------------

/**
 * @brief Test that a CodeUnit with value 0x0000 formats as "0x0000".
 */
TEST(CodeUnitPrimitiveTest, Formatting_Zero)
{
    CodeUnit cu{std::uint16_t{0x0000}};
    EXPECT_EQ(std::format("{}", cu), "0x0000");
}

/**
 * @brief Test that a CodeUnit with value 0xFFFF formats as "0xFFFF".
 */
TEST(CodeUnitPrimitiveTest, Formatting_Max)
{
    CodeUnit cu{std::uint16_t{0xFFFF}};
    EXPECT_EQ(std::format("{}", cu), "0xFFFF");
}

/**
 * @brief Test that a CodeUnit with value 0x0041 formats as "0x0041" (not "A" or "65").
 */
TEST(CodeUnitPrimitiveTest, Formatting_NotChar)
{
    CodeUnit cu{std::uint16_t{0x0041}};
    EXPECT_EQ(std::format("{}", cu), "0x0041");
}

/**
 * @brief Test that a CodeUnit with a leading surrogate value formats correctly.
 */
TEST(CodeUnitPrimitiveTest, Formatting_LeadingSurrogate)
{
    CodeUnit cu{std::uint16_t{0xD800}};
    EXPECT_EQ(std::format("{}", cu), "0xD800");
}

/**
 * @brief Test that a CodeUnit with a mid-range value formats with the correct zero-padding.
 */
TEST(CodeUnitPrimitiveTest, Formatting_ZeroPadded)
{
    CodeUnit cu{std::uint16_t{0x00FF}};
    EXPECT_EQ(std::format("{}", cu), "0x00FF");
}

/**
 * @brief Test that formatting reflects the value after a set_value call.
 */
TEST(CodeUnitPrimitiveTest, Formatting_AfterSetValue)
{
    CodeUnit cu;
    cu.set_value(std::uint16_t{0xDC00});
    EXPECT_EQ(std::format("{}", cu), "0xDC00");
    cu.set_value(std::uint16_t{0x007F});
    EXPECT_EQ(std::format("{}", cu), "0x007F");
}

// ---------------------------------------------------------------------------
// Output stream
// ---------------------------------------------------------------------------

/**
 * @brief Test that a CodeUnit with value 0x0000 streams as "0x0000".
 */
TEST(CodeUnitPrimitiveTest, OutputStream_Zero)
{
    CodeUnit cu{std::uint16_t{0x0000}};
    std::ostringstream oss;
    oss << cu;
    EXPECT_EQ(oss.str(), "0x0000");
}

/**
 * @brief Test that a CodeUnit with value 0xFFFF streams as "0xFFFF".
 */
TEST(CodeUnitPrimitiveTest, OutputStream_Max)
{
    CodeUnit cu{std::uint16_t{0xFFFF}};
    std::ostringstream oss;
    oss << cu;
    EXPECT_EQ(oss.str(), "0xFFFF");
}

/**
 * @brief Test that a CodeUnit with value 0x0041 streams as "0x0041" (not "A" or "65").
 */
TEST(CodeUnitPrimitiveTest, OutputStream_NotChar)
{
    CodeUnit cu{std::uint16_t{0x0041}};
    std::ostringstream oss;
    oss << cu;
    EXPECT_EQ(oss.str(), "0x0041");
}

/**
 * @brief Test that the output stream reflects the value after a set_value call.
 */
TEST(CodeUnitPrimitiveTest, OutputStream_AfterSetValue)
{
    CodeUnit cu;
    cu.set_value(std::uint16_t{0xD800});
    std::ostringstream oss;
    oss << cu;
    EXPECT_EQ(oss.str(), "0xD800");
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_surrogate
// ---------------------------------------------------------------------------

/**
 * @brief Test that the first leading surrogate (0xD800) is a surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsSurrogate_FirstLeading)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0xD800}}.is_surrogate());
}

/**
 * @brief Test that the last trailing surrogate (0xDFFF) is a surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsSurrogate_LastTrailing)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0xDFFF}}.is_surrogate());
}

/**
 * @brief Test that a mid-surrogate value (0xDC00) is a surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsSurrogate_MidRange)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0xDC00}}.is_surrogate());
}

/**
 * @brief Test that the code unit just before the surrogate range (0xD7FF) is not a surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsSurrogate_BelowRange)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0xD7FF}}.is_surrogate());
}

/**
 * @brief Test that the code unit just after the surrogate range (0xE000) is not a surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsSurrogate_AboveRange)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0xE000}}.is_surrogate());
}

/**
 * @brief Test that an ASCII code unit is not a surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsSurrogate_ASCII)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0041}}.is_surrogate());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_leading_surrogate
// ---------------------------------------------------------------------------

/**
 * @brief Test that 0xD800 is a leading surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsLeadingSurrogate_First)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0xD800}}.is_leading_surrogate());
}

/**
 * @brief Test that 0xDBFF is a leading surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsLeadingSurrogate_Last)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0xDBFF}}.is_leading_surrogate());
}

/**
 * @brief Test that 0xD900 (mid leading surrogate range) is a leading surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsLeadingSurrogate_MidRange)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0xD900}}.is_leading_surrogate());
}

/**
 * @brief Test that 0xDC00 (first trailing surrogate) is not a leading surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsLeadingSurrogate_TrailingIsNot)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0xDC00}}.is_leading_surrogate());
}

/**
 * @brief Test that a non-surrogate code unit is not a leading surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsLeadingSurrogate_NonSurrogate)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0041}}.is_leading_surrogate());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_trailing_surrogate
// ---------------------------------------------------------------------------

/**
 * @brief Test that 0xDC00 is a trailing surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsTrailingSurrogate_First)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0xDC00}}.is_trailing_surrogate());
}

/**
 * @brief Test that 0xDFFF is a trailing surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsTrailingSurrogate_Last)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0xDFFF}}.is_trailing_surrogate());
}

/**
 * @brief Test that 0xDE00 (mid trailing surrogate range) is a trailing surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsTrailingSurrogate_MidRange)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0xDE00}}.is_trailing_surrogate());
}

/**
 * @brief Test that 0xDBFF (last leading surrogate) is not a trailing surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsTrailingSurrogate_LeadingIsNot)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0xDBFF}}.is_trailing_surrogate());
}

/**
 * @brief Test that a non-surrogate code unit is not a trailing surrogate.
 */
TEST(CodeUnitPrimitiveTest, IsTrailingSurrogate_NonSurrogate)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0041}}.is_trailing_surrogate());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_ascii
// ---------------------------------------------------------------------------

/**
 * @brief Test that 0x0000 is an ASCII code unit.
 */
TEST(CodeUnitPrimitiveTest, IsASCII_Zero)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0000}}.is_ascii());
}

/**
 * @brief Test that 0x007F is an ASCII code unit.
 */
TEST(CodeUnitPrimitiveTest, IsASCII_Max)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x007F}}.is_ascii());
}

/**
 * @brief Test that 0x0041 ('A') is an ASCII code unit.
 */
TEST(CodeUnitPrimitiveTest, IsASCII_UpperAlpha)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0041}}.is_ascii());
}

/**
 * @brief Test that 0x0080 is not an ASCII code unit.
 */
TEST(CodeUnitPrimitiveTest, IsASCII_AboveRange)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0080}}.is_ascii());
}

/**
 * @brief Test that a surrogate code unit is not an ASCII code unit.
 */
TEST(CodeUnitPrimitiveTest, IsASCII_Surrogate)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0xD800}}.is_ascii());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_ascii_tab_or_newline
// ---------------------------------------------------------------------------

/**
 * @brief Test that 0x0009 (tab) is an ASCII tab or newline.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiTabOrNewline_Tab)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0009}}.is_ascii_tab_or_newline());
}

/**
 * @brief Test that 0x000A (LF) is an ASCII tab or newline.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiTabOrNewline_LF)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x000A}}.is_ascii_tab_or_newline());
}

/**
 * @brief Test that 0x000D (CR) is an ASCII tab or newline.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiTabOrNewline_CR)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x000D}}.is_ascii_tab_or_newline());
}

/**
 * @brief Test that 0x000C (FF) is not an ASCII tab or newline.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiTabOrNewline_FF)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x000C}}.is_ascii_tab_or_newline());
}

/**
 * @brief Test that 0x0020 (space) is not an ASCII tab or newline.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiTabOrNewline_Space)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0020}}.is_ascii_tab_or_newline());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_ascii_whitespace
// ---------------------------------------------------------------------------

/**
 * @brief Test that 0x0009 (tab) is ASCII whitespace.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiWhitespace_Tab)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0009}}.is_ascii_whitespace());
}

/**
 * @brief Test that 0x000A (LF) is ASCII whitespace.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiWhitespace_LF)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x000A}}.is_ascii_whitespace());
}

/**
 * @brief Test that 0x000C (FF) is ASCII whitespace.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiWhitespace_FF)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x000C}}.is_ascii_whitespace());
}

/**
 * @brief Test that 0x000D (CR) is ASCII whitespace.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiWhitespace_CR)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x000D}}.is_ascii_whitespace());
}

/**
 * @brief Test that 0x0020 (space) is ASCII whitespace.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiWhitespace_Space)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0020}}.is_ascii_whitespace());
}

/**
 * @brief Test that 0x0021 ('!') is not ASCII whitespace.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiWhitespace_Exclamation)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0021}}.is_ascii_whitespace());
}

/**
 * @brief Test that 0x000B (VT) is not ASCII whitespace.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiWhitespace_VT)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x000B}}.is_ascii_whitespace());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_c0_control
// ---------------------------------------------------------------------------

/**
 * @brief Test that 0x0000 (NUL) is a C0 control.
 */
TEST(CodeUnitPrimitiveTest, IsC0Control_NUL)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0000}}.is_c0_control());
}

/**
 * @brief Test that 0x001F (US) is a C0 control.
 */
TEST(CodeUnitPrimitiveTest, IsC0Control_Last)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x001F}}.is_c0_control());
}

/**
 * @brief Test that 0x0009 (tab) is a C0 control.
 */
TEST(CodeUnitPrimitiveTest, IsC0Control_Tab)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0009}}.is_c0_control());
}

/**
 * @brief Test that 0x0020 (space) is not a C0 control.
 */
TEST(CodeUnitPrimitiveTest, IsC0Control_Space)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0020}}.is_c0_control());
}

/**
 * @brief Test that 0x0041 ('A') is not a C0 control.
 */
TEST(CodeUnitPrimitiveTest, IsC0Control_Alpha)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0041}}.is_c0_control());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_c0_control_or_space
// ---------------------------------------------------------------------------

/**
 * @brief Test that a C0 control code unit satisfies is_c0_control_or_space.
 */
TEST(CodeUnitPrimitiveTest, IsC0ControlOrSpace_C0)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0000}}.is_c0_control_or_space());
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x001F}}.is_c0_control_or_space());
}

/**
 * @brief Test that 0x0020 (space) satisfies is_c0_control_or_space.
 */
TEST(CodeUnitPrimitiveTest, IsC0ControlOrSpace_Space)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0020}}.is_c0_control_or_space());
}

/**
 * @brief Test that 0x0021 ('!') does not satisfy is_c0_control_or_space.
 */
TEST(CodeUnitPrimitiveTest, IsC0ControlOrSpace_Exclamation)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0021}}.is_c0_control_or_space());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_control
// ---------------------------------------------------------------------------

/**
 * @brief Test that a C0 control code unit is a control.
 */
TEST(CodeUnitPrimitiveTest, IsControl_C0)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0000}}.is_control());
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x001F}}.is_control());
}

/**
 * @brief Test that 0x007F (DEL) is a control.
 */
TEST(CodeUnitPrimitiveTest, IsControl_DEL)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x007F}}.is_control());
}

/**
 * @brief Test that 0x0080 is a control.
 */
TEST(CodeUnitPrimitiveTest, IsControl_C1First)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0080}}.is_control());
}

/**
 * @brief Test that 0x009F is a control.
 */
TEST(CodeUnitPrimitiveTest, IsControl_C1Last)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x009F}}.is_control());
}

/**
 * @brief Test that 0x0020 (space) is not a control.
 */
TEST(CodeUnitPrimitiveTest, IsControl_Space)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0020}}.is_control());
}

/**
 * @brief Test that 0x0041 ('A') is not a control.
 */
TEST(CodeUnitPrimitiveTest, IsControl_Alpha)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0041}}.is_control());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_ascii_digit
// ---------------------------------------------------------------------------

/**
 * @brief Test that 0x0030 ('0') is an ASCII digit.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiDigit_First)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0030}}.is_ascii_digit());
}

/**
 * @brief Test that 0x0039 ('9') is an ASCII digit.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiDigit_Last)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0039}}.is_ascii_digit());
}

/**
 * @brief Test that 0x0035 ('5') is an ASCII digit.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiDigit_MidRange)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0035}}.is_ascii_digit());
}

/**
 * @brief Test that 0x002F ('/') is not an ASCII digit.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiDigit_BelowRange)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x002F}}.is_ascii_digit());
}

/**
 * @brief Test that 0x003A (':') is not an ASCII digit.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiDigit_AboveRange)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x003A}}.is_ascii_digit());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_ascii_upper_hex_digit
// ---------------------------------------------------------------------------

/**
 * @brief Test that ASCII digits (0x0030..0x0039) are ASCII upper hex digits.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiUpperHexDigit_Digit)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0030}}.is_ascii_upper_hex_digit());
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0039}}.is_ascii_upper_hex_digit());
}

/**
 * @brief Test that 0x0041 ('A') through 0x0046 ('F') are ASCII upper hex digits.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiUpperHexDigit_UpperAF)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0041}}.is_ascii_upper_hex_digit());
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0046}}.is_ascii_upper_hex_digit());
}

/**
 * @brief Test that 0x0047 ('G') is not an ASCII upper hex digit.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiUpperHexDigit_G)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0047}}.is_ascii_upper_hex_digit());
}

/**
 * @brief Test that 0x0061 ('a') is not an ASCII upper hex digit.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiUpperHexDigit_LowerA)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0061}}.is_ascii_upper_hex_digit());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_ascii_lower_hex_digit
// ---------------------------------------------------------------------------

/**
 * @brief Test that ASCII digits (0x0030..0x0039) are ASCII lower hex digits.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiLowerHexDigit_Digit)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0030}}.is_ascii_lower_hex_digit());
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0039}}.is_ascii_lower_hex_digit());
}

/**
 * @brief Test that 0x0061 ('a') through 0x0066 ('f') are ASCII lower hex digits.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiLowerHexDigit_LowerAF)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0061}}.is_ascii_lower_hex_digit());
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0066}}.is_ascii_lower_hex_digit());
}

/**
 * @brief Test that 0x0067 ('g') is not an ASCII lower hex digit.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiLowerHexDigit_G)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0067}}.is_ascii_lower_hex_digit());
}

/**
 * @brief Test that 0x0041 ('A') is not an ASCII lower hex digit.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiLowerHexDigit_UpperA)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0041}}.is_ascii_lower_hex_digit());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_ascii_hex_digit
// ---------------------------------------------------------------------------

/**
 * @brief Test that an ASCII upper hex digit satisfies is_ascii_hex_digit.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiHexDigit_UpperHex)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0046}}.is_ascii_hex_digit()); // 'F'
}

/**
 * @brief Test that an ASCII lower hex digit satisfies is_ascii_hex_digit.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiHexDigit_LowerHex)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0066}}.is_ascii_hex_digit()); // 'f'
}

/**
 * @brief Test that a decimal digit satisfies is_ascii_hex_digit.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiHexDigit_Digit)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0035}}.is_ascii_hex_digit()); // '5'
}

/**
 * @brief Test that 0x0047 ('G') does not satisfy is_ascii_hex_digit.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiHexDigit_G)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0047}}.is_ascii_hex_digit());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_ascii_upper_alpha
// ---------------------------------------------------------------------------

/**
 * @brief Test that 0x0041 ('A') is an ASCII upper alpha.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiUpperAlpha_First)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0041}}.is_ascii_upper_alpha());
}

/**
 * @brief Test that 0x005A ('Z') is an ASCII upper alpha.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiUpperAlpha_Last)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x005A}}.is_ascii_upper_alpha());
}

/**
 * @brief Test that 0x0061 ('a') is not an ASCII upper alpha.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiUpperAlpha_Lowercase)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0061}}.is_ascii_upper_alpha());
}

/**
 * @brief Test that 0x005B ('[') is not an ASCII upper alpha.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiUpperAlpha_AboveRange)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x005B}}.is_ascii_upper_alpha());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_ascii_lower_alpha
// ---------------------------------------------------------------------------

/**
 * @brief Test that 0x0061 ('a') is an ASCII lower alpha.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiLowerAlpha_First)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0061}}.is_ascii_lower_alpha());
}

/**
 * @brief Test that 0x007A ('z') is an ASCII lower alpha.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiLowerAlpha_Last)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x007A}}.is_ascii_lower_alpha());
}

/**
 * @brief Test that 0x0041 ('A') is not an ASCII lower alpha.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiLowerAlpha_Uppercase)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0041}}.is_ascii_lower_alpha());
}

/**
 * @brief Test that 0x007B ('{') is not an ASCII lower alpha.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiLowerAlpha_AboveRange)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x007B}}.is_ascii_lower_alpha());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_ascii_alpha
// ---------------------------------------------------------------------------

/**
 * @brief Test that an ASCII upper alpha satisfies is_ascii_alpha.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiAlpha_Upper)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0041}}.is_ascii_alpha()); // 'A'
}

/**
 * @brief Test that an ASCII lower alpha satisfies is_ascii_alpha.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiAlpha_Lower)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0061}}.is_ascii_alpha()); // 'a'
}

/**
 * @brief Test that a digit does not satisfy is_ascii_alpha.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiAlpha_Digit)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0035}}.is_ascii_alpha());
}

// ---------------------------------------------------------------------------
// Unicode attribute predicates — is_ascii_alphanumeric
// ---------------------------------------------------------------------------

/**
 * @brief Test that an ASCII digit satisfies is_ascii_alphanumeric.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiAlphanumeric_Digit)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0035}}.is_ascii_alphanumeric()); // '5'
}

/**
 * @brief Test that an ASCII upper alpha satisfies is_ascii_alphanumeric.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiAlphanumeric_Upper)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0041}}.is_ascii_alphanumeric()); // 'A'
}

/**
 * @brief Test that an ASCII lower alpha satisfies is_ascii_alphanumeric.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiAlphanumeric_Lower)
{
    EXPECT_TRUE(CodeUnit{std::uint16_t{0x0061}}.is_ascii_alphanumeric()); // 'a'
}

/**
 * @brief Test that a non-alphanumeric code unit does not satisfy is_ascii_alphanumeric.
 */
TEST(CodeUnitPrimitiveTest, IsAsciiAlphanumeric_NonAlphanumeric)
{
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0020}}.is_ascii_alphanumeric()); // space
    EXPECT_FALSE(CodeUnit{std::uint16_t{0x0021}}.is_ascii_alphanumeric()); // '!'
}
