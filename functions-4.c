#include "monty.h"

/**
 * _add_dnodeint - _adds a new node at the beginning of a doubly linked list
 * @head: doubly linked list root
 * @n: new node data
 *
 * Return: created node, or NULL if it fails
 */
dlistint_t *_add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;

	new_node->next = *head;
	new_node->prev = NULL;

	if (*head)
		(*head)->prev = new_node;

	*head = new_node;

	return (new_node);
}

/**
 * _add_dnodeint_end - _adds a new node at the end of a doubly linked list
 * @head: doubly linked list root
 * @n: created node data
 *
 * Return: created node (success), or NULL (faillure)
 */
dlistint_t *_add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *tmp = *head;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new_node;
	new_node->prev = tmp;

	return (new_node);
}

/**
 * insert_dnodeint_at_index - inserts a node at a given position
 * in a doubly linked list
 * @h: doubly linked list root
 * @idx: given position
 * @n: created node data
 *
 * Return: created node, or NULL (failure)
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i;
	dlistint_t *new_node;
	dlistint_t *tmp = *h;

	if (idx == 0)
		return (_add_dnodeint(h, n));
	for (i = 0; tmp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			if (tmp->next == NULL)
				return (_add_dnodeint_end(h, n));
			new_node = malloc(sizeof(dlistint_t));
			if (!new_node || !h)
				return (NULL);
			new_node->n = n;
			new_node->next = NULL;
			new_node->next = tmp->next;
			new_node->prev = tmp;
			tmp->next->prev = new_node;
			tmp->next = new_node;
			return (new_node);
		}
		else
			tmp = tmp->next;
	}

	return (NULL);
}

/**
 * get_dnodeint_at_index - gets the nth node of a doubly linked list
 * @head: doubly linked list root
 * @index: given position
 *
 * Return: nth node, or  NULL (failure)
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);

	for (; head && i < index; head = head->next)
		i++;

	return (head ? head : NULL);
}

/**
 * delete_dnodeint_at_index - deltes a node in a doubly linked list
 * at a given position
 * @head: doubly linked list root
 * @index: given position
 *
 * Return: 1 (success), -1 (failure)
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp = *head;
	unsigned int i = 0;

	if (!index)
	{
		(*head) = tmp->next;
		if (tmp->next)
			tmp->next->prev = NULL;
		tmp->next = NULL;
		free(tmp);
		return (1);
	}
	while (i < index)
	{
		tmp = tmp->next;
		i++;
		if (!tmp)
			return (0);
	}

	tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	free(tmp);

	return (1);
}
