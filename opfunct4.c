#include "monty.h"

/**
 * rotr - Rotates the stack to the top.
 * @stack: Pointer to pointer to first node of linked list
 * @line_number: the line number in the file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if ((*stack) && (*stack)->next)
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		(*stack)->prev = tmp->next;
		tmp->next->next = *stack;
		tmp->next->prev = NULL;
		tmp->next = NULL;
	}
}
