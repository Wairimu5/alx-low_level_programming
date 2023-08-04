#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at the given index in a decimal number.
 * @n: Pointer to the number to modify.
 * @index: Index of the bit to set to 1.
 *
 * Return: Returns 1 if the bit was successfully set to 1, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);

