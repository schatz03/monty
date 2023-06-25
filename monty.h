#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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
 * @f: handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_m **stack, unsigned int line_number);
} instruction_m;

extern stack_m *head;
typedef void (*exec_m)(stack_m **, unsigned int);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);
stack_m *create_node(int n);
void free_nodes(void);
void _pall(stack_m **, unsigned int);
void _push(stack_m **, unsigned int);
void add_to_queue(stack_m **, unsigned int);

void call_fun(exec_m, char *, char *, int, int);

void _rev_pall(stack_m **, unsigned int);
void _pop(stack_m **, unsigned int);
void _nop(stack_m **, unsigned int);
void _swap(stack_m **, unsigned int);
void _add(stack_m **, unsigned int);
void _sub(stack_m **, unsigned int);
void _div(stack_m **, unsigned int);
void _mul(stack_m **, unsigned int);
void _mod(stack_m **, unsigned int);

void _pallchar(stack_m **, unsigned int);
void _pallstr(stack_m **, unsigned int);
void _rotl(stack_m **, unsigned int);

void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);
void _rotr(stack_m **, unsigned int);

#endif
