#include <stdio.h>
#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at the given index in a decimal number.
 * @n: Pointer to the number to modify.
 * @index: Index of the bit to set to 1.
 *
 * Return: Returns 1 if the bit was successfully set to 1, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index);

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    unsigned long int n;

    n = 1024;
    set_bit(&n, 5);
    printf("%lu\n", n);

    n = 0;
    set_bit(&n, 10);
    printf("%lu\n", n);

    n = 98;
    set_bit(&n, 0);
    printf("%lu\n", n);

    return (0);
}
