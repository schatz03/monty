#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_m - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_m
{
		int n;
		struct stack_m *prev;
		struct stack_m *next;
} stack_m;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_m
{
		char *opcode;
		void (*f)(stack_m **stack, unsigned int line_number);
} instruction_m;

typedef struct OPCODEarg {
    char *arg;
    char *op_code;
    char *content;
} OPCODEarg;
OPCODEarg op_code_and_arg;
instruction_m* create_instructions();
int _isdigit(char *str);
void trim(char *str);
int _parse_opcode(char *line, stack_m **stack, unsigned int line_number);
void fill_instructions(instruction_m* instructions);
void free_instructions(instruction_m* instructions);
void free_stack(stack_m *head);
/* Function declarations */
int process_opcodes(FILE *file, instruction_m *instructions);
void push(stack_m **stack, unsigned int line_number);
void pall(stack_m **stack, unsigned int line_number);
#endif
