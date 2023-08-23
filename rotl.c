#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the top of the stack.
 */
void rotl(stack_t **stack)
{
    if (*stack && (*stack)->next)
    {
        stack_t *first = *stack;
        stack_t *last = *stack;

        while (last->next)
            last = last->next;

        *stack = first->next;
        (*stack)->prev = NULL;

        last->next = first;
        first->prev = last;
        first->next = NULL;
    }
}
