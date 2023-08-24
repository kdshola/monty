#include "monty.h"

/**
 * exec_direct - determines execution line
 * @op_code: opcode and its arguments
 * Return:true of false
 */
bool exec_direct(char **op_code)
{
	if (strcmp(op_code[0], "push") == 0)
		return (false);
	else
		return (true);
}

/**
 * free_dlistint - frees a doubly linked lis
 * @head: pointer to list start
 * Return: Nothing
 */
void free_dlistint(stack_t *head)
{
	if (head == NULL)
		return;
	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}

/**
 * free_vectors - frees an array of strings
 * @vectors: string array
 * Return: Nothing
 */
void free_vectors(char **vectors)
{
	int i = 0;

	while (vectors[i])
	{
		free(vectors[i]);
		i++;
	}
	free(vectors);
}

/**
 * count_tokens - count number of tokens
 * @input: user input
 * @delimiter: string delimiter
 * Return: number of tokens
 */
int count_tokens(char *input, char *delimiter)
{
	int token_count = 0;
	char *token_ptr = NULL;

	token_ptr = strtok(input, delimiter);
	while (token_ptr)
	{
		token_count++;
		token_ptr = strtok(NULL, delimiter);
	}
	token_count++;
	return (token_count);
}

/**
 * tokenize - creates tokens from user input
 * @copy: copy of input from script
 * @line_input: input from script
 * Return: poiner to string tokens
 */
char **tokenize(char *copy, char *line_input)
{
	char **tokens = NULL, *tok = NULL;
	int i, j = 0, token_num = 0;

	token_num = count_tokens(line_input, " \t\n");
	tokens = malloc(sizeof(char *) * token_num);
	if (tokens == NULL)
	{
		free(copy);
		exit_malloc();
	}
	tok = strtok(copy, " \t\n");
	for (i = 0; tok != NULL; i++)
	{
		tokens[i] = malloc(sizeof(char) * (strlen(tok) + 1));
		if (tokens[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(tokens[j]);
			}
			free(tokens);
			free(copy);
			exit_malloc();
		}
		strcpy(tokens[i], tok);
		tok = strtok(NULL, " \t\n");
	}
	free(copy);
	tokens[i] = NULL;
	return (tokens);
}
