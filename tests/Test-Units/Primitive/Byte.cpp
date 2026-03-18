/**
 * @file Test-Units/Primitive/Byte.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Unit tests for the Byte primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains unit tests for the Byte primitive type in the WHATWG Infra library.
 */

#include <gtest/gtest.h>
#include <Softloq/WHATWG/Infra/Primitive/Byte/Byte.hpp>
#include <limits>
#include <sstream>

using namespace Softloq::WHATWG::Infra;

// ---------------------------------------------------------------------------
// Type identity
// ---------------------------------------------------------------------------

/**
 * @brief Test that get_type() returns PrimitiveType::Byte.
 */
TEST(BytePrimitiveTest, ByteType)
{
    Byte b;
    EXPECT_EQ(b.get_type(), PrimitiveType::Byte);
}

/**
 * @brief Test that get_type() returns PrimitiveType::Byte when accessed through the base class pointer.
 */
TEST(BytePrimitiveTest, PolymorphicType)
{
    Byte b;
    const Primitive* base = &b;
    EXPECT_EQ(base->get_type(), PrimitiveType::Byte);
}

// ---------------------------------------------------------------------------
// Construction
// ---------------------------------------------------------------------------

/**
 * @brief Test that the default-constructed Byte holds 0.
 */
TEST(BytePrimitiveTest, DefaultConstructorIsZero)
{
    Byte b;
    EXPECT_EQ(b.get_value(), std::uint8_t{0});
}

/**
 * @brief Test that Byte constructed with 0 holds 0.
 */
TEST(BytePrimitiveTest, ValueConstruction_Zero)
{
    Byte b{std::uint8_t{0}};
    EXPECT_EQ(b.get_value(), std::uint8_t{0});
}

/**
 * @brief Test that Byte constructed with a mid-range value holds that value.
 */
TEST(BytePrimitiveTest, ValueConstruction_MidRange)
{
    Byte b{std::uint8_t{127}};
    EXPECT_EQ(b.get_value(), std::uint8_t{127});
}

/**
 * @brief Test that Byte constructed with the maximum value (255) holds 255.
 */
TEST(BytePrimitiveTest, ValueConstruction_Max)
{
    Byte b{std::numeric_limits<std::uint8_t>::max()};
    EXPECT_EQ(b.get_value(), std::uint8_t{255});
}

/**
 * @brief Test that Byte constructed with an arbitrary value holds that value.
 */
TEST(BytePrimitiveTest, ValueConstruction_Arbitrary)
{
    Byte b{std::uint8_t{42}};
    EXPECT_EQ(b.get_value(), std::uint8_t{42});
}

// ---------------------------------------------------------------------------
// Mutation
// ---------------------------------------------------------------------------

/**
 * @brief Test that set_value stores a new non-zero value.
 */
TEST(BytePrimitiveTest, SetValue_NonZero)
{
    Byte b;
    b.set_value(std::uint8_t{100});
    EXPECT_EQ(b.get_value(), std::uint8_t{100});
}

/**
 * @brief Test that set_value can store 0 after a non-zero construction.
 */
TEST(BytePrimitiveTest, SetValue_ToZero)
{
    Byte b{std::uint8_t{200}};
    b.set_value(std::uint8_t{0});
    EXPECT_EQ(b.get_value(), std::uint8_t{0});
}

/**
 * @brief Test that set_value can store the maximum value (255).
 */
TEST(BytePrimitiveTest, SetValue_ToMax)
{
    Byte b;
    b.set_value(std::numeric_limits<std::uint8_t>::max());
    EXPECT_EQ(b.get_value(), std::uint8_t{255});
}

/**
 * @brief Test that set_value can be called multiple times, always reflecting the latest value.
 */
TEST(BytePrimitiveTest, SetValue_MultipleTimes)
{
    Byte b;
    b.set_value(std::uint8_t{50});
    EXPECT_EQ(b.get_value(), std::uint8_t{50});
    b.set_value(std::uint8_t{200});
    EXPECT_EQ(b.get_value(), std::uint8_t{200});
    b.set_value(std::uint8_t{1});
    EXPECT_EQ(b.get_value(), std::uint8_t{1});
}

/**
 * @brief Test that set_value reflects the change on get_value immediately.
 */
