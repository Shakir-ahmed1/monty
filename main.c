#include "monty.h"
char *commands;
void executer(stack_t **stack)
{
	unsigned int len, i, j;
	char *command;
instruction_t instructions[] = {
	{"push", push},
	{"pall", pall}
};
	len = line_count();
	for (i = 1; i < len; i++)
	{
		command = get_command(i);
		for (j = 0; j < CMD_COUNT; j++)
		{
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
	int fd, fdr;
	stack_t *head;

	commands = malloc(sizeof(char)*10000);
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY); 
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	fdr = read(fd, commands, 10000);
	if (fdr == -1)
	{
		fprintf(stderr, "Error: Can't read file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	head = NULL;
	executer(&head);
	return (0);	
}
