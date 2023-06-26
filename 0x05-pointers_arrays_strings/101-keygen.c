#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	char password[84];
	int i, sum;

	srand(time(NULL));

	/* Generate random password */
	for (i = 0, sum = 0; sum < 2772 - 122; i++)
	{
		password[i] = rand() % 94 + 33;
		sum += password[i];
	}

	password[i] = 2772 - sum;
	password[i + 1] = '\0';

	/* Print the generated password */
	printf("%s\n", password);

	return 0;
}
