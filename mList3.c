#include "monty.h"

/**
 * push_element - pushes an element to the stack
 * @vars: Pointer of type vars_t
 * @head: Pointer of type stack_t
 * Return: Return count
 */
char push_element(vars_t *vars, stack_t **head)
{
    if (strcmp(vars->mode, "stack") == 0)
    {
        add_element(vars, head);
    }
    else
    {
        append_node_to_end(vars, head);
    }
    return (0);
}

/**
 * add_element - function to add elements to list
 * @list: Pointer of type vars_t
 * @head: Pointer of type stack_t
 * Return: Return count
 */
char add_element(vars_t *list, stack_t **head)
{
    stack_t *new_node = *head;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_resources(list, *head);
        exit(EXIT_FAILURE);
    }
    if (list->tokens[1] == NULL || validate_integer(list->tokens[1]) == 0)
    {
        fprintf(stderr, "L%d: usage: push integer\n", list->line_number);
        free_resources(list, *head);
        exit(EXIT_FAILURE);
    }
    new_node->n = atoi(list->tokens[1]);
    new_node->next = *head;
    new_node->prev = NULL;
    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
    *head = new_node;
    return (1);
}

/**
 * validate_integer - Validate that the values are integers
 * @str: pointer to string
 * Return: 1 if the function is correct
 */
int validate_integer(char *str)
{
    int i = 0;

    if (atoi(str) < 0 || str[i] == '-')
    {
        i++;
    }

    while (str[i] != '\0')
    {
        if (str[i] < 47 || str[i] > 57)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

/**
 * print_entire_list - print the entire stack list
 * @list: pointer of type vars_t
 * @head: Pointer of type stack_t
 *
 * Return: Return count
 */
char print_entire_list(__attribute__((unused)) vars_t *list, stack_t **head)
{
    int count = 0;
    stack_t *node = *head;

    while (node != NULL)
    {
        printf("%d\n", node->n);
        node = node->next;
        count++;
    }
    return (0);
}
/**
 * print_last_node - prints the last node in the stack
 * @vars: Pointer of type vars_t
 * @head: Pointer of type stack_t
 * Return: Return count
 */
char print_last_node(vars_t *vars, stack_t **head)
{
    stack_t *node = *head;

    UNUSED(vars);
    if (head == NULL || *head == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", vars->line_number);
        free_resources(vars, *head);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", node->n);
    return (0);
}
