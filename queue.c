#include "monty.h"

/**
 * queue - Set the format of the data to a queue (FIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number being executed from the Monty file
 */
void queue(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    global.data_structure = QUEUE;
}
