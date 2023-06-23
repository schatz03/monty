#include "monty.h"
/**
 * main - entry point
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: exit status int
 */

int main(int argc, char *argv[])
{
	OPCODEarg *op_code_and_arg = NULL;
	FILE *file;
	/* Fill the opcode and its function in instruction_t structure */
	instruction_m *instructions = create_instructions();
	(void)op_code_and_arg;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fill_instructions(instructions);
	/* Read and execute Monty byte code */
	process_opcodes(file, instructions);
	fclose(file);
	free_instructions(instructions);
	return (EXIT_SUCCESS);
}
