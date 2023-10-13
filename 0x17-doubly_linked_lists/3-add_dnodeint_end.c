#include "lists.h"

/**
 * add_dnodeint_end - adds a node to the end of a double linked list
 * @head: a pointer to the beginning of the first node of a DLL
 * @n : a number to be stored in the new node of the DLL
 *
 * Return: a pointer to the newly created node
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *find_the_end;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;
	if (*head == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
	}
	else
	{
		find_the_end = (*head);
		while (find_the_end->next != NULL)
		{
			find_the_end = find_the_end->next;
		}
		new->prev = find_the_end;
		find_the_end->next = new;
		new->next = NULL;
	}
	return (new);
}
