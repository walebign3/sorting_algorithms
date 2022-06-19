#include "main.h"

/**
 * main - super simple shell
 * @argc: passed argument count
 * @argv: array of passed argument
 *
 * Return: Always 0.
 */
int main (int argc, char **argv)
{
	char **args;
	char *lnptr = NULL;
	size_t n = 0;
	ssize_t lnsize;
	int int_mode;

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
		args = tokens_fun(lnptr);
		if (args == NULL || *args == NULL || **args == '\0')
			continue;
		execute_fun(args, argv);

		free(args);
	}
	if (lnsize < 0 && int_mode == 1)
		write(STDERR_FILENO, "\n", 1);
	free(lnptr);
	return (0);
}

