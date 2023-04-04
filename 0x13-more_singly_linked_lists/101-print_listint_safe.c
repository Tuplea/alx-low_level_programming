#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the first element of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nom = 0;
	const listint_t *temp = head, *loopnode = head;

	if (head == NULL)
	{
		return (nom);
	}

	while (temp != NULL)
	{
		printf("[%p] %d\n", (void *) temp, temp->n);
		temp = temp->next;
		nom++;

		if (temp >= loopnode)
		{
			printf("-> [%p] %d\n", (void *) temp, temp->n);
		}

		loopnode = (loopnode == head) ? temp : loopnode;
	}

	return (nom);
}
