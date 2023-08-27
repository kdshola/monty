#include "monty.h"

/**
 * enqueue - adds data to queue
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void enqueue(stack_t **stack, unsigned int line_number __attribute__((unused)))
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
	{
		exit_malloc();
	}
	new->next = NULL;
	new->n = top_data;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = queue_rear = queue_front = new;
	}
	else
	{
		queue_rear->next = new;
		queue_rear = new;
	}
	top_data = 0;
	data_count++;
}

/**
 * stack_m - sets operation mode to stack mode
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void stack_m(stack_t **stack __attribute__((unused)), unsigned int line_number
__attribute__((unused)))
{
	stack_mode = true;
}

/**
 * get_op_queue - finds the function corresponding to an opcode
 * @op_code: an array opertion code vectors
 * Return: address of the funcyion or NULL
 */
void (*get_op_queue(char *op_code))(stack_t **stack, unsigned int line_num)
{
	int i = 0;
	instruction_t op_n_functn[] = {
		{"push", enqueue},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"mod", mod},
		{"div", divide},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack_m},
		{"queue", queue},
		{NULL, NULL}
	};

	if (op_code[0] == '#')
		return (NULL);
	for (i = 0; op_n_functn[i].opcode; i++)
	{
		if (strcmp(op_code, op_n_functn[i].opcode) == 0)
			return (op_n_functn[i].f);
	}
	exit_invalid(op_code);

	return (NULL);
}
