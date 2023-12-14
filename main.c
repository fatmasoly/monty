#include "monty.h"
glob_val glob_nod;
/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of strings representing the command-line arguments.
 *
 * Description:
 * This function serves as the entry point for the Monty interpreter.
 * It reads Monty bytecode from a file specified in the command-line
 * argument,interprets the commands, and executes them accordingly
 * The program initializes necessary variables
 * such as the file pointer, stack mode, and stack pointer
 * It then reads each line of the file, parsing and executing
 * the commands until the end of the file is reached. If any errors occur,
 * appropriate error messages are printed to stderr, and the program exits
 * with a failure status.
 *
 * Return:
 * 0 on successful execution.
 */
int main(int argc, char **argv)
{
size_t n = 0;
unsigned int line = 1;
int swi_stack = 1;
stack_t *h = NULL;
val_free(&glob_nod);
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
glob_nod.fd = fopen(argv[1], "r");
if (glob_nod.fd == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (getline(&glob_nod.buff, &n, glob_nod.fd) != -1)
{
read_line(&h, line, &swi_stack);
line++;
}
free_stk(&h);
return (0);
}
/**
 * val_free - Resets global values to NULL.
 * @glob_nod: Pointer to the global values structure.
 *
 * Description:
 * This function takes a pointer to the global values structure and sets
 * both the file pointer (`fd`) and character buffer pointer (`buff`) to
 * NULL. It is designed to reset the global values before using them to
 * avoid referencing invalid memory locations.
 */
void val_free(glob_val *glob_nod)
{
glob_nod->fd = NULL;
glob_nod->buff = NULL;
}

