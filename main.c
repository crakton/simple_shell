#include "shell.h"
/**
 * main - entry file of the simple shell program
 * Return: 0 on success
 */
int main(void)
{
	ssize_t _b = 0;
	size_t _s = 0;
	char *e = NULL, *a[20];
	int i = 1, v = 0, ex = 0, _e = 0, b = 0;

	_prompt("$ ", 2);
	_b = getline(&e, &_s, stdin);
	while (_b != -1)
	{
		if (*e != '\n')
		{
			cmds(e, a);
			if (a[0] != NULL)
			{
				ex = verify(a[0]);
				if (ex != 0)
				{
					v = env_path(a);
					if (v == 0)
						_e = exec(a), free(*a);
					else
					{
						b = builtins(a, ex);
						if (b != 0)
						_e = err_print(a, i), free(e);
					}
				}
				else
					_e = exec(a), free(e);
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
