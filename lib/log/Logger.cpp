/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Logger
*/

#include <iostream>
#include <sstream>
#include <ctime>
#include "Logger.hpp"

namespace lib::log {

Logger::Logger() :
    out_(&std::cerr)
{

}

Logger &Logger::Get()
{
    static Logger instance;
    return instance;
}

void Logger::SetLogLevel(Level value)
{
    level_ = value;
}

void Logger::SetOutput(std::ostream &output)
{
    out_ = &output;
}

void Logger::Debug(const std::string &source, const std::string &message)
{
    std::stringstream stream;
    stream
        << GetTimeString()
        << " \033[35mDBG\033[0m \033[1m"
        << source
        << "\033[0m: "
        << message
        << "\n";
    (*out_) << stream.str();
}

void Logger::Info(const std::string &source, const std::string &message)
{
    std::stringstream stream;
    stream
        << GetTimeString()
        << " \033[34mINF\033[0m \033[1m"
        << source
        << "\033[0m: "
        << message
        << "\n";
    (*out_) << stream.str();
}

void Logger::Warning(const std::string &source, const std::string &message)
{
    std::stringstream stream;
    stream
        << GetTimeString()
        << " \033[33mWRN\033[0m \033[1m"
        << source
        << "\033[0m: "
        << message
        << "\n";
    (*out_) << stream.str();
}

void Logger::Error(const std::string &source, const std::string &message)
{
    std::stringstream stream;
    stream
        << GetTimeString()
        << " \033[31mERR\033[0m \033[1m"
        << source
        << "\033[0m: "
        << message
        << "\n";
    (*out_) << stream.str();
}

void Logger::Exception(const std::exception &exception)
{
    std::stringstream stream;
    stream
        << GetTimeString()
        << " \033[31mEXC\033[0m "
        << exception.what()
        << "\n";
    (*out_) << stream.str();
}

std::string Logger::GetTimeString()
{
    const std::time_t now = std::time(nullptr);
    const std::tm calendar_time = *std::localtime(std::addressof(now));
    return "\033[30m"
        + std::to_string(calendar_time.tm_hour)
        + ":"
        + std::to_string(calendar_time.tm_min)
        + "\033[0m";
}

}
