#include "shell.h"

/**
 * fprint - replace %s with passed third arg
 * @input: input string
 * @fd: file descriptor
 * @replacement: replacement string
 *
 * Return: formated string
 */

void fprint(char *input, int fd, char *replacement)
{
	char *match = _strstr(input, "%s");
	char result[BUFFER_SIZE];
	size_t prefix_len;

	if (match == NULL)
	{
		write(fd, input, _strlen(input));
		return;
	}

	prefix_len = match - input;

	/* Copy the prefix before "%s" */
	strncpy(result, input, prefix_len);
	result[prefix_len] = '\0';

	strcat(result, replacement);
	strcat(result, match + 2);

	write(fd, result, _strlen(result));
}
