/**
 * @file Test-Units/Primitive/Null.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Unit tests for the Null primitive type in the WHATWG Infra library.
 * 
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains unit tests for the Null primitive type in the WHATWG Infra library.
 */

#include <gtest/gtest.h>
#include <Softloq/WHATWG/Infra/Primitive/Null/Null.hpp>

using namespace Softloq::WHATWG::Infra;

/**
 * @brief Test that the Null primitive type returns the correct primitive type.
 */
TEST(NullPrimitiveTest, NullType)
{
    Null null_value;
    EXPECT_EQ(null_value.get_type(), PrimitiveType::Null);
}

/**
 * @brief Test that the Null primitive type can be formatted as a string.
 */
TEST(NullPrimitiveTest, NullFormatting)
{
    Null null_value;
    std::string formatted = std::format("{}", null_value);
    EXPECT_EQ(formatted, "null");
}

