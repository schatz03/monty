#include "monty.h"

/**
 * execute - helper function for main function
 * @args: pointer to struct of arguments from main
 * @file: pointer to file
 * Description: opens and reads from the file
 * containing the opcodes, and calls the function
 * that will find the corresponding executing function
 */
void execute(args_m *args, FILE *file)
{
	size_t line_length = 0;

	while (getline(&data.line, &line_length, file) != -1)
	{
		args->line_number++;
		data.words = strtow(data.line);
		if (data.words[0] == NULL || data.words[0][0] == '#')
		{
			free_instractions(0);
			continue;
		};
		if (!get_instruction(data.words)->f)
		{
			fprintf(stderr, UNKNOWN, args->line_number, data.words[0]);
			free_instractions(1);
			exit(EXIT_FAILURE);
		}
		get_instruction(data.words)->f(&(data.stack), args->line_number);
		free_instractions(0);
	}
	free_instractions(1);
}
