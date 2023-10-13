#include "lists.h"


/**
 * dlistint_len - Counts all the nodes of a double linked list
 * @h: a pointer to the first node of a double linked list
 *
 * Return: the number of nodes of a double linked list
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;

	if (h == NULL)
		return (len);
	while (h != NULL)
	{
		len++;
		h = h->next;
	}
	return (len);
}
