#include "monty.h"

/**
 * push - Adds a new node at the beginning of a list
 * @stack: Pointer to pointer of first node.
 * @line_number: the line number in the file.
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed\n");
		free(globals.lineptr);
		free_stack(*stack);
		fclose(globals.fp);
		exit(EXIT_FAILURE);
	}

	new->n = globals.data;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - Prints all elements of a linked list
 * @stack: Pointer to pointer to first node of linked list
 * @line_number: the line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * free_stack - Frees a list
 * @stack: Pointer to pointer of first node.
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
