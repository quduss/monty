#include "monty.h"

global_x glob_var;

/**
 * init_glob_var - initializes the glob_var struct
 * @file_desc: The file descriptor
 */
void init_glob_var(FILE *file_desc)
{
	glob_var.is_stack = 0;
	glob_var.curr_line = 1;
	glob_var.token_2 = NULL;
	glob_var.head_node = NULL;
	glob_var.file_desc = file_desc;
	glob_var.buf = NULL;
}
/**
 * free_globvar - frees glob_var upon end of program
 */
void free_globvar(void)
{
	free_list(glob_var.head_node);
	free(glob_var.buf);
	fclose(glob_var.file_desc);
}
/**
 * main - monty program
 * @av: array of arguments to monty program
 * @ac: number of arguments to monty program
 * Return: 0 upon success
 */
int main(int ac, char *av[])
{
	FILE *file_desc;
	void (*func_ptr)(stack_t **stack, unsigned int line_number);
	ssize_t no_of_chars;
	size_t buf_size;
	char *ptr;

	file_desc = check_file(ac, av);
	init_glob_var(file_desc);
	no_of_chars = getline(&glob_var.buf, &buf_size, file_desc);
	while (!(no_of_chars == -1))
	{
		ptr = strtok(glob_var.buf, "\t \n");
		if (ptr != NULL && ptr[0] != '#')
		{
			func_ptr = get_opcs(ptr);
			if (func_ptr == NULL)
			{
				dprintf(2, "L%u: ", glob_var.curr_line);
				dprintf(2, "unknown instruction %s\n", ptr);
				free_globvar();
				exit(EXIT_FAILURE);
			}
			glob_var.token_2 = strtok(NULL, "\t \n");
			func_ptr(&glob_var.head_node, glob_var.curr_line);
		}
		glob_var.curr_line++;
		no_of_chars = getline(&glob_var.buf, &buf_size, file_desc);
	}

	free_globvar();

	return (0);
}
