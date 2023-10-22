#ifndef STACK_QUEUE
#define STACK_QUEUE

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <ctype.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - struct to use for global variable
 * @is_stack: integer to check if stack or queue
 * @curr_line: current line in the bytecode file
 * @token_2: opcode argument in the current line
 * @head_node: head node of the doubly linked list
 * @file_desc: The file descriptor of the bytecode file opened
 * @buf: buffer to be used to read each line of the file opened
 * Description: struct to use for global variable
 */
typedef struct global_s
{
	FILE *file_desc;
	stack_t *head_node;
	unsigned int curr_line;
	int is_stack;
	char *buf;
	char *token_2;
} global_x;

extern global_x glob_var;

void (*get_opcs(char *opcode))(stack_t **stack, unsigned int line_number);

void free_list(stack_t *head_node);
FILE *check_file(int ac, char *av[]);
void init_glob_var(FILE *file_desc);
void add_dnodeint(stack_t **head_node, const int i);
void push_(stack_t **head_node, unsigned int line_number);
void pall_(stack_t **head_node, unsigned int line_number);
void free_globvar(void);
void pint_(stack_t **head_node, unsigned int line_number __attribute__((unused)));
void pop_(stack_t **head_node, unsigned int line_number);
void swap_(stack_t **head_node, unsigned int line_number);
void add_(stack_t **head_node, unsigned int line_number);
void nop_(stack_t **head_node, unsigned int line_number);
void sub_(stack_t **head_node, unsigned int line_number);
void div_(stack_t **head_node, unsigned int line_number);

#endif
