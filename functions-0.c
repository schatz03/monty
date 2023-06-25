#include "monty.h"


/**
 * _add - for adding a node to the stack
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void _add(stack_m **new_node, __attribute__((unused))unsigned int ln)
{
	stack_m *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * _pall - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void _pall(stack_m **stack, unsigned int line_number)
{
	stack_m *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _pop(stack_m **stack, unsigned int line_number)
{
	stack_m *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * _rev_pall - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _rev_pall(stack_m **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
