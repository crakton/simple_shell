#include "shell.h"

/**
 * err_code - Dispay the error codes
 * @n: number to display
 * Return: a number as error
 */

int err_code(int n)
{
	unsigned int code;
	int i = 0;

	if (n < 0)
	{
		code = -n;
		i = i + _putchar('-');
	}
	else
		code = n;
	if (code / 10 != '\0')
		i = i + err_code(code / 10);
	i =  i + _putchar(code % 10 + '0');
	return (i);
}
