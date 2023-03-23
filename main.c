#include "monty.h"
char *commands;

void executer(stack_t **stack)
{
	unsigned int len = 0, i, j;
	char *command;
instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"nop", nop},
	{"pint", pint},
	{NULL,NULL}
};
	len = line_count(commands);
	for (i = 1; i < len; i++)
	{
		command = get_command(i);
		for (j = 0; j < CMD_COUNT; j++)
		{
		/*	printf("=%s=",command);*/
			if (strcmp(instructions[j].opcode, command) == 0)
			{
				free(command);
				break;
			}
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
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		free(commands);
		exit(EXIT_FAILURE);
	}
	fdr = read(fd, commands, 10000);
	if (fdr == -1)
	{
		fprintf(stderr, "Error: Can't read file %s", argv[1]);
		free(commands);
		exit(EXIT_FAILURE);
	}
	head = NULL;
	executer(&head);
	free(commands);
	free_stack(head);
	return (0);	
}
