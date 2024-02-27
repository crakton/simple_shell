#include "shell.h"

/**
 * _getenv -  global variables
 * Return: pointer to variable, NULL means failed
 */

char *_getenv(char *global_var)
{
	int i = 0;
	const char __SETTER__[] = "=";
	char *env_token, *envdup, *env_token_dup;

	if (global_var != NULL)
	{
		if (environ == NULL)
			return (NULL);
		envdup = _strdup(environ[i]);
		while (envdup != NULL)
		{
			env_token = strtok(envdup, __SETTER__);
			if (_strcmp(env_token, global_var) == 0)
			{
				env_token = strtok(NULL, __SETTER__);
				env_token_dup = _strdup(env_token);
				free(envdup);
				return (env_token_dup);
			}
			i++;
			free(envdup);
			envdup = _strdup(environ[i]);
		}
	}
	return (NULL);
}
