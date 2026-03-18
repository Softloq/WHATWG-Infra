/**
 * @file Test-Units/Primitive/Number.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Unit tests for the Number primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains unit tests for the Number primitive type in the WHATWG Infra library.
 */

#include <gtest/gtest.h>
#include <Softloq/WHATWG/Infra/Primitive/Number/Number.hpp>
#include <sstream>

using namespace Softloq::WHATWG::Infra;

// ---------------------------------------------------------------------------
// Type identity
// ---------------------------------------------------------------------------

/**
 * @brief Test that UInt8 reports PrimitiveType::Number.
 */
TEST(NumberPrimitiveTest, UInt8Type)
{
    UInt8 n;
    EXPECT_EQ(n.get_type(), PrimitiveType::Number);
}

/**
 * @brief Test that Int32 reports PrimitiveType::Number.
 */
TEST(NumberPrimitiveTest, Int32Type)
{
    Int32 n;
    EXPECT_EQ(n.get_type(), PrimitiveType::Number);
}

/**
 * @brief Test that UInt64 reports PrimitiveType::Number.
 */
TEST(NumberPrimitiveTest, UInt64Type)
{
    UInt64 n;
    EXPECT_EQ(n.get_type(), PrimitiveType::Number);
}

/**
 * @brief Test that get_type() returns PrimitiveType::Number when accessed through the base class pointer.
 */
TEST(NumberPrimitiveTest, PolymorphicType)
{
    Int32 n;
    const Primitive* base = &n;
    EXPECT_EQ(base->get_type(), PrimitiveType::Number);
}

// ---------------------------------------------------------------------------
// Construction
// ---------------------------------------------------------------------------

/**
 * @brief Test that the default-constructed UInt8 holds 0.
 */
TEST(NumberPrimitiveTest, DefaultConstructorIsZero_UInt8)
{
    UInt8 n;
    EXPECT_EQ(n.get_value(), std::uint8_t{0});
}

/**
 * @brief Test that the default-constructed Int32 holds 0.
 */
TEST(NumberPrimitiveTest, DefaultConstructorIsZero_Int32)
{
    Int32 n;
    EXPECT_EQ(n.get_value(), std::int32_t{0});
}

/**
 * @brief Test that UInt8 can be constructed with a non-zero value.
 */
TEST(NumberPrimitiveTest, ValueConstruction_UInt8)
{
    UInt8 n{255};
    EXPECT_EQ(n.get_value(), std::uint8_t{255});
}

/**
 * @brief Test that Int32 can be constructed with a positive value.
 */
TEST(NumberPrimitiveTest, ValueConstruction_Int32_Positive)
{
    Int32 n{42};
    EXPECT_EQ(n.get_value(), std::int32_t{42});
}

/**
 * @brief Test that Int32 can be constructed with a negative value.
 */
TEST(NumberPrimitiveTest, ValueConstruction_Int32_Negative)
{
    Int32 n{-100};
    EXPECT_EQ(n.get_value(), std::int32_t{-100});
}

/**
 * @brief Test that Int8 can be constructed with a boundary value.
 */
TEST(NumberPrimitiveTest, ValueConstruction_Int8_MinMax)
{
    Int8 nmin{-128};
    Int8 nmax{127};
    EXPECT_EQ(nmin.get_value(), std::int8_t{-128});
    EXPECT_EQ(nmax.get_value(), std::int8_t{127});
}

/**
 * @brief Test that UInt64 can be constructed with a large value.
 */
TEST(NumberPrimitiveTest, ValueConstruction_UInt64_Large)
{
    UInt64 n{1'000'000'000'000ULL};
    EXPECT_EQ(n.get_value(), std::uint64_t{1'000'000'000'000ULL});
}

// ---------------------------------------------------------------------------
// Mutation
// ---------------------------------------------------------------------------

/**
 * @brief Test that set_value stores the new value for UInt8.
 */
TEST(NumberPrimitiveTest, SetValue_UInt8)
{
    UInt8 n;
    n.set_value(200);
    EXPECT_EQ(n.get_value(), std::uint8_t{200});
}

/**
 * @brief Test that set_value stores a negative value for Int32.
 */
TEST(NumberPrimitiveTest, SetValue_Int32_Negative)
{
    Int32 n;
    n.set_value(-999);
    EXPECT_EQ(n.get_value(), std::int32_t{-999});
}

/**
 * @brief Test that set_value can be called multiple times, always reflecting the latest value.
 */
