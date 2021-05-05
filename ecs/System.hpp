#pragma once

#include "Components.hpp"

template<typename T>
class EntityManager;

template<typename ... Ts>
class ISystem {
public:
    Signature<Components, TypeList<Ts...>> signature;
    virtual void run(Ts &...args) = 0;

    bool match(const std::bitset<Components::size> &entity)
    {
        return (entity & signature.bitset) == signature.bitset;
    }

    void updateEntity(std::size_t entityid, EntityManager<Components> &manager)
    {
        run(manager.template getEntityComponent<Ts>(entityid)...);
    }
};
