/*
** EPITECH PROJECT, 2021
** indie
** File description:
** IndieStudioServer
*/

#pragma once

#include <string>

static const std::string Usage = "usage: ./server [-a address|--address address]\n"
                                 "                [-p port|--port port]\n"
                                 "                [-d|--debug]\n";

class IndieStudioServer {
public:
    IndieStudioServer(int argc, char const **argv);

    int start();

private:
    bool tryParseArguments();

    int m_argc;
    char const **m_argv;
    std::string m_address;
    short m_port;
    bool m_debug;
};
