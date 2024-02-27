#include "shell.h"

/**
 * verify - validate if a file exist
 * @pathname: the file location
 * Return: 0 file exist, -1 on error
 */

int verify(char *pathname)
{
	int status;
	
	status = (open(pathname, O_RDONLY));
	if (status != -1)
	{
		close(status);
		return (0);
	}
	else
		return -1;
}
