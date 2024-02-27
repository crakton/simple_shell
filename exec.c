#include "shell.h"

/**
 * exec - child process creation, executes and waits
 * for the child process to update status
 * @args - array of inputs
 * Return: 0 on success
 */

int exec(char **args)
{
	pid_t pid = 0;
	int status = 0, exec_status = 0;

	pid = fork(); 
	if (pid == -1)
	/* Child process creation */
		_prompt("process creation failed\n", 7);
	else if (pid == 0)
	{
		exec_status = execve(args[0], args, environ);
		if (exec_status == -1)
		{
			exec_status = 126;
			perror("exec");
			exit(exec_status);
		}
		exit(0);
	}
	else
		/* Parent process creation */
		wait(&status);

	exec_status = WEXITSTATUS(status);
	return (exec_status);
}
