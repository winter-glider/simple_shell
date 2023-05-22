#include "shell.h"

/**
 * process_line - process single line of input
 * @line: single line from input
 *@prog_name: the name of the file
 */

void process_line(char *line, char *prog_name)
{
	char **parsed_input = parse_input(line);

	if (parsed_input != NULL && parsed_input[0] != NULL)
	{
		interpret_input(parsed_input);
		execute_action(parsed_input, prog_name);
	}
	cleanup_memory(parsed_input);
}
