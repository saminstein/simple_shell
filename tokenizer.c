#include "shell.h"

/**
 * tokenize - splits users comamnd into tokens
 * @user_input: pointer to the user command
 * Return: array of pointer to a string
 */
char **tokenize(char *user_input)
{
	char *token;
	char **commands;
	int i = 0;
	int bufsize = BUFSIZE;

	if (user_input[0] == ' ' && user_input[_strlen(user_input)] == ' ')
	{
		exit(0);
	}
	if (user_input == NULL)
	{
		return (NULL);
	}

	commands = malloc(sizeof(char *) * bufsize);
	if (commands == NULL)
	{
		free(commands);
		perror("hsh");
		return (NULL);
	}

	token = strtok(user_input, DELIM);
	while (token != NULL)
	{
		commands[i] = token;
		token = strtok(NULL, DELIM);
		i++;
	}
	commands[i] = NULL;

	return (commands);
}
