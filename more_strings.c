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
/**REMEMBER TO FREE S AFTER USE!!**/
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
 * _memcpy - copy a block of memory from one locatio
 * n to another
 * @newptr: pointer to starting address of destinatio
 * memory
 * @ptr: pointer to the starting address of the sourc
 * e memory
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
	int num = 0;

	while (*s != '\0')
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		else if (*s == '+')
		{
			;
		}
		else if (*s >= '0' && *s <= '9')
		{
			num = num * 10 + (*s - '0');
		}
		else if (num != 0)
		{
			break;
		}
		s++;
	}
	return (sign * num);
}
