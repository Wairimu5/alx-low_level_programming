#include "main.h"

/**
 * puts_half - Prints half of a string.
 * @str: Pointer to a string.
 */
void puts_half(char *str)
{
	int length = 0;
	int start_index;
	int i;

	/* Calculate the length of the string */
	while (str[length] != '\0')
		length++;

	/* Calculate the starting index for printing the second half */
	start_index = (length + 1) / 2;

	/* Print the second half of the string */
	for (i = start_index; str[i] != '\0'; i++)
		_putchar(str[i]);

	_putchar('\n');
}
