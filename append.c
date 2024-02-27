#include "shell.h"

/**
 * append - Join the input paths to global env PATH
 * @dir: directory to be appended
 * @cmd: command to concat
 * Return: Buffer to the concatenated path
 */

char *append(char *dir, char *cmd)
{
	int i,j = 0, len1, len2;
	char *cmd_path = NULL;
	
	if (cmd_path == NULL || cmd == NULL)
		return (NULL);
	len1 = _strlen(dir);
	len2 = _strlen(cmd);
	cmd_path = malloc(len1 + len2 + 2);
	if (cmd_path == NULL)
		return (NULL);
	for (i = 0; dir[i] != '\0'; i++)
	{
		cmd_path[i] = dir[i];
	}
	if (dir[i - 1] != '/')
	{
		cmd_path[i] = '/';
		i++;
	}
	while (cmd[j] != '\0')
	{
		cmd_path[i + j] = cmd[j];
		j++;
	}
	cmd_path[i + j] = '\0';
	return (cmd_path);
}
