/*
** EPITECH PROJECT, 2021
** indie
** File description:
** ISystem
*/

#pragma once

namespace ecs {

class ISystem {
    public:
        virtual ~ISystem() = default;

        virtual void run() = 0;

    protected:
    private:
};

}
