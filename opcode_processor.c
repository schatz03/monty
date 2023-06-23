#include "monty.h"

/**
 * process_opcodes - Read and execute Monty byte code instructions
 * @file: Pointer to the file containing the byte code instructions
 * @instructions: Array of instruction structures
 *
 * Description: Reads each line of the byte code file, tokenizes the opcode,
 * and executes the corresponding function based on the opcode.
 * Each opcode function is responsible for the specific operation.
 */
void process_opcodes(FILE *file, instruction_m *instructions)
{
	unsigned int line_number = 1;
	stack_m *stack = NULL;
	char *buffer = NULL;
	size_t n = 0;
	int read, j, check;

	while ((read = getline(&buffer, &n, file)) != -1)
	{
		if (_parse_opcode(buffer, &stack, line_number) != 1)
			continue;
		if (op_code_and_arg.op_code == NULL || op_code_and_arg.op_code[0] == '#'
		|| op_code_and_arg.op_code[0] == '\n')
		{
			line_number++;
			continue;
		}
		j = 0;
		while (instructions[j].f != NULL &&
			   strcmp(instructions[j].opcode, op_code_and_arg.op_code) != 0)
			j++;
		if (instructions[j].f == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_number, op_code_and_arg.op_code);
			exit(EXIT_FAILURE);
		}
		instructions[j].f(&stack, line_number);
		line_number++;
	}
	check = fclose(file);
	if (check == -1)
		exit(-1);
}
