#include "shell.h"

/**
 * execute_cmd - execute command
 * @cmd: array of tokenized command
 * Return: 1 on failure, 0 on success
 */
int execute_cmd(char **cmd)
{
	char *command = NULL, *new_command = NULL;
	pid_t child = -1;
	int status = 0;
	int cmd_len;

	if (cmd == NULL || cmd[0] == NULL)
		return (1);

	command = cmd[0];
	new_command = find_path(command);
	if (new_command == NULL)
		return (1);

	if (cmd && access(new_command, X_OK) == 0)
	{
		child = fork();
		if (child == -1)
			print_error(cmd, "error in fork\n");
		else if (child == 0)
		{
			if (execve(new_command, cmd, environ) == -1)
				print_error(cmd, "error in excecve\n");
		}
		else
		{
			if (waitpid(child, &status, 0) == -1)
			{
				print_error(cmd, "error in waitpid\n");
			}
		}
		cmd_len = _strlen(new_command);
		if (_strncmp(new_command, command, cmd_len) != 0)
			free(new_command);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		return (status);
	}
	free(new_command);
	return (1);
}
