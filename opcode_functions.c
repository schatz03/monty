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
	if (_isdigit(op_code_and_arg.arg) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_m));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(op_code_and_arg.arg);
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
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - Print the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction in the bytecode file
 *
 * Description: Prints the value at the top of the stack, followed by a newline.
 * If the stack is empty, it prints an error message and exits with EXIT_FAILURE.
 */
void pint(stack_m **stack, unsigned int line_number)
{
	stack_m *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}
