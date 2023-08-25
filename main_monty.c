#include "monty.h"

/**
 * get_op_functn - finds the function corresponding to an opcode
 * @op_code: an array opertion code vectors
 * Return: address of the funcyion or NULL
 */
void (*get_op_functn(char **op_code))(stack_t **stack, unsigned int line_num)
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

	for (i = 0; op_n_functn[i].opcode; i++)
	{
		if (strcmp(op_code[0], op_n_functn[i].opcode) == 0)
			return (op_n_functn[i].f);
	}
	exit_invalid(op_code);

	return (NULL);
}

/**
 * is_readable - checks for readable character
 * @line: line to check;
 * Return: true if readable
 */
bool is_readable(char *line)
{
	size_t i, len = 0;

	len = strlen(line);
	if (len == 1)
		return (false);
	for (i = 0; i < len; i++)
	{
		if (line[i] == '#')
			return (false);
		else if (line[i] > 40)
			return (true);
	}
	return (false);
}

/**
 * parse_file - Reads and executes commands from script
 * @script: file pointer to script
 * Return: Nothing
 */
void parse_file(FILE *script)
{
	ssize_t chars_read = 0;
	size_t len = 0, buf_size = 0;
	char *line_copy = NULL;
	void (*f)(stack_t **stack, unsigned int line_number) = NULL;

	while (!feof(script))
	{
		chars_read = getline(&line, &buf_size, script);
		if (chars_read == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		if (is_readable(line) == false)
		{
			line_number++;
			continue;
		}
		len = strlen(line);
		line_copy = malloc(sizeof(char) * (len + 1));
		if (line_copy == NULL)
			exit_malloc();
		line_copy = strcpy(line_copy, line);
		op_tokens = tokenize(line_copy, line);
		if (stack_mode)
			f = get_op_functn(op_tokens);
		else
			f = get_op_queue(op_tokens);
		f(&top, line_number);
		free_vectors(op_tokens);
		line_number++;
	}
	free(line);
	free_dlistint(top);
}

int data_count = 0;
bool stack_mode = true;
int top_data = 0;
int second_data = 0;
char *line = NULL;
char **op_tokens = NULL;
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
	return (0);
}
