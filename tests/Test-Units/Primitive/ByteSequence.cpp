/**
 * @file Test-Units/Primitive/ByteSequence.cpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief Unit tests for the ByteSequence primitive type in the WHATWG Infra library.
 *
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This file contains unit tests for the ByteSequence primitive type in the WHATWG Infra library.
 */

#include <gtest/gtest.h>
#include <Softloq/WHATWG/Infra/Primitive/ByteSequence/ByteSequence.hpp>
#include <sstream>
#include <stdexcept>

using namespace Softloq::WHATWG::Infra;

// ---------------------------------------------------------------------------
// Type identity
// ---------------------------------------------------------------------------

/**
 * @brief Test that get_type() returns PrimitiveType::ByteSequence.
 */
TEST(ByteSequencePrimitiveTest, ByteSequenceType)
{
    ByteSequence bs;
    EXPECT_EQ(bs.get_type(), PrimitiveType::ByteSequence);
}

/**
 * @brief Test that get_type() returns PrimitiveType::ByteSequence when accessed through the base class pointer.
 */
TEST(ByteSequencePrimitiveTest, PolymorphicType)
{
    ByteSequence bs;
    const Primitive* base = &bs;
    EXPECT_EQ(base->get_type(), PrimitiveType::ByteSequence);
}

// ---------------------------------------------------------------------------
// Construction
// ---------------------------------------------------------------------------

/**
 * @brief Test that the default-constructed ByteSequence is empty.
 */
TEST(ByteSequencePrimitiveTest, DefaultConstructorIsEmpty)
{
    ByteSequence bs;
    EXPECT_EQ(bs.size(), std::size_t{0});
    EXPECT_TRUE(bs.is_empty());
}

/**
 * @brief Test that a ByteSequence constructed from an empty initializer_list is empty.
 */
TEST(ByteSequencePrimitiveTest, InitializerListConstruction_Empty)
{
    ByteSequence bs{};
    EXPECT_EQ(bs.size(), std::size_t{0});
    EXPECT_TRUE(bs.is_empty());
}

/**
 * @brief Test that a ByteSequence constructed from a single-element initializer_list holds that byte.
 */
TEST(ByteSequencePrimitiveTest, InitializerListConstruction_SingleByte)
{
    ByteSequence bs{0xABu};
    EXPECT_EQ(bs.size(), std::size_t{1});
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0xAB});
}

/**
 * @brief Test that a ByteSequence constructed from a multi-element initializer_list holds those bytes in order.
 */
TEST(ByteSequencePrimitiveTest, InitializerListConstruction_MultipleBytes)
{
    ByteSequence bs{0x01u, 0x02u, 0x03u};
    EXPECT_EQ(bs.size(), std::size_t{3});
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0x01});
    EXPECT_EQ(bs[1].get_value(), std::uint8_t{0x02});
    EXPECT_EQ(bs[2].get_value(), std::uint8_t{0x03});
}

/**
 * @brief Test that a ByteSequence constructed with boundary values (0x00, 0xFF) holds them correctly.
 */
TEST(ByteSequencePrimitiveTest, InitializerListConstruction_BoundaryValues)
{
    ByteSequence bs{0x00u, 0xFFu};
    EXPECT_EQ(bs.size(), std::size_t{2});
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0x00});
    EXPECT_EQ(bs[1].get_value(), std::uint8_t{0xFF});
}

// ---------------------------------------------------------------------------
// Container interface — size
// ---------------------------------------------------------------------------

/**
 * @brief Test that size() returns 0 for a default-constructed ByteSequence.
 */
TEST(ByteSequencePrimitiveTest, Size_Empty)
{
    ByteSequence bs;
    EXPECT_EQ(bs.size(), std::size_t{0});
}

/**
 * @brief Test that size() returns the correct count after construction from an initializer_list.
 */
