#include "monty.h"

/**
 * erro - Prints appropiate error messages determined by error code.
 * @error_code: Below are the error codes
 * (1) => The user does not give more than one file to the program.
 * (2) => The file provided is unreadable and cannot be opened.
 * (3) => The file provided contains invalid instruction.
 * (4) => When the program cannot malloc.
 * (5) => When the parameter passed to instruction "push" is not int.
 * (6) => Stack is empty for pint.
 * (7) => Stack is empty for pop.
 * (8) => Stack is too short for the operation.
 */
void erro(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_numb;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_numb = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_numb, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_erro - handles the errors.
 * @error_code: The following are the error codes:
 * (6) => When the stack is empty for pint.
 * (7) => When the stack is empty for pop.
 * (8) => When stack is very short.
 * (9) => Divided by zero.
 */
void more_erro(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_numb;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_numb = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_numb, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_erro - handles all errors.
 * @error_code: The following are error codes:
 * (10) ~> The number inside node is outside bounds of ASCII.
 * (11) ~> Empty stack.
 */
void string_erro(int error_code, ...)
{
	va_list ag;
	int l_numb;

	va_start(ag, error_code);
	l_numb = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_numb);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_numb);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
