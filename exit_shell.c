#include "shell.h"

/**
 * exit_shell - function to exit from a shell
 * @cmd: array of command
 * @status: status of the shell
 * Return: nothing
 */
void exit_shell(char **cmd, int status)
{
	if (cmd[1] != NULL)
	{
		status = _atoi(cmd[1]);
	}
	else
	{
		free(cmd);
		exit(status);
	}
}

/*
int exit_shell(char **cmd)
{
	if (cmd[1] != NULL)
	{
		exit(atoi(cmd[1]));
	}
	else
	{
		return (0);
	}
}
*/
