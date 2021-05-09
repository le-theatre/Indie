/*
** EPITECH PROJECT, 2021
** indie
** File description:
** ArgumentsParser
*/

#include "lib/cli/Parser.hpp"
#include "ArgumentsParser.hpp"

namespace indie {

ArgumentsParser::ArgumentsParser(int argc, char const **argv) :
    commandLine_(argc, argv),
    config_({"", 0, false})
{
    AddDebugHandler();
    AddAddressHandler();
    AddPortHandler();
}

server::Config ArgumentsParser::GetConfig()
{
    if (!commandLine_.parse()) {
        throw std::runtime_error("unable to parse configuration");
    }
    return config_;
}

void ArgumentsParser::AddDebugHandler()
{
    commandLine_.addFlag("--debug", "-d", [&debug = config_.debug]() {
        debug = true;
    });
}

void ArgumentsParser::AddAddressHandler()
{
    commandLine_.addRequiredOption("--address", "-a",
        [&address = config_.address](const std::string &value) {
            address = value;
            return true;
        });
}

void ArgumentsParser::AddPortHandler()
{
    commandLine_.addRequiredOption("--port", "-p",
        [&port = config_.port](const std::string &value) {
            port = (server::Config::Port)std::stoi(value);
            return true;
        });
}

}
