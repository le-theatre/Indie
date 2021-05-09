/*
** EPITECH PROJECT, 2021
** indie
** File description:
** IndieServer
*/

#pragma once

#include <string>
#include "server/Config.hpp"
#include "server/Engine.hpp"

namespace indieserv {

static const std::string IndieServerUsage = \
    "usage: ./server [-a address|--address address]\n"
    "                [-p port|--port port]\n"
    "                [-d|--debug]\n";

class IndieServer {
public:
    IndieServer(int argc, char const **argv);
    int Run();

private:
    bool TryParseCommandOptions();
    void ParseCommandOptions();
    void InitServer();
    void RegisterOptionHandlers();
    void DisplayUsage();

    int argc_;
    char const **argv_;
    server::Config config_;
    server::Engine server_;
};

}
