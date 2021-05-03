/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Entity
*/


#pragma once

#include <vector>

namespace ecs {

class Entity {
public:
    using ID = std::size_t;
    Entity();
    ID getID() const;
private:
    ID $id;
};

}
