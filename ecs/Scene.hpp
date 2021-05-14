/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Scene
*/

#pragma once

#include <tuple>

#include "World.hpp"
#include "IScene.hpp"

namespace Ecs {

template<
    typename ComponentList,
    typename UpdateSystemList,
    typename SetupSystemList = TypeList<>
>
class Scene : public IScene {
private:
    typename UpdateSystemList::Tuple $updateSystems;
    typename SetupSystemList::Tuple $setupSystems;

    template<typename TSystem>
    void runSystem(TSystem &system)
    {
        for (auto &entity : ecs.entityManager.$entities) {
            if (entity.isAlive and system.match(entity.bitset)) {
                system.updateEntity(entity.entityId, ecs);
            }
        }
    }

    template <typename SystemList>
    void updateSystems(typename SystemList::Tuple systems)
    {
        std::apply([this](auto &&...args){((runSystem(args)), ...);}, systems);
    }

protected:
    World<ComponentList> &ecs;

public:
    Scene(World<ComponentList> &$ecs) : ecs($ecs) {}

    /**
     * @brief onStart function is called for a scene
     * when it is pushed on the scene stack
     */
    virtual void onStart()
    {
        updateSystems<SetupSystemList>($setupSystems);
    }

    /**
     * @brief onStop function is called right before
     * the scene is pop of the stack
     */
    virtual void onStop() {}

    /**
     * @brief onPause function is called when a scene
     * is pushed over the current scene
     * 
     */
    virtual void onPause() {}

    /**
     * @brief onResume is called when the current scene
     * is popped and the scene goes on top of the scene stack
     */
    virtual void onResume() {}

    /**
     * @brief dunno what to do with this
     */
    virtual void handleEvent() {}

    /**
     * @brief The fixedUpdate function is called at a fixed time 
     */
    virtual void fixedUpdate() {}

    /**
     * @brief The update function is called as much as possible
     * This function is only called for the scene at the top of the "stack"
     * @param deltaTime represent the elapsed time between two frames
     */
    virtual void update([[maybe_unused]] float deltaTime) 
    {
        updateSystems<UpdateSystemList>($updateSystems);
    }

    /**
     * @brief Same behaviour as update() but called
     * for every scene in the stack scene except for the top scene
     */
    virtual void shadowUpdate(float) {}

    /**
     * @brief Same behaviour as fixedUpdate() but called
     * for every scene in the stack scene except for the top scene
     */
    virtual void shadowFixedUpdate() {}

};

}
