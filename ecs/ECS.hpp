/*
** EPITECH PROJECT, 2021
** indie
** File description:
** ECS
*/

#pragma once

#include <vector>
#include "ISystem.hpp"
#include "World.hpp"

namespace ecs {

class ECS {
public:
    ECS();
    ~ECS();
    void run();
    void registerSystem();

private:
    World $world;
    std::vector<ISystem> $systems;
};

}
