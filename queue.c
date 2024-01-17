#include "monty.h"

/**
* f_queue - Prints the value at the front of the queue.
* @head: Double pointer to the head of the queue.
* @counter:  Line count in the Monty bytecode file.
*
* Return: No return value (void).
*/
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
* addqueue - Adds a new node to the tail of the queue.
* @n: The value to be added to the new node.
* @head: Double pointer to the head of the queue.
*
* Return: No return value (void).
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
