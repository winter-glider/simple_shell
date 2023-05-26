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
    if (name == NULL || value == NULL)
    {
        return (-1);
    }

    if (setenv(name, value, overwrite) != 0)
    {
        return (-1);
    }

    return (0);
}
#include "shell.h"

/**
 * shell_unsetenv - Unset an environment variable
 * @name: Name of the environment variable to unset
 * Return: 0 on success, -1 on failure
 */
int shell_unsetenv(const char *name)
{
    if (name == NULL)
    {
        return (-1);
    }

    if (unsetenv(name) != 0)
    {
        return (-1);
    }

    return (0);
}

