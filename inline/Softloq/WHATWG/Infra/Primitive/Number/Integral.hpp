/**
 * @file Softloq/WHATWG/Infra/Primitive/Number/Integral.hpp
 * @author Softloq CEO - Brandon Foster (Paradox Gene)
 * @brief This header defines the Integral type for the WHATWG Infra library, representing integral numeric values in the context of web APIs.
 * 
 * Copyright (c) 2026 Softloq. All rights reserved.
 * Softloq implementation of the WHATWG Infra library.
 * This header defines the Integral type for the WHATWG Infra library.
 * The Integral type is a specialization of the Number template for integral types, providing additional functionality specific to integral values.
 */

#ifndef SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INTEGRAL_HPP
#define SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INTEGRAL_HPP

#include <concepts>
#include <ostream>

namespace Softloq::WHATWG::Infra
{

/**
 * @brief Concept for types that behave like integral types, supporting basic arithmetic and comparison operations.
 */
template <typename T>
concept IntegralConcept =
    std::regular<T>
    && std::swappable<T>
    && std::totally_ordered<T>
    && requires(T a, T b)
    {
        { a + b }  -> std::same_as<T>;
        { a += b } -> std::same_as<T&>;
        { a - b }  -> std::same_as<T>;
        { a -= b } -> std::same_as<T&>;
        { a * b }  -> std::same_as<T>;
        { a *= b } -> std::same_as<T&>;
        { a / b }  -> std::same_as<T>;
        { a /= b } -> std::same_as<T&>;
        { a % b }  -> std::same_as<T>;
        { a %= b } -> std::same_as<T&>;

        { ++a }    -> std::same_as<T&>;
        { a++ }    -> std::same_as<T>;
        { --a }    -> std::same_as<T&>;
        { a-- }    -> std::same_as<T>;
    }
    && requires(T a, int n)
    {
        { a << n } -> std::same_as<T>;
        { a <<= n } -> std::same_as<T&>;
        { a >> n } -> std::same_as<T>;
        { a >>= n } -> std::same_as<T&>;
    }
    && requires(std::ostream& os, T a)
    {
        { os << a } -> std::same_as<std::ostream&>;
    };

/**
 * @brief Concept for integral types, including both standard integral types and user-defined types that satisfy IntegralLike.
 */
template <typename T>
concept Integral = std::integral<T> || IntegralConcept<T>;

} // namespace Softloq::WHATWG::Infra

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INTEGRAL_HPP