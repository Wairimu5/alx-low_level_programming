#include <stdlib.h>

/**
 * is_space - Checks if a character is a whitespace character.
 * @c: The character to check.
 *
 * Return: 1 if character is a whitespace, 0 otherwise.
 */
int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count words from.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (!is_space(str[i]))
		{
			count++;
			while (str[i] && !is_space(str[i]))
				i++;
		}
		else
		{
			i++;
		}
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: Pointer to an array of strings (words) or NULL if it fails.
 */
char **strtow(char *str)
{
	int word_count, i, j = 0, k, start;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);

	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!is_space(str[i]))
		{
			start = i;
			while (str[i] && !is_space(str[i]))
				i++;

			words[j] = malloc((i - start + 1) * sizeof(char));

			if (words[j] == NULL)
			{
				for (k = 0; k < j; k++)
					free(words[k]);
				free(words);
				return (NULL);
			}

			for (k = 0; start < i; start++, k++)
				words[j][k] = str[start];
			words[j][k] = '\0';
			j++;
		}
	}

	words[j] = NULL;
	return (words);
}
