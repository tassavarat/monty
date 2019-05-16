#include "monty.h"

/**
 * swap -  swaps the top two elements of the stack..
 * @stack: pointer to a pointer of first node
 * @line_number: the line number in the file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr,"L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	tmp = (*stack)->next;

	(*stack)->n = tmp->n;
	tmp->n = num;
}

/**
 * add - Prints all elements of a linked list
 * @stack: Pointer to pointer to first node of linked list
 * @line_number: the line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr,"L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;

	(*stack)->n += tmp->n;
	free(tmp);
	(*stack)->prev = NULL;
}
