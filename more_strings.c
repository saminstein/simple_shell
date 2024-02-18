#include "shell.h"

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocate
 * d
 * @size: size of memory
 * Return: new pointer
 */
void *_realloc(void *ptr, size_t size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(size));

	if (size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	newptr = malloc(size);
	if (newptr == NULL)
		return (NULL);
	_memcpy(newptr, ptr, size);
	free(ptr);

	return (newptr);
}

/**
 * _strdup - duplicates a string
 * @str: The string to duplicate
 * Return: duplicated string
 */
char *_strdup(char *str)
{
	size_t str_len;
	char *newstr;

	str_len = _strlen(str) + 1;
	newstr = malloc(sizeof(char) * str_len);
	if (newstr == NULL)
		return (NULL);
	_memcpy(newstr, str, str_len);

	return (newstr);
}

/**
 * _memcpy - copy a block of memory from one locat
 * ion to another
 * @newptr: pointer to starting address of destina
 * tion memory
 * @ptr: pointer to the starting address of the so
 * urce memory
 * @size: size of new pointer
 * Return: nothing
 */
void _memcpy(void *newptr, const void *ptr, size_t size)
{
	char *char_oldptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i = 0;


	while (i < size)
	{
		char_newptr[i] = char_oldptr[i];
		i++;
	}
}

/**
 * _atoi - converts a string to an integer
 * @s: The string to be converted
 * Return: integer
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int n = 0;

	do {
		if (*s == '-')
		{
			sign *= -1;
		}
		else if (*s >= '0' &&  *s <= '9')
		{
			n = (n * 10) + (*s - '0');
		}
		else if (n > 0)
		{
			break;
		}
	} while (*s++);
	return (sign * n);
}
