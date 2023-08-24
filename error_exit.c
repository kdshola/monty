#include "monty.h"

/**
 * print_error - prints error message
 * @op_vector:opcode and its arguments
 * Return: nothing
 */
void print_error(char **op_vector)
{
	char *push_message = "usage: push integer";

	fprintf(stderr, "%s%d: ", "L", line_number);
	if (strcmp(op_vector[0], "push") == 0)
		fprintf(stderr, "%s\n", push_message);
	free(line);
	free_dlistint(top);
	free_vectors(op_vector);
	fclose(file_ptr);
	exit(EXIT_FAILURE);
}

/**
 * exit_unreadable - prints message and ends program if unable to open script
 * @script: script name or path
 * Return: Nothing
 */
void exit_unreadable(char *script)
{
	fprintf(stderr, "%s %s\n", "Error: Can't open file", script);
	exit(EXIT_FAILURE);
}

/**
 * exit_malloc - prints message and exits due to malloc failure
 * Return: Nothing
 */
void exit_malloc(void)
{
	fprintf(stderr, "%s\n", "Error: malloc failed");
	free_dlistint(top);
	free(line);
	fclose(file_ptr);
	exit(EXIT_FAILURE);
}

/**
 * exit_invalid - exits upon invalid op_code and prints message
 * @op_code: op_code vector
 * Return: nothing
 */
void exit_invalid(char **op_code)
{
	char *message = "unknown instruction";

	free(line);
	fprintf(stderr, "%s%d: %s %s\n", "L", line_number, message, op_code[0]);
	free_vectors(op_code);
	free_dlistint(top);
	fclose(file_ptr);
	exit(EXIT_FAILURE);
}

/**
 * nop - does nothing
 * @stack: pointer to stack top
 * @line_number: script line containing the opcode and its arguements
 * Return: Nothing
 */
void nop(stack_t **stack __attribute__((unused)), unsigned int line_number
__attribute__((unused)))
{
}