TEST(ByteSequencePrimitiveTest, Size_AfterConstruction)
{
    ByteSequence bs{0x01u, 0x02u, 0x03u, 0x04u, 0x05u};
    EXPECT_EQ(bs.size(), std::size_t{5});
}

/**
 * @brief Test that size() increases by 1 after each push_back.
 */
TEST(ByteSequencePrimitiveTest, Size_AfterPushBack)
{
    ByteSequence bs;
    bs.push_back(Byte{std::uint8_t{0x10}});
    EXPECT_EQ(bs.size(), std::size_t{1});
    bs.push_back(Byte{std::uint8_t{0x20}});
    EXPECT_EQ(bs.size(), std::size_t{2});
}

// ---------------------------------------------------------------------------
// Container interface — is_empty
// ---------------------------------------------------------------------------

/**
 * @brief Test that is_empty() returns true for a default-constructed ByteSequence.
 */
TEST(ByteSequencePrimitiveTest, IsEmpty_DefaultConstructed)
{
    ByteSequence bs;
    EXPECT_TRUE(bs.is_empty());
}

/**
 * @brief Test that is_empty() returns false for a non-empty ByteSequence.
 */
TEST(ByteSequencePrimitiveTest, IsEmpty_NonEmpty)
{
    ByteSequence bs{0x61u};
    EXPECT_FALSE(bs.is_empty());
}

/**
 * @brief Test that is_empty() returns true after clear() is called on a non-empty sequence.
 */
TEST(ByteSequencePrimitiveTest, IsEmpty_AfterClear)
{
    ByteSequence bs{0x61u, 0x62u};
    bs.clear();
    EXPECT_TRUE(bs.is_empty());
}

// ---------------------------------------------------------------------------
// Container interface — operator[]
// ---------------------------------------------------------------------------

/**
 * @brief Test that operator[] returns the correct byte at index 0.
 */
TEST(ByteSequencePrimitiveTest, SubscriptOperator_FirstElement)
{
    ByteSequence bs{0xAAu, 0xBBu, 0xCCu};
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0xAA});
}

/**
 * @brief Test that operator[] returns the correct byte at the last index.
 */
TEST(ByteSequencePrimitiveTest, SubscriptOperator_LastElement)
{
    ByteSequence bs{0xAAu, 0xBBu, 0xCCu};
    EXPECT_EQ(bs[2].get_value(), std::uint8_t{0xCC});
}

/**
 * @brief Test that operator[] (const) returns the correct byte.
 */
TEST(ByteSequencePrimitiveTest, SubscriptOperator_Const)
{
    const ByteSequence bs{0x10u, 0x20u};
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0x10});
    EXPECT_EQ(bs[1].get_value(), std::uint8_t{0x20});
}

/**
 * @brief Test that operator[] allows mutation of a byte value.
 */
TEST(ByteSequencePrimitiveTest, SubscriptOperator_MutateElement)
{
    ByteSequence bs{0x00u, 0x00u};
    bs[0].set_value(std::uint8_t{0x42});
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0x42});
}

// ---------------------------------------------------------------------------
// Container interface — at
// ---------------------------------------------------------------------------

/**
 * @brief Test that at() returns the correct byte for a valid index.
 */
TEST(ByteSequencePrimitiveTest, At_ValidIndex)
{
    ByteSequence bs{0x11u, 0x22u, 0x33u};
    EXPECT_EQ(bs.at(1).get_value(), std::uint8_t{0x22});
}

/**
 * @brief Test that at() (const) returns the correct byte for a valid index.
 */
TEST(ByteSequencePrimitiveTest, At_ValidIndex_Const)
{
    const ByteSequence bs{0x11u, 0x22u, 0x33u};
    EXPECT_EQ(bs.at(2).get_value(), std::uint8_t{0x33});
}

/**
 * @brief Test that at() throws std::out_of_range for an out-of-bounds index.
 */
TEST(ByteSequencePrimitiveTest, At_OutOfRange)
{
    ByteSequence bs{0x01u};
    EXPECT_THROW(bs.at(1), std::out_of_range);
}

