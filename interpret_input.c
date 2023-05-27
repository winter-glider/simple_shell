#include "shell.h"

/**
  *interpret_input - interprets input
  *@input: input to be interpreted
  *Return: nothing
  */
void interpret_input(char **input)
{
	char **env;
	int exit_code;

	if (strcmp(input[0], "exit") == 0)
	{
		if (input[1] != NULL)
		{
			if (is_valid_number(input[1]))
			{
				exit_code = atoi(input[1]);
				cleanup_memory(input);
				exit(exit_code);
			}
			else
			{
				write(2, "./hsh: 1: exit: Illegal number: ", 32);
				write(2, input[1], strlen(input[1]));
				write(2, "\n", 1);
				cleanup_memory(input);
				exit(2);
			}
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
/**
  *is_valid_number - checks numbers
  *@str: the string
  *Return: valid numbers
  */
bool is_valid_number(const char *str)
{
	if (str == NULL || *str == '\0')
		return (false);

	if (*str == '+' || *str == '-')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}

	return (true);
}

