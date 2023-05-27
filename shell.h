#ifndef SHELL_H
#define SHELL_H

extern char **environ;
/* global constants */
#define BUFFER_SIZE 1024

#include "advanced.h"
/* libs includes */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/* Shell core functions */
void interpret_input(char **parsed_input);
char **parse_input(char *input);
char *read_input(void);
void execute_action(char **args, char *prog_name);
void run_non_interactive(char *filename);
void run_interactive(char *filename);

/* Helper functions */
char *get_builtin_path(char *command);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int shell_setenv(const char *name, const char *value, int overwrite);
int shell_unsetenv(const char *name);
bool is_valid_number(const char *str);
char *create_env_entry(const char *name, const char *value);
void process_line(char *line, char *prog_name);
void cleanup_memory(char **parsed_input);
void fprint(char *input, int fd, char *replacement);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strstr(char *haystack, char *needle);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);

#endif /* SHELL_H */
