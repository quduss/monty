#include "monty.h"
/**
 * free_list - frees the doubly linked list
 * @head_node: pointer to head node of the list
 */
void free_list(stack_t *head_node)
{
	stack_t *ptr;

	while ((ptr = head_node) != NULL)
	{
		head_node = head_node->next;
		free(ptr);
	}
}
