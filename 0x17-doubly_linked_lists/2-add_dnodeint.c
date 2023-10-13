#include "lists.h"


/**
 * add_dnodeint - adds a node to the beginning of a double linked list
 * @head: a pointer to the beginning of the first node of a DLL
 * @n : a number to be stored in the new node of the DLL
 *
 * Return: a pointer to the newly created node
 */


dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;
	if (*head == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{

		(*head)->prev = new;
		new->next = *head;
		new->prev = NULL;
	}
	*head = new;
	return (new);
}
