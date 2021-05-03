/*
** EPITECH PROJECT, 2021
** indie
** File description:
** main
*/

#include "Draw.hpp"
#include "Ecs.hpp"

// Move => Transform, Vitesse, Direction



int main(void)
{
    Ecs ecs;

    ecs
        .registerSystem(Draw())
        .registerSystem(Move())
        .registerSystem(Collisions())
        .assetsDirectory("assets/")
        ;
    ecs.run();
}