TEST(NumberPrimitiveTest, SetValueMultipleTimes)
{
    Int32 n;
    n.set_value(1);
    EXPECT_EQ(n.get_value(), 1);
    n.set_value(-5);
    EXPECT_EQ(n.get_value(), -5);
    n.set_value(0);
    EXPECT_EQ(n.get_value(), 0);
}

// ---------------------------------------------------------------------------
// Conversion operator
// ---------------------------------------------------------------------------

/**
 * @brief Test that explicit conversion to uint8_t returns the correct value.
 */
TEST(NumberPrimitiveTest, ConversionOperator_UInt8)
{
    UInt8 n{42};
    EXPECT_EQ(static_cast<std::uint8_t>(n), std::uint8_t{42});
}

/**
 * @brief Test that explicit conversion to int32_t returns the correct value.
 */
TEST(NumberPrimitiveTest, ConversionOperator_Int32)
{
    Int32 n{-7};
    EXPECT_EQ(static_cast<std::int32_t>(n), std::int32_t{-7});
}

/**
 * @brief Test that the conversion operator and get_value() are always consistent.
 */
TEST(NumberPrimitiveTest, ConversionConsistencyWithGetValue)
{
    Int32 n{123};
    EXPECT_EQ(static_cast<std::int32_t>(n), n.get_value());
}

// ---------------------------------------------------------------------------
// Arithmetic operators
// ---------------------------------------------------------------------------

/**
 * @brief Test that operator+ returns the correct sum.
 */
TEST(NumberPrimitiveTest, Addition)
{
    Int32 a{3}, b{4};
    Int32 result = a + b;
    EXPECT_EQ(result.get_value(), 7);
}

/**
 * @brief Test that operator- returns the correct difference.
 */
TEST(NumberPrimitiveTest, Subtraction)
{
    Int32 a{10}, b{3};
    Int32 result = a - b;
    EXPECT_EQ(result.get_value(), 7);
}

/**
 * @brief Test that operator* returns the correct product.
 */
TEST(NumberPrimitiveTest, Multiplication)
{
    UInt16 a{6}, b{7};
    UInt16 result = a * b;
    EXPECT_EQ(result.get_value(), std::uint16_t{42});
}

/**
 * @brief Test that operator/ returns the correct quotient.
 */
TEST(NumberPrimitiveTest, Division)
{
    UInt32 a{20}, b{4};
    UInt32 result = a / b;
    EXPECT_EQ(result.get_value(), std::uint32_t{5});
}

/**
 * @brief Test that operator% returns the correct remainder.
 */
TEST(NumberPrimitiveTest, Modulo)
{
    Int32 a{17}, b{5};
    Int32 result = a % b;
    EXPECT_EQ(result.get_value(), 2);
}

/**
 * @brief Test that adding zero to a value yields the original value.
 */
TEST(NumberPrimitiveTest, AdditionWithZero)
{
    Int32 a{99}, zero{0};
    EXPECT_EQ((a + zero).get_value(), 99);
}

// ---------------------------------------------------------------------------
// Compound assignment operators
// ---------------------------------------------------------------------------

/**
 * @brief Test that operator+= mutates and returns the correct reference.
 */
TEST(NumberPrimitiveTest, CompoundAdd)
{
    Int32 n{5};
    n += Int32{3};
    EXPECT_EQ(n.get_value(), 8);
}

/**
 * @brief Test that operator-= mutates and returns the correct reference.
 */
TEST(NumberPrimitiveTest, CompoundSubtract)
{
    Int32 n{10};
    n -= Int32{4};
    EXPECT_EQ(n.get_value(), 6);
}

/**
 * @brief Test that operator*= mutates and returns the correct reference.
 */
TEST(NumberPrimitiveTest, CompoundMultiply)
{
    Int32 n{3};
    n *= Int32{7};
    EXPECT_EQ(n.get_value(), 21);
}

/**
 * @brief Test that operator/= mutates and returns the correct reference.
 */
TEST(NumberPrimitiveTest, CompoundDivide)
{
    Int32 n{12};
    n /= Int32{4};
    EXPECT_EQ(n.get_value(), 3);
}

/**
 * @brief Test that operator%= mutates and returns the correct reference.
 */
TEST(NumberPrimitiveTest, CompoundModulo)
{
    Int32 n{13};
    n %= Int32{5};
    EXPECT_EQ(n.get_value(), 3);
}

/**
 * @brief Test that compound assignment returns a reference to the same object.
 */
