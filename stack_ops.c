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
	char *message = "can't swap, stack too short";

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
	char *message = "can't pop an empty stack";
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "%s%d: %s\n", "L", line_number, message);
		free(line);
		fclose(file_ptr);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = queue_front = temp->next;
		free(temp);
	}
	data_count--;
}

/**
 * pint - An opcode that prints stack top
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	char *message = "can't pint, stack empty";

	if (*stack == NULL)
	{
		fprintf(stderr, "%s%d: %s\n", "L", line_number, message);
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
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		exit_malloc();
	}
	new->prev = NULL;
	new->n = top_data;
	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = queue_rear = queue_front = new;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = queue_front = new;
	}
	data_count++;
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
