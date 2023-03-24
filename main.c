#include "monty.h"
char *commands;
int inst_len(instruction_t *inst)
{
	int i;
	for (i = 0; inst[i].opcode != NULL;)
		i++;
	return i;	
}
void executer(stack_t **stack)
{
	unsigned int len = 0, i, j, len1;
	char *command;

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"sub", sub},
	{"mul", mul},
	{"div", divv},
	{"mod", mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{"nop", nop},
	{NULL,NULL}
};
	len1 = inst_len(instructions);
	len = line_count(commands);
	for (i = 1; i < len; i++)
	{
		command = get_command(i, stack);
		for (j = 0; instructions[j].opcode != NULL; j++)
		{
		/*	printf("=%s=",command);*/
			if (strcmp(instructions[j].opcode, command) == 0)
			{
				free(command);
				break;
			}
		}
		if (j == len1)
		{
		fprintf(stderr, "L%d: unknown instruction %s\n", i, command);
		free(commands);
		free(command);
		exit(EXIT_FAILURE);
		}
		instructions[j].f(stack, i);
	}
}
int main (int argc, char *argv[])
{
	int fd, fdr, i;
	stack_t *head;

	commands = malloc(sizeof(char)*10000);

	for(i = 0; i < 1000; i++)
		commands[i] = 0;
	if (!commands)
		error_handler(ERR_MALLOC, 0);
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free(commands);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY); 
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(commands);
		exit(EXIT_FAILURE);
	}
	fdr = read(fd, commands, 10000);
	if (fdr == -1)
	{
		fprintf(stderr, "Error: Can't read file %s\n", argv[1]);
		free(commands);
		exit(EXIT_FAILURE);
	}
	head = NULL;
	executer(&head);
	free(commands);
	free_stack(head);
	return (0);
}
