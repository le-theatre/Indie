/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Logger
*/

#pragma once

#include <string>

namespace server {

enum class LogLevel {
    Debug = 0,
    Info = 1,
    Warn = 2,
    Error = 3,
    None = 4
};

class Logger {
public:
    static Logger &getInstance();

    void setLogLevel(LogLevel level);

    void debug(const std::string &message);

    void info(const std::string &message);

    void warning(const std::string &message);

    void error(const std::string &message);

private:
    Logger() {}

    LogLevel m_level{LogLevel::Debug};

public:
    Logger(Logger const&) = delete;

    void operator=(Logger const&) = delete;
};

}
