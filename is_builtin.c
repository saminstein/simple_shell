#include "shell.h"

/**
 * handle_builtin - function that match a command 
 * with its corresponding builtin function
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
