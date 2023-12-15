#include "monty.h"
/**
 * nop - Does nothing.
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 *
 * Description:
 *   - The nop function does nothing and serves as a placeholder opcode.
 *   - It takes the stack and line number as parameters but does not perform
 *     any operations on the stack.
 * Code by LINUS OBURA @ ALX
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
    /* Do nothing */
}
