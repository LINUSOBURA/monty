#include "monty.h"

/**
 * main - Entry point of the Monty interpreter program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Description:
 *   - The main function serves as the entry point for the Monty interpreter.
 *   - It takes command-line arguments specifying the Monty bytecode file.
 *   - The function opens the specified file, reads its content, and interprets
 *     the Monty bytecode instructions.
 *   - The stack is initialized, and each line of the
 *		bytecode file is processed
 *     by calling the process_line function.
 *   - After interpreting the bytecode, the function closes the file, frees
 *     allocated memory, and exits with a success or failure status.
 *
 * Return:
 *   - EXIT_SUCCESS: The program executed successfully.
 *   - EXIT_FAILURE: An error occurred during execution.
 * Code by LINUS OBURA @ ALX
 */
int main(int argc, char *argv[])
{
	FILE *monty_file;
	char *line = NULL;
	stack_t *stack;
	size_t len = 0, line_len;
	unsigned int line_number = 0;
	char *filename;

	filename = argv[0];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", filename);
		return (EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	stack = NULL;

	while (getline(&line, &len, monty_file) != -1)
	{
		line_number++;

		line_len = strlen(line);/* Remove newline character if present */
		if (line_len > 0 && line[line_len - 1] == '\n')
		{
			line[line_len - 1] = '\0';
		}

		process_line(line, &stack, line_number);
	}

	fclose(monty_file);
	free(line);

    /* Free any remaining nodes in the stack */
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
