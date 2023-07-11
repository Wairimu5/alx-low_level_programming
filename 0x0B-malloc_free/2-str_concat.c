#include <stdlib.h>

/**
 * str_concat - Concatenates two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: A pointer to the concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concatenated;
	unsigned int len1 = 0, len2 = 0, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate the length of s1 and s2 */
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	/* Allocate memory for the concatenated string */
	concatenated = malloc((len1 + len2 + 1) * sizeof(char));
	if (concatenated == NULL)
		return (NULL);

	/* Copy the contents of s1 */
	for (i = 0; i < len1; i++)
		concatenated[i] = s1[i];

	/* Copy the contents of s2 */
	for (j = 0; j < len2; j++)
		concatenated[i++] = s2[j];

	concatenated[i] = '\0'; /* Null-terminate the concatenated string */

	return (concatenated);
}
