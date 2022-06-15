#include "main.h"

/**
 * main - super simple shell
 * @argc: passed argument count
 * @argv: array of passed argument
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char **argv)
{
	loop_fun(argv);
	return EXIT_SUCCESS;
}
