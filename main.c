#include "monty.h"

globals_t globals;

int main(int argc, char *argv[])
{
	instruction_t opcodes[] = {
		{"pall", pall},
		{NULL, NULL}
	};
	stack_t *stack;
	int i, j, len;
	unsigned int line_number;
	size_t n;
	char *token;

	stack = NULL;
	n = 0;
	len = 0;
	line_number = 0;
	globals.lineptr = NULL;
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
	while ((len = getline(&globals.lineptr, &n, globals.fp)) != EOF)
	{
		++line_number;
		token = strtok(globals.lineptr, " \n");
		/*
		printf("token start\n\n");
		printf("token is [%s]\n", token);
		*/
		if (!token)
			continue;
		if (!strcmp(token, "push"))
		{
			/*
			printf("Match found\n");
			*/
			token = strtok(NULL, " \n");
			/*
			printf("token match is [%s]\n", token);
			*/
			if (token)
			{
				for (j = 0; token[j]; ++j)
				{
					if (token[j] < '0' || token[j] > '9')
					{
						printf("L%d: usage: push integer\n", line_number);
						free(globals.lineptr);
						free_stack(stack);
						fclose(globals.fp);
						exit(EXIT_FAILURE);
					}
				}
				globals.data = atoi(token);
				push(&stack, line_number);
				/*
				printf("data is %d\n", globals.data);
				printf("token middle is %s\n", token);
				*/
				continue;
			}
			else
			{
				printf("L%d: usage: push integer\n", line_number);
				free(globals.lineptr);
				free_stack(stack);
				fclose(globals.fp);
				exit(EXIT_FAILURE);
			}
		}
		for (i = 0; opcodes[i].opcode; ++i)
		{
			if (!strcmp(token, opcodes[i].opcode))
			{
				token = strtok(NULL, " \n");
				opcodes[i].f(&stack, line_number);
				break;
			}
		}
		if (!opcodes[i].opcode)
		{
			printf("L%d: unknown instruction %s\n", line_number, token);
			free(globals.lineptr);
			free_stack(stack);
			fclose(globals.fp);
			exit(EXIT_FAILURE);
		}
		/*
		printf("token after is [%s]\n", token);
		*/
	}
	free(globals.lineptr);
	free_stack(stack);
	fclose(globals.fp);
	return (EXIT_SUCCESS);
}
