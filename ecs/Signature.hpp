/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Signature
*/

#pragma once

#include <bitset>
#include <type_traits>
#include <utility>

#include "common/TypeList.hpp"

namespace Ecs {

template<typename typeList, typename SignatureComponents>
struct Signature {
public:
    std::bitset<typeList::size> bitset;

    template<typename C>
    void setBit()
    {
        bitset[IndexOf<C, typeList>::value] = true;
    }

    template <typename ... Types>
    void callSetBit(TypeList<Types...>)
    {
        (setBit<Types>(), ...);
    }

    Signature()
    {
        callSetBit(SignatureComponents{});
    }
};

}
