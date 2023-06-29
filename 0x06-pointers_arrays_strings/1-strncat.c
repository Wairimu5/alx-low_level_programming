#include "main.h"
#include <stddef.h>

/**
 * _strncat - Concatenates two strings, using at most n bytes from src.
 * @dest: Destination string pointer.
 * @src: Source string pointer.
 * @n: Maximum number of bytes from src to be appended.
 *
 * Return: Pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0;
	int i;

	while (dest[dest_len] != '\0')
		dest_len++;

	for (i = 0; i < n && src[i] != '\0'; i++, dest_len++)
		dest[dest_len] = src[i];

	dest[dest_len] = '\0';

	return (dest);
}
