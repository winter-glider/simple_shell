#include "shell.h"

void interpret_input(char **input) {
	if (strcmp(input[0], "exit") == 0)
		exit(EXIT_SUCCESS);
}
