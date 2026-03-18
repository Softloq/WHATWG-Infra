/**
 * @file Test-Units/Primitive/Boolean.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Unit tests for the Boolean primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains unit tests for the Boolean primitive type in the WHATWG Infra library.
 */

#include <gtest/gtest.h>
#include <Softloq/WHATWG/Infra/Primitive/Boolean/Boolean.hpp>
#include <sstream>

using namespace Softloq::WHATWG::Infra;

// ---------------------------------------------------------------------------
// Type identity
// ---------------------------------------------------------------------------

/**
 * @brief Test that get_type() returns PrimitiveType::Boolean.
 */
TEST(BooleanPrimitiveTest, BooleanType)
{
    Boolean b;
    EXPECT_EQ(b.get_type(), PrimitiveType::Boolean);
}

/**
 * @brief Test that get_type() returns PrimitiveType::Boolean when accessed through the base class pointer.
 */
TEST(BooleanPrimitiveTest, PolymorphicType)
{
    Boolean b;
    const Primitive* base = &b;
    EXPECT_EQ(base->get_type(), PrimitiveType::Boolean);
}

// ---------------------------------------------------------------------------
// Construction
// ---------------------------------------------------------------------------

/**
 * @brief Test that the default-constructed Boolean holds false.
 */
TEST(BooleanPrimitiveTest, DefaultConstructorIsFalse)
{
    Boolean b;
    EXPECT_FALSE(b.get_value());
}

/**
 * @brief Test that Boolean constructed with true holds true.
 */
TEST(BooleanPrimitiveTest, TrueValueConstruction)
{
    Boolean b{true};
    EXPECT_TRUE(b.get_value());
}

/**
 * @brief Test that Boolean constructed with false holds false.
 */
TEST(BooleanPrimitiveTest, FalseValueConstruction)
{
    Boolean b{false};
    EXPECT_FALSE(b.get_value());
}

// ---------------------------------------------------------------------------
// Mutation
// ---------------------------------------------------------------------------

/**
 * @brief Test that set_value(true) correctly stores true.
 */
TEST(BooleanPrimitiveTest, SetValueToTrue)
{
    Boolean b;
    b.set_value(true);
    EXPECT_TRUE(b.get_value());
}

/**
 * @brief Test that set_value(false) correctly stores false after a true construction.
 */
TEST(BooleanPrimitiveTest, SetValueToFalse)
{
    Boolean b{true};
    b.set_value(false);
    EXPECT_FALSE(b.get_value());
}

/**
 * @brief Test that set_value can be called multiple times, always reflecting the latest value.
 */
TEST(BooleanPrimitiveTest, SetValueMultipleTimes)
{
    Boolean b;
    b.set_value(true);
    EXPECT_TRUE(b.get_value());
    b.set_value(false);
    EXPECT_FALSE(b.get_value());
    b.set_value(true);
    EXPECT_TRUE(b.get_value());
}

// ---------------------------------------------------------------------------
// Conversion operator
// ---------------------------------------------------------------------------

/**
 * @brief Test that explicit bool conversion returns true for a true Boolean.
 */
TEST(BooleanPrimitiveTest, OperatorBoolTrue)
{
    Boolean b{true};
    EXPECT_TRUE(static_cast<bool>(b));
}

/**
 * @brief Test that explicit bool conversion returns false for a false Boolean.
 */
TEST(BooleanPrimitiveTest, OperatorBoolFalse)
{
    Boolean b{false};
    EXPECT_FALSE(static_cast<bool>(b));
}

/**
 * @brief Test that operator bool and get_value() are always consistent.
 */
TEST(BooleanPrimitiveTest, OperatorBoolConsistencyWithGetValue)
{
    Boolean bt{true};
    EXPECT_EQ(static_cast<bool>(bt), bt.get_value());

    Boolean bf{false};
    EXPECT_EQ(static_cast<bool>(bf), bf.get_value());
}

// ---------------------------------------------------------------------------
// Logical negation
// ---------------------------------------------------------------------------

/**
 * @brief Test that logical negation of true yields false.
 */
TEST(BooleanPrimitiveTest, NegationOfTrue)
{
    Boolean b{true};
    EXPECT_FALSE((!b).get_value());
}

/**
 * @brief Test that logical negation of false yields true.
 */
TEST(BooleanPrimitiveTest, NegationOfFalse)
{
    Boolean b{false};
    EXPECT_TRUE((!b).get_value());
}

/**
 * @brief Test that double negation of true yields true.
 */
TEST(BooleanPrimitiveTest, DoubleNegationTrue)
{
    Boolean b{true};
    EXPECT_TRUE((!(!b)).get_value());
}

/**
 * @brief Test that double negation of false yields false.
 */
TEST(BooleanPrimitiveTest, DoubleNegationFalse)
{
    Boolean b{false};
    EXPECT_FALSE((!(!b)).get_value());
}

/**
 * @brief Test that the result of operator! is still a Boolean with the correct type.
 */
