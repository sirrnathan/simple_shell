#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>

/**
 * struct info_s - struct containing relevant info for shell
 * @readfd: file descriptor to read from
 * @args: array of arguments passed to shell
 * @env: environment variables
 * @argv: name of the shell
 * @line: input from user
 * @buffer: buffer to store input
 */
typedef struct info_s
{
	int readfd;
	char **args;
	char **env;
	char *argv;
	char *line;
	char *buffer;
} info_t;

int is_shell_interactive(info_t *info);
int is_character_lim(char d, char *lim);
int is_character_d(int d);
int string_to_integer(char *s);

#endif /* SHELL_H */ 

