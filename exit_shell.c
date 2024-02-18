#include "shell.h"

/**
 * exit_shell - function to exit from a shell
 * @cmd: array of command
 * @status: status of the shell
 * Return: nothing
 */
void exit_shell(char **cmd, int status)
{
	if (cmd[1])
	{
		status = _atoi(cmd[1]);
	}
	free(cmd);
	exit(status);
}
