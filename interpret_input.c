#include "shell.h"

void interpret_input(char **input, char **action) {
	if (strcmp(input[0], "exit") == 0)
		exit(EXIT_SUCCESS);
    *action = input[0];
}
