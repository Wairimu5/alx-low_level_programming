#include <stdio.h>
#include <stdlib.h>

/**
 * multiply - Multiplies two positive numbers
 * @num1: First number
 * @num2: Second number
 *
 * Return: Result of the multiplication
 */
int multiply(int num1, int num2)
{
	return (num1 * num2);
}

/**
 * is_valid_number - Checks if a string represents a valid positive number
 * @str: The string to check
 *
 * Return: 1 if the string represents a valid positive number, 0 otherwise
 */
int is_valid_number(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}

int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 3 || !is_valid_number(argv[1]) || !is_valid_number(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	result = multiply(num1, num2);

	printf("%d\n", result);

	return (0);
}
