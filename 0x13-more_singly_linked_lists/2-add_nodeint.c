#include "lists.h"
/**
 * add_nodeint - Adds new node at the beginning of a linked list
 * @head: is a pointer to a pointer  to the head of linked list
 * @n: The value is to be added to new node
 *
 * Return: A pointer to the new node, or NULL if failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newnode;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = *head;
	*head = newnode;

	return (newnode);
}
