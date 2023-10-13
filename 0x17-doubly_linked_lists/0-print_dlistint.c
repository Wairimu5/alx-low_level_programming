#include "lists.h"


/**
 * print_dlistint - prints all the nodes of a double linked list
 * @h: a pointer to the first node of a double linked list
 *
 * Return: the number of nodes of a double linked list
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t number_nodes = 0;

	if (h == NULL)
		return (number_nodes);
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		number_nodes++;
	}
	return (number_nodes);
}
