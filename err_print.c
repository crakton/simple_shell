#include "shell.h"

/**
 * err_print - for invalid commands print 
 * an error message
 * @args: input args pointer
 * @counter: shell execution counter
 * Return: exit status
 */

int err_print(char **args, int counter)
{
	char *mode1 = "hsh"; /* interactive mode */
	char *mode2 = "./hsh"; /*non-interactive mode */

	if (isatty(STDIN_FILENO))
		write(2, mode1,3);
	else
		write(2, mode2, 5);
	write(2, ":(", 2);
	err_code(counter);
	write(2, ") ", 2);
	write(2, args[0], strlen(args[0]));
	write(2, ":: not found", 12);
	write(2,"\n", 2);
	return (127);
}
