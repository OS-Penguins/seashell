#include "commands.h"
#include <sys/stat.h>
#include <sys/types.h>

#include <cctype>

// sub-function made to differ the mkdir() functions
static void sub1(const std::string & input) {
    if (mkdir(input.c_str(), S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == -1)
        perror("mkdir");
}

// command for mkdir
void seashell::mkdir(const std::string & input) {
    std::string foldername;
    for (auto i = input.find("r") + 1; i < input.size(); i++) {
        if (auto character = input.at(i); not isspace(character)) {
            foldername += character;
        } else if (not foldername.empty()) {
            sub1(foldername);
            foldername.clear();
        }
    }
    if (not foldername.empty()) { sub1(foldername); }
}
