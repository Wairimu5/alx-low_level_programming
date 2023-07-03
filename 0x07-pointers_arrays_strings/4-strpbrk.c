#include "main.h"
#include <stdio.h>

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: Pointer to the string to be searched.
 * @accept: Pointer to the string containing the bytes to search for.
 *
 * Return: Pointer to the first occurrence of a byte in s that matches one
 *         of the bytes in accept, or NULL if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
	char *p_s, *p_accept;

	while (*s != '\0')
	{
		p_accept = accept;
		while (*p_accept != '\0')
		{
			if (*p_accept == *s)
			{
				p_s = s;
				return (p_s);
			}
			p_accept++;
		}
		s++;
	}

	return (NULL);
}
