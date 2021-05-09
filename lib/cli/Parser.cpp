/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Parser
*/

#include <iostream>
#include "Parser.hpp"

namespace lib::cli {

Parser::Parser(int argc, char const **argv) :
    m_argc(std::size_t(argc)),
    m_argv(argv),
    m_flags(),
    m_options(),
    m_container(nullptr)
{
}

void Parser::setNonOptionsStore(std::vector<std::string> &container)
{
    m_container = &container;
}

void Parser::addOption(const std::string &longOption,
    const std::string &shortOption,
    OptionHandler &&handler)
{
    m_options.emplace_back(OptionData{longOption, shortOption, handler, false});
}

void Parser::addFlag(const std::string &longOption,
    const std::string &shortOption,
    FlagHandler &&handler)
{
    m_flags.emplace_back(FlagData{longOption, shortOption, handler, false});
}

void Parser::addRequiredOption(const std::string &longOption,
    const std::string &shortOption,
    OptionHandler &&handler)
{
    m_options.emplace_back(OptionData{longOption, shortOption, handler, true});
}

void Parser::addRequiredFlag(const std::string &longOption,
    const std::string &shortOption,
    FlagHandler &&handler)
{
    m_flags.emplace_back(FlagData{longOption, shortOption, handler, true});
}

bool Parser::parse() noexcept
{
    try {
        for (std::size_t i = 0; i < m_argc; ++i) {
            if (i + 1 < m_argc && searchMatchingOption(m_argv[i], m_argv[i + 1])) {
                continue;
            } else if (!searchMatchingFlag(m_argv[i]) && m_container != nullptr) {
                m_container->emplace_back(m_argv[i]);
            }
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return checkRequired();
}

bool Parser::searchMatchingOption(const std::string &value, const std::string &nextValue)
{
    for (auto &option : m_options) {
        if (value == option.shortOption || value == option.longOption) {
            if (!option.handler(nextValue)) {
                throw std::exception();
            }
            option.required = false;
            return true;
        }
    }
    return false;
}

bool Parser::searchMatchingFlag(const std::string &value)
{
    for (auto &flag : m_flags) {
        if (value == flag.shortOption || value == flag.longOption) {
            flag.handler();
            flag.required = false;
            return true;
        }
    }
    return false;
}

bool Parser::checkRequired()
{
    for (const auto& option : m_options) {
        if (option.required) {
            return false;
        }
    }
    for (const auto& flag : m_flags) {
        if (flag.required) {
            return false;
        }
    }
    return true;
}

}
