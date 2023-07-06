/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:44:48 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/06 13:04:52 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rev_rotate_both(t_list **a, t_list **b, int *cost_a, int *cost_b)
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
void	do_rotate_both(t_list **a, t_list **b, int *cost_a, int *cost_b)
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
void	do_rotate_a(t_list **a, int *cost)
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
void	do_rotate_b(t_list **b, int *cost)
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

void	do_move(t_list **a, t_list **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	ft_pa(a, b);
}
