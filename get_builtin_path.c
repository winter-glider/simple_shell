#include "shell.h"

/**
  *get_builtin_path - gets the builtin path
  *@command: command in the path
  *Return: path
  */

char *get_builtin_path(char *command)
{
	int i = 0;
	char *path, *path_copy, *token, *command_path;

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5; /* Skip "PATH="*/
			path_copy = _strdup(path);
			token = _strtok(path_copy, ":");
			while (token != NULL)
			{
				command_path = malloc(_strlen(token) + _strlen(command) + 2);
				sprintf(command_path, "%s/%s", token, command);
				if (access(command_path, X_OK) == 0)
				{
					free(path_copy);
					return (command_path);
				}
				free(command_path);
				token = _strtok(NULL, ":");
			}
			free(path_copy);
			break;
		}
		i++;
	}
	return (NULL);
}
