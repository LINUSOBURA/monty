#include "monty.h"
/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 *
 * Description:
 *   - If the stack is empty, prints an error message and exits.
 *   - Otherwise, prints the value at the top of the stack.
 * Code by LINUS OBURA @ ALX
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(-1);
	}

	printf("%d\n", (*stack)->n);
}
