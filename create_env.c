#include "shell.h"

/**
  *create_env_entry - creates environ entry
  *@name: name of env
  *@value: value of env
  *Return: env_entry
  */
char *create_env_entry(const char *name, const char *value)
{
	size_t name_len = strlen(name);
	size_t value_len = strlen(value);
	char *entry = malloc(name_len + value_len + 2);

	if (entry == NULL)
		return (NULL);

	sprintf(entry, "%s=%s", name, value);

	return (entry);

}
