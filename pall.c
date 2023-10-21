#include "monty.h"
/**
 * pall_ - prints the integer n of each node on the stack
 * @head_node: pointer to pointer to head node of the linked list
 * @line_number: current line number in the bytecode file
 */
void pall_(stack_t **head_node, unsigned int line_number)
{
	stack_t *ptr = *head_node;
	(void)line_number;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
