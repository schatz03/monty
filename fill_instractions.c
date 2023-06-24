#include "monty.h"
/**
 * create_instructions - Create an array of instruction structures
 *
 * Description: Allocates memory for an array of instruction structures
 * and returns a pointer to the allocated memory.
 *
 * Return: Pointer to the array of instruction structures
 */
instruction_m *create_instructions()
{
	instruction_m *instructions = (instruction_m *)malloc(
		sizeof(instruction_m) * 4);
	if (instructions == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (instructions);
}
/**
 * fill_instructions - Fill the array of instruction structures
 * @instructions: Pointer to the array of instruction structures
 *
 * Description: Fills the array of instruction structures with the
 * corresponding opcodes and function pointers.
 */
void fill_instructions(instruction_m *instructions)
{
	instructions[0].opcode = "push";
	instructions[0].f = push;
	instructions[1].opcode = "pall";
	instructions[1].f = pall;
	instructions[2].opcode = "pint";
	instructions[2].f = pint;
	instructions[3].opcode = NULL;
}
/**
 * free_instructions - Free the allocated memory for
 * the array of instruction structures
 * @instructions: Pointer to the array of instruction structures
 *
 * Description: Frees the memory allocated for the array of
 * instruction structures.
 */
void free_instructions(instruction_m *instructions)
{
	free(instructions);
}
