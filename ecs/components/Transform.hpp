/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Transform
*/

#pragma once

#include "common/Vec3.hpp"

namespace ecs::components {

struct Transform {
    Vec3f position;
    Vec3f scale;
    Vec3f rotation;
};

}
