/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:45:03 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/05 13:46:33 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// assign a position to each node of the list in ascending order (do not confuse with index)
void	get_position(lnk_list **stack)
{
	lnk_list	*tmp;
	int			i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

// retorna a posicao do menor index na stack
int	get_lowest_index_position(lnk_list **stack)
{
	lnk_list	*tmp;
	int			lowest_index;
	int			lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->position;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

int	get_target(lnk_list **a, int b_idx, int target_idx, int target_pos)
{
	lnk_list	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/* get_target_position:

		*	da target na stack A da posicao correcta depois sera usado para calcular o custo
 */
void	get_target_position(lnk_list **a, lnk_list **b)
{
	lnk_list	*tmp_b;
	int			target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_position = target_pos;
		tmp_b = tmp_b->next;
	}
}
