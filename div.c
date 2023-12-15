#include "monty.h"

/**
 * div_op - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 *
 * Description:
 *   - If the stack contains less than two elements, prints an error message
 *     and exits with EXIT_FAILURE.
 *   - If the top element of the stack is 0, prints an error message
 *     and exits with EXIT_FAILURE.
 *   - Otherwise, divides the value of the second top element by the
 *     top element of the stack.
 *   - The result is stored in the second top element of the stack, and
 *     the top element is removed.
 * Code by LINUS OBURA @ ALX
 */

void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;

	temp = *stack;
	*stack = temp->next;

	if (*stack)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}
