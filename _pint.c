#include "monty.h"

/* Function to print the top element of the stack */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        fclose(file);
        if (line)
            free(line);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