TEST(NumberPrimitiveTest, CompoundAssignmentReturnsSelf)
{
    Int32 n{1};
    Int32& ref = (n += Int32{0});
    EXPECT_EQ(&ref, &n);
}

// ---------------------------------------------------------------------------
// Increment and decrement operators
// ---------------------------------------------------------------------------

/**
 * @brief Test that prefix ++ increments the value and returns the updated instance.
 */
TEST(NumberPrimitiveTest, PrefixIncrement)
{
    Int32 n{5};
    Int32& ref = ++n;
    EXPECT_EQ(n.get_value(), 6);
    EXPECT_EQ(&ref, &n);
}

/**
 * @brief Test that postfix ++ increments the value and returns the pre-increment copy.
 */
TEST(NumberPrimitiveTest, PostfixIncrement)
{
    Int32 n{5};
    Int32 before = n++;
    EXPECT_EQ(n.get_value(), 6);
    EXPECT_EQ(before.get_value(), 5);
}

/**
 * @brief Test that prefix -- decrements the value and returns the updated instance.
 */
TEST(NumberPrimitiveTest, PrefixDecrement)
{
    Int32 n{5};
    Int32& ref = --n;
    EXPECT_EQ(n.get_value(), 4);
    EXPECT_EQ(&ref, &n);
}

/**
 * @brief Test that postfix -- decrements the value and returns the pre-decrement copy.
 */
TEST(NumberPrimitiveTest, PostfixDecrement)
{
    Int32 n{5};
    Int32 before = n--;
    EXPECT_EQ(n.get_value(), 4);
    EXPECT_EQ(before.get_value(), 5);
}

// ---------------------------------------------------------------------------
// Equality and inequality
// ---------------------------------------------------------------------------

/**
 * @brief Test that a Number is equal to itself (reflexive).
 */
TEST(NumberPrimitiveTest, EqualitySelf)
{
    Int32 n{42};
    EXPECT_TRUE(n == n);
}

/**
 * @brief Test that two Numbers with the same value are equal.
 */
TEST(NumberPrimitiveTest, EqualitySameValue)
{
    Int32 a{7}, b{7};
    EXPECT_TRUE(a == b);
}

/**
 * @brief Test that two Numbers with different values are not equal.
 */
TEST(NumberPrimitiveTest, EqualityDifferentValues)
{
    Int32 a{7}, b{8};
    EXPECT_FALSE(a == b);
}

/**
 * @brief Test that two Numbers with different values satisfy inequality.
 */
TEST(NumberPrimitiveTest, InequalityDifferentValues)
{
    Int32 a{1}, b{2};
    EXPECT_TRUE(a != b);
}

/**
 * @brief Test that two Numbers with the same value do not satisfy inequality.
 */
TEST(NumberPrimitiveTest, InequalitySameValue)
{
    Int32 a{5}, b{5};
    EXPECT_FALSE(a != b);
}

/**
 * @brief Test that equality is symmetric: a == b implies b == a.
 */
TEST(NumberPrimitiveTest, EqualitySymmetry)
{
    Int32 a{3}, b{3};
    EXPECT_EQ(a == b, b == a);

    Int32 c{3}, d{4};
    EXPECT_EQ(c == d, d == c);
}

/**
 * @brief Test that equality and inequality are complementary.
 */
TEST(NumberPrimitiveTest, EqualityAndInequalityAreComplementary)
{
    Int32 a{10}, b{20};
    EXPECT_NE(a == b, a != b);

    Int32 c{5}, d{5};
    EXPECT_NE(c == d, c != d);
}

// ---------------------------------------------------------------------------
// Ordering comparisons
// ---------------------------------------------------------------------------

/**
 * @brief Test that operator< returns true when the left operand is less.
 */
TEST(NumberPrimitiveTest, LessThan)
{
    Int32 a{3}, b{5};
    EXPECT_TRUE(a < b);
    EXPECT_FALSE(b < a);
}

/**
 * @brief Test that operator< returns false for equal values.
 */
TEST(NumberPrimitiveTest, LessThanFalseForEqual)
{
    Int32 a{4}, b{4};
    EXPECT_FALSE(a < b);
}

/**
 * @brief Test that operator<= returns true for less-than.
 */
TEST(NumberPrimitiveTest, LessThanOrEqual_Less)
{
    Int32 a{2}, b{5};
    EXPECT_TRUE(a <= b);
}

/**
 * @brief Test that operator<= returns true for equal values.
 */
