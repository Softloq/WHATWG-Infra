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

/**
 * @brief Test that the Boolean primitive type returns PrimitiveType::Boolean.
 */
TEST(BooleanPrimitiveTest, BooleanType)
{
    Boolean b;
    EXPECT_EQ(b.get_type(), PrimitiveType::Boolean);
}

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

/**
 * @brief Test that set_value correctly updates the stored value.
 */
TEST(BooleanPrimitiveTest, SetValueToTrue)
{
    Boolean b;
    b.set_value(true);
    EXPECT_TRUE(b.get_value());
}

/**
 * @brief Test that set_value can flip the value back to false.
 */
TEST(BooleanPrimitiveTest, SetValueToFalse)
{
    Boolean b{true};
    b.set_value(false);
    EXPECT_FALSE(b.get_value());
}

/**
 * @brief Test that explicit bool conversion returns the correct value for true.
 */
TEST(BooleanPrimitiveTest, OperatorBoolTrue)
{
    Boolean b{true};
    EXPECT_TRUE(static_cast<bool>(b));
}

/**
 * @brief Test that explicit bool conversion returns the correct value for false.
 */
TEST(BooleanPrimitiveTest, OperatorBoolFalse)
{
    Boolean b{false};
    EXPECT_FALSE(static_cast<bool>(b));
}

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
 * @brief Test that two Boolean instances with the same value are equal.
 */
TEST(BooleanPrimitiveTest, EqualityTrueTrue)
{
    Boolean a{true}, b{true};
    EXPECT_TRUE(a == b);
}

/**
 * @brief Test that two Boolean instances with the same false value are equal.
 */
TEST(BooleanPrimitiveTest, EqualityFalseFalse)
{
    Boolean a{false}, b{false};
    EXPECT_TRUE(a == b);
}

/**
 * @brief Test that two Boolean instances with different values are not equal.
 */
TEST(BooleanPrimitiveTest, EqualityTrueFalse)
{
    Boolean a{true}, b{false};
    EXPECT_FALSE(a == b);
}

/**
 * @brief Test that two Boolean instances with different values satisfy inequality.
 */
TEST(BooleanPrimitiveTest, InequalityTrueFalse)
{
    Boolean a{true}, b{false};
    EXPECT_TRUE(a != b);
}

/**
 * @brief Test that two Boolean instances with the same value do not satisfy inequality.
 */
TEST(BooleanPrimitiveTest, InequalityTrueTrue)
{
    Boolean a{true}, b{true};
    EXPECT_FALSE(a != b);
}

/**
 * @brief Test that a true Boolean formats as "true".
 */
TEST(BooleanPrimitiveTest, FormattingTrue)
{
    Boolean b{true};
    std::string formatted = std::format("{}", b);
    EXPECT_EQ(formatted, "true");
}

/**
 * @brief Test that a false Boolean formats as "false".
 */
TEST(BooleanPrimitiveTest, FormattingFalse)
{
    Boolean b{false};
    std::string formatted = std::format("{}", b);
    EXPECT_EQ(formatted, "false");
}

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
