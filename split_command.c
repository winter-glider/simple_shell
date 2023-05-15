#include "shell.h"

int split_command(char* command, char** args)
{
	int num_args = 0;

	args[num_args] = strtok(command, " ");
	while (args[num_args] != NULL)
	{
		num_args++;
		args[num_args] = strtok(NULL, " ");
	}

	return (num_args);
}
