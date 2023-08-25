#ifndef MONTY_H
#define MONTY_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int top_data;
extern unsigned int line_number;
extern char **op_tokens;
extern char *line;
extern stack_t *top;
extern stack_t *queue_front;
extern stack_t *queue_rear;
extern int data_count;
extern bool stack_mode;
extern FILE *file_ptr;

void enqueue(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void stack_m(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void check_args(char **op_vector);
void (*get_op_functn(char **op_code))(stack_t **stack, unsigned int line_num);
void (*get_op_queue(char **op_code))(stack_t **stack, unsigned int line_num);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
bool is_readable(char *line);
void parse_file(FILE *script);
void exit_unreadable(char *script);
void exit_malloc(void);
void exit_invalid(char **op_code);
int count_tokens(char *input, char *delimiter);
void free_vectors(char **vectors);
char **tokenize(char *copy, char *line_input);
void print_error(char **op_vector);
void free_dlistint(stack_t *head);

#endif
