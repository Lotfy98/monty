#include "monty.h"
/**
* match_command - function to match the inserted command
* @m: Parameter type struc
* @r: parameter type struc]
*
* Return: Return count
*/
char (*match_command(vars_t *m, stack_t **r))(vars_t *n, stack_t **r)
{
int i;
operation_t operations[] = {
{"push", push_element},
{"pall", print_entire_list},
{"pint", print_last_node},
{"pop", remove_top_element},
{"swap", swap_top_elements},
{"add", add_top_elements},
{"nop", do_nothing},
{"sub", subtract_top_elements},
{"div", divide_elements},
{"mul", multiply_elements},
{"mod", compute_modulus},
{"#", handle_comment},
{"pchar", print_char_at_top},
{"pstr", print_stack_as_string},
{"rotl", rotate_stack_to_bottom},
{"rotr", reverse_stack},
{"stack", set_data_format},
{"queue", set_data_format},
{NULL, NULL},
};
UNUSED(r);
for (i = 0; operations[i].f != NULL; i++)
{
if (strcmp(operations[i].word, m->tokens[0]) == 0)
break;
}
return (operations[i].f);
}
