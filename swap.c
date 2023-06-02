#include "push_swap.h"
/*
aqui vao as funcoes de swap
SA
SB
SSS*/

/* THIS FUNCTION SWAPS THE TWO TOP ELEMMETTS */
void    swap_elements(lnk_list *stack)
{
    int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
    tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
}
void    ft_sa(lnk_list **stackA)
{
    swap_elements(*stackA);
    ft_printf("sa\n");
}

void    ft_sb(lnk_list **stackB)
{
    swap_elements(*stackB);
    ft_printf("sb\n");
}

void    ft_ss(lnk_list **stackA, lnk_list **stackB)
{
    swap_elements(*stackA);
    swap_elements(*stackB);
    ft_printf("ss\n");
}