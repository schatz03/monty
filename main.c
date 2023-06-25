#include "monty.h"

/**
 * main - check code
 * @argc: arguments count
 * @argv: argument vetor
 *
 * Return: EXIT_SUCCESS, or EXIT_FAILURE if it failed
 */
int main(int argc, char *argv[])
{
	data_m data = {NULL, NULL, NULL, NULL, 0};
	args_m args;

	args.av = argv[1];
	args.ac = argc;
	args.line_number = 0;
	(void)data;
	if (args.ac != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	data.fptr = fopen(args.av, "r");
	if (data.fptr == NULL)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, args.av);
		exit(EXIT_FAILURE);
	}
	execute(&args, data.fptr);

	return (EXIT_SUCCESS);
}
