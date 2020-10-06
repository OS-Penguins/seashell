#include <stdio.h>  //puts
#include <string.h> //strncmp

struct command_entry {
    const char * name;
    void (*cmd)(const char *);
};

typedef struct command_entry command_t;

static command_t commands[] = {{NULL, NULL}};

#define INPUT_BUFFER_SIZE 1024

int main() {

    puts("Welcome to SeaShell\nPress Ctrl-C or Ctrl-D to exit");

    char input[INPUT_BUFFER_SIZE];

    while (fgets(input, INPUT_BUFFER_SIZE, stdin) != NULL) {

        // iter is the iterator which walks over the list of available commands
        command_t * iter = commands;
        while (iter->name != NULL) {
            if (strncmp(iter->name, input, strlen(iter->name)) == 0) {
                iter->cmd(input);
                break;
            }

            iter++;
        }

        // We reach the end of the array without finding a command
        if (iter->name == NULL) { puts("Unrecognized command"); }
    }
}
