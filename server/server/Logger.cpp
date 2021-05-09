/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Logger
*/

#include <iostream>
#include <sstream>
#include "Logger.hpp"

namespace server {

Logger &Logger::GetInstance()
{
    static Logger instance;
    return instance;
}

void Logger::SetLogLevel(LogLevel level)
{
    level_ = level;
}

void Logger::Debug(const std::string &message)
{
    if ((int)level_ > (int)LogLevel::Debug) {
        return;
    }
    std::stringstream stream;
    stream << "\033[35mDEBUG\033[0m "
        << message
        << "\n";
    std::cerr << stream.str();
}

void Logger::Info(const std::string &message)
{
    if ((int)level_ > (int)LogLevel::Info) {
        return;
    }
    std::stringstream stream;
    stream << "\033[34mINFO\033[0m "
        << message
        << "\n";
    std::cerr << stream.str();
}

void Logger::Warning(const std::string &message)
{
    if ((int)level_ > (int)LogLevel::Warn) {
        return;
    }
    std::stringstream stream;
    stream << "\033[33mWARN\033[0m "
        << message
        << "\n";
    std::cerr << stream.str();
}

void Logger::Error(const std::string &message)
{
    if ((int)level_ > (int)LogLevel::Error) {
        return;
    }
    std::stringstream stream;
    stream << "\033[31mERROR\033[0m "
        << message
        << "\n";
    std::cerr << stream.str();
}

}
