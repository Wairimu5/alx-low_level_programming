#include "lists.h"

/**
 * sum_dlistint - sum all the nodes of a double linked list
 * @head: a pointer to the first node of a double linked list
 *
 * Return: all nodes summed up
 */


int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (sum);
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
