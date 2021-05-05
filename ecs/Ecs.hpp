#pragma once

#include "EntityManager.hpp"
#include "SceneManager.hpp"

template<typename ComponentList>
class Ecs {
    EntityManager<ComponentList> entityManager;
    SceneManager sceneManager;

    void run()
    {
        while (1) {
            loop();
        }
    }

private:
    void loop()
    {

    }
};
