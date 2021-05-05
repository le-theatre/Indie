#include "Signature.hpp"
#include "EntityManager.hpp"
#include <iostream>

#include "Components.hpp"
#include "System.hpp"
#include "Scene.hpp"
#include "Ecs.hpp"

class MovementSystem : public ISystem<Transform, Velocity> {
public:
    void run(
        Ecs<Components> &ecs,
        Transform &transform,
        Velocity &velocity
    ) override {
        transform.position += (velocity.direction * velocity.speed);
    }
};

class RenderSystem : public ISystem<Transform, Renderer> {
public:
    void run(
        Ecs<Components> &ecs,
        Transform &transform,
        Renderer &renderer
    ) override {
        renderer.shape.setPosition(sf::Vector2f(transform.position.x, transform.position.y));
        ecs.window.draw(renderer.shape);
    }
};

#include <SFML/Window/Event.hpp>
class GameScene : public Scene<MovementSystem, RenderSystem> {
public:
    GameScene(Ecs<Components> &ecs) : Scene(ecs) {}

    void update(float deltatime) {
        $ecs.window.display();
        $ecs.window.clear();
        sf::Event event;
        while ($ecs.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                $ecs.scenes.pop();
            }
        }
    }
};

#include <memory>

int main(void)
{
    Ecs<Components> ecs;
    std::bitset<Components::size> b;
    for (auto i = 0; i < 100; ++i) {
        auto builder = ecs.entityManager
            .createEntity()
            .addComponent<Transform>(sf::Vector3f(std::rand() % 1920, std::rand() % 1080, 0))
            .addComponent<Velocity>(std::rand() % 10, sf::Vector3f((std::rand() % 3) - 1, (std::rand() % 3) - 1, 0))
            .addComponent<Renderer>(sf::Color(std::rand()%255, std::rand()%255, std::rand()%255));
        builder.build();
    }

    ecs.scenes.push(std::make_unique<GameScene>(ecs));
    ecs.run();
}

