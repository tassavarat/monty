#include "monty.h"

int data;

int main(int argc, char *argv[])
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	stack_t *stack;
	FILE *fp;
	int i, len;
	unsigned int line_number;
	size_t n;
	char *lineptr, *token, *tmp;

	stack = NULL;
	n = 0;
	len = 0;
	line_number = 1;
	lineptr = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((len = getline(&lineptr, &n, fp)) != EOF)
	{
		token = strtok(lineptr, " \n");
		/*
		printf("token start\n\n");
		*/
		/*printf("token is [%s]\n", token);*/
		if (!token)
			continue;
		for (i = 0; opcodes[i].opcode; ++i)
		{
			if (!strcmp(token, opcodes[i].opcode))
			{
				/*printf("match found\n");*/
				token = strtok(NULL, " \n");
				if (token)
				{
					data = atoi(token);
					/*printf("data is %d\n", data);*/
					/*printf("token middle is %s\n", token);*/
				}
				opcodes[i].f(&stack, line_number);
			}
		}
		/*
		printf("token after is [%s]\n", token);
		*/
		++line_number;
	}
	/*
	   for (i = 0; opcodes[i].opcode; ++i)
	   {
	   if (!strcmp(token, opcodes[i].opcode))
	   {
	   printf("match found\n");
	   opcodes[i].f(&stack, line_number);
	   }
	   }
	   */
	/*
	   stack = NULL;

	   data = 2;
	   push(&stack, 1);
	   data = 4;
	   push(&stack, 2);
	   data = 6;
	   push(&stack, 3);
	   data = 8;
	   pall(&stack, 4);
	   printf("data is %d\n", data);
	   */
	return (EXIT_SUCCESS);
}
