#include "monty.h"

/**
 * get_instruction - Retrieves the corresponding instruction structure
 *                   for a given opcode
 * @opcode: The opcode for which to retrieve the instruction
 *
 * Description:
 *   - The get_instruction function searches for the instruction associated
 *     with a given opcode within the instructions array.
 *   - The function takes an opcode as a parameter and iterates through the
 *     instructions array, comparing opcodes until a match is found.
 *   - If a match is found, a pointer to the corresponding instruction
 *     structure is returned; otherwise, NULL is returned.
 *
 * @opcode: A string representing the opcode to search for.
 *
 * Return:
 *   - On success, a pointer to the instruction_t structure.
 *   - On failure (opcode not found), returns NULL.
 *	Code by LINUS OBURA @ ALX
 */

instruction_t *get_instruction(char *opcode)
{
    /* Example: linear search */
	int i;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (&instructions[i]);
	}

	return (NULL); /* Opcode not found */
}
