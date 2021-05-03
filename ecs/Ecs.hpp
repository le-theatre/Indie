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

class Ecs {
    public:
        Ecs();
        ~Ecs();

        void run();
        Ecs &registerSystem();

        ecs::World world;

    protected:
    private:
        std::vector<ISystem> _systems;
};
