#include "shell.h"

/**
 * handle_builtin - function that match a comm
 * and with its corresponding builtin function
 * @cmd: The command to match
 * Return: -1 on failure & 0 on success
 */
int handle_builtin(char **cmd)
{
	int i;
	builtin_t funcs[] = {
		{"cd", my_cd},
		{"env", my_env},
		{NULL, NULL}
	};

	for (i = 0; funcs[i].name != NULL; i++)
	{
		if (_strcmp(cmd[0], funcs[i].name) == 0)
		{
			return (funcs[i].function(cmd));
		}
	}
	return (-1);
}

/**
 * is_builtin - checks if command is builtin
 * @cmd: tokenize command to check
 * Return: -1 on failure & 0 on success
 */

int is_builtin(char **cmd)
{
	int i;
	builtin_t funcs[] = {
		{"cd", NULL},
		{"env", NULL},
		{NULL, NULL}
	};

	if (cmd == NULL || cmd[0] == NULL)
		return (-1);

	for (i = 0; funcs[i].name != NULL; i++)
	{
		if (_strcmp(cmd[0], funcs[i].name) == 0)
		{
			return (0);
		}
	}
	return (-1);
}
