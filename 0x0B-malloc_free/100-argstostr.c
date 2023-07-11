#include <stdlib.h>

/**
 * argstostr - Concatenates all arguments of the program
 * @ac: The argument count
 * @av: The argument vector
 *
 * Return: A pointer to the concatenated string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	char *concatenated;
	int i, k, len, total_len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate the total length of the concatenated string */
	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len])
			len++;
		total_len += len + 1; /* Add 1 for the newline character */
	}

	/* Allocate memory for the concatenated string */
	concatenated = (char *)malloc((total_len + 1) * sizeof(char));
	if (concatenated == NULL)
		return (NULL);

	/* Copy the arguments into the concatenated string */
	k = 0;
	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len])
		{
			concatenated[k] = av[i][len];
			k++;
			len++;
		}
		concatenated[k] = '\n'; /* Add newline character */
		k++;
	}
	concatenated[k] = '\0'; /* Null-terminate the concatenated string */

	return (concatenated);
}
