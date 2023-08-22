#include "monty.h"

/* Function to check if a string is a numeric value */
int is_numeric(const char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]) && str[i] != '-')
            return 0;
    }
    return 1;
}

/* Function to free the entire stack */
void free_stack(stack_t *stack)
{
    while (stack)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }
}
