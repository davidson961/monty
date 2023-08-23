#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the top of the stack.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *first = *stack;
    stack_t *last = *stack;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    while (last->next != NULL)
        last = last->next;

    *stack = first->next;
    first->next = NULL;
    last->next = first;
}
