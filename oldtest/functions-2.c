#include "monty.h"

/**
 * _mod - Handle the _modulo instruction
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: nothing
 */
void _mod(stack_m **stack, unsigned int line_number)
{
	int result = 0;
	stack_m *new_node = NULL;
	stack_m *new_node_0 = get_dnodeint_at_index(*stack, 0);
	stack_m *new_node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, _mod_FAIL, line_number);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}

	if (new_node_0->n == 0)
	{
		fprintf(stderr, _div_ZERO, line_number);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}

	result = new_node_1->n % new_node_0->n;
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
 * stack - Handle the 'stack' instruction
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: nothing
 */
void stack(stack_m **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 0;
}

/**
 * _rotl - Handle the '_rotl' instruction
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: nothing
 */
void _rotl(stack_m **stack, unsigned int line_number)
{
	stack_m *current_node = *stack;
	int value = 0;

	(void)line_number;

	if (*stack == NULL)
		return;
	current_node = get_dnodeint_at_index(*stack, 0);
	value = current_node->n;
	delete_dnodeint_at_index(stack, 0);
	_add_dnodeint_end(stack, value);
}

/**
 * queue - Handle the 'queue' instruction
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: nothing
 */
void queue(stack_m **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 1;
}

/**
 * _rotr - Handle the '_rotr' instruction
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: nothing
 */
void _rotr(stack_m **stack, unsigned int line_number)
{
	stack_m *current_node = *stack;
	int value = 0, length = dlistint_len(*stack);

	(void)line_number;

	if (*stack == NULL)
		return;
	current_node = get_dnodeint_at_index(*stack, length - 1);
	value = current_node->n;
	delete_dnodeint_at_index(stack, length - 1);
	_add_dnodeint(stack, value);
}
