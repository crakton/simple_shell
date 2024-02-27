#include "shell.h"

/**
 * _strlen - length of the string character *str
 * @str: length of the found string
 * Return: string's length
 */

int _strlen(const char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}
