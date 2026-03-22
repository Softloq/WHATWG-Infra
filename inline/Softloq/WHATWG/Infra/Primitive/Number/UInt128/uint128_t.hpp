/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/UInt128/uint128_t.hpp
 * @brief This header defines the uint128_t type. It is a struct representing a 128-bit unsigned integer, composed of two 64-bit parts: high and low.
 * 
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the uint128_t type, a struct representing a 128-bit unsigned integer, composed of two 64-bit parts: high and low.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT128_UINT128_T_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT128_UINT128_T_HPP

#include <compare>
#include <cstdint>
#include <ostream>

namespace Softloq::WHATWG::Infra
{

/**
 * @brief A struct representing a 128-bit unsigned integer, composed of two 64-bit parts: high and low.
 */
class uint128_t final
{
    std::uint64_t high;
    std::uint64_t low;

// std::regular requirements
public:
    uint128_t() noexcept = default;
    uint128_t(std::uint64_t high_part, std::uint64_t low_part) noexcept : high(high_part), low(low_part) {}
    uint128_t(const uint128_t&) noexcept = default;
    uint128_t& operator=(const uint128_t& other) noexcept
    {
        if (this != &other)
        {
            high = other.high;
            low = other.low;
        }
        return *this;
    }
    friend bool operator==(const uint128_t&, const uint128_t&) = default;

// std::totally_ordered requirements
public:
    friend bool operator<(const uint128_t& lhs, const uint128_t& rhs) noexcept
    {
        if (lhs.high != rhs.high)
            return lhs.high < rhs.high;
        return lhs.low < rhs.low;
    }

    friend bool operator>(const uint128_t& lhs, const uint128_t& rhs) noexcept
    {
        if (lhs.high != rhs.high)
            return lhs.high > rhs.high;
        return lhs.low > rhs.low;
    }

    friend bool operator<=(const uint128_t& lhs, const uint128_t& rhs) noexcept
    {
        if (lhs.high != rhs.high)
            return lhs.high < rhs.high;
        return lhs.low <= rhs.low;
    }

    friend bool operator>=(const uint128_t& lhs, const uint128_t& rhs) noexcept
    {
        if (lhs.high != rhs.high)
            return lhs.high > rhs.high;
        return lhs.low >= rhs.low;
    }

    auto operator<=>(const uint128_t& other) noexcept
    {
        if (high != other.high)
            return high <=> other.high;
        return low <=> other.low;
    }

// Arithmetic operator requirements
public:
    uint128_t operator+(const uint128_t& other) const noexcept
    {
        uint128_t result;
        result.low = low + other.low;
        result.high = high + other.high + (result.low < low); // Handle carry
        return result;
    }

    uint128_t operator-(const uint128_t& other) const noexcept
    {
        uint128_t result;
        result.low = low - other.low;
        result.high = high - other.high - (low < other.low); // Handle borrow
        return result;
    }

    uint128_t operator*(const uint128_t& other) const noexcept
    {
        // This is a simple implementation that does not handle overflow.
        // A complete implementation would need to handle the full 128-bit multiplication.
        uint128_t result;
        result.low = low * other.low;
        result.high = high * other.low + low * other.high; // Cross terms
        return result;
    }

    uint128_t operator/(const uint128_t& other) const noexcept
    {
        // Division of 128-bit integers is complex and typically requires a more sophisticated algorithm.
        // This is a placeholder implementation that does not perform actual division.
        return uint128_t{};
    }

    uint128_t operator%(const uint128_t& other) const noexcept
    {
        // Modulo of 128-bit integers is complex and typically requires a more sophisticated algorithm.
        // This is a placeholder implementation that does not perform actual modulo.
        return uint128_t{};
    }

    uint128_t& operator+=(const uint128_t& other) noexcept { *this = *this + other; return *this; }
    uint128_t& operator-=(const uint128_t& other) noexcept { *this = *this - other; return *this; }
    uint128_t& operator*=(const uint128_t& other) noexcept { *this = *this * other; return *this; }
    uint128_t& operator/=(const uint128_t& other) noexcept { *this = *this / other; return *this; }
    uint128_t& operator%=(const uint128_t& other) noexcept { *this = *this % other; return *this; }

    uint128_t& operator++() noexcept { *this += uint128_t{0, 1}; return *this; }
    uint128_t operator++(int) noexcept { uint128_t copy = *this; ++(*this); return copy; }
    uint128_t& operator--() noexcept { *this -= uint128_t{0, 1}; return *this; }
    uint128_t operator--(int) noexcept { uint128_t copy = *this; --(*this); return copy; }
    
    uint128_t operator<<(int shift) const noexcept
    {
        if (shift >= 128)
            return uint128_t{0, 0};
        else if (shift >= 64)
            return uint128_t{low << (shift - 64), 0};
        else
            return uint128_t{(high << shift) | (low >> (64 - shift)), low << shift};
    }

    uint128_t operator>>(int shift) const noexcept
    {
        if (shift >= 128)
            return uint128_t{0, 0};
        else if (shift >= 64)
            return uint128_t{0, high >> (shift - 64)};
        else
            return uint128_t{high >> shift, (low >> shift) | (high << (64 - shift))};
    }

    uint128_t& operator<<=(int shift) noexcept { *this = *this << shift; return *this; }
    uint128_t& operator>>=(int shift) noexcept { *this = *this >> shift; return *this; }

// Output stream operator requirements
public:
    friend std::ostream& operator<<(std::ostream& os, const uint128_t& value)
    {
        // This is a simple implementation that prints the high and low parts in hexadecimal.
        // A more complete implementation might convert the entire 128-bit value to decimal.
        return os << std::hex << value.high << std::hex << value.low << std::dec;
    }
};

} // namespace Softloq::WHATWG::Infra

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_UINT128_UINT128_T_HPP