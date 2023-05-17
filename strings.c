#include "shell.h"

/**
  *_strlen - returns the length of a string
  *@s: string
  *Return: the length
  */
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;

	}

	return (count);

}
/**
  *_strncmp - compares strings
  *@str1: string one
  *@str2: second string
  *@n: number of bytes in string
  *Return: comparison
  */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;
	int difference;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			difference = (int)(unsigned char)str1[i] - (int)(unsigned char)str2[i];
			return (difference);
		}
		if (str1[i] == '\0' || str2[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
/**
  *_strdup - duplicates strings
  *@str: the string
  *Return: duplicate string
  */

char *_strdup(const char *str)
{
	if (str == NULL)
		return (NULL);

	int length = 0, i;

	while (str[length] != '\0')
		length++;

	char *duplicate = malloc(sizeof(char) * (length + 1));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		duplicate[i] = str[i];

	duplicate[length] = '\0';

	return (duplicate);
}

/**
  *_strcpy - copies strings
  *@dest: destination
  *@src: source string
  *Return: copied string
  */

char *_strcpy(char *dest, const char *src)
{
	size_t i;
	char *original_destination;

	original_destination = dest;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (original_destination);
}

