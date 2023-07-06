/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:15:24 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/06 13:04:52 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_biggest(t_list *stack)
{
	t_list	*biggest;

	if (!stack)
		return (NULL);
	biggest = stack;
	while (stack)
	{
		if (stack->data > biggest->data)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_list	*find_second_biggest(t_list *stack)
{
	t_list	*biggest;
	t_list	*second_biggest;

	if (!stack || !stack->next)
		return (NULL);
	biggest = stack;
	second_biggest = stack;
	while (stack)
	{
		if (stack->data > biggest->data)
		{
			second_biggest = biggest;
			biggest = stack;
		}
		else if (stack->data > second_biggest->data
			&& stack->data < biggest->data)
		{
			second_biggest = stack;
		}
		stack = stack->next;
	}
	return (second_biggest);
}

int	is_sorted(t_list *stack)
{
	t_list	*current;

	if (stack == NULL || stack->next == NULL)
	{
		return (1);
	}
	current = stack;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}

t_list	*find_smallest(t_list *stack)
{
	t_list	*smallest;

	smallest = stack;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->data < smallest->data)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}
