#include "monty.h"

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
	while (temp && temp->n != 0 && ((*stack)->n < 127 && ((*stack)->n > 0)))
	{
		printf("%c",temp->n);
		temp = temp->next;
	}
	printf("\n");
}
