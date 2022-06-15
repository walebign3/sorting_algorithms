#include "main.h"

/**
 * loop_fun - loop function
 * @argv: pointer to pointer argument
 *
 * Return: Always 0.
 */
void loop_fun(char **argv)
{
	char *lnptr;
	char **tok;
	int status;

	do {
		write(STDOUT_FILENO,"#cisfun$ ",10);
		lnptr = read_line();
		tok = tokens_fun(lnptr);
		status = execute_fun(tok,argv);

		free(lnptr);
		free(tok);
	} while (status);
}
