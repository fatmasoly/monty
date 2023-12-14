#include "monty.h"
/**
 * print_all - Prints all elements in the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty file
 * where the operation occurs.
 *
 * Description:
 * This function prints all the elements in the stack.
 * If the stack is empty,it does nothing.
 * It iterates through the stack and prints each element's
 * value on a new line, starting from the top of the stack.
 */
void print_all(stack_t **stack, unsigned int line_number)
{
stack_t *h;
(void)line_number;
if (!stack || !*stack)
return;
h = *stack;
while (h->next != NULL)
{
printf("%d\n", h->n);
h = h->next;
}
printf("%d\n", h->n);
}
/**
 * print_stack - Prints the top element of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty file where the operation
 *
 * Description:
 * This function prints the value of the top element in the stack. If the
 * stack is empty, it prints an error message to stderr, frees the stack,
 * and exits with a failure status. Otherwise, it prints the value of the
 * top element on a new line.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
if (!stack || !*stack)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
free_stk(stack);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}

