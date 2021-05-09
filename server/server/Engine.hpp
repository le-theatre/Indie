/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Engine
*/

#pragma once

#include <string>
#include "Config.hpp"

namespace server {

class Engine {
public:
    Engine();
    int Run();
    void SetConfig(const Config &config);

private:
    Config config_;
};

}
