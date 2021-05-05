#pragma once

// TODO Use our own vectors
#include <SFML/System/Vector3.hpp>

#include "TypeList.hpp"

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

struct Velocity {
    float speed;
    sf::Vector3f direction;

    Velocity(
        float _speed = 0.f,
        const sf::Vector3f &_direction = sf::Vector3f(0, 0, 0)
    ) : speed(_speed), direction(_direction) {}
};

struct Collider {};

#include <SFML/Graphics/RectangleShape.hpp>

struct Renderer {
    sf::RectangleShape shape;

    Renderer(
        const sf::Color &color = sf::Color::White
    ) {
        shape.setFillColor(color);
        shape.setSize(sf::Vector2f(10, 10));
        shape.setOrigin(shape.getSize() / 2.f);
    }
};

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
