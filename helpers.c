#include "monty.h"

/**
 * _isdigit - checks if a string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int _isdigit(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * trim - Trim leading and trailing spaces from a string
 * @str: The string to trim
 * Description: This function removes
 * leading and trailing spaces from a string.
 */
void trim(char *str)
{
	char *end, *start;

	start = str;
	while (isspace(*start))
		start++;

	end = str + strlen(str) - 1;
	while (end > start && isspace(*end))
		end--;

	*(end + 1) = '\0';
	memmove(str, start, strlen(start) + 1);
}

/**
 * _parse_opcode - parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 * Return: int
 */
int _parse_opcode(char *line, stack_m **stack, unsigned int line_number)
{
	char *opcode, *firstWord, *arguments, *push;

	(void)stack;
	push = "push";
	line[strcspn(line, "\n")] = '\0';
	if (strlen(line) == 0)
		return (0);

	firstWord = line;
	while (isspace(*firstWord))
		firstWord++;

	opcode = strtok(firstWord, " ");
	if (opcode != NULL)
	{
		trim(opcode);
		if (strlen(opcode) == 0)
			return (0);
		op_code_and_arg.op_code = opcode;
		arguments = strtok(NULL, " ");

		if (arguments != NULL)
		{
			if (_isdigit(arguments) != 1 && strcmp(opcode, push) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			trim(arguments);
			op_code_and_arg.arg = atoi(arguments);
		}
		return (1);
	}
	return (0);
}
