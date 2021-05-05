/*
** EPITECH PROJECT, 2021
** indie
** File description:
** main
*/

#include "systems/Draw.hpp"
#include "ecs/ECS.hpp"

int main(void)
{
    ecs::ECS ecs;

    ecs.registerSystem(Draw());
    ecs.registerSystem(Move());
    ecs.registerSystem(Collisions());
    ecs.assetsDirectory("assets/");
    ecs.run();
}
