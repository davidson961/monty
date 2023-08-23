#include "monty.h"
#include <stdio.h>

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 */
void pstr(stack_t **stack)
{
    stack_t *current = *stack;

    while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
    {
        printf("%c", current->n);
        current = current->next;
    }

    printf("\n");
}
