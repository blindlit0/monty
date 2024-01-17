#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - Monty code interpreter entry point
* @argc: Argument count
* @argv: Argument vector
*
* Description:
*   The main function serves as the entry point for the Monty code interpreter.
*   It takes command-line arguments, including the program name and optional
*   file name, and executes the Monty code instructions found in the specified
*   file or from standard input.
*
* Return: 0 on successful execution.
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
