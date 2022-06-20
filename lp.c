#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - super simple shell
 * @argc: passed argument count
 * @argv: array of passed argument
 *
 * Return: Always 0.
 */
int main (int argc, char **argv)
{
	char *lnptr = NULL;
	size_t n = 0;
	ssize_t lnsize;
	int int_mode;
	pid_t pid;
	int status;
	char *args[2];

	if (argc < 1)
		return (-1);
	while (1)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			write(STDOUT_FILENO, "~$ ", 3);
		}
		lnsize = getline(&lnptr, &n, stdin);
		if (lnsize < 0)
			break;
		if (lnptr[lnsize - 1] == '\n')
			lnptr[lnsize - 1] = '\0';
		args[0] = lnptr;
		args[1] = NULL;
		if (args == NULL || *args == NULL || **args == '\0')
			continue;
		pid = fork();
		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
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
	if (int_mode == 1)
		write(STDERR_FILENO, "\n", 1);
	free(lnptr);
	return (0);
}

