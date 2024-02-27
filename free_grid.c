#include "shell.h"
#include <stdlib.h>

/**
 *free_grid - Free the allocated memory used in the last excercise
 *@grid: pointer to grid
 *@height: Height of the grid
 */

void free_grid(char **grid, int height)
{
	int i = 0;

	if (grid == NULL)
		return;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
}
