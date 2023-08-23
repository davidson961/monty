#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = NULL;
    stack_t *last = *stack;

    (void)line_number; 

    if (*stack && (*stack)->next)
    {
        while (last->next)
            last = last->next;

        tmp = last->prev;
        tmp->next = NULL;
        last->prev = NULL;
        last->next = *stack;
        (*stack)->prev = last;
        *stack = last;
    }
}
