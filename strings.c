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
	char *duplicate;
	int length = 0, i;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
		length++;

	duplicate = malloc(sizeof(char) * (length + 1));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		duplicate[i] = str[i];

	duplicate[length] = '\0';

	return (duplicate);
}

/**
 * _strstr - look for occurance of given string
 * @haystack: source string
 * @needle: lookup string
 *
 * Return: return a pointer to the beginning of the located substring
 */

char *_strstr(char *haystack, char *needle)
{
	const char *h, *n;

	if (*needle == '\0')
		return (haystack);

	while (*haystack != '\0')
	{
		h = haystack;
		n = needle;

		while (*n != '\0' && *h == *n)
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return (haystack); /* match found */
		haystack++;
	}
	return (NULL);
}
/**
  *_strcmp - compares two strings.
  *@s1: string 1
  *@s2: string 2
  *Return: 0 if strings are equal
  *else return < 0 if s1 char lower than s2 in ASCII
  *else return > 0 if s1 char higher than s2 in ASCII
  */
int _strcmp(char *s1, char *s2)
{
	if (strcmp(s1, s2) > 0)
	{
		return (strcmp(s1, s2));
	}
	else if (strcmp(s1, s2) < 0)
	{
		return (strcmp(s1, s2));

	}
	else
		return (0);


}
