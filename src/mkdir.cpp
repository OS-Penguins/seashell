#include "commands.h"
#include <sys/stat.h>
#include <sys/types.h>

#include <cctype>
#include <iostream>
void sub1(const std::string & input);

void seashell::mkdir(const std::string & input) {
    std::string foldername;
    for (auto i = input.find("r") + 1; i < input.size(); i++) {
        auto character = input.at(i);
        if (isspace(character)) {
            if (not foldername.empty()) {
                sub1(foldername);
                foldername.clear();
            }
        } else {
            foldername += character;
        }
    }
    if (not foldername.empty()) { sub1(foldername); }
}

// sub-function made to differ the mkdir() functions
void sub1(const std::string & input) {
    if (mkdir(input.c_str(), S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == -1)
        perror("mkdir");
}
