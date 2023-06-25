#include "monty.h"

/**
 * _add - Handles the _add instruction
 * @stack: Double pointer to the stack to _modify
 * @line_number: Number of the line in the file
 *
 * Return: nothing
 */
void _add(stack_m **stack, unsigned int line_number)
{
	int sum = 0;
	stack_m *new_node = NULL;
	stack_m *new_node_0 = get_dnodeint_at_index(*stack, 0);
	stack_m *new_node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, _add_FAIL, line_number);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}

	sum = new_node_0->n + new_node_1->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	new_node = _add_dnodeint(stack, sum);
	if (!new_node)
	{
		fprintf(stderr, MALLOC_FAIL);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * _nop - Handles the _nop instruction
 * @stack: Double pointer to the stack
 * @line_number: Number of the line in the file
 *
 * Return: nothing
 */
void _nop(stack_m **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * _sub - Handles the _sub instruction
 * @stack: Double pointer to the stack
 * @line_number: Number of the line in the file
 *
 * Return: nothing
 */

void _sub(stack_m **stack, unsigned int line_number)
{
	int result = 0;
	stack_m *new_node = NULL;
	stack_m *new_node_0 = get_dnodeint_at_index(*stack, 0);
	stack_m *new_node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, _sub_FAIL, line_number);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}

	result = new_node_1->n - new_node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	new_node = _add_dnodeint(stack, result);
	if (!new_node)
	{
		fprintf(stderr, MALLOC_FAIL);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * _div - Handles the _div instruction
 * @stack: Double pointer to the stack
 * @line_number: Number of the line in the file
 *
 * Return: nothing
 */
void _div(stack_m **stack, unsigned int line_number)
{
	int result = 0;
	stack_m *new_node = NULL;
	stack_m *new_node_0 = get_dnodeint_at_index(*stack, 0);
	stack_m *new_node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, _div_FAIL, line_number);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}

	if (new_node_0->n == 0)
	{
		fprintf(stderr, _div_ZERO, line_number);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}

	result = new_node_1->n / new_node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	new_node = _add_dnodeint(stack, result);
	if (!new_node)
	{
		fprintf(stderr, MALLOC_FAIL);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * _mul -  handle the _multiplication instruction
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: nothing
 */
void _mul(stack_m **stack, unsigned int line_number)
{
	int result = 0;
	stack_m *new_node = NULL;
	stack_m *new_node_0 = get_dnodeint_at_index(*stack, 0);
	stack_m *new_node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, _mul_FAIL, line_number);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}

	result = new_node_1->n * new_node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	new_node = _add_dnodeint(stack, result);
	if (!new_node)
	{
		fprintf(stderr, MALLOC_FAIL);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}
}
