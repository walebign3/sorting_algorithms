#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void execute_fun(char **tok, char **argv);
char *read_line(void);
/**
 * execute_fun - split command arguments
 * @tok: pointer to command arguments
 *
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

/**
 * read_line - read commands
 *
 * Return: line of pointer.
 */
char *read_line(void)
{
	char *cmd = NULL;
	size_t n = 0;
	int int_mode;
	ssize_t lnsize;

	int_mode = isatty(STDIN_FILENO);
	if (int_mode == 1)
	{
		write(STDOUT_FILENO, "~$ ", 3);
	}
	lnsize = getline(&cmd, &n, stdin);
	if (lnsize == -1)
	{
		free(cmd);
		return (NULL);
	}
	if(cmd[lnsize -1] == '\n')
		cmd[lnsize -1] = '\0';
	return (cmd);
}

/**
 * main - super simple shell
 * @argc: passed argument count
 * @argv: array of passed argument
 *
 * Return: Always 0.
 */
int main (int argc, char **argv)
{
	char **args = malloc(2 * sizeof(char*));
	(void)argc;

	do {
		errno = 0;
		args[0] = read_line();
		if (args[0] == NULL && errno == 0)
			return (0);
		args[1] = NULL;
		execute_fun(args, argv);
	}
	while (1);
	return (0);
}
