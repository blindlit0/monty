#include "monty.h"

/**
* f_pop - Removes the top element from the stack.
* @head: Double pointer to the head of the stack.
* @counter: Line count in the Monty bytecode file.
*
* Return: No return value (void).
*/
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
* f_pint - Prints the value at the top of the stack.
* @head: Double pointer to the head of the stack.
* @counter: Line count in the Monty bytecode file.
*
* Return: No return value (void).
*/
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
* f_nop - Does nothing.
* @head: Double pointer to the head of the stack.
* @counter: Line count in the Monty bytecode file.
*
* Return: No return value (void).
*/
void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
