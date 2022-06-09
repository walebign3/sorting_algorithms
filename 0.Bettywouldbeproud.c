#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char buffer[] = "This is a beautiful code";

	write(STDOUT_FILENO, buffer, 24);
	return (0);
}
