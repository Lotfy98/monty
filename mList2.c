#include "monty.h"
/**
 * add_top_elements - adds the top two elements of the stack
 * @vars: stack quantity
 * @head: top stack
 * Return: returns 0 if correct
 */
char add_top_elements(vars_t *vars, stack_t **head)
{
    int sum = 0;
    stack_t *node = *head;
    stack_t *temp_node = *head;
    int count;

    count = count_stack_items(&*head);

    if (count < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", vars->line_number);
        free_resources(vars, *head);
        exit(EXIT_FAILURE);
    }
    sum = node->n + node->next->n;
    node->next->n = sum;
    *head = node->next;
    node->next->prev = NULL;
    free(temp_node);
    return (0);
}
/**
 * do_nothing - The opcode nop doesn’t do anything
 * @vars: stack quantity
 * @head: top stack
 * Return:  returns 0 if correct
 */
char do_nothing(vars_t *vars, stack_t **head)
{
    UNUSED(vars);
    UNUSED(head);
    return (0);
}
/**
 * subtract_top_elements - subtracts the top element of the stack from the
 * second top element of the stack
 * @vars: stack quantity
 * @head: top stack
 * Return: returns 0 if correct
 */
char subtract_top_elements(vars_t *vars, stack_t **head)
{
    int difference = 0;
    stack_t *node = *head;
    stack_t *temp_node = *head;
    int count;

    count = count_stack_items(&*head);

    if (count < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", vars->line_number);
        free_resources(vars, *head);
        exit(EXIT_FAILURE);
    }
    difference = node->next->n - node->n;
    node->next->n = difference;
    *head = node->next;
    node->next->prev = NULL;
    free(temp_node);
    return (0);
}
/**
 * divide_elements - divides the second top element of the stack by the top
 * element of the stack
 * @vars: stack quantity
 * @head: top stack
 * Return: returns 0 if correct
 */
char divide_elements(vars_t *vars, stack_t **head)
{
    int division = 0;
    stack_t *node = *head;
    stack_t *temp_node = *head;
    int count;

    count = count_stack_items(&*head);

    if (count < 2)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", vars->line_number);
        free_resources(vars, *head);
        exit(EXIT_FAILURE);
    }
    if (node->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", vars->line_number);
        free_resources(vars, *head);
        exit(EXIT_FAILURE);
    }
    division = node->next->n / node->n;
    node->next->n = division;
    *head = node->next;
    node->next->prev = NULL;
    free(temp_node);
    return (0);
}
/**
 * multiply_elements - multiplies the second top element of the stack with the
 * top element of the stack
 * @vars: stack quantity
 * @head: top stack
 * Return: returns 0 if correct
 */
char multiply_elements(vars_t *vars, stack_t **head)
{
    int product = 0;
    stack_t *node = *head;
    stack_t *temp_node = *head;
    int count;

    count = count_stack_items(&*head);

    if (count < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", vars->line_number);
        free_resources(vars, *head);
        exit(EXIT_FAILURE);
    }
    product = node->n * node->next->n;
    node->next->n = product;
    *head = node->next;
    node->next->prev = NULL;
    free(temp_node);
    return (0);
}