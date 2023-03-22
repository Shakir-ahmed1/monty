#include "monty.h"
char *commands;
/**
 * pushs - performes push at the stack
 * stack - the pointer to the tack
 * line_number - the line number in the given monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp;

	if (stack == NULL)
	{
		fprintf(stderr, "Error: invalid stack\n");
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc faliled\n");
		exit(EXIT_FAILURE);
	}
	new->n = get_number(line_number);
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	else
	{
		temp = (*stack)->next;
		new->prev = *stack;
		new->next = temp;
		if (tmp)
			temp->prev = new;
		(*stack)->next = new;
		return;
	}
}
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
	{
		fprintf(stderr, "Error: invalid stack\n");
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
