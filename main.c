#include "shell.h"
/**
 * main - entry file of the simple shell program
 * Return: 0 on success
 */
int main(void)
{
	ssize_t _b = 0;
	size_t _s = 0;
	char *e = NULL, *args[20];
	int i = 1, v = 0, ex = 0, _e = 0, b = 0;

	_prompt("$ ", 2);
	_b = getline(&e, &_s, stdin);
	while (_b != -1)
	{
		if (*e != '\n')
		{
			cmds(e, args);
			if (args[0] != NULL)
			{
				ex = verify(args[0]);
				if (ex != 0)
				{
					v = env_path(args);
					if (v == 0)
						_e = exec(args), free(*args);
					else
					{
						b = builtins(args, ex);
						if (b != 0)
							_e = err_print(args, i), free(e);
					}
				}
				else
					_e = exec(args), free(e);
			}
			else
				free(e);
		}
		else if (*e == '\n')
			free(e);
		e = NULL, i++;
		_prompt("$ ", 2), _b = getline(&e, &_s, stdin);
	}
	memory(e);
	return (_e);
}
