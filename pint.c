#include "monty.h"
/**
 * pint_ - prints the value at the top of the stack
 * @head_node: pointer to pointer to head node of the list
 * @line_number: line number of the pint opcode
 */
void pint_(stack_t **head_node, unsigned int line_number __attribute__((unused)))
{
	if (!(*head_node))
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "can't pint, stack empty\n");
		free_globvar();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head_node)->n);
}
