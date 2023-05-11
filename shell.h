#ifndef SHELL_H
#define SHELL_H

/* global constants */
#define MAX_CMD_LEN 100
#define MAX_NUM_ARGS 10
#define BUFFER_SIZE 1024

/* libs includes */
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int split_command(char* command, char** args);

#endif /* SHELL_H */
