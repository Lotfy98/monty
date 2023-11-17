#include "monty.h"

/**
 * rotate_stack_to_bottom - rotates the stack to the *bottom
 * @vars: pointer type vars_t
 * @head: double pointer type stack_t
 * Return: 0
 */
char rotate_stack_to_bottom(vars_t *vars, stack_t **head)
{
	stack_t *temp_node = *head;
	stack_t *current_node = *head;
	int stack_length;

	stack_length = count_stack_items(&*head);
	if (stack_length < 2)
		return (0);

	UNUSED(vars);
	*head = temp_node->next;
	(*head)->prev = NULL;
	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = temp_node;
	temp_node->prev = current_node;
	temp_node->next = NULL;
	return (0);
}

/**
 * reverse_stack - reverse stack
 * @vars: pointer type vars_t
 * @head: double pointer type stack_t
 * Return: 0
 */
char reverse_stack(vars_t *vars, stack_t **head)
{
	return (rotate_stack_to_bottom(vars, head));
}
/**
 * append_node_to_end - add stack at the end
 * @vars: pointer type vars_t
 * @head: double pointer type stack_t
 * Return: 0
 */
char append_node_to_end(vars_t *vars, stack_t **head)
{
	stack_t *new_node = NULL;
	stack_t *last_node = *head;

	UNUSED(vars);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_resources(vars, *head);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(vars->tokens[1]);
	new_node->next = NULL;
	if (*head != NULL)
	{
		while (last_node->next != NULL)
			last_node = last_node->next;

		last_node->next = new_node;
	}
	else
		*head = new_node;

	new_node->prev = last_node;
	return (0);
}
/**
 * set_data_format - sets the format of the data to a stack (LIFO) and
 * sets the format of the data to a queue (FIFO
 * @vars: pointer type vars_t
 * @head: double pointer type stack_t
 * Return: 0
 */
char set_data_format(vars_t *vars, stack_t **head)
{
	UNUSED(head);

	if (strcmp("stack", vars->tokens[0]) == 0)
		vars->mode = "stack";
	else
		vars->mode = "queue";
	return (0);
}
