#include "shell.h"

/**
 * process_line - process single line of input
 * @line: single line from input
 */

void process_line(char *line)
{
	char **parsed_input = parse_input(line);

	if (parsed_input != NULL && parsed_input[0] != NULL)
		execute_action(parsed_input);
	cleanup_memory(parsed_input);
}
