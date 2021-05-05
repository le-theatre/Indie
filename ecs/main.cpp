#include "Signature.hpp"
#include "SFML/System/Vector3.hpp"
#include "EntityManager.hpp"
#include <iostream>

struct Transform {
    sf::Vector3f position;
    sf::Vector3f rotation;
    sf::Vector3f scale;

    Transform(
        const sf::Vector3f &_position = sf::Vector3f(0, 0, 0),
        const sf::Vector3f &_rotation = sf::Vector3f(0, 0, 0),
        const sf::Vector3f &_scale = sf::Vector3f(0, 0, 0)
    ) : position(_position), rotation(_rotation), scale(_scale) {}
};

struct Velocity {};

struct Collider {};

struct Renderer {};

struct Audio {};

struct TagPlayer {};

using Components = TypeList<
    Transform,
    Collider,
    Renderer,
    Velocity,
    Audio,
    TagPlayer
>;

Signature<Components, TypeList<Transform, Velocity>> MoveSignature;
Signature<Components, TypeList<Transform, Collider>> CollisionSignature;
Signature<Components, TypeList<Transform, Renderer>> RenderSignature;

int main(void)
{
    EntityManager<
        Transform,
        Collider,
        Renderer,
        Velocity,
        Audio,
        TagPlayer
    > manager;
    auto builder = manager
        .createEntity()
        .addComponent<Transform>(sf::Vector3f(5, 10, 9))
        .addComponent<Audio>();
    std::cout << builder.getEntity().bitset.to_string() << std::endl;

}

// g++ main.cpp -std=c++17
