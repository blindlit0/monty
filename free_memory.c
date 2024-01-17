#include "monty.h"

/**
* free_stack - Frees the memory allocated
*		for a doubly linked list.
* @head: Pointer to the head of the
*	doubly linked list (stack).
*
* Return:  No return value (void).
*/
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
* f_stack - Prints the elements of the stack.
* @head: Pointer to the head of the
*	doubly linked list (stack).
* @counter: Line count in the Monty bytecode file.
*
* Return: No return value (void).
*/
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
