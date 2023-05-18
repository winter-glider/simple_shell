#include "shell.h"

/**
  *interpret_input - interprets input
  *@input: input to be interpreted
  *Return: nothing
  */
void interpret_input(char **input)
{
	char **env;
	size_t len;

	if (_strcmp(input[0], "exit") == 0)
		exit(EXIT_SUCCESS);

	else if (_strcmp(input[0], "env") == 0)
	{
		for (env = environ; *env != NULL; env++)
		{
			len = _strlen(*env);
			write(1, *env, len);
			write(1, "\n", 1);
		}
	}
}