/**
 * @brief Test that at() throws std::out_of_range on an empty sequence.
 */
TEST(ByteSequencePrimitiveTest, At_EmptySequenceThrows)
{
    ByteSequence bs;
    EXPECT_THROW(bs.at(0), std::out_of_range);
}

// ---------------------------------------------------------------------------
// Container interface — push_back
// ---------------------------------------------------------------------------

/**
 * @brief Test that push_back appends a byte to an empty sequence.
 */
TEST(ByteSequencePrimitiveTest, PushBack_IntoEmpty)
{
    ByteSequence bs;
    bs.push_back(Byte{std::uint8_t{0x7F}});
    EXPECT_EQ(bs.size(), std::size_t{1});
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0x7F});
}

/**
 * @brief Test that push_back appends bytes in the correct order.
 */
TEST(ByteSequencePrimitiveTest, PushBack_OrderPreserved)
{
    ByteSequence bs;
    bs.push_back(Byte{std::uint8_t{0x01}});
    bs.push_back(Byte{std::uint8_t{0x02}});
    bs.push_back(Byte{std::uint8_t{0x03}});
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0x01});
    EXPECT_EQ(bs[1].get_value(), std::uint8_t{0x02});
    EXPECT_EQ(bs[2].get_value(), std::uint8_t{0x03});
}

// ---------------------------------------------------------------------------
// Container interface — clear
// ---------------------------------------------------------------------------

/**
 * @brief Test that clear() removes all bytes from the sequence.
 */
TEST(ByteSequencePrimitiveTest, Clear_NonEmpty)
{
    ByteSequence bs{0x01u, 0x02u, 0x03u};
    bs.clear();
    EXPECT_EQ(bs.size(), std::size_t{0});
    EXPECT_TRUE(bs.is_empty());
}

/**
 * @brief Test that clear() on an already-empty sequence is a no-op.
 */
TEST(ByteSequencePrimitiveTest, Clear_AlreadyEmpty)
{
    ByteSequence bs;
    bs.clear();
    EXPECT_TRUE(bs.is_empty());
}

/**
 * @brief Test that push_back works correctly after clear().
 */
TEST(ByteSequencePrimitiveTest, Clear_ThenPushBack)
{
    ByteSequence bs{0x01u, 0x02u};
    bs.clear();
    bs.push_back(Byte{std::uint8_t{0xFF}});
    EXPECT_EQ(bs.size(), std::size_t{1});
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0xFF});
}

// ---------------------------------------------------------------------------
// Container interface — iteration
// ---------------------------------------------------------------------------

/**
 * @brief Test that range-based for loop traverses bytes in the correct order.
 */
TEST(ByteSequencePrimitiveTest, Iteration_RangeFor)
{
    ByteSequence bs{0x0Au, 0x0Bu, 0x0Cu};
    std::vector<std::uint8_t> collected;
    for (const auto& b : bs)
        collected.push_back(b.get_value());
    ASSERT_EQ(collected.size(), std::size_t{3});
    EXPECT_EQ(collected[0], std::uint8_t{0x0A});
    EXPECT_EQ(collected[1], std::uint8_t{0x0B});
    EXPECT_EQ(collected[2], std::uint8_t{0x0C});
}

/**
 * @brief Test that cbegin/cend iterates over all bytes in the correct order.
 */
TEST(ByteSequencePrimitiveTest, Iteration_CBeginCEnd)
{
    ByteSequence bs{0xF0u, 0xF1u};
    auto it = bs.cbegin();
    EXPECT_EQ(it->get_value(), std::uint8_t{0xF0});
    ++it;
    EXPECT_EQ(it->get_value(), std::uint8_t{0xF1});
    ++it;
    EXPECT_EQ(it, bs.cend());
}

/**
 * @brief Test that begin/end on an empty sequence returns equal iterators.
 */
