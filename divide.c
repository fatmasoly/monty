#include "monty.h"

/**
 * div_stack - Divides the next element of the stack
 * by the top element.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 *
 * Description:
 * This function divides the value of the next element
 * of the stack by the value of the top element.
 * The result replaces the next element, and the top elementis removed.
 * If the stack contains less than two elements, it prints an error
 * message and exits with EXIT_FAILURE.
 * If the top element is 0, it prints an
 * error message and exits with EXIT_FAILURE due to division by zero.
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
free_stk(stack);
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
free_stk(stack);
exit(EXIT_FAILURE);
}
(*stack)->next->n /= (*stack)->n;
pop_stack(stack, line_number);
}

