/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:45:32 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/06 13:04:52 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TO DO
// STACK SIZE

#include "push_swap.h"

// asigns index to each
void	assign_index(t_list *stacka, int stack_size)
{
	t_list	*ptr;
	t_list	*highest;
	int		value;

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

void	add_to_stack(t_list **stack, t_list *new_node)
{
	t_list	*iterator;

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

int	get_stack_size(t_list *stack)
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
