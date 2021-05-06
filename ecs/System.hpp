/*
** EPITECH PROJECT, 2021
** indie
** File description:
** System
*/

#pragma once

#include "ECS.hpp"
#include "Components.hpp"

template<typename ... Ts>
class ISystem {
public:
    Signature<Components, TypeList<Ts...>> signature;
    virtual void run(ECS<Components> &ecs, Ts &...args) = 0;

    bool match(const std::bitset<Components::size> &entity)
    {
        return (entity & signature.bitset) == signature.bitset;
    }

    void updateEntity(std::size_t entityid, ECS<Components> &ecs)
    {
        run(ecs, ecs.entityManager.template getEntityComponent<Ts>(entityid)...);
    }
};
