#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 *
 * Description:
 *   - If the stack contains less than two elements, prints an error message
 *     and exits with EXIT_FAILURE.
 *   - Otherwise, swaps the values of the top two elements of the stack.
 * Code by LINUS OBURA @ ALX
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(-1);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
