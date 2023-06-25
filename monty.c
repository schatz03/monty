#include "monty.h"

/**
 * execute - helper function for main function
 * @args: pointer to struct of arguments from main
 *
 * Description: opens and reads from the file
 * containing the opcodes, and calls the function
 * that will find the corresponding executing function
 */
void execute(args_m *args)
{
	int get = 0;
	size_t len = 0;
	void (*code_func)(stack_m **, unsigned int);

	while (1)
	{
		args->line_number++;
		get = getline(&(data.line), &len, data.fptr);
		if (get < 0)
			break;
		data.words = strtow(data.line);
		if (data.words[0] == NULL || data.words[0][0] == '#')
		{
			free_instractions(0);
			continue;
		}
		code_func = get_instruction(data.words);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, UNKNOWN, args->line_number, data.words[0]);
			free_instractions(1);
			exit(EXIT_FAILURE);
		}
		code_func(&(data.stack), args->line_number);
		free_instractions(0);
	}
	free_instractions(1);
}
