#include "shell.h"

/**
 * cmds - users inputs for executing
 * @entry: input
 * @args: input array pointer
 * Return: size of the array
 */

int cmds(char *entry, char **args)
{
	int i = 0;
	char *opts, *aux = entry, *cmd;

	cmd = strtok(entry, "\n\t\r ");
	args[i] = cmd;
	while (aux != NULL)
	{
		++i;
		opts = strtok(NULL, "\n\t\r "); /* forevery iteration extract the command */
		aux = opts;
		args[i] = opts; /* store the next option (i) to the array pointer */
	}
	args[i] = NULL; /*last index of array tto zero */
	return (i); /* return last index as length of the args */
}