TEST(ByteSequencePrimitiveTest, Iteration_EmptySequence)
{
    ByteSequence bs;
    EXPECT_EQ(bs.begin(), bs.end());
}

// ---------------------------------------------------------------------------
// Equality
// ---------------------------------------------------------------------------

/**
 * @brief Test that two default-constructed ByteSequences are equal.
 */
TEST(ByteSequencePrimitiveTest, Equality_BothEmpty)
{
    ByteSequence a;
    ByteSequence b;
    EXPECT_TRUE(a == b);
}

/**
 * @brief Test that a ByteSequence is equal to itself (reflexive).
 */
TEST(ByteSequencePrimitiveTest, Equality_Self)
{
    ByteSequence bs{0x01u, 0x02u, 0x03u};
    EXPECT_TRUE(bs == bs);
}

/**
 * @brief Test that two ByteSequences with the same bytes in the same order are equal.
 */
TEST(ByteSequencePrimitiveTest, Equality_SameContent)
{
    ByteSequence a{0x61u, 0x62u, 0x63u};
    ByteSequence b{0x61u, 0x62u, 0x63u};
    EXPECT_TRUE(a == b);
}

/**
 * @brief Test that two ByteSequences with different bytes are not equal.
 */
TEST(ByteSequencePrimitiveTest, Equality_DifferentContent)
{
    ByteSequence a{0x61u, 0x62u};
    ByteSequence b{0x61u, 0x63u};
    EXPECT_FALSE(a == b);
}

/**
 * @brief Test that two ByteSequences with different lengths are not equal.
 */
TEST(ByteSequencePrimitiveTest, Equality_DifferentLength)
{
    ByteSequence a{0x61u, 0x62u};
    ByteSequence b{0x61u, 0x62u, 0x63u};
    EXPECT_FALSE(a == b);
}

/**
 * @brief Test that equality is symmetric: a == b implies b == a.
 */
TEST(ByteSequencePrimitiveTest, Equality_Symmetric)
{
    ByteSequence a{0xAAu, 0xBBu};
    ByteSequence b{0xAAu, 0xBBu};
    EXPECT_EQ(a == b, b == a);
}

/**
 * @brief Test that an empty sequence is not equal to a non-empty sequence.
 */
TEST(ByteSequencePrimitiveTest, Equality_EmptyVsNonEmpty)
{
    ByteSequence a;
    ByteSequence b{0x01u};
    EXPECT_FALSE(a == b);
}

// ---------------------------------------------------------------------------
// Inequality
// ---------------------------------------------------------------------------

/**
 * @brief Test that two ByteSequences with the same content are not unequal.
 */
TEST(ByteSequencePrimitiveTest, Inequality_SameContent)
{
    ByteSequence a{0x01u, 0x02u};
    ByteSequence b{0x01u, 0x02u};
    EXPECT_FALSE(a != b);
}

/**
 * @brief Test that two ByteSequences with different content are unequal.
 */
TEST(ByteSequencePrimitiveTest, Inequality_DifferentContent)
{
    ByteSequence a{0x01u, 0x02u};
    ByteSequence b{0x01u, 0x03u};
    EXPECT_TRUE(a != b);
}

/**
 * @brief Test that equality and inequality are complementary.
 */
TEST(ByteSequencePrimitiveTest, EqualityAndInequalityAreComplementary)
{
    ByteSequence a{0xAAu};
    ByteSequence b{0xBBu};
    EXPECT_NE(a == b, a != b);

    ByteSequence c{0xCCu};
    ByteSequence d{0xCCu};
    EXPECT_NE(c == d, c != d);
}

// ---------------------------------------------------------------------------
// WHATWG Infra — byte_lowercase
// ---------------------------------------------------------------------------

/**
 * @brief Test that byte_lowercase converts A–Z (0x41–0x5A) to a–z (0x61–0x7A).
 */
