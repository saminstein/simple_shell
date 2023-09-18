#ifndef _SHELL
#define _SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>

#define DELIM " \t\r\n\a"
#define BUFSIZE 1024

/**
 * struct builtin_c - builtin struct for command
 * @name: name of the command builtin (cd, exit, e
 * nv)
 * @function: function that executes the command
 */
typedef struct builtin_c
{
	char *name;
	int (*function)(char **cmd);
} builtin_t;

extern char **environ;
char *_getenv(char *name);

void prompt(void);
void get_signal(int sig);



/** GETLINE **/
ssize_t _getline(char **user_input, size_t *n, int status);

/** TOKENIZER **/
char **tokenize(char *user_input);

/** STRINGS **/
int _strcmp(char *s1, char *s2);
int _strlen(char *s);


void *_realloc(void *ptr, size_t size);


int handle_builtin(char **cmd);

#endif

