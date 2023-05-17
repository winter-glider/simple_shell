#include "shell.h"

/**
  *_strtok - tokenizes a string
  *@str: string to be tokenized
  *@delim: used to determine where to tokenize
  *Return: pointer to tokenized str or NULL
  */
char *_strtok(char *str, const char *delim)
{
	static char *last;
	char *tokens;
	const char *d;
	int end = 0;

	if (str != NULL)
	{
		last = str;
	}
	if (last == NULL)
	{
		return (NULL);
	}

	tokens = last;

	while (*last && !end)
	{
		for (d = delim; *d; d++)
		{
			if (*last == *d)
			{
				*last++ = '\0';
				end = 1;
				break;
			}
		}
		if (!end)
		{
			last++;
		}
	}
	if (tokens == last)
	{
		return (NULL);
	}
	else
		return (tokens);
}
