/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Engine
*/

#include <iostream>
#include "lib/log/Logger.hpp"
#include "Engine.hpp"

namespace server {

Engine::Engine()
{

}

int Engine::Run()
{
    lib::log::Logger::Get().Info("Server", "listenning for requests");
    return 0;
}

void Engine::SetConfig(const Config &config)
{
    config_ = config;
}

}
