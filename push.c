#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - pushes or adds an element to stack
 * @line_number: line number in file
 * @stack: pointer to the head of stack
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *ag;
	stack_t *new_nod;

	ag = strtok(NULL, "\n");
	if (!ag || (!isdigit(*ag) && *ag != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(ag);
	new_nod = malloc(sizeof(stack_t));
	if (!new_nod)
	{
		fprintf(stderr, "Error: malloc error\n");
		exit(EXIT_FAILURE);
	}

	new_nod->n = value;
	new_nod->prev = NULL;
	new_nod->next = *stack;

	if (*stack)
		(*stack)->prev = new_nod;

	*stack = new_nod;
}
