/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:45:32 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/05 13:47:02 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TO DO
// STACK SIZE

#include "push_swap.h"

// asigns index to each
void	assign_index(lnk_list *stacka, int stack_size)
{
	lnk_list	*ptr;
	lnk_list	*highest;
	int			value;

	while (--stack_size > 0)
	{
		ptr = stacka;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->data == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->data > value && ptr->index == 0)
			{
				value = ptr->data;
				highest = ptr;
				ptr = stacka;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

void	add_to_stack(lnk_list **stack, lnk_list *new_node)
{
	lnk_list	*iterator;

	if (!stack)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		iterator = *stack;
		while (iterator->next != NULL)
			iterator = iterator->next;
		iterator->next = new_node;
		new_node->prev = iterator;
	}
}

int	get_stack_size(lnk_list *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
