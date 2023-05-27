#include "shell.h"

/**
  * get_builtin_path - gets the builtin path
  * @command: command in the path
  * Return: path
  */

char *get_builtin_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy, *token, *command_path;

	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		command_path = malloc(strlen(token) + strlen(command) + 2);
		sprintf(command_path, "%s/%s", token, command);
		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (command_path);
		}
		free(command_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	if (access(command, F_OK) != -1)
		return (strdup(command));
	else
		return (NULL);
}
