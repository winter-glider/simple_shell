#include "shell.h"

/**
 * read_input - get user input
 *
 * Return: input string
 */

char *read_input(void)
{
	char *input = NULL;
	size_t bufsize = 0;
	ssize_t len = _getline(&input, &bufsize, stdin);

	if (len == -1)
	{
		free(input);
		return (NULL);
	}
	input[len - 1] = '\0'; /* Remove newline character */
	return (input);
}
