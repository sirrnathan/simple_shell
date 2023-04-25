#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * main - Simple shell program
 * @argc: The number of arguments
 * @argv: An array of arguments
 * @envp: An array of environment variables
 *
 * Return: Always 0
 */
int main(int argc, char **argv, char **envp)
{
	char buffer[BUFFER_SIZE];
	pid_t pid;
	int status;

	while (1)
	{
		/* Display prompt and wait for user input */
		printf("$ ");
		fflush(stdout);
		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			break;
		}

		/* Remove trailing newline */
		buffer[strcspn(buffer, "\n")] = '\0';

		/* Fork a new process to execute the command */
		pid = fork();
		if (pid < 0)
		{
			fprintf(stderr, "Error: failed to fork\n");
			exit(1);
		}
		else if (pid == 0)
		{
			/* Child process: execute the command */
			if (execlp(buffer, buffer, (char *) NULL) < 0)
			{
				fprintf(stderr, "Error: command not found\n");
				exit(1);
			}
		}
		else
		{
			/* Parent process: wait for the child to exit */
			waitpid(pid, &status, 0);
		}
	}

	return (0);
}

