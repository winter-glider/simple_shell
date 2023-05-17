#include "shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */

int main(int argc, char *argv[]) {
    if (argc > 1)
	{
        /* Non-interactive mode */
		run_non_interactive(argv[1]);
	}
	else
	{
		/* Interactive mode */
		run_interactive();
	}
	return 0;
}
