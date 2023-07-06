/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_linkedlists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:44:33 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/07/06 13:26:05 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// THE FIRST NODE IS THE FIRST ELEMENT OF THE STACK

t_list	*create_new_node(int content)
{
	t_list	*node;

	node = malloc(sizeof * node);
	if (!node)
		return (NULL);
	node->data = content;
	node->index = 0;
	node->position = -1;
	node->target_position = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = NULL;
	return (node);
}

void	print_list_index(t_list *stack)
{
	while (stack->next != NULL)
	{
		printf("%i\n", stack->index);
		stack = stack->next;
	}
	printf("%i\n", stack->data);
}

t_list	*get_last_node(t_list **stack)
{
	t_list	*iterator;

	iterator = *stack;
	while (stack && iterator->next)
	{
		iterator = iterator->next;
	}
	return (iterator);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
