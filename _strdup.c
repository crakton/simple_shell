#include "shell.h"

/**
 * _strdup - string duplicate
 * @str - string duplicate pointer 
 * Return: the pointer of the duplicate string
 */

char *_strdup(char *str)
{
	unsigned int i, len;
	char *dup;

	if (str == NULL)
		return (NULL);
	for (len = 0; str[len] != '\0'; len++)
		;
	dup = (char *) malloc(sizeof(char) * (len +1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
	{
		dup[i] = str[i];
	}
	return (dup);
}
