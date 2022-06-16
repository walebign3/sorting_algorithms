#ifndef _HEADER_H_
#define _HEADER_H_

#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 64
#define DELIM " \t\r\n\a"
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
char **tokens_fun(char *lnptr);
int execute_fun(char **tok, char **argv);
void loop_fun(char **argv);
void handle_signal(int m);

#endif /* _HEADER_H_ */
