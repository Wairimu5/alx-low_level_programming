#include "main.h"

/**
 * wildcmp - Compares two strings and checks if they are identical.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 1 if the strings are identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0') /* Both strings reach the end */
		return (1);

	if (*s1 == *s2) /* Current characters match */
	{
		if (*s1 == '\0') /* End of string s1 reached, check s2 */
			return (wildcmp(s1, s2 + 1));
		return (wildcmp(s1 + 1, s2 + 1));
	}

	if (*s2 == '*') /* Wildcard encountered in s2 */
	{
		if (*s1 == '\0') /* Check if remaining s1 can be replaced by '*' in s2 */
			return (wildcmp(s1, s2 + 1));
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}

	return (0); /* Characters don't match and no wildcard */
}
