#include "shell.h"

/**
 * parse_input - extract the action and args of the inputed command
 * @input: user input command
 *
 * Return: an array of broken down command
 */

char **parse_input(char *input)
{
	const int MAX_TOKENS = 64;
	const int MAX_TOKEN_LENGTH = 256;

	char **tokens = malloc(MAX_TOKENS * sizeof(char *));
	char *token = strtok(input, " \t\n");
	int i = 0;

	while (token != NULL && i < MAX_TOKENS - 1)
	{
		tokens[i] = malloc(MAX_TOKEN_LENGTH * sizeof(char));
		strncpy(tokens[i], token, MAX_TOKEN_LENGTH - 1);
		i++;
		token = strtok(NULL, " \t\n");
	}

	tokens[i] = NULL;
	return (tokens);
}
