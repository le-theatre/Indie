/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Logger
*/

#pragma once

#include <string>
#include <stdexcept>

namespace lib::log {

enum class Level {
    Debug = 0,
    Info = 1,
    Warn = 2,
    Error = 3,
    Exception = 4,
    None = 4
};

class Logger {
public:
    static Logger &Get();
    void SetOutput(std::ostream &stream);
    void SetLogLevel(Level level);
    void Debug(const std::string &source, const std::string &message);
    void Info(const std::string &source, const std::string &message);
    void Warning(const std::string &source, const std::string &message);
    void Error(const std::string &source, const std::string &message);
    void Exception(const std::exception &exception);

private:
    std::string GetTimeString();

    std::ostream *out_;
    Logger();
    Level level_{Level::Debug};

public:
    Logger(Logger const&) = delete;
    void operator=(Logger const&) = delete;
};

}
