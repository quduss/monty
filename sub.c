#include "monty.h"
/**
 * sub_ - subtracts the top element of the stack from the second top
 * element of the stack
 * @head_node: pointer to pointer to the head node of the stack
 * @line_number: line number of the sub opcode in the file
 */

void sub_(stack_t **head_node, unsigned int line_number)
{
	int sub;
	stack_t *first_node, *second_node;

	if (!(*head_node && (*head_node)->next))
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first_node = *head_node;
	second_node = (*head_node)->next;
	sub = second_node->n - first_node->n;
	free(first_node);
	second_node->prev = NULL;
	second_node->n = sub;
	*head_node = second_node;
}
