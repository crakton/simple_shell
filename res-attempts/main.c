#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Main Entry
 * Return: 0 for success, -1 for Exit */

int main(int argc, char **argv)
{
	FILE *file = NULL;
	char *input;
	int status;

	/* We modify the main entry function to accept a file as input and execute the commands from the file. */
	if (argc > 1)
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			perror("main");
			return EXIT_FAILURE;
		}
	}
	else
		{
		file = stdin; /*not a file but an input command.*/
	}
	
	while (1)
	{
		if (file == NULL)
		{
			printf("#cisfun$ ");
			input = read_input(stdin);
		}
		else
		{
			input = read_input(file);
			if (input == NULL)
				break;
		}

		if (input == NULL)
			continue;

		if (strcmp(input, "exit\n") == 0)
		{
			free(input);
			break;
		}

		status = execute_command(&input);
		free(input);
		if (status == -1)
			break; 
	} 
	if (argc > 1) 
		fclose(file);

	return EXIT_SUCCESS;
}
