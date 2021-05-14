#include <iostream>

#include "ecs/Scene.hpp"
#include "ecs/System.hpp"
#include "ecs/World.hpp"

/* Personnals Components */
#include "Components.hpp"

class MovementSystem : public Ecs::System<Components, Transform, Velocity> {
public:
    void run(
        Ecs::World<Components> &world,
        Transform &transform,
        Velocity &velocity
    ) final {
        transform.position += (velocity.direction * velocity.speed * (world.deltaTime / 1e2f));
    }
};

class RenderSystem : public Ecs::System<Components, Transform, Renderer> {
public:
    void run(
        Ecs::World<Components> &world,
        Transform &transform,
        Renderer &renderer
    ) final {
        renderer.shape.setScale(sf::Vector2f(transform.scale.x, transform.scale.y));
        renderer.shape.setPosition(sf::Vector2f(transform.position.x, transform.position.y));
        world.window.draw(renderer.shape);
    }
};

class AreYouSureScene : public Ecs::Scene<Components, TypeList<RenderSystem>>
{
public:
    AreYouSureScene(Ecs::World<Components> &ecs) : Scene(ecs) {}

    void onStart()
    {
        ecs.entityManager.createEntity()
            .addComponent<Transform>(Vec3f(1920 / 2, 1080 / 2), Vec3f(), Vec3f(100, 25))
            .addComponent<Renderer>()
            .build();
    }

    void update(float deltatime) {
        Scene::update(deltatime);

        ecs.window.display();
        ecs.window.clear();
        sf::Event event;
        while (ecs.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                ecs.stop();
            }
        }
    }
};

#include <SFML/Window/Event.hpp>
class GameScene : public Ecs::Scene<Components, TypeList<MovementSystem, RenderSystem>>
{
public:
    GameScene(Ecs::World<Components> &ecs) : Scene(ecs) {}

    void update(float deltatime) {
        Scene::update(deltatime);

        ecs.window.display();
        ecs.window.clear();
        sf::Event event;
        while (ecs.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                ecs.sceneManager.push<AreYouSureScene>();
            }
        }
    }
};

#include <memory>

int main(void)
{
    Ecs::World<Components> world;
    for (auto i = 0; i < 15000; ++i) {
        world.entityManager
            .createEntity()
            .addComponent<Transform>(Vec3f(std::rand() % 1920, std::rand() % 1080, 0))
            .addComponent<Velocity>(std::rand() % 10 + 1, Vec3f((std::rand() % 3) - 1, (std::rand() % 3) - 1, 0))
            .addComponent<Renderer>(sf::Color(std::rand()%255, std::rand()%255, std::rand()%255))
            .build();
    }

    world.sceneManager.push<GameScene>();
    world.run();
}

