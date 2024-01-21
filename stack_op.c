#include "monty.h"

/**
 * mul_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sums;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_erro(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sums = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sums;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sums;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_erro(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_erro(9, line_number);
	(*stack) = (*stack)->next;
	sums = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sums;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
