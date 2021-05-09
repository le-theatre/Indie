/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Engine
*/

#include "Engine.hpp"
#include "Logger.hpp"

namespace server {

Engine::Engine()
{

}

int Engine::Run()
{
    Logger::GetInstance().Info("starting server");
    return 0;
}

void Engine::SetAddress(const std::string &address)
{
    config_.address = address;
}

void Engine::SetDebug(bool debug)
{
    config_.debug = debug;
}

void Engine::SetPort(short port)
{
    config_.port = port;
}

void Engine::SetConfig(const Config &config)
{
    config_ = config;
}

}
