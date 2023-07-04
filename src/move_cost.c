/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:44:48 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/04 15:05:55 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* do_rev_rotate_both:

Roda ambos os stacks A e B em sentido anti-horário até que um deles esteja na posição correta.
O custo fornecido é negativo, uma vez que ambas as posições estão na metade inferior
de seus respectivos stacks. O custo é aumentado à medida que os stacks são
rodados, quando um deles atinge 0, o stack foi rodado o máximo possível
e a posição superior está correta.
*/
static void	do_rev_rotate_both(lnk_list **a, lnk_list **b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(a, b);
	}
}

/* ft_rotate_both:
*/
static void	do_rotate_both(lnk_list **a, lnk_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr(a, b);
	}
}

/* do_rotate_a:
*	
*/
static void	do_rotate_a(lnk_list **a, int *cost)
{

	if (*cost > 0)
	{
		while (*cost > 0)
		{
			ft_ra(a);
			(*cost)--;
		}
	}
	else if (*cost < 0)
	{
		while (*cost < 0)
		{
			ft_rra(a);
			(*cost)++;
		}
	}
}

/* ft_rotate_b:
*	
*/
static void	do_rotate_b(lnk_list **b, int *cost)
{
	if (*cost > 0)
	{
		while (*cost > 0)
		{
			ft_rb(b);
			(*cost)--;
		}
	}
	else if (*cost < 0)
	{
		while (*cost < 0)
		{
			ft_rrb(b);
			(*cost)++;
		}
	}
}

void	do_move(lnk_list **a, lnk_list **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);	
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	ft_pa(a, b);
}