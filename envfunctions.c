#include "shell.h"

/**
 * shell_setenv - Set or modify an environment variable
 * @name: Name of the environment variable
 * @value: Value to be assigned to the variable
 * @overwrite: Flag indicating whether to overwrite existing value
 * Return: 0 on success, -1 on failure
 */
int shell_setenv(const char *name, const char *value, int overwrite)
{
	size_t n_len = strlen(name);
	char *new_entry;
	int i, var_index = -1;

	if (name == NULL || value == NULL)
	{
		fprintf(stderr, "setenv: Missing arguments\n");
		return (-1);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, n_len == 0 && environ[i][n_len] == '='))
		{
			var_index = i;
			break;
		}
	}
	if (var_index != -1 && !overwrite)
	{
		fprintf(stderr, "setenv: '%s' already exists\n", name);
		return (-1);
	}
	new_entry = create_env_entry(name, value);
	if (new_entry == NULL)
		return (-1);
	if (var_index != -1)
		free(environ[var_index]);

	environ[var_index] = new_entry;

	return (0);
}