TEST(ByteSequencePrimitiveTest, ByteLowercase_UppercaseLetters)
{
    ByteSequence bs{0x41u, 0x42u, 0x5Au}; // 'A', 'B', 'Z'
    bs.byte_lowercase();
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0x61}); // 'a'
    EXPECT_EQ(bs[1].get_value(), std::uint8_t{0x62}); // 'b'
    EXPECT_EQ(bs[2].get_value(), std::uint8_t{0x7A}); // 'z'
}

/**
 * @brief Test that byte_lowercase leaves bytes outside A–Z unchanged.
 */
TEST(ByteSequencePrimitiveTest, ByteLowercase_NonUppercaseUnchanged)
{
    ByteSequence bs{0x61u, 0x30u, 0xFFu}; // 'a', '0', 0xFF
    bs.byte_lowercase();
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0x61}); // already lowercase
    EXPECT_EQ(bs[1].get_value(), std::uint8_t{0x30}); // digit unchanged
    EXPECT_EQ(bs[2].get_value(), std::uint8_t{0xFF}); // non-ASCII unchanged
}

/**
 * @brief Test that byte_lowercase handles a mixed sequence correctly.
 */
TEST(ByteSequencePrimitiveTest, ByteLowercase_MixedContent)
{
    ByteSequence bs{0x48u, 0x65u, 0x4Cu, 0x4Cu, 0x4Fu}; // 'H', 'e', 'L', 'L', 'O'
    bs.byte_lowercase();
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0x68}); // 'h'
    EXPECT_EQ(bs[1].get_value(), std::uint8_t{0x65}); // 'e' unchanged
    EXPECT_EQ(bs[2].get_value(), std::uint8_t{0x6C}); // 'l'
    EXPECT_EQ(bs[3].get_value(), std::uint8_t{0x6C}); // 'l'
    EXPECT_EQ(bs[4].get_value(), std::uint8_t{0x6Fu}); // 'o'
}

/**
 * @brief Test that byte_lowercase on an empty sequence is a no-op.
 */
TEST(ByteSequencePrimitiveTest, ByteLowercase_Empty)
{
    ByteSequence bs;
    bs.byte_lowercase();
    EXPECT_TRUE(bs.is_empty());
}

/**
 * @brief Test that byte_lowercase is idempotent: applying it twice gives the same result.
 */
TEST(ByteSequencePrimitiveTest, ByteLowercase_Idempotent)
{
    ByteSequence bs{0x41u, 0x42u, 0x43u}; // 'A', 'B', 'C'
    bs.byte_lowercase();
    ByteSequence bs2 = bs;
    bs.byte_lowercase();
    EXPECT_TRUE(bs == bs2);
}

// ---------------------------------------------------------------------------
// WHATWG Infra — byte_uppercase
// ---------------------------------------------------------------------------

/**
 * @brief Test that byte_uppercase converts a–z (0x61–0x7A) to A–Z (0x41–0x5A).
 */
TEST(ByteSequencePrimitiveTest, ByteUppercase_LowercaseLetters)
{
    ByteSequence bs{0x61u, 0x62u, 0x7Au}; // 'a', 'b', 'z'
    bs.byte_uppercase();
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0x41}); // 'A'
    EXPECT_EQ(bs[1].get_value(), std::uint8_t{0x42}); // 'B'
    EXPECT_EQ(bs[2].get_value(), std::uint8_t{0x5A}); // 'Z'
}

/**
 * @brief Test that byte_uppercase leaves bytes outside a–z unchanged.
 */
TEST(ByteSequencePrimitiveTest, ByteUppercase_NonLowercaseUnchanged)
{
    ByteSequence bs{0x41u, 0x30u, 0xFFu}; // 'A', '0', 0xFF
    bs.byte_uppercase();
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0x41}); // already uppercase
    EXPECT_EQ(bs[1].get_value(), std::uint8_t{0x30}); // digit unchanged
    EXPECT_EQ(bs[2].get_value(), std::uint8_t{0xFF}); // non-ASCII unchanged
}

