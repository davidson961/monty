#include "monty.h"

/* Function to push an element onto the stack */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");
    if (!arg || !is_numeric(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    int value = atoi(arg);
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}
