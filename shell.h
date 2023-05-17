#ifndef SHELL_H
#define SHELL_H

extern char **environ;

/* global constants */
#define BUFFER_SIZE 1024

/* libs includes */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/* Shell core functions */
void interpret_input(char **parsed_input);
char **parse_input(char *input);
char *read_input(void);
void execute_action(char **args);
void run_non_interactive(char *filename);
void run_interactive(void);

/* Helper functions */
char *get_builtin_path(char *command);
void process_line(char *line);
void cleanup_memory(char **parsed_input);

#endif /* SHELL_H */
