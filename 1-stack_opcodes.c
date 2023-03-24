#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		error_handler(ERR_PCHAR, line_number);
	if ((*stack)->n > 127 || ((*stack)->n < 0))
	{
		free_stack(*stack);
		error_handler(ERR_PCHARANGE, line_number);
	}
	printf("%c\n",(*stack)->n);
}
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	temp = *stack;
	while (temp && temp->n != 0 && temp->n <= 127 && temp->n >= 0)
	{
		printf("%c",temp->n);
		temp = temp->next;
	}
	printf("\n");
}
/**
 * rotl - rotates the stack to the top
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp1;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp1 = *stack;
	temp->next = temp1;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	temp1->prev = temp;
	temp1->next = NULL;
}
/**
 * rotr - it makes the stack to the bottom
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;

	*stack = temp;

}
/**
 * stackmode - it is a filler for stack mode
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
void stackmode(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * queuemode - it is a filler for queue mode
 * @stack: the pointer to the stack
 * @line_number: the line number in the given monty file
 */
void queuemode(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
