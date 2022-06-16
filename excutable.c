#include "main.h"

/**
 * execute_fun - split command arguments
 * @args: pointer to command arguments
 * @argv: pointer to pointer arguments
 *
 * Return: line of pointer.
 */
int execute_fun(char **args, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror(argv[0]);
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
	return 1;
}
