#include "shell.h"

/**
 * main - entry file of the simple shell program
 * Return: 0 on success
 */

int main (void)
{
	ssize_t _bytessize_ = 0;
	size_t _bufsize_ = 0;
	char *entry = NULL, *args[20];
	int counter = 1, verify_status =0;
	int exist_status = 0, exit_status = 0;
	int builtins_status = 0;

	_prompt("$ ", 2);
	_bytessize_ = getline(&entry, &_bufsize_, stdin);
	while (_bytessize_ != -1)
	{
		if (*entry != '\n')
		{
			cmds(entry, args);
			if (args[0] != NULL)
			{
				exist_status = verify(args[0]);
				if (exist_status != 0)
				{
					verify_status = env_path(args);
					if (verify_status == 0)
						exit_status = exec(args), free(*args);
					else
					{
						builtins_status = builtins(args, exist_status);
						if (builtins_status != 0)
							exit_status = err_print(args, counter), free(entry);
					}
				}
				else
					exit_status = exec(args), free(entry);
			}
			else
				free(entry);
		}
		else if (*entry == '\n')
			free(entry);
		entry = NULL, counter++;
		_prompt("$ ", 2), _bytessize_ = getline(&entry, &_bufsize_, stdin);
	}
	memory(entry);
	return (exit_status);
}
