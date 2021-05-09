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
    static Logger &GetInstance();
    void SetLogLevel(LogLevel level);
    void Debug(const std::string &message);
    void Info(const std::string &message);
    void Warning(const std::string &message);
    void Error(const std::string &message);

private:
    Logger() {};
    LogLevel level_{LogLevel::Debug};

public:
    Logger(Logger const&) = delete;
    void operator=(Logger const&) = delete;
};

}
