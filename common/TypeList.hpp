/*
** EPITECH PROJECT, 2021
** indie
** File description:
** TypeList
*/

#pragma once

#include <cstdint>
#include <vector>
#include <tuple>
#include <type_traits>

template<typename ...Ts>
struct TypeList
{
    using Tuple = std::tuple<Ts...>;
    static constexpr std::size_t size{sizeof...(Ts)};
};

template<typename, typename>
struct IndexOf {};

template <typename T, typename... Ts>
struct IndexOf<T, TypeList<T, Ts...>>
    : std::integral_constant<std::size_t, 0>
{
};

template <typename T, typename TOther, typename... Ts>
struct IndexOf<T, TypeList<TOther, Ts...>>
    : std::integral_constant<std::size_t, 1 + IndexOf<T, TypeList<Ts...>>::value>
{
};

///////////////////////////////////////////////////////////////////////////////
// simple code example:
//
// struct T1 {};
//
// struct T2 {};
//
// struct T3 {};
//
// struct T4 {};
//
// using Types = TypeList<T1, T2, T3, T4>;
//
// std::cout << Types::size << std::endl;
// std::cout << IndexOf<T2, Types>::value << std::endl;
//
///////////////////////////////////////////////////////////////////////////////
