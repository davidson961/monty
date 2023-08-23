#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom (right).
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    stack_t *last = *stack;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    while (last->next != NULL)
        last = last->next;

    last->prev->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;

    (void)line_number; 
}
