#include "shell.h"

/**
 * _getline - Reads input from stream
 * @user_input: buffer to store user input
 * @n: size of user_input
 * @status: exit status
 * Return: -1 on failure & 0 on success
 */
ssize_t _getline(char **user_input, size_t *n, int status)
{
	ssize_t readed;

	if (isatty(STDIN_FILENO) == 1)
		prompt();

	readed = getline(user_input, n, stdin);
	if (readed == -1)
	{
		free(*user_input);
		if (isatty(STDIN_FILENO))
			print("\n");
		exit(status);
	}
	return (readed);
}
