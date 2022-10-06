#include "monty.h"

/**
 * main - Main functions of Monty's Interpreter
 * @argc: Argument's counter
 * @argv: Arguments to main
 * Return: 0 is success
 */
int err_status = 0;
int main(int argc, char *argv[])
{
	FILE *fd;
	stack_t *stack = NULL;
	char *buffer = NULL, *opcode = NULL, *tokens = NULL;
	size_t len_buff = 0;
	ssize_t bytes_read = 0;
	unsigned int line_number = 0;
	int select = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (bytes_read != -1)
	{
		bytes_read = getline(&buffer, &len_buff, fd);
		if (bytes_read == -1)
			break;
		line_number++;
		opcode = strtok(buffer, DELIM);

		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				tokens = strtok(NULL, DELIM);
				if (tokens == NULL)
				{
					error_unknown(opcode, line_number);
					free_errors(stack, buffer, fd);
				}
				else
					push_op(&stack, line_number, tokens);
			}
			else
			{
				select = select_op(opcode, &stack, line_number);
				id_status(stack, buffer, fd, line_number);
				if (select == -1)
					error_unknown(opcode, line_number), free_errors(stack, buffer, fd);
			}
		}
	}

	return (0);
}
