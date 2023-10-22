#include "monty.h"
/**
 * get_opcs - selects the correct opcode to perform
 * @opcode: opc input
 * Return: the pointer to corresponding function to be called
 */
void (*get_opcs(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t opc_and_func_arr[] = {
		{"push", push_},
		{"pall", pall_},
		{"pint", pint_},
		{"pop", pop_},
		{NULL, NULL}
	};
	int j;

	for (j = 0; opc_and_func_arr[j].opcode; j++)
	{
		if (strcmp(opc_and_func_arr[j].opcode, opcode) == 0)
			break;
	}
	return (opc_and_func_arr[j].f);
}
