#include "commands.h"
#include <sys/stat.h>
#include <sys/types.h>

#include <cctype>
#include <iostream>
#include <unistd.h>
// sub-function made to differ the mkdir() functions
static void sub1(const std::string & input) {
    if (rmdir(input.c_str()) == -1) {
        std::cout << input << std::endl;
        perror("rmdir");
    }
}

// command for mkdir
void seashell::rmdir(const std::string & input) {
    std::string foldername;
    for (auto i = input.find('i') + 2; i < input.size(); i++) {
        if (auto character = input.at(i); not isspace(character)) {
            foldername += character;
        } else if (not foldername.empty()) {
            sub1(foldername);
            foldername.clear();
        }
    }
    if (not foldername.empty()) { sub1(foldername); }
}
