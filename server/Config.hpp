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
    std::string address;
    short port;
    bool debug;
};

}
