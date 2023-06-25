#include "monty.h"

/**
 * push - handles the push instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void push(stack_m **stack, unsigned int line_number)
{
	stack_m *new_s = NULL;
	int num = 0, i;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}
	for (i = 0; data.words[1][i]; i++)
	{
		if (isalpha(data.words[1][i]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			free_instractions(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.words[1]);
	if (data.qflag == 0)
		new_s = _add_dnodeint(stack, num);
	else if (data.qflag == 1)
		new_s = _add_dnodeint_end(stack, num);
	if (!new_s)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pall - handles the _pall instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void _pall(stack_m **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		print_dlistint(*stack);
}

/**
 * _pint - Handles the _pint instruction
 * @stack: Double pointer to the stack to push to
 * @line_number: Number of the line in the file
 *
 * Return: nothing
 */
void _pint(stack_m **stack, unsigned int line_number)
{
	stack_m *current = *stack;

	if (!current)
	{
		dprintf(STDERR_FILENO, _pint_FAIL, line_number);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", current->n);
}

/**
 * _pop - Handles the _pop instruction
 * @stack: Double pointer to the stack to _modify
 * @line_number: Number of the line in the files
 *
 * Return: nothing
 */
void _pop(stack_m **stack, unsigned int line_number)
{
	stack_m *tmp = *stack;

	if (!tmp)
	{
		dprintf(STDERR_FILENO, _pop_FAIL, line_number);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}

/**
 * _swap - Handles the _swap instruction
 * @stack: Double pointer to the stack to _modify
 * @line_number: number of the line in the file
 *
 * Return: nothing
 */
void _swap(stack_m **stack, unsigned int line_number)
{
	stack_m *tmp = *stack, *new_node = NULL;
	int number;

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, _swap_FAIL, line_number);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}

	tmp = get_dnodeint_at_index(*stack, 0);
	number = tmp->n;
	delete_dnodeint_at_index(stack, 0);
	new_node = insert_dnodeint_at_index(stack, 1, number);
	if (!new_node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}
}
