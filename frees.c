#include "monty.h"
/**
 * free_resources - function to free allocated resources
 * @head: Parameter type struc
 * @vars: parameter type struc]
 */

void free_resources(vars_t *vars, stack_t *head)
{
    free_doubly_linked_list(head);
    free(vars->buffer);
    free(vars->arrays);
    free(vars->tokens);
}
