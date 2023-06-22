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
	char line[100];
	unsigned int line_number = 1;
	stack_m *stack = NULL;
	char *opcode;
	int found;
	int i;

	while (fgets(line, sizeof(line), file))
	{
		line[strcspn(line, "\n")] = '\0';

		opcode = strtok(line, " \t");
		if (opcode == NULL)
		{
			line_number++;
			continue;
		}

		found = 0;
		for (i = 0; instructions[i].opcode; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				found = 1;
				break;
			}
		}

		if (!found)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}

		line_number++;
	}
}

