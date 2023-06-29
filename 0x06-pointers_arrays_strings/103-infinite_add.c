#include <stdio.h>

/**
 * infinite_add - Adds two numbers
 * @n1: First number as a string
 * @n2: Second number as a string
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 *
 * Return: Pointer to the result or 0 if the result cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, len_res;
	int carry = 0, digit_sum;
	int i, j, k;

	/* Calculate the lengths of n1 and n2 */
	for (len1 = 0; n1[len1] != '\0'; len1++)
		;
	for (len2 = 0; n2[len2] != '\0'; len2++)
		;

	/* Check if the result can be stored in r */
	if (size_r <= len1 || size_r <= len2)
		return (0);

	/* Calculate the sum of digits */
	len_res = (len1 > len2) ? len1 : len2;
	r[len_res] = '\0'; /* Null-terminate the result string */
	i = len1 - 1;
	j = len2 - 1;
	k = len_res - 1;

	while (k >= 0)
	{
		digit_sum = carry;

		if (i >= 0)
			digit_sum += n1[i] - '0';
		if (j >= 0)
			digit_sum += n2[j] - '0';

		carry = digit_sum / 10;
		r[k] = (digit_sum % 10) + '0';

		i--;
		j--;
		k--;
	}

	/* Check if there is a leftover carry */
	if (carry != 0)
	{
		/* Check if there is enough space in r to store the carry */
		if (size_r <= len_res + 1)
			return (0);

		/* Shift the digits to the right and store the carry */
		for (i = len_res; i >= 0; i--)
			r[i + 1] = r[i];
		r[0] = carry + '0';
		len_res++;
	}

	return (r);
}

int main(void)
{
	char n1[] = "123456789";
	char n2[] = "987654321";
	char result[20];

	char *res = infinite_add(n1, n2, result, sizeof(result));
	if (res)
		printf("Result: %s\n", res);
	else
		printf("Cannot store the result\n");

	return 0;
}
