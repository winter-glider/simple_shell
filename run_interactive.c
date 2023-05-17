#include "shell.h"

/**
 * run_interactive - run interactive mode
 */

void run_interactive(void)
{
	char **parsed_input;
	char *user_input;

	while (true)
	{
		write(STDOUT_FILENO, "$ ", strlen("$ "));
		user_input = read_input();
		if (user_input == NULL)
			break;

		parsed_input = parse_input(user_input);

		interpret_input(parsed_input);
		execute_action(parsed_input);
		cleanup_memory(parsed_input);
		free(user_input);
	}
}
