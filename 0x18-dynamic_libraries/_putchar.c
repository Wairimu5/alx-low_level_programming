#include "main.h"
#include <unistd.h>


/**
 * _putchar - set the integer to 402
 * @c: a pointer the integer we want to swap
 *
 * Return: nothing
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
