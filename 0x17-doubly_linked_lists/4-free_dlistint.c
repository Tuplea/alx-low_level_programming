#include "lists.h"

/**
 * free_dlistint - free that dlistint_t list
 *
 * @head: is head of list
 *
 * Return: none
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	if (head != NULL)
		while (head->prev != NULL)
			head = head->prev;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
