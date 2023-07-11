#include <stdlib.h>

/**
 * free_grid - Frees the memory allocated for a 2D grid
 * @grid: Pointer to the grid to be freed
 * @height: The height of the grid
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
		return;

	/* Free the memory for each row */
	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	/* Free the memory for the grid */
	free(grid);
}
