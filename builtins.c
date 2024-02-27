#include "shell.h"

/**
 * builtins - check if arguments are from 
 * unix shell command
 * @args: points to the arguments array pointers
 * @exit_stat: exist status
 * Return: 0 if it is a builtin command, -1 not a builtin command
 */

int builtins(char **args, int exit_stat)
{
	char *_builtins[2] = {
		"exit",
		"env"
	};
	int i = 0;

	while (i < 2)
	{
		if (_strcmp(args[0], _builtins[i]) == 0)
		break;
	i++;
	}
	if (i == 0)
	{
		if (_strcmp(_builtins[i], "env") == 0)
		{
			if (environ == NULL)
				return (0);
			write(1, environ, 1000);
		}
		if (_strcmp(_builtins[i], "exit") == 0)
		{
			free(args[0]);
			exit(exit_stat);
		}
		return (0);
	}
	return (-1);
}
