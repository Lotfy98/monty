#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define UNUSED(x) (void)(x)

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
 *  struct variables - Struct to save variables
 * @buffer: Input text
 * @arrays: Array of arrays of pointers
 * @tokens: Token stored strings
 * @line_number: line number
 * @mode: mode
 */
typedef struct variables
{
	char *buffer;
	char **arrays;
	char **tokens;
	int line_number;
	char *mode;
} vars_t;

/**
 * struct operation - opcode and its function
 * @word: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct operation
{
	char *word;
	char (*f)(vars_t *, stack_t **);
} operation_t;

int main(int argc, char **argv);
char *handleFile(char *filename);
char add_element(vars_t *list, stack_t **);
char print_entire_list(vars_t *list, stack_t **);
void *fill_array(void *str, char c, size_t len);
void *copy_memory(char *dest, char *src, size_t n);
void *reallocate_memory(void *str, size_t old_size, size_t new_size);
char *cut_string(char *buffer, char *d);
char **split_string(char *buffer, char *delimiter);
char (*match_command(vars_t *m, stack_t **r))(vars_t *n, stack_t **r);
void free_doubly_linked_list(stack_t *head);
int validate_integer(char *str);
char print_last_node(vars_t *vars, stack_t **head);
char remove_top_element(vars_t *vars, stack_t **head);
char add_top_elements(vars_t *vars, stack_t **head);
char do_nothing(vars_t *vars, stack_t **head);
char subtract_top_elements(vars_t *vars, stack_t **head);
char divide_elements(vars_t *vars, stack_t **head);
char multiply_elements(vars_t *vars, stack_t **head);
char compute_modulus(vars_t *vars, stack_t **head);
char handle_comment(vars_t *vars, stack_t **head);
char print_char_at_top(vars_t *vars, stack_t **head);

char swap_top_elements(vars_t *vars, stack_t **head);
char print_stack_as_string(vars_t *vars, stack_t **head);
char rotate_stack_to_bottom(vars_t *vars, stack_t **head);
char reverse_stack(vars_t *vars, stack_t **head);
char append_node_to_end(vars_t *vars, stack_t **head);
char set_data_format(vars_t *vars, stack_t **head);
char push_element(vars_t *vars, stack_t **head);

void free_resources(vars_t *vars, stack_t *head);

void vodika(vars_t *vars, stack_t **head);

int count_stack_items(stack_t **head);

#endif
