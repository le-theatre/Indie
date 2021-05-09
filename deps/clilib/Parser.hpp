/*
** EPITECH PROJECT, 2021
** indie
** File description:
** Parser
*/

#pragma once

#include <string>
#include <functional>
#include <tuple>
#include <vector>

namespace clilib {

class Parser {
public:
    using FlagHandler = std::function<void()>;
    using OptionHandler = std::function<bool(const std::string &)>;

    Parser(int argc, char const **argv);

    /// All arguments that were not identified as flags will be pushed into
    /// container.
    void setNonOptionsStore(std::vector<std::string> &container);

    /// Register an command line option. Upon encoutering it, handler will be
    /// called with the next argument.
    /// If one of the handler for a given option returns false, a call to
    /// parse will fail.
    void addOption(const std::string &longOption,
        const std::string &shortOption,
        OptionHandler &&handler);

    /// Register an command line flag. Upon encoutering it, handler will be
    /// called.
    void addFlag(const std::string &longOption,
        const std::string &shortOption,
        FlagHandler &&handler);

    /// Same as addOption though a call to parse will fail if this option is
    /// never encountered.
    void addRequiredOption(const std::string &longOption,
        const std::string &shortOption,
        OptionHandler &&handler);

    /// Same as addFlag though a call to parse will fail if this flag is never
    /// encountered.
    void addRequiredFlag(const std::string &longOption,
        const std::string &shortOption,
        FlagHandler &&handler);

    /// Parse will return false if a required option or flag is missing, if one
    /// of the option handlers returned false or if an exception was thrown
    /// inside of a handler.
    bool parse() noexcept;

private:
    template <typename THandler> struct Data {
        std::string shortOption;
        std::string longOption;
        THandler handler;
        bool required;
    };

    using FlagData = Data<FlagHandler>;
    using OptionData = Data<OptionHandler>;

    bool searchMatchingOption(const std::string &value, const std::string &nextValue);
    bool searchMatchingFlag(const std::string &value);
    bool checkRequired();

    std::size_t m_argc;
    char const **m_argv;
    std::vector<FlagData> m_flags;
    std::vector<OptionData> m_options;
    std::vector<std::string> *m_container;
};

}
