#include "monty.h"

/**
* compute_modulus - computes the rest of the division
* of the second top element of
* the stack by the top element of the stack
* @vars: stack quantity
* @head: top stack
* Return: returns 0 if correct
*/
char compute_modulus(vars_t *vars, stack_t **head)
{
int modulus = 0;
stack_t *node = *head;
stack_t *temp_node = *head;
int count;

count = count_stack_items(&*head);

if (count < 2)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", vars->line_number);
free_resources(vars, *head);
exit(EXIT_FAILURE);
}
if (node->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", vars->line_number);
free_resources(vars, *head);
exit(EXIT_FAILURE);
}

modulus = node->next->n % node->n;
node->next->n = modulus;
*head = node->next;
node->next->prev = NULL;
free(temp_node);
return (0);
}

/**
* handle_comment - Special character that represents a comment
* @vars: stack quantity
* @head: top stack
* Return: returns 0 if correct
*/
char handle_comment(vars_t *vars, stack_t **head)
{
UNUSED(vars);
UNUSED(head);
return (0);
}

/**
* print_char_at_top - prints the char at the top of the stack,
* followed by a new line
* @vars: stack quantity
* @head: top stack
* Return: returns 0 if correct
*/
char print_char_at_top(vars_t *vars, stack_t **head)
{
stack_t *node = *head;

if (node == NULL)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", vars->line_number);
free_resources(vars, *head);
exit(EXIT_FAILURE);
}

if (node->n < 0 || node->n > 126)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", vars->line_number);
free_resources(vars, *head);
exit(EXIT_FAILURE);
}
putchar(node->n);
putchar('\n');
return (0);
}

/**
* swap_top_elements - swaps the top two elements of the stack
* @vars: stack quantity
* @head: top stack
* Return: returns 0 if correct
*/
char swap_top_elements(vars_t *vars, stack_t **head)
{
int temp;
int count;

count = count_stack_items(&*head);

if (count < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", vars->line_number);
free_resources(vars, *head);
exit(EXIT_FAILURE);
}
temp = (*head)->n;
(*head)->n = (*head)->next->n;
(*head)->next->n = temp;
return (0);
}
