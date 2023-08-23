#include "monty.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Open and read the Monty ByteCodes file (argv[1]) */
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        /* Parse the line and call the appropriate opcode function */
        /* You need to implement this part based on your project logic */
        /* For example: execute_opcode(&stack, line, line_number); */
    }

    /* Clean up and close the file */
    free(line);
    fclose(file);
    free_stack(stack);

    return 0;
}
