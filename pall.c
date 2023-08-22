#include "monty.h"

/* Function to print all elements in the stack */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
