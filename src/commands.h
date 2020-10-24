#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>

namespace seashell {
    void ls(const std::string &);
    void mkdir(const std::string&);
    void pwd(const std::string &);
    // Exec is special
    bool exec(const std::string &);
}

#endif
