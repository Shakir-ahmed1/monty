#include "monty.h"
unsigned int line_count()
{
	unsigned int j = 0, i = 1;

	while (commands[j] != '\0')
	{
		if (commands[j] == '\n')
			i++;
		j++;
	}
	return i;
}
unsigned int line_manager(unsigned int line)
{
	int i = 0;
	unsigned int j = 1;

	while (commands[i] != '\0' && j < line)
	{
		i++;
		if (commands[i] == '\n')
			j++;
	}
	if (commands[i] == '\0')
		return (0);
	if (commands[i] != '\0' && commands[i + 1] != '\0' && i != 0) 
		i++;
	return (i);
}
/**
 * get_command - it extracts the command
 * @line: the line to extract from
 * Return: the command name
 */
char *get_command(unsigned int line, stack_t **stack)
{
	unsigned int i = 1;
	char *cmd;
	char *temp;

	temp = commands;
	while (i < line && *temp != '\0')
	{
		if (*temp == '\n')
			i++;
		temp++;
	}
	cmd = malloc(sizeof(char) * 16);
	if (cmd == NULL)
	{
		free_stack(*stack);
		error_handler(ERR_MALLOC, line);
	}
	if (*temp == '#')
	{
		cmd[0] = 'n';
		cmd[1] = 'o';
		cmd[2] = 'p';
		cmd[3] = '\0';
		return (cmd);
	}

	while (*temp == ' ')
	{
		temp++;
	}

	if (*temp == '\n')
	{
		cmd[0] = 'n';
		cmd[1] = 'o';
		cmd[2] = 'p';
		cmd[3] = '\0';
		return (cmd);
	}
	i = 0;

	while ((*temp != ' ' && *temp != '\n') && i < 16)
	{
		cmd[i] = *temp;
		temp++;
		i++;
	}

	cmd[i] = '\0';
	return (cmd);
}
/**
 * get_number - it extracts the command
 * @line: the line to extract from
 * Return: the command name
 */
int get_number(unsigned int line, stack_t **stack)
{
	unsigned int i = 1, j = 0, condition = 0;
	int result = 0;
	char *cmd, *temp, hold[21];

	temp = commands;

	while (i < line && *temp != '\0')
	{
		if (*temp == '\n')
			i++;
		temp++;
	}
	while (*temp == ' ')
		temp++;
	if (*temp == '\n')
	{
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	cmd = malloc(sizeof(char) * 16);
	if (cmd == NULL)
	{
		free_stack(*stack);
		error_handler(ERR_MALLOC, 0);
	}
	i = 0;
	while ((*temp != ' ' && *temp != '\n') && i < 16)
	{
		temp++;
		i++;
	}
	if (*temp == '\n')
	{
		free(cmd);
		free_stack(*stack);
		error_handler(ERR_PUSH, line);
	}
	while (*temp == ' ')
		temp++;
	i = 0;
	while ((*temp != ' ' && *temp != '\n') && i < 16)
	{
		cmd[i] = *temp;
		temp++;
		i++;
	}
	cmd[i] = '\0';
	for (j = 0; j < 10; j++)
	{
		if (cmd[0] == ('0' + (char) j) || (cmd[1] == ('0' + (char) j) && cmd[0] == '-'))
			condition = 1;
	}
	sprintf(hold, "%d", atoi(cmd));
	if (strlen(cmd) != strlen(hold))
		condition = 0;
	if (cmd[0] == '-' && cmd[1] == '0')
		condition = 1;
	if (condition == 0)
	{
		free(cmd);
		free_stack(*stack);
		error_handler(ERR_PUSH, line);
	}
	result = atoi(cmd);

	free(cmd);
	return (result);
}
