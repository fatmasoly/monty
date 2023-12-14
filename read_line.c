#include "monty.h"
/**
 * read_line - Parses and executes Monty file commands.
 * @head: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty file.
 * @swi_stack: A pointer to an integer representing the stack mode.
 *
 * Description:
 * This function reads and processes each line of the Monty file. It uses
 * strtok to tokenize the line and interprets the commands accordingly.
 * If the command is "stack" or "queue," it sets the stack mode based on
 * the command. If the command is "push," it extracts
 * the integer argument,
 * checks if it's a valid integer
 * and pushes it onto the stack. For other
 * commands, it dispatches the execution to the corresponding functions.
 */
void read_line(stack_t **head, unsigned int line_number, int *swi_stack)
{
char *tok;
tok = strtok(glob_nod.buff, " \t\n");
if (tok == NULL || tok[0] == '\0' || tok[0] == '#')
return;
if (strcmp("stack", tok) == 0 || strcmp("queue", tok) == 0)
{
if (strcmp("stack", tok) == 0)
*swi_stack = 1;
if (strcmp("queue", tok) == 0)
*swi_stack = 0;
}
else if (strcmp("push", tok) == 0)
{
tok = strtok(NULL, " \t\n");
check_integer(head, tok, line_number);
push_ope(head, atoi(tok), *swi_stack);
}
else
{
map_ope(head, tok, line_number);
}
}

