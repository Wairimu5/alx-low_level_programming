#include <stdio.h>

/**
 * main - Prints the number of arguments passed into the program
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int count;

	(void) argv; /* Indicates that the parameter is unused */

	count = argc - 1;

	printf("%d\n", count);

	return (0);
}
