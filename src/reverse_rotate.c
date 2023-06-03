/*
AQUI VOU AS FUNCOES DE REVERSE ROTATION
RRA
RRB
RRR
*/
#include "push_swap.h"

void reverse_rotate(lnk_list **stack)
{
    lnk_list *last;
    lnk_list *first;

    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    last = *stack;
    first = *stack;
    while (last->next != NULL)
        last = last->next;
    while (first->next != last)
        first = first->next;
    first->next = NULL;
    last->next = *stack;
    *stack = last;
}

void reverse_rotate_a(lnk_list **stacka)
{
    reverse_rotate(stacka);
    ft_putstr_fd("rra\n", 1);
}

void reverse_rotate_b(lnk_list **stackb)
{
    reverse_rotate(stackb);
    ft_putstr_fd("rrb\n", 1);
}

void reverse_rotate_ab(lnk_list **stacka, lnk_list **stackb)
{
    reverse_rotate(stacka);
    reverse_rotate(stackb);
    ft_putstr_fd("rrr\n", 1);
}

