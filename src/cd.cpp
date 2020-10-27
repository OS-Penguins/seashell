#include "commands.h"
#include <sys/stat.h>
#include <sys/types.h>

#include <cctype>
#include <iostream>
#include <unistd.h>

void seashell::cd(const std::string & input) {
    const auto end_of_cd = input.find('d');

    auto start_path = end_of_cd + 1;
    while (isspace(input[start_path])) start_path++;

    auto end_path = input.find_last_not_of(" \t\n\r\v");

    auto directory = input.substr(start_path, end_path + 1 - start_path);

    if (chdir(directory.c_str())) perror("cd");
}
