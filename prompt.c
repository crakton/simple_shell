#include "shell.h"

/**
 * _prompt - return prompts to standard output
 *
 * @propmt: string input pointer
 * @size: length of the string
 */

int _prompt(const char *prompt, unsigned int size)
{
	int i = 0;

	if (isatty(STDIN_FILENO))
	{
		i = write(1, prompt, size);
		if (i == -1)
			return (-1);
	}
	return (0);
}
