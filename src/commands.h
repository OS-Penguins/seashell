#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>

namespace seashell {
    void ls(const std::string &);
    void mkdir(const std::string&);
    void copy(const std::string &);
    void rmdir(const std::string&);
    void cd(const std::string&);
    void help(const std::string&);
    void exit(const std::string&);

    // Exec is special
    bool exec(const std::string &);
}

#endif
