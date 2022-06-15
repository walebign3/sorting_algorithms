#ifndef _HEADER_H_
#define _HEADER_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 64
#define DELIM " \t\r\n\a"

void loop_fun(char **argv);
char *read_line(void);
char **tokens_fun(char *lnptr);
int execute_fun(char **args, char **argv);

#endif /* _HEADER_H_ */
