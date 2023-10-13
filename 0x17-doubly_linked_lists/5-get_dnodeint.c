#include "lists.h"

/**
 * get_dnodeint_at_index - returns a node in the double linked list
 * @head: a pointer to the first node of a double linked list
 * @index: the desired index
 *
 * Return: the node at the desired index
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int now = 0;

	if (head == NULL)
		return (NULL);
	while (head != NULL)
	{
		if (now == index)
			return (head);
		now++;
		head = head->next;
	}
	return (NULL);
}
