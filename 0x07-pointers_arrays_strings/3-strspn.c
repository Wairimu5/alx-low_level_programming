#include "main.h"
#include <stdio.h>

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: Pointer to the string to be analyzed.
 * @accept: Pointer to the string containing the accepted bytes.
 *
 * Return: The number of bytes in the initial segment of s that consist
 *         only of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int len = 0;
	int found;
	char *original_accept = accept; /* Store the original accept pointer */

	while (*s)
	{
		found = 0;
		while (*accept)
		{
			if (*s == *accept)
			{
				found = 1;
				break;
			}
			accept++;
		}

		if (!found)
			break;

		len++;
		s++;
		accept = original_accept; /* Reset accept to the beginning */
	}

	return (len);
}
