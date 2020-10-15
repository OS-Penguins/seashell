#include "commands.h"

#include <cstdio>   // perror
#include <dirent.h> // opendir
#include <string>

namespace seashell {

// Just prints out the files in the current directory
// No permissions, filetypes, or anything fancy
void ls(const std::string &) {
    auto * dirp = opendir(".");

    if (dirp == nullptr) {
        perror("ls");
        return;
    }

    while (dirp != nullptr) {
        const auto * entry = readdir(dirp);
        puts(entry->d_name);
    }

    closedir(dirp);
}

} // namespace seashell
