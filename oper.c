#include "monty.h"

/**
 * map_ope - Maps and executes Monty file commands.
 * @head: A double pointer to the top of the stack.
 * @s: The command string to be mapped and executed.
 * @line_number: The line number in the Monty file.
 *
 * Description:
 * This function maps the given command string to its corresponding
 * function and executes it. It uses an array of structures to associate
 * command strings with their corresponding functions. If the command
 * string is found in the array, the associated function is executed.
 * If the command is not recognized
 * it prints an error message to stderr,
 * frees the stack, and exits with a failure status.
 */
void map_ope(stack_t **head, char *s, unsigned int line_number)
{
int mode = 0, idx = 0;
instruction_t opes[] = {
{"pall", print_all},
{"pint", print_stack},
{"pop", pop_stack},
{"swap", swap_stack},
{"nop", nop_stack},
{"add", add_elements},
{NULL, NULL}
};
for (; opes[idx].opcode != NULL; ++idx)
{
if (strcmp(opes[idx].opcode, s) == 0)
{
opes[idx].f(head, line_number);
mode = 1;
}
}
if (mode == 0)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, s);
free_stk(head);
exit(EXIT_FAILURE);
}
}

