#include <stdio.h>

/**
 * print_binary - Prints the binary equivalent of a decimal number
 * @n: The number to print in binary
 */
void print_binary(unsigned long int n)
{
    int i, count = 0;
    unsigned long int current;
    int bits = sizeof(unsigned long int) * 8;

    for (i = bits - 1; i >= 0; i--)
    {
        current = n >> i;

        if (current & 1)
        {
            putchar('1');
            count++;
        }
        else if (count)
            putchar('0');
    }
    if (!count)
        putchar('0');
}
