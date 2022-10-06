#include "monty.h"

/**
 * free_errors - Frees all errors
 * @stack: Double linked used to stack the integers
 * @buffer: Buffer that stores the line for getline
 * @fd: File descriptor of the Monty's file
 */
void free_errors(stack_t *stack, char *buffer, FILE *fd)
{
        if (stack != NULL)
                free_stack(stack);
        fclose(fd);
        free(buffer);
        exit(EXIT_FAILURE);
}

/**
 * free_stack - Function to free a double linked list
 * @stack: Double linked used to stack the integers
 */

void free_stack(stack_t *stack)
{
        stack_t *tmp, *aux;

        if (stack == NULL)
                return;
        tmp = stack;
        while (tmp != NULL)
        {
                aux = tmp->next;
                free(tmp);
                tmp = aux;
        }
}

/**
 * error_unknown - Error for invalid instruction
 * @opcode:String with the operation code
 * @line_number: Line number of the current opcode
 */
void error_unknown(char *opcode, unsigned int line_number)
{
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
}

/**
 * id_status - Check's for type of error
 * @stack: Double linked used to stack the integers
 * @l_number: Line number of the current opcode
 * @fd: File descriptor of the Monty's file
 * @buffer: Buffer that stores the line for getline
 */
void id_status(stack_t *stack, char *buffer, FILE *fd, unsigned int line_number)
{
        if (err_status == 2)
        {
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
                free_errors(stack, buffer, fd);
        }
        if (err_status == 3)
        {
                fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
                free_errors(stack, buffer, fd);
        }
        if (err_status == 4)
        {
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
                free_errors(stack, buffer, fd);
        }
        if (err_status == 5)
        {
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                free_errors(stack, buffer, fd);
        }
        if (err_status == 6)
        {
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
                free_errors(stack, buffer, fd);
        }
        if (err_status == 7)
        {
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
                free_errors(stack, buffer, fd);
        }
}
