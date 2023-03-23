#include "monty.h"
char *commands;
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * pushs - performes push at the stack
 * stack - the pointer to the tack
 * line_number - the line number in the given monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

/*	if (stack == NULL)
	{
		fprintf(stderr, "Error: invalid stack\n");
		exit(EXIT_FAILURE);
	}*/
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		error_handler(ERR_MALLOC, line_number);
	new->n = get_number(line_number);
	new->prev = NULL;
	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		if (*stack)
			(*stack)->prev = new;
		(*stack) = new;
/*		(*stack)->next = new;
		new->next = NULL;
		new->prev = *stack;
		(*stack) = new;*/
	}
}
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) temp;
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
void pint(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
		error_handler(ERR_EMPTYSTACK, line_number);
	printf("%d\n", (*stack)->n);
}
