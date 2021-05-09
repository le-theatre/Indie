/*
** EPITECH PROJECT, 2021
** indie
** File description:
** ArgumentsParser
*/

#pragma once

#include "server/Config.hpp"

namespace indieserv {

class ArgumentsParser {
public:
    ArgumentsParser(int argc, char const **argv);
    server::Config GetConfig();

private:
    void AddDebugHandler();
    void AddAddressHandler();
    void AddPortHandler();

    clilib::Parser commandLine_;
    server::Config config_;
};

}
