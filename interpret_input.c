#include "shell.h"

/**
  *interpret_input - interprets input
  *@input: input to be interpreted
  *Return: nothing
  */
void interpret_input(char **input)
{
	char **env;

	if (strcmp(input[0], "exit") == 0)
		exit(EXIT_SUCCESS);

	else if (strcmp(input[0], "env") == 0)
	{
		for (env = environ; *env != NULL; env++)
			fprint("%s\n", STDOUT_FILENO, *env);
	}
}
