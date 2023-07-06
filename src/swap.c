/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:45:37 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/06 13:04:52 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
aqui vao as funcoes de swap
SA
SB
SSS*/

/* THIS FUNCTION SWAPS THE TWO TOP ELEMMETTS */
void	swap_elements(t_list *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
}

void	ft_sa(t_list **stackA)
{
	swap_elements(*stackA);
	ft_printf("sa\n");
}

void	ft_sb(t_list **stackB)
{
	swap_elements(*stackB);
	ft_printf("sb\n");
}

void	ft_ss(t_list **stackA, t_list **stackB)
{
	swap_elements(*stackA);
	swap_elements(*stackB);
	ft_printf("ss\n");
}
