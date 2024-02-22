#include "shell.h"

/**
 * set_alias - Define an alias
 * @args: An array of pointers to tokens representing the command and its arguments
 */

/* Function to set an alias */
void set_alias(char **args)
{
    if (args[1] == NULL || args[2] == NULL) {
        printf("Usage: alias [name[='value'] ...]\n");
        return;
    }
    
    printf("Setting alias: %s='%s'\n", args[1], args[2]);
}

void print_aliases(void)
{
    printf("Printing all aliases:\n");
}

