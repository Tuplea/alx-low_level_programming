#include "lists.h"

/**
 * free_listint_safe - frees a listint_t linked list
 * @h: pointer to the first node of the list
 *
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nom = 0;
	listint_t *temp = NULL, *loopnode = NULL;

	if (h == NULL)
	{
		return (nom);
	}

	loopnode = *h;

	while (*h != NULL)
	{
		temp = (*h)->next;
		free(*h);
		nom++;

		if (temp >= loopnode)
		{
			break;
		}

		loopnode = (loopnode == *h) ? temp : loopnode;
		*h = temp;
	}

	*h = NULL;

	return (nom);
}
