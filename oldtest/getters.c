#include "monty.h"

/**
 * get_instruction - manage all functions
 * @parsed: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function (success),
 * or NULL (failure)
 */
instruction_m *get_instruction(char **parsed)
{

	int i = 0;
	instruction_m *_instructions = fill_instruction();

	while (_instructions[i].opcode != NULL)
	{
		if (strcmp(_instructions[i].opcode, parsed[0]) == 0)
			return (&_instructions[i]);
		i++;
	}
	return (NULL);
}

/**
 * pchar - Handles the 'pchar' instructio
 * @stack: Double pointer to the stack to retrieve the top element from
 * @line_number: Number of the line in the file
 *
 * Return: nothing
 */
void pchar(stack_m **stack, unsigned int line_number)
{
	stack_m *new_node = *stack;

	if (!new_node)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, line_number);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}

	if (new_node->n < 0 || new_node->n > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE, line_number);
		free_instractions(1);
		exit(EXIT_FAILURE);
	}

	putchar(new_node->n);
	putchar('\n');
}

/**
 * pstr - Handles the 'pstr' instruction
 * @stack: Double pointer to the stack to retrieve elements from
 * @line_number: Number of the line in the file
 *
 * Return: nothing
 */
void pstr(stack_m **stack, unsigned int line_number)
{
	stack_m *new_node = *stack;
	(void)line_number;
	if (!new_node)
	{
		putchar('\n');
		return;
	}

	while (new_node && new_node->n != 0 && new_node->n >= 0 && new_node->n <= 127)
	{
		putchar(new_node->n);
		new_node = new_node->next;
	}

	putchar('\n');
}
/**
 * fill_instruction - fill all functions with opcode
 * Return: nothing
 */
instruction_m *fill_instruction()
{
	instruction_m *ptr_instructions = NULL;
	instruction_m instructions[] = {
		{"push", push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}};
	ptr_instructions = instructions;
	return (ptr_instructions);
}
