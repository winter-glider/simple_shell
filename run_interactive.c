#include "shell.h"

/**
 * run_interactive - run interactive mode
 */

void run_interactive(void)
{
	char *user_input;

	while (true)
	{
		write(STDOUT_FILENO, "$ ", strlen("$ "));
		user_input = read_input();
		if (user_input == NULL)
			break;

		process_line(user_input);
		free(user_input);
	}
}
