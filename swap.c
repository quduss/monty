#include "monty.h"
/**
 * swap_ - swaps the top two elements of the stack
 * @head_node: pointer to pointer to head node of the stack
 * @line_number: line number of the swap opcode in the file
 */

void swap_(stack_t **head_node, unsigned int line_number)
{
	stack_t *first_node, *second_node, *third_node;

	if (!(*head_node && (*head_node)->next))
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first_node = *head_node;
	second_node = first_node->next;
	third_node = second_node->next;

	first_node->next = third_node;
	first_node->prev = second_node;
	second_node->next = first_node;
	second_node->prev = NULL;
	if (third_node != NULL)
		third_node->prev = first_node;
	*head_node = second_node;
}
