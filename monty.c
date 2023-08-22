#include "monty.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    stack_t *stack = NULL;
    char *line = NULL;
    size_t line_len = 0;
    unsigned int line_number = 0;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}
    };

    while (getline(&line, &line_len, file) != -1)
    {
        line_number++;
        char *opcode = strtok(line, " \t\n");
        if (opcode)
        {
            int valid_opcode = 0;
            for (int i = 0; instructions[i].opcode != NULL; i++)
            {
                if (strcmp(opcode, instructions[i].opcode) == 0)
                {
                    valid_opcode = 1;
                    opcode_func func = instructions[i].func;
                    func(&stack, line_number);
                    break;
                }
            }
            if (!valid_opcode)
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                fclose(file);
                if (line)
                    free(line);
                free_stack(stack);
                return EXIT_FAILURE;
            }
        }
    }

    fclose(file);
    if (line)
        free(line);
    free_stack(stack);
    return 0;
}
