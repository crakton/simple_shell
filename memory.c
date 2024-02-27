#include "shell.h"

/**
 * memory - Clear the last execution from memo
 * @memo: memory input
 */

void memory(char *memo)
{
	if (isatty(STDIN_FILENO))
	{
		_putchar('\n');
		free(memo);
	}
	if (!isatty(STDIN_FILENO))
	{
		free(memo);
	}
}
