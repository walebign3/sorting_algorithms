#include "main.h"

/**
 * tokens_fun - split command arguments
 * @line: pointer to command arguments
 *
 * Return: line of pointer.
 */
char **tokens_fun(char *lnptr)
{
	int bufsize = BUFSIZE, i = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens)
	{
		write(STDOUT_FILENO,"mem alloc error\n",16);
		exit(EXIT_FAILURE);
	}
	token = strtok(lnptr, DELIM);
	tokens[i] = NULL;
	return tokens;
}

