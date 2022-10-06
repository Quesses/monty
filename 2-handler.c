#include "monty.h"

/**
 * swap_op - Swaps the top 2 elements of the stack
 * @stack: Double linked used to stack the integers
 * @line_number: Line number of the current opcode
 */
void swap_op(stack_t **stack, unsigned int line_number)
{
        stack_t *tmp, *aux;
        int i = 0;

        if (*stack == NULL)
        {
                err_status = 4;
                return;
        }
        tmp = *stack;
        while (tmp->next != NULL)
        {
                tmp = tmp->next;
                i++;
        }
        if (i < 2)
        {
                err_status = 4;
                return;
        }
        aux = tmp->prev;
        aux->prev->next = tmp;
        tmp->prev = aux->prev;
        aux->prev = tmp;
        tmp->next = aux;
        aux->next = NULL;
        (void)line_number;
}

/**
 * add_op - Adds the top 2 element of the stack
 * @stack: Double linked used to stack the integers
 * @line_number: Line number of the current opcode
 */
void add_op(stack_t **stack, unsigned int line_number)
{
        stack_t *tmp;
        int i = 0;

        if (*stack == NULL)
        {
                err_status = 5;
                return;
        }
        tmp = *stack;
        while (tmp->next != NULL)
        {
                tmp = tmp->next;
                i++;
        }
        if (i < 2)
	{
		err_status = 5;
                return;
        }
        tmp = tmp->prev;
        tmp->n = tmp->next->n + tmp->n;
        pop_op(stack, line_number);
}

/**
 * sub_op - Subtracts the top 2 element of the stack
 * @stack: Double linked used to stack the integers
 * @line_number: Line number of the current opcode
 */
void sub_op(stack_t **stack, unsigned int line_number)
{
        stack_t *tmp;
        int i = 0;

        if (*stack == NULL)
        {
                err_status = 6;
                return;
        }
        tmp = *stack;
        while (tmp->next != NULL)
        {
                tmp = tmp->next;
                i++;
        }
        if (i < 2)
        {
                err_status = 6;
                return;
        }
        tmp = tmp->prev;
        tmp->n = tmp->n - tmp->next->n;
        pop_op(stack, line_number);
}

/**
 * mul_op - Multiplies the top 2 element of the stack
 * @stack: Double linked used to stack the integers
 * @line_number: Line number of the current opcode
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
        stack_t *tmp;
        int i = 0;

        if (*stack == NULL)
        {
                err_status = 6;
                return;
        }
        tmp = *stack;
        while (tmp->next != NULL)
        {
                tmp = tmp->next;
		i++;
        }
        if (i < 2)
        {
                err_status = 7;
                return;
        }
        tmp = tmp->prev;
        tmp->n = tmp->n * tmp->next->n;
        pop_op(stack, line_number);
}
