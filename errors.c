#include "monty.h"
void error_handler(int a, int li)
{
	if (a == ERR_MALLOC)
		fprintf(stderr,"Error: malloc failed\n");
	else if (a == ERR_PUSH)
		fprintf(stderr,"L%d: usage: push integer\n", li);
	else if (a == ERR_EMPTYSTACK)
		fprintf(stderr,"L%d: can't pint, stack empty\n", li);
	else if (a == ERR_POP)
		fprintf(stderr,"L%d: can't pop an empty stack\n", li);
	else if (a == ERR_SWAP)
		fprintf(stderr,"L%d: can't swap, stack too short\n", li);
	else if (a == ERR_ADD)
		fprintf(stderr,"L%d: can't add, stack too short\n", li);
	else if (a == ERR_SUB)
		fprintf(stderr,"L%d: can't sub, stack too short\n", li);
	else if (a == ERR_DIV)
		fprintf(stderr,"L%d: can't div, stack too short\n", li);
	else if (a == ERR_MUL)
		fprintf(stderr,"L%d: can't mul, stack too short\n", li);
	else if (a == ERR_MOD)
		fprintf(stderr,"L%d: can't mod, stack too short\n", li);
	else if (a == ERR_PCHAR)
		fprintf(stderr,"L%d: can't pchar, stack empty\n", li);
	else if (a == ERR_ZERO)
		fprintf(stderr,"L%d: division by zeo\n", li);
	free(commands);
	exit(EXIT_FAILURE);
}
