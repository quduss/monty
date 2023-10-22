#include "monty.h"
/**
 * add_ - adds the top two elements of the stack
 * @head_node: pointer to pointer to the head node of the stack
 * @line_number: line number of the add opcode in the file
 */

void add_(stack_t **head_node, unsigned int line_number)
{
	int sum;
	stack_t *first_node, *second_node;

	if (!(*head_node && (*head_node)->next))
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first_node = *head_node;
	second_node = (*head_node)->next;

	sum = first_node->n + second_node->n;
	second_node->n = sum;
	second_node->prev = NULL;
	free(first_node);
	*head_node = second_node;
}
