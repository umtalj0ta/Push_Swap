/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:45:15 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/05 13:46:43 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
AQUI VOU AS FUNCOES DE REVERSE ROTATION
RRA
RRB
RRR
*/
#include "push_swap.h"

void	reverse_rotate(lnk_list **stack)
{
	lnk_list	*last;
	lnk_list	*first;

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

void	ft_rra(lnk_list **stacka)
{
	reverse_rotate(stacka);
	ft_printf("rra\n");
}

void	ft_rrb(lnk_list **stackb)
{
	reverse_rotate(stackb);
	ft_printf("rrb\n");
}

void	ft_rrr(lnk_list **stacka, lnk_list **stackb)
{
	reverse_rotate(stacka);
	reverse_rotate(stackb);
	ft_printf("rrr\n");
}
