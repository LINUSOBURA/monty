#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 *
 * Description:
 *   - If the stack contains less than two elements, prints an error message
 *     and exits with EXIT_FAILURE.
 *   - Otherwise, subtracts the value of the top element from the
 *     second top element of the stack.
 *   - The result is stored in the second top element of the stack, and
 *     the top element is removed.
 * Code by LINUS OBURA @ ALX
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(-1);
	}

    (*stack)->n -= (*stack)->next->n;

    temp = *stack;
    *stack = temp->next;
    (*stack)->prev = NULL;
}
