#pragma once

#include <stack>
#include <memory>

#include "EntityManager.hpp"
#include "IScene.hpp"

// To refacto
#include <SFML/Graphics/RenderWindow.hpp>

template<typename ComponentList>
class Ecs {
public:
    EntityManager<ComponentList> entityManager;
    std::stack<std::unique_ptr<IScene>> scenes;

    // To refacto
    sf::RenderWindow window{sf::VideoMode(1920, 1080), "Ecs"};

    void run()
    {
        std::cout << "Starting Ecs..." << std::endl;
        while (scenes.size()) {
            tick();
        }
        std::cout << "Ending Ecs..." << std::endl;
    }

private:
    void tick()
    {
        auto scene = scenes.top().get();
        scene->update(1.f / 60.f);
        scene->updateSystems();
    }
};
