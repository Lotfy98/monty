#include "monty.h"

/**
* count_stack_items - item counter in a stack
* @head: double stack pointer
* Return: counter
*/
int count_stack_items(stack_t **head)
{
int count = 0;
stack_t *stack = *head;

while (stack != NULL)
{
stack = stack->next;
count++;
}
return (count);
}

/**
* print_stack_as_string - prints the string starting at the top of the stack,
* followed by a new line
* @vars: stack quantity
* @head: top stack
* Return: returns 0 if correct
*/
char print_stack_as_string(vars_t *vars, stack_t **head)
{
char *buffer = NULL;
size_t buffer_size = 1, i = 0;
stack_t *stack = *head;

UNUSED(vars);
if (stack == NULL)
{
putchar('\n');
return (1);
}
buffer = malloc(sizeof(char) * buffer_size);
if (buffer == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
free_resources(vars, *head);
exit(EXIT_FAILURE);
}
while (stack != NULL)
{
if (stack->n == 0 || stack->n < 0 || stack->n > 126)
{
i++;
break;
}
buffer[i] = stack->n, stack = stack->next, i++;
if (i >= buffer_size)
{
buffer = reallocate_memory(buffer, sizeof(char) * i, sizeof(char) * (i + 1));
if (buffer == NULL)
{
fprintf(stderr, "Error: realloc failed\n");
free_resources(vars, *head);
exit(EXIT_FAILURE);
}
}
}
buffer[i] = '\0';
printf("%s\n", buffer);
free(buffer);
return (0);
}

/**
* remove_top_element - removes the top element of the stack
* @vars : index of the node, starting at 0
* @head: Pointer to head list
* Return: Return count
*/
char remove_top_element(vars_t *vars, stack_t **head)
{
stack_t *temp_node;

UNUSED(vars);
if (head == NULL || *head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", vars->line_number);
free_resources(vars, *head);
exit(EXIT_FAILURE);
}
temp_node = *head;
*head = temp_node->next;
if (temp_node->next != NULL)
{
temp_node->next->prev = NULL;
}
free(temp_node);
return (1);
}
