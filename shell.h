#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <time.h>

extern char **environ;

/* Function prototypes */
int _putchar(char c);
int _strcmp(char *str1, char *str2);
int _strlen(const char *str);
int _prompt(const char *prompt, unsigned int size);
char *_strdup(char *str);
char *_getenv(char *global_var);
int env_path(char **args);
int builtins(char **args, int exit_stat);
char *append(char *dir, char *cmd);
void free_grid(char **grid, int height);
int err_code(int n);
void memory(char *memo);
int cmds(char *entry, char **args);
int err_print(char **args, int counter);
int verify(char *pathname);
int exec(char **args);

#endif
