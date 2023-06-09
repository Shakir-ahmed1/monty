#include "monty.h"
char *commands;
/**
 * nop - it ignores new lines comments
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * check_mode - checks whether the insert mode is stack mode or push
 * @stack: the pointer to the stack
 * @line: the line number in the given monty file
 * Return: the mode
 */
int check_mode(unsigned int line, stack_t **stack)
{
	unsigned int i = 0;
	int mode = 0;
	char *t;
	char st[] = "ack";
	char qu[] = "eue";

	if (line > 50)
		return (mode);
	for (i = 1; i < line; i++)
	{
		t = get_command(i,stack);
		if (strcmp(&t[2], st) == 0)
			mode = 0;
		if (strcmp(&t[2], qu) == 0)
			mode = 1;
		free(t);
	}
	return (mode);
}
/**
 * push - performes push at the stack
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp;
	int i;

	i = get_number(line_number, stack);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free_stack(*stack);
		error_handler(ERR_MALLOC, line_number);
	}
	new->n = i;
	if (check_mode(line_number, stack) == 0)
	{
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	(*stack) = new;
	}
	else
	{
		temp = *stack;
		if (*stack == NULL)
		{
			new->prev = NULL;
			*stack = new;
			return;
		}

		while (temp->next)
			temp = temp->next;
                new->next = NULL;
		temp->next = new;
		new->prev = temp;
	}

}
/**
 * pall - performes pall at the stack
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
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
/**
 * pint - prints the to element of the stack
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
void pint(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
		error_handler(ERR_EMPTYSTACK, line_number);
	printf("%d\n", (*stack)->n);
}
/**
 * pop - performes pop at the stack
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
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
/**
 * swap - performes swap at the stack
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
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
/**
 * add - performes addition of the top elements of the stack
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
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
/**
 * sub - performes subtraciton of the top elements of the stack
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
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
/**
 * mul - performes multiplication of the top elements of the stack
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
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
/**
 * divv - performes division of the top elements of the stack
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
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
/**
 * mod - performes modulus of the top elements of the stack
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		error_handler(ERR_MOD, line_number);
	if ((*stack)->next == NULL)
	{
		free(*stack);
		error_handler(ERR_MOD, line_number);
	}
	if ((*stack)->n == 0)
		error_handler(ERR_ZERO, line_number);
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
}
