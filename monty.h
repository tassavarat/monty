#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * struct globals_s - struct contains global variables.
 * @data: value to initialize nodes.
 * @fp: a file pointer.
 * @lineptr: pointer to a dynamic buffer.
 * @token: a pointer to the next token.
*/
typedef struct globals_s
{
	int data;
	FILE *fp;
	char *lineptr, *token;
} globals_t;

extern globals_t globals;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* opfunct1 */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

/* monty_check */
void error_handle(stack_t **stack, unsigned int line_number, int error_type);
void check_op(stack_t **stack, unsigned int line_number);
void parse_arg(int argc, char *argv[]);
void read_line(stack_t **stack);

#endif /* MONTY_H */
