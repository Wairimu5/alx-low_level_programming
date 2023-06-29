#include "main.h"
#include <stdio.h>

/**
 * leet - encodes a string into 1337.
 * @str: the string to encode
 *
 * Return: pointer to the encoded string
 */
char *leet(char *str)
{
	int i, j;
	char *letters = "AEOTL";
	char *leet_chars = "43071";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (str[i] == letters[j] || str[i] == letters[j] + 32)
			{
				str[i] = leet_chars[j];
				break;
			}
		}
	}

	return (str);
}
