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
	char *line = NULL;
	size_t len = 0;

	printf("$ ");
	fflush(stdout);

	getline(&line, &len, stdin);
	return (0);
}
