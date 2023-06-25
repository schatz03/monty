#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_m;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_m **stack, unsigned int line_number);
} instruction_m;

/**
 * struct args_s - structure of arguments from main
 * @av: argument vector
 * @ac: argument counter
 * @line_number: number of the current line in the file
 *
 * Description: arguments passed to main from the command line
 * used in different functions, organized in a struct for clarity
 */
typedef struct args_s
{
	char *av;
	int ac;
	unsigned int line_number;
} args_m;

/**
 * struct data_s - extern data to access inside functions
 * @line: line from the file
 * @words: parsed line
 * @stack: pointer to the stack
 * @fptr: file pointer
 * @qflag: flag for queue or stack
 */
typedef struct data_s
{
	char *line;
	char **words;
	stack_m *stack;
	FILE *fptr;
	int qflag;
} data_m;

typedef stack_m dlistint_t;

extern data_m data;

#define DATA_INIT                 \
{                             \
	NULL, NULL, NULL, NULL, 0 \
}

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define _pint_FAIL "L%u: can't _pint, stack empty\n"
#define _pop_FAIL "L%u: can't _pop an empty stack\n"
#define _swap_FAIL "L%u: can't _swap, stack too short\n"
#define _add_FAIL "L%u: can't _add, stack too short\n"
#define _sub_FAIL "L%u: can't _sub, stack too short\n"
#define _div_FAIL "L%u: can't _div, stack too short\n"
#define _div_ZERO "L%u: _division by zero\n"
#define _mul_FAIL "L%u: can't _mul, stack too short\n"
#define _mod_FAIL "L%u: can't _mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_RANGE "L%u: can't pchar, value out of range\n"
/* main.c */
void execute(args_m *args);
/* fetch_func.c */
void (*get_instruction(char **parsed))(stack_m **, unsigned int);
void push(stack_m **stack, unsigned int line_number);
instruction_m *fill_instruction();
void _pall(stack_m **stack, unsigned int line_number);
/* funcs1.c */
void _pint(stack_m **stack, unsigned int line_number);
void _pop(stack_m **stack, unsigned int line_number);
void _swap(stack_m **stack, unsigned int line_number);
void _add(stack_m **stack, unsigned int line_number);
void _nop(stack_m **stack, unsigned int line_number);
/* funcs2.c */
void _sub(stack_m **stack, unsigned int line_number);
void _div(stack_m **stack, unsigned int line_number);
void _mul(stack_m **stack, unsigned int line_number);
void _mod(stack_m **stack, unsigned int line_number);
/* funcs3.c */
void _rotl(stack_m **stack, unsigned int line_number);
void _rotr(stack_m **stack, unsigned int line_number);
void stack(stack_m **stack, unsigned int line_number);
void queue(stack_m **stack, unsigned int line_number);
/* char.c */
void pchar(stack_m **stack, unsigned int line_number);
void pstr(stack_m **stack, unsigned int line_number);
/* strtow.c */
int wc(char *s);
char **strtow(char *str);
void free_everything(char **args);
/* free.c */
void free_instractions(int all);
/* dprintf */
int dprintf(int fd, const char *format, ...);
/* getline */
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
/* doubly linked list fuctions */
size_t dlistint_len(const dlistint_t *h);
dlistint_t *_add_dnodeint(dlistint_t **head, const int n);
size_t print_dlistint(const dlistint_t *h);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
dlistint_t *_add_dnodeint_end(dlistint_t **head, const int n);
void free_dlistint(dlistint_t *head);

#endif /* MONTY_H */
