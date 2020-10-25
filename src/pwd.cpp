#include "commands.h"

#include <unistd.h>

// pwd command (does not need to free malloc)
void seashell::pwd(const std::string &) {
    auto * dir_name = get_current_dir_name();
    puts(dir_name);
}
