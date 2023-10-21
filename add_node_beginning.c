#include "monty.h"
/**
 * add_dnodeint - adds a newnode at the begining of the linked list
 * @head_node: pointer to pointer to head node
 * @i: integer data of new node
 */
void add_dnodeint(stack_t **head_node, const int i)
{
	stack_t *ptr;

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globvar();
		exit(EXIT_FAILURE);
	}
	ptr->n = i;
	if (*head_node == NULL)
	{
		ptr->next = *head_node;
		ptr->prev = NULL;
		*head_node = ptr;
	}
	else
	{
		(*head_node)->prev = ptr;
		ptr->next = *head_node;
		ptr->prev = NULL;
		*head_node = ptr;
	}
}
