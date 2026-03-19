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
#include <cstdint>

namespace Softloq::WHATWG::Infra
{

template <typename T>
concept IntegralLike = requires(T a, T b) {
    { a + b }  -> std::convertible_to<T>;
    { a - b }  -> std::convertible_to<T>;
    { ++a }    -> std::same_as<T&>;
    { a == b } -> std::convertible_to<bool>;
    { a < b }  -> std::convertible_to<bool>;
    requires std::is_default_constructible_v<T>;
    requires std::is_copy_constructible_v<T>;
};

template <typename T>
concept Integral = std::integral<T> || IntegralLike<T>;

} // namespace Softloq::WHATWG::Infra

#endif // SOFTLOQ_WHATWG_INFRA_PRIMITIVE_NUMBER_INTEGRAL_HPP