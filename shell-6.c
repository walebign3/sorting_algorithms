#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

char *read_line(void);
/**
 * read_line - read a character until new line
 *
 * Return: line of character
 */
char *read_line(void)
{
	int n = 0;
	char c;
	char *buf = malloc(sizeof(char) * 64);

	while(read(STDIN_FILENO, &c, 1) >= 0)
	{
		if (c == EOF || c == '\n')
		{
			buf[n] = '\0';
			return buf;
		}
		else
			buf[n] = c;
		n++;
	}
	printf("%s", buf);
	return buf;
}
/**
 * main - super simple shell
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
        pid_t ch;
        char *tok, *lnptr;
        size_t i;
        char **cmd = malloc(64 * sizeof(char*));

        if (!cmd)
        {
                perror("lsh: allocation error\n");
                exit(EXIT_FAILURE);
        }
        if (argc != 1)
                perror("./shell: No such file or directory");
        while(1)
        {
                write(STDOUT_FILENO,"#cisfun$ ",10);
		lnptr = read_line();
                tok = strtok(lnptr, " \t\n\r");
                for (i = 0; i < 64 && tok != NULL; i++)
                {
                        cmd[i] = tok;
                        tok = strtok(NULL, " \n\t\r");
                }
                cmd[i] = NULL;
                ch = fork();
                if (ch == 0)
                {
                        if (execve(cmd[0], cmd, NULL))
                        {
                                perror(argv[0]);
                                exit(EXIT_FAILURE);
                        }
                }
                if (ch > 0)
                wait(NULL);
        }
        write(STDOUT_FILENO,"\n",1);
        free(cmd);
        free(lnptr);
        return 0;
}