/**
 * @brief Test that byte_uppercase handles a mixed sequence correctly.
 */
TEST(ByteSequencePrimitiveTest, ByteUppercase_MixedContent)
{
    ByteSequence bs{0x68u, 0x45u, 0x6Cu, 0x6Cu, 0x6Fu}; // 'h', 'E', 'l', 'l', 'o'
    bs.byte_uppercase();
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0x48}); // 'H'
    EXPECT_EQ(bs[1].get_value(), std::uint8_t{0x45}); // 'E' unchanged
    EXPECT_EQ(bs[2].get_value(), std::uint8_t{0x4C}); // 'L'
    EXPECT_EQ(bs[3].get_value(), std::uint8_t{0x4C}); // 'L'
    EXPECT_EQ(bs[4].get_value(), std::uint8_t{0x4F}); // 'O'
}

/**
 * @brief Test that byte_uppercase on an empty sequence is a no-op.
 */
TEST(ByteSequencePrimitiveTest, ByteUppercase_Empty)
{
    ByteSequence bs;
    bs.byte_uppercase();
    EXPECT_TRUE(bs.is_empty());
}

/**
 * @brief Test that byte_uppercase is idempotent: applying it twice gives the same result.
 */
TEST(ByteSequencePrimitiveTest, ByteUppercase_Idempotent)
{
    ByteSequence bs{0x61u, 0x62u, 0x63u}; // 'a', 'b', 'c'
    bs.byte_uppercase();
    ByteSequence bs2 = bs;
    bs.byte_uppercase();
    EXPECT_TRUE(bs == bs2);
}

/**
 * @brief Test that byte_lowercase and byte_uppercase are inverses of each other.
 */
TEST(ByteSequencePrimitiveTest, ByteLowercaseUppercase_AreInverses)
{
    ByteSequence bs{0x41u, 0x42u, 0x43u}; // 'A', 'B', 'C'
    bs.byte_lowercase();
    bs.byte_uppercase();
    EXPECT_EQ(bs[0].get_value(), std::uint8_t{0x41});
    EXPECT_EQ(bs[1].get_value(), std::uint8_t{0x42});
    EXPECT_EQ(bs[2].get_value(), std::uint8_t{0x43});
}

// ---------------------------------------------------------------------------
// WHATWG Infra — starts_with
// ---------------------------------------------------------------------------

/**
 * @brief Test that any sequence starts with an empty sequence.
 */
TEST(ByteSequencePrimitiveTest, StartsWith_EmptyPrefix)
{
    ByteSequence bs{0x01u, 0x02u, 0x03u};
    ByteSequence empty;
    EXPECT_TRUE(bs.starts_with(empty));
}

/**
 * @brief Test that an empty sequence starts with an empty sequence.
 */
TEST(ByteSequencePrimitiveTest, StartsWith_BothEmpty)
{
    ByteSequence a;
    ByteSequence b;
    EXPECT_TRUE(a.starts_with(b));
}

/**
 * @brief Test that a sequence starts with itself.
 */
TEST(ByteSequencePrimitiveTest, StartsWith_Self)
{
    ByteSequence bs{0x01u, 0x02u, 0x03u};
    EXPECT_TRUE(bs.starts_with(bs));
}

/**
 * @brief Test that a sequence starts with a proper prefix.
 */
TEST(ByteSequencePrimitiveTest, StartsWith_ProperPrefix)
{
    ByteSequence bs{0x01u, 0x02u, 0x03u};
    ByteSequence prefix{0x01u, 0x02u};
    EXPECT_TRUE(bs.starts_with(prefix));
}

/**
 * @brief Test that a sequence starts with a single-byte prefix.
 */
TEST(ByteSequencePrimitiveTest, StartsWith_SingleBytePrefix)
{
    ByteSequence bs{0xAAu, 0xBBu, 0xCCu};
    ByteSequence prefix{0xAAu};
    EXPECT_TRUE(bs.starts_with(prefix));
}

