#pragma once

#include <memory>
#include <tuple>

#include "System.hpp"

template<typename ... SystemList>
class Scene {
private:
    std::tuple<SystemList...> $systems;

protected:
    EntityManager<Components> &$manager;
    Scene(EntityManager<Components> &manager) : $manager(manager) {}

public:
    virtual void onStart() {}
    virtual void onStop() {}
    virtual void onPause() {}
    virtual void onResume() {}
    virtual void handleEvent() {}
    virtual void fixedUpdate() {}
    virtual void update(float deltaTime) {}
    virtual void shadowUpdate(float deltaTime) {}
    virtual void shadowFixedUpdate() {}

    template<typename TSystem>
    void runSystem(TSystem &system)
    {
        for (auto &entity : $manager.$entities) {
            std::cout << "entity(" << entity.entityId << ")" << std::endl;
            if (entity.isAlive and system.match(entity.bitset)) {
                system.updateEntity(entity.entityId, $manager);
            }
        }
    }

    void updateSystems()
    {
        std::apply([this](auto &&...args){((runSystem(args)), ...);}, $systems);
    }
};

class SceneManager {

};
