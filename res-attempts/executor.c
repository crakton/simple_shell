#include "shell.h"

/**
 * execute_command - Execute the command with arguments
 * @args: An array of pointers to tokens representing the command and its arguments
 * Return: 0 on success, -1 on exit command
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
		return 1;

	if (strcmp(args[0], "exit") == 0)
	{
		/* implement the logical operators && and || to execute commands conditionally. */
		if (args[1] != NULL)
			exit(atoi(args[1]));
		else
			exit(EXIT_SUCCESS);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		char **env = environ;
		while (*env)
		{
			printf("%s\n", *env);
		env++;
		}
		return 0;
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		change_directory(args);
		return 0;
	}

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("execute_command");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("execute_command");
		exit(EXIT_FAILURE);
	}
	else
		{
			/* Parent process */
			do
			{
				waitpid(pid, &status, WUNTRACED);
			}while (!WIFEXITED(status) && !WIFEXITED(status));
		}

		return 0;
}
