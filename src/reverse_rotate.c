/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:45:15 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/06 13:04:52 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
AQUI VOU AS FUNCOES DE REVERSE ROTATION
RRA
RRB
RRR
*/
#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*first;

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

void	ft_rra(t_list **stacka)
{
	reverse_rotate(stacka);
	ft_printf("rra\n");
}

void	ft_rrb(t_list **stackb)
{
	reverse_rotate(stackb);
	ft_printf("rrb\n");
}

void	ft_rrr(t_list **stacka, t_list **stackb)
{
	reverse_rotate(stacka);
	reverse_rotate(stackb);
	ft_printf("rrr\n");
}
