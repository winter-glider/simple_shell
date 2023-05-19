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
	char *result;
	size_t prefix_len, replacement_len, suffix_len;

	if (match == NULL)
	{
		write(fd, input, _strlen(input));
		return;
	}

	prefix_len = match - input;
	replacement_len = replacement != NULL ? _strlen(replacement) : 0;
	suffix_len = _strlen(match + 2);

	result = malloc(prefix_len + replacement_len + suffix_len + 1);

	/* Copy the prefix before "%s" */
	strncpy(result, input, prefix_len);
	result[prefix_len] = '\0';

	if (replacement != NULL)
		strcat(result, replacement);
	strcat(result, match + 2);

	write(fd, result, _strlen(result));
	free(result);
}
