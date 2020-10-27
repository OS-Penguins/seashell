#include "commands.h"

#include <iostream>
#include <string>

namespace seashell {

void help(const std::string &) {
    std::cout << "List of available commands: \n"

                 "ls - displays files in directory\n"
                 "pwd - print working directory\n"
                 "cd <directory> - changes current directory to <directory>\n"
                 "mkdir/rmdir <directory> - creates or deletes <directory>\n"
                 "cp - copy a file\n"
                 "Talari - :)"
              << std::endl;
}
} // namespace seashell
