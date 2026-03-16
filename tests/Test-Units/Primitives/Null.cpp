#include <gtest/gtest.h>
#include <Softloq/WHATWG/Infra/Primitive/Null/Null.hpp>

using namespace Softloq::WHATWG::Infra;

TEST(NullPrimitiveTest, NullType) {
    Null null_value;
    EXPECT_EQ(null_value.get_type(), PrimitiveType::Null);
}
