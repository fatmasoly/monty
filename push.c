#include "monty.h"

/**
 * push_ope - Pushes a node onto the stack or queue based on mode.
 * @head: A double pointer to the top of the stack or queue.
 * @n: The integer value to be pushed onto the stack or queue.
 * @swi_stack: An integer indicating stack (1) or queue (0) mode.
 *
 * Description:
 * This function pushes a new node with the given integer value onto the
 * stack or queue based on the specified mode. If the mode is 1, it pushes
 * the node onto the stack; if the mode is 0, it pushes the node onto the
 * queue. The actual push operation is delegated to helper functions
 * push_node_stack or push_node_queue, depending on the mode.
 */
void push_ope(stack_t **head, int n, int swi_stack)
{
if (swi_stack == 1)
push_node_stack(head, n);
else
push_node_queue(head, n);
}
/**
 * push_node_stack - Pushes a new node to the top of the stack.
 * @head: A double pointer to the top of the stack.
 * @n: The integer value to be stored in the new node.
 *
 * Description:
 * This function allocates memory for a new node, assigns the given integer
 * value to it, and pushes it onto the top of the stack. If the allocation
 * fails, it prints an error message to stderr, frees the stack, and exits
 * with a failure status. If the stack is empty, the new node becomes the
 * only node in the stack. Otherwise, it inserts the new node at the top
 * and adjusts the pointers accordingly.
 */
void push_node_stack(stack_t **head, int n)
{
stack_t *new_node;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
free_stk(head);
exit(EXIT_FAILURE);
}
new_node->n = n;
new_node->prev = NULL;
if (*head == NULL)
{
new_node->next = NULL;
*head = new_node;
return;
}
new_node->next = *head;
(*head)->prev = new_node;
*head = new_node;
}
/**
 * push_node_queue - Pushes a new node to the end of the queue.
 * @head: A double pointer to the front of the queue.
 * @n: The integer value to be stored in the new node.
 *
 * Description:
 * This function allocates memory for a new node,
 * assigns the given integer
 * value to it, and pushes it onto the end of the queue.
 * If the allocation fails,
 * it prints an error message to stderr, frees the queue, and exits
 * with a failure status. If the queue is empty, the new node becomes the
 * only node in the queue. Otherwise, it inserts the new node at the end
 * and adjusts the pointers accordingly.
 */
void push_node_queue(stack_t **head, int n)
{
stack_t *new_node;
stack_t *back = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
free_stk(head);
exit(EXIT_FAILURE);
}
new_node->n = n;
new_node->next = NULL;
if (*head == NULL)
{
new_node->prev = NULL;
*head = new_node;
return;
}
while (back->next)
back = back->next;
back->next = new_node;
new_node->prev = back;
}
/**
 * free_stk - Frees the memory allocated for a stack.
 * @head: A double pointer to the top of the stack.
 *
 * Description:
 * This function frees the memory allocated for a stack
 * including closing the file associated with the global values
 * and freeing the character buffer
 * If the stack is empty or NULL, it does nothing. Otherwise, it
 * iterates through the stack, frees each node, and sets the stack to NULL.
 */
void free_stk(stack_t **head)
{
fclose(glob_nod.fd);
free(glob_nod.buff);
if (head == NULL || *head == NULL)
return;
while ((*head)->next)
{
*head = (*head)->next;
free((*head)->prev);
}
free(*head);
*head = NULL;
}

