/*
aQUI VAO AS FUNCOES DE PUSH
PA
PB*/

#include "push_swap.h"

void push_element(lnk_list **stacka, lnk_list **stackb)
{
    lnk_list *tmp;

    if (*stacka == NULL)
        return ;
    tmp = *stacka;
    *stacka = (*stacka)->next;
    tmp->next = *stackb;
    *stackb = tmp;
}

void push_a(lnk_list **stacka, lnk_list **stackb)
{
    push_element(stackb, stacka);
    ft_putstr_fd("pa\n", 1);
}
void push_b(lnk_list **stacka, lnk_list **stackb)
{
    push_element(stacka, stackb);
    ft_putstr_fd("pb\n", 1);
}
