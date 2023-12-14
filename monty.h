#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct glob_val - Structure to hold global values.
 * @fd: Pointer to a FILE structure.
 * @buff: Pointer to a character buffer.
 *
 * Description:
 * The `glob_val` structure is designed to store global values
 * that need to be accessed across multiple functions or files
 * It includes a FILE pointer
 * (`fd`) for file-related operations and a character pointer (`buff`) for
 * managing character data.
 *
 * This structure is declared globally using the name `glob_nod`.
 */
typedef struct glob_val
{
FILE *fd;
char *buff;
} glob_val;


extern glob_val glob_nod;

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
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void val_free(glob_val *glob_nod);
void read_line(stack_t **, unsigned int, int *);
void map_ope(stack_t **, char *, unsigned int);
void check_integer(stack_t **, char *, unsigned int);
int cust_isdigit(int c);
void push_node_stack(stack_t **, int);
void push_node_queue(stack_t **, int);
void push_ope(stack_t **, int, int);

void print_all(stack_t **, unsigned int);
void print_stack(stack_t **, unsigned int);

void pop_stack(stack_t **, unsigned int);
void nop_stack(stack_t **, unsigned int);
void swap_stack(stack_t **, unsigned int);
void add_elements(stack_t **, unsigned int);

void free_stk(stack_t **);

#endif
