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
#include <Softloq/WHATWG/Infra/Primitives/All.hpp>
#include <limits>
#include <sstream>

using namespace Softloq::WHATWG::Infra;

// ---------------------------------------------------------------------------
// Type identity — all eight aliases
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
 * @brief Test that UInt16 reports PrimitiveType::Number.
 */
TEST(NumberPrimitiveTest, UInt16Type)
{
    UInt16 n;
    EXPECT_EQ(n.get_type(), PrimitiveType::Number);
}

/**
 * @brief Test that UInt32 reports PrimitiveType::Number.
 */
TEST(NumberPrimitiveTest, UInt32Type)
{
    UInt32 n;
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
 * @brief Test that Int8 reports PrimitiveType::Number.
 */
TEST(NumberPrimitiveTest, Int8Type)
{
    Int8 n;
    EXPECT_EQ(n.get_type(), PrimitiveType::Number);
}

/**
 * @brief Test that Int16 reports PrimitiveType::Number.
 */
TEST(NumberPrimitiveTest, Int16Type)
{
    Int16 n;
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
 * @brief Test that Int64 reports PrimitiveType::Number.
 */
TEST(NumberPrimitiveTest, Int64Type)
{
    Int64 n;
    EXPECT_EQ(n.get_type(), PrimitiveType::Number);
}

/**
 * @brief Test that get_type() returns PrimitiveType::Number through the base class pointer.
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
 * @brief Test that all default-constructed aliases hold 0.
 */
TEST(NumberPrimitiveTest, DefaultConstructorIsZero_AllAliases)
{
    EXPECT_EQ(UInt8{}.get_value(),  std::uint8_t{0});
    EXPECT_EQ(UInt16{}.get_value(), std::uint16_t{0});
    EXPECT_EQ(UInt32{}.get_value(), std::uint32_t{0});
    EXPECT_EQ(UInt64{}.get_value(), std::uint64_t{0});
    EXPECT_EQ(Int8{}.get_value(),   std::int8_t{0});
    EXPECT_EQ(Int16{}.get_value(),  std::int16_t{0});
    EXPECT_EQ(Int32{}.get_value(),  std::int32_t{0});
    EXPECT_EQ(Int64{}.get_value(),  std::int64_t{0});
}

/**
 * @brief Test value construction for UInt8 at its boundaries.
 */
TEST(NumberPrimitiveTest, ValueConstruction_UInt8_Boundaries)
{
    EXPECT_EQ(UInt8{0}.get_value(),   std::uint8_t{0});
    EXPECT_EQ(UInt8{255}.get_value(), std::uint8_t{255});
}

/**
 * @brief Test value construction for Int8 at its boundaries.
 */
TEST(NumberPrimitiveTest, ValueConstruction_Int8_Boundaries)
{
    EXPECT_EQ(Int8{-128}.get_value(), std::numeric_limits<std::int8_t>::min());
    EXPECT_EQ(Int8{127}.get_value(),  std::numeric_limits<std::int8_t>::max());
}

/**
 * @brief Test value construction for Int32 with positive and negative values.
 */
TEST(NumberPrimitiveTest, ValueConstruction_Int32_PositiveNegative)
{
    EXPECT_EQ(Int32{42}.get_value(),   std::int32_t{42});
    EXPECT_EQ(Int32{-100}.get_value(), std::int32_t{-100});
}

/**
 * @brief Test value construction for Int32 at its boundaries.
 */
TEST(NumberPrimitiveTest, ValueConstruction_Int32_Boundaries)
{
    EXPECT_EQ(Int32{std::numeric_limits<std::int32_t>::min()}.get_value(),
              std::numeric_limits<std::int32_t>::min());
    EXPECT_EQ(Int32{std::numeric_limits<std::int32_t>::max()}.get_value(),
              std::numeric_limits<std::int32_t>::max());
}

/**
 * @brief Test value construction for UInt32 at its maximum boundary.
 */
TEST(NumberPrimitiveTest, ValueConstruction_UInt32_Max)
{
    UInt32 n{std::numeric_limits<std::uint32_t>::max()};
    EXPECT_EQ(n.get_value(), std::numeric_limits<std::uint32_t>::max());
}

/**
 * @brief Test value construction for Int64 at its boundaries.
 */
TEST(NumberPrimitiveTest, ValueConstruction_Int64_Boundaries)
{
    EXPECT_EQ(Int64{std::numeric_limits<std::int64_t>::min()}.get_value(),
              std::numeric_limits<std::int64_t>::min());
    EXPECT_EQ(Int64{std::numeric_limits<std::int64_t>::max()}.get_value(),
              std::numeric_limits<std::int64_t>::max());
}

/**
 * @brief Test value construction for UInt64 with a large value.
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
 * @brief Test that set_value stores a new value for UInt8.
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
 * @brief Test that set_value stores the boundary value for Int64.
 */
TEST(NumberPrimitiveTest, SetValue_Int64_Boundary)
{
    Int64 n;
    n.set_value(std::numeric_limits<std::int64_t>::min());
    EXPECT_EQ(n.get_value(), std::numeric_limits<std::int64_t>::min());
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

/**
 * @brief Test that set_value back to zero works correctly.
 */
TEST(NumberPrimitiveTest, SetValueBackToZero)
{
    Int32 n{42};
    n.set_value(0);
    EXPECT_EQ(n.get_value(), 0);
}

// ---------------------------------------------------------------------------
// Conversion operator
// ---------------------------------------------------------------------------

/**
 * @brief Test that explicit conversion returns the correct value for UInt8.
 */
TEST(NumberPrimitiveTest, ConversionOperator_UInt8)
{
    UInt8 n{42};
    EXPECT_EQ(static_cast<std::uint8_t>(n), std::uint8_t{42});
}

/**
 * @brief Test that explicit conversion returns the correct value for a negative Int32.
 */
TEST(NumberPrimitiveTest, ConversionOperator_Int32_Negative)
{
    Int32 n{-7};
    EXPECT_EQ(static_cast<std::int32_t>(n), std::int32_t{-7});
}

/**
 * @brief Test that explicit conversion and get_value() are always consistent.
 */
TEST(NumberPrimitiveTest, ConversionConsistencyWithGetValue)
{
    Int32 pos{123};
    EXPECT_EQ(static_cast<std::int32_t>(pos), pos.get_value());

    Int32 neg{-456};
    EXPECT_EQ(static_cast<std::int32_t>(neg), neg.get_value());
}

/**
 * @brief Test that explicit conversion reflects a value set via set_value.
 */
TEST(NumberPrimitiveTest, ConversionAfterSetValue)
{
    Int32 n{0};
    n.set_value(77);
    EXPECT_EQ(static_cast<std::int32_t>(n), 77);
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
    EXPECT_EQ((a + b).get_value(), 7);
}

/**
 * @brief Test that operator+ is commutative: a + b == b + a.
 */
TEST(NumberPrimitiveTest, AdditionCommutativity)
{
    Int32 a{12}, b{5};
    EXPECT_EQ((a + b).get_value(), (b + a).get_value());
}

/**
 * @brief Test that adding zero is an identity: a + 0 == a.
 */
TEST(NumberPrimitiveTest, AdditionIdentity)
{
    Int32 a{99}, zero{0};
    EXPECT_EQ((a + zero).get_value(), a.get_value());
    EXPECT_EQ((zero + a).get_value(), a.get_value());
}

/**
 * @brief Test that operator- returns the correct difference.
 */
TEST(NumberPrimitiveTest, Subtraction)
{
    Int32 a{10}, b{3};
    EXPECT_EQ((a - b).get_value(), 7);
}

/**
 * @brief Test that subtracting a value from itself yields zero.
 */
TEST(NumberPrimitiveTest, SubtractionSelf)
{
    Int32 a{42};
    EXPECT_EQ((a - a).get_value(), 0);
}

/**
 * @brief Test that subtraction can produce a negative result.
 */
TEST(NumberPrimitiveTest, SubtractionNegativeResult)
{
    Int32 a{3}, b{10};
    EXPECT_EQ((a - b).get_value(), -7);
}

/**
 * @brief Test that operator* returns the correct product.
 */
TEST(NumberPrimitiveTest, Multiplication)
{
    UInt16 a{6}, b{7};
    EXPECT_EQ((a * b).get_value(), std::uint16_t{42});
}

/**
 * @brief Test that multiplying by 1 is an identity: a * 1 == a.
 */
TEST(NumberPrimitiveTest, MultiplicationIdentity)
{
    Int32 a{55}, one{1};
    EXPECT_EQ((a * one).get_value(), a.get_value());
}

/**
 * @brief Test that multiplying by 0 yields 0.
 */
TEST(NumberPrimitiveTest, MultiplicationByZero)
{
    Int32 a{123}, zero{0};
    EXPECT_EQ((a * zero).get_value(), 0);
}

/**
 * @brief Test that operator* is commutative: a * b == b * a.
 */
TEST(NumberPrimitiveTest, MultiplicationCommutativity)
{
    Int32 a{7}, b{9};
    EXPECT_EQ((a * b).get_value(), (b * a).get_value());
}

/**
 * @brief Test that operator/ returns the correct quotient.
 */
TEST(NumberPrimitiveTest, Division)
{
    UInt32 a{20}, b{4};
    EXPECT_EQ((a / b).get_value(), std::uint32_t{5});
}

/**
 * @brief Test that dividing by 1 is an identity: a / 1 == a.
 */
TEST(NumberPrimitiveTest, DivisionIdentity)
{
    Int32 a{77}, one{1};
    EXPECT_EQ((a / one).get_value(), a.get_value());
}

/**
 * @brief Test that integer division truncates toward zero.
 */
TEST(NumberPrimitiveTest, DivisionTruncation)
{
    Int32 a{7}, b{2};
    EXPECT_EQ((a / b).get_value(), 3);
}

/**
 * @brief Test that operator% returns the correct remainder.
 */
TEST(NumberPrimitiveTest, Modulo)
{
    Int32 a{17}, b{5};
    EXPECT_EQ((a % b).get_value(), 2);
}

/**
 * @brief Test that n % 1 == 0 for any value.
 */
TEST(NumberPrimitiveTest, ModuloByOne)
{
    Int32 a{99}, one{1};
    EXPECT_EQ((a % one).get_value(), 0);
}

/**
 * @brief Test that n % n == 0 for any non-zero value.
 */
TEST(NumberPrimitiveTest, ModuloSelf)
{
    Int32 a{13};
    EXPECT_EQ((a % a).get_value(), 0);
}

/**
 * @brief Test that arithmetic result type preserves PrimitiveType::Number.
 */
TEST(NumberPrimitiveTest, ArithmeticResultType)
{
    Int32 a{2}, b{3};
    EXPECT_EQ((a + b).get_type(), PrimitiveType::Number);
}

// ---------------------------------------------------------------------------
// Compound assignment operators
// ---------------------------------------------------------------------------

/**
 * @brief Test that operator+= correctly mutates the value.
 */
TEST(NumberPrimitiveTest, CompoundAdd)
{
    Int32 n{5};
    n += Int32{3};
    EXPECT_EQ(n.get_value(), 8);
}

/**
 * @brief Test that operator-= correctly mutates the value.
 */
TEST(NumberPrimitiveTest, CompoundSubtract)
{
    Int32 n{10};
    n -= Int32{4};
    EXPECT_EQ(n.get_value(), 6);
}

/**
 * @brief Test that operator*= correctly mutates the value.
 */
TEST(NumberPrimitiveTest, CompoundMultiply)
{
    Int32 n{3};
    n *= Int32{7};
    EXPECT_EQ(n.get_value(), 21);
}

/**
 * @brief Test that operator/= correctly mutates the value.
 */
TEST(NumberPrimitiveTest, CompoundDivide)
{
    Int32 n{12};
    n /= Int32{4};
    EXPECT_EQ(n.get_value(), 3);
}

/**
 * @brief Test that operator%= correctly mutates the value.
 */
TEST(NumberPrimitiveTest, CompoundModulo)
{
    Int32 n{13};
    n %= Int32{5};
    EXPECT_EQ(n.get_value(), 3);
}

/**
 * @brief Test that all compound assignment operators return a reference to the same object.
 */
TEST(NumberPrimitiveTest, CompoundAssignmentReturnsSelf_AllOperators)
{
    Int32 n{10};
    EXPECT_EQ(&(n += Int32{0}), &n);
    EXPECT_EQ(&(n -= Int32{0}), &n);
    EXPECT_EQ(&(n *= Int32{1}), &n);
    EXPECT_EQ(&(n /= Int32{1}), &n);
    EXPECT_EQ(&(n %= Int32{7}), &n);
}

/**
 * @brief Test that n += x produces the same result as n = n + x.
 */
TEST(NumberPrimitiveTest, CompoundAddConsistencyWithPlus)
{
    Int32 a{10}, b{3};
    Int32 via_plus = a + b;
    a += b;
    EXPECT_EQ(a.get_value(), via_plus.get_value());
}

/**
 * @brief Test that n -= x produces the same result as n = n - x.
 */
TEST(NumberPrimitiveTest, CompoundSubtractConsistencyWithMinus)
{
    Int32 a{10}, b{3};
    Int32 via_minus = a - b;
    a -= b;
    EXPECT_EQ(a.get_value(), via_minus.get_value());
}

/**
 * @brief Test that chained compound assignments accumulate correctly.
 */
TEST(NumberPrimitiveTest, CompoundAddChained)
{
    Int32 n{0};
    n += Int32{1};
    n += Int32{2};
    n += Int32{3};
    EXPECT_EQ(n.get_value(), 6);
}

// ---------------------------------------------------------------------------
// Increment and decrement operators
// ---------------------------------------------------------------------------

/**
 * @brief Test that prefix ++ increments the value and returns a reference to the same object.
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
 * @brief Test that prefix -- decrements the value and returns a reference to the same object.
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

/**
 * @brief Test that prefix ++ is consistent with += 1.
 */
TEST(NumberPrimitiveTest, PrefixIncrementConsistencyWithCompoundAdd)
{
    Int32 a{10}, b{10};
    ++a;
    b += Int32{1};
    EXPECT_EQ(a.get_value(), b.get_value());
}

/**
 * @brief Test that prefix -- is consistent with -= 1.
 */
TEST(NumberPrimitiveTest, PrefixDecrementConsistencyWithCompoundSubtract)
{
    Int32 a{10}, b{10};
    --a;
    b -= Int32{1};
    EXPECT_EQ(a.get_value(), b.get_value());
}

/**
 * @brief Test that consecutive prefix increments accumulate.
 */
TEST(NumberPrimitiveTest, ConsecutivePrefixIncrements)
{
    Int32 n{0};
    ++n; ++n; ++n;
    EXPECT_EQ(n.get_value(), 3);
}

/**
 * @brief Test that consecutive prefix decrements accumulate.
 */
TEST(NumberPrimitiveTest, ConsecutivePrefixDecrements)
{
    Int32 n{3};
    --n; --n; --n;
    EXPECT_EQ(n.get_value(), 0);
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
 * @brief Test that zero is equal to zero.
 */
TEST(NumberPrimitiveTest, EqualityZero)
{
    Int32 a{0}, b{0};
    EXPECT_TRUE(a == b);
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
 * @brief Test that inequality is symmetric: a != b implies b != a.
 */
TEST(NumberPrimitiveTest, InequalitySymmetry)
{
    Int32 a{1}, b{2};
    EXPECT_EQ(a != b, b != a);
}

/**
 * @brief Test that equality and inequality are complementary: exactly one holds.
 */
TEST(NumberPrimitiveTest, EqualityAndInequalityAreComplementary)
{
    Int32 a{10}, b{20};
    EXPECT_NE(a == b, a != b);

    Int32 c{5}, d{5};
    EXPECT_NE(c == d, c != d);
}

/**
 * @brief Test that equality holds after arithmetic produces the expected value.
 */
TEST(NumberPrimitiveTest, EqualityAfterArithmetic)
{
    Int32 a{3}, b{4}, expected{7};
    EXPECT_TRUE((a + b) == expected);
}

// ---------------------------------------------------------------------------
// Ordering comparisons
// ---------------------------------------------------------------------------

/**
 * @brief Test that operator< returns true when the left operand is strictly less.
 */
TEST(NumberPrimitiveTest, LessThan)
{
    Int32 a{3}, b{5};
    EXPECT_TRUE(a < b);
    EXPECT_FALSE(b < a);
}

/**
 * @brief Test that operator< returns false for equal values (strict inequality).
 */
TEST(NumberPrimitiveTest, LessThanFalseForEqual)
{
    Int32 a{4}, b{4};
    EXPECT_FALSE(a < b);
}

/**
 * @brief Test that operator< is anti-symmetric: a < b implies !(b < a).
 */
TEST(NumberPrimitiveTest, LessThanAntiSymmetry)
{
    Int32 a{2}, b{8};
    EXPECT_TRUE(a < b);
    EXPECT_FALSE(b < a);
}

/**
 * @brief Test that operator< is transitive: a < b and b < c implies a < c.
 */
TEST(NumberPrimitiveTest, LessThanTransitivity)
{
    Int32 a{1}, b{5}, c{10};
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(b < c);
    EXPECT_TRUE(a < c);
}

/**
 * @brief Test that operator<= returns true for strictly less-than.
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
 * @brief Test that <= is consistent with < and ==: (a <= b) == (a < b || a == b).
 */
TEST(NumberPrimitiveTest, LessThanOrEqualConsistency)
{
    Int32 a{3}, b{5};
    EXPECT_EQ(a <= b, (a < b || a == b));

    Int32 c{4}, d{4};
    EXPECT_EQ(c <= d, (c < d || c == d));
}

/**
 * @brief Test that operator> returns true when the left operand is strictly greater.
 */
TEST(NumberPrimitiveTest, GreaterThan)
{
    Int32 a{9}, b{3};
    EXPECT_TRUE(a > b);
    EXPECT_FALSE(b > a);
}

/**
 * @brief Test that operator> is consistent with operator<: (a > b) == (b < a).
 */
TEST(NumberPrimitiveTest, GreaterThanConsistencyWithLessThan)
{
    Int32 a{7}, b{2};
    EXPECT_EQ(a > b, b < a);

    Int32 c{1}, d{9};
    EXPECT_EQ(c > d, d < c);
}

/**
 * @brief Test that operator>= returns true for strictly greater-than.
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
 * @brief Test that >= is consistent with > and ==: (a >= b) == (a > b || a == b).
 */
TEST(NumberPrimitiveTest, GreaterThanOrEqualConsistency)
{
    Int32 a{5}, b{3};
    EXPECT_EQ(a >= b, (a > b || a == b));

    Int32 c{4}, d{4};
    EXPECT_EQ(c >= d, (c > d || c == d));
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
 * @brief Test ordering trichotomy holds for equal values.
 */
TEST(NumberPrimitiveTest, OrderingTrichotomyEqual)
{
    Int32 a{4}, b{4};
    int count = (a < b ? 1 : 0) + (a == b ? 1 : 0) + (a > b ? 1 : 0);
    EXPECT_EQ(count, 1);
}

/**
 * @brief Test that negative values compare correctly against positive values.
 */
TEST(NumberPrimitiveTest, SignedNegativeComparison)
{
    Int32 neg{-10}, pos{5};
    EXPECT_TRUE(neg < pos);
    EXPECT_TRUE(pos > neg);
    EXPECT_FALSE(neg > pos);
    EXPECT_FALSE(pos < neg);
}

/**
 * @brief Test that two negative values compare correctly.
 */
TEST(NumberPrimitiveTest, NegativeToNegativeComparison)
{
    Int32 a{-3}, b{-1};
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(b > a);
}

/**
 * @brief Test unsigned zero boundary comparisons.
 */
TEST(NumberPrimitiveTest, UnsignedZeroBoundary)
{
    UInt32 zero{0}, one{1};
    EXPECT_TRUE(zero < one);
    EXPECT_TRUE(zero <= one);
    EXPECT_FALSE(zero > one);
    EXPECT_TRUE(zero == UInt32{0});
}

// ---------------------------------------------------------------------------
// Formatting — all eight aliases, boundaries, and edge cases
// ---------------------------------------------------------------------------

/**
 * @brief Test that Int32{0} formats as "0".
 */
TEST(NumberPrimitiveTest, FormattingZero_Int32)
{
    EXPECT_EQ(std::format("{}", Int32{0}), "0");
}

/**
 * @brief Test that Int32{42} formats as "42".
 */
TEST(NumberPrimitiveTest, FormattingPositive_Int32)
{
    EXPECT_EQ(std::format("{}", Int32{42}), "42");
}

/**
 * @brief Test that Int32{-42} formats as "-42".
 */
TEST(NumberPrimitiveTest, FormattingNegative_Int32)
{
    EXPECT_EQ(std::format("{}", Int32{-42}), "-42");
}

/**
 * @brief Test that Int8{-1} formats as "-1" (not as a char).
 */
TEST(NumberPrimitiveTest, FormattingNegative_Int8)
{
    EXPECT_EQ(std::format("{}", Int8{-1}), "-1");
}

/**
 * @brief Test that Int8{-128} formats as "-128" (minimum boundary).
 */
TEST(NumberPrimitiveTest, FormattingMinBoundary_Int8)
{
    EXPECT_EQ(std::format("{}", Int8{-128}), "-128");
}

/**
 * @brief Test that Int8{127} formats as "127" (maximum boundary).
 */
TEST(NumberPrimitiveTest, FormattingMaxBoundary_Int8)
{
    EXPECT_EQ(std::format("{}", Int8{127}), "127");
}

/**
 * @brief Test that UInt8{0} formats as "0" (not the null character).
 */
TEST(NumberPrimitiveTest, FormattingZero_UInt8AsNumber)
{
    EXPECT_EQ(std::format("{}", UInt8{0}), "0");
}

/**
 * @brief Test that UInt8{255} formats as "255" (not as a character).
 */
TEST(NumberPrimitiveTest, FormattingMax_UInt8AsNumber)
{
    EXPECT_EQ(std::format("{}", UInt8{255}), "255");
}

/**
 * @brief Test that UInt8{65} formats as "65", not "A".
 */
TEST(NumberPrimitiveTest, FormattingUInt8NotChar)
{
    EXPECT_EQ(std::format("{}", UInt8{65}), "65");
}

/**
 * @brief Test that Int16{-1000} formats as "-1000".
 */
TEST(NumberPrimitiveTest, FormattingNegative_Int16)
{
    EXPECT_EQ(std::format("{}", Int16{-1000}), "-1000");
}

/**
 * @brief Test that UInt16{65535} formats as "65535".
 */
TEST(NumberPrimitiveTest, FormattingMax_UInt16)
{
    EXPECT_EQ(std::format("{}", UInt16{65535}), "65535");
}

/**
 * @brief Test that UInt32 max formats correctly.
 */
TEST(NumberPrimitiveTest, FormattingMax_UInt32)
{
    EXPECT_EQ(std::format("{}", UInt32{std::numeric_limits<std::uint32_t>::max()}), "4294967295");
}

/**
 * @brief Test that a large UInt64 value formats correctly.
 */
TEST(NumberPrimitiveTest, FormattingLarge_UInt64)
{
    EXPECT_EQ(std::format("{}", UInt64{1'000'000'000'000ULL}), "1000000000000");
}

/**
 * @brief Test that a negative Int64 value formats correctly.
 */
TEST(NumberPrimitiveTest, FormattingNegative_Int64)
{
    EXPECT_EQ(std::format("{}", Int64{-1'000'000'000'000LL}), "-1000000000000");
}

/**
 * @brief Test that formatting reflects the value after a set_value call.
 */
TEST(NumberPrimitiveTest, FormattingAfterSetValue)
{
    Int32 n{0};
    n.set_value(99);
    EXPECT_EQ(std::format("{}", n), "99");
    n.set_value(-1);
    EXPECT_EQ(std::format("{}", n), "-1");
}

/**
 * @brief Test that formatting and OStream produce the same output.
 */
TEST(NumberPrimitiveTest, FormattingAndOStreamConsistency)
{
    Int32 n{-77};
    std::ostringstream oss;
    oss << n;
    EXPECT_EQ(std::format("{}", n), oss.str());
}

// ---------------------------------------------------------------------------
// Output stream — all eight aliases, boundaries, and edge cases
// ---------------------------------------------------------------------------

/**
 * @brief Test that UInt8{0} streams as "0".
 */
TEST(NumberPrimitiveTest, OutputStreamZero_UInt8)
{
    std::ostringstream oss;
    oss << UInt8{0};
    EXPECT_EQ(oss.str(), "0");
}

/**
 * @brief Test that UInt8{65} streams as "65", not "A".
 */
TEST(NumberPrimitiveTest, OutputStreamUInt8NotChar)
{
    std::ostringstream oss;
    oss << UInt8{65};
    EXPECT_EQ(oss.str(), "65");
}

/**
 * @brief Test that Int8{-128} streams as "-128", not as a character.
 */
TEST(NumberPrimitiveTest, OutputStreamMinBoundary_Int8)
{
    std::ostringstream oss;
    oss << Int8{-128};
    EXPECT_EQ(oss.str(), "-128");
}

/**
 * @brief Test that Int32{-7} streams as "-7".
 */
TEST(NumberPrimitiveTest, OutputStreamNegative_Int32)
{
    std::ostringstream oss;
    oss << Int32{-7};
    EXPECT_EQ(oss.str(), "-7");
}

/**
 * @brief Test that UInt32 max streams correctly.
 */
TEST(NumberPrimitiveTest, OutputStreamMax_UInt32)
{
    std::ostringstream oss;
    oss << UInt32{std::numeric_limits<std::uint32_t>::max()};
    EXPECT_EQ(oss.str(), "4294967295");
}

/**
 * @brief Test that a negative Int64 streams correctly.
 */
TEST(NumberPrimitiveTest, OutputStreamNegative_Int64)
{
    std::ostringstream oss;
    oss << Int64{-1'000'000'000'000LL};
    EXPECT_EQ(oss.str(), "-1000000000000");
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
