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
