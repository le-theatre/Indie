/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Components
*/

#pragma once

#include "common/Vec3.hpp"

#include "common/TypeList.hpp"

struct Transform {
    Vec3f position;
    Vec3f rotation;
    Vec3f scale;

    Transform(
        const Vec3f &_position = Vec3f(0, 0, 0),
        const Vec3f &_rotation = Vec3f(0, 0, 0),
        const Vec3f &_scale = Vec3f(1, 1, 1)
    ) : position(_position), rotation(_rotation), scale(_scale) {}
};

struct Velocity {
    float speed;
    Vec3f direction;

    Velocity(
        float _speed = 0.f,
        const Vec3f &_direction = Vec3f(0, 0, 0)
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
