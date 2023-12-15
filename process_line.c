#include "monty.h"

/**
 * process_line - Processes a line of Monty bytecode
 * @line: The line of Monty bytecode to be processed
 * @stack: A pointer to the head of the stack
 * @line_number: The line number in the Monty bytecode file
 *
 * Description:
 *   - The process_line function tokenizes the input line to extract the
 *     opcode and argument (if present) from the Monty bytecode.
 *   - It then obtains the corresponding instruction structure using the
 *     get_instruction function and executes the associated function.
 *   - If the opcode is not recognized, an error message is printed to stderr,
 *     indicating the unknown instruction, and the program exits with failure.
 *   - The argument, if present, is not used directly in this function, and
 *     memory allocated for it (if any) is not freed here.
 *	Code by LINUS OBURA @ ALX
 */
void process_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode, *arg;
	instruction_t *instruction;

    /* Tokenize the line to get opcode and argument */
	opcode = strtok(line, " ");
	arg = strtok(NULL, " ");

	if (!opcode || *opcode == '#')
	{
		return; /* Ignore empty lines and comments */
	}

	(void)arg;
	instruction = get_instruction(opcode);

	if (!instruction)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(-1);
	}

    /* Call the function associated with the opcode */
	instruction->f(stack, line_number);
}
