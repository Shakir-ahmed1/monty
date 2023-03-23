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
	int i;

	i = get_number(line_number, stack);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free_stack(*stack);
		error_handler(ERR_MALLOC, line_number);
	}
	new->n = i;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	(*stack) = new;
}
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		error_handler(ERR_EMPTYSTACK, line_number);
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
