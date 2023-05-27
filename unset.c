#include "shell.h"

/**
  *shell_unsetenv - unsets the environment
  *@name: name of env
  *Return: the unsetenv
  */
int shell_unsetenv(const char *name)
{
	size_t name_len = strlen(name);
	int var_index = -1, i;

	if (name == NULL)
	{
		fprintf(stderr, "Unsetenv: Missing arguments\n");
		return (-1);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			var_index = i;
			break;
		}
	}
	if (var_index == -1)
	{
		fprintf(stderr, "unsetenv: '%s' does not exist", name);
		return (-1);
	}

	free(environ[var_index]);

	for (i = var_index; environ[i] != NULL; i++)
		environ[i] = environ[i + 1];

	return (0);
}

