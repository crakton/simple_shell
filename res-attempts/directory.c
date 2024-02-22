#include "shell.h"


/**
 * change_directory - Change the current directory
 * @args: An array of pointers to tokens representing the command and its arguments
 */
void change_directory(char **args)
{
	if (args[1] == NULL)
	{
		chdir(getenv("HOME"));
	}
	else if (chdir(args[1]) != 0) 
	{
		perror("change_directory");
	}
}