TEST(NumberPrimitiveTest, LessThanOrEqual_Equal)
{
    Int32 a{4}, b{4};
    EXPECT_TRUE(a <= b);
}

/**
 * @brief Test that operator> returns true when the left operand is greater.
 */
TEST(NumberPrimitiveTest, GreaterThan)
{
    Int32 a{9}, b{3};
    EXPECT_TRUE(a > b);
    EXPECT_FALSE(b > a);
}

/**
 * @brief Test that operator>= returns true for greater-than.
 */
TEST(NumberPrimitiveTest, GreaterThanOrEqual_Greater)
{
    Int32 a{7}, b{2};
    EXPECT_TRUE(a >= b);
}

/**
 * @brief Test that operator>= returns true for equal values.
 */
TEST(NumberPrimitiveTest, GreaterThanOrEqual_Equal)
{
    Int32 a{6}, b{6};
    EXPECT_TRUE(a >= b);
}

/**
 * @brief Test that ordering is consistent: exactly one of a<b, a==b, a>b holds.
 */
TEST(NumberPrimitiveTest, OrderingTrichotomy)
{
    Int32 a{3}, b{5};
    int count = (a < b ? 1 : 0) + (a == b ? 1 : 0) + (a > b ? 1 : 0);
    EXPECT_EQ(count, 1);
}

/**
 * @brief Test signed negative comparisons.
 */
TEST(NumberPrimitiveTest, SignedNegativeComparison)
{
    Int32 neg{-10}, pos{5};
    EXPECT_TRUE(neg < pos);
    EXPECT_TRUE(pos > neg);
    EXPECT_FALSE(neg > pos);
}

// ---------------------------------------------------------------------------
// Formatting
// ---------------------------------------------------------------------------

/**
 * @brief Test that Int32{0} formats as "0".
 */
TEST(NumberPrimitiveTest, FormattingZero_Int32)
{
    Int32 n{0};
    EXPECT_EQ(std::format("{}", n), "0");
}

/**
 * @brief Test that Int32{42} formats as "42".
 */
TEST(NumberPrimitiveTest, FormattingPositive_Int32)
{
    Int32 n{42};
    EXPECT_EQ(std::format("{}", n), "42");
}

/**
 * @brief Test that Int8{-1} formats as "-1".
 */
TEST(NumberPrimitiveTest, FormattingNegative_Int8)
{
    Int8 n{-1};
    EXPECT_EQ(std::format("{}", n), "-1");
}

/**
 * @brief Test that UInt8{255} formats as "255" (not as a character).
 */
TEST(NumberPrimitiveTest, FormattingUInt8AsNumber)
{
    UInt8 n{255};
    EXPECT_EQ(std::format("{}", n), "255");
}

/**
 * @brief Test that UInt64 formats a large value correctly.
 */
TEST(NumberPrimitiveTest, FormattingLarge_UInt64)
{
    UInt64 n{1'000'000'000'000ULL};
    EXPECT_EQ(std::format("{}", n), "1000000000000");
}

/**
 * @brief Test that formatting reflects the value after a set_value call.
 */
TEST(NumberPrimitiveTest, FormattingAfterSetValue)
{
    Int32 n{0};
    n.set_value(99);
    EXPECT_EQ(std::format("{}", n), "99");
}

// ---------------------------------------------------------------------------
// Output stream
// ---------------------------------------------------------------------------

/**
 * @brief Test that UInt8{0} streams as "0".
 */
TEST(NumberPrimitiveTest, OutputStreamZero_UInt8)
{
    UInt8 n{0};
    std::ostringstream oss;
    oss << n;
    EXPECT_EQ(oss.str(), "0");
}

/**
 * @brief Test that Int32{-7} streams as "-7".
 */
TEST(NumberPrimitiveTest, OutputStreamNegative_Int32)
{
    Int32 n{-7};
    std::ostringstream oss;
    oss << n;
    EXPECT_EQ(oss.str(), "-7");
}

/**
 * @brief Test that UInt8 streams as a number, not a character.
 */
TEST(NumberPrimitiveTest, OutputStreamUInt8AsNumber)
{
    UInt8 n{65};
    std::ostringstream oss;
    oss << n;
    EXPECT_EQ(oss.str(), "65");
}

/**
 * @brief Test that the output stream reflects the value after a set_value call.
 */
TEST(NumberPrimitiveTest, OutputStreamAfterSetValue)
{
    Int32 n{0};
    n.set_value(123);
    std::ostringstream oss;
    oss << n;
    EXPECT_EQ(oss.str(), "123");
}
