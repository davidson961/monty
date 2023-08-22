#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data structure for the stack */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Data structure for the opcode instructions */
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Enumeration for data structure type (STACK or QUEUE) */
typedef enum data_structure_e
{
    STACK,
    QUEUE
} data_structure_t;

/* Global variable to store data structure type */
typedef struct global_s
{
    data_structure_t data_structure;
    /* ... other members ... */
} global_t;

/* ... other function prototypes ... */

extern global_t global;

#endif /* MONTY_H */
