#include "monty.h"
/**
 * push - Pushes an element to the stack
 * @stack: pointer to the head of the stack
 * @line_num: Line number in the file
 */
void push(stack_t **stack, unsigned int line_num)
{
	char *value_str = strtok(NULL, " \t\n");

	if (!value_str || !isdigit(*value_str) && *value_str != '-')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	int value = atoi(value_str);

	/* Create a new node */
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initialize the new node */
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	/* Update the previous node if the stack is not empty */
	if (*stack)
		(*stack)->prev = new_node;

	/* Update the stack to point to the new node */
	*stack = new_node;

}
/**
 * pall - Prints all the values on the stack
 * @stack: pointer to the head of the stack
 * @line_num: Line number in the file
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

	/* Add a check for an empty stack */
	if (!*stack)
		printf("The stack is empty\n");
}
