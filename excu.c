#include "main.h"

/**
 * execute_fun - split command arguments
 * @tok: pointer to command arguments
 * @argv: file name
 * Return: line of pointer.
 */
void execute_fun(char **tok, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(tok[0], tok, NULL) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork() error");
	}
	else
	{
		wait(&status);
	}
}

