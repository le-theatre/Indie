/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Server
*/

#pragma once

#include <string>

namespace server {

class Server {
public:
    Server();

    void setAddress(const std::string &address);

    void setPort(short port);

    void setDebug(bool debugMode);

    int run();

private:
    std::string m_address;
    short m_port;
    bool m_debug;
};

}
