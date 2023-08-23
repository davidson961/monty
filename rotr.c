#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the top of the stack.
 *@line_number: line_number
 */
void rotr(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
    stack_t *last = *stack;
    stack_t *secondLast = *stack;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    while (last->next != NULL)
    {
        secondLast = last;
        last = last->next;
    }

    secondLast->next = NULL;
    last->next = *stack;
    *stack = last;
}
