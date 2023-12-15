#include "monty.h"
/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 *
 * Description:
 *   - If the stack is empty, prints an error message and exits.
 *   - Otherwise, removes the top element of the stack.
 * Code by LINUS OBURA @ ALX
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(-1);
	}

	temp = *stack;
	*stack = temp->next;

	if (*stack)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}
