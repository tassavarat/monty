#include "monty.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a list
 * @stack: Pointer to pointer of first node
 * @n: Integer to store in node
 *
 * Return: Address of new element or NULL on failure
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
 * print_dlistint - Prints all elements of a linked list
 * @h: Pointer to first node of linked list
 *
 * Return: Number of nodes
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
 * free_dlistint - Frees a list
 * @head: Pointer to list being freed
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
