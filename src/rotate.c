/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:45:18 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/05 13:46:48 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
AQUI VAO AS FUNCOES DE ROTATION
RA
RB
RRR
*/

void	rotate_elements(lnk_list **stack)
{
	lnk_list	*iterator;

	if (!stack)
		return ;
	if (!*stack)
		return ;
	iterator = *stack;
	while (iterator->next != NULL)
	{
		iterator = iterator->next;
	}
	iterator->next = *stack;
	*stack = (*stack)->next;
	iterator->next->next = NULL;
}

void	ft_ra(lnk_list **stackA)
{
	rotate_elements(stackA);
	ft_printf("ra\n");
}

void	ft_rb(lnk_list **stackB)
{
	rotate_elements(stackB);
	ft_printf("rb\n");
}

void	ft_rr(lnk_list **stackA, lnk_list **stackB)
{
	rotate_elements(stackA);
	rotate_elements(stackB);
	ft_printf("rr\n");
}
