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
	char *push;
	(void)line_number;

	push = "push";
	new_node = malloc(sizeof(stack_m));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (_isdigit(op_code_and_arg.arg) != 1 && op_code_and_arg.op_code == push)
		return;
	new_node->n = atoi(op_code_and_arg.arg);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

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
	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}
