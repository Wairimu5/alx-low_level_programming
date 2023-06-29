#include "main.h"
#include <stddef.h>

/**
 * _strcat - function that concatenates 2 strings.
 * @dest: destination string pointer.
 * @src: source string pointer.
 * Return: pointer to destination string
 */
char *_strcat(char *dest, char *src)
{
        int length_of_string = 0;
        int z;

        while (dest[length_of_string] != '\0')
                length_of_string++;

        for (z = 0; src[z] != '\0'; z++, length_of_string++)
        {
                dest[length_of_string] = src[z];
        }

        dest[length_of_string] = '\0';

        return (dest);
}
