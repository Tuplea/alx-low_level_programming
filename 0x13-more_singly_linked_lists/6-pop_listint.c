#include "lists.h"

/**
 * pop_listint - Deletes the head node of a linked list and returns its data
 * @head: A pointer to a pointer to the head of the linked list
 *
 * Return: The data stored in the head node, or 0 if the linked list is empty
 */
int pop_listint(listint_t **head)
{
listint_t *update;
int nom;

if (*head == NULL)
return (0);

update = *head;
nom = update->n;
*head = (*head)->next;
free(update);

return (nom);
}
