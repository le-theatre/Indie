#pragma once

#include <stack>
#include <memory>

#include "EntityManager.hpp"
#include "SceneManager.hpp"

#include <SFML/Graphics.hpp>
#include <chrono>
#include <ctime>
// #include <boost/any.hpp>

namespace Ecs {

template<typename ComponentList>
class World
{
private:

public:
    static inline const float FRAME = 1.f / 60.f;
    float deltaTime = FRAME;

    sf::RenderWindow window{sf::VideoMode(1920, 1080), "ECS"};

    EntityManager<ComponentList>    entityManager;
    SceneManager<ComponentList>     sceneManager;

    World() : sceneManager(*this) {}

    void run()
    {
        auto start = std::chrono::system_clock::now();
        // auto end = start;
        float previousTime = 0.f, counter = 0.f;

        std::cout << "Starting World..." << std::endl;
        while (sceneManager.isOk()) {
            auto end = std::chrono::system_clock::now();
            auto elapsedTime = (end - start).count() / 1e6f;

            deltaTime = previousTime - elapsedTime;
            counter += deltaTime;
            previousTime = elapsedTime;
            while (counter > World::FRAME) {
                sceneManager.fixedUpdate();
                counter -= World::FRAME;
            }
            sceneManager.update(deltaTime);
        }
        std::cout << "Ending World..." << std::endl;
    }

};

}
