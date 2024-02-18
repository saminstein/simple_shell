#include "shell.h"

/**
 * _getenv - Gets an environment variable
 * @name: The variable to get
 * Return: The content of the environment variable
 * or NULL if variable does not exist
 */
char *_getenv(char *name)
{
	int i;
	int len = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return (&environ[i][len + 1]);
		}
	}
	return (NULL);
}
