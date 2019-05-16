#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: pointer to a pointer of first node
 * @line_number: the line number in the file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
		error_handle(stack, line_number, 3);
	num = (*stack)->n;
	tmp = (*stack)->next;

	(*stack)->n = tmp->n;
	tmp->n = num;
}

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to pointer to first node of linked list
 * @line_number: the line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
		error_handle(stack, line_number, 4);
	tmp = *stack;
	*stack = (*stack)->next;

	(*stack)->n += tmp->n;
	free(tmp);
	(*stack)->prev = NULL;
}
