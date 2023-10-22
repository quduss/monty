#include "monty.h"
/**
 * mul_ - multiplies the second top element of the stack by the top
 * element of the stack
 * @head_node: pointer to pointer to the head node of the stack
 * @line_number: line number of the div opcode in the file
 */

void mul_(stack_t **head_node, unsigned int line_number)
{
	int mul;
	stack_t *first_node, *second_node;

	if (!(*head_node && (*head_node)->next))
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first_node = *head_node;
	second_node = (*head_node)->next;
	mul = second_node->n * first_node->n;
	free(first_node);
	second_node->prev = NULL;
	second_node->n = mul;
	*head_node = second_node;
}
