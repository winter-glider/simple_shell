#include "shell.h"

/**
 * run_non_interactive - execute a file with commands
 * @filename: file with commands
 */

void run_non_interactive(char *filename)
{
	char buffer[BUFFER_SIZE], *ptr, *end;
	ssize_t read_size;

	int file = open(filename, O_RDONLY);
	if (file == -1)
	{
		perror("open");
		return;
	}

	while ((read_size = read(file, buffer, sizeof(buffer) - 1)) != -1)
	{
		if (read_size == 0)
			break; /* reached end of file */

		buffer[read_size] = '\0'; /* null-terminate */
		ptr = buffer;

		while ((end = strchr(ptr, '\n')) != NULL)
		{
			*end = '\0';
			process_line(ptr);
			ptr = end + 1;
		}

		if (ptr < buffer + read_size)
			process_line(ptr);
	}
	close(file);
}
