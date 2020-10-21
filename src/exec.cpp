#include "commands.h"
#include <sys/wait.h> // waitpid

#include <cctype>   // isspace
#include <unistd.h> // execvp
#include <vector>

namespace seashell {

// Returns true if exec succeeds
bool exec(const std::string & command) {

    std::vector<std::string> arguments{""};

    enum quote_type_t : char {
        none = false, single_quotes = '\'', double_quotes = '"'
    } quote_type = none;

    bool escaped = false; // true if last character is a '\'

    for (char c : command) {
        if (c == '\\') escaped = true;
        else if (escaped) {
            // Appended the correct version onto the end of the arguments
            switch (c) {
            case '"':
            case '\'':
            default:
                arguments.back() += c;
                break;
            case 'n':
                arguments.back() += '\n';
                break;
            case 'b':
                arguments.back() += '\b';
                break;
            }
            escaped = false;
        } else if (quote_type != none) {
            switch (c) {
            case '\\':
                escaped = true;
                break;
            case '"':
            case '\'':
                if (c == quote_type) {
                    quote_type = none;
                    break;
                } else
                    [[fallthrough]];
            default:
                arguments.back() += c;
                break;
            }
        } else if (isspace(c)) {
            if (not arguments.back().empty()) arguments.emplace_back();
        } else if (c == '\'' or c == '"')
            quote_type = static_cast<quote_type_t>(c);
        else {
            arguments.back() += c;
        }
    }

    auto pid = fork();
    if (pid == 0) {
        // In child process
        std::vector<char *> argv;
        for (auto & argument : arguments) argv.push_back(argument.data());
        argv.push_back(nullptr);

        if (execvp(argv[0], argv.data()) == -1) {
            perror("exec");
            exit(-1);
        }
        // Should never get to here, as exec replaces our code with the invoked program

    } else if (pid < 0) {
        // Error handling
        perror("fork");
        return false;
    }

    int status;
    if (const auto ret = waitpid(pid, &status, 0); ret == pid) return true;
    else if (ret == -1) {
        return false;
    }

    return true;
}
} // namespace seashell
