#include <cstdio> // puts
#include <functional>
#include <iostream> // cin
#include <map>
#include <string> // getline

using command = std::function<void(const std::string &)>;

static const std::map<std::string, command> commands{};

static std::string first_word(const std::string & input) {
    static constexpr auto * whitespace = " \t\n\v\f";

    const auto start_of_first_word = input.find_first_not_of(whitespace);

    // Only whitespace characters were found -> return ""
    if (start_of_first_word == std::string::npos) return "";

    const auto end_of_first_word = input.find_first_of(whitespace, start_of_first_word);

    // The entire buffer is one word -> return the entire buffer
    return end_of_first_word == std::string::npos ? input : input.substr(end_of_first_word);
}

int main() {

    puts("Welcome to SeaShell\nPress Ctrl-C or Ctrl-D to exit");

    std::string buffer;

    while (std::getline(std::cin, buffer)) {

        if (const auto cmd = commands.find(first_word(buffer)); cmd != commands.end()) {
            // Found a builtin command
            cmd->second(buffer);
        } else {
            // Could not find a command
            puts("Unrecognized command.");
        }
    }
}
