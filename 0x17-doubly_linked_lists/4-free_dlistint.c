#include "lists.h"

/**
 * free_dlistint - frees all the nodes of a double linked list
 * @head: a pointer to the first node of a double linked list
 *
 * Return: nothing
 */


void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		free(current);
		current = head->next;
		head = head->next;
	}
}
