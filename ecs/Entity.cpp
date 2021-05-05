/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Entity
*/

#include "Entity.hpp"

namespace ecs {

Entity::Entity()
{

}

Entity::ID Entity::getID() const
{
    return $id;
}

}
