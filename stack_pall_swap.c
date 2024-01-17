#include "monty.h"

/**
* f_pall - Prints all elements in the stack.
* @head: Double pointer to the head of the stack.
* @counter: Unused line count in the Monty bytecode file.
*
* Return: No return value (void).
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
* f_swap - Swaps the top two elements of the stack.
* @head: Double pointer to the head of the stack.
* @counter: Line count in the Monty bytecode file.
*
* Return: No return value (void).
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