/**
 * @brief Test that starts_with returns false when the prefix does not match.
 */
TEST(ByteSequencePrimitiveTest, StartsWith_WrongPrefix)
{
    ByteSequence bs{0x01u, 0x02u, 0x03u};
    ByteSequence prefix{0x01u, 0x03u};
    EXPECT_FALSE(bs.starts_with(prefix));
}

/**
 * @brief Test that starts_with returns false when the other sequence is longer.
 */
TEST(ByteSequencePrimitiveTest, StartsWith_OtherLonger)
{
    ByteSequence bs{0x01u, 0x02u};
    ByteSequence longer{0x01u, 0x02u, 0x03u};
    EXPECT_FALSE(bs.starts_with(longer));
}

/**
 * @brief Test that an empty sequence does not start with a non-empty sequence.
 */
TEST(ByteSequencePrimitiveTest, StartsWith_EmptyDoesNotStartWithNonEmpty)
{
    ByteSequence empty;
    ByteSequence bs{0x01u};
    EXPECT_FALSE(empty.starts_with(bs));
}

// ---------------------------------------------------------------------------
// Formatting
// ---------------------------------------------------------------------------

/**
 * @brief Test that an empty ByteSequence formats as "[]".
 */
TEST(ByteSequencePrimitiveTest, Formatting_Empty)
{
    ByteSequence bs;
    EXPECT_EQ(std::format("{}", bs), "[]");
}

/**
 * @brief Test that a single-byte ByteSequence formats correctly.
 */
TEST(ByteSequencePrimitiveTest, Formatting_SingleByte)
{
    ByteSequence bs{0x61u};
    EXPECT_EQ(std::format("{}", bs), "[0x61]");
}

/**
 * @brief Test that a multi-byte ByteSequence formats all bytes space-separated inside brackets.
 */
TEST(ByteSequencePrimitiveTest, Formatting_MultipleBytes)
{
    ByteSequence bs{0x01u, 0xABu, 0xFFu};
    EXPECT_EQ(std::format("{}", bs), "[0x01 0xAB 0xFF]");
}

/**
 * @brief Test that formatting uses uppercase hex digits for each byte.
 */
TEST(ByteSequencePrimitiveTest, Formatting_UppercaseHex)
{
    ByteSequence bs{0x0Fu, 0xF0u};
    EXPECT_EQ(std::format("{}", bs), "[0x0F 0xF0]");
}

/**
 * @brief Test that formatting reflects changes made after construction.
 */
TEST(ByteSequencePrimitiveTest, Formatting_AfterPushBack)
{
    ByteSequence bs;
    bs.push_back(Byte{std::uint8_t{0x00}});
    bs.push_back(Byte{std::uint8_t{0xFF}});
    EXPECT_EQ(std::format("{}", bs), "[0x00 0xFF]");
}

// ---------------------------------------------------------------------------
// Output stream
// ---------------------------------------------------------------------------

/**
 * @brief Test that an empty ByteSequence streams as "[]".
 */
TEST(ByteSequencePrimitiveTest, OutputStream_Empty)
{
    ByteSequence bs;
    std::ostringstream oss;
    oss << bs;
    EXPECT_EQ(oss.str(), "[]");
}

/**
 * @brief Test that a single-byte ByteSequence streams correctly.
 */
TEST(ByteSequencePrimitiveTest, OutputStream_SingleByte)
{
    ByteSequence bs{0xFFu};
    std::ostringstream oss;
    oss << bs;
    EXPECT_EQ(oss.str(), "[0xFF]");
}

/**
 * @brief Test that a multi-byte ByteSequence streams all bytes space-separated inside brackets.
 */
TEST(ByteSequencePrimitiveTest, OutputStream_MultipleBytes)
{
    ByteSequence bs{0x00u, 0x7Fu, 0x80u};
    std::ostringstream oss;
    oss << bs;
    EXPECT_EQ(oss.str(), "[0x00 0x7F 0x80]");
}
