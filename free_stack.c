#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @stack: head of the stack
*/

void free_stack(stack_t **stack)
{
	stack_t *current, *next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
