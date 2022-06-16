#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - super simple shell
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	pid_t ch;
	char *tok, *lnptr = NULL;
	size_t i, n;
	int int_mode;
	char **cmd = malloc(64 * sizeof(char*));

	if (!cmd)
	{
		perror("lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	if (argc != 1)
		perror("./shell: No such file or directory");
	while(int_mode)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		}
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
			}
		}
		if (ch > 0)
		wait(NULL);
	}
	return 0;
}
