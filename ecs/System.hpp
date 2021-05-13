#pragma once

#include "World.hpp"

namespace Ecs {

template<typename ComponentList, typename ... Ts>
class System {
public:
    Signature<ComponentList, TypeList<Ts...>> signature;
    virtual void run(World<ComponentList> &ecs, Ts &...args) = 0;

    bool match(const std::bitset<ComponentList::size> &entity)
    {
        return (entity & signature.bitset) == signature.bitset;
    }

    void updateEntity(std::size_t entityid, World<ComponentList> &ecs)
    {
        run(ecs, ecs.entityManager.template getEntityComponent<Ts>(entityid)...);
    }
};

}
