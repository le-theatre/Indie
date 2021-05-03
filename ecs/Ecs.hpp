/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Ecs
*/

#pragma once

#include <vector>
#include "ISystem.hpp"
#include "World.hpp"

namespace ecs {

class Ecs {
public:
    Ecs();
    ~Ecs();
    void run();
    Ecs &registerSystem();

    World world;

private:
    std::vector<ISystem> _systems;
};

}
