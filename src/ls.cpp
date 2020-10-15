#include "commands.h"

#include <algorithm> // sort
#include <cstdio>    // perror
#include <dirent.h>  // opendir
#include <string>
#include <vector>

namespace seashell {

// Just prints out the files in the current directory
// No permissions, filetypes, or anything fancy
void ls(const std::string &) {

    // Open the current directory
    auto * dirp = opendir(".");

    // On an error, print and return
    if (dirp == nullptr) {
        perror("ls");
        return;
    }

    std::vector<std::string> files{};

    // NOTE: if readdir has an error, there is no way to see that currently.
    for (const auto * entry = readdir(dirp); entry != nullptr; entry = readdir(dirp)) {
        // The '.' and '..' paths should not be printed (currently.)
        if (entry->d_name[0] != '.') files.emplace_back(entry->d_name);
    }

    // We are done with the dirent iterator.
    closedir(dirp);

    // Simple ASCII sort
    std::sort(std::begin(files), std::end(files));

    // Print the filenames.
    for (const auto & file : files) puts(file.c_str());
}

} // namespace seashell
