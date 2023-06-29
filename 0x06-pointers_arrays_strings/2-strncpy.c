#include "main.h"
#include <stddef.h>

/**
 * _strncpy - Copies a string.
 * @dest: Destination string pointer.
 * @src: Source string pointer.
 * @n: Maximum number of characters to be copied.
 *
 * Return: Pointer to the resulting string dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
