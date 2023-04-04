#include "lists.h"

/**
 * free_list - frees a linked list
 * @head - points to head of a linked list
 */
void free_listint(listint_t *head)
{
	listint_t *update;

	while (head != NULL)
	{
		update = head;
		head = head->next;
		free(update);
	}
}
