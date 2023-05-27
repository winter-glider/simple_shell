#include "shell.h"

/**
  *interpret_input - interprets input
  *@input: input to be interpreted
  *Return: nothing
  */
void interpret_input(char **input)
{
	char **env;
	int temp;

	if (strcmp(input[0], "exit") == 0)
	{
		if (input[1] != NULL)
		{
			temp = atoi(input[1]);
			cleanup_memory(input);
			exit(temp);
		}
		else
		{
			cleanup_memory(input);
			exit(EXIT_SUCCESS);
		}
	}

	else if (strcmp(input[0], "env") == 0)
	{
		for (env = environ; *env != NULL; env++)
			printf("%s\n", *env);
	}
}
