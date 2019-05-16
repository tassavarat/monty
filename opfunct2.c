#include "monty.h"

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