TEST(BytePrimitiveTest, SetValue_ReflectedByGetValue)
{
    Byte b{std::uint8_t{10}};
    b.set_value(std::uint8_t{20});
    EXPECT_EQ(b.get_value(), std::uint8_t{20});
    EXPECT_NE(b.get_value(), std::uint8_t{10});
}

// ---------------------------------------------------------------------------
// Conversion operator
// ---------------------------------------------------------------------------

/**
 * @brief Test that explicit conversion to std::uint8_t returns 0 for a default-constructed Byte.
 */
TEST(BytePrimitiveTest, OperatorUInt8_Zero)
{
    Byte b;
    EXPECT_EQ(static_cast<std::uint8_t>(b), std::uint8_t{0});
}

/**
 * @brief Test that explicit conversion to std::uint8_t returns the correct value.
 */
TEST(BytePrimitiveTest, OperatorUInt8_Value)
{
    Byte b{std::uint8_t{128}};
    EXPECT_EQ(static_cast<std::uint8_t>(b), std::uint8_t{128});
}

/**
 * @brief Test that explicit conversion to std::uint8_t returns 255 for the maximum Byte.
 */
TEST(BytePrimitiveTest, OperatorUInt8_Max)
{
    Byte b{std::uint8_t{255}};
    EXPECT_EQ(static_cast<std::uint8_t>(b), std::uint8_t{255});
}

/**
 * @brief Test that operator std::uint8_t and get_value() are always consistent.
 */
TEST(BytePrimitiveTest, OperatorUInt8_ConsistencyWithGetValue)
{
    Byte b{std::uint8_t{77}};
    EXPECT_EQ(static_cast<std::uint8_t>(b), b.get_value());
}

// ---------------------------------------------------------------------------
// Equality
// ---------------------------------------------------------------------------

/**
 * @brief Test that a Byte instance is equal to itself (reflexive, value 0).
 */
TEST(BytePrimitiveTest, EqualitySelf_Zero)
{
    Byte b{std::uint8_t{0}};
    EXPECT_TRUE(b == b);
}

/**
 * @brief Test that a Byte instance is equal to itself (reflexive, non-zero value).
 */
TEST(BytePrimitiveTest, EqualitySelf_NonZero)
{
    Byte b{std::uint8_t{42}};
    EXPECT_TRUE(b == b);
}

/**
 * @brief Test that two Byte instances with the same value are equal.
 */
TEST(BytePrimitiveTest, EqualitySameValue)
{
    Byte a{std::uint8_t{100}};
    Byte b{std::uint8_t{100}};
    EXPECT_TRUE(a == b);
}

/**
 * @brief Test that two Byte instances with different values are not equal.
 */
TEST(BytePrimitiveTest, EqualityDifferentValues)
{
    Byte a{std::uint8_t{10}};
    Byte b{std::uint8_t{20}};
    EXPECT_FALSE(a == b);
}

/**
 * @brief Test that equality is symmetric: a == b implies b == a.
 */
TEST(BytePrimitiveTest, EqualitySymmetry)
{
    Byte a{std::uint8_t{55}};
    Byte b{std::uint8_t{55}};
    EXPECT_EQ(a == b, b == a);

    Byte c{std::uint8_t{10}};
    Byte d{std::uint8_t{20}};
    EXPECT_EQ(c == d, d == c);
}

/**
 * @brief Test equality at boundary values (0 and 255).
 */
TEST(BytePrimitiveTest, EqualityBoundaryValues)
{
    Byte lo_a{std::uint8_t{0}};
    Byte lo_b{std::uint8_t{0}};
    EXPECT_TRUE(lo_a == lo_b);

    Byte hi_a{std::uint8_t{255}};
    Byte hi_b{std::uint8_t{255}};
    EXPECT_TRUE(hi_a == hi_b);

    EXPECT_FALSE(lo_a == hi_a);
}

// ---------------------------------------------------------------------------
// Inequality
// ---------------------------------------------------------------------------

/**
 * @brief Test that two Byte instances with the same value are not unequal.
 */
TEST(BytePrimitiveTest, InequalitySameValue)
{
    Byte a{std::uint8_t{100}};
    Byte b{std::uint8_t{100}};
    EXPECT_FALSE(a != b);
}

