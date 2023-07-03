#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the diagonals of a square matrix.
 * @a: Pointer to the 2D array representing the matrix.
 * @size: Size of the square matrix.
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0; /* Sum of the main diagonal */
	int sum2 = 0; /* Sum of the secondary diagonal */

	for (i = 0; i < size; i++)
	{
		sum1 += a[i * size + i]; /* Elements on the main diagonal */
		sum2 += a[i * size + (size - 1 - i)]; /* Elements on the secondary diagonal */
	}

	printf("Sum of main diagonal: %d\n", sum1);
	printf("Sum of secondary diagonal: %d\n", sum2);
}
