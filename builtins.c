#include "shell.h"

/**
 * my_cd - function to change a directory
 * @cmd: tokenized command
 * Return: 1 on failure and 0 on success
 */
int my_cd(char **cmd)
{
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
	{
		chdir(_getenv("HOME"));
		return (0);
	}
	else
	{
		if (chdir(cmd[1]) == 0)
			return (1);
	}
	if (_strcmp(cmd[1], "-") == 0)
	{
		chdir(_getenv("OLDPWD"));
		return (0);
	}
	if (chdir(cmd[1]) == -1)
	{
		perror("cd");
		return (-1);
	}
	else if (chdir(cmd[1]) == 0)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", _getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}

	return (0);
}

/**
 * my_env - prints the environment
 * @cmd: command array
 * Return: 0 on success
 */
int my_env(__attribute__((unused)) char **cmd)
{
	int i = 0;
	int count;

	while (environ[i] != NULL)
	{
		count = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], count);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
