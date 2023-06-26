#include "main.h"

int _putchar(char c);  /* Declaration of _putchar */

/**
 * puts2 - Prints every other character of a string.
 * @str: Pointer to a string.
 */
void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i % 2 == 0)
		{
			_putchar(str[i]);
		}
	}

	_putchar('\n');
}
