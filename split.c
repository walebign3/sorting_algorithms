#include "main.h"

/**
 * tokens_fun - split command arguments
 * @linptr: pointer to command arguments
 *
 * Return: line of pointer.
 */
char **tokens_fun(char *lnptr)
{
	char **tokens = malloc(2 * sizeof(char*));

	if (!tokens)
	{
		write(STDOUT_FILENO,"mem alloc error\n",16);
		exit(EXIT_FAILURE);
	}

	tokens[0] = lnptr;
	tokens[1] = NULL;

	return tokens;
}

