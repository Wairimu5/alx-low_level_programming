#include "main.h"

/**
 * swap_integers - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_integers(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
