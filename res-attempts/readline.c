#include "shell.h"

/**
 * read_input - Read a line of input from stdin
 * @file: The file stream to read from
 * Return: The input read from stdin
 */
char *read_input(FILE *file)
{
	char *input = NULL;
	size_t bufsize = 0;

	if (getline(&input, &bufsize, file) == -1)
	{
		free(input);
		return NULL;
	}
	return input;
}
