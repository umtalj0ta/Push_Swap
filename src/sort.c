/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:00:39 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/05 16:23:05 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*sort_three(lnk_list **stack)
{
	lnk_list	*biggest;

	if (is_sorted(*stack) == 1)
		return (*stack);
	biggest = find_biggest(*stack);
	if (biggest == *stack)
		ft_ra(stack);
	if (biggest == (*stack)->next)
		ft_rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		ft_sa(stack);
	return (*stack);
}

void	push_all_save_two(lnk_list **stack_a, lnk_list **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			ft_pb(stack_a, stack_b);
			pushed++;
		}
		else
			ft_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 2)
	{
		ft_pb(stack_a, stack_b);
		pushed++;
	}
}

void	reorder_based_on_lowest(lnk_list **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			ft_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ft_ra(stack_a);
			lowest_pos--;
		}
	}
}

void	sort(lnk_list **stack_a, lnk_list **stack_b)
{
	push_all_save_two(stack_a, stack_b);
	/* if (!is_sorted(*stack_a))
		ft_sa(stack_a); */
	// sort_three(stack_a);
	// if(!is_sorted(*stack_a))
	// 	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		reorder_based_on_lowest(stack_a);
}
