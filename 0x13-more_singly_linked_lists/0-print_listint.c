#include "lists.h"

/**
 * print_listint - will print all the elements of a linked list
 * @h: linked list of type listint_t to print
 *
 * Return: number of nodes as given
 */
size_t print_listint(const listint_t *h)
{
	size_t nom = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		nom++;
		h = h->next;
	}
	return (nom);
}
