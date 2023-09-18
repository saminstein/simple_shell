#include "shell.h"

/**
 * find_path - function to find the full path of a
 * command
 * @command: tokenized the input
 * Return: full path of the command
 */
char *find_path(char *command)
{
	char *path, *path_copy, *path_token, *temp;
	int cmd_len, dir_len;

	path = _getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			cmd_len = _strlen(command);
			dir_len = _strlen(path_token);
			temp = malloc(cmd_len + dir_len + 2);
			if (temp == NULL)
				return (NULL);
			_strcpy(temp, path_token);
			_strcat(temp, "/");
			_strcat(temp, command);

			if (access(temp, F_OK) == 0)
			{
				free(path_copy);
				return (temp);
			}
			else
			{
				free(temp);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (access(command, F_OK) == 0)
			return (command);
	}
	return (NULL);
}
