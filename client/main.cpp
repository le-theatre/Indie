/*
** EPITECH PROJECT, 2021
** indie
** File description:
** main
*/

#include "systems/Draw.hpp"
#include "ecs/Ecs.hpp"

int main(void)
{
    Ecs ecs;

    ecs.registerSystem(Draw());
    ecs.registerSystem(Move());
    ecs.registerSystem(Collisions());
    ecs.assetsDirectory("assets/");
    ecs.run();
}
