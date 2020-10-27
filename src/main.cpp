#include "commands.h"

#include <functional>
#include <iostream> // cin
#include <map>
#include <string> // getline

using command = std::function<void(const std::string &)>;

static const std::map<std::string, command> commands{
    {"ls", seashell::ls},     {"mkdir", seashell::mkdir}, {"cp", seashell::copy},
    {"pwd", seashell::pwd},   {"rmdir", seashell::rmdir}, {"cd", seashell::cd},
    {"exit", seashell::exit}, {"help", seashell::help},
};

static std::string first_word(const std::string & input) {
    static constexpr auto * whitespace = " \t\n\v\f";

    const auto start_of_first_word = input.find_first_not_of(whitespace);

    // Only whitespace characters were found -> return ""
    if (start_of_first_word == std::string::npos) return "";

    const auto end_of_first_word = input.find_first_of(whitespace, start_of_first_word);

    // The entire buffer is one word -> return the entire buffer
    return end_of_first_word == std::string::npos
               ? input
               : input.substr(start_of_first_word, end_of_first_word - start_of_first_word);
}

int main() {

    puts("Welcome to SeaShell\nPress Ctrl-C or Ctrl-D to exit");

    std::string buffer;

    while (std::getline(std::cin, buffer)) {
        const auto command_to_run = first_word(buffer);
        if (const auto cmd = commands.find(command_to_run); cmd != commands.end()) {
            // Found a builtin command
            cmd->second(buffer);
        } else if (not seashell::exec(buffer)) {
            // Could not find a command
            std::cerr << "Unrecognized command: " << command_to_run << '\n';
        }
    }
}