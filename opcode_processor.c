#include "monty.h"

/**
 * process_opcodes - Read and execute Monty byte code instructions
 * @file: Pointer to the file containing the byte code instructions
 * @instructions: Array of instruction structures
 *
 * Description: Reads each line of the byte code file, tokenizes the opcode,
 * and executes the corresponding function based on the opcode.
 * Each opcode function is responsible for the specific operation.
 * Return: 0 or 1 if all good
 */
int process_opcodes(FILE *file, instruction_m *instructions)
{
	unsigned int i = 0, counter = 0;
	size_t size = 0, read_line = 1;
	stack_m *stack = NULL;
	char *op, *content;

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		op_code_and_arg.content = content;
		counter++;
		if (read_line > 0)
		{
			op = strtok(content, " \n\t");
			if (op && op[0] == '#')
				return (0);
			op_code_and_arg.arg = strtok(NULL, " \n\t");
			while (instructions[i].opcode && op)
			{
				if (strcmp(op, instructions[i].opcode) == 0)
				{
					instructions[i].f(&stack, counter);
					return (0);
				}
				i++;
			}
			if (op && instructions[i].opcode == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
				fclose(file);
				free(content);
				exit(EXIT_FAILURE);
			}
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
