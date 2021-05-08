/*
** EPITECH PROJECT, 2021
** indie
** File description:
** main
*/

#include <iostream>
#include "clilib/Parser.hpp"
#include "Settings.hpp"
#include "Server.hpp"

static const std::string Usage = "usage: ./server [-a address|--address address]\n"
                                 "                [-p port|--port port]\n"
                                 "                [-d|--debug]\n";

int indieStudioServer(const std::string &address, short port, bool debug)
{
    server::Server server;

    server.setPort(port);
    server.setAddress(address);
    server.setDebug(debug);
    return server.run();
}

int main(int argc, char const *argv[])
{
    clilib::Parser commandLine(argc, argv);
    std::string address;
    bool debug = false;
    short port = 0;

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
        return 84;
    }
    return indieStudioServer(address, port, debug);
}
