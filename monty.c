#include "monty.h"
/**
 * main - read and execute instruction from files
 * @argc: count of inputted arguments
 * @argv: array of arguments
 * Return: 0 else, -1  on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack;
	char *line;
	size_t len;
	unsigned int line_num;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack = NULL;
	line = NULL;
	len = 0;
	line_num =  0;

	while (getline(&line, &len, file) != -1)
	{
		line_num++;
		push(&stack, line_num);
		pall(&stack, line_num);
	}
	free(line);
	fclose(file);
	return (0);
}
