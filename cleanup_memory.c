#include "shell.h"

/**
 * cleanup_memory - frees the memory of parsed_input
 * @parsed_input: heap array
 */

void cleanup_memory(char **parsed_input)
{
	int i = 0;

	if (parsed_input == NULL)
		return;

	for (; parsed_input[i] != NULL; i++)
		free(parsed_input[i]);
	*parsed_input = NULL;
	free(parsed_input);
}
