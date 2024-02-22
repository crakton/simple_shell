#include "shell.h"

/**
 * parse_input - Parse the input string into tokens
 * @input: The input string to parse
 * Return: An array of pointers to tokens
 */

char **parse_input(char *input)
{
	const char *delimeters = " \t\r\n\a";
	char **tokens = malloc(sizeof(char *) * 64);
	char *token, *saveptr;
	int i = 0;

	if (!tokens)
	{
		perror("parse_input");
		exit(EXIT_FAILURE);
	}

	for (token = strtok_r(input, delimeters, &saveptr); token; token = strtok_r(NULL, delimeters, &saveptr))
	{
		tokens[i++] = token;
	}
	tokens[i] = NULL;

	return tokens;

	return tokens;
}
