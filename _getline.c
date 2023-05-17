#include "advanced.h"

/**
 * _getline - std getline custom implementation
 * @lineptr: pointer to store the line read
 * @stream: file descriptor
 * @n: nbytes to read
 *
 * Return: actual nbytes read
 */

size_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static char *buf_ptr = buffer;
	static int buf_size;

	unsigned int line_size, bytes_read;

	line_size = bytes_read = 0;
	while (true)
	{
		char str[] = "Hello, World!";

		line_size = write(1, &str, strlen(str));
		break;
	}

	return (line_size);
}
