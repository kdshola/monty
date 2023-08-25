#include "monty.h"

/**
 * queue - sets operation mode to queue
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void queue(stack_t **stack __attribute__((unused)), unsigned int line_number
__attribute__((unused)))
{
	stack_mode = false;
}

/**
 * rotr - rotates stack to the right once
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	int last_data;
	stack_t *temp = queue_rear;

	if (*stack == NULL)
		return;
	last_data = temp->n;
	while (temp->prev)
	{
		temp->n = temp->prev->n;
		temp = temp->prev;
	}
	temp->n = last_data;

}

/**
 * rotl - rotates stack to the left once
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	int top_data;
	stack_t *temp = *stack;

	if (*stack == NULL)
		return;
	top_data = temp->n;
	while (temp->next)
	{
		temp->n = temp->next->n;
		temp = temp->next;
	}
	temp->n = top_data;
}

/**
 * pstr - prints stack string till non acii char or zero
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		putchar('\n');
	}
	else
	{
		while (temp->n > 0 && temp->n < 128)
		{
			putchar(temp->n);
			temp = temp->next;
		}
		putchar('\n');
	}
}

/**
 * pchar - prints stack acii char or zero
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	char *message = "can't pchar, stack empty";
	char *range = "can't pchar, value out of range";

	if (*stack == NULL)
	{
		fprintf(stderr, "%s%d: %s\n", "L", line_number, message);
		free(line);
		free_vectors(op_tokens);
		fclose(file_ptr);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "%s%d: %s\n", "L", line_number, range);
		free(line);
		fclose(file_ptr);
		free_vectors(op_tokens);
		free_dlistint(top);
		exit(EXIT_FAILURE);
	}
	else
	{
		putchar((*stack)->n);
		putchar('\n');
	}

}
