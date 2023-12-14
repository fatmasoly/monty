#include "monty.h"
/**
 * pop_stack - Removes the top element of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty file
 * where the operation occurs.
 *
 * Description:
 * This function removes the top element of the stack.
 * If the stack is empty, it prints an error message
 * to stderr, frees the stack, and exits
 * with a failure status. If there is only one element in the stack, it
 * frees the element and sets the stack to NULL. Otherwise, it moves the
 * stack pointer to the next element, frees the previous element, and
 * updates pointers accordingly.
 */
void pop_stack(stack_t **stack, unsigned int line_number)
{
if (!stack || !*stack)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
free_stk(stack);
exit(EXIT_FAILURE);
}
if ((*stack)->next == NULL)
{
free(*stack);
*stack = NULL;
return;
}
*stack = (*stack)->next;
free((*stack)->prev);
(*stack)->prev = NULL;
}
/**
 * nop_stack - Does nothing.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty file
 * where the operation occurs.
 *
 * Description:
 * This function serves as a no-operation (nop) for the stack.
 * It takes in
 * the stack and line number as parameters but performs no actual
 * operation. It is used for Monty file commands that have no impact on
 * the stack.
 */
void nop_stack(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}
/**
 * swap_stack - Swaps the top two elements of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty file
 * where the operation occurs.
 *
 * Description:
 * This function swaps the positions of the top two elements of the stack.
 * If the stack is empty or contains only one element, it prints an error
 * message to stderr, frees the stack, and exits with a failure status.
 * Otherwise, it swaps the values of the top two elements.
 */
void swap_stack(stack_t **stack, unsigned int line_number)
{
int swa;
if (!stack || !*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
free_stk(stack);
exit(EXIT_FAILURE);
}
swa = (*stack)->next->n;
(*stack)->next->n = (*stack)->n;
(*stack)->n = swa;
}
/**
 * add_elements - Adds the top two elements of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty file
 * where the operation occurs.
 *
 * Description:
 * This function adds the top two elements of the stack and replaces them
 * with the result. If the stack is empty or contains only one element,
 * it prints an error message to stderr, frees the stack, and exits with a
 * failure status. Otherwise, it performs the addition operation on the
 * top two elements and pops the original top element from the stack.
 */
void add_elements(stack_t **stack, unsigned int line_number)
{
if (!stack || !*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
free_stk(stack);
exit(EXIT_FAILURE);
}
(*stack)->next->n += (*stack)->n;
pop_stack(stack, line_number);
}

