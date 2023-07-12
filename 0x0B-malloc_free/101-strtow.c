#include <stdlib.h>
#include <stdio.h>

int is_space(char c);
int count_words(char *str);
char **free_words(char **words, int count);

/**
 * strtow - Splits a string into words
 * @str: The input string
 *
 * Return: Pointer to an array of strings (words), or NULL on failure
 */
char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
		return (NULL);

	int word_count = count_words(str);
	if (word_count == 0)
		return (NULL);

	char **words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	int i, j = 0, k, len, start;

	for (i = 0; i < word_count; i++)
	{
		while (is_space(*str))
			str++;

		start = 0;
		while (str[start] && !is_space(str[start]))
			start++;

		words[j] = malloc((start + 1) * sizeof(char));
		if (words[j] == NULL)
			return (free_words(words, j));

		for (k = 0; k < start; k++)
			words[j][k] = str[k];
		words[j][k] = '\0';

		j++;
		str += start;
	}

	words[j] = NULL;
	return (words);
}

/**
 * is_space - Checks if a character is a space
 * @c: The character to check
 *
 * Return: 1 if c is a space, 0 otherwise
 */
int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/**
 * count_words - Counts the number of words in a string
 * @str: The input string
 *
 * Return: The number of words
 */
int count_words(char *str)
{
	int count = 0;

	while (*str)
	{
		while (is_space(*str))
			str++;

		if (*str)
		{
			count++;
			while (*str && !is_space(*str))
				str++;
		}
	}

	return (count);
}

/**
 * free_words - Frees the memory allocated for the words
 * @words: The array of words
 * @count: The number of words
 *
 * Return: NULL
 */
char **free_words(char **words, int count)
{
	for (int i = 0; i < count; i++)
		free(words[i]);

	free(words);
	return (NULL);
}
