#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 *
 * Description:
 *   - If the stack contains less than two elements, prints an error message
 *     and exits with EXIT_FAILURE.
 *   - Otherwise, adds the values of the top two elements of the stack.
 *   - The result is stored in the second top element of the stack, and
 *     the top element is removed.
 * Code by LINUS OBURA @ ALX
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);
}
