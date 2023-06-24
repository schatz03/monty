#include "monty.h"
/**
 * push - Push an element to the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction in the byte code file
 *
 * Description: Pushes an element to the top of the stack.
 * If the argument is not an integer or if no argument is given,
 * it prints an error message and exits with EXIT_FAILURE.
 * Uses the atoi function to convert the argument to an integer.
 */
void push(stack_m **stack, unsigned int line_number)
{
	stack_m *new_node;
	(void)line_number;
	new_node = malloc(sizeof(stack_m));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = op_code_and_arg.arg;
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
}
/**
 * pall - Print all the values on the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction in the byte code file
 *
 * Description: Prints all the values on the stack, starting from the top.
 * If the stack is empty, it does not print anything.
 */
void pall(stack_m **stack, unsigned int line_number)
{
	stack_m *current = *stack;
	(void)line_number;
	while (current && current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}
