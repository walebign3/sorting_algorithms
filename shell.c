#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
/**
 * main - super simple shell
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	pid_t ch;
	char *lnptr = NULL;
	size_t n;
	ssize_t lnsize;
	char **cmd = malloc(64 * sizeof(char*));

	if (!cmd)
	{
		perror("lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	if (argc < 1)
		return (-1);
	while(lnsize != EOF)
	{
		write(STDOUT_FILENO,"#cisfun$ ",10);
		lnsize = getline(&lnptr, &n, stdin);
		if (lnsize < 1)
			break;
		if (lnptr[lnsize - 1] == '\n')
			lnptr[lnsize-1] = '\0';
		cmd[0] = lnptr;
		cmd[1] = NULL;
		ch = fork();
		if (ch == 0)
		{
			if (execve(cmd[0], cmd, NULL))
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		if (ch > 0)
			wait(NULL);
	}
	free(cmd);
	free(lnptr);
	return 0;
}
