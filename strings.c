#include "shell.h"

/**
 * _strcmp - compares two string
 * @s1: pointer to the first character
 * @s2: pointer to the second character
 * Return: integer value
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

/**
 * _strlen - return the length of a string
 * @s: the input string
 * Return: length of s
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strncmp - compares at most the first n bytes stri
 * ng 1 and string 2
 * @s1: The first string
 * @s2: The second string
 * @n: length
 * Return: integer
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	if (i < n)
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * *_strcpy - copies a str from src to dest
 * @src: source of the str
 * @dest: destination of the str
 * Return: copied str
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * *_strcat - concatenates two strings
 * @src: pointer to the first string
 * @dest: pointer to the second string
 * Return: concatenated strings
 */

char *_strcat(char *dest, char *src)
{
	int len = _strlen(dest);
	int i = 0;

	while (dest[len] != '\0')
		i++;
	while (src[i] != '\0')
	{
		dest[len] = src[i];
		i++;
		len++;
	}
	dest[len] = '\0';

	return (dest);
}
