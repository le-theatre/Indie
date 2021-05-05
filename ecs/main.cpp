#include "Signature.hpp"
#include "EntityManager.hpp"
#include <iostream>

#include "Components.hpp"
#include "System.hpp"
#include "SceneManager.hpp"

class MovementSystem : public ISystem<Transform, Velocity> {
public:
    void run(Transform &transform, Velocity &velocity) override {
        std::cout
            << "MovementSystem: position: "
            << transform.position.x << " "
            << transform.position.y << " "
            << transform.position.z << std::endl;
    }
};


class GameScene : public Scene<MovementSystem> {
public:
    GameScene(EntityManager<Components> &manager) : Scene(manager) {}
};

#include <memory>

int main(void)
{
    EntityManager<Components> manager;
    for (auto i = 0; i < 100; ++i) {
    manager
        .createEntity()
        .addComponent<Transform>(sf::Vector3f(5, 10, 9))
        .addComponent<Velocity>(10, sf::Vector3f(50, 0, 0))
        .build();
    }

    manager
        .createEntity()
        .addComponent<Transform>(sf::Vector3f(10, 9, 8))
        .addComponent<Audio>()
        .build();
    // std::cout << builder.getEntity().bitset.to_string() << std::endl;

    GameScene s(manager);

    s.updateSystems();
}

// g++ main.cpp -std=c++17
