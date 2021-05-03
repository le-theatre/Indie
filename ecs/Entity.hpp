/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Entity
*/

#include <vector>

#pragma once

namespace ecs {

class Entity {
    public:
        using ID = std::size_t;
        ID getId() const {
            return $entityId;
        }

        // ID getParentId() const {
        //     return $parentId;
        // }

        // const std::vector &getChildrensId() const {
        //     return $childrens;
        // }

    private:
        ID $entityId;
        // ID $parentId;
        // std::vector<ID> $childrens;
};

}
