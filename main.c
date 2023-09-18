#include "shell.h"

/**
 * main - entry for the unix clone
 * Return: 1 or 0
 */
int main(void)
{
	char *user_input;
	char **cmd;
	int status = 0;
	size_t n;

	signal(SIGINT, get_signal);
	while (1)
	{
		user_input = NULL;
		_getline(&user_input, &n, status);
		cmd = tokenize(user_input);
		if (cmd[0] == NULL)
		{
			free(user_input);
			free(cmd);
			continue;
		}
		if (_strcmp(cmd[0], "exit") == 0)
		{
			free(user_input);
			exit_shell(cmd, status);
			free(cmd);
			continue;
		}
		else if (is_builtin(cmd) == 0)
		{
			status = handle_builtin(cmd);
			free(cmd);
			free(user_input);
			continue;
		}
		status = execute_cmd(cmd);
		if (status == 1)
			print_error(cmd, "not found\n");
		free(cmd);
		free(user_input);
		user_input = NULL;
	}
	return (0);
}
