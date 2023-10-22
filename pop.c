#include "monty.h"
/**
 * pop_ - deletes the first element in the stack
 * @head_node: pointer to pointer to head node of the stack
 * @line_number: line number of the pop opcode
 */
void pop_(stack_t **head_node, unsigned int line_number)
{
	stack_t *ptr;

	if (!(*head_node))
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		free_globvar();
		exit(EXIT_FAILURE);
	}
	ptr = *head_node;
	*head_node = (*head_node)->next;
	free(ptr);
}
