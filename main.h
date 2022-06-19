#ifndef _HEADER_H_
#define _HEADER_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

char **tokens_fun(char *lnptr);
void execute_fun(char **tok, char **argv);

#endif /* _HEADER_H_ */
