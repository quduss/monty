#include "monty.h"
/**
 * div_ - divides the second top element of the stack by the top
 * element of the stack
 * @head_node: pointer to pointer to the head node of the stack
 * @line_number: line number of the div opcode in the file
 */

void div_(stack_t **head_node, unsigned int line_number)
{
	int div;
	stack_t *first_node, *second_node;

	if (!(*head_node && (*head_node)->next))
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first_node = *head_node;
	second_node = (*head_node)->next;
	if (first_node->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = second_node->n / first_node->n;
	free(first_node);
	second_node->prev = NULL;
	second_node->n = div;
	*head_node = second_node;
}
