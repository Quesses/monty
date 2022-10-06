#include "monty.h"

/**
 * push_op - Adds a new element to the stack
 * @stack: Double linked used to stack the integers
 * @line_number: Line number of the current opcode
 * @num: Element to add
 */
void push_op(stack_t **stack, unsigned int line_number, char *num)
{
        stack_t *new, *tmp;
        int value;

        value = atoi(num);
        if (value == 0 && *num != '0')
        {
                printf("L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }
        new = malloc(sizeof(stack_t));
        if (new == NULL)
        {
                printf("Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
        if (*stack == NULL)
        {
                new->n = value;
                new->prev = (*stack);
                new->next = NULL;
                *stack = new;
                return;
        }
        new->n = value;
	 new->next = NULL;
        tmp = *stack;
        while (tmp->next != NULL)
        {
                tmp = tmp->next;
        }
        new->prev = tmp;
        tmp->next = new;
}

/**
 * select_op - Look for a function that match with the opcode
 * @opcode: String with the operation code
 * @stack: Double linked used to stack the integers
 * @line_number: Line number of the current opcode
 * Return: o if success, -1 if fails
 */
int select_op(char *opcode, stack_t **stack, unsigned int line_number)
{
        instruction_t funct_op[] = {
                {"pall", pall_op},
                {"pint", pint_op},
                {"pop", pop_op},
                {"swap", swap_op},
                {"add", add_op},
                {"sub", sub_op},
                {"mul", mul_op},
                {NULL, NULL}
        };

        int i = 0;

	if (strcmp(opcode, "nop") == 0)
                return (0);
        while (funct_op[i].opcode != NULL)
        {
                if (strcmp(opcode, funct_op[i].opcode) == 0)
                {
                        (funct_op[i].f)(stack, line_number);
                        return (0);
                }
        i++;
        }
        return (-1);
}
/**
 * pall_op - Print all the elements of the stack
 * @stack: Double linked used to stack the integers
 * @line_number: Line number of the current opcode
 */
void pall_op(stack_t **stack, unsigned int line_number)
{
        stack_t *tmp = *stack;

        if (*stack == NULL)
                return;
        while (tmp->next != NULL)
        {
                tmp = tmp->next;
        }
        while (tmp->prev != NULL)
        {
                printf("%d\n", tmp->n);
                tmp = tmp->prev;
        }
        printf("%d\n", tmp->n);
        (void)line_number;
}

/**
 * pint_op - Print the value at the top of the stack
 * @stack: Double linked used to stack the integers
 * @line_number: Line number of the current opcode
 */

void pint_op(stack_t **stack, unsigned int line_number)
{
        stack_t *tmp = *stack;

        if (*stack == NULL)
        {

                err_status = 2;
                return;
        }
        while (tmp->next != NULL)
        {
                tmp = tmp->next;
	}
	printf("%d\n", tmp->n);
        (void)line_number;

}

/**
 * pop_op - Remove the top element of the stack
 * @stack: Double linked used to stack the integers
 * @line_number: Line number of the current opcode
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
        stack_t *tmp;

        if (*stack == NULL)
        {
                err_status = 3;
                return;
        }
        tmp = *stack;
        while (tmp->next != NULL)
        {
                tmp = tmp->next;
        }
        if (tmp->prev != NULL)
        {
                tmp->prev->next = NULL;
                free(tmp);
        }
        else
        {
                free(tmp);
                *stack = NULL;
        }
        (void)line_number;
}
