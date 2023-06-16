#include "lists.h"

/**
 * get_dnodeint_at_index - returns that
 *
 * nth node of our dlistint_t linked list
 *
 * @head: is head of our list
 *
 * @index: is index of nth node
 *
 * Return: nth node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	if (head == NULL)
		return (NULL);

	while (head->prev != NULL)
		head = head->prev;

	i = 0;

	while (head != NULL)
	{
		if (i == index)
			break;
		head = head->next;
		i++;
	}

	return (head);
}
