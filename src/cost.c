/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:44:42 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/06/23 16:44:43 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

/* get_cost:

Calcula o custo de mover cada elemento da pilha B para a posição correta na pilha A.
Dois custos são calculados:
cost_b representa o custo de levar o elemento até o topo da pilha B
cost_a representa o custo de chegar à posição correta na pilha A.
Se o elemento estiver na metade inferior da pilha, o custo será negativo,
se estiver na metade superior, o custo é positivo.
*/
void	get_cost(lnk_list **stack_a, lnk_list **stack_b)
{
	lnk_list	*tmp_a;
	lnk_list	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->position) * -1;
		tmp_b->cost_a = tmp_b->target_position;
		if (tmp_b->target_position > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_position) * -1;
		tmp_b = tmp_b->next;
	}
}

/* do_cheapest_move:
*	Encontra elemento na stack B mais barato para dar push para a stack A
*	e move -o para a posicao correcta na stack A
*/
void	do_cheapest_move(lnk_list **stack_a, lnk_list **stack_b)
{
	lnk_list	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}