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
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
		error_handler(ERR_POP, line_number);
	temp = *stack;
	if (temp->next == NULL)
	{
		free(temp);
		*stack = NULL;
		return;
	}	
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}
void swap(stack_t **stack, unsigned int line_number)
{
	int i;
	if (*stack == NULL)
		error_handler(ERR_SWAP, line_number);
	if ((*stack)->next == NULL)
	{
		free(*stack);
		error_handler(ERR_SWAP, line_number);
	}
	i = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = i;
}
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		error_handler(ERR_ADD, line_number);
	if ((*stack)->next == NULL)
	{
		free(*stack);
		error_handler(ERR_ADD, line_number);
	}
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
}
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		error_handler(ERR_SUB, line_number);
	if ((*stack)->next == NULL)
	{
		free(*stack);
		error_handler(ERR_SUB, line_number);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
}
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		error_handler(ERR_MUL, line_number);
	if ((*stack)->next == NULL)
	{
		free(*stack);
		error_handler(ERR_MUL, line_number);
	}
	(*stack)->next->n = (*stack)->n * (*stack)->next->n;
	pop(stack, line_number);
}
void divv(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		error_handler(ERR_DIV, line_number);
	if ((*stack)->next == NULL)
	{
		free(*stack);
		error_handler(ERR_DIV, line_number);
	}
	if ((*stack)->n == 0)
		error_handler(ERR_ZERO, line_number);
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
}
