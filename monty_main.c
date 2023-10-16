#include "monty.h"
stack_t *head = NULL;


/**
 * main - The entry point of the program.
 * @argc: The count of arguments.
 * @argv: The list of arguments.
 * Return: Always returns 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}


/**
 * create_node - Creates a node.
 * @num: The number to store in the node.
 * Return: A pointer to the node on success, or NULL on failure.
 */
stack_t *create_node(int num)
{
	stack_t *vertex;

	vertex = malloc(sizeof(stack_t));
	if (vertex == NULL)
		err(4);
	vertex->next = NULL;
	vertex->prev = NULL;
	vertex->n = num;
	return (vertex);
}


/**
 * free_nodes - Deallocates memory for nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


