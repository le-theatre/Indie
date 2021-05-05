#pragma once

#include <bitset>
#include "TypeList.hpp"

// tmp
#include <iostream>
#include <vector>
#include <climits>
#include <cstdint>
#include <type_traits>
#include <utility>
#include <tuple>

template<typename typeList, typename SignatureComponents>
struct Signature {
public:
    std::bitset<typeList::size> $bitset;

    template<typename C>
    void setBit()
    {
        $bitset[IndexOf<C, typeList>::value] = true;
    }

    template <typename ... Types>
    void callSetBit(TypeList<Types...>) {
        (setBit<Types>(), ...);
    }

    Signature() {
        std::cout << "Bitset size: " << $bitset.size() << std::endl;
        callSetBit(SignatureComponents{});
        std::cout << "Bitset: " << $bitset.to_string() << std::endl;
    }
};
