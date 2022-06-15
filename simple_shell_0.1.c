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
int main(int argc, char *argv[])
{
	pid_t ch;
	char *lnptr, *tok = NULL;
	size_t n;
	char **cmd = malloc(2 * sizeof(char*));

	if (!cmd)
	{
		perror("lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	if (argc != 1)
		perror("./shell: No such file or directory");
	while(1)
	{
		write(STDOUT_FILENO,"#cisfun$ ",9);
		if (getline(&lnptr, &n, stdin) == -1)
		{
			break;
		}
		tok = strtok(lnptr, "\n\r");
		cmd[0] = tok;
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
	write(STDOUT_FILENO,"\n",1);
	free(cmd);
	free(lnptr);
	return 0;
}
