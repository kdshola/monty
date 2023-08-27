#include "monty.h"

/**
 * get_op_functn - finds the function corresponding to an opcode
 * @op_code: an array opertion code vectors
 * Return: address of the funcyion or NULL
 */
void (*get_op_functn(char *op_code))(stack_t **stack, unsigned int line_num)
{
	int i = 0;
	instruction_t op_n_functn[] = {
		{"push", push},
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

/**
 * parse_file - Reads and executes commands from script
 * @script: file pointer to script
 * Return: Nothing
 */
void parse_file(FILE *script)
{
	ssize_t chars_read = 0;
	size_t buf_size = 0;
	char *op_code = NULL;
	void (*f)(stack_t **stack, unsigned int line_number) = NULL;

	while (!feof(script))
	{
		chars_read = getline(&line, &buf_size, script);
		if (chars_read == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		op_code = strtok(line, " \t\n");
		if (op_code == NULL)
		{
			line_number++;
			continue;
		}
		op_arg = strtok(NULL, " \t\n");
		f = get_op_functn(op_code);
		if (f)
			f(&top, line_number);
		line_number++;
		free(line);
		line = NULL;
		buf_size = 0;
	}
	free(line);
	free_dlistint(top);
}

int data_count = 0;
bool stack_mode = true;
int top_data = 0;
int second_data = 0;
char *line = NULL;
char *op_arg = NULL;
unsigned int line_number = 1;
FILE *file_ptr = NULL;
stack_t *top = NULL;
stack_t *queue_front = NULL;
stack_t *queue_rear = NULL;

/**
 * main - Entry point for monty program that reads and interprets
 * input script
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success or EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
	char *file_path = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	file_path = argv[1];
	file_ptr = fopen(file_path, "r");
	if (file_ptr == NULL)
		exit_unreadable(file_path);
	 parse_file(file_ptr);
	 fclose(file_ptr);
	exit(EXIT_SUCCESS);
}
