#pragma once

#include <tuple>

#include "World.hpp"
#include "IScene.hpp"

namespace Ecs {

template<typename ComponentList, typename ... SystemList>
class Scene : public IScene {
private:
    std::tuple<SystemList...> $systems;

protected:
    World<ComponentList> &$ecs;

public:
    Scene(World<ComponentList> &ecs) : $ecs(ecs) {}

    virtual void onStart() {}
    virtual void onStop() {}
    virtual void onPause() {}
    virtual void onResume() {}
    virtual void handleEvent() {}
    virtual void fixedUpdate() {}
    virtual void update(float) { updateSystems(); }
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

}
