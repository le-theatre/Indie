#pragma once

#include <bitset>
#include <type_traits>
#include <utility>

#include "TypeList.hpp"

// tmp

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
