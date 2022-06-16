#include "main.h"

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

	int_mode = isatty(STDIN_FILENO);
	if (int_mode == 1)
	{
		write(STDOUT_FILENO, "~$ ", 3);
	}
	if (getline(&cmd, &n, stdin) == -1)
	{
		free(cmd);
		return (NULL);
	}
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
	char **args = NULL;
        char *lnptr = NULL;
	int status;
	(void)argc;

	do {
		errno = 0;
		lnptr = read_line();
		if (lnptr == NULL && errno == 0)
			return (0);
		if (lnptr)
		{
			args = tokens_fun(lnptr);
			if (!args)
				free(lnptr);

			status = execute_fun(args, argv);

			free(args);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(status);
		}
		free(lnptr);
	} while (1);
	return (0);
}
