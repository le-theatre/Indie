/*
** EPITECH PROJECT, 2021
** indie
** File description:
** args
*/

#include <iostream>
#include "clilib/Parser.hpp"
#include "IndieStudioServer.hpp"
#include "Settings.hpp"
#include "Server.hpp"

IndieStudioServer::IndieStudioServer(int argc, char const **argv) :
    m_argc(argc),
    m_argv(argv),
    m_address(),
    m_port(0),
    m_debug(false)
{
}

int IndieStudioServer::start()
{
    server::Server server;

    if (!tryParseArguments()) {
        return 84;
    }
    server.setPort(m_port);
    server.setAddress(m_address);
    server.setDebug(m_debug);
    return server.run();
}

bool IndieStudioServer::tryParseArguments()
{
    clilib::Parser commandLine(m_argc, m_argv);
    std::string address;
    short port;
    bool debug;

    commandLine.addFlag("--debug", "-d", [&debug]() {
        debug = true;
    });
    commandLine.addRequiredOption("--port", "-p", [&port](const std::string &value) {
        try { port = std::stoi(value); }
        catch (...) {
            std::cerr << "error: port must be a number" << std::endl;
            return false;
        }
        return true;
    });
    commandLine.addRequiredOption("--address", "-a", [&address](const std::string &value) {
        address = value;
        return true;
    });
    if (!commandLine.parse()) {
        std::cerr << Usage;
        return false;
    }
    m_debug = debug;
    m_address = address;
    m_port = port;
    return true;
}
