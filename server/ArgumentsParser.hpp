/*
** EPITECH PROJECT, 2021
** indie
** File description:
** ArgumentsParser
*/

#pragma once

#include "lib/cli/Parser.hpp"
#include "server/Config.hpp"

namespace indie {

class ArgumentsParser {
public:
    ArgumentsParser(int argc, char const **argv);
    server::Config GetConfig();

private:
    void AddDebugHandler();
    void AddAddressHandler();
    void AddPortHandler();

    lib::cli::Parser commandLine_;
    server::Config config_;
};

}
