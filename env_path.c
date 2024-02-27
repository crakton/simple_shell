#include "shell.h"

/**
 * env_path - check if initial argument is
 * a valid command
 * @args: entries
 * Return: 0 on success, -1 not found
 */

int env_path(char **args)
{
	char *global_path = NULL;
	char *global_dup = NULL;
	char *dir_path = NULL;
	char *cmd_path = NULL;
	char *test_cur_path[121];
	int status = -1, i = 0;

	global_path = _getenv("PATH");
	if (global_path == NULL)
		return (-1);
	global_dup = _strdup(global_path);
	dir_path = strtok(global_dup, ":");
	if (dir_path == NULL)
		return (-1);
	free(global_path);
	while (status == -1 && dir_path != NULL)
	{
		cmd_path = append(dir_path, args[0]);
		test_cur_path[i] = cmd_path;
		status = verify(test_cur_path[i]);
		dir_path = strtok(NULL, ":");
		i++;
	}
	i--;
	free(global_dup);
	free_grid(test_cur_path, i);
	if (status == 0)
	{
		args[0] = test_cur_path[i];
		return (status);
	}
	else
	{
		free(test_cur_path[i]);
		return (-1);
	}
}
