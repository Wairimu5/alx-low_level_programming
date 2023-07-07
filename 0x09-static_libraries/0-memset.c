#include "main.h"

/**
 * _memset - Fills a block of memory with a specific value
 * @s: Pointer to the starting address of memory to be filled
 * @b: The desired value to be set
 * @n: Number of bytes to be filled
 *
 * Return: Pointer to the modified memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
    {
        s[i] = b;
    }

    return (s);
}
