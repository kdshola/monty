#include "monty.h"

/**
 * swap - swaps the top two stack elements
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (data_count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_dlistint(top);
		free(line);
		fclose(file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		(*stack)->prev = temp;
		temp->prev = NULL;
		temp->next = *stack;
		*stack = queue_front = temp;
	}

}

/**
 * pop - removes top stack element
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(line);
		fclose(file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = queue_front = temp->next;
		free(temp);
		data_count--;
	}
}

/**
 * pint - An opcode that prints stack top
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(line);
		fclose(file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}

/**
 * push - An opcode that pushes an element onto the stack top
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	int i, num = 0;
	stack_t *new = NULL;

	if (op_arg == NULL)
		print_error();
	for (i = 0; op_arg[i]; i++)
	{
		if (op_arg[0] == '-')
			continue;
		if (op_arg[i] > 57 || op_arg[i] < 48)
			print_error();
	}
	num = atoi(op_arg);
	top_data = num;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit_malloc();
	new->next = NULL;
	new->prev = NULL;
	new->n = top_data;
	if (*stack == NULL)
	{
		*stack = queue_rear = queue_front = new;
	}
	else if (stack_mode)
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = queue_front = new;
	}
	else
	{
		new->prev = queue_rear;
		queue_rear->next = new;
		queue_rear = new;
	}
	data_count++;
	top_data = 0;
}


/**
 * pall - An opcode that prints all stack elements
 * @stack: the opcode and its arguements
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	if (*stack == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
