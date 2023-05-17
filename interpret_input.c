#include "shell.h"

/**
  *interpret_input - interprets input
  *@input: input to be interpreted
  *Return: nothing
  */
void interpret_input(char **input)
{
	if (strcmp(input[0], "exit") == 0)
		exit(EXIT_SUCCESS);
}
