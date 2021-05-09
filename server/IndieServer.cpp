/*
** EPITECH PROJECT, 2021
** indie
** File description:
** IndieServer
*/

#include <iostream>
#include "clilib/Parser.hpp"
#include "IndieServer.hpp"
#include "ArgumentsParser.hpp"

namespace indieserv {

IndieServer::IndieServer(int argc, char const **argv) :
    argc_(argc),
    argv_(argv),
    config_()
{

}

int IndieServer::Run()
{
    if (!TryParseCommandOptions()) {
        DisplayUsage();
        return 84;
    }
    InitServer();
    return server_.Run();
}

bool IndieServer::TryParseCommandOptions()
{
    try {
        ParseCommandOptions();
    } catch (...) {
        return false;
    }
    return true;
}

void IndieServer::ParseCommandOptions()
{
    config_ = ArgumentsParser(argc_, argv_).GetConfig();
}

void IndieServer::InitServer()
{
    server_.SetConfig(config_);
}

void IndieServer::DisplayUsage()
{
    std::cerr << IndieServerUsage;
}

}
