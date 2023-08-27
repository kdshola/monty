#include "monty.h"

/**
 * print_error - prints error message
 * Return: nothing
 */
void print_error(void)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free(line);
	free_dlistint(top);
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
	fprintf(stderr, "Error: Can't open file %s\n", script);
	exit(EXIT_FAILURE);
}

/**
 * exit_malloc - prints message and exits due to malloc failure
 * Return: Nothing
 */
void exit_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
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
void exit_invalid(char *op_code)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_code);
	free(line);
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
