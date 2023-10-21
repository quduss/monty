#include "monty.h"
/**
 * check_file - check for correct number of args to monty and if
 * file can be opened
 * @av: array of arguments to monty program
 * @ac: number of arguments to monty program
 * Return: file descriptor of opened file
 */
FILE *check_file(int ac, char *av[])
{
	FILE *file_desc;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_desc = fopen(av[1], "r");

	if (file_desc == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	return (file_desc);
}
