#include "shell.h"

/**
 * _strcmp - compares two string
 * @str1: string one
 * @str2: string two
 * Return: 0 if string 1 and 2 are the same
 * number < 0 string 2 is bigger
 * number > 0 string one is bigger
 */

int _strcmp(char *str1, char *str2)
{
	int i = 0, rn =0;

	while (rn == 0)
	{
		if ((*(str1 + i) == '\0') && (*(str2 + i) == '\0'))
			break;
		rn = *(str1 + i) - *(str2 + i);
		i++;
	}
	return (rn);
}
