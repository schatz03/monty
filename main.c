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
	data_m data = DATA_INIT;
	args_m args;

	args.av = argv[1];
	args.ac = argc;
	args.line_number = 0;
	if (args.ac != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	data.fptr = fopen(args.av, "r");
	if (!data.fptr)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, args.av);
		exit(EXIT_FAILURE);
	}
	execute(&args);

	return (EXIT_SUCCESS);
}
