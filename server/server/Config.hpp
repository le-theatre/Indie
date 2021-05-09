/*
** EPITECH PROJECT, 2021
** indie
** File description:
** ServerConfig
*/

#pragma once

#include <string>

namespace server {

struct Config {
    using Port = uint16_t;
    std::string address;
    Port port;
    bool debug;
};

}
