#include "monty.h"

/* Function to add the top two elements of the stack */
void add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    int sum = (*stack)->n + (*stack)->next->n;
    pop(stack, line_number); // Remove the top element
    (*stack)->n = sum; // Store the result in the new top element
}