TEST(BooleanPrimitiveTest, NegationPreservesType)
{
    Boolean b{true};
    EXPECT_EQ((!b).get_type(), PrimitiveType::Boolean);
}

// ---------------------------------------------------------------------------
// Equality
// ---------------------------------------------------------------------------

/**
 * @brief Test that a Boolean instance is equal to itself (reflexive).
 */
TEST(BooleanPrimitiveTest, EqualitySelfTrue)
{
    Boolean b{true};
    EXPECT_TRUE(b == b);
}

/**
 * @brief Test that a false Boolean instance is equal to itself (reflexive).
 */
TEST(BooleanPrimitiveTest, EqualitySelfFalse)
{
    Boolean b{false};
    EXPECT_TRUE(b == b);
}

/**
 * @brief Test that two true Boolean instances are equal.
 */
TEST(BooleanPrimitiveTest, EqualityTrueTrue)
{
    Boolean a{true}, b{true};
    EXPECT_TRUE(a == b);
}

/**
 * @brief Test that two false Boolean instances are equal.
 */
TEST(BooleanPrimitiveTest, EqualityFalseFalse)
{
    Boolean a{false}, b{false};
    EXPECT_TRUE(a == b);
}

/**
 * @brief Test that a true and a false Boolean are not equal.
 */
TEST(BooleanPrimitiveTest, EqualityTrueFalse)
{
    Boolean a{true}, b{false};
    EXPECT_FALSE(a == b);
}

/**
 * @brief Test that equality is symmetric: a == b implies b == a.
 */
TEST(BooleanPrimitiveTest, EqualitySymmetry)
{
    Boolean a{true}, b{true};
    EXPECT_EQ(a == b, b == a);

    Boolean c{true}, d{false};
    EXPECT_EQ(c == d, d == c);
}

// ---------------------------------------------------------------------------
// Inequality
// ---------------------------------------------------------------------------

/**
 * @brief Test that two true Boolean instances are not unequal.
 */
TEST(BooleanPrimitiveTest, InequalityTrueTrue)
{
    Boolean a{true}, b{true};
    EXPECT_FALSE(a != b);
}

/**
 * @brief Test that two false Boolean instances are not unequal.
 */
TEST(BooleanPrimitiveTest, InequalityFalseFalse)
{
    Boolean a{false}, b{false};
    EXPECT_FALSE(a != b);
}

/**
 * @brief Test that a true and a false Boolean are unequal.
 */
TEST(BooleanPrimitiveTest, InequalityTrueFalse)
{
    Boolean a{true}, b{false};
    EXPECT_TRUE(a != b);
}

/**
 * @brief Test that inequality is symmetric: a != b implies b != a.
 */
TEST(BooleanPrimitiveTest, InequalitySymmetry)
{
    Boolean a{true}, b{false};
    EXPECT_EQ(a != b, b != a);
}

/**
 * @brief Test that equality and inequality are complementary: (a == b) != (a != b).
 */
TEST(BooleanPrimitiveTest, EqualityAndInequalityAreComplementary)
{
    Boolean a{true}, b{false};
    EXPECT_NE(a == b, a != b);

    Boolean c{true}, d{true};
    EXPECT_NE(c == d, c != d);
}

// ---------------------------------------------------------------------------
// Formatting
// ---------------------------------------------------------------------------

/**
 * @brief Test that a true Boolean formats as "true".
 */
TEST(BooleanPrimitiveTest, FormattingTrue)
{
    Boolean b{true};
    EXPECT_EQ(std::format("{}", b), "true");
}

/**
 * @brief Test that a false Boolean formats as "false".
 */
TEST(BooleanPrimitiveTest, FormattingFalse)
{
    Boolean b{false};
    EXPECT_EQ(std::format("{}", b), "false");
}

/**
 * @brief Test that formatting reflects the value after a set_value call.
 */
TEST(BooleanPrimitiveTest, FormattingAfterSetValue)
{
    Boolean b;
    b.set_value(true);
    EXPECT_EQ(std::format("{}", b), "true");
    b.set_value(false);
    EXPECT_EQ(std::format("{}", b), "false");
}

// ---------------------------------------------------------------------------
// Output stream
// ---------------------------------------------------------------------------

/**
 * @brief Test that a true Boolean streams as "true".
 */
TEST(BooleanPrimitiveTest, OutputStreamTrue)
{
    Boolean b{true};
    std::ostringstream oss;
    oss << b;
    EXPECT_EQ(oss.str(), "true");
}

/**
 * @brief Test that a false Boolean streams as "false".
 */
TEST(BooleanPrimitiveTest, OutputStreamFalse)
{
    Boolean b{false};
    std::ostringstream oss;
    oss << b;
    EXPECT_EQ(oss.str(), "false");
}

/**
 * @brief Test that the output stream reflects the value after a set_value call.
 */
TEST(BooleanPrimitiveTest, OutputStreamAfterSetValue)
{
    Boolean b;
    b.set_value(true);
    std::ostringstream oss;
    oss << b;
    EXPECT_EQ(oss.str(), "true");
}
