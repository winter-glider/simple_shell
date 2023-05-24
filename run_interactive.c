#include "shell.h"

/**
 * run_interactive - run interactive mode
 *@filename: the filename
 */

void run_interactive(char *filename)
{
	char *user_input;

	while (true)
	{
	/*	write(STDOUT_FILENO, "($) ", strlen("($) "));*/
		user_input = read_input();
		if (user_input == NULL)
			break;

		process_line(user_input, filename);
write(STDOUT_FILENO, "($) ", _strlen("($) "));
		free(user_input);
	}
}
