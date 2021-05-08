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

Logger &Logger::getInstance()
{
    static Logger instance;
    return instance;
}

void Logger::setLogLevel(LogLevel level)
{
    m_level = level;
}

void Logger::debug(const std::string &message)
{
    if ((int)m_level > (int)LogLevel::Debug) {
        return;
    }
    std::stringstream stream;
    stream << "\033[35mDEBUG\033[0m "
        << message
        << "\n";
    std::cerr << stream.str();
}

void Logger::info(const std::string &message)
{
    if ((int)m_level > (int)LogLevel::Info) {
        return;
    }
    std::stringstream stream;
    stream << "\033[34mINFO\033[0m "
        << message
        << "\n";
    std::cerr << stream.str();
}

void Logger::warning(const std::string &message)
{
    if ((int)m_level > (int)LogLevel::Warn) {
        return;
    }
    std::stringstream stream;
    stream << "\033[33mWARN\033[0m "
        << message
        << "\n";
    std::cerr << stream.str();
}

void Logger::error(const std::string &message)
{
    if ((int)m_level > (int)LogLevel::Error) {
        return;
    }
    std::stringstream stream;
    stream << "\033[31mERROR\033[0m "
        << message
        << "\n";
    std::cerr << stream.str();
}

}
