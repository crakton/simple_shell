#include "shell.h"

/**
 * _putchar - Write a charater print to stdout
 * c: character to write;
 * Return: 1 on success, -1 on error, errno is set appropriately
 */

int _putchar(char c)
{
	return (write(1,&c, 1));
}
