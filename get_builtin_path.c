#include "shell.h"

extern char **environ;

char *get_builtin_path(char *command) {
    int i = 0;
    while (environ[i] != NULL) {
        if (strncmp(environ[i], "PATH=", 5) == 0) {
            char *path = environ[i] + 5; // Skip "PATH="
            char *path_copy = strdup(path);
            char *token = strtok(path_copy, ":");
            while (token != NULL) {
                char *command_path = malloc(strlen(token) + strlen(command) + 2); // +2 for '/' and null terminator
                sprintf(command_path, "%s/%s", token, command);
                if (access(command_path, X_OK) == 0) {
                    free(path_copy);
                    return command_path;
                }
                free(command_path);
                token = strtok(NULL, ":");
            }
            free(path_copy);
            break;
        }
        i++;
    }
    return NULL;
}
