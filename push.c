#include "monty.h"
/**
 * push_ - pushes a new node to the stack
 * @head_node: pointer to pointer to the head node 
 * @line_number: line number
 */
void push_(stack_t **head_node, unsigned int line_number)
{
	int i, k;

	if (glob_var.token_2 == NULL)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "usage: push integer\n");
		free_globvar();
		exit(EXIT_FAILURE);
	}

	for (k = 0; glob_var.token_2[k] != '\0'; k++)
        {
		if (glob_var.token_2[k] != '-' && !isdigit(glob_var.token_2[k]))
		{
			dprintf(2, "L%u: ", line_number);
			dprintf(2, "usage: push integer\n");
			free_globvar();
			exit(EXIT_FAILURE);
		}
	}

	i = atoi(glob_var.token_2);

	if (glob_var.is_stack == 0)
		add_dnodeint(head_node, i);
}
