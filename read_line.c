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

	if (getline(&cmd, &n, stdin) == -1)
	{
		perror("read line error");
		exit(EXIT_FAILURE);
	}
	return cmd;
}
