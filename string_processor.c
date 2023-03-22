#include "monty.h"
unsigned int line_count()
{
	int i = 1, j = 0;

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
char *get_command(unsigned int line)
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
	while (*temp == ' ')
	{
		temp++;
	}
	if (*temp == '\n')
		return (NULL);
	cmd = malloc(sizeof(char) * 16);
	if (cmd == NULL)
		return (NULL);
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
int get_number(unsigned int line)
{
	unsigned int i = 1;
	int result = 0;
	char *cmd;
	char *temp;

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
		exit(EXIT_FAILURE);
	cmd = malloc(sizeof(char) * 16);
	if (cmd == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while ((*temp != ' ' && *temp != '\n') && i < 16)
	{
		temp++;
		i++;
	}
	if (*temp == '\n')
		exit(EXIT_FAILURE);
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
	result = atoi(cmd);
	free(cmd);
	return (result);
}
/*
int main(void)
{
	printf("==%d==\n",get_number(0));
	return (0);
}
*/
