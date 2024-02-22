#include "shell.h"

/**
 * remove_comments - Remove comments from the input string
 * @input: The input string
 * Return: The input string with comments removed
 */
char *remove_comments(char *input)
{
	char *comment_pos = strchr(input, '#');
	if (comment_pos != NULL)
		*comment_pos = '\0';
	return input;
}
