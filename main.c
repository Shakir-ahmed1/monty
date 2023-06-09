#include "monty.h"
char *commands;
/**
 * inst_len - calculates the number of instructions possible
 * @inst: the instruction array
 * Return: the number of instructions
 */
int inst_len(instruction_t *inst)
{
	int i;
	for (i = 0; inst[i].opcode != NULL;)
		i++;
	return i;	
}
/**
 * executer - it executes the commands in a file
 * @stack: the head of the stack
 */
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
	{"rotl", rotl},
	{"rotr", rotr},
	{"stack", stackmode},
	{"queue", queuemode},
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
/**
 * main - entry point
 * @argc: number of  argumnts passed by the program
 * @argv: the arguments passed by the program
 * Return: always 0
 */

int main (int argc, char *argv[])
{
	int fd, fdr, i;
	stack_t *head;

	commands = malloc(sizeof(char)*40000);

	if (commands == NULL)
		error_handler(ERR_MALLOC, 0);
	for(i = 0; i < 40000; i++)
		commands[i] = 0;
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
	fdr = read(fd, commands, 40000);
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
