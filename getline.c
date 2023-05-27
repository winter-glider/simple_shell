#include "shell.h"

/**
  *_getline - Implementation of getline
  *@lineptr: arg 1
  *@n: length of line
  *@stream: file stream
  *Return: line
  */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = *n, i = 0;
	char *buffer = *lineptr, *new_buffer;
	int count;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (buffer == NULL)
	{
		bufsize = 128;
		buffer = malloc(bufsize);
		if (buffer == NULL)
			return (-1);
	}
	while (1)
	{
		count = fgetc(stream);
		if (count == EOF)
			break;
		if (i >= bufsize - 1)
		{
			bufsize += 128;
			new_buffer = realloc(buffer, bufsize);
			if (new_buffer == NULL)
				return (-1);
			buffer = new_buffer;
		}
		buffer[i++] = count;
		if (count == '\n')
			break;
	}
	buffer[i] = '\0';
	*lineptr = buffer;
	*n = bufsize;

	return ((ssize_t)i);
}
