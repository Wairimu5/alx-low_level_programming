#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at the given index
 * @head: a pointer to the first node of a double linked list
 * @index: the desired index
 *
 * Return: 1 in success or -1 in failure
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *next, *previous, *find_the_index;
	unsigned int now = 0;

	if (head == NULL || *head == NULL)
		return (-1);
	find_the_index = *head;
	while (find_the_index->next != NULL)
	{
		if (now == index)
		{
			printf("%d\n", now);
			break;
		}
		find_the_index = find_the_index->next;
		now++;
	}
	if (index > now)
		return (-1);
	if (index == 0)
	{
		next = find_the_index->next;
		if (next == NULL)
			*head = NULL;
		else
		{
			next->prev = NULL;
			*head = next;
		}
		return (1);
	}
	next = find_the_index->next;
	previous = find_the_index->prev;
	previous->next = next;
	next->prev = previous;
	printf("After Deleting...\n");
	free(find_the_index);
	return (1);
}
