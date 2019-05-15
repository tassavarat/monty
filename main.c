#include "monty.h"

globals_t globals;

int main(int argc, char *argv[])
{
	stack_t *stack;

	stack = NULL;
	parse_arg(argc, argv);
	read_line(&stack);
	free(globals.lineptr);
	free_stack(stack);
	fclose(globals.fp);
	return (EXIT_SUCCESS);
}
