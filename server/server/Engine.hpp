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
    void SetAddress(const std::string &address);
    void SetPort(short port);
    void SetDebug(bool debugMode);

private:
    Config config_;
};

}
