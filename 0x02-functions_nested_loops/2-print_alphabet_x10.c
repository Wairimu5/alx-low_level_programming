#include "main.h"

/**
 * print_alphabet_x10 - Prints the alphabet in lowercase ten times
 */
void print_alphabet_x10(void)
{
	int i, j;
	char letter;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 26; j++)
		{
			letter = 'a' + j;
			_putchar(letter);
		}
		_putchar('\n');
	}
}
