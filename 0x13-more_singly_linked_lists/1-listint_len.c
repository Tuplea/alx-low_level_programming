#include "lists.h"

/**
 * listint_len - returns all elements in a linked lists
 * @h: linked list of type listint_t to traverse
 *
 * Return: all nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t nom = 0;

	while (h != NULL)
	{
		nom++;
		h = h->next;
	}
	return (nom);
}

