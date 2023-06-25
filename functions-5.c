#include "monty.h"

/**
 * print_dlistint - prints a doubly linked list
 * @h: doubly linked list root
 *
 * Return: doubly liked list length
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t len = 0;

	if (!h)
		return (0);

	for (; h; h = h->next, len++)
		printf("%d\n", h->n);
	return (len);
}

/**
 * dlistint_len - returns the length of doubly linked list
 * @h: douly linked list root
 *
 * Return: length of list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;

	if (!h)
		return (0);

	for (; h; h = h->next)
		len++;
	return (len);
}

/**
 * free_dlistint - frees a doubly linked list
 * @head: doubly linked list root
 *
 * Return: nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
