#include "monty.h"

/**
 * cust_isdigit - Checks if a character is a digit.
 *
 * @c: The character to be checked.
 *
 * Description:
 * This function determines whether the given
 * character @c is a digit (0-9).
 *
 * Return: 1 if @c is a digit, and 0 otherwise.
 */
int cust_isdigit(int c)
{
if (c >= '0' && c <= '9')
return (1);
else
return (0);
}

/**
 * check_integer - Checks if a string represents a valid integer.
 * @head: A double pointer to the top of the stack.
 * @s: The string to be checked.
 * @line: The line number in the Monty file where the operation occurs.
 *
 * Description:
 * This function checks if the given string represents a valid integer.
 * If the string is NULL, empty, or contains non-digit characters
 * it prints an error message to stderr
 * frees the stack, and exits with a failure status.
 * It is typically used in conjunction with the "push"
 * command to validate
 * the integer argument before pushing it onto the stack.
 */
void check_integer(stack_t **head, char *s, unsigned int line)
{
unsigned long idx = 0;
if (s == NULL || *s == '\0')
{
fprintf(stderr, "L%u: usage: push integer\n", line);
free_stk(head);
exit(EXIT_FAILURE);
}
if (s[0] == '-')
{
if (s[1] == '\0')
{
fprintf(stderr, "L%u: usage: push integer\n", line);
free_stk(head);
exit(EXIT_FAILURE);
}
idx++;
}
for (; idx < strlen(s); idx++)
{
if (!cust_isdigit(s[idx]))
{
fprintf(stderr, "L%u: usage: push integer\n", line);
free_stk(head);
exit(EXIT_FAILURE);
}
}
}

