#include "shell.h"

/**
 * print - prints a string
 * @c: string to print
 */
void print(char *c)
{
	write(STDOUT_FILENO, c, _strlen(c));
}

/**
 * get_signal - handle signal
 * @sig: signal
 * Return: nothing
 */
void get_signal(int sig)
{
	if (sig == SIGINT)
	{
		print("\n($) ");
	}
}

/**
 * print_error - prints error message
 * @cmd: array of command
 * @sms: error message to print out
 */
void print_error(char **cmd, char *sms)
{
	print(_getenv("_"));
	print(": 1: ");
	print(cmd[0]);
	print(": ");
	print(sms);
}
