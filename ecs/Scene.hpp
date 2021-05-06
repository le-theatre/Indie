/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Scene
*/

#pragma once

#include <memory>
#include <tuple>
#include "System.hpp"
#include "ECS.hpp"
#include "IScene.hpp"

template<typename ... SystemList>
class Scene : public IScene {
private:
    std::tuple<SystemList...> $systems;

protected:
    ECS<Components> &$ecs;
    Scene(ECS<Components> &ecs) : $ecs(ecs) {}

public:
    virtual void onStart() {}
    virtual void onStop() {}
    virtual void onPause() {}
    virtual void onResume() {}
    virtual void handleEvent() {}
    virtual void fixedUpdate() {}
    virtual void update(float) {}
    virtual void shadowUpdate(float) {}
    virtual void shadowFixedUpdate() {}

    template<typename TSystem>
    void runSystem(TSystem &system)
    {
        for (auto &entity : $ecs.entityManager.$entities) {
            if (entity.isAlive and system.match(entity.bitset)) {
                system.updateEntity(entity.entityId, $ecs);
            }
        }
    }

    void updateSystems() final
    {
        std::apply([this](auto &&...args){((runSystem(args)), ...);}, $systems);
    }
};

