#include "shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	/* Non-interactive mode */
	if (argc > 1)
	{
		write(1, argv[0], strlen(argv[0]));
		run_non_interactive(argv[1]);
		return (EXIT_SUCCESS);
	}
	else
	{
		/* Interactive mode */
		if (!isatty(STDIN_FILENO))
		{
			run_interactive(argv[0]);
			return (EXIT_SUCCESS);
		}
		else
		{
			write(STDOUT_FILENO, "($)", strlen("($)"));
			run_interactive(argv[0]);
		}
	}
	return (0);
}
