#include "commands.h"
#include <sys/stat.h>
#include <sys/types.h>

#include <iostream>
void sub1(const std::string & input);

void seashell::mkdir(const std::string & input) {
    sub1(input.substr(input.find(" "), input.length()));
}

// sub-function made to differ the mkdir() functions
void sub1(const std::string & input) {
    std::cout << input << std::endl;
    mkdir(input.c_str(), S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
}
