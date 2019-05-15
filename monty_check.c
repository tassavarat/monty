#include "monty.h"

void error_handle(stack_t **stack, unsigned int line_number, int error_type)
{
	if (error_type == 0)
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
	if (error_type == 1)
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, globals.token);
	free(globals.lineptr);
	free_stack(*stack);
	fclose(globals.fp);
	exit(EXIT_FAILURE);
}
void check_op(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"pall", pall},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opcodes[i].opcode; ++i)
	{
		if (!strcmp(globals.token, opcodes[i].opcode))
		{
			globals.token = strtok(NULL, " \n");
			opcodes[i].f(stack, line_number);
			break;
		}
	}
	if (!opcodes[i].opcode)
		error_handle(stack, line_number, 1);
}
void parse_arg(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	globals.fp = fopen(argv[1], "r");
	if (!globals.fp)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}
void read_line(stack_t **stack)
{
	int j, len;
	unsigned int line_number;
	size_t n;

	len = 0;
	line_number = 0;
	n = 0;
	globals.lineptr = NULL;
	while ((len = getline(&globals.lineptr, &n, globals.fp)) != EOF)
	{
		++line_number;
		globals.token = strtok(globals.lineptr, " \n");
		if (!globals.token)
			continue;
		if (!strcmp(globals.token, "push"))
		{
			globals.token = strtok(NULL, " \n");
			if (globals.token)
			{
				for (j = 0; globals.token[j]; ++j)
					if (globals.token[j] < '0' || globals.token[j] > '9')
						error_handle(stack, line_number, 0);
				globals.data = atoi(globals.token);
				push(stack, line_number);
				continue;
			}
			else
				error_handle(stack, line_number, 0);
		}
		check_op(stack, line_number);
	}
}
