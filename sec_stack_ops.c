#include "monty.h"

/**
 * mod - computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0, numerator, demoninator;
	char *message = "can't mod, stack too short";
	char *zero_msg = "division by zero";

	if (data_count < 2)
	{
		fprintf(stderr, "%s%d: %s\n", "L", line_number, message);
		free_dlistint(top);
		free(line);
		fclose(file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		numerator = (*stack)->next->n;
		demoninator = (*stack)->n;
		if (demoninator == 0)
		{
			fprintf(stderr, "%s%d: %s\n", "L", line_number, zero_msg);
			free_dlistint(top);
			free(line);
			fclose(file_ptr);
			exit(EXIT_FAILURE);
		}
		mod = numerator % demoninator;
		(*stack)->next->n = mod;
		pop(stack, line_number);
	}
	data_count--;
}
/**
 * mul - multiples the top two stack elements
 * @line_number: script line containing the opcode and its arguements
 * @stack: pointer to stack top
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int mul = 0;
	char *message = "can't mul, stack too short";

	if (data_count < 2)
	{
		fprintf(stderr, "%s%d: %s\n", "L", line_number, message);
		free_dlistint(top);
		free(line);
		fclose(file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		mul = (*stack)->n * (*stack)->next->n;
		(*stack)->next->n = mul;
		pop(stack, line_number);
	}
	data_count--;
}
/**
 * divide - divides the second stack element by the one tp stack element
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int div = 0, numerator, demoninator;
	char *message = "can't div, stack too short";
	char *zero_msg = "division by zero";

	if (data_count < 2)
	{
		fprintf(stderr, "%s%d: %s\n", "L", line_number, message);
		free_dlistint(top);
		free(line);
		fclose(file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		numerator = (*stack)->next->n;
		demoninator = (*stack)->n;
		if (demoninator == 0)
		{
			fprintf(stderr, "%s%d: %s\n", "L", line_number, zero_msg);
			free_dlistint(top);
			fclose(file_ptr);
			free(line);
			exit(EXIT_FAILURE);
		}
		div = numerator / demoninator;
		(*stack)->next->n = div;
		pop(stack, line_number);
	}
	data_count--;
}

/**
 * sub - subtracts the top stack element from the one below it
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int sub = 0;
	char *message = "can't sub, stack too";

	if (data_count < 2)
	{
		fprintf(stderr, "%s%d: %s\n", "L", line_number, message);
		free_dlistint(top);
		free(line);
		fclose(file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		sub = (*stack)->next->n - (*stack)->n;
		(*stack)->next->n = sub;
		pop(stack, line_number);
	}
	data_count--;
}
/**
 * add - ads the top two stack elements
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	char *message = "can't add, stack too short";

	if (data_count < 2)
	{
		fprintf(stderr, "%s%d: %s\n", "L", line_number, message);
		free_dlistint(top);
		free(line);
		fclose(file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum = (*stack)->n + (*stack)->next->n;
		(*stack)->next->n = sum;
		pop(stack, line_number);
	}
	data_count--;
}
