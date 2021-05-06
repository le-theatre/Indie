/*
** EPITECH PROJECT, 2021
** indie
** File description:
** ECS
*/

#pragma once

#include <stack>
#include <memory>
#include "EntityManager.hpp"
#include "IScene.hpp"
/// TODO: Change render system
#include <SFML/Graphics/RenderWindow.hpp>

template<typename ComponentList>
class ECS {
public:
    EntityManager<ComponentList> entityManager;
    std::stack<std::unique_ptr<IScene>> scenes;

    /// TODO: Change render system
    sf::RenderWindow window{sf::VideoMode(1920, 1080), "ECS"};

    void run()
    {
        std::cout << "Starting ECS..." << std::endl;
        while (scenes.size()) {
            tick();
        }
        std::cout << "Ending ECS..." << std::endl;
    }

private:
    void tick()
    {
        auto scene = scenes.top().get();
        scene->update(1.f / 60.f);
        scene->updateSystems();
    }
};
