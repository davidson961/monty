#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element by the top element.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void mod(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    (*stack)->next->n %= (*stack)->n;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(temp);
}
