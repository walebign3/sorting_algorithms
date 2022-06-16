#include "main.h"
/**
 *signal_handler- it keeps track is interactive mode
 *@m: the signal number
 *Return: nothing
 */

void signal_handler(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "~$ ", 3);
}

/**
 * main - super simple shell
 * @argc: passed argument count
 * @argv: array of passed argument
 *
 * Return: Always 0.
 */
int main (int __attribute__((__unused__)) argc, char **argv)
{
	char **args;
        char *lnptr = NULL;
        size_t n = 0;
        ssize_t lnsize;
        int int_mode;

	signal(SIGINT, signal_handler);
	do {
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
	} while (1);
	if (lnsize < 0 && int_mode == 1)
		write(STDERR_FILENO, "\n", 1);
	free(lnptr);
	return (0);
}
