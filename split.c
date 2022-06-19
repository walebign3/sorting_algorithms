#include "main.h"

/**
 * tokens_fun - split command arguments
 * @line: pointer to command arguments
 *
 * Return: line of pointer.
 */
char **tokens_fun(char *lnptr)
{
	char **tokens = malloc(64 * sizeof(char*));

	if (!tokens)
	{
		write(STDOUT_FILENO,"mem alloc error\n",16);
		exit(EXIT_FAILURE);
	}

	tokens[0] = strtok(lnptr, "\n\r");
	tokens[1] = NULL;

	return tokens;
}

