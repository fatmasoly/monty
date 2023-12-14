#include "monty.h"

/**
 * multi_stack - Multiplies the next element of
 * the stack by the top element.
 *
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 *
 * Description:
 * This function multiplies the value of the next element
 * of the stack by the value of the top element.
 * The result replaces the next element, and the top
 * element is removed. If the stack contains less than two elements,
 * it prints an error message and exits with EXIT_FAILURE.
 */
void multi_stack(stack_t **stack, unsigned int line_number)
{
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
free_stk(stack);
exit(EXIT_FAILURE);
}
(*stack)->next->n *= (*stack)->n;
pop_stack(stack, line_number);
}

