#include "shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	char *args[MAX_NUM_ARGS + 1];
	int num_args;

	char *line = NULL;
	size_t len = 0;

	printf("$ ");
	fflush(stdout);

	getline(&line, &len, stdin);

	/* remove trailing newline */
	line[strlen(line) - 1] = '\0';

	/* split command into arguments */
	num_args = split_command(line, args);

	printf("Num: %d - %s\n",num_args, args[0]);
	return (0);
}
