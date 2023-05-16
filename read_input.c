#include "shell.h"

char *read_input() {
    char *input = NULL;
    size_t bufsize = 0;
    ssize_t len = getline(&input, &bufsize, stdin);
    if (len == -1) {
        free(input);
        return NULL;
    }
    input[len - 1] = '\0'; // Remove newline character
    return input;
}