/**
 * @brief Test that two Byte instances with different values are unequal.
 */
TEST(BytePrimitiveTest, InequalityDifferentValues)
{
    Byte a{std::uint8_t{10}};
    Byte b{std::uint8_t{20}};
    EXPECT_TRUE(a != b);
}

/**
 * @brief Test that inequality is symmetric: a != b implies b != a.
 */
TEST(BytePrimitiveTest, InequalitySymmetry)
{
    Byte a{std::uint8_t{10}};
    Byte b{std::uint8_t{20}};
    EXPECT_EQ(a != b, b != a);
}

/**
 * @brief Test that equality and inequality are complementary: (a == b) != (a != b).
 */
TEST(BytePrimitiveTest, EqualityAndInequalityAreComplementary)
{
    Byte a{std::uint8_t{10}};
    Byte b{std::uint8_t{20}};
    EXPECT_NE(a == b, a != b);

    Byte c{std::uint8_t{50}};
    Byte d{std::uint8_t{50}};
    EXPECT_NE(c == d, c != d);
}

/**
 * @brief Test inequality at boundary values (0 and 255).
 */
TEST(BytePrimitiveTest, InequalityBoundaryValues)
{
    Byte lo{std::uint8_t{0}};
    Byte hi{std::uint8_t{255}};
    EXPECT_TRUE(lo != hi);
    EXPECT_FALSE(lo != Byte{std::uint8_t{0}});
}

// ---------------------------------------------------------------------------
// Formatting
// ---------------------------------------------------------------------------

/**
 * @brief Test that a Byte with value 0 formats as "0".
 */
TEST(BytePrimitiveTest, Formatting_Zero)
{
    Byte b{std::uint8_t{0}};
    EXPECT_EQ(std::format("{}", b), "0");
}

/**
 * @brief Test that a Byte with value 255 formats as "255".
 */
TEST(BytePrimitiveTest, Formatting_Max)
{
    Byte b{std::uint8_t{255}};
    EXPECT_EQ(std::format("{}", b), "255");
}

/**
 * @brief Test that a Byte with value 65 formats as "65" (not "A").
 */
TEST(BytePrimitiveTest, Formatting_NotChar)
{
    Byte b{std::uint8_t{65}};
    EXPECT_EQ(std::format("{}", b), "65");
}

/**
 * @brief Test that a Byte with a mid-range value formats as its decimal representation.
 */
TEST(BytePrimitiveTest, Formatting_MidRange)
{
    Byte b{std::uint8_t{127}};
    EXPECT_EQ(std::format("{}", b), "127");
}

/**
 * @brief Test that formatting reflects the value after a set_value call.
 */
TEST(BytePrimitiveTest, Formatting_AfterSetValue)
{
    Byte b;
    b.set_value(std::uint8_t{42});
    EXPECT_EQ(std::format("{}", b), "42");
    b.set_value(std::uint8_t{200});
    EXPECT_EQ(std::format("{}", b), "200");
}

// ---------------------------------------------------------------------------
// Output stream
// ---------------------------------------------------------------------------

/**
 * @brief Test that a Byte with value 0 streams as "0".
 */
TEST(BytePrimitiveTest, OutputStream_Zero)
{
    Byte b{std::uint8_t{0}};
    std::ostringstream oss;
    oss << b;
    EXPECT_EQ(oss.str(), "0");
}

/**
 * @brief Test that a Byte with value 255 streams as "255".
 */
TEST(BytePrimitiveTest, OutputStream_Max)
{
    Byte b{std::uint8_t{255}};
    std::ostringstream oss;
    oss << b;
    EXPECT_EQ(oss.str(), "255");
}

/**
 * @brief Test that a Byte with value 65 streams as "65" (not "A").
 */
TEST(BytePrimitiveTest, OutputStream_NotChar)
{
    Byte b{std::uint8_t{65}};
    std::ostringstream oss;
    oss << b;
    EXPECT_EQ(oss.str(), "65");
}

/**
 * @brief Test that the output stream reflects the value after a set_value call.
 */
TEST(BytePrimitiveTest, OutputStream_AfterSetValue)
{
    Byte b;
    b.set_value(std::uint8_t{99});
    std::ostringstream oss;
    oss << b;
    EXPECT_EQ(oss.str(), "99");
}
