#include "monty.h"

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
