#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack with the top element.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void mul(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n *= (*stack)->n;
    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(temp);
}
