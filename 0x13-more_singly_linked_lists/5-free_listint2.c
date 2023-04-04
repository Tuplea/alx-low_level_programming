#include "lists.h"

/**
 * free_listint2 - frees a linked list and sets the head to NULL
 * @head: A pointer to a pointer to the head of the linked list
 */
void free_listint2(listint_t **head)
{
	listint_t *update;

	while (*head != NULL)
	{
		update = *head;
		*head = (*head)->next;
		free(update);
	}

	*head = NULL;
}
