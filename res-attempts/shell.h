#ifndef __SHELL_H
#define __SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* Use __environ if environ is not available */
extern char **environ;

/* Function prototypes */
void print_prompt(void);
char **parse_input(char *input);
int execute_command(char **args);
void free_memory(char *input, char **args);
char *read_input(FILE *file);
void set_env_variable(char **args);
void unset_env_variable(char **args);
void change_directory(char **args);
void print_aliases(void);
void set_alias(char **args);
char *replace_variables(char *input);
char *remove_comments(char *input);
#endif /* __SHELL_H */
