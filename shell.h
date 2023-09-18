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
 * @name: name of the command builtin (cd, exit, env)
 * @function: function that executes the command
 */

typedef struct builtin_c
{
	char *name;
	int (*function)(char **cmd);
} builtin_t;

extern char **environ;
char *_getenv(char *name);

/** PRINTS **/
void print(char *c);
void prompt(void);
void print_error(char **cmd, char *sms);


/** GETLINE **/
ssize_t _getline(char **user_input, size_t *n, int status);

/** TOKENIZER **/
char **tokenize(char *user_input);

/** STRINGS **/
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _atoi(char *s);
char *_strdup(char *str);
void _memcpy(void *newptr, const void *ptr, size_t size);
void *_realloc(void *ptr, size_t size);


int is_builtin(char **cmd);


/** BUILTINs **/
int my_cd(char **cmd);

#endif
