/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Server
*/

#include "Server.hpp"
#include "Logger.hpp"

namespace server {

Server::Server()
{
}

int Server::run()
{
    Logger::getInstance().info("starting server");
    return 0;
}

void Server::setAddress(const std::string &address)
{
    m_address = address;
}

void Server::setDebug(bool debug)
{
    m_debug = debug;
}

void Server::setPort(short port)
{
    m_port = port;
}

}
