#include "shell.h"

/**
 * set_env_variable - Set or modify an environment variable
 * @args: An array of pointers to tokens representing the command and its arguments
 */
void set_env_variable(char **args)
{
	if (args[1] != NULL && args[2] != NULL)
	{
		if (setenv(args[1], args[2], 1) != 0)
		{
			perror("set_env_variable");
		}
	}
	else
	{
			fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
	}

}

/**
 * unset_env_variable - Unset an environment variable
 * @args: An array of pointers to tokens representing the command and its arguments
 */
void unset_env_variable(char **args)
{
	if (args[1] !=  NULL)
	{
		if (unsetenv(args[1]) != 0)
		{
			perror("unset_env_variable");
		}
	}
	else
		{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
	}
}
