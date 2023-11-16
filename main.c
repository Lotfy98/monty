#include "monty.h"

/**
 * free_doubly_linked_list - function to free elements in list
 * @head: Pointer of type list
 */
void free_doubly_linked_list(stack_t *head)
{
    stack_t *temp_node = head;

    if (head == NULL)
    {
        return;
    }
    free_doubly_linked_list(head->next);
    free(temp_node);
}

/**
 * main - Main function
 * @argc: Number of arguments
 * @argv: Array of arguments of main.
 * Return: 1 if success
 */
int main(int argc, char **argv)
{
    vars_t vars = {NULL};
    char *delim = "\n\t";
    stack_t *head = NULL;

    vars.mode = "stack";
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    vars.buffer = handleFile(argv[1]);
    vars.arrays = split_string(vars.buffer, delim);
    if (vars.arrays == NULL)
    {
        printf("Data invalid");
    }
    else
    {
        vodika(&vars, &head);
    }
    free_doubly_linked_list(head), free(vars.arrays), free(vars.buffer);
    if (!vars.tokens)
    {
        free(vars.tokens);
    }
    exit(EXIT_SUCCESS);
}
/**
 * vodka - item counter in a stack
 * @head: double stack pointer
 * @vars: counter
 */
void vodika(vars_t *vars, stack_t **head)
{
    int a;
    char (*f)(vars_t *m, stack_t **head);

    for (a = 0; vars->arrays[a] != NULL; a++)
    {
        vars->line_number = a + 1;
        if (strcmp(vars->arrays[a], "salto") == 0)
            continue;
        vars->tokens = split_string(vars->arrays[a], " ");
        if (vars->tokens[0][0] == '#')
        {
            free(vars->tokens);
            continue;
        }
        f = match_command(vars, &*head);
        if (f == NULL)
        {
            fprintf(stderr, "L%d: unknown instruction %s\n",
                    vars->line_number, vars->arrays[a]);
            free_resources(vars, *head);
            exit(EXIT_FAILURE);
        }
        else
            f(vars, &*head);
        free(vars->tokens);
    }
}
